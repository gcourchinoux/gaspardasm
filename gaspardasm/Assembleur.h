/*
parse tokens and execute.

Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
#pragma once
#include <string>
#include <iostream>

#include <list>
#include "Memory.h"
#include "Vga.h"
#define USER_MODE 2
class Assembleur
{

public:
	void thread_check_int();
	Assembleur();
	bool contain_deux_points(std::string str);
	std::string function_name(std::string str);
	void scan_functions();
	 void clear_flags();
	 	void check_data(long data, long data2);
		void resolve_pagination();
		void set_interrupt_table(unsigned long long adress);
		void do_interrupt(unsigned char i);
		void set_exec_mode(char mode);
		void execute(struct tree* tmp);
	 void run_function(std::string function_name);
	void scan_ast();
	void scan_tok();
	int size; 
	char* file; 
	void create_tok(); 
	std::list<std::string> toks;
	void print_toks();
	std::string actual_function;
	 std::list<struct tree*> ops;
	 Memory  mem;

	  unsigned long long regs[31];


	  bool carry; 
	 bool negative;
	 bool zero;
	 bool equal;
	 bool overflow;
	 bool greater_than;
	 bool greater_than_equal;
	 bool less_than_equal;
	 bool less_than;

	 unsigned long long adress_pagination; 

	 unsigned long long adress_interrupt;

	 bool is_kernel_mode; // true yes ; false not  by default true 

	 void init();

	 Interrupt* int_;
	 
	 Vga* vga; 

};

struct opcode_gaspard {
 const 	char* name;
	unsigned char opcode;
	unsigned char num_of_op;// le nombre d'opérandes max 3

	void (*handler)(struct opcode_gaspard* s);

};
// structure tree 

struct tree {

	std::string function_name;

	long long data;
	unsigned long long adress;
	std::string str; // généralement les nom des fonctions en cas de saut 
	bool is_displacement; // dispa , disp dispb_write etc etc 

	
	unsigned char reg1; 
	unsigned char reg2;

	bool is_or; 
	bool is_xor; 
	bool is_and;
	bool is_not; 
	bool is_shift_right; 
	bool is_shift_left;
	bool is_mult; 
	bool is_add; 
	bool is_addc; 
	bool is_sub; 
	bool is_subc; 
	bool is_inc; 
	bool is_dec;
	bool is_modul; 
	bool is_div; 
	bool is_divs; 
	bool is_cmp; 
	bool is_pop; 
	bool is_push; 
	bool is_prcfg; 
	bool is_ret; 
	bool is_syscall; 
	bool is_bne; 
	bool is_beq; 
	bool is_bltu; 
	bool is_bgt; 
	bool is_bgtu; 
	bool is_bge; 
	bool is_ble; 
	bool is_jmp; 
	bool is_jsr; 
	bool is_jsra; 
	bool is_disp;
	bool is_branch_not_equal;
	bool is_branch_equal;
	bool is_branch_less_than;
	bool is_branch_less_than_unsigned;
	bool is_branch_greater_than;
	bool is_branch_greater_than_unsigned;
	bool is_branch_greater_than_or_equal;
	bool is_branch_less_or_equal_than;
	bool is_dispab_write; 
	bool is_dispab_read; 
	bool is_dispas_write;
	bool is_dispas_read;
	bool is_dispal_write;
	bool is_dispal_read;
	bool jump_adress;
	// pour prcfg : 

	bool prcfg_pagination; // configureation égale a 1  
	bool prcfg_interrupt;  // configuration égale a 2
	bool prcfg_user_mode;
};