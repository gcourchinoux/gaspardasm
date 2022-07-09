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
// todo a faire
long long Memory::operator[](unsigned long long adress)
{
    if (general_config == nullptr) {


        return mem[adress];
    }

    // pagination activée : 




    return 0;
}

char Memory::read_char(unsigned long long adress)
{
    return 0;
}

short Memory::read_short(unsigned long long adress)
{
    return 0;
}

long  Memory::read_long(unsigned long long adress)
{
    return 0;
}

long long Memory::read_long_long(unsigned long long adress)
{
    return 0;
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