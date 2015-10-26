
#include "reg.h"

/**
 * \c registo module callback function.
 */
void registo::entry()
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
