#ifndef RESPONSE_H_
#define RESPONSE_H_

#include "mongoose.h"
#include "Config.h"
#include <string>

class Response {
public:
	Response(int code = HTTP_OK, std::string body = ""): code(code), body(body){} ;

	void setCode(int code);

	void sendTo(mg_connection *c);

	virtual ~Response();
private:
	int code;
	std::string body;

	std::string getData();
};

#endif /* RESPONSE_H_ */
