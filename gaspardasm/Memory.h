#pragma once
class Memory
{
public: 

	long long* mem;



	Memory(); // o = le nombre d'octects alloués  
	void set_pagination_table(unsigned long long adress);
	long long operator[](unsigned long long adress);


	long long read_char(unsigned long long adress);
	long long read_short(unsigned long long adress); 
	long long read_long(unsigned long long adress);
	long long read_long_long(unsigned long long adress); 
	/*
	True = ok 
	false = problème
	*/
	bool write_char(unsigned long long adress,char data);
	bool write_short(unsigned long long adress, short data);
	bool write_long(unsigned long long adress, long data);
	bool write_long_long(unsigned long long adress, long long data);

	/*
	Toujours l'appeller en l'initalisant 
	*/
	void set_memory(int byte);
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


};

struct page_table {


	unsigned char mode : 4; 
	/*
	1 = kernel mode 
	2 only acees in kernel m 
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

	struct page_child child[];
};
struct page_child {

	unsigned char is_writed:1; 

	unsigned char mode : 4; 
	/*
	1= kernel mode
	2= uniquement accès user mode 
	3 = accès dans les deux 
	*/

	unsigned char disabled : 4; 
	/*
	1 = impossible d'écrire
	2= peut uniquement être lu 
	3= peut uniquement être écrit
	*/

	unsigned long long adress; 
	/*
	adresse physique qui est paginée 
	*/

};