#ifndef GETTRACKCONTROLLER_H_
#define GETTRACKCONTROLLER_H_

#include "Controller.h"

class GetTrackController: public Controller {
public:
	GetTrackController();

	virtual Response * getResponse (Request * request);

	virtual ~GetTrackController();

private:
	std::string trackId;
	std::string usrName;
	std::string password;

	bool checkUserLogged();

	Response * getTrackResponse();

};

#endif /* GETTRACKCONTROLLER_H_ */
