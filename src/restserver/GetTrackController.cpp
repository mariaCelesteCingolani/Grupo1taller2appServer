#include "GetTrackController.h"
#include "Config.h"
#include "../plog/Log.h"
#include "../DB/DBManager.h"
#include <map>
#include <iostream>


GetTrackController::GetTrackController():Controller(HTTP_GET, "/api/tracks") {
}


bool GetTrackController::canProcess(Request * request) {
	LOG(plog::debug) << "GetTrackController::canProcess";
	if (Controller::canProcess(request)){
		LOG(plog::debug)<< "	Método y uri ok, verificando parámetros ";
		// parámetros
		if (request->getQuery() != ""){
			std::map<std::string, std::string> map = parseQuery(request->getQuery());
			if (map.count(TRACK_ID_KEY)){
				LOG(plog::debug)<< "	Parámetros ok - buscando track: " << map[TRACK_ID_KEY];
				this->trackId = map[TRACK_ID_KEY];
			}
		}
		// headers
		this->usrName = request->getHeader(USER_NAME_HEADER);
		this->token = request->getHeader(TOKEN_HEADER);
		LOG(plog::debug)<< "    Headers ok - User: " << this->usrName << "Token: " << this->token;
		return true;
	}
	return false;
}

Response *GetTrackController::getResponse() {
	if (checkUserLogged()){
		LOG(plog::info)<< "Usuario válido generando respuesta";
		DBManager d("mongodb://admin:admin@musicio-shard-00-00-7k5wq.mongodb.net:27017,musicio-shard-00-01-7k5wq.mongodb.net:27017,musicio-shard-00-02-7k5wq.mongodb.net:27017/musiciodb?ssl=true&replicaSet=musicio-shard-0&authSource=admin");
		Track * track = d.getTrack(trackId);
		Response * response =  NULL;
		if (track != NULL){
			response = new Response(HTTP_OK, "Transfer-Encoding: chunked",
					track->buffer, track->size);
		} else{
			LOG(plog::info)<< "No se encontró el track solicitado";
			response = new Response(HTTP_NOT_FOUND);
		}
		return response;
	}
	return NULL;
}

bool GetTrackController::checkUserLogged(){
	LOG(plog::info)<< "Validando usuario: "  << "Name: " << usrName << "Token: "  << token;
	// todo
	return true;
}



GetTrackController::~GetTrackController() {
}
