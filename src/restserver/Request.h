#ifndef REQUEST_H_
#define REQUEST_H_

#include "mongoose.h"
#include "Config.h"
#include <string>
#include <map>

class Request {
public:
	Request(http_message* mssg);
	virtual ~Request();
    std::string getBody() const;
    std::string getMethod() const;
    std::string getQuery() const;
    std::string getUri() const;

private:
	std::string method;
	std::string uri;
	std::string body;
	std::string query;
	void parse (http_message * mssg);
};

#endif /* REQUEST_H_ */
