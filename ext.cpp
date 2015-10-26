
#include "ext.h"

/**
 * sign extends din from 16 bits to 32 bits.
 */
void ext::entry()
{
    sc_int<16> aux16;  
    sc_int<32> aux32;  // cuidado com o sinal
    sc_uint<32> auxu;  

    aux16=din.read();
    aux32=aux16;
    auxu=aux32;

    dout.write(auxu);
}
