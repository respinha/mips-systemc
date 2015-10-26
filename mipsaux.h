
// mipsaux.h

/**
 * \file mipsaux.h
 *
 * auxiliary functions related to MIPS.
 */

#ifndef MIPSAUX_H
#define MIPSAUX_H

/**
 * disassemble determines the assembly instruction from the machine code.
 *
 * disassemble is a function that given the machine code \c cod
 * determines the corresponding MIPS native assembly language instruction
 * %and store it in the \c decod string.
 */
void disassemble(unsigned cod, char *decod);

#endif

