/*
parse tokens and execute.

Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
#include "Assembleur.h"
#include <string.h>
#include <thread>


/*

TODO : 

FAIRE LE CHANGEMENT DE GPR1 POUR EXECUTER LE CODE D?S CHANGEMENT AVERTIR LE SYST87ME ET CHANGER LE POINTEUR 




*/

void Assembleur::thread_check_int() {

	while (true) {
		if (int_->int_pending == true) {

			// changer gpr1 
			struct interrupt* int_data = int_->get_int(int_->num_of_int_pending);

			regs[1] =int_data->adress ;


		}


	}


}

void or_(struct opcode_gaspard* s) {


}
void xor_ (struct opcode_gaspard* s) {


}
void and_ (struct opcode_gaspard* s) {


}
void not_(struct opcode_gaspard* s) {


}

void shfl(struct opcode_gaspard* s) {


}

void shfr(struct opcode_gaspard* s) {


}


void mult(struct opcode_gaspard* s) {


}

void add(struct opcode_gaspard* s) {


}

void addc(struct opcode_gaspard* s) {


}

void subc(struct opcode_gaspard* s) {


}

void sub(struct opcode_gaspard* s) {


}

void inc(struct opcode_gaspard* s) {


}

void dec(struct opcode_gaspard* s) {


}
void modul(struct opcode_gaspard* s) {


}


void div_(struct opcode_gaspard* s) {


}

void divs(struct opcode_gaspard* s) {


}

void cmp(struct opcode_gaspard* s) {


}

void disp(struct opcode_gaspard* s) {


}

void dispa(struct opcode_gaspard* s) {


}
void disp_imm_to_pointer(struct opcode_gaspard* s) {


}

void disp_pointer_to_imm(struct opcode_gaspard* s) {


}

void push(struct opcode_gaspard* s) {


}

void pop(struct opcode_gaspard* s) {


}
void prcfg(struct opcode_gaspard* s) {


}

void ret(struct opcode_gaspard* s) {


}

void syscall_(struct opcode_gaspard* s) {


}

void void_(struct opcode_gaspard* s) {


}

void calle(struct opcode_gaspard* s) {


}

void callz(struct opcode_gaspard* s) {


}

void callc(struct opcode_gaspard* s) {


}

void callo(struct opcode_gaspard* s) {


}

void callrz(struct opcode_gaspard* s) {


}
void callrc(struct opcode_gaspard* s) {


}

void callro(struct opcode_gaspard* s) {


}

void dispab(struct opcode_gaspard* s) {


}

void dispab_read(struct opcode_gaspard* s) {


}

void dispas_write(struct opcode_gaspard* s) {


}

void dispas_read(struct opcode_gaspard* s) {


}

void dispal_write(struct opcode_gaspard* s) {


}

void dispal_read(struct opcode_gaspard* s) {


}

struct opcode_gaspard opcodes[] = {

 {"or",10,2, or_ },
  {"xor",8,2,xor_},
  {"and",9,2,and_},
  {"not",11,1,not_},
  {"shfl",18,2,shfl},
  {"shfr",13,2,shfr},
  {"mult",7,2,mult},
  {"add",46,2,add},
  {"addc",26,2,addc},
  {"sub",5,2,sub},
  {"subc",27,2,subc},
  {"inc",4,1,inc},
  {"dec",153,1,dec},
  {"modul",25,2,modul},
  {"div",28,2,div_},
  {"divs",29,2,divs},
  {"cmp",16,2,cmp},
  {"disp",44,2,disp},
  {"dispa",3,2,dispa},
  {"dispa",30,2,disp_imm_to_pointer},
  {"dispa",31,2,disp_pointer_to_imm},
  {"push",35,1,push},
  {"pop",33,1,pop},
  {"prcfg",150,1,prcfg},
  {"ret",32,1,ret},
  {"syscall",36,1,syscall_},
  {"void",0,1,void_},
  {"bne",154,1,calle},
  {"beq",19,1,callz},
  {"blt",20,1,callc},
  {"bltu",21,1,callo},
  {"bgt",22,1,callrz},
  {"bgtu",23,1,callrc},
  {"bge",24,1,callro},
  {"dispab_write",112,1,dispab},
  {"dispab_read",111,1,dispab_read},
  {"dispas_write",40,1,dispas_write},
  {"dispas_read",41,1,dispas_read},
  {"dispal_write",45,1,dispal_write},
  {"dispal_read",47,1,dispal_read},
  {"ble",156,1,NULL},
  {"jmp",157,1,NULL},
  {"jsr",158,1,NULL},
  {"jsra",159,1,NULL},

};


Assembleur::Assembleur() {



}
bool Assembleur::contain_deux_points(std::string str) {


	char* str2 = (char*)str.c_str();

	for (int x = 0; x < strlen(str2);x++) {

		if (str2[x] == ':') {

			return true;
		}


	}




	return false;

}
std::string Assembleur::function_name(std::string str) {

	char* str2 = (char*)str.c_str();

	std::string tmp_str = "";

	for (int x = 0; x < strlen(str2); x++) {
		if (str2[x] == ':') {

			break;
		}
		tmp_str += str2[x];
	}


	return tmp_str;
}
void Assembleur::scan_functions() {

	std::list<std::string>::iterator itt;
	for (itt = toks.begin(); itt != toks.end(); ++itt) {
		std::string tmp = *itt;
		

		if (contain_deux_points(tmp) == true) {

			std::string func_name = function_name(tmp);

		}

		// pas opcode peut ?tre drapeau du compilateur ou delcaration de fonction

	}





}
unsigned char gpr_fpr(char* argument) {
	if (strcmp(argument, "GPR0") == 0) {
		//~ return 34;
		return 0;
	}
	else if (strcmp(argument, "GPR1") == 0) {
		return 1;
	}
	else if (strcmp(argument, "GPR2") == 0) {
		return 2;
	}
	else if (strcmp(argument, "GPR3") == 0) {
		return 3;
	}
	else if (strcmp(argument, "GPR4") == 0) {
		return 4;
	}
	else if (strcmp(argument, "GPR5") == 0) {
		return 5;
	}
	else if (strcmp(argument, "GPR6") == 0) {
		return 6;
	}
	else if (strcmp(argument, "GPR7") == 0) {
		return 7;
	}
	else if (strcmp(argument, "GPR8") == 0) {
		return 8;
	}
	else if (strcmp(argument, "GPR9") == 0) {
		return 9;
	}
	else if (strcmp(argument, "GPR10") == 0) {
		return 10;
	}
	else if (strcmp(argument, "GPR11") == 0) {
		return 11;
	}
	else if (strcmp(argument, "GPR12") == 0) {
		return 12;
	}
	else if (strcmp(argument, "GPR13") == 0) {
		return 13;
	}
	else if (strcmp(argument, "GPR14") == 0) {
		return 14;
	}
	else if (strcmp(argument, "GPR15") == 0) {
		return 15;
	}
	else if (strcmp(argument, "GPR16") == 0) {
		return 16;
	}
	else if (strcmp(argument, "GPR17") == 0) {
		return 17;
	}
	else if (strcmp(argument, "GPR18") == 0) {
		return 18;
	}
	else if (strcmp(argument, "GPR19") == 0) {
		return 19;
	}
	else if (strcmp(argument, "GPR20") == 0) {
		return 20;
	}
	else if (strcmp(argument, "GPR21") == 0) {
		return 21;
	}
	else if (strcmp(argument, "GPR22") == 0) {
		return 22;
	}
	else if (strcmp(argument, "GPR23") == 0) {
		return 23;
	}
	else if (strcmp(argument, "GPR24") == 0) {
		return 24;
	}
	else if (strcmp(argument, "GPR25") == 0) {
		return 25;
	}
	else if (strcmp(argument, "GPR26") == 0) {
		return 26;
	}
	else if (strcmp(argument, "GPR27") == 0) {
		return 27;
	}
	else if (strcmp(argument, "GPR28") == 0) {
		return 28;
	}
	else if (strcmp(argument, "GPR29") == 0) {
		return 29;
	}
	else if (strcmp(argument, "GPR30") == 0) {
		return 30;
	}
	else if (strcmp(argument, "GPR31") == 0) {
		return 31;
	}
	else if (strcmp(argument, "FPR0") == 0) {
		return 32;
	}
	else if (strcmp(argument, "FPR1") == 0) {
		return 33;
	}
	else if (strcmp(argument, "FPR2") == 0) {
		return 34;
	}
	else if (strcmp(argument, "FPR3") == 0) {
		return 35;
	}
	else if (strcmp(argument, "FPR4") == 0) {
		return 36;
	}
	else if (strcmp(argument, "FPR5") == 0) {
		return 37;
	}
	else if (strcmp(argument, "FPR6") == 0) {
		return 38;
	}
	else if (strcmp(argument, "FPR7") == 0) {
		return 39;
	}
	else if (strcmp(argument, "FPR8") == 0) {
		return 40;
	}
	else if (strcmp(argument, "FPR9") == 0) {
		return 41;
	}
	else if (strcmp(argument, "FPR10") == 0) {
		return 42;
	}
	else if (strcmp(argument, "FPR11") == 0) {
		return 43;
	}
	else if (strcmp(argument, "FPR12") == 0) {
		return 44;
	}
	else if (strcmp(argument, "FPR13") == 0) {
		return 45;
	}
	else if (strcmp(argument, "FPR14") == 0) {
		return 46;
	}
	else if (strcmp(argument, "FPR15") == 0) {
		return 47;
	}
	else if (strcmp(argument, "FPR16") == 0) {
		return 48;
	}
	else if (strcmp(argument, "FPR17") == 0) {
		return 49;
	}
	else if (strcmp(argument, "FPR18") == 0) {
		return 50;
	}
	else if (strcmp(argument, "FPR19") == 0) {
		return 51;
	}
	else if (strcmp(argument, "FPR20") == 0) {
		return 52;
	}
	else if (strcmp(argument, "FPR21") == 0) {
		return 53;
	}
	else if (strcmp(argument, "FPR22") == 0) {
		return 54;
	}
	else if (strcmp(argument, "FPR23") == 0) {
		return 55;
	}
	else if (strcmp(argument, "FPR24") == 0) {
		return 56;
	}
	else if (strcmp(argument, "FPR25") == 0) {
		return 57;
	}
	else if (strcmp(argument, "FPR26") == 0) {
		return 58;
	}
	else if (strcmp(argument, "FPR27") == 0) {
		return 59;
	}
	else if (strcmp(argument, "FPR28") == 0) {
		return 60;
	}
	else if (strcmp(argument, "FPR29") == 0) {
		return 61;
	}
	else if (strcmp(argument, "FPR30") == 0) {
		return 62;
	}
	else if (strcmp(argument, "FPR31") == 0) {
		return 63;
	}
	else if (strcmp(argument, "RETGPR") == 0) {
		return 32;
	}
	else {

		return 254;
	}


}
/*
Appel au d?part pour initlaiser les modes du processeur virtuel
*/
void Assembleur::init() {

	is_kernel_mode = true;

	mem.update_exec(is_kernel_mode);

	int_ = new Interrupt();

	// d?clenecher le thread et le d?tacher

	mem.int_ = int_;
	std::thread th(&Assembleur::thread_check_int,this);
	th.detach();
	int_->set_time_handler();
	// vga : 

	vga = new Vga();
	mem.vga = vga;

	vga->init(); 
}
void Assembleur :: clear_flags() {


	equal = false; 
	negative = false; 
	carry = false; 
	overflow = true; 
}
// todo a finir en fonction des conditions des branches 
void Assembleur::check_data(long data,long data2) {



	if (data <0 || data2 <0) {

		negative = true;
	}

	if (data & 1<< 63) {

		// carry flag 

		carry = true; 
		overflow = true;

	}

	if (data2 & 1<< 63) {

		carry = true;
		overflow = true;
	}


	if (data == 0 || data2 == 0) {

		zero = true;

	}


	if (data == data2) {

		equal = true;

	}

	if (data > data2) {
		greater_than = true;

	}
	if (data >= data2) {

		greater_than_equal = true;
	}
	if (data <= data2) {

		less_than_equal = true;
	}
	if (data < data2) {

		less_than = true;
	}

}
/*
TODO 
R?soudre les structs de pagination
D?plac? dans Memory class
*/
void Assembleur::resolve_pagination() {


}
/*
But de cette m?thode incrementer i et remplir i avec le numero d'interruption dans le tableau des interruptionsinit
*/
void Assembleur::set_interrupt_table(unsigned long long adress) {


	struct interrupt* i = mem.get_int(adress);


	for (int x = 0; x < 254;x++) {

		i = i + sizeof(struct interrupt);
		int_->set_interrupt_config(i,x);


	}
}


/*
faire les interruptions demand?es 

*/
void Assembleur::do_interrupt(unsigned char i) {



}


/*
si USER_MODE 
passer is_kernel_mode sur false

*/
void Assembleur::set_exec_mode(char mode) {

	if (mode == USER_MODE) {

		is_kernel_mode = false;
		mem.update_exec(is_kernel_mode);

	}

}
 void Assembleur::execute(struct tree *tmp) {


	if (tmp->is_add == true) {

		clear_flags();
		if (tmp->data > 0) {

			check_data(regs[tmp->reg1], tmp->data);

			regs[tmp->reg1] = regs[tmp->reg1] + tmp->data;

		}
		else {

			check_data(regs[tmp->reg1], regs[tmp->reg2]);
			regs[tmp->reg1] = regs[tmp->reg1] + regs[tmp->reg2];

		}

	}
	else if (tmp->is_addc == true) {


		clear_flags();
		if (tmp->data > 0) {

			check_data(regs[tmp->reg1], tmp->data);

			regs[tmp->reg1] = regs[tmp->reg1] + tmp->data;

		}
		else {

			check_data(regs[tmp->reg1], regs[tmp->reg2]);
			regs[tmp->reg1] = regs[tmp->reg1] + regs[tmp->reg2];

		}


	}
	else if (tmp->is_and == true) {
		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] & regs[tmp->reg2];

	}
	else  if (tmp->is_beq == true) {


		if (equal == true) {

			run_function(tmp->str);

		}

	}
	else if (tmp->is_bge == true) {


	}
	else if (tmp->is_bgt == true) {


	}
	else if (tmp->is_bgtu == true) {


	}
	else if (tmp->is_ble == true) {


	}
	else if (tmp->is_bltu == true) {


	}
	else if (tmp->is_bne == true) {
		
		if (equal != true) {

			run_function(tmp->str);

		}

	}
	else if (tmp->is_branch_equal == true) {

		if (equal == true) {

			run_function(tmp->str);

		}

	}
	else if (tmp->is_branch_greater_than == true) {



		if (greater_than == true) {

			run_function(tmp->str);
		}

	}
	else if (tmp->is_branch_greater_than_or_equal == true) {

	if (greater_than_equal == true) {

		run_function(tmp->str);
	}

	}
	else if (tmp->is_branch_greater_than_unsigned == true) {

	if (greater_than_equal == true && negative== true) {

		run_function(tmp->str);
	}

	}
	else if (tmp->is_branch_less_or_equal_than == true) {

	if (less_than_equal == true && negative == true) {

		run_function(tmp->str);
	}
	}
	else if (tmp->is_branch_less_than == true) {


	if (less_than == true) {

		run_function(tmp->str);
	}

	}
	else if (tmp->is_branch_less_than_unsigned == true) {

	if (less_than == true && negative == true) {

		run_function(tmp->str);
	}

	}
	else if (tmp->is_branch_not_equal == true) {

	if (equal != true) {

		run_function(tmp->str);

	}

	}
	else if (tmp->is_cmp == true) {
		clear_flags();
		check_data(regs[tmp->reg1], regs[tmp->reg2]);

	}
	else if (tmp->is_dec == true) {

		regs[tmp->reg1]--;

	}
	else if (tmp->is_disp == true) {

		if (tmp->data > 0) {

			regs[tmp->reg1] = tmp->data;

		}
		else {

			regs[tmp->reg1] = regs[tmp->reg2];

		}

	}
	else if (tmp->is_dispab_read == true) {

		regs[tmp->reg1] = mem.read_char(regs[tmp->reg2]);

	}
	else if (tmp->is_dispab_write == true) {
		// dabord adresse et ensuite donn?es
		mem.write_char(regs[tmp->reg1],regs[tmp->reg2]);
	}
	else if (tmp->is_dispal_read == true) {


		regs[tmp->reg1] = mem.read_long(regs[tmp->reg2]);

	

	}
	else if (tmp->is_dispal_write == true) {



		mem.write_long(regs[tmp->reg1],regs[tmp->reg2]);
	}
	else if (tmp->is_dispas_read == true) {


		regs[tmp->reg1] = mem.read_short(regs[tmp->reg2]);

	}
	else if (tmp->is_dispas_write == true) {

		
		mem.write_short(regs[tmp->reg1],regs[tmp->reg2]);
	}
	else if (tmp->is_displacement == true) {


	}
	else if (tmp->is_div == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] / regs[tmp->reg2];

	}
	else if (tmp->is_divs == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] / regs[tmp->reg2];

	}
	else if (tmp->is_inc == true) {

		regs[tmp->reg1]++;


	}
	else if (tmp->is_jmp == true) {


	return 	run_function(tmp->str);

	}
	else if (tmp->is_jsr == true) {

	return 	run_function(tmp->str);


	}
	else if (tmp->is_jsra == true) {

	return 	run_function(tmp->str);

	}
	else if (tmp->is_modul == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] % regs[tmp->reg2];

	}
	else if (tmp->is_mult == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] * regs[tmp->reg2];
	}
	else if (tmp->is_not == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = ~regs[tmp->reg1];

	}
	else if (tmp->is_or == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] | regs[tmp->reg2];

	}
	else if (tmp->is_pop == true) {

	mem.write_long_long(regs[0], regs[tmp->reg1]);

	regs[0]--;

	}
	else if (tmp->is_prcfg == true) {


	if (tmp->prcfg_interrupt == true) {


		adress_interrupt = tmp->adress;
		set_interrupt_table(adress_interrupt);
	}
	else if (tmp->prcfg_user_mode == true) {


		if (tmp->adress == 2) {

			set_exec_mode(USER_MODE);

		}


	}
	else if (tmp->prcfg_pagination == true) {

		adress_pagination = tmp->adress;
		resolve_pagination();
	}


	}
	else if (tmp->is_push == true) {

	regs[0]++; 
	mem.write_long_long(regs[0],regs[tmp->reg1]);
	}
	else if (tmp->is_ret == true) {


	}
	else if (tmp->is_shift_left == true) {
		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] << regs[tmp->reg2];

	}
	else if (tmp->is_shift_right == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] >> regs[tmp->reg2];

	}
	else if (tmp->is_sub == true) {

		std::cout << "sub x " << std::endl;
		clear_flags();
		if (tmp->data > 0) {

			check_data(regs[tmp->reg1], tmp->data);

			regs[tmp->reg1] = regs[tmp->reg1] - tmp->data;

		}
		else {

			check_data(regs[tmp->reg1], regs[tmp->reg2]);
			regs[tmp->reg1] = regs[tmp->reg1] - regs[tmp->reg2];

		}

	}
	else if (tmp->is_subc == true) {

		clear_flags();
		if (tmp->data > 0) {

			check_data(regs[tmp->reg1], tmp->data);

			regs[tmp->reg1] = regs[tmp->reg1] - tmp->data;

		}
		else {

			check_data(regs[tmp->reg1], regs[tmp->reg2]);
			regs[tmp->reg1] = regs[tmp->reg1] - regs[tmp->reg2];

		}

	}
	else if (tmp->is_syscall == true) {

	do_interrupt(tmp->reg1);


	}
	else if (tmp->is_xor == true) {

		clear_flags();


		check_data(regs[tmp->reg1], regs[tmp->reg2]);
		regs[tmp->reg1] = regs[tmp->reg1] ^ regs[tmp->reg2];

	}
	else if (tmp->jump_adress == true) {

	return run_function(tmp->str);
	}

}
/*
executer le code de la fonction 
*/
void Assembleur::run_function(std::string function_name) {

	std::list<struct tree*>::iterator itt;


	for (itt = ops.begin(); itt != ops.end(); ++itt) {
		struct tree* tmp = *itt;


		if (tmp->function_name != function_name) {


			
		}
		else {
			std::cout << "function name ok execution " << std::endl;
			execute(tmp);
		}

	}


}
void Assembleur::scan_ast() {


	std::list<struct tree*>::iterator itt;
	for (itt = ops.begin(); itt != ops.end(); ++itt) {
		struct tree* tmp = *itt; 


		std::cout << "function name " << tmp->function_name  <<std::endl;
		execute(tmp);



	}



}

/*
build ast 

*/
void Assembleur::scan_tok() {



	std::list<std::string>::iterator itt;
	for (itt = toks.begin(); itt != toks.end(); ++itt) {
		std::string tmp = *itt;
		bool ok = false;
		for (int x = 0;x< sizeof(opcodes) / sizeof(struct opcode_gaspard);x++) {

			if (strcmp(opcodes[x].name,tmp.c_str()) == 0) {

				struct tree* tr = new struct tree; 
				ok = true;

				tr->function_name = actual_function;

				// faire un switch : 



				switch (opcodes[x].opcode) {

				case 10: {
					// or
					++itt; 
					tmp= *itt;
					tr->is_or = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt; 
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}
				case 8: {
					//xor
					++itt;
					tmp = *itt;
					tr->is_xor = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;

					break;
				}
					  
				case 9: {
					//and
					++itt;
					tmp = *itt;
					tr->is_and = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}

				case 11: {
					//not

					++itt;
					tmp = *itt;
					tr->is_not = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					

					break;
				}
				case 18: {
					//shfl

					++itt;
					tmp = *itt;
					tr->is_shift_left = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}

				case 13: {
					//shfr
					++itt;
					tmp = *itt;
					tr->is_shift_right = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}

				case 7: {

					//mult;

					++itt;
					tmp = *itt;
					tr->is_mult = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;

					break;
				}
				

				case 46: {


					// add
					++itt;
					tmp = *itt;
					tr->is_add = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());

					if (op2 == 254) {
						tr->data = atol(tmp.c_str());
						tr->reg2 = 254;

					}
					else {

						tr->reg2 = op2;

					}

					break;
				}
				case 26: {

					// addc
					++itt;
					tmp = *itt;
					tr->is_addc = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					if (op2 == 254) {
						tr->data = atol(tmp.c_str());
						tr->reg2 = 254;

					}
					else {

						tr->reg2 = op2;

					}
					break;
				}
				case 5: {
					std::cout << "sub" << std::endl;
					// sub
					++itt;
					tmp = *itt;
					tr->is_sub = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					if (op2 == 254) {
						tr->data = atol(tmp.c_str());
						tr->reg2 = 254;

					}
					else {

						tr->reg2 = op2;

					}
					break;
				}
				case 27: {


					// subc
					++itt;
					tmp = *itt;
					tr->is_subc = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					if (op2 == 254) {
						tr->data = atol(tmp.c_str());
						tr->reg2 = 254;
					}
					else {

						tr->reg2 = op2;

					}
					break;
				}
				case 4: {

					// inc
					++itt;
					tmp = *itt;
					tr->is_inc = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					
				}

				case 153: {


					// dec
					++itt;
					tmp = *itt;
					tr->is_dec = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					

					break;
				}
				case 25: {

					//modul 
					++itt;
					tmp = *itt;
					tr->is_modul = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}
				case 28: {

					// div 

					++itt;
					tmp = *itt;
					tr->is_div = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}
				case 29: {

					// divs
					++itt;
					tmp = *itt;
					tr->is_divs = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;

				}
				case 16: {

					// cmp 

					++itt;
					tmp = *itt;
					tr->is_cmp = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;

				}

				case 44: {


					// disp 
					++itt;
					tmp = *itt;
					tr->is_disp = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					

					if (op2 == 254) {

						tr->data = atol(tmp.c_str());


					}
					else {
						tr->reg2 = op2;
					}

					break;
				}
				case 3: {

					// dispa

					// instruction pas utilis?e 

					break;
				}
				case 30: {
					// dispa imm to ptr


					break;
				}
				case 31: {

					// dispa ptr to imm 3



					break;
				}
				case 35: {

					// push 


					++itt;
					tmp = *itt;
					tr->is_push = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					
					break; 

				}
				case 33: {

					// pop

					++itt;
					tmp = *itt;
					tr->is_pop = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					break; 

				}
				case 150: {

					// prcffg 
					++itt;
					tmp = *itt;

					if (strcmp("1",tmp.c_str()) == 0) {


						tr->prcfg_pagination = true;

					}
					else if (strcmp("2", tmp.c_str()) == 0) {

						tr->prcfg_interrupt = true;
					}
					else if (strcmp("3", tmp.c_str()) == 0) {

						tr->prcfg_user_mode = true;
					}

					++itt;
					tmp = *itt;

					tr->adress = atol(tmp.c_str());
					break; 

				}
				case 36: {

					// syscall
					++itt;
					tmp = *itt;

					// r?cuprerr le numero 


					tr->reg1 = atol(tmp.c_str());
					break; 
				}
				case 0: {

					// void 

					break; 

				}
				case 154: {

					// bne 

					++itt;
					tmp = *itt;
					tr->is_branch_not_equal = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());

					if (op1 == 254) {

						tr->str = tmp;

					}
					else {

						tr->reg1 = op1;
 
					}
					break; 
				}

				case 19: {


					// beq 

					++itt;
					tmp = *itt;
					tr->is_branch_equal = true;
					tr->str = tmp;

					break;
				}
				case 20: {

					// blt
					++itt;
					tmp = *itt;
					tr->is_branch_less_than = true;
					tr->str = tmp;

					break;
				}
				case 21: {


					// bltu 
					++itt;
					tmp = *itt;
					tr->is_branch_less_than_unsigned = true;
					tr->str = tmp;


					break;

				}
				case 22: {

					// bgt 
					++itt;
					tmp = *itt;
					tr->is_branch_greater_than = true;
					tr->str = tmp;


					break; 
				}
				case 23: {

					// bgtu 
					++itt;
					tmp = *itt;
					tr->is_branch_greater_than_unsigned = true;
					tr->str = tmp;



					break;
				}
				case 24: {

					// bge 
					++itt;
					tmp = *itt;
					tr->is_branch_greater_than_or_equal = true;
					tr->str = tmp;

					break; 
				}

				case 112: {

					// dispab_write

					++itt;
					tmp = *itt;
					tr->is_dispab_write = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;

					break;
				}
				case 111: {

					// dispab_read


					++itt;
					tmp = *itt;
					tr->is_dispab_read = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}
				case 40: {

					// dispas _ write 
					++itt;
					tmp = *itt;
					tr->is_dispas_write = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break;
				}
				case 41: {

					// dispas_read; 

					++itt;
					tmp = *itt;
					tr->is_dispas_read = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break; 

				}
				case 45: {


					// dispal _write 
					++itt;
					tmp = *itt;
					tr->is_dispal_write = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;
					break; 
				}
				case 47: {
					// dispal_read
					++itt;
					tmp = *itt;
					tr->is_dispal_read = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					++itt;
					tmp = *itt;

					unsigned char op2 = gpr_fpr((char*)tmp.c_str());
					tr->reg2 = op2;

					break;
				}

				case 156: {

					// ble 
					++itt;
					tmp = *itt;
					tr->is_branch_less_or_equal_than = true;
					unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->reg1 = op1;
					break;
				}
				case 157: {

					// jmp
					++itt;
					tmp = *itt;
					tr->jump_adress = true;


					//unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->str = tmp;
					break; 

				}
				case 158: {

					// jsr 
					++itt;
					tmp = *itt;
					tr->jump_adress = true;
					

					//unsigned char op1 = gpr_fpr((char*)tmp.c_str());
					tr->str = tmp;
					break;

				}

				case 159: {


					// jsra 
					++itt;
					tmp = *itt;
					tr->jump_adress = true;
					tr->str = tmp;
					break; 

				}
				}
				ops.push_back(tr);

			}

		}	

		if (ok == false) {

			if (contain_deux_points(tmp) == true) {

				std::string func_name = function_name(tmp);
				actual_function = func_name;
			}
			// continuer si 


		}
		// pas opcode peut ?tre drapeau du compilateur ou delcaration de fonction

	}



}

void Assembleur::print_toks() {

	for (std::string tmp : toks) {


		std::cout << "token : " << tmp << std::endl;
	}


}

// todo le refaire avec le code de compilerc
void Assembleur::create_tok() {


	//char* tmp_str = strtok_s(file," ,@:\n",&file);

	int status = 0;
	std::string tmp;

	bool okay = false;
	while (status != size) {


		if (file[status] == '\n' || file[status] == ' ' || file[status] == '\t' || file[status] == ',') {

			if (okay != false) {

				toks.push_back(tmp);
				okay = false;
				tmp = "";

			}


		}
		else {
			okay = true;
			tmp += file[status];


		}

		status++;

	}

}
