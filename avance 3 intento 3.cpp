#include <iostream>
#include <stdio.h>
#include<string.h>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;


struct consultorio {
	char paci[100];
	char hrs[100];
	char nomtrat[100];
	float prec;
	int num;
	char desc[1000];
	int catra, total;
	
};
void archivo();

consultorio citas[3];
int main()
{
	int opcion, nuci, a, i, j;
	

	do {
		cout << "bienvenido al consultorio de tatalan (Angel Jonathan Garza Orozco)" << endl;
		cout << "1-Agendar cita <3" << endl;
		cout << "2-Modificar cita <3" << endl;
		cout << "3-Eliminar cita <3" << endl;
		cout << "4-Lista de citas vigentes <3" << endl;
		cout << "5-Limpiar pantalla <3" << endl;
		cout << "6-Salir <3" << endl;
		cin >> opcion;
		

		switch (opcion)
		{
		case 1:

			for (i = 0; i < 3; i++)
			{
				cout << "El numero de cita es:" << endl;
				citas[i].num = i + 1;
				cout << citas[i].num << endl;
				cout << "Ingrese el nombre del paciente" << endl;
				cin >> citas[i].paci;
				cout << "Ingrese la hora del tratamiento (favor de ingresarlo en 24 horas)" << endl;
				cin >> citas[i].hrs;
				cout << "Ingrese el nombre del tratamiento" << endl;
				cin >> citas[i].nomtrat;
				cout << "Ingrese una descripcion" << endl;
				cin.ignore();
				cin.getline(citas[i].desc, 10000, '\n');
				cout << "Ingrese la cantidad del tratamiento" << endl;
				cin >> citas[i].catra;
				cout << "Ingrese el precio unitario" << endl;
				cin >> citas[i].prec;
				citas[i].total = citas[i].prec * citas[i].catra;
				cout << "El total es: $" << citas[i].total << endl;

			}


			cout << "¿¿Desea regresar al menu??" << endl;
			cout << "1-si" << endl;
			cout << "2-no" << endl;
			cin >> a;


			break;
		case 2:
			cout << "Ingrese el numero de cita que desee modificar" << endl;
			cin >> j;
			i = j - 1;
			for (i; i < j; i++)
			{

				cout << "Ingrese el nombre del paciente" << endl;
				cin >> citas[i].paci;
				cout << "Ingrese la hora del tratamiento (favor de ingresarlo en 24 horas)" << endl;
				cin >> citas[i].hrs;
				cout << "Ingrese el nombre del tratamiento" << endl;
				cin >> citas[i].nomtrat;
			}
			break;
		case 3:
			cout << "Ingrese la cita a eliminar" << endl;
			cin >> nuci;
			cout << "¿¿Desea regresar al menu??" << endl;
			cout << "1-si" << endl;
			cout << "2-no" << endl;
			cin >> a;

			break;
		case 4:

			for (i = 0; i < 3; i++)
			{
				cout << "El numero de cita es:  " << citas[i].num << endl;
				cout << "El paciente es: " << citas[i].paci << endl;
				cout << "La hora de la cita es: " << citas[i].hrs << endl;
				cout << "El Tratamiento es: " << citas[i].nomtrat
					<< endl;

			}
			cout << "¿¿Desea regresar al menu??" << endl;
			cout << "1-si" << endl;
			cout << "2-no" << endl;
			cin >> a;

			break;
		case 5:
			system("cls");
			cout << "!!yey ahora tu pantalla esta limpia!!" << endl;
			cout << "¿¿Desea regresar al menu??" << endl;
			cout << "1-si" << endl;
			cout << "2-no" << endl;
			cin >> a;

			break;
		case 6:
			archivo();

			cout << "Muchas gracias por su visita, que tenga un buen dia" << endl;
			
			a = 2;
			
			break;
		default:
			cout << "Ingrese una ocpion valida" << endl;
			a = 1;
			

		}


	} while (a == 1);

}

void archivo()
{
	ofstream archivo;
	string tex;
	
	cout << "citas uwu" << endl;
	archivo.open("citas uwu", ios::out);

	if (archivo.fail())
	{
		cout << "error no se creo su archivo :c";
		exit(1);

	}
	
	
	archivo << "no.de cita" << "\t";
	archivo << "nombre" << "\t";
	archivo << "hora" << "\t";
	archivo << "tratamiento" << "\t";
	archivo << "descripcion" << "\t";
	archivo << "precio unitario" << "\t";
	archivo << "cantidad de tratamiento" << "\t"; 
	archivo << "total" << "\t" << "\n";
	
	for (int i = 0; i < 3; i++)
	{ 

	archivo <<i + 1<< ".-" << "\t" << "\t";
	tex = citas[i].paci;
	archivo << tex << "\t";
	tex = citas[i].hrs;
	archivo << tex << "\t";
	tex = citas[i].nomtrat;
	archivo << tex << "\t" << "\t" << "\t";
	tex = citas[i].desc;
	archivo << tex << "\t" << "\t";
	tex = citas[i].prec;
	archivo << tex << "\t" << "\t";
	tex = citas[i].catra;
	archivo << tex << "\t" << "\t";
	tex = citas[i].total;
	archivo << tex << "\t" << "\n";

}


	archivo.close();
}
