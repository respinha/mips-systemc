#ifndef COMP_H
#define COMP_H

/**
 *
 * 2:1 Mux module template.
 */

#include <systemc.h>

/**
 * Mux module.
 * Mux module models a generic 2:1 multiplexor of template type T. 
 * Implementation based on a template class.
 *
 *   - input ports
 *   	- \c T \c din0		- input 
 *   	- \c T \c din1		- input 
 *   	- \c bool \c sel		- select 
 *   - output ports
 *   	- \c T \c dout		- output
 */

class comparator: public sc_module
{
public:
  sc_in< sc_uint<32> >  din0;
  sc_in< sc_uint<32> >  din1;
  sc_in< sc_uint<2> >  sel;        
  sc_out< T > dout;

  SC_CTOR(comparator)
     {      
      SC_METHOD(entry);
      sensitive << din0 << din1 << din2 << din3 << sel;
    }
  
};  


#endif
