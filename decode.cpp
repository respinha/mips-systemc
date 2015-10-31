
#include "decode.h"

/**
 * \c decode module callback function.
 */
void decode::entry()
{
  sc_uint<32> tinst;

  tinst=inst.read();

  rs.write(tinst.range(25,21));
  rt.write(tinst.range(20,16));
  rd.write(tinst.range(15,11));
  imm.write(tinst.range(15,0));
  opcode.write(tinst.range(31,26));
  shamt.write(tinst.range(10,6));
  funct.write(tinst.range(5,0));
  jump.write(tinst.range(25,0));
}
