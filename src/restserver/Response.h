#ifndef RESPONSE_H_
#define RESPONSE_H_

#include "mongoose.h"
#include <string>

#define HTTP_OK 200
#define HTTP_CREATED 201
#define HTTP_BAD_REQUEST 400
#define HTTP_NOT_FOUND 404
#define HTTP_FORBIDDEN 403
#define HTTP_SERVER_ERROR 500

class Response {
public:
	Response();

	std::string getData();

	virtual std::string getBody() = 0;

	void sendTo(mg_connection *c);

	virtual ~Response();
protected:
	int code;
};

#endif /* RESPONSE_H_ */
