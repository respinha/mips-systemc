
#include "comp.h"

/**
 * \c decode module callback function.
 */
void comparator::entry()
{ 
	sc_uint<32> a = din0.read();
    sc_uint<32> b = din1.read();

    sc_int<32> asign;
    sc_int<32> bsign;

    asign=a;
    bsign=b;

    sc_int<32> result = asign-bsign;

    eq.write(result == 0);
    gr.write(result > 0);
    le.write(result <= 0);
}
