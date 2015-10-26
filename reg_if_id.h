#ifndef REG_IF_ID_H
#define REG_IF_ID_H

/**
 *
 * reg_if_id_t module interface.
 */

#include <systemc.h>

#include "regT.h"

/**
 * reg_if_id_t module.
 * reg_if_id_t module is the IF/ID pipeline register. 
 */

SC_MODULE(reg_if_id_t) {

	// Ports
	
	sc_in  < bool > clk;
	sc_in  < bool > reset;
	sc_in  < bool > enable;

	sc_in  < sc_uint<32> > inst_if, PC4_if;
	sc_out < sc_uint<32> > inst_id, PC4_id;

	sc_in  < sc_uint<32> > PC_if;     // only for visualization purposes
	sc_in  < bool >        valid_if;  // only for visualization purposes
	sc_out < sc_uint<32> > PC_id;     // only for visualization purposes
	sc_out < bool >        valid_id;  // only for visualization purposes

	// Modules

	regT < sc_uint<32> > *inst, *PC4;

	regT < sc_uint<32> > *PC;        // only for visualization purposes
	regT < bool > *valid;            // only for visualization purposes

	SC_CTOR(reg_if_id_t) {

		inst = new regT < sc_uint<32> > ("inst");;
		inst->din(inst_if);
		inst->dout(inst_id);
		inst->clk(clk);
		inst->enable(enable);
		inst->reset(reset);

		PC4 = new regT < sc_uint<32> > ("PC4");;
		PC4->din(PC4_if);
		PC4->dout(PC4_id);
		PC4->clk(clk);
		PC4->enable(enable);
		PC4->reset(reset);

		PC = new regT < sc_uint<32> > ("PC");;
		PC->din(PC_if);
		PC->dout(PC_id);
		PC->clk(clk);
		PC->enable(enable);
		PC->reset(reset);

		valid = new regT < bool > ("valid");;
		valid->din(valid_if);
		valid->dout(valid_id);
		valid->clk(clk);
		valid->enable(enable);
		valid->reset(reset);
		
	}
};

#endif
