#include "DBManager.h"


#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/instance.hpp>
#include <mongocxx/exception/exception.hpp>




DBManager::DBManager(string srcuri) {
	mongocxx::instance inst { };
	mongocxx::uri uri(srcuri);
	this->client = mongocxx::client(uri);
	this->db = this->client["musiciodb"];
	this->collection = db["tracks"];
}


bool DBManager::addTrack(Track* track){

	bsoncxx::builder::stream::document document{};
	bsoncxx::types::b_binary data { bsoncxx::binary_sub_type::k_binary, (unsigned int)track->size,(const uint8_t*)track->buffer};
	bsoncxx::document::value doc_value = document
			<< "_id" << track->id
			<< "type" << track->type
			<< "size" << track->size
			<< "data" << data
		<< bsoncxx::builder::stream::finalize;
	bsoncxx::document::view view = doc_value.view();
	try{
		collection.insert_one(view);
	} catch (const mongocxx::exception& e){
		return false;
	}
	return true;
}

Track* DBManager::getTrack (string id){
	auto cursor = collection.find(
				bsoncxx::builder::stream::document { } << "_id" << id
						<< bsoncxx::builder::stream::finalize);
	Track * track = new Track();
	try{
		for (auto&& doc : cursor) {

				track->id = doc["_id"].get_utf8().value.to_string();
				track->type = doc["type"].get_utf8().value.to_string();
				bsoncxx::document::element store_ele = doc["data"];
				if (store_ele) {
					int size = store_ele.get_binary().size;
					track->copyAndSave( (char*) store_ele.get_binary().bytes, size);
				}
		}
    } catch (const mongocxx::exception& e) {
		return NULL;
	}
	return track;
}


bool DBManager::deleteTrack(string id){
	bsoncxx::builder::stream::document filter_builder;
	filter_builder << "_id" << id;
	collection.delete_one(filter_builder.view());
	return true;
}



DBManager::~DBManager() {
	// TODO Auto-generated destructor stub
}


