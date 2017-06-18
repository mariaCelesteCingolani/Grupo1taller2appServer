#ifndef RESTSERVER_H_
#define RESTSERVER_H_

#include "ControllerManager.h"
#include "mongoose.h"
#include "Config.h"
#include <list>

class RestServer {
private:
	int port;
	mg_mgr* mgr;
	mg_connection* nc;
	bool running;
	ControllerManager * cont;

public:
	RestServer(int port = PORT);

	bool start();

	bool stop();

	void handleRequest(mg_connection *c, http_message * p);

	virtual ~RestServer();
};

#endif /* RESTSERVER_H_ */
