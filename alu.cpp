
// alu.cpp

#include "alu.h"

/**
 * \c alu module callback function.
 */
void alu::calc()
{
    sc_uint<32> a=din1.read();
    sc_uint<32> b=din2.read();
    sc_int<32> asign;
    sc_int<32> bsign;

    asign=a;
    bsign=b;

    sc_uint<32> res;

    switch (op.read())
    {
       case 0: res = a & b;    // and
               break;
       case 1: res = a | b;    // or
               break;
       case 2: res = a + b;    // add
               break;
       case 6: res = a - b;    // subtract
               break;
       case 7: res = (asign < bsign);  // set on less than
               break;
    }
    
    dout.write(res);
}
