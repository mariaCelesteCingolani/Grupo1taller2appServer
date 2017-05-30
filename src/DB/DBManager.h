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

	// agrega un nuevo track
	// devuelve true en caso de éxito, false en otro caso
	bool addTrack(Track* track);

	// borra el track correspondiente a id
	bool deleteTrack(string id);

	// Devuelve el track correspondiente a id
	// o null si no existe
	Track* getTrack (string id);


	DBManager(string uri);
	virtual ~DBManager();
};

#endif /* DBMANAGER_H_ */
