#ifndef DECODEMOD_H
#define DECODEMOD_H

/**
 *
 * Decode module interface.
 */

#include <systemc.h>

/**
 * Decode module.
 * Decode module splits instruction in its fields.
 *   - input ports
 *   	- \c sc_uint<32> \c inst		- instruction 
 *   - output ports
 *   	- \c sc_uint<5> \c rs		- instruction rs field
 *   	- \c sc_uint<5> \c rd		- instruction rd field
 *   	- \c sc_uint<5> \c rt		- instruction rt field
 *   	- \c sc_uint<16> \c imm		- instruction imm field
 *   	- \c sc_uint<6> \c opcode		- instruction opcode field
 *   	- \c sc_uint<5> \c funct		- instruction funct field
 *   	- \c sc_uint<6> \c shamt		- instruction shamt field
 */

SC_MODULE(decode) {
  
  sc_in< sc_uint<32> >  inst;
  sc_out< sc_uint<5> >  rs;        
  sc_out< sc_uint<5> >  rt;        
  sc_out< sc_uint<5> >  rd;        
  sc_out< sc_uint<16> >  imm;        
  sc_out< sc_uint<6> > opcode;        
  sc_out< sc_uint<5> > shamt;        
  sc_out< sc_uint<6> > funct;
  sc_out< sc_uint<26> > jump;        

  SC_CTOR(decode)
     {      
      SC_METHOD(entry);
      sensitive << inst;
    }
  
  void entry();
};

#endif
