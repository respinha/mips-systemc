#ifndef REGTMOD_H
#define REGTMOD_H

/**
 *
 * regT template interface.
 */

#include <systemc.h>

/**
 * regT template.
 * regT template implements a variable width register. 
 * The type of data is selected by the template class T.
 * Synchronous on writes and resets.
 *
 *   - input ports
 *   	- \c T \c din		- input 
 *   	- \c bool \c reset		- reset 
 *   	- \c bool \c enable		- enable 
 *   	- \c bool \c clk		- clock 
 *   - output ports
 *   	- \c T \c dout		- output
 */


template <class T> class regT : public sc_module 
{
public:
  
  sc_in< T >  din;
  sc_out< T > dout;

  sc_in< bool > reset;
  sc_in< bool > enable;
  sc_in< bool > clk;

  T val;

  SC_CTOR(regT)
    {      
      SC_METHOD(entry);
      sensitive_pos << clk;
      val=0;
    }
  
  void entry();
};


template <class T> void regT<T>::entry()
{
    if(reset) {
       val=0;
       dout.write(val);
    }
    else if(clk.event() && clk==1 && enable==1) {
        val=din.read();
        dout.write(val);
    }
}

#endif
