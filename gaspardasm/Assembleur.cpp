#include "Assembleur.h"


Assembleur::Assembleur() {





}
void Assembleur::print_toks() {

	for (std::string tmp : toks) {


		std::cout << "token : " << tmp << std::endl;
	}


}
// todo le refaire avec le code de compilerc
void Assembleur::create_tok() {


	int status = 0; 
	std::string tmp = "";
	while (status != size) {
		if (file[status] == '\n' || file[status] == ' ') {
			if (tmp.size() > 1) {
				toks.push_back(tmp);
				tmp = "";

			}
			 if (file[status] == ' ') {

				toks.push_back(" ");


			}
		}
		else {

			
			 if (file[status] == '\0') {


			}
			else if (file[status] == '\t') {


			}
			
			else {

				tmp += file[status];

			}

			

		}

		status++; 

	}
	
}