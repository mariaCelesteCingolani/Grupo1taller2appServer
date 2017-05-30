#ifndef RESPONSE_H_
#define RESPONSE_H_

#include "mongoose.h"
#include "Config.h"
#include <string>

class Response {
public:
	Response(int code = HTTP_OK, std::string headers = "", void * data = NULL, int data_size = 0):
		code(code),
		headers(headers),
		data(data),
		data_size(data_size){} ;

	void setCode(int code);

	void sendTo(mg_connection *c);

	virtual ~Response();
protected:
	int code;
	std::string headers;
	void * data;
	int data_size;

};

#endif /* RESPONSE_H_ */
