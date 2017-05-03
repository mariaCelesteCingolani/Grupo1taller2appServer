#include "Response.h"

#include <sstream>

Response::Response() {
	// TODO Auto-generated constructor stub

}

void Response::sendTo(mg_connection *c) {
	std::string data = getData();
	mg_printf(c, "%s", data.c_str());
}

std::string Response::getData(){
	std::ostringstream data;
	std::string body = getBody();
	data << "HTTP/1.0 " << code << "\n";
	data << "Content-Length: " << body.length() << std::endl;
	data << std::endl;
	data << body;
	return data.str();
}

Response::~Response() {
	// TODO Auto-generated destructor stub
}
