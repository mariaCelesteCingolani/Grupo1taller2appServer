#include "plog/Log.h"
#include "DB/DBManager.h"


#include <iostream>


int main(int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;
	// LOG
	plog::init(plog::debug, "Sample.log");
	LOG(plog::debug) << "Hello log!";
	// MONGO DB
	DBManager d;
	d.helloWorld();
	return 0;

}

