#include "plog/Log.h"
#include "restserver/RestServer.h"

int main(int argc, char *argv[]) {

	plog::init(plog::debug, "appserver.log");
	LOG(plog::info) << "Starting appserver";
	RestServer r ;
	r.start();
	return 0;

}
