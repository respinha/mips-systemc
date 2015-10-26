#ifndef EXTMOD_H
#define EXTMOD_H

/**
 *
 * \c ext module interface.
 */

#include <systemc.h>

/**
 * \c ext module.
 * \c ext module sign extends a sc_uint<16> value to a sc_uint<32>.
 *   - input ports
 *   	- \c sc_uint<16> \c din	- input
 *   - output ports
 *   	- \c sc_uint<16> \c dout	- output
 */

SC_MODULE(ext) {
  
  sc_in< sc_uint<16> >  din;
  sc_out< sc_uint<32> > dout;

  SC_CTOR(ext)
     {      
      SC_METHOD(entry);
      sensitive << din;
    }
  
  void entry();
};

#endif
