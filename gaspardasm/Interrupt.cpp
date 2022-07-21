/*
Manage Interrupts

Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
#include "Interrupt.h"
#include <cstddef>
#include <thread>
// todo faire le temps que le système d'exploitation renvoit


/*
0 : interruption 
1: tentative d'atteinte à la sécurité , execution de prcfg en mode user par exemple
2:bad opcode
3: accès à une adresse non paginée 
4: horloge tick tack toutes les seonces


*/
void Interrupt::tick_time()
{
	int_pending = true; 
	num_of_int_pending = 4;

	std::this_thread::sleep_for(std::chrono::seconds(1));


}

void Interrupt::set_int_config(void* data)
{
}

bool Interrupt::do_int(int i)
{// par défaut interruption 


	int_pending = true; 
	num_of_int_pending = i;


	return true;
}

void Interrupt::set_interrupt_config(interrupt* data, int int_num)
{

	interrupts[int_num].active = data->active;
	interrupts[int_num].adress = data->adress;

}

interrupt* Interrupt::get_int(int num)
{

	return &interrupts[num];
}

void Interrupt::set_time_handler() {



	std::thread time(&Interrupt::tick_time,this);
	time.detach();

}