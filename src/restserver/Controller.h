#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Response.h"
#include "Request.h"
#include <string>
#include <map>

class Controller {
public:
	Controller(std::string method, std::string uri): method(method), uri(uri){};

	virtual Response * getResponse () = 0;

	virtual bool canProcess (Request * request );

	virtual ~Controller();

protected:

	std::map<std::string, std::string> parseQuery(const std::string& query);
	std::string method;
	std::string uri;
};

#endif /* CONTROLLER_H_ */
