
#include <filesystem>  
#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include "head.h"
namespace fs = std::filesystem;


using namespace std;

std::string path = "C:/Users/Gabriela/Desktop/studia/io/funkcja1/funkcja1";
std::string ext(".cpp");
std::string exh(".h");
std::list<std::string>pliki;
//std::map<std::string, std::vector<std::string>> mapa_nazw_plikow;



void list_of_files() {

	cout << "zawartosc folderu: " << endl;
	for (const auto& entry : fs::directory_iterator(path)) {
		const auto filenameStr = entry.path().filename().string();
		if (entry.is_regular_file()) {
			std::cout << filenameStr << '\n';
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
	cout << "zawartosc projektu:" << endl;
	for (list<string>::iterator it = pliki.begin(); it != pliki.end(); it++)
	{


		cout << *it << endl;
	}

}

void relation() {
	map<string, vector<string>>mapa_nazw_plikow;
	cout << endl << "______________" << endl;
	for (auto it = pliki.begin(); it != pliki.end(); it++) {
		ifstream plik(*it);

		while (!plik.eof()) {
			string linijka;
			getline(plik, linijka);
			///cout << linijka << endl;

			string szukany = "#include"
				;
			size_t gdzie = linijka.find(szukany);


			if (linijka.find("#include") != string::npos&& linijka.find("<")==string::npos) {
				gdzie += szukany.size();
				string nazwa_pliku = linijka.substr(gdzie);
				///cout << nazwa_pliku << endl;
				mapa_nazw_plikow[*it].push_back(nazwa_pliku);
			}
		}

	}
	///map<string, vector<string>>::iterator cur;

	for (auto i = mapa_nazw_plikow.begin(); i != mapa_nazw_plikow.end(); i++) {
		cout << "polaczenia plikow cpp: " << endl;
		if (i->first != "a.out") {
			cout << i->first << ": ";
			for (auto ii = i->second.begin(); ii != i->second.end(); ii++) 
			{
				cout << *ii << " ";
			}

		}
		cout << endl;
	}


}