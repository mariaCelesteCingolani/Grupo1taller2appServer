#include "Response.h"
#include "../plog/Log.h"
#include <sstream>

#include <iostream>
#include <fstream>

using namespace std;

void Response::sendTo(mg_connection *c) {
	LOG(plog::info)<< "Enviando respuesta " ;

	// header
	std::ostringstream heads;
	heads << "HTTP/1.0 " << code << std::endl;
	heads << headers << std::endl;
	heads << std::endl;
	std::string head = heads.str();
	mg_printf(c, "%s", head.c_str());

	// body si hay que mandar datos
	if (data != NULL) {
		mg_send_http_chunk(c, (char *)data, data_size);
		mg_send_http_chunk(c, "", 0); // Tell the client we're finished
	}
}


Response::~Response() {
}
