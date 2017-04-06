#ifndef RESTSERVER_H_
#define RESTSERVER_H_

class RestServer {

public:

	RestServer();

	void start();

	void run();

	void stop();

	virtual ~RestServer();



};

#endif /* RESTSERVER_H_ */
