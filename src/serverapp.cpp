#include "plog/Log.h"
#include "DB/DBManager.h"
#include "DB/Track.h"
#include "restserver/RestServer.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;
	// LOG
	plog::init(plog::debug, "appserver.log");
	LOG(plog::info) << "Starting appserver";
	RestServer r ;
	r.start();
	return 0;

}

