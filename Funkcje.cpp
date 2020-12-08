#include <filesystem>  
#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include "Functions.h"

	namespace fs = std::filesystem;

	using namespace std;
	

	std::string path = "C:/Users/Michal/Desktop/AGH/3/IO/PROJEKT_1/IO/IO";
	std::string ext(".cpp");
	std::string exh(".h");
	std::list<std::string>pliki;
	map<string, vector<string>>mapa_nazw_plikow_1;
	map<string, vector<string>>mapa_deklaracji_funkcji_1;
	map<string, vector<string>>mapa_pol_funkcji_1;
	map<string, vector<string>>mapa_pol_namespace_1;

	



	void list_of_files(){

		cout << "ZAWARTOSC FOLDERU: " << endl;
		cout << endl;
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


	void add_to_list(){
		cout << endl << "______________" << endl;
		for (const auto& entry : fs::directory_iterator(path)) {
			const auto filenameStr = entry.path().filename().string();
			if (entry.is_regular_file()) {
				if (entry.path().extension() == ext || entry.path().extension() == exh)
				{
					pliki.push_back(filenameStr);

				}
			}
		}
		cout << endl;
		cout << "ZAWARTOSC PROJEKTU:" << endl;
		cout << endl;
		for (list<string>::iterator it = pliki.begin(); it != pliki.end(); it++)
		{
			cout << *it << endl;
			cout << endl;
		}

	}


	void fun_3(){
		map<string, vector<string>>mapa_nazw_plikow;
		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);
				
				string szukany;
				size_t gdzie = linijka.find(szukany);


				if (linijka.find("#include") != string::npos && linijka.find("<") == string::npos) {
					gdzie += szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					
					nazwa_pliku.erase(remove(nazwa_pliku.begin(), nazwa_pliku.end(), '"'), nazwa_pliku.end());
					nazwa_pliku.erase(0,8);
					
					mapa_nazw_plikow[*it].push_back(nazwa_pliku);
				}
			}

		}
		
		cout << "POLACZENIA PLIKOW: " << endl;

		for (auto i = mapa_nazw_plikow.begin(); i != mapa_nazw_plikow.end(); i++) {
			cout << endl;
			if (i->first != "a.out") {
				cout << i->first << ": ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}
		
		std::string name = "nazwy_plikow.dot";
		graph_making(mapa_nazw_plikow, name);
		mapa_nazw_plikow_1 = mapa_nazw_plikow;

	}


	void relation2(){

		map<string, vector<string>>mapa_deklaracji_funkcji;
		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);
				
				string szukany;
				size_t gdzie = linijka.find(szukany);


				if ((linijka.find("void") != string::npos || linijka.find("int") != string::npos) && linijka.find("if") == string::npos && linijka.find("for") == string::npos && linijka.find(";") == string::npos)
				{
					gdzie += szukany.size();
					string nazwa_pliku = linijka.substr(gdzie);
					nazwa_pliku.erase(nazwa_pliku.find("("));

					string del = "void";
					string del1 = "int";
					size_t pos = nazwa_pliku.find(del);
					size_t pos1 = nazwa_pliku.find(del1);
					if (pos != std::string::npos)
					{
						nazwa_pliku.erase(pos, del.length());
					}
					else if (pos1 != std::string::npos)
					{
						nazwa_pliku.erase(pos1, del1.length());
					}

					mapa_deklaracji_funkcji[*it].push_back(nazwa_pliku);
				}
			}
		}
		cout << "DEKLARACJE FUNKCJI: " << endl;
		for (auto i = mapa_deklaracji_funkcji.begin(); i != mapa_deklaracji_funkcji.end(); i++) {
			cout << endl;
			if (i->first != "a.out") {
				cout << i->first << ": ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}

		std::string name = "graf_dekl.dot";
		graph_making(mapa_deklaracji_funkcji, name);

		mapa_deklaracji_funkcji_1 = mapa_deklaracji_funkcji;
	}

	

	void relation3(){
		map<string, vector<string>>mapa_pol_funkcji;
		string nazwa_funkcji;

		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			string funkcja;
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);

				string szukany;
				string szukany1;

				size_t gdzie = linijka.find(szukany);
				size_t gdzie1 = linijka.find(szukany1);

				if ((linijka.find("int") != string::npos || linijka.find("void") != string::npos) && linijka.find("(){") != string::npos && linijka.find("if") == string::npos)
				{
					gdzie1 = szukany.size();
					nazwa_funkcji = linijka.substr(gdzie1);
					nazwa_funkcji.erase(nazwa_funkcji.find("("));

					string del = "void";
					string del1 = "int";
					size_t pos = nazwa_funkcji.find(del);
					size_t pos1 = nazwa_funkcji.find(del1);
					if (pos != std::string::npos)
					{
						nazwa_funkcji.erase(pos, del.length());
					}
					else if (pos1 != std::string::npos)
					{
						nazwa_funkcji.erase(pos1, del1.length());

					}
					
				}
					
				if (linijka.find("(") != string::npos && linijka.find(");") != string::npos && linijka.find("for") == string::npos && linijka.find("std") == string::npos && linijka.find("return") == string::npos && linijka.find("while") == string::npos && linijka.find("if") == string::npos && linijka.find(".") == string::npos && linijka.find("void") == string::npos && linijka.find("system") == string::npos && linijka.find("getline") == string::npos && linijka.find("template") == string::npos)
				{
					gdzie = szukany.size();
					string nazwa_funkcji1 = linijka.substr(gdzie);
					
					nazwa_funkcji1.erase(nazwa_funkcji1.find("("));
					mapa_pol_funkcji[nazwa_funkcji].push_back(nazwa_funkcji1);
				}
			}
		}
		cout << "POLACZENIA FUNKCJI: " << endl;
		for (auto i = mapa_pol_funkcji.begin(); i != mapa_pol_funkcji.end(); i++) {
			cout << endl;
			if (i->first != "a.out") {
				cout << i->first << "-> ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}

		std::string name = "graf_funkcje.dot";
		graph_making(mapa_pol_funkcji, name);

		std::string name1 = "graf_pliki_funkcje.dot";
		graf_making_2(mapa_deklaracji_funkcji_1, mapa_pol_funkcji, mapa_nazw_plikow_1, name1);

		mapa_pol_funkcji_1 = mapa_pol_funkcji;
		
	}
	

	void relation5(){
		map<string, vector<string>>mapa_pol_namespace;
		string nms;


		cout << endl << "______________" << endl;
		for (auto it = pliki.begin(); it != pliki.end(); it++)
		{
			ifstream plik(*it);

			while (!plik.eof())
			{
				string linijka;
				getline(plik, linijka);



				string szukany;
				string szukany1;
				size_t gdzie = linijka.find(szukany);
				size_t gdzie1 = linijka.find(szukany1);



				if (linijka.find("namespace") != string::npos && linijka.find("{") != string::npos && linijka.find("find") == string::npos && linijka.find("cout") == string::npos && linijka.find("strcpy_s") == string::npos)
				{
					gdzie += szukany.size();
					nms = linijka.substr(gdzie);

					nms.erase(nms.find("{"));

					string del = "namespace";
					size_t pos = nms.find(del);
					if (pos != std::string::npos)
					{
						nms.erase(pos, del.length());
					}

				}

				if (linijka.find("using") != string::npos && linijka.find("namespace") != string::npos && linijka.find("if") == string::npos && linijka.find("//") == string::npos && linijka.find("std") == string::npos)
				{
					gdzie1 = szukany1.size();
					string nmss = linijka.substr(gdzie1);
					

					nmss.erase(nmss.find(";"));
					string del1 = "using";
					size_t pos1 = nmss.find(del1);
					if (pos1 != std::string::npos)
					{
						nmss.erase(pos1, del1.length());
					}
					string del2 = "namespace";
					size_t pos2 = nmss.find(del2);
					if (pos2 != std::string::npos)
					{
						nmss.erase(pos2, del2.length());
					}
		
					mapa_pol_namespace[nms].push_back(nmss);

				}

			}
		
		}
		cout << "POLACZENIA NAMESPACE: " << endl;
		for (auto i = mapa_pol_namespace.begin(); i != mapa_pol_namespace.end(); i++) {
			cout << endl;
			if (i->first != "a.out") {
				cout << i->first << "-> ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}

		std::string name = "graf_namespace.dot";
		graph_making(mapa_pol_namespace, name);

		mapa_pol_namespace_1 = mapa_pol_namespace;


	}

	void file_nm(){
		cout << endl << "______________" << endl;
		map<string, vector<string>>fs_nm;
		for (auto it = pliki.begin(); it != pliki.end(); it++) {
			ifstream plik(*it);

			while (!plik.eof()) {
				string linijka;
				getline(plik, linijka);

				string szukany;
					
				size_t gdzie = linijka.find(szukany);


				if (linijka.find("namespace") != string::npos && linijka.find("using") == string::npos && linijka.find("npos") == string::npos && linijka.find("cout") == string::npos && linijka.find("string") == string::npos && linijka.find("for") == string::npos && linijka.find("std") == string::npos && linijka.find("strcpy_s") == string::npos && linijka.find("map") == string::npos) {
					gdzie += szukany.size();
					string nazwa_nm = linijka.substr(gdzie);

					nazwa_nm.erase(nazwa_nm.find("{"));

					string del = "namespace";
					size_t pos = nazwa_nm.find(del);
					if (pos != std::string::npos)
					{
						nazwa_nm.erase(pos, del.length());
					}
					
					fs_nm[*it].push_back(nazwa_nm);
				}
			}

		}
		
		cout << "POLACZENIA PLIKI -> NAMESPACE" << endl;
		for (auto i = fs_nm.begin(); i != fs_nm.end(); i++) {
			cout <<  endl;
			if (i->first != "a.out") {
				cout << i->first << "-> ";
				for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
				{
					cout << *ii << " ";
				}

			}
			cout << endl;
		}

		std::string name1 = "graf_pliki_namespace.dot";
		graf_making_2(fs_nm,mapa_pol_namespace_1, mapa_nazw_plikow_1, name1);

		std::string name2 = "graf_pliki_funkcje_namespace.dot";
		combined_graf_making(mapa_deklaracji_funkcji_1, mapa_pol_funkcji_1, fs_nm, mapa_pol_namespace_1, mapa_nazw_plikow_1, name2);
	}

	
	

	

	

	
