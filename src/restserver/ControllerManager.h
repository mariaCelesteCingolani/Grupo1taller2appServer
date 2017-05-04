#ifndef CONTROLLERMANAGER_H_
#define CONTROLLERMANAGER_H_

#include "Request.h"
#include "Response.h"
#include "Controller.h"
#include <list>

class ControllerManager {
public:
	ControllerManager();

	Response * process(Request * request);

	virtual ~ControllerManager();
private:
	std::list<Controller *> controllers;

	void addController (Controller * cont);
};

#endif /* CONTROLLERMANAGER_H_ */
