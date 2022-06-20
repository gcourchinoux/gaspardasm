#pragma once
#include <string>
#include <iostream>

#include <list>

class Assembleur
{

public:
	Assembleur();
	int size; 
	char* file; 
	void create_tok(); 
	std::list<std::string> toks;
	void print_toks();
};

