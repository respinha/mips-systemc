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

SC_MODULE(control_jbr) {
  
  sc_in< sc_uint<32> > loe;
  sc_in< sc_uint<32> > gr;
  sc_in< sc_uint<32> > eq;

  sc_out< sc_uint<2> > dout;
  sc_out< bool > btaken;     

  SC_CTOR(control_jbr)
     {      
      SC_METHOD(entry);
      sensitive << loe << gr << eq;
    }
  
  void entry();
};

#endif
