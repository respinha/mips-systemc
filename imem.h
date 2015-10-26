//imem.h

#ifndef IMEMMOD_H
#define IMEMMOD_H

/**
 *
 * Imem module interface.
 */

#include <vector>

#include <systemc.h>

#include "mem32.h"

/**
 * Imem module.
 * Imem module models the instruction memory of MIPS. 
 * Assynchronous on reads, no writes allowed.
 *   - input ports
 *   	- \c sc_uint<32> \c addr		- address 
 *   - output ports
 *   	- \c sc_uint<32> \c inst		- instruction
 */


class imem : public sc_module, public mem32
{
  public:
    sc_in< sc_uint<32> >  addr;
    sc_out< sc_uint<32> >  inst;        

    SC_CTOR(imem)
     {      
      SC_METHOD(entry);
      sensitive << addr;

      init_memory("instmem.hex");	// JLA
     }
  
    void entry();
};

#endif
