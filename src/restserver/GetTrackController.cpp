#include "GetTrackController.h"
#include "Config.h"
#include "../plog/Log.h"
#include "../DB/DBManager.h"
#include <map>


GetTrackController::GetTrackController():Controller(HTTP_GET, "/api/tracks") {
}


bool GetTrackController::canProcess(Request * request) {
	// todo cambiar lectura de request.
	if (Controller::canProcess(request)){
		LOG(plog::info)<< "Método y uri coinciden, verificando cuerpo ";
		// todo agregar lectura de header
		if (request->getQuery() != ""){
			std::map<std::string, std::string> map = parseQuery(request->getQuery());
			if (map.count(TRACK_ID_KEY)){
				LOG(plog::info)<< "Cuerpo del mensaje ok";
				this->trackId = map[TRACK_ID_KEY];
				return true;
			}
		}
	}
	return false;
}

Response *GetTrackController::getResponse() {
	if (checkUserLogged()){
		LOG(plog::info)<< "Usuario válido generando respuesta";
		DBManager d("mongodb://localhost:27017");
		Track * track = d.getTrack(trackId);
		Response * response =  NULL;
		if (track != NULL){
			response = new Response(HTTP_OK, "Transfer-Encoding: chunked",
					track->buffer, track->size);
		} else{
			response = new Response(HTTP_NOT_FOUND);
		}
		return response;
	}
	return NULL;
}

bool GetTrackController::checkUserLogged(){
	LOG(plog::info)<< "Validando usuario: "  << "Name: " << usrName << "Token: "  << usrPasswd;
	// todo
	return true;
}



GetTrackController::~GetTrackController() {
	// TODO Auto-generated destructor stub
}
