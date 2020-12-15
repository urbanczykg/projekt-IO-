#include <filesystem>  
#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include "Functions.h"
#include <gtest/gtest.h>

std::string name_copy;
std::string name_2_copy;
std::string name_3_copy;



void graph_making(std::map<std::string, std::vector<std::string>>l, std::string name)
{
	std::ofstream file( name);
	file << "digraph files_graph\n{\n";
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		if (i->first != "a.out")
		{
			for (auto j = i->second.begin(); j != i->second.end(); ++j)
			{
				file << '"' << i->first << '"' << " -> " << '"' << *j << '"'
				<< "\n";
				
			}
		}
	}

	file << "}";
	file.close();
	std::string x = "dot -Tpng -O " + name;
	char tab[100];
	strcpy_s(tab, x.c_str());
	system(tab);

	name_copy = name;
}

TEST(Test_Plikow, Test_1)
{
	std::fstream file(name_copy, std::ios::in | std::ios::_Nocreate);
	ASSERT_TRUE(file.is_open());
	file.close();
}

TEST(Test_Plikow, Test_Zawartosci_1)
{
	std::fstream file(name_copy, std::ios::in | std::ios::_Nocreate);

	while (!file.eof())
	{
		std::string linijka;
		std::getline(file, linijka);

		size_t znalezionaPozycja = linijka.find("->");


		ASSERT_TRUE(znalezionaPozycja != 0); //istnienie -> w pliku
		file.close();
		
	}
}




void combined_graf_making(std::map<std::string, std::vector<std::string>>l, std::map<std::string, std::vector<std::string>>x, std::map<std::string, std::vector<std::string>>a, std::map<std::string, std::vector<std::string>>b, std::map<std::string, std::vector<std::string>>h, std::string name)
{
	std::ofstream file( name);
	file << "digraph files_graph\n{\n";

	for (auto i = h.begin(); i != h.end(); ++i)
	{
		if (i->first != "a.out")
		{
			for (auto j = i->second.begin(); j != i->second.end(); ++j)
			{
				file << '"' << i->first << '"' << " -> " << '"' << *j << '"'
					<< "\n";

			}
		}
	}

	for (auto i = l.begin(); i != l.end(); i++)
	{
			
			for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
			{
				for (auto n = x.begin(); n != x.end(); n++)
				{ 
					if (n->first == *ii)
					{
						for (auto g = n->second.begin(); g != n->second.end(); g++)
						{
							
							file << '"' << i->first << '"' << "->" << '"' << n->first << '"'
								<< "\n";
							file << '"' <<n->first << '"' << "->" << '"' << *g << '"'
								<< "\n";
							
						}
					}
				}
			}
		
	}

	for (auto i = a.begin(); i != a.end(); i++)
	{

		for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
		{
			for (auto n = b.begin(); n != b.end(); n++)
			{
				if (n->first == *ii)
				{
					for (auto g = n->second.begin(); g != n->second.end(); g++)
					{

						file << '"' << i->first << '"' << "->" << '"' << n->first << '"'
							<< "\n";
						file << '"' << n->first << '"' << "->" << '"' << *g << '"'
							<< "\n";

					}
				}
			}
		}

	}
	
	file << "}";
	file.close();
	std::string aa = "dot -Tpng -O " + name;
	char tab[100];
	strcpy_s(tab, aa.c_str());
	system(tab);

	name_2_copy = name;
}

TEST(Test_Plikow, Test_2)
{
	std::fstream file(name_2_copy, std::ios::in | std::ios::_Nocreate);
	ASSERT_TRUE(file.is_open());
	file.close();
}

TEST(Test_Plikow, Test_Zawartosci_2)
{
	std::fstream file(name_2_copy, std::ios::in | std::ios::_Nocreate);

	while (!file.eof())
	{
		std::string linijka;
		std::getline(file, linijka);

		size_t znalezionaPozycja = linijka.find("->");


		ASSERT_TRUE(znalezionaPozycja != 0); //istnienie -> w pliku
		file.close();

	}
}

void graf_making_2(std::map<std::string, std::vector<std::string>>l, std::map<std::string, std::vector<std::string>>x, std::map<std::string, std::vector<std::string>>h, std::string name)
{
	std::ofstream file(name);
	file << "digraph files_graph\n{\n";

	for (auto i = h.begin(); i != h.end(); ++i)
	{
		if (i->first != "a.out")
		{
			for (auto j = i->second.begin(); j != i->second.end(); ++j)
			{
				file << '"' << i->first << '"' << " -> " << '"' << *j << '"'
					<< "\n";

			}
		}
	}

	for (auto i = l.begin(); i != l.end(); i++)
	{

		for (auto ii = i->second.begin(); ii != i->second.end(); ii++)
		{
			for (auto n = x.begin(); n != x.end(); n++)
			{
				if (n->first == *ii)
				{
					for (auto g = n->second.begin(); g != n->second.end(); g++)
					{

						file << '"' << i->first << '"' << "->" << '"' << n->first << '"'
							<< "\n";
						file << '"' << n->first << '"' << "->" << '"' << *g << '"'
							<< "\n";

					}
				}
			}
		}

	}

	file << "}";
	file.close();
	std::string a = "dot -Tpng -O " + name;
	char tab[100];
	strcpy_s(tab, a.c_str());
	system(tab);

	name_3_copy = name;
}

TEST(Test_Plikow, Test_3)
{
	std::fstream file(name_3_copy, std::ios::in | std::ios::_Nocreate);
	ASSERT_TRUE(file.is_open());
	file.close();
}

TEST(Test_Plikow, Test_Zawartosci_3)
{
	std::fstream file(name_3_copy, std::ios::in | std::ios::_Nocreate);

	while (!file.eof())
	{
		std::string linijka;
		std::getline(file, linijka);

		size_t znalezionaPozycja = linijka.find("->");


		ASSERT_TRUE(znalezionaPozycja != 0); //istnienie -> w pliku
		file.close();

	}
}




