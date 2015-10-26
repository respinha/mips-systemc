//imem.cpp

#include <vector>
#include <string>

#include "imem.h"
#include "mipsaux.h"

/**
 * \c imem module callback function.
 */
void imem::entry()
{
    if(addr.read()>=size() || addr.read() % 4 != 0) {
        //assert(addr.read()<size() && addr.read() % 4 ==0); // abort
	inst.write(0x25); // if invalid address output nop
	return;
    }
    inst.write(memory[addr.read()/4]);
}

