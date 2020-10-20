#include <filesystem>  
#include <iostream>
#include "head.h"
namespace fs = std::filesystem;


using namespace std;

std::string path = "C:/Users/Gabriela/Desktop/studia/io/funkcja1/funkcja1";
std::string ext(".cpp");
std::string exh(".h");
std::list<std::string>pliki;


void list_of_files() {

	for (const auto& entry : fs::directory_iterator(path)) {
		const auto filenameStr = entry.path().filename().string();
		if (entry.is_regular_file()) {
			std::cout << "file: " << filenameStr << '\n';
		}
		else
			std::cout << "??    " << filenameStr << '\n';
	}
}
template <class Path> typename Path::string_type extension(const Path& p);

void add_to_list()
{




	for (const auto& entry : fs::directory_iterator(path)) {
		const auto filenameStr = entry.path().filename().string();
		if (entry.is_regular_file()) {
			if (entry.path().extension() == ext || entry.path().extension() == exh)
			{
				pliki.push_back(filenameStr);

			}
		}
		

	}
	for (list<string>::iterator it = pliki.begin(); it != pliki.end(); it++)
	{


		cout << *it << endl;
	}

}