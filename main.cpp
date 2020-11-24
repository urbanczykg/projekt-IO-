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
		
		file_nm();
		file_fun();
		

		int x;

		for (;;)
		{
			std::cout<<std::endl;
			std::cout << "Wybierz graf:" << std::endl;
			std::cout << "Graf pliki - 1" << std::endl;
			std::cout << "Graf funkcje - 2" << std::endl;
			std::cout << "Graf namespace - 3" << std::endl;
			std::cout << "Graf pliki-funkcje - 4" << std::endl;
			std::cout << "Graf pliki-namespace - 5" << std::endl;
			std::cout << "Graf pliki-funkcje-namespace - 6" << std::endl;
			std::cin >> x;

			switch (x)
			{
			case 1:
				std::cout << "Nastapi otworzenie grafu zależności plików" << std::endl;
				char gp[50];
				strcpy_s(gp, "graf_pliki.png");
				system(gp);
				break;

			case 2:
				std::cout << "Nastapi otworzenie grafu funkcji" << std::endl;
				char gf[50];
				strcpy_s(gf, "graf_funkcje.png");
				system(gf);
				break;

			case 3:
				std::cout << "Nastapi otworzenie grafu przestrzeni nazw" << std::endl;
				char gn[50];
				strcpy_s(gn, "graf_namespace.png");
				system(gn);
				break;

			case 4:
				std::cout << "Nastapi otworzenie grafu pliki - funkcje" << std::endl;
				char gpf[50];
				strcpy_s(gpf, "graf_pliki_funkcje.png");
				system(gpf);
				break;

			case 5:
				std::cout << "Nastapi otworzenie grafu pliki - namespace" << std::endl;
				char gpn[50];
				strcpy_s(gpn, "graf_pliki_namespace.png");
				system(gpn);
				break;

			case 6:
				std::cout << "Nastapi otworzenie grafu pliki - funkcje - namespace" << std::endl;
				char gpnf[50];
				strcpy_s(gpnf, "graf_pliki_funkcje_ns.png");
				system(gpnf);
				break;


			default:
				break;




			}
		}


	
		


			
		
		return 0;
	}

