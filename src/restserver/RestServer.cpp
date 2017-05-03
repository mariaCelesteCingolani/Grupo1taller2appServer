#include "RestServer.h"
#include "NotFoundResponse.h"
#include "Response.h"
#include "Request.h"
#include "../plog/Log.h"
#include "../utils/Utils.h"


void event_handler(mg_connection *nc, int ev, void *ev_data) {
	if (ev == MG_EV_HTTP_REQUEST) {
		RestServer *self = (RestServer *) nc->user_data;
		if (self != NULL) {
			self->handleRequest(nc, (http_message *) ev_data);
		}
	}
}

RestServer::RestServer(int port): port(port), mgr(NULL), nc(NULL), running(false){
}

bool RestServer::start() {
	if (mgr != NULL){
		LOG(plog::info) << "El servidor ya ha sido iniciado";
		return true;
	}
	// crea el server
	mgr = new mg_mgr;
	mg_mgr_init(mgr, NULL);
	// enlaza al puerto
	nc = mg_bind(mgr, intToString(port).c_str(), event_handler);
	if (nc == NULL){
		LOG(plog::error) << "Problema conectando al servidor al puerto: " << port;
		return false;
	}
	// protocolo http
	mg_set_protocol_http_websocket(nc);
	LOG(plog::info) << "Se ha iniciado el servidor en el puerto: "<< port;
	nc->user_data = this;
	running = true;
	// loop escuchar conexiones
	for (;;) {
		mg_mgr_poll(mgr, 1000);
	}
	return true;
}

bool RestServer::stop() {
	if (running) {
		mg_mgr_free(mgr);
		// todo liberar conexion si hay
		running = false;
		return true;
	}
	return false;
}

void RestServer::handleRequest(mg_connection *c, http_message * p){
	// request parsea el mensaje
	Request * req = new Request (p);
	// controller ve si puede procesar el request
	Response *resp = cont->process(req);
	if (resp == NULL) {
		resp = new NotFoundResponse();
	}
	resp->sendTo(c);
	delete resp;
	delete req;
}


RestServer::~RestServer() {
	stop();
}
