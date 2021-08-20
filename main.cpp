#include <iostream>
#include <string>
#include "PC.h"
#include "Red.h"
#include <vector>
using namespace std;

int menu();

int main() {
	vector<PC *> pcs;
	int opcion;
	while((opcion = menu()) != 3) {
		switch (opcion) {
			case 1: {
				string nombre, mascara, ip;
				cout << "Ingrese el nombre" << endl;
				cin >> nombre;
				cout << "Ingrese el IP" << endl;
				cin >> ip;
				cout << "Ingrese el mascara de red" << endl;
				cin >> mascara;
				pcs.push_back(new PC(mascara, ip, nombre));
				cout << "Creada con exito" << endl;
				break;
			}
			case 2: {
				int opcion2;
				bool exit = false;
				for (int i = 0; i < pcs.size(); i++) {
					cout << i << " ";
					pcs[i]->toString();
					cout << endl;
				}
				cout << "En que computadora desea ingresar:" << endl;
				cin >> opcion2;
				while (exit == false) {
					bool ip_encontrada = false;
					string comando;
					cout << pcs[opcion2]->getNombre() << "#";
					cin >> comando;
					int tamano = comando.size();
					string comando_ping;
					comando_ping = comando.substr(0, 4);


					if (comando == "show") {
						cout << "IP: " << pcs[opcion2]->getIp() << endl;
						cout << "Netmask: " << pcs[opcion2]->getMascara() << endl;
					} else if (comando_ping == "ping") {

						for (int i = 0; i < pcs.size(); i++) {
							if (pcs[i]->getIp() == comando.substr(5, comando.size())) {
								ip_encontrada = true;
							}
						}
						if (ip_encontrada == true) {
							bool exitoso = pcs[opcion2]->ping(comando.substr(5, comando.size()));
							if (exitoso == true) {
								cout << "Pinging to: " << comando.substr(5, comando.size()) << " with 32 bytes of data: " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": bytes=32 time=37s TTL=46 " << endl;
								cout << "Ping statistic for " << comando.substr(5, comando.size()) << " :" << endl;
								cout << "Packets: Sent = 4,Received = 4, Lost = 0 (0% loss)" << endl;
							} else if (exitoso == false) {
								cout << "Pinging to: " << comando.substr(5, comando.size()) << " with 32 bytes of data: " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
								cout << "Reply from: " << comando.substr(5, comando.size()) << ": Destination host unreachable " << endl;
								cout << "Ping statistic for " << comando.substr(5, comando.size()) << " :" << endl;
								cout << "Packets: Sent = 4,Received = 4, Lost = 0 (0% loss)" << endl;
							}
						} else {
							cout << "Pinging to: " << comando.substr(5, comando.size()) << " with 32 bytes of data: " << endl;
							cout << "Requested tomed out." << endl;
							cout << "Requested tomed out." << endl;
							cout << "Requested tomed out." << endl;
							cout << "Requested tomed out." << endl;
							cout << "Ping statistic for " << comando.substr(5, comando.size()) << " :" << endl;
							cout << "Packets: Sent = 4,Received = 0, Lost = 4 (100% loss)" << endl;
						}
					} else if (comando == "exit") {
						exit = true;
					}
				}
				break;
			}
			case 3: {
				cout << "Saliendo del menu........" << endl;

				break;
			}
		}//fin del switch
	}//fin while menu
	return 0;
}
int menu() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Agregar PC" << endl;
	cout << "2. Ingresar PC" << endl;
	cout << "3. Salir " << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cout << endl;
	while(opcion < 1 || opcion > 3) {
		cout << "Seleccione una opcion dentro del rango disponible" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}