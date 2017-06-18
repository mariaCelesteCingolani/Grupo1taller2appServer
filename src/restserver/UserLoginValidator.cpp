
#include "UserLoginValidator.h"
#include "Config.h"
#include "../plog/Log.h"
#include <iostream>

static int s_exit_flag = 0;

static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
	struct http_message *hm = (struct http_message *) ev_data;
	UserLoginValidator *self = (UserLoginValidator *) nc->user_data;
	switch (ev) {
		// no se puede establecer conexion
		case MG_EV_CONNECT:
			if (*(int *) ev_data != 0) {
				s_exit_flag = 1;
				LOG(plog::error)<< "No se ha podido conectar al shared server";
			}
			break;
		// caso conexion ok
		case MG_EV_HTTP_REPLY:
			nc->flags |= MG_F_CLOSE_IMMEDIATELY;
			if (hm->resp_code == HTTP_CREATED){
				self->setTrue();
			}
			s_exit_flag = 1;
			break;
		// salir del loop
		case MG_EV_CLOSE:
			if (s_exit_flag == 0) {
				printf("Server closed connection\n");
				s_exit_flag = 1;
			}
			break;
		default:
			break;
	}
}

void UserLoginValidator::setFalse() {
	userLogged = false;
}

void UserLoginValidator::setTrue() {
	userLogged = true;
}


UserLoginValidator::UserLoginValidator() :
	mgr(NULL), nc(NULL), userLogged(false) {
	mgr = new mg_mgr;
	mg_mgr_init(mgr, NULL);
}

bool UserLoginValidator::isLogged(std::string userName, std::string password) {
	std::string headers = "Content-Type: application/json\r\n";
	std::string body = "{\"userName\":\""+ userName + "\",\"password\":\"" + password + "\"}";
	nc = mg_connect_http(mgr, ev_handler, SHARED_SERVER_TOKEN,
			headers.c_str(), body.c_str());
	nc->user_data = this;
	while (s_exit_flag == 0) {
		mg_mgr_poll(mgr, 1000);
	}
	return userLogged;
}

UserLoginValidator::~UserLoginValidator() {
	mg_mgr_free(mgr);
}
