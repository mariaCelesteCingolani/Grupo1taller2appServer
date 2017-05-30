#include "ControllerManager.h"
#include "GetTrackController.h"

ControllerManager::ControllerManager() {
	this->controllers.push_back(new GetTrackController());
}

Response *ControllerManager::process(Request *request) {
	Response * response;
	for (Controller * cont: controllers){
		if (cont->canProcess(request)){
			response = cont->getResponse();
			return response;
		}
	}
	return NULL;
}

ControllerManager::~ControllerManager() {
	// TODO Auto-generated destructor stub
}
