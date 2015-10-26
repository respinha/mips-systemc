//MIPSimemview.cpp

#include "../imem.h"
#include "../mipsaux.h"

#include "PortValRead.h"

#include "MIPSimemview.h"

MIPSimemview::MIPSimemview( imem &m, 
		            sc_port_base &pc, 
		            sc_port_base &pc_id, 
		            sc_port_base &valid_id, 
		            sc_port_base &pc_exe, 
		            sc_port_base &valid_exe, 
		            sc_port_base &pc_mem, 
		            sc_port_base &valid_mem, 
		            sc_port_base &pc_wb, 
		            sc_port_base &valid_wb, 
		            QWidget* parent,  const char* name, Qt::WFlags fl )
    : MIPSmemview( m, parent, name, fl )
{   
    // access to PC value
    PC     = new PortValRead(pc,"PC");
    PC_id  = new PortValRead(pc_id,"PC_id");
    Valid_id  = new PortValRead(valid_id,"valid_id");
    PC_exe = new PortValRead(pc_exe,"PC_exe");
    Valid_exe = new PortValRead(valid_exe,"valid_exe");
    PC_mem = new PortValRead(pc_mem,"PC_mem");
    Valid_mem = new PortValRead(valid_mem,"valid_mem");
    PC_wb  = new PortValRead(pc_wb,"PC_wb");
    Valid_wb  = new PortValRead(valid_wb,"valid_wb");

    initList();
}

QString MIPSimemview::MemItem(unsigned int i)
{
    unsigned int instVal;
    QString HexVal, ListStr;
    char instStr[200];

    //PCs
    if(PC->read() == i) ListStr = "F";
    else if(PC_id->read()  == i && Valid_id->read()  == 1) ListStr="D";
    else if(PC_exe->read() == i && Valid_exe->read() == 1) ListStr="E";
    else if(PC_mem->read() == i && Valid_mem->read() == 1) ListStr="M";
    else if(PC_wb->read()  == i && Valid_wb->read()  == 1) ListStr="W";
    else ListStr=" ";
	
    //address
    HexVal.setNum(i,16);
    ListStr+=HexVal.rightJustify(4)+":";

    //Instruction code
    instVal=mem.at(i);
    HexVal.setNum((unsigned) instVal,16);
    ListStr=ListStr+HexVal.rightJustify(8);

    //instruction
    disassemble(instVal,instStr);
    ListStr=ListStr+" "+instStr;

    return ListStr;
}

unsigned int MIPSimemview::current()
{
    return PC->read()/4;
}

/**  
 *  Inserts one MemItem in ListBox for each word in memory.
 *  Determines maximum sizes of widget.
 */
void MIPSimemview::initList()
{
    MIPSmemview::initList();

    if(count()>0) {
       // determine maxWidth
       unsigned int i,height, maxWidth=0;
       for(i=0; i < count() ; i++)
           if((unsigned)(item(i)->width(this)) > maxWidth)
              maxWidth=item(i)->width(this);

       height=item(0)->height(this);  // is fixed for all items
        
       // set Maximum size
       setMaximumSize(maxWidth+20,height*mem.size()/4+4);

       if(mem.size()>0 && mem.size()<80) 
          resize(maxWidth+4,height*mem.size()/4+4);
       else resize(maxWidth+20,100);
    }
}

/**  
 *  Destroys the object and frees any allocated resources
 */
MIPSimemview::~MIPSimemview()
{
    // no need to delete child widgets, Qt does it all for us
    delete PC;
    delete PC_id;
    delete Valid_id;
    delete PC_exe;
    delete Valid_exe;
    delete PC_mem;
    delete Valid_mem;
    delete PC_wb;
    delete Valid_wb;
}
