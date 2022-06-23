#include "Assembleur.h"
#include<string.h>

/*

TODO : 

fauire des pass ou une fonction généraliste ? 


*/

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

		// pas opcode peut être drapeau du compilateur ou delcaration de fonction

	}





}
/*
build ast 

*/
void Assembleur::scan_tok() {



	std::list<std::string>::iterator itt;
	for (itt = toks.begin(); itt != toks.end(); ++itt) {
		std::string tmp = *itt;
		for (int x = 0;x< sizeof(opcodes) / sizeof(struct opcode_gaspard);x++) {

			if (strcmp(opcodes[x].name,tmp.c_str()) == 0) {

				struct tree* tr = new struct tree; 


			}


}

		// pas opcode peut être drapeau du compilateur ou delcaration de fonction

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
