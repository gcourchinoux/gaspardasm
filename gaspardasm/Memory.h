#pragma once
class Memory
{
public: 

	long long* mem;



	Memory(int o); // o = le nombre d'octects allou�s  
	long long operator=(long long data);
	long long operator[](unsigned long long adress);
};

