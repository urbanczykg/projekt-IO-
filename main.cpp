#include <iostream>
#include "head.h"
#include <list>
#include <filesystem>
#include <string>
#include <functional>


namespace pole_figur
{
	double kolo(const double PI, short r)
	{
		return(PI * r * r);
	}
}
namespace algorytm
{
	using namespace pole_figur;
	void liczba() {
		std::cout << 2.0 * kolo(3, 4);
	}

}
	int main()
	{
		list_of_files();
		//std::cout << "  " << std::endl;
		add_to_list();
		relation();
		relation2();
		relation3();
		std::cout << "XXXXXX" << std::endl;
		relation5();
		
		std::cout << "Nastapi otworzenie grafu zależności plików" << std::endl;
		char gp[50];
		strcpy_s(gp, "graf_pliki.png");
		system(gp);

		std::cout << "Nastapi otworzenie grafu funkcji" << std::endl;
		char gf[50];
		strcpy_s(gf, "graf_funkcje.png");
		system(gf);

		std::cout << "Nastapi otworzenie grafu przestrzeni nazw" << std::endl;
		char gn[50];
		strcpy_s(gn, "graf_namespace.png");
		system(gn);

	
		


			
		
		return 0;
	}

