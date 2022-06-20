#include <iostream>
#include <fstream>
#include "Assembleur.h"
int file_size; 
char* file_char; 

void open_file(char * filename) {
	std::cout << "nom du fichier : " << filename << std::endl; 
	std::ifstream file(filename, std::ifstream::in);

	if (file.is_open() == false) {

		std::cout << ("Fichier non existant") << std::endl;
	}


	file.seekg(0, file.end);

	int size = file.tellg();
	file_size = size;
	file.seekg(std::ifstream::beg);

	file_char = new char[size];

	file.read(file_char, size);
	file.close();
}
int main(int argc,char *argv[]) {


	// ouverture du fichier 

	open_file(argv[1]);


	Assembleur assm;

	assm.size = file_size ;
	assm.file = file_char;
	assm.create_tok();
	assm.print_toks();
}