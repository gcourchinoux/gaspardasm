#pragma once
#include <string>
#include <iostream>

#include <list>

class Assembleur
{

public:
	Assembleur();
	bool contain_deux_points(std::string str);
	std::string function_name(std::string str);
	void scan_functions();
	void scan_tok();
	int size; 
	char* file; 
	void create_tok(); 
	std::list<std::string> toks;
	void print_toks();
};

struct opcode_gaspard {
 const 	char* name;
	unsigned char opcode;
	unsigned char num_of_op;// le nombre d'opérandes max 3

	void (*handler)(struct opcode_gaspard* s);

};
// structure tree 

struct tree {

	std::string function_name;


};