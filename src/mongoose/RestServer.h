#ifndef RESTSERVER_H_
#define RESTSERVER_H_

class RestServer {

private:

	int port;


	static void ev_handler (ev_handler(struct mg_connection *nc, int ev, void *ev_data);

	static void handle_sum_call(struct mg_connection *nc, struct http_message *hm)

public:

	RestServer();

	void start();

	void stop();

	virtual ~RestServer();



};

#endif /* RESTSERVER_H_ */
