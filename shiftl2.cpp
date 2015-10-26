
#include "shiftl2.h"

/**
 * \c shifl2 module callback function.
 */
void shiftl2::entry()
{
    dout.write(din.read() << 2);
}
