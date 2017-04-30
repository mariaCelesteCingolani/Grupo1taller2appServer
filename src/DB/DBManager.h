#ifndef DBMANAGER_H_
#define DBMANAGER_H_

#include <string>
#include <mongocxx/client.hpp>

#include "Track.h"

using namespace std;

class DBManager {
private:
	mongocxx::client client;
	mongocxx::database db;
	mongocxx::collection collection;


public:

	// adds a track to the database.
	// returns true if success, false other
	bool addTrack(Track* track);

	bool deleteTrack(string id);

	Track* getTrack (string id);



	DBManager(string uri);
	virtual ~DBManager();
};

#endif /* DBMANAGER_H_ */
