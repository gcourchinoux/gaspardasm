/*
Manage the gaspardasm memory
Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
#include "Memory.h"

/*

TODO 


- faire le systsème de sécurisation dela pagination
*/
Memory::Memory() {


}
/*
Prend deux paramètres 
la table et l'enfant puis les compare et renvoit true pour dire que la copie peut se dérouler 

false pour dire que cela n'est pas possible.


rappel kernel mode à tous les droits 
user mode pratiquement aucun. 


read = si action lecture alors true sinon false
*/
bool Memory::check(struct page_table *table,struct page_child *ch,bool read) {

    // d'abord voir si le mode d'execution est égale 

    if (ch->mode == 1 && exec_mode != true) {
       // refus d'execution car il y a une tentative de user mode de copier dans le kernel mode 
        // faire une interuption. 
        return false;

    }
    // tentatie de kernel de copier dans le user mode 
    if(ch->mode == 2 && exec_mode == true) {

        return false;

    }
    // l'action est écriture mais l'enfant peut uniquement être lu.
    if (ch->disabled == 2 && read == false) {

        return false;
    }

    if (ch->disabled == 3 && read != true) {

        return false;
    }
    return true;

}

/*
Penser à bien l'apeller dès qu'il y a une mise  à jour notamment quand les interruptions seront implémentées

*/
void Memory::update_exec(bool exec) {

    exec_mode = exec;


}

void Memory::set_pagination_table(unsigned long long adress) {


    general_config = (struct pag_general_config*) get_adress(adress);
    // résoudre la première table 

    pages = (struct page_table*) get_adress(general_config->adress_of_page);
}
/*
Note sur get_page() : 

le problème ici c'est que page_child contient 10 childs de manière statique. 
J'ai décidé cela afin de d'éviter une optimisation de msvc et peut être de clang. 


d'un page_table


A tester
*/
struct page_table* Memory::get_page(int page_num) {

    int num_child = general_config->num_pag_child; 
    
    int child_size = sizeof(struct page_child);

    struct page_table* tmp = pages;


    switch (num_child) {

    case 1: {

        tmp = pages + sizeof(struct page_table) - child_size * 9 * page_num;

        break;
    }

    case 2: {
        tmp = pages + sizeof(struct page_table) - child_size *8 * page_num;



        break;
    }
    case 3: {

        tmp = pages + sizeof(struct page_table) - child_size * 7 * page_num;

        break;
    }
    case 4: {

        tmp = pages + sizeof(struct page_table) - child_size * 6 * page_num;

        break;
    }
    case 5: {

        tmp = pages + sizeof(struct page_table) - child_size * 5 * page_num;


        break;
    }
    case 6: {

        tmp = pages + sizeof(struct page_table) - child_size * 4 * page_num;

        break;
    }
    case 7: {
        tmp = pages + sizeof(struct page_table) - child_size * 3 * page_num;


        break;
    }
    case 8: {

        tmp = pages + sizeof(struct page_table) - child_size * 2 * page_num;

        break;
    }
    case 9: {

        tmp = pages + sizeof(struct page_table) - child_size * 1 * page_num;


        break;
    }
    case 10: {


        tmp = pages + sizeof(struct page_table)  * page_num;
        break;
    }
    }



    // tester tmp ? 


    return tmp;

}
/*
permet de trouver la page table associé 
*/
struct page_table * Memory::resolve_adress(unsigned long long adress) {


    struct adress* adr = (struct adress*) &adress;

    struct page_table* page = get_page(adr->page_table);

    
    return page;

}

// todo a faire
long long Memory::operator[](unsigned long long adress)
{
    if (general_config == nullptr) {


        return mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page,&page->child[adr->child_table],true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }


    return mem[page->child[adr->child_table].adress + adr->offset];
}

char Memory::read_char(unsigned long long adress)
{
    char* tmp_mem =(char*) mem;
    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }



    return tmp_mem[page->child[adr->child_table].adress + adr->offset];

}

short Memory::read_short(unsigned long long adress)
{
    short* tmp_mem = (short*)mem;
    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);


    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }


    return tmp_mem[page->child[adr->child_table].adress + adr->offset];
}

long  Memory::read_long(unsigned long long adress)
{
    long* tmp_mem = (long*)mem;
    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);


    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }


    return tmp_mem[page->child[adr->child_table].adress + adr->offset];
}

long long Memory::read_long_long(unsigned long long adress)
{

    if (general_config == nullptr) {


        return mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);


    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }


    return mem[page->child[adr->child_table].adress + adr->offset];

}
unsigned char Memory::read_unsigned_char(unsigned long long adress) {

  unsigned char* tmp_mem = (unsigned char*)mem;
    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }



    return tmp_mem[page->child[adr->child_table].adress + adr->offset];

}
unsigned short Memory::read_unsigned_short(unsigned long long adress)
{
    unsigned short* tmp_mem = (unsigned short*)mem;
    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);


    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }


    return tmp_mem[page->child[adr->child_table].adress + adr->offset];
}

unsigned long  Memory::read_unsigned_long(unsigned long long adress)
{
    unsigned long* tmp_mem = (unsigned long*)mem;
    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }



    return tmp_mem[page->child[adr->child_table].adress + adr->offset];
}

unsigned long long Memory::read_unsigned_long_long(unsigned long long adress)
{
    unsigned long long * tmp_mem = (unsigned long long *)mem;

    if (general_config == nullptr) {


        return tmp_mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], true) == false) {
        // do interrupt 
        int_->do_int(1);

        return 0;
    }



    return tmp_mem[page->child[adr->child_table].adress + adr->offset];

}
bool Memory::write_char(unsigned long long adress, char data)
{
    char* tmp_mem = (char*)mem;
    if (general_config == nullptr) {


        tmp_mem[adress] = data;
         return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);


    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


     tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}

bool Memory::write_short(unsigned long long adress, short data)
{

    short* tmp_mem = (short*)mem;
    if (general_config == nullptr) {


        tmp_mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}

bool Memory::write_long(unsigned long long adress, long data)
{
    long* tmp_mem = (long*)mem;
    if (general_config == nullptr) {


        tmp_mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}

bool Memory::write_long_long(unsigned long long adress, long long data)
{

    if (general_config == nullptr) {


        mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


    mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;

}

bool Memory::write_unsigned_char(unsigned long long adress, unsigned char data)
{
   unsigned char* tmp_mem = (unsigned char*)mem;
    if (general_config == nullptr) {


        tmp_mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}

bool Memory::write_unsigned_short(unsigned long long adress, unsigned short data)
{

    unsigned short* tmp_mem = (unsigned short*)mem;
    if (general_config == nullptr) {


        tmp_mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}

bool Memory::write_unsigned_long(unsigned long long adress,unsigned long data)
{
    unsigned long* tmp_mem = (unsigned long*)mem;
    if (general_config == nullptr) {


        tmp_mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);


    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }

    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}

bool Memory::write_unsigned_long_long(unsigned long long adress,unsigned  long long data)
{
    unsigned long long* tmp_mem = (unsigned long long*)mem;

    if (general_config == nullptr) {


        tmp_mem[adress] = data;
        return true;
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);

    if (check(page, &page->child[adr->child_table], false) == false) {
        // do interrupt 
        int_->do_int(1);

        return false;
    }


    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;

    return true;
}


void Memory::set_memory(int byte)
{

    mem = new long long[byte];
}

void* Memory::get_adress(unsigned long long adress) {

    
   void *final_ =  mem + adress;

   return &mem[adress];
}


struct interrupt* Memory::get_int(unsigned long long adress) {

    return (struct interrupt*)&mem[adress];

}