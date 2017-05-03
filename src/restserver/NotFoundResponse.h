#ifndef NOTFOUNDRESPONSE_H_
#define NOTFOUNDRESPONSE_H_

#include "Response.h"

class NotFoundResponse: public Response {
public:
	NotFoundResponse();

	std::string getBody();

	virtual ~NotFoundResponse();
};

#endif /* NOTFOUNDRESPONSE_H_ */
