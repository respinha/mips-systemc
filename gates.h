#ifndef GATESMOD_H
#define GATESMOD_H

/**
 * \c several gates module interface
 */

#include <systemc.h>

/**
 * \c andgate module.
 * \c andgate module models a two input and gate
 *   - input ports
 *   	- \c bool \c din1	- first input
 *   	- \c bool \c din2	- second input
 *   - output ports
 *   	- \c bool \c dout	- result
 */

SC_MODULE(andgate) {
  
  sc_in< bool >  din1;
  sc_in< bool >  din2;
  sc_out< bool > dout;

  SC_CTOR(andgate)
     {      
      SC_METHOD(entry);
      sensitive << din1 << din2;
    }
  
  void entry();
};

/**
 * \c orgate module.
 * \c orgate module models a two input or gate
 *   - input ports
 *   	- \c bool \c din1	- first input
 *   	- \c bool \c din2	- second input
 *   - output ports
 *   	- \c bool \c dout	- result
 */

SC_MODULE(orgate) {
  
  sc_in< bool >  din1;
  sc_in< bool >  din2;
  sc_out< bool > dout;

  SC_CTOR(orgate)
     {      
      SC_METHOD(entry);
      sensitive << din1 << din2;
    }
  
  void entry();
};

#endif
