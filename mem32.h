//mem32.h

#ifndef MEM32MOD_H
#define MEM32MOD_H

/**
 * \c mem32 class interface.
 */

#include <systemc.h>
#include <vector>

using std::vector;

/**
 * \c mem32 is the base class of all 32 bit memories (instruction memory,
 * data memory %and register bank).
 *
 * \c mem32 includes a variable size vector of \c sc_int<32> elements and basic 
 * access functions to these elements.
 */ 
class mem32
{
  public:
    /** size in bytes of memory. */
    unsigned int size();
    void init_memory(const char *);

    /** returns element at address addr (considers addr as byte address).
     * only accepts addresses multiple of 4.*/
    sc_uint<32> at(sc_uint<32> addr);
  protected:

    vector< sc_uint<32> > memory;
};

#endif
