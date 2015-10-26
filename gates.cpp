
#include "gates.h"

/**
 * \c andgate module callback function.
 */
void andgate::entry()
{
   dout.write(din1.read() && din2.read());
}

/**
 * \c orgate module callback function.
 */
void orgate::entry()
{
   dout.write(din1.read() || din2.read());
}
