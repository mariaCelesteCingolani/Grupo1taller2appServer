#include "Request.h"
#include "../plog/Log.h"

string Request::getBody() const {
	return std::string(mssg->body.p, (size_t) mssg->body.len);
}

string Request::getMethod() const {
	return std::string(mssg->method.p, (size_t) mssg->method.len);
}

string Request::getQuery() const {
	return std::string(mssg->query_string.p, (size_t) mssg->query_string.len);
}

string Request::getUri() const {
	return std::string(mssg->uri.p, (size_t) mssg->uri.len);
}

string Request::getHeader (string key){
	struct mg_str *value = mg_get_http_header(mssg, key.c_str());
	if (value != NULL){
		return std::string(value->p, (size_t) value->len);
	}
	return "";
}

Request::~Request() {
	// TODO Auto-generated destructor stub
}
