#include <iostream>

void PruebaArgumentos(int argc, char** argv)
{
	//si el programa fue lanzado con argumentos..
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << argv[i] << "\n";
			//toda acadena de texto termina con un /0
			int j = 0;
			int value = 0;
			std::cout << " ";

			do
			{
				value = (int)argv[i][j];
				std::cout << argv[i][j] << " = " << value << " 0x" << std::hex << value << "\n ";
				j++;
			} while (argv[i][j] != 0);
			std::cout << "\n";
		}
	}
	else
	{
		std::cout << "No se dieron argumentos. Cerrando\n";
	}
}

void Promedio(int argc, char** argv)
{
	//ejercicio 2 de apuntadores
	//forma C de asignar memoria 
	//int* x = (int*) malloc(sizeof(int));
	// forma C++ de asignar memoria

	/*int* x = new int;

	*x = 99;
	std::cout << "sizeof int " << sizeof(int) << "\n";
	std::cout << " x :" << *x << " en " << x << "\n";

	*x = 'k';
	std::cout << "sizeof int " << sizeof(int) << "\n";
	std::cout << " x :" << *x << " en " << x << "\n";

	*(x + 1) = 18;
	std::cout << " x+1 :" << *(x + 1) << " en " << x + 1 << "\n";*/

	//generar una lista de 100 enteros aleatorios
	 
	int* acumulador = new int;
	*acumulador = 0;
	//saber si continua poniendo numeros o no
	char* continuar = new char;
	*continuar = 10;
	//float division
	float* division = new float;
	*division = 0.0;
	//arreglo de 100 enteros
	int* y = new int[100];
	memset(y, 0, 100 * sizeof(int));

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Escribe un numero\n" << std::endl;
		std::cin >> y[i];

		if (y[i] > 0)
		{
			std::cout << " y[" << i << "] = " << *(y + i) << "\n";
			*division += 1.0;
			*acumulador += y[i];

			std::cout << "quieres continuar?\n";
			std::cin >> *continuar;

			if (*continuar == 115)
			{

			}
			else if (*continuar == 110)
			{
				std::cout << "Aqui esta el promedio: \n";
				break;
			}
		}
	}
	float promedio = *acumulador / *division;
	std::cout << " promedio = " << promedio << "\n";
}

int main(int argc, char** argv)
{
	//apuntador a funcion
	void (*proceso)(int, char**) = nullptr;

	//preguntar al usuario la funcion deseada
	std::cout << "Funciones disponibles: \n";
	std::cout << "  1. Prueba de argumentos \n";
	std::cout << "  2. Promedio: \n";
	std::cout << "Ingresa el numero de la funcion que quieres \n";

	int seleccion;
	std::cin >> seleccion;
	std::cout << seleccion << "mem: " << &seleccion << "\n";
	if (seleccion == 1)
		proceso = &PruebaArgumentos;
	else if (seleccion == 2)
		proceso = &Promedio;
	else
	{
		std::cout << "Opcion no valida\n";
		main(argc, argv);
	}

	(*proceso)(argc, argv);
	return 0;
}