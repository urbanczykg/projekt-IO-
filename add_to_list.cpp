#include <filesystem>  
#include <iostream>
#include "head.h"
#include <fstream>
#include <string>
#include <map>
namespace fs = std::filesystem;


using namespace std;

std::string path = "C:/Users/Gabriela/Desktop/studia/io/funkcja1/funkcja1";
std::string ext(".cpp");
std::string exh(".h");
std::list<std::string>pliki;
std::map<string, vector<string >> mapa_nazw_plikow;


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


void fun3()
{

	for (auto it = pliki.begin(); it != pliki.end(); it++)
	{
		ifstream pliki("*it");
		while (!pliki.eof())
		{
			string linijka;
			getline(pliki, linijka);
			string szukamy = "#include";
			size_t gdzie = linijka.find(szukamy);
			if (!(string::npos == linijka.find("#include")))
			{
				gdzie += szukamy.size();
				string nazwa_pliku = linijka.substr(gdzie);

				mapa_nazw_plikow[*it].push_back(nazwa_pliku);

				///map<string, vector<string>>::iterator cur;

				for (auto i = mapa_nazw_plikow.begin(); i != mapa_nazw_plikow.end(); i++) {
					cout << "polaczenia plikow cpp: " << endl;
					if (i->first != "a.out") {
						cout << i->first << ": ";
						for (auto ii = i->second.begin(); ii != i->second.end(); ii++) {
							cout << *ii << " ";
						}

					}

				}
			}

		}
	}
}