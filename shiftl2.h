#ifndef SHIFTL2MOD_H
#define SHIFTL2MOD_H

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

SC_MODULE(shiftl2) {
  
  sc_in < sc_uint<32> >  din;
  sc_out< sc_uint<32> >  dout;

  SC_CTOR(shiftl2)
     {      
      SC_METHOD(entry);
      sensitive << din;
    }
  
  void entry();
};

#endif
