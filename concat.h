#ifndef CONCATMOD_H
#define CONCATMOD_H

/**
 *
 * \c shiftl2 module interface.
 */

#include <systemc.h>

/**
 * \c shiftl2 module.
 * \c shiftl2 module shifts a sc_uint<32> two bits to the left.
 *   - input ports
 *   	- \c sc_uint<32> \c din	- input
 *   - output ports
 *   	- \c sc_uint<32> \c dout	- output
 */

SC_MODULE(concatenator) {
  
  sc_in < sc_uint<32> >  PC4;
  sc_in< sc_uint<26> >  jump;
  sc_out < sc_uint<32> > PreShift;

  SC_CTOR(concatenator)
     {      
      SC_METHOD(entry);
      sensitive << PC4 << jump;
    }
  
  void entry();
};

#endif
