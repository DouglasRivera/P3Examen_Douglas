#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#ifndef PC_H
#define PC_H
class PC {
	private:
		string mascara;
		string ip;
		string nombre;

	public:
		PC(string,string,string);
		~PC();
		void setMascara(string);
		void setIp(string);
		void setNombre(string);
		string getNombre();
		string getIp();
		string getMascara();
	    string toString();
		bool ping(string);
};
#endif