#include "plog/Log.h"
#include "DB/DBManager.h"
#include "DB/Track.h"
#include "restserver/RestServer.h"

#include <iostream>
#include <fstream>

using namespace std;

void aux();

int main(int argc, char *argv[]) {

	std::cout << "Hello World!" << std::endl;

	plog::init(plog::debug, "appserver.log");
	LOG(plog::info) << "Starting appserver";
	RestServer r ;
	r.start();
	return 0;

}


void aux(){
	ifstream myFile ("data", ios::in | ios::binary);
	myFile.seekg(0,ios_base::end);
	int size = myFile.tellg();
	myFile.seekg(0,ios_base::beg);
	char buffer[size];
	myFile.read (buffer, size);
	DBManager d("mongodb://localhost:27017");
	Track* track = new Track("abc", "mp3", size, buffer);
	d.addTrack(track);
	Track * result = d.getTrack("abc");
	ofstream ofile ("out",  ios::out | ios::binary);
	ofile.write(result->buffer, result->size);
}
