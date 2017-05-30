#include "Request.h"
#include "../plog/Log.h"

//todo borrar
#include <iostream>

std::string Request::getBody() const {
	return std::string(mssg->body.p, (size_t) mssg->body.len);
}

std::string Request::getMethod() const {
	return std::string(mssg->method.p, (size_t) mssg->method.len);
}

std::string Request::getQuery() const {
	return std::string(mssg->query_string.p, (size_t) mssg->query_string.len);
}

std::string Request::getUri() const {
	return std::string(mssg->uri.p, (size_t) mssg->uri.len);
}



//void Request::parse (http_message * mssg){
////	struct http_message {
////	  struct mg_str method; /* "GET" */
////	  struct mg_str uri;    /* "/my_file.html" */
////	  struct mg_str query_string;
//
////	  /* Message body */
////	  struct mg_str body; /* Zero-length for requests with no body */
////	};
////	struct mg_str {
////	  const char *p; /* Memory chunk pointer */
////	  size_t len;    /* Memory chunk length */
////	};
//	// todo borrar esto
//	std::string aux = this->method = std::string(mssg->message.p, (size_t)mssg->message.len);
//	std::cout << aux << std::endl;
//	// fin borrar
//	// METHOD:
//	this->method = std::string(mssg->method.p, (size_t)mssg->method.len);
//	// URI
//	this->uri = std::string(mssg->uri.p, (size_t)mssg->uri.len);
//	// BODY :
//	this->body = std::string(mssg->body.p, (size_t)mssg->body.len);
//	// QUERY
//	this->query = std::string(mssg->query_string.p, (size_t)mssg->query_string.len);
//
//}


Request::~Request() {
	// TODO Auto-generated destructor stub
}
