#include "GetTrackController.h"
#include "Config.h"
#include "UserLoginValidator.h"
#include "../plog/Log.h"
#include "../DB/DBManager.h"
#include <map>

GetTrackController::GetTrackController():Controller(HTTP_GET, "/api/tracks") {
}

Response *GetTrackController::getResponse(Request * request) {
	// parámetros
	if (request->getQuery() == ""){
		LOG(plog::debug)<< " Parámetros: vacío";
		return new Response(HTTP_UNPROCESSABLE);
	}
	std::map<std::string, std::string> map = parseQuery(request->getQuery());
	if (!map.count(TRACK_ID_KEY) or !map.count(USERNAME_KEY) or !map.count(PASSWORD_KEY)) {
		LOG(plog::debug)<< " Parámetros: faltan parámetros";
		return new Response(HTTP_UNPROCESSABLE);
	}
	LOG(plog::debug)<< " Parámetros: ok";
	this->trackId = map[TRACK_ID_KEY];
	this->usrName = map[USERNAME_KEY];
	this->password = map[PASSWORD_KEY];
	if (!checkUserLogged()){
		LOG(plog::debug)<< " Validación de usuario: no loggeado";
		return new Response(HTTP_FORBIDDEN);
	}
	LOG(plog::debug)<< " Validación de usuario: ok";
	Response * response = getTrackResponse();
	if (response == NULL){
		LOG(plog::debug)<< " Buscar track: no encontrado";
		return new Response(HTTP_NOT_FOUND);
	}
	LOG(plog::debug)<< " Buscar track: OK";
	return response;
}


bool GetTrackController::checkUserLogged() {
	UserLoginValidator v;
	return v.isLogged(usrName, password);
}

Response *GetTrackController::getTrackResponse() {
	DBManager d(MONGO_HOST);
	Track * track = d.getTrack(trackId);
	Response * response = NULL;
	if (track != NULL) {
		response = new Response(HTTP_OK, "Transfer-Encoding: chunked",
				track->buffer, track->size);
	}
	return response;
}

GetTrackController::~GetTrackController() {
}





