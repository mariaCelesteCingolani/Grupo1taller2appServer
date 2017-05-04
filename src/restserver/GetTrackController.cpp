#include "GetTrackController.h"
#include "Config.h"
#include "../plog/Log.h"
#include <map>


GetTrackController::GetTrackController():Controller(HTTP_GET, "/api/tracks") {
}


bool GetTrackController::canProcess(Request * request) {
	if (Controller::canProcess(request)){
		LOG(plog::info)<< "Método y uri coinciden, verificando cuerpo ";
		if (request->getQuery() != ""){
			std::map<std::string, std::string> map = parseQuery(request->getQuery());
			if (map.count(USER_KEY) && map.count(PASS_KEY) && map.count(TRACK_ID_KEY)){
				LOG(plog::info)<< "Cuerpo del mensaje ok";
				this->trackId = map[TRACK_ID_KEY];
				this->usrName = map[USER_KEY];
				this->usrPasswd = map[PASS_KEY];
				return true;
			}
		}
	}
	return false;
}

Response *GetTrackController::process(Request * request) {
	if (checkUserLogged()){
		LOG(plog::info)<< "Usuario válido generando respuesta";
		Response * response = new Response();
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
