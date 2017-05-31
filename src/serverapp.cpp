#include "plog/Log.h"
#include "DB/DBManager.h"
#include "DB/Track.h"
#include "restserver/RestServer.h"

#include <iostream>
#include <fstream>

using namespace std;

void addTrack(string trackId, string path);
void deleteTrack (string trackId);
void showHelp();

int main(int argc, char *argv[]) {

	std::cout << "Este es el servidor de MUSIC-IO" << std::endl;

	plog::init(plog::debug, "appserver.log");
	LOG(plog::info) << "Starting appserver";

	if (argc <= 1){
		RestServer r ;
		r.start();
	} else{
		string modo = string (argv[1]);
		if  (modo.compare("-a") == 0){
			if (argc >= 4){
				string trackId = string(argv[2]);
				string path = string(argv[3]);
				addTrack (trackId, path);
			} else{
				cout<< "argumentos incorrectos" << endl;
				showHelp();
			}
		} else if (modo.compare("-r") == 0){
			if (argc >= 3){
				string trackId = string(argv[2]);
				deleteTrack(trackId);
			} else{
				cout<< "argumentos incorrectos" << endl;
				showHelp();
			}
		}else{
			showHelp();
		}
	}



	return 0;

}


void addTrack(string trackId, string path){
	cout << "Agregando el track:" << endl <<
			"	Id: " << trackId << endl <<
			"   Path: "<< path << endl;
	ifstream myFile (path, ios::in | ios::binary);
	myFile.seekg(0,ios_base::end);
	int size = myFile.tellg();
	myFile.seekg(0,ios_base::beg);
	char buffer[size];
	myFile.read (buffer, size);
	DBManager d("mongodb://localhost:27017");
	Track* track = new Track(trackId, "mp3", size, buffer);
	if (d.addTrack(track)){
		cout << "Agregado con éxito" << endl;
	} else{
		cout << "Error al agregar el track" << endl;
	}
//	Track * result = d.getTrack("abc");
//	ofstream ofile ("out",  ios::out | ios::binary);
//	ofile.write(result->buffer, result->size);
}

void deleteTrack (string trackId){
	DBManager d("mongodb://localhost:27017");
	d.deleteTrack(trackId);
	cout << "Borrado el track con id: " << trackId << endl;
}

void showHelp(){
	cout << "Modo de uso del programa: " << endl;
	cout << "serverapp [modo]" << endl;
	cout << "Si no se pasa ningún argumento por defecto se ejecuta el servidor" << endl;
	cout << "-a trackId path: " << endl;
	cout << "    agrega un nuevo track, con el id indicado, desde el archivo indicado" << endl;
	cout << "-r trackId: " << endl;
	cout << "    elimina el track indicado" << endl;
}
