

struct page_child {

	unsigned char is_writed : 1;

	unsigned char mode : 4;
	/*
	1= kernel mode
	2= uniquement accès user mode
	3 = accès dans les deux
	*/

	unsigned char disabled : 4;
	/*
	1 = peut être écrit et lu
	2= peut uniquement être lu
	3= peut uniquement être écrit
	*/

	unsigned long long adress;
	/*
	adresse physique qui est paginée
	*/

};
struct pag_general_config {

	unsigned short pag_table_num;
	unsigned char num_pag_child;
	unsigned char child_size;

	/*
	1= 512 bytes

	2 = 1 kilobytes

	3 = 1 mégabytes

	*/

	unsigned long long adress_of_page; // adresse physique
};

struct page_table {


	unsigned char mode : 4;
	/*
	1 = kernel mode
	2 only acees in user mode
	3 = access in both mode
	*/
	unsigned char disabled : 4;
	/*
	1 page cannot be writed or read

	2 this page can only be read
	3 rthis page can only be writed
	*/
	unsigned char present : 1;
	/*
	doit être présent pour être effectif
	*/

	struct page_child child[10];
};


struct adress {
	unsigned short page_table;
	unsigned char child_table : 4;  // position child
	unsigned long long offset : 44;


};
#define WHERE_IS_PAG_CONFIG 0x0
#define WHERE_IS_THE_FIRST_PAGE sizeof(struct pag_general_config) +1


int main() {

	struct pag_general_config* pag = (struct pag_general_config*) 0x0;

	pag->adress_of_page = WHERE_IS_THE_FIRST_PAGE; 
	pag->num_pag_child = 3; 
	pag->pag_table_num = 10; 
	// 10 pages avec 3enfants chacunes. 


}
