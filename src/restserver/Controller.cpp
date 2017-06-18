#include "Controller.h"

#include "../plog/Log.h"
#include <regex>
#include <map>


bool Controller::canProcess (Request * request ){
	return (this->method.compare(request->getMethod()) == 0 &&
			this->uri.compare(request->getUri())== 0 );
};



std::map<std::string, std::string> Controller::parseQuery(const std::string& query){
    std::map<std::string, std::string> data;
    std::regex pattern("([\\w+%]+)=([^&]*)");
    auto words_begin = std::sregex_iterator(query.begin(), query.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; i++)
    {
        std::string key = (*i)[1].str();
        std::string value = (*i)[2].str();
        data[key] = value;
    }

    return data;
}

Controller::~Controller() {

}
