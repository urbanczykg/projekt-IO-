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
std::string xxx[17] = { "main", "list_of_files", "add_to_list", "fun_3", "relation2", "relation3", "relation5", "file_nm", "graph_making", "combined_graf_making", "graf_making_2","connected_components","param_of_graph", "cc","push","connections","RemoveDuplicates"};
int number_of_functions = sizeof(xxx)/sizeof(xxx[1]);


struct node 
{
	std::string name;
	std::string done;
	node* next;
};


class Function
{
public:

	int E_edges_of_fthe_graph = 0;
	int N_odes_of_the_graph = 0;
	int P_connceted_components = 0;
	int M;
	

	void show_par(){
		std::cout << std::endl;
		std::cout << "PARAMETERS OF GRAPH" << std::endl;
		std::cout<<std::endl;
		std::cout << "Nodes of the graph: " << N_odes_of_the_graph << std::endl;
		std::cout << "Edges of the graph: " << E_edges_of_fthe_graph << std::endl;
	}


	void cyclomatic_complexity(std::string t){

		std::cout << "Cyclomatic complexity for " << t << " : " << M << std::endl;
	}


	friend void graph_making(std::map<std::string, std::vector<std::string>>l, std::string name, double val);
};

Function graph_par;
Function* func = new Function[number_of_functions];


void push(node*& S, std::string n){

	node* p = new node;
	p->name = n;
	p->next = S;
	S = p;
}


int check(node* S, std::string n, std::string n1){

	node* p = S;
	int counter = 0;
	int counter2 = 0;

	while (p != NULL)
	{
		if (p->name == n || p->name == n1)
		{
			counter++;
			if (counter > 1 && p->done != "yes")
			{
				counter2++;
				p->done = "yes";
			}
		}
		p = p->next;
	}
	return counter2;
}

int check1(node* S, std::string n){

	node* p = S;
	int counter = 0;
	int counter2 = 0;

	while (p != NULL)
	{
		if (p->name == n)
		{
			counter++;
			if (counter > 1 && p->done != "yes")
			{
				counter2++;
				p->done = "yes";
			}
		}
		p = p->next;
	}
	return counter2;
}



void param_of_graph(std::map<std::string, std::vector<std::string>>l){

	node* S = NULL;
	node* SS = NULL;
	
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		std::string h = i->first;
		push(S, h);
		graph_par.N_odes_of_the_graph++;

		for (auto j = i->second.begin(); j != i->second.end(); ++j)
		{
			graph_par.N_odes_of_the_graph++;
			graph_par.E_edges_of_fthe_graph++;

			std::string x = *j;

			push(S, x);
			graph_par.N_odes_of_the_graph = graph_par.N_odes_of_the_graph - check(S, x, h);

			std::string b;
			b = h + x;
			push(SS, b);
			graph_par.E_edges_of_fthe_graph = graph_par.E_edges_of_fthe_graph - check1(SS,b);

		}
	}

	graph_par.show_par();
}

void connected_components(std::string function, int l, std::map<std::string, std::vector<std::string>>a){

	for (auto i = a.begin(); i != a.end(); ++i)
	{
		std::string x = i->first;
		int counter = 0;

		for (auto j = i->second.begin(); j != i->second.end(); ++j)
		{
			counter++;
		}

		std::string comp = " " + function;

		if (comp.compare(x) ==0)
			func[l].P_connceted_components = counter;	
	}
}


void graph_making(std::map<std::string, std::vector<std::string>>l, std::string name, int o){

	std::ofstream file(name);
	file << "strict digraph \n{\n";

	if (o == 1)
	{
		
		for (int i = 0; i < number_of_functions; i++)
		{
				file << xxx[i] << "[ label = " << '"' <<xxx[i]<<" - "<< func[i].M << "\"]"
					<< "\n";
		}

			

		for (auto i = l.begin(); i != l.end(); ++i)
		{
			if (i->first != "a.out")
			{
				for (auto j = i->second.begin(); j != i->second.end(); ++j)
				{
						file << i->first << " -> " << *j
							<< "\n";
				}
			}
		}
	}

	else
	{
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
	std::ofstream file(name);
	file << "strict digraph files_graph\n{\n";

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
	file << "strict digraph files_graph\n{\n";

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

void connections(std::map<std::string, std::vector<std::string>>a){

	for (int i = 0; i < number_of_functions; i++)
	{
		connected_components(xxx[i], i,a);
		func[i].M = graph_par.E_edges_of_fthe_graph - graph_par.N_odes_of_the_graph + (2 * func[i].P_connceted_components);
	}
}

void cc(){

	for (int i = 0; i < number_of_functions; i++)
	{
		func[i].cyclomatic_complexity(xxx[i]);
	}
}






