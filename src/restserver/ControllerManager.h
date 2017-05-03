#ifndef CONTROLLERMANAGER_H_
#define CONTROLLERMANAGER_H_

#include "Request.h"
#include "Response.h"

class ControllerManager {
public:
	ControllerManager();

	Response * process(Request * request);

	virtual ~ControllerManager();
};

#endif /* CONTROLLERMANAGER_H_ */
