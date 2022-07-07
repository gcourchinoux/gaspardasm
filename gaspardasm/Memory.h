#pragma once
class Memory
{
public: 

	long long* mem;



	Memory(); // o = le nombre d'octects allou�s  
	void set_pagination_table(unsigned long long adress);
	long long operator[](unsigned long long adress);


	long long read_char(unsigned long long adress);
	long long read_short(unsigned long long adress); 
	long long read_long(unsigned long long adress);
	long long read_long_long(unsigned long long adress); 
	/*
	True = ok 
	false = probl�me
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

