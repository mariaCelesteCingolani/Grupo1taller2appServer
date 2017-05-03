#include "NotFoundResponse.h"

NotFoundResponse::NotFoundResponse() {
	this->code = HTTP_NOT_FOUND;
}

std::string NotFoundResponse::getBody(){
	return "";
}

NotFoundResponse::~NotFoundResponse() {

}
