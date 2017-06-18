#include "ControllerManager.h"
#include "GetTrackController.h"
#include "../plog/Log.h"

ControllerManager::ControllerManager() {
	this->controllers.push_back(new GetTrackController());
}

Response *ControllerManager::process(Request *request) {
	Response * response;
	for (Controller * cont: controllers){
		if (cont->canProcess(request)){
			LOG(plog::debug)<< " Método y uri: ok ";
			response = cont->getResponse(request);
			return response;
		}
	}
	LOG(plog::debug)<< " Método y uri: error ";
	return new Response(HTTP_BAD_REQUEST);
}

ControllerManager::~ControllerManager() {
	// TODO Auto-generated destructor stub
}
