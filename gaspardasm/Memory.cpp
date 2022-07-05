#include "Memory.h"

Memory::Memory(int o) {

    mem = new long long[o];

}

long long Memory::operator=(long long data)
{




    return data;
}
// todo a faire
long long Memory::operator[](unsigned long long adress)
{
    return 0;
}
