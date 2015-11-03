#ifndef JBRCMOD_H
#define JBRCMOD_H

/**
 *
 * \c jbrcalculator module interface.
 */

#include <systemc.h>

/**
 * jbrcalculator module
 * Inputs: PC4, jump_id2, addr_ext;
 * Outputs: JumpTargetAddress, BranchTargetAddress
 */

SC_MODULE(jbrcalculator) {
  
  sc_in < sc_uint<32> >  PC4;
  sc_in < sc_uint<26> >  jump_id2;
  sc_in < sc_uint<32> >  addr_ext;

  sc_out < sc_uint<32> > jump_target;
  sc_out < sc_uint<32> > br_target;

  SC_CTOR(jbrcalculator)
     {      
      SC_METHOD(entry);
      sensitive << PC4 << jump_id2 << addr_ext;
    }
  
  void entry();
};

#endif
