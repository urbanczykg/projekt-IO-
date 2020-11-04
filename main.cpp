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
		relation4();
	
		using namespace algorytm;


		liczba();	
		
		return 0;
	}

