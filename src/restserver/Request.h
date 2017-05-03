#ifndef REQUEST_H_
#define REQUEST_H_

#include "mongoose.h"

class Request {
public:
	Request(http_message* mssg);
	virtual ~Request();
};

#endif /* REQUEST_H_ */
