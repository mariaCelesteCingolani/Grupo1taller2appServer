#include "plog/Log.h"
#include "DB/DBManager.h"


#include <iostream>
#include <fstream>

#include "DB/Track.h"


using namespace std;

int main(int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;
	// LOG
	plog::init(plog::debug, "appserver.log");
	LOG(plog::debug) << "Hello log!";
	// MONGO DB
//	DBManager d("mongodb://localhost:27017");
//	ifstream myFile ("data", ios::in | ios::binary);
//	myFile.seekg(0,ios_base::end);
//	int size = myFile.tellg();
//	myFile.seekg(0,ios_base::beg);
//	char* buffer = new char[size];
//	myFile.read (buffer, size);
//	Track* track = new Track("123","mp3",size, buffer);
//	bool resultok = d.addTrack(track);
//	if (resultok){
//		cout << "insert ok" << endl;
//	} else{
//		cout << "error insert" << endl;
//	}
//
//	Track * track2 = d.getTrack("123");
//	cout << "id: "<< track2->id << "size: " << track2->size << endl;
//	ofstream oFile("out_test", ios::out | ios::binary);
//	oFile.write(track2->buffer, track2->size);
//	bool deleteOk = d.deleteTrack("123");
//	if (deleteOk){
//		cout << "delete ok" <<  endl;
//	}

	return 0;

}

