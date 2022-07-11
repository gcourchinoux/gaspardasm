/*
Main.cpp
Gaspardasm
Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/

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
	assm.mem.set_memory(1000); // normalement ce paramètre est pris dans les commandes d'invocations
	assm.file = file_char;
	assm.create_tok();
	assm.print_toks();
	assm.scan_tok();
	assm.scan_ast();
}