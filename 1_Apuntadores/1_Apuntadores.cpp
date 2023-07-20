#include <iostream>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << argv[i] << "\n";
			//Toda cadena de texto termina en /0
			int j = 0;
			int value = 0;
			std::cout << " ";
			do
			{
				value = int(argv[i][j]);
				std::cout << argv[i][j] << " = " << value << " 0x" << std::hex << value << "\n ";
				j++;
			} while (argv[i][j] != 0);

			std::cout << "\n";
		}
	}
	else {
		std::cout << "No hay argumentos\n";
	}

    return 0;
}