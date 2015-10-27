#ifndef HAZARDMOD_H
#define HAZARDMOD_H

/**
 *
 * hazard module interface.
 */

#include <systemc.h>

/**
 * hazard module.
 * hazard module is the hazard detection unit.
 *
 *   - input ports
 *   	- \c sc_uint<5> \c rs	   - first register being read 
 *   	- \c sc_uint<5> \c rt	   - second register being read 
 *   	- \c sc_uint<5> \c WriteReg_exe	   - register to be written (EXE)
 *   	- \c sc_uint<5> \c WriteReg_mem	   - register to be written (MEM)
 *   	- \c bool \c RegWrite_exe	   - control signal of writing registers (EXE)
 *   	- \c bool \c RegWrite_mem	   - control signal of writing registers (MEM)
 *   - output ports
 *   	- \c bool \c enable_pc      - enables PC update
 *   	- \c bool \c enable_ifid    - enables IF/ID update
 *   	- \c bool \c reset_idexe    - resets IF/EXE
 */

SC_MODULE( hazard )
{
  public: 
    sc_in< sc_uint<5> >  rs;
    sc_in< sc_uint<5> >  rt;        
    sc_in< bool > MemRead;
    sc_in< sc_uint<5> >  WriteReg_exe, WriteReg_mem;        
    sc_in< bool >  RegWrite_exe, RegWrite_mem;        
    sc_in< bool > BranchTaken;
    sc_out< bool >  enable_pc, enable_ifid, reset_id1id2, reset_idexe, reset_ifid, reset_exmem;        

    SC_CTOR(hazard)
    {      
        SC_METHOD(detect_hazard);
        sensitive << rs << rt 
		  << WriteReg_exe << RegWrite_exe
		  << WriteReg_mem << RegWrite_mem
		  << MemRead << BranchTaken;
   }
  
    void detect_hazard();
};

#endif
