#pragma once
class Memory
{
public: 

	long long* mem;



	Memory(int o); // o = le nombre d'octects alloués  
	long long operator=(long long data);
	long long operator[](unsigned long long adress);
};

