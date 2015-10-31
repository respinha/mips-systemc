#ifndef REG_EXE_MEM_H
#define REG_EXE_MEM_H

/**
 *
 * reg_exe_mem_t module interface.
 */

#include <systemc.h>

#include "regT.h"

/**
 * reg_exe_mem_t module.
 * reg_exe_mem_t module is the EXE/MEM pipeline register. 
 */

SC_MODULE(reg_exe_mem_t) {

	// Ports
	
	sc_in  < bool > clk;
	sc_in  < bool > reset;
	sc_in  < bool > enable;

	sc_in  < sc_uint<32> > aluOut_exe, regb_exe; //, BranchTarget_exe;
	sc_out < sc_uint<32> > aluOut_mem, regb_mem; //, BranchTarget_mem;

	sc_in  < sc_uint<5> > WriteReg_exe;
	sc_out < sc_uint<5> > WriteReg_mem;

	sc_in  < bool > MemRead_exe, MemWrite_exe, MemtoReg_exe, RegWrite_exe;
	sc_out < bool > MemRead_mem, MemWrite_mem, MemtoReg_mem, RegWrite_mem;

	//sc_in  < bool > Zero_exe;
	//sc_out < bool > Zero_mem;

	sc_in  < sc_uint<32> > PC_exe;   // only for visualization purposes
	sc_out < sc_uint<32> > PC_mem;   // only for visualization purposes
	sc_in  < bool > valid_exe;       // only for visualization purposes
	sc_out < bool > valid_mem;       // only for visualization purposes

	// Modules

	regT < sc_uint<32> > *aluOut, *regb; //, *BranchTarget;
	regT < sc_uint<5> >  *WriteReg;
	regT < bool > *MemRead, *MemWrite, *MemtoReg, *RegWrite;

	regT < sc_uint<32> > *PC;        // only for visualization purposes
	regT < bool > *valid;            // only for visualization purposes

	SC_CTOR(reg_exe_mem_t) {

		aluOut = new regT < sc_uint<32> > ("aluOut");;
		aluOut->din(aluOut_exe);
		aluOut->dout(aluOut_mem);
		aluOut->clk(clk);
		aluOut->enable(enable);
		aluOut->reset(reset);

		regb = new regT < sc_uint<32> > ("regb");;
		regb->din(regb_exe);
		regb->dout(regb_mem);
		regb->clk(clk);
		regb->enable(enable);
		regb->reset(reset);

		WriteReg = new regT < sc_uint<5> > ("WriteReg");;
		WriteReg->din(WriteReg_exe);
		WriteReg->dout(WriteReg_mem);
		WriteReg->clk(clk);
		WriteReg->enable(enable);
		WriteReg->reset(reset);

/*		BranchTarget = new regT < sc_uint<32> > ("BranchTarget");;
		BranchTarget->din(BranchTarget_exe);
		BranchTarget->dout(BranchTarget_mem);
		BranchTarget->clk(clk);
		BranchTarget->enable(enable);
		BranchTarget->reset(reset);
*/

		MemRead = new regT < bool >("MemRead");
		MemRead->din(MemRead_exe);
		MemRead->dout(MemRead_mem);
		MemRead->clk(clk);
		MemRead->enable(enable);
		MemRead->reset(reset);

		MemWrite = new regT < bool >("MemWrite");
		MemWrite->din(MemWrite_exe);
		MemWrite->dout(MemWrite_mem);
		MemWrite->clk(clk);
		MemWrite->enable(enable);
		MemWrite->reset(reset);

		MemtoReg = new regT < bool >("MemtoReg");
		MemtoReg->din(MemtoReg_exe);
		MemtoReg->dout(MemtoReg_mem);
		MemtoReg->clk(clk);
		MemtoReg->enable(enable);
		MemtoReg->reset(reset);

/*
		Branch = new regT < bool >("Branch");
		Branch->din(Branch_exe);
		Branch->dout(Branch_mem);
		Branch->clk(clk);
		Branch->enable(enable);
		Branch->reset(reset);

		Zero = new regT < bool >("Zero");
		Zero->din(Zero_exe);
		Zero->dout(Zero_mem);
		Zero->clk(clk);
		Zero->enable(enable);
		Zero->reset(reset);
*/

		RegWrite = new regT < bool >("RegWrite");
		RegWrite->din(RegWrite_exe);
		RegWrite->dout(RegWrite_mem);
		RegWrite->clk(clk);
		RegWrite->enable(enable);
		RegWrite->reset(reset);

		// Visualization only
		PC = new regT < sc_uint<32> > ("PC");;
		PC->din(PC_exe);
		PC->dout(PC_mem);
		PC->clk(clk);
		PC->enable(enable);
		PC->reset(reset);

		valid = new regT < bool > ("valid");;
		valid->din(valid_exe);
		valid->dout(valid_mem);
		valid->clk(clk);
		valid->enable(enable);
		valid->reset(reset);

	}
};

#endif
