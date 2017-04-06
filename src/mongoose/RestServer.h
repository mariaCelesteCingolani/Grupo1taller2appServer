#ifndef RESTSERVER_H_
#define RESTSERVER_H_

class RestServer {
 
private:

	int port;

public:

	RestServer();

	void start();

	void stop();

	virtual ~RestServer();



};

#endif /* RESTSERVER_H_ */
