#ifndef CONTROLMOD_H
#define CONTROLMOD_H

/**
 *
 * Control module interface.
 */
 
#include <systemc.h>

/**
 * Control module.
 * Control module models the control unit of MIPS.
 *   - input ports
 *   	- \c sc_uint<6> \c opcode	- instruction opcode field
 *   	- \c sc_uint<6> \c funct		- instruction funct field
 *   - output ports
 *   	- \c bool \c RegDst	- selects if rd or rt is written
 *   	- \c bool \c RegWrite	- enables writing in Register file
 *   	- \c bool \c MemRead	- enables reading from Memory 
 *   	- \c bool \c MemWrite	- enables writing to Memory 
 *   	- \c bool \c MemtoReg	- Value to write in register comes from memory
 *   	- \c sc_uint<6> \c ALUOp		- selects ALU operation
 *   	- \c bool \c ALUSrc	- selects ALU second operand
 *   	- \c bool \c Branch	- active if instruction is beq
 */

SC_MODULE(control) {
  
  sc_in< sc_uint<6> >  opcode;
  sc_in< sc_uint<6> >  funct;

  /* jbr (output) defined as:
  *   0: No jump/branch
  *   1: beq
  *   2: bne
  *   3: bgtz
  *   4: blez
  *   5: j
  *   6: jr
  */
  sc_out < sc_uint<3> > jbr;

  sc_out< bool >  RegDst;              
  sc_out< bool >  MemRead;        
  sc_out< bool >  MemtoReg;        
  sc_out< sc_uint<3> >  ALUOp;        
  sc_out< bool >  MemWrite;        
  sc_out< bool >  ALUSrc;        
  sc_out< bool >  RegWrite;        

  SC_CTOR(control)
     {      
      SC_METHOD(entry);
      sensitive << opcode << funct;
    }
  
  void entry();
};

#endif
