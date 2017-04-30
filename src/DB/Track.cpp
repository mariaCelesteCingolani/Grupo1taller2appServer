/*
 * Track.cpp
 *
 *  Created on: Apr 27, 2017
 *      Author: celeste
 */

#include "Track.h"

#include <string.h>

void Track::copyAndSave (char *data, int size){

	this->buffer = new char[size];
	memcpy(this->buffer, data, size);
	this->size = size;
}

Track::~Track() {

}
