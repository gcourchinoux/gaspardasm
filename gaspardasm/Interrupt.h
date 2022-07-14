#pragma once
/*
Manage Interrupts 

Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
/*
TODO : 

faire ,le temps 


ATTENTION: CETTE CLASSE N'A PAS ACCES A lA MEMOIRE DIRECTEMENT

Un thread tourne dans Assembleur.cpp pour déterminer quand faire une interruption 
les variables int_pending et num_of_int_pendign permettent d'indiquer respectivement s'il y a  interruption et le numéro de celle ci. 




*/

class Interrupt
{



	void tick_time(); 
	/*
	Configurer la table des interruptions récuprer la structure dans un pointeur puis la passer dans cette méthode 
	*/
	void set_int_config(void* data); 

	bool do_int(int i);
	
	/*
	Tableau d'interrupt
	*/
	struct interrupt interrupts[254];
	/*
	permet de configurer une inteupprtion voulue prcfg appelle cette méthode
	*/
	void set_interrupt_config(struct interrupt *data,int int_num);

	/*
	Dans Assembleur.cpp il y aun theread qui regarde l'interruption en cours et qui modifie l'adresse de GPR1 et qui execute.
	
	*/
	bool int_pending; 
	int num_of_int_pending;
};

struct interrupt {

	unsigned char active : 1; 

	unsigned long adress;


};