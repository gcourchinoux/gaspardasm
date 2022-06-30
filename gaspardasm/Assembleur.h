#pragma once
#include <string>
#include <iostream>

#include <list>

class Assembleur
{

public:
	Assembleur();
	bool contain_deux_points(std::string str);
	std::string function_name(std::string str);
	void scan_functions();
	void clear_flags();
	void check_data(long data, long data2);
	void execute(tree* tmp);
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

	unsigned long long regs[31];


	bool carry; 
	bool negative; 
	bool zero;
	bool equal;
	bool overflow;

	long long *mem;
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
};