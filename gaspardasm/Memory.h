/*
Manage the gaspardasm memory
Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
#pragma once
#include "Interrupt.h"

class Memory
{
public: 

	long long* mem;



	Memory();
	bool check(struct page_table* table, struct page_child* ch,bool read);
	// o = le nombre d'octects alloués  
	void update_exec(bool exec_mode);
	void set_pagination_table(unsigned long long adress);
	struct page_table* get_page(int page_num);
	struct page_table* resolve_adress(unsigned long long adress);
	long long operator[](unsigned long long adress);


	char read_char(unsigned long long adress);
	short read_short(unsigned long long adress);
	unsigned long read_unsigned_long(unsigned long long adress);

	long  read_long(unsigned long long adress);
	long long read_long_long(unsigned long long adress);
	unsigned char read_unsigned_char(unsigned long long adress);

	unsigned short read_unsigned_short(unsigned long long adress);

	/*
	True = ok 
	false = problème
	*/
	unsigned long long read_unsigned_long_long(unsigned long long adress);
	bool write_char(unsigned long long adress,char data);
	bool write_short(unsigned long long adress, short data);
	bool write_long(unsigned long long adress, long data);
	bool write_long_long(unsigned long long adress, long long data);

	bool write_unsigned_char(unsigned long long adress, unsigned char data);

	bool write_unsigned_short(unsigned long long adress, unsigned short data);

	bool write_unsigned_long(unsigned long long adress, unsigned long data);

	bool write_unsigned_long_long(unsigned long long adress, unsigned long long data);

	/*
	Toujours l'appeller en l'initalisant 
	*/
	void set_memory(int byte);


	void* get_adress(unsigned long long adress);
	struct pag_general_config* general_config;
	struct page_table* pages;
	/*
	true = kernel mode 
	false = user mode
	*/
	bool exec_mode;


	Interrupt* int_;
};
struct page_child {

	unsigned char is_writed : 1;

	unsigned char mode : 4;
	/*
	1= kernel mode
	2= uniquement accès user mode
	3 = accès dans les deux
	*/

	unsigned char disabled : 4;
	/*
	1 = peut être écrit et lu
	2= peut uniquement être lu
	3= peut uniquement être écrit
	*/

	unsigned long long adress;
	/*
	adresse physique qui est paginée
	*/

};
struct pag_general_config {

	unsigned short pag_table_num; 
	unsigned char num_pag_child; 
	unsigned char child_size; 

	/*
	1= 512 bytes 

	2 = 1 kilobytes 

	3 = 1 mégabytes 
	
	*/

	unsigned long long adress_of_page; // adresse physique
};

struct page_table {


	unsigned char mode : 4; 
	/*
	1 = kernel mode 
	2 only acees in user mode
	3 = access in both mode 
	*/
	unsigned char disabled : 4; 
	/*
	1 page cannot be writed or read

	2 this page can only be read 
	3 rthis page can only be writed
	*/
	unsigned char present : 1; 
	/*
	doit être présent pour être effectif
	*/

	struct page_child child[10];
};


struct adress {
	unsigned short page_table;
	unsigned char child_table : 4;  // position child
	unsigned long long offset : 44;


};