
#ifndef USERLOGINVALIDATOR_H_
#define USERLOGINVALIDATOR_H_

#include "mongoose.h"
#include <string>

class UserLoginValidator {
public:
	UserLoginValidator();

	bool isLogged(std::string userName, std::string password);

	void setTrue();

	void setFalse();

	virtual ~UserLoginValidator();
private:
	mg_mgr* mgr;
	mg_connection* nc;
	bool userLogged;
};

#endif /* USERLOGINVALIDATOR_H_ */
