#include "Memory.h"

Memory::Memory() {


}


// todo a faire
long long Memory::operator[](unsigned long long adress)
{
    return 0;
}

long long Memory::read_char(unsigned long long adress)
{
    return 0;
}

long long Memory::read_short(unsigned long long adress)
{
    return 0;
}

long long Memory::read_long(unsigned long long adress)
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
