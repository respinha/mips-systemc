
#include "concat.h"

void concatenator::entry()
{
	sc_uint<32> tPC4, tjump;
	sc_uint<2> zeros = 0;

	tPC4 = PC4.read();
	tjump = jump.read();

	sc_uint<28> concatenatedValue;
	concatenatedValue = (zeros, tPC4.range(29,26));

	PreShift.write((concatenatedValue, jump));
}
