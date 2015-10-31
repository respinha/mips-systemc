#ifndef MUX4MOD_H
#define MUX4MOD_H

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
  sc_in< sc_uint<32> >  PC4;
  sc_in< sc_uint<32> >  jr;        
  sc_in< sc_uint<32> >  bta;
  sc_in< sc_uint<32> >  jta;
  sc_in< sc_uint<2> >  sel;        
  sc_out< T > dout;

  SC_CTOR(mux4)
     {      
      SC_METHOD(entry);
      sensitive << PC4 << jr << bta << jta << sel;
    }
  
  void entry();
};  


template <class T> void mux4<T>::entry()
{
  switch(sel.read()) {
    case 0: dout.write(PC4.read());
            break;
    case 1: dout.write(jr.read());
            break;
    case 2: dout.write(bta.read());
            break;
    case 3: dout.write(jta.read());
            break;
  }
}

#endif
