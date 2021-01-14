#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <filesystem>  
#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>

	
	void list_of_files();
	void add_to_list();
	void fun_3();
	void relation2();
	void relation3();
	void relation5();
	void file_nm();
	void graph_making(std::map<std::string, std::vector<std::string>>l, std::string name, int o);
	void combined_graf_making(std::map<std::string, std::vector<std::string>>l, std::map<std::string, std::vector<std::string>>x, std::map<std::string, std::vector<std::string>>a, std::map<std::string, std::vector<std::string>>b, std::map<std::string, std::vector<std::string>>h, std::string name);
	void graf_making_2(std::map<std::string, std::vector<std::string>>l, std::map<std::string, std::vector<std::string>>x, std::map<std::string, std::vector<std::string>>h, std::string name);
	void param_of_graph(std::map<std::string, std::vector<std::string>>l);
	void connections(std::map<std::string, std::vector<std::string>>a);
	void cc();
	struct node;
	void push(node*& S, std::string n);
	int check(node* S, std::string n);
	
	

	

#endif
