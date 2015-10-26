#ifndef REGFILEMOD_H
#define REGFILEMOD_H

/**
 *
 * Regfile module interface.
 */

#include <systemc.h>

#include "mem32.h"

/**
 * Regfile module.
 * Regfile module models the integer register bank of MIPS.
 * Synchronous on writes, assinchronous on read.
 *
 *   - input ports
 *   	- \c sc_uint<5> \c reg1		- id1 of register to read 
 *   	- \c sc_uint<5> \c reg2		- id2 of register to read 
 *   	- \c sc_uint<5> \c regwrite	- id of register to write 
 *   	- \c sc_uint<32> \c datawr	- value to write 
 *   	- \c bool \c wr			- write enable
 *   	- \c bool \c clk		- clock
 *   	- \c bool \c reset		- reset
 *   - output ports
 *   	- \c sc_uint<32> \c data1		- value of register id1
 *   	- \c sc_uint<32> \c data2		- value of register id2
 */

class regfile : public sc_module, public mem32
{
   public: 
      sc_in< sc_uint<5> >  reg1;
      sc_in< sc_uint<5> >  reg2;        
      sc_in< sc_uint<5> >  regwrite;        
      sc_in< sc_uint<32> > datawr;        
      sc_in<bool> wr;        
      sc_in<bool> clk;
      sc_in<bool> reset;
      sc_in<bool> enable;

      sc_out< sc_uint<32> > data1;        
      sc_out< sc_uint<32> > data2;        

      sc_signal< sc_uint<5> >  s_reg1, s_reg2;

      SC_CTOR(regfile)
      {      
         SC_METHOD(regfile_access);
         sensitive_pos << clk;
         sensitive << s_reg1 << s_reg2;

         init_regs();
      }
      void init_regs();
      void dump();
      void regfile_access();
};

#endif
