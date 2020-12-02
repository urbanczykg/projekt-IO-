
#include <filesystem>  
#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include "head.h"
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;




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
	for (auto it = pliki.begin(); it != pliki.end(); it++)
	{
		ifstream plik(*it);

		while (!plik.eof()) {
			string linijka;
			getline(plik, linijka);
			///cout << linijka << endl;

			string szukany = "#include";
			size_t gdzie = linijka.find(szukany);


			if (linijka.find("#include") != string::npos && linijka.find("<") == string::npos) {
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
			cout << i->first << "-> ";
			for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
			{
				cout << *ii << " ";
			}

		}
		cout << endl;
	}


}

void relation2()
	{

		map<string, vector<string>>mapa_deklaracji_funkcji;
		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);
				///cout << linijka << endl;

				string szukany = "void";
				string szukany1 = "int";
				size_t gdzie = linijka.find(szukany);


				if ((linijka.find(szukany) != string::npos || linijka.find(szukany1) != string::npos) && linijka.find("string") == string::npos && linijka.find("if") == string::npos && linijka.find("for") == string::npos && linijka.find(";") == string::npos)
				{
					gdzie += szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					///cout << nazwa_pliku << endl;
					mapa_deklaracji_funkcji[*it].push_back(nazwa_pliku);

				}
			}
		}

		for (auto i = mapa_deklaracji_funkcji.begin(); i != mapa_deklaracji_funkcji.end(); i++) {
			cout << "Funkcje: " << endl;
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

void relation3()
	{
		map<string, vector<string>>mapa_pol_funkcji;
		string nazwa_funkcji;

		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			string funkcja;
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);

				///cout << linijka << endl;

				string szukany;
				string szukany1;

				size_t gdzie = linijka.find(szukany);
				size_t gdzie1 = linijka.find(szukany1);

				if (linijka.find("int") != string::npos && linijka.find("(){") != string::npos)
				{
					gdzie1 = szukany.size();
					nazwa_funkcji = linijka.substr(gdzie1);
					
				}
					
				if (linijka.find("();") != string::npos && linijka.find("for") == string::npos && linijka.find("while") == string::npos && linijka.find("if") == string::npos && linijka.find(".") == string::npos && linijka.find("void") == string::npos)
				{
					gdzie = szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					///cout << nazwa_pliku << endl;
					mapa_pol_funkcji[nazwa_funkcji].push_back(nazwa_pliku);
				}
				


			}
		}

		for (auto i = mapa_pol_funkcji.begin(); i != mapa_pol_funkcji.end(); i++) {
			cout << "polaczenia funkcji cpp: " << endl;
			if (i->first != "a.out") {
				cout << i->first << "-> ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}
	}

void relation5()
{

	string* nm = new string[10];
	string* unm = new string[10];

	cout << endl << "______________" << endl;
	for (auto it = pliki.begin(); it != pliki.end(); it++)
	{
		ifstream plik(*it);

		while (!plik.eof())
		{
			string linijka;
			getline(plik, linijka);



			string szukany;
			size_t gdzie = linijka.find(szukany);


			for (int i = 0; i < 10; i++) {
				if (linijka.find("namespace") != string::npos && linijka.find("{") != string::npos && linijka.find("find") == string::npos && linijka.find("cout") == string::npos)
				{
					gdzie += szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					nm[i] = nazwa_pliku;


				}

			}
		}
	}
	cout << endl << "______________" << endl;
	for (auto it = pliki.begin(); it != pliki.end(); it++)
	{
		ifstream plik(*it);

		while (!plik.eof())
		{
			string linijka1;
			getline(plik, linijka1);


			string szukany1;

			size_t gdzie1 = linijka1.find(szukany1);

			for (int i = 0; i < 10; i++)
			{


				if (linijka1.find("using") != string::npos && linijka1.find("namespace") != string::npos && linijka1.find("if") == string::npos && linijka1.find("//") == string::npos && linijka1.find("std") == string::npos )
				{
					gdzie1 += szukany1.size();
					string nazwa_pliku1 = linijka1.substr(gdzie1);




					unm[i] = nazwa_pliku1;



				}

			}
		}
	}

	for (int i = 0; i < 1; i++)
	{


		cout << nm[i] << " -> " << unm[i] << endl;

	}

}


void file_nm()
	{
		cout << "POLACZENIE PLIKI -> NAMESPACE" << endl;

		map<string, vector<string>>fs_nm;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);
				///cout << linijka << endl;

				string szukany;
					
				size_t gdzie = linijka.find(szukany);


				if (linijka.find("namespace") != string::npos && linijka.find("using") == string::npos && linijka.find("npos") == string::npos && linijka.find("cout") == string::npos && linijka.find("for") == string::npos && linijka.find("std") == string::npos && linijka.find("strcpy_s") == string::npos) {
					gdzie += szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					///cout << nazwa_pliku << endl;
					fs_nm[*it].push_back(nazwa_pliku);
				}
			}

		}
		///map<string, vector<string>>::iterator cur;

		for (auto i = fs_nm.begin(); i != fs_nm.end(); i++) {
			cout << "Plik - namespace: " << endl;
			if (i->first != "a.out") {
				cout << i->first << "-> ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}
	}

	void file_fun()
	{
		map<string, vector<string>>f_f;
		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			string funkcja;
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);

				///cout << linijka << endl;

				string szukany;

				size_t gdzie = linijka.find(szukany);


				if ((linijka.find("(){") != string::npos || linijka.find("();") != string::npos) && linijka.find("for") == string::npos && linijka.find("while") == string::npos && linijka.find("if") == string::npos && linijka.find(".") == string::npos && linijka.find("void") == string::npos)
				{
					gdzie = szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					///cout << nazwa_pliku << endl;
					f_f[*it].push_back(nazwa_pliku);
				}


			}
		}

		for (auto i = f_f.begin(); i != f_f.end(); i++) {
			cout << "Plik - funkcja: " << endl;
			if (i->first != "a.out") {
				cout << i->first << "-> ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}

		
	}


