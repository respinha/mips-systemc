	
#include "jbrcalc.h"

void jbrcalculator::entry()
{
	sc_uint<32> tPC4, tjump, concat_v, finalVal;
	sc_uint<2> zeros = 0;
	sc_uint<28> pc4_zeros;

	tPC4 = PC4.read();
	tjump = jump_id2.read();

	
	pc4_zeros = (zeros, tPC4.range(29,26));
	concat_v = (pc4_zeros, tjump);
	finalVal = concat_v << 2;

	jump_target.write(finalVal);
	br_target.write((int) PC4.read() + (int) addr_ext.read());
}
