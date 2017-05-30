#include "Response.h"
#include "../plog/Log.h"
#include <sstream>

#include <iostream>
#include <fstream>

using namespace std;

void Response::sendTo(mg_connection *c) {
	LOG(plog::info)<< "Enviando respuesta " ;

	// TODO DESCOMENTAR.
//	// header
//	std::ostringstream data;
//	data << "HTTP/1.0 " << code << std::endl;
//	data << "Transfer-Encoding: chunked" << std::endl;
//	data << std::endl;
//	std::string head = data.str();
//	mg_printf(c, "%s", head.c_str());
//
//	// body
//	ifstream myFile ("data", ios::in | ios::binary);
//	myFile.seekg(0,ios_base::end);
//	int size = myFile.tellg();
//	myFile.seekg(0,ios_base::beg);
//	char buffer[size];
//	myFile.read (buffer, size);
//	// TODO por si en el futuro mandamos por partes
//	mg_send_http_chunk(c, buffer, size);
//	mg_send_http_chunk(c, "", 0); // Tell the client we're finished


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
	// TODO Auto-generated destructor stub
}
