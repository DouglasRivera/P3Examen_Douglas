#include "Red.h"
Red::Red(){
}

Red::~Red(){
for(int i = 0; i<pc.size(); i++) {
		delete pc.at(i);
	}	
}

vector<PC*> Red::getPC() {
	return this->pc;
}