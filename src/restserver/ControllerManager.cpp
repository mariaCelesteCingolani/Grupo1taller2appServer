#include "ControllerManager.h"
#include "GetTrackController.h"
#include "../plog/Log.h"

ControllerManager::ControllerManager() {
	this->controllers.push_back(new GetTrackController());
}

Response *ControllerManager::process(Request *request) {
	LOG(plog::debug) << "ControllerManager::process";
	Response * response;
	for (Controller * cont: controllers){
		if (cont->canProcess(request)){
			response = cont->getResponse();
			LOG(plog::debug) << "	respuesta encontrada";
			return response;
		}
	}
	LOG(plog::debug) << "	respuesta no encontrada";
	return NULL;
}

ControllerManager::~ControllerManager() {
	// TODO Auto-generated destructor stub
}
