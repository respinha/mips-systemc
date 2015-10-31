#ifndef COMP_H
#define COMP_H

#include <systemc.h>

SC_MODULE(comparator) {
  
  sc_in< sc_uint<32> >  din0;
  sc_in< sc_uint<32> >  din1;        
  sc_out< bool >  gr, eq, le;

  SC_CTOR(comparator)
     {      
      SC_METHOD(entry);
      sensitive << din0 << din1;
    }
  
  void entry();
};


#endif
