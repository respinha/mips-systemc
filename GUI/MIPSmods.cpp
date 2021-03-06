// MIPSmods.cpp


#include "../mips.h"
#include "modview.h"

#include "MIPSmods.h"
//Added by qt3to4:
#include <QPixmap>
#include <QCloseEvent>

#define MODSTEPX 160   // horizontal spacing of module views

/**
 * MIPSmods contructor.
 * Creates and inicializes the widgets that display the
 * port values of intruction memory, control, decode, register file,
 * alu and data memory.
 */
MIPSmods::MIPSmods( mips &m, QWidget* parent,  const char* name, Qt::WFlags fl )
    : Q3ScrollView( parent, name, fl ), mips1(m)
{   
    //resize viewport
    resizeContents(820+5,194+5);

    resize( QSize(1200+10,250+10) ); 
    setMaximumSize( QSize(1200+10,250+10) ); 

    setIcon(QPixmap("mips.xpm"));

    setVScrollBarMode(Auto);
    setHScrollBarMode(Auto);

    //imemview
    ModView *imemView=new ModView("imem",viewport());
    imemView->addPort(mips1.instmem->addr, "PC");
    imemView->addPort(mips1.instmem->inst, "inst");
    addChild(imemView,5,5);
    
    connect(this,SIGNAL(updateModules()), imemView, SLOT(redrawModule()));

    //ctrlview
    ModView *ctrlView=new ModView("Control",viewport());
    ctrlView->addPort(mips1.ctrl->opcode,  "opcode");
    ctrlView->addPort(mips1.ctrl->funct,   "funct");
    ctrlView->addPort(mips1.ctrl->RegDst,  "RegDst");
   // ctrlView->addPort(mips1.ctrl->Branch,  "Branch");
    ctrlView->addPort(mips1.ctrl->MemRead, "MemRead");
    ctrlView->addPort(mips1.ctrl->MemWrite,"MemWrite");
    ctrlView->addPort(mips1.ctrl->MemtoReg,"MemtoReg");
    ctrlView->addPort(mips1.ctrl->ALUSrc,  "ALUSrc");
    ctrlView->addPort(mips1.ctrl->ALUOp,   "ALUOp");
    ctrlView->addPort(mips1.ctrl->RegWrite,"RegWrite");
    ctrlView->addPort(mips1.ctrl->jbr,"jbr");
    addChild(ctrlView,5+MODSTEPX*1,5);
    
    connect(this,SIGNAL(updateModules()), ctrlView, SLOT(redrawModule()));

    //rfileview
    ModView *rfileView=new ModView("regfile",viewport());
    rfileView->addPort(mips1.rfile->reg1, "r1");
    rfileView->addPort(mips1.rfile->reg2, "r2");
    rfileView->addPort(mips1.rfile->regwrite, "rw");
    rfileView->addPort(mips1.rfile->data1, "r1_out");
    rfileView->addPort(mips1.rfile->data2, "r2_out");
    rfileView->addPort(mips1.rfile->datawr, "rw_in");
    addChild(rfileView,5+MODSTEPX*2,5);
    
    connect(this,SIGNAL(updateModules()), rfileView, SLOT(redrawModule()));

    //aluView
    ModView *aluView=new ModView("ALU",viewport());
    aluView->addPort(mips1.alu1->din1, "din1");
    aluView->addPort(mips1.alu1->din2, "din2");
    aluView->addPort(mips1.alu1->op, "op");
    aluView->addPort(mips1.alu1->dout, "dout");
   // aluView->addPort(mips1.alu1->zero, "zero");
    addChild(aluView,5+MODSTEPX*3,5);

    connect(this,SIGNAL(updateModules()), aluView, SLOT(redrawModule()));

    //dmemview
    ModView *dmemView=new ModView("dmem",viewport());
    dmemView->addPort(mips1.datamem->addr, "addr");
    dmemView->addPort(mips1.datamem->din, "din");
    dmemView->addPort(mips1.datamem->dout, "dout");
    addChild(dmemView,5+MODSTEPX*4,5);
    
    connect(this,SIGNAL(updateModules()), dmemView, SLOT(redrawModule()));

    //hazview
    ModView *hazview=new ModView("haz",viewport());
    hazview->addPort(mips1.hazard_unit->rs, "rs");
    hazview->addPort(mips1.hazard_unit->rt, "rt");
    hazview->addPort(mips1.hazard_unit->MemRead_exe, "MRead_e");
    hazview->addPort(mips1.hazard_unit->MemRead_mem, "MRead_m");
    hazview->addPort(mips1.hazard_unit->WriteReg_exe, "WrReg_e");
    hazview->addPort(mips1.hazard_unit->WriteReg_mem, "WrReg_m");
    hazview->addPort(mips1.hazard_unit->RegWrite_exe, "RWrite_e");
    hazview->addPort(mips1.hazard_unit->RegWrite_mem, "RWrite_m");
    hazview->addPort(mips1.hazard_unit->BranchTaken, "BrTken"); 
    hazview->addPort(mips1.hazard_unit->enable_pc, "en_pc");
    hazview->addPort(mips1.hazard_unit->enable_ifid, "en_ifid");
    hazview->addPort(mips1.hazard_unit->enable_id1id2, "en_id1id2");
    hazview->addPort(mips1.hazard_unit->reset_id1id2, "rs_id1id2");
    hazview->addPort(mips1.hazard_unit->reset_idexe, "rs_idexe");
    hazview->addPort(mips1.hazard_unit->reset_ifid, "rs_ifid");
    hazview->addPort(mips1.hazard_unit->reset_exmem, "rs_exmem");

    addChild(hazview,5+MODSTEPX*5,5);
    
    connect(this,SIGNAL(updateModules()), hazview, SLOT(redrawModule()));


    ModView *ctrl2view =new ModView("ctrl2",viewport());
    ctrl2view->addPort(mips1.ctrl2->le, "le");
    ctrl2view->addPort(mips1.ctrl2->gr, "gr");
    ctrl2view->addPort(mips1.ctrl2->eq, "eq");
    ctrl2view->addPort(mips1.ctrl2->select, "ctrl2_sel");
    ctrl2view->addPort(mips1.ctrl2->jbr, "jbr");
    ctrl2view->addPort(mips1.ctrl2->btaken, "btaken");

    addChild(ctrl2view,5+MODSTEPX*6,5);
    
    connect(this,SIGNAL(updateModules()), ctrl2view, SLOT(redrawModule()));

    setFocusPolicy(Qt::StrongFocus);
}

/*  
 *  Destroys the object and frees any allocated resources
 */
MIPSmods::~MIPSmods()
{
    // no need to delete child widgets, Qt does it all for us
}

void MIPSmods::closeEvent(QCloseEvent *e)
{
   e->ignore();  //dont close
}
