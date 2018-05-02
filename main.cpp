#include <string>
#include <iostream>     /* atof, atoi */
#include <vector>
#include "dni.hpp"
#include "nodebb.hpp"
#include "abb.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
	
	int option;
	int op2 = 5;
	int size;
	int npruebas;
	cout << "INTRODUZCA LA OPCION QUE DESEA: " << endl;
	cout << "	1.- MODO DEMO" << endl;
	cout << "	2.- MODO ESTADISTICA" << endl;
	cout << "opcion: ";
	cin >> option;
	switch (option) {
	case 1: {
		abb<int> demo;
		while (op2 != 0) {
			cout << "INTRODUZCA LA OPCION QUE DESEA: " << endl;
			cout << "	0.- SALIR" << endl;
			cout << "	1.- INSERTAR" << endl;
			cout << "	2.- EXTRAER" << endl;
			cout << "opcion: ";
			cin >> op2;
			switch (op2) {
			case 1: {
				int val;
				cout << "INTRODUZCA VALOR: ";
				cin >> val;
				demo.insert(val);
				cout << demo;
				break;
			}
			case 2: {
				int val;
				cout << "INTRODUZCA VALOR: ";
				cin >> val;
				demo.eliminar(val);
				cout << demo;
				break;
			}
			}
		}
		break;
	}
	case 2:
		cout << "INTRODUZCA EL TAMAÑO DEL ARBOL QUE DESEA: ";
		cin >> size;
		cout << endl;

		cout << "INTRODUZCA EL NUMERO DE PRUEBAS QUE DESEA: ";
		cin >> npruebas;
		cout << endl;

		srand(time(NULL));
		vector<dni> banco;
		banco.resize(2*size);

		abb<dni> stat;
		for (int i = 0; i < size; i++) {
			stat.insert(banco[i]);
		}

		int min, max, avg;
		min = 123123123;
		max = 0;
		avg = 0;
		int compare = 0;
		
		cout << endl << endl << endl;
		cout << "###### BUSQUEDAS ######";

		for (int i = 0; i < npruebas; i++) {
			compare = 1;
			compare = stat.search(banco[i]);

			if (compare < min) {
				min = compare;
			}

			if (compare > max) {
				max = compare;
			}
			avg += compare;


		}

		avg = avg / npruebas;
		cout << endl;
		cout << "min:	" << min << endl;
		cout << "max:	" << max << endl;
		cout << "avg:	" << avg << endl;

		cout << endl << endl << endl;
		cout << "###### INSERCIONES ######";

		min = 123123123;
		max = 0;
		avg = 0;

		for (int i = (banco.size() - 1); i > (banco.size() - npruebas); i--) {
			compare = 1;
			compare = stat.insert(banco[i]);

			if (compare < min) {
				min = compare;
			}

			if (compare > max) {
				max = compare;
			}
			avg += compare;


		}

		avg = avg / npruebas;
		cout << endl;
		cout << "min:	" << min << endl;
		cout << "max:	" << max << endl;
		cout << "avg:	" << avg << endl;

		break;
	}
}
