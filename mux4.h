#ifndef MUXMOD_H
#define MUXMOD_H

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

template <class T> class mux4: public sc_module
{
public:
  sc_in< T >  din0;
  sc_in< T >  din1;        
  sc_in< T >  din2;
  sc_in< T >  din3;
  sc_in< sc_uint<2> >  sel;        
  sc_out< T > dout;

  SC_CTOR(mux)
     {      
      SC_METHOD(entry);
      sensitive << din0 << din1 << din2 << din3 << sel;
    }
  
  void entry();
};


template <class T> void mux4<T>::entry()
{
  switch(sel.read()) {
    case 0: dout.write(din0.read());
            break;
    case 1: dout.write(din1.read());
            break;
    case 2: dout.write(din2.read());
            break;
    case 3: dout.write(din3.read());
            break;
  }
}

#endif
