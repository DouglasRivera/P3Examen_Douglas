#ifndef RED_H
#define RED_H
#include "PC.h"
#include <vector>
#include <iostream>

class Red
{
	private:
	vector <PC*> pc;	
	public:
	Red();
	~Red();
	vector<PC*> getPC(); 
};

#endif