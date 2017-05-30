#ifndef REQUEST_H_
#define REQUEST_H_

#include "mongoose.h"
#include "Config.h"
#include <string>

using namespace std;

class Request {
public:
	Request(http_message* mssg):mssg(mssg){};
	virtual ~Request();
    string getBody() const;
    string getMethod() const;
    string getQuery() const;
    string getUri() const;
    string getHeader (string key);

private:
	http_message * mssg;

};

#endif /* REQUEST_H_ */
