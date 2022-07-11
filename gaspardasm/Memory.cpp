#include "Memory.h"

/*

TODO 

faire les unsigned 

- faire le systsème de sécurisation dela pagination
*/
Memory::Memory() {


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

    page->child[adr->child_table].adress;
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


        return mem[adress];
    }

    // pagination activée : 


    struct adress* adr = (struct adress*)&adress;

    struct page_table* page = get_page(adr->page_table);




    return tmp_mem[page->child[adr->child_table].adress + adr->offset];

}
bool Memory::write_char(unsigned long long adress, char data)
{
    return false;
}

bool Memory::write_short(unsigned long long adress, short data)
{
    return false;
}

bool Memory::write_long(unsigned long long adress, long data)
{
    return false;
}

bool Memory::write_long_long(unsigned long long adress, long long data)
{
    return false;
}

void Memory::set_memory(int byte)
{

    mem = new long long[byte];
}

void* Memory::get_adress(unsigned long long adress) {

    
   void *final_ =  mem + adress;

   return final_;
}