#include "Response.h"
#include "../plog/Log.h"
#include <sstream>

void Response::sendTo(mg_connection *c) {
	LOG(plog::info)<< "Enviando respuesta " ;
	std::string data = this->getData();
	mg_printf(c, "%s", data.c_str());
}

std::string Response::getData(){
	std::ostringstream data;
	data << "HTTP/1.0 " << code << "\n";
	data << "Content-Length: " << body.length() << std::endl;
	data << std::endl;
	data << body;
	return data.str();
}

Response::~Response() {
	// TODO Auto-generated destructor stub
}
