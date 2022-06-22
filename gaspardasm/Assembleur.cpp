#include "Assembleur.h"
#include<string.h>
Assembleur::Assembleur() {





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
