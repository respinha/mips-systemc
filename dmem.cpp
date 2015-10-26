//dmem.cpp

#include <string>

#include "dmem.h"

/**
 * callback of the assynchronous behaviour of module \c dmem
 */
void dmem::read_mem()
{
    if(rd.read()) {
        //assert(addr.read()<size() && addr.read() % 4 == 0);
        if((addr.read()<size() && addr.read() % 4 == 0))
           dout.write(memory[addr.read()/4]);
	else dout.write(0);
    }
}

/**
 * callback of the synchronous behaviour of module \c dmem
 */
void dmem::write_mem()
{
    if(wr.read()) {
        //assert(addr.read()<size() && addr.read() % 4 == 0);
        if((addr.read()<size() && addr.read() % 4 == 0)) {
           memory[addr.read()/4]=din.read();
           //dout.write(memory[addr.read()/4]);
	}
    }
}

/**
 * Writes the contents of memory to \c stdout.
 */
void dmem::dump()
{
    unsigned int i;

    for(i=0;i<size();i+=4)
       printf("%3d: ",i);
    printf("\n");
    for(i=0;i<size();i+=4)
       printf("%5d",(int) memory[i/4]);
    printf("\n");
}
