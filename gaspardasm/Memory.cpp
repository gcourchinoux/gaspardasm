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
struct page_table* Memory::get_page(int page_num) {

    

    return pages + sizeof(struct page_table) + general_config->num_pag_child * page_num;

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




    mem[page->child[adr->child_table].adress + adr->offset] = data;


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




    tmp_mem[page->child[adr->child_table].adress + adr->offset] = data;


}


void Memory::set_memory(int byte)
{

    mem = new long long[byte];
}

void* Memory::get_adress(unsigned long long adress) {

    
   void *final_ =  mem + adress;

   return final_;
}