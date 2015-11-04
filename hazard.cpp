
#include "hazard.h"

/**
 * Callback for the hazrd detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	//data hazards
	if( rs.read()!=0 && rs.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	    || rs.read()!=0 && rs.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
	    || rs.read()!=0 && rs.read()==WriteReg_wb.read() && RegWrite_wb.read()==true
	    || rt.read()!=0 && rt.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead_exe.read() == true // no caso do lw  
	    || rt.read()!=0 && rt.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead_mem.read() == true
	    || rt.read()!=0 && rt.read()==WriteReg_wb.read() && RegWrite_wb.read()==true){

		enable_pc.write(false);
		enable_ifid.write(false);
		enable_id1id2.write(false);
		enable_rfile.write(false);
		reset_ifid.write(false);
		reset_id1id2.write(false);
		reset_idexe.write(true);
		reset_exmem.write(false);
		reset_memwb.write(false);
		
	}
	else if(BranchTaken.read()){

		enable_pc.write(true);	
		enable_ifid.write(true);
		enable_id1id2.write(true);
		enable_rfile.write(true);
		reset_id1id2.write(false);
		reset_idexe.write(false);
		reset_ifid.write(true);
		reset_exmem.write(false);
		reset_memwb.write(false);
	}
	else {
        enable_pc.write(true);
		enable_ifid.write(true);
		enable_id1id2.write(true);
		enable_rfile.write(true);
		reset_idexe.write(false);
		reset_id1id2.write(false);
		reset_ifid.write(false);
		reset_exmem.write(false);
		reset_memwb.write(false);
	}
}

