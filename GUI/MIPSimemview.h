#ifndef MIPSIMEMVIEW_H
#define MIPSIMEMVIEW_H

#include <systemc.h>

#include "MIPSmemview.h"

class imem;

class PortValRead;

/**
 * Visualization of instruction memory contents.
 */

class MIPSimemview : public MIPSmemview
{ 
    Q_OBJECT

public:
    MIPSimemview( imem &m, 
		  sc_port_base &pc,          // PC output port
		  sc_port_base &pc_id,       // PC in ID (output of reg_if_id)
		  sc_port_base &valid_id,    // true if PC in ID valid
		  sc_port_base &pc_exe,      // PC in EXE (output of reg_id_exe)
		  sc_port_base &valid_exe,   // true if PC in EXE valid
		  sc_port_base &pc_mem, 
		  sc_port_base &valid_mem, 
		  sc_port_base &pc_wb, 
		  sc_port_base &valid_wb, 
		  QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    virtual ~MIPSimemview();
public slots:
    virtual void initList(void);
protected:
    virtual QString MemItem(unsigned int i);
    virtual unsigned int current(void);
private:
    PortValRead *PC, *PC_id, *Valid_id, *PC_exe, *Valid_exe, 
                *PC_mem, *Valid_mem, *PC_wb, *Valid_wb;
};

#endif // MIPSIMEMVIEW_H
