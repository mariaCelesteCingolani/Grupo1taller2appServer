#ifndef TRACK_H_
#define TRACK_H_

#include <string>
#include <fstream>

using namespace std;

class Track {
public:
	string id;
	string type;
	int size;
	char *  buffer;

	Track(string id = "", string type = "", int size = 0, char * buffer = NULL):
		id(id), type(type), size(size), buffer(buffer){};

	void copyAndSave (char *data, int size);

	virtual ~Track();
};

#endif /* TRACK_H_ */
