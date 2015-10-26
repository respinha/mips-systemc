#ifndef DMEMMOD_H
#define DMEMMOD_H

/**
 *
 * Dmem module interface.
 */

#include <systemc.h>

#include "mem32.h"

/**
 * Dmem module.
 * Dmem module models the data memory of MIPS. 
 * Synchronous on writes, assynchronous on reads.
 *   - input ports
 *   	- \c sc_uint<32> \c addr		- address 
 *   	- \c sc_uint<32> \c din		- input data 
 *   	- \c bool \c wr		- write enable 
 *   	- \c bool \c rd		- read enable 
 *   	- \c bool \c clk		- clock 
 *   - output ports
 *   	- \c sc_uint<32> \c dout		- output data 
 */

class dmem :public sc_module, public mem32 
{
  public:
  
  sc_in< sc_uint<32> >  addr;
  sc_in< sc_uint<32> >  din;        
  sc_in<bool> wr;        
  sc_in<bool> rd;        
  sc_in<bool> clk;        

  sc_out< sc_uint<32> >  dout;        

  SC_CTOR(dmem)
    {      
      SC_METHOD(read_mem);
      sensitive << addr << rd;
      SC_METHOD(write_mem);
      sensitive_pos(clk);

      init_memory("datamem.dat");
    }
  
  void read_mem();
  void write_mem();
  void dump();
};

#endif
