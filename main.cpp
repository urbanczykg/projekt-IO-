#include <iostream>
#include "Functions.h"
#include <list>
#include <filesystem>
#include <string>

#include <gtest/gtest.h>



	namespace pole_figur{

		double kolo(const double PI, short r)
		{
		return(PI * r * r);
		}
	}

	namespace algorytm{

		using namespace pole_figur;

		void liczba()
		{
		std::cout << 2.0 * kolo(3, 4);
		}
	}


	


	int main(int argc, char* argv[]){
		
	
		list_of_files();
		add_to_list();
		fun_3();
		relation2();
		relation3();
		relation5();
		file_nm();


		int x;

		for (;;)
		{
			std::cout << std::endl;
			std::cout << "Wybierz graf lub uruchom testy jednostkowe:" << std::endl;
			std::cout << "Graf pliki - 1" << std::endl;
			std::cout << "Graf funkcje - 2" << std::endl;
			std::cout << "Graf namespace - 3" << std::endl;
			std::cout << "Graf deklaracje - 4" << std::endl;
			std::cout << "Graf pliki-funkcje - 5" << std::endl;
			std::cout << "Graf pliki-namespace - 6" << std::endl;
			std::cout << "Graf pliki-funkcje-namespace - 7" << std::endl;
			std::cout << "TESTY JEDNOSTKOWE - 8" << std::endl;
			std::cin >> x;
			
			switch (x)
			{
			case 1:
				std::cout << "Nastapi otworzenie grafu zaleznosci plikow" << std::endl;
				char gp[50];
				strcpy_s(gp, "nazwy_plikow.dot.png");
				system(gp);
				break;

			case 2:
				std::cout << "Nastapi otworzenie grafu funkcji" << std::endl;
				char gf[50];
				strcpy_s(gf, "graf_funkcje.dot.png");
				system(gf);
				break;

			case 3:
				std::cout << "Nastapi otworzenie grafu przestrzeni nazw" << std::endl;
				char gn[50];
				strcpy_s(gn, "graf_namespace.dot.png");
				system(gn);
				break;

			case 4:
				std::cout << "Nastapi otworzenie grafu deklaracji funkcji" << std::endl;
				char gd[50];
				strcpy_s(gd, "graf_dekl.dot.png");
				system(gd);
				break;

			case 5:
				std::cout << "Nastapi otworzenie grafu pliki - funkcje" << std::endl;
				char gpf[50];
				strcpy_s(gpf, "graf_pliki_funkcje.dot.png");
				system(gpf);
				break;

			case 6:
				std::cout << "Nastapi otworzenie grafu pliki - namespace" << std::endl;
				char gpn[50];
				strcpy_s(gpn, "graf_pliki_namespace.dot.png");
				system(gpn);
				break;

			case 7:
				std::cout << "Nastapi otworzenie grafu pliki - funkcje - namespace" << std::endl;
				char gpnf[50];
				strcpy_s(gpnf, "graf_pliki_funkcje_namespace.dot.png");
				system(gpnf);
				break;

			case 8:
				
				testing::InitGoogleTest(&argc, argv);
				return RUN_ALL_TESTS();

			default:
				break;
			}
		}

		return 0;
	}

	

