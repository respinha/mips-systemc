//imem.cpp

#include <vector>
#include <string>

using std::string;

#include "mem32.h"

/**
 * reads \c mem32 memory contents from file \c filename.
 * The first number in each line of file is added to memory as an 32 bit 
 * integer.
 * The number is in base 16. Lines that do not start with a number are ignored.
 * The size of memory is given by the valid lines.
 */
void mem32::init_memory(const char *filename)
{
    unsigned int val;
    string str;
    
    ifstream data(filename);

    if(!data) {
         fprintf(stderr,"ERROR: Could not find file %s\n",filename);
	 exit(1);
    }

    memory.clear();

    std::getline(data, str);
    while(!data.eof()) {
         if (sscanf(str.c_str(),"%x",&val)==1) {
	     memory.push_back(val);
	 }
	 std::getline(data, str);
    }
}

/** return the number of bytes in memory */
unsigned int mem32::size()
{
    return memory.size()*4;
}

/** return memory contents at addr address. Considers addr as a byte address.
 * Only works if addr is a multiple of 4. */
sc_uint<32> mem32::at(sc_uint<32> addr)
{
    assert(addr<size() && addr % 4 == 0);
    return memory[addr / 4];
}

