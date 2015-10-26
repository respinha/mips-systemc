#ifndef REG_MEM_WB_H
#define REG_MEM_WB_H

/**
 *
 * reg_mem_wb_t module interface.
 */

#include <systemc.h>

#include "regT.h"

/**
 * reg_mem_wb_t module.
 * reg_mem_wb_t module is the MEM/WB pipeline register. 
 */

SC_MODULE(reg_mem_wb_t) {

	// Ports
	
	sc_in  < bool > clk;
	sc_in  < bool > reset;
	sc_in  < bool > enable;

	sc_in  < sc_uint<32> > aluOut_mem, memOut_mem;
	sc_out < sc_uint<32> > aluOut_wb, memOut_wb;

	sc_in  < sc_uint<5> > WriteReg_mem;
	sc_out < sc_uint<5> > WriteReg_wb;

	sc_in  < bool > MemtoReg_mem, RegWrite_mem;
	sc_out < bool > MemtoReg_wb, RegWrite_wb;

	sc_in  < sc_uint<32> > PC_mem;   // only for visualization purposes
	sc_out < sc_uint<32> > PC_wb;    // only for visualization purposes
	sc_in  < bool > valid_mem;       // only for visualization purposes
	sc_out < bool > valid_wb;        // only for visualization purposes

	// Modules

	regT < sc_uint<32> > *aluOut, *memOut;
	regT < sc_uint<5> > *WriteReg;
	regT < bool > *MemtoReg, *RegWrite;

	regT < sc_uint<32> > *PC;        // only for visualization purposes
	regT < bool > *valid;            // only for visualization purposes

	SC_CTOR(reg_mem_wb_t) {

		aluOut = new regT < sc_uint<32> > ("aluOut");;
		aluOut->din(aluOut_mem);
		aluOut->dout(aluOut_wb);
		aluOut->clk(clk);
		aluOut->enable(enable);
		aluOut->reset(reset);

		memOut = new regT < sc_uint<32> > ("memOut");;
		memOut->din(memOut_mem);
		memOut->dout(memOut_wb);
		memOut->clk(clk);
		memOut->enable(enable);
		memOut->reset(reset);

		WriteReg = new regT < sc_uint<5> > ("WriteReg");;
		WriteReg->din(WriteReg_mem);
		WriteReg->dout(WriteReg_wb);
		WriteReg->clk(clk);
		WriteReg->enable(enable);
		WriteReg->reset(reset);

		MemtoReg = new regT < bool >("MemtoReg");
		MemtoReg->din(MemtoReg_mem);
		MemtoReg->dout(MemtoReg_wb);
		MemtoReg->clk(clk);
		MemtoReg->enable(enable);
		MemtoReg->reset(reset);

		RegWrite = new regT < bool >("RegWrite");
		RegWrite->din(RegWrite_mem);
		RegWrite->dout(RegWrite_wb);
		RegWrite->clk(clk);
		RegWrite->enable(enable);
		RegWrite->reset(reset);

		PC = new regT < sc_uint<32> > ("PC");;
		PC->din(PC_mem);
		PC->dout(PC_wb);
		PC->clk(clk);
		PC->enable(enable);
		PC->reset(reset);

		valid = new regT < bool > ("valid");;
		valid->din(valid_mem);
		valid->dout(valid_wb);
		valid->clk(clk);
		valid->enable(enable);
		valid->reset(reset);
	}
};

#endif
