#ifndef GETTRACKCONTROLLER_H_
#define GETTRACKCONTROLLER_H_

#include "Controller.h"

class GetTrackController: public Controller {
public:
	GetTrackController();

	Response * getResponse ();

	bool canProcess (Request * request );

	virtual ~GetTrackController();
private:
	std::string trackId;
	std::string usrName;
	std::string token;

	bool checkUserLogged();
};

#endif /* GETTRACKCONTROLLER_H_ */
