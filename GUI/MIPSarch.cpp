//MIPSarch.cpp
// 
// Widget to display MIPS architecture
//

#include <qpixmap.h>
#include <qevent.h>
#include <qcursor.h>
//Added by qt3to4:
#include <QCloseEvent>
#include <QMouseEvent>

#include "PortValItem.h"
#include "PortValRead.h"

#include "MIPSarch.h"
#include "../mips.h"
#include "../mipsaux.h"

/**
 * MIPSarchcanvas constructor.
 */

MIPSarchCanvas::MIPSarchCanvas(mips &m, QObject *parent) : Q3Canvas(parent), mips1(m)
{
    // set background to MipsArch.png
    QPixmap backFig("GUI/MIPS_datapathPipe4.png");
    resize(backFig.width(),backFig.height());
    setBackgroundPixmap(backFig);

    // create and position the items that display the port values
    PortValItem *portVal;
    Q3CanvasText *qText;

    // instruction labels in stages
    qText=new Q3CanvasText("nop",this);
    qText->setTextFlags(Qt::AlignLeft | Qt::AlignTop);
    qText->setVisible(true);
    qText->move(10,6);
    qText->setColor(QColor("red"));
    instStage.push_back(qText);
    pcStage.push_back(new PortValRead(mips1.PCreg->dout,"PC"));
    validpcStage.push_back(new PortValRead(mips1.reg_if_id->valid_if,"valid_PC"));

    qText=new Q3CanvasText("nop",this);
    qText->setTextFlags(Qt::AlignLeft | Qt::AlignTop);
    qText->setVisible(true);
    qText->move(200,6);
    qText->setColor(QColor("red"));
    instStage.push_back(qText);
    pcStage.push_back(new PortValRead(mips1.reg_if_id->PC_id,"PC_id"));
    validpcStage.push_back(new PortValRead(mips1.reg_if_id->valid_id,"valid_PC_id"));

    qText=new Q3CanvasText("nop",this);
    qText->setTextFlags(Qt::AlignLeft | Qt::AlignTop);
    qText->setVisible(true);
    qText->move(300,6);
    qText->setColor(QColor("green"));
    instStage.push_back(qText);
    pcStage.push_back(new PortValRead(mips1.reg_id1_id2->PC_id2,"PC_id2"));
    validpcStage.push_back(new PortValRead(mips1.reg_id1_id2->valid_id2,"valid_PC_id2"));

    qText=new Q3CanvasText("nop",this);
    qText->setTextFlags(Qt::AlignLeft | Qt::AlignTop);
    qText->setVisible(true);
    qText->move(484,6);
    qText->setColor(QColor("red")); 
    instStage.push_back(qText);
    pcStage.push_back(new PortValRead(mips1.reg_id_exe->PC_exe,"PC_exe"));
    validpcStage.push_back(new PortValRead(mips1.reg_id_exe->valid_exe,"valid_PC_exe"));
    
    qText=new Q3CanvasText("nop",this);
    qText->setTextFlags(Qt::AlignLeft | Qt::AlignTop);
    qText->setVisible(true);
    qText->move(661,6);
    qText->setColor(QColor("red"));
    instStage.push_back(qText);
    pcStage.push_back(new PortValRead(mips1.reg_exe_mem->PC_mem,"PC_mem"));
    validpcStage.push_back(new PortValRead(mips1.reg_exe_mem->valid_mem,"valid_PC_mem"));

    qText=new Q3CanvasText("nop",this);
    qText->setTextFlags(Qt::AlignLeft | Qt::AlignTop);
    qText->setVisible(true);
    qText->move(800,6);
    qText->setColor(QColor("red"));
    instStage.push_back(qText);
    pcStage.push_back(new PortValRead(mips1.reg_mem_wb->PC_wb,"PC_wb"));
    validpcStage.push_back(new PortValRead(mips1.reg_mem_wb->valid_wb,"valid_PC_wb"));



    // value of port signals
    // IF
    portVal=new PortValItem(this,mips1.instmem->addr, "PC");
    portVal->move(81,260);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.add4->res, "PC4");
    portVal->move(110,91);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.PCreg->din, "NPC");
    portVal->move(11,239);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.instmem->inst, "inst");
    portVal->move(153,245);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    //ID
    portVal=new PortValItem(this,mips1.ctrl->RegWrite, "RegWrite");
    portVal->move(383,54);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.ctrl->MemtoReg, "MemtoReg");
    portVal->move(383,66);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    /*portVal=new PortValItem(this,mips1.ctrl->Branch, "Branch");
    portVal->move(383,78);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);*/

    portVal=new PortValItem(this,mips1.ctrl->MemRead, "MemRead");
    portVal->move(383,90);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.ctrl->MemWrite, "MemWrite");
    portVal->move(383,102);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.ctrl->ALUSrc, "ALUSrc");
    portVal->move(383,114);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.ctrl->ALUOp, "ALUOp");
    portVal->move(383,126);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.ctrl->RegDst, "RegDst");
    portVal->move(383,138);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_if_id->inst_id, "inst_id");
    portVal->move(218,256);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);


    portVal=new PortValItem(this,mips1.reg_id1_id2->opcode_id2, "opcode");
    portVal->move(290,95);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id1_id2->funct_id2, "funct");
    portVal->move(290,130);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);


    portVal=new PortValItem(this,mips1.dec1->rd, "rd");
    portVal->move(370,360);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.dec1->imm, "imm");
    portVal->move(299,383);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.rfile->reg1, "r1");
    portVal->move(334,224);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.rfile->reg2, "r2");
    portVal->move(334,243);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.rfile->data1, "r1_out");
    portVal->move(422,222);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.rfile->data2, "r2_out");
    portVal->move(422,251);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.e1->dout, "imm_ext");
    portVal->move(403,398);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.hazard_unit->enable_pc, "enable_pc");
    portVal->move(124,412);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.hazard_unit->reset_idexe, "reset_haz_idexe");
    portVal->move(280,422);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    //EXE
    portVal=new PortValItem(this,mips1.reg_id_exe->RegWrite_exe, "RegWrite_exe");
    portVal->move(475,54);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->MemtoReg_exe, "MemtoReg_exe");
    portVal->move(475,66);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

/*    portVal=new PortValItem(this,mips1.reg_id_exe->Branch_exe, "Branch_exe");
    portVal->move(475,78);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);
    */

    portVal=new PortValItem(this,mips1.reg_id_exe->MemRead_exe, "MemRead_exe");
    portVal->move(475,90);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->MemWrite_exe, "MemWrite_exe");
    portVal->move(475,102);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->ALUSrc_exe, "ALUSrc_exe");
    portVal->move(475,114);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->ALUOp_exe, "ALUOp_exe");
    portVal->move(475,126);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->rega_exe, "rega_exe");
    portVal->move(472,220);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->regb_exe, "regb_exe");
    portVal->move(472,250);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.alu1->din2, "alu_din2");
    portVal->move(535,287);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_id_exe->WriteReg_exe, "WriteReg_exe");
    portVal->move(475,348);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    /*portVal=new PortValItem(this,mips1.reg_id_exe->PC4_exe, "PC4_exe");
    portVal->move(472,171);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal); */

    portVal=new PortValItem(this,mips1.jbrcalc->br_target, "BranchTarget");
    portVal->move(599,167);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.sl2->dout, "addr_ext");
    portVal->move(519,192);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.alu1->dout, "alu_dout");
    portVal->move(591,269);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

  /*  portVal=new PortValItem(this,mips1.alu1->zero, "zero");
    portVal->move(591,236);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

*/
    //MEM
    portVal=new PortValItem(this,mips1.reg_exe_mem->RegWrite_mem, "RegWrite_mem");
    portVal->move(652,54);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_exe_mem->MemtoReg_mem, "MemtoReg_mem");
    portVal->move(652,66);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

/*    portVal=new PortValItem(this,mips1.reg_exe_mem->Branch_mem, "Branch_mem");
    portVal->move(652,78);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);
    */

    portVal=new PortValItem(this,mips1.reg_exe_mem->MemRead_mem, "MemRead_mem");
    portVal->move(652,90);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_exe_mem->MemWrite_mem, "MemWrite_mem");
    portVal->move(652,102);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_exe_mem->aluOut_mem, "aluOut_mem");
    portVal->move(652,250);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_exe_mem->regb_mem, "regb_mem");
    portVal->move(684,294);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_exe_mem->WriteReg_mem, "WriteReg_mem");
    portVal->move(652,349);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.datamem->dout, "dmem.dout");
    portVal->move(758,300);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

/*
    portVal=new PortValItem(this,mips1.reg_exe_mem->Zero_mem, "Zero_mem");
    portVal->move(663,205);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

*/

    portVal=new PortValItem(this,mips1.hazard_unit->BranchTaken, "BranchTaken");
    portVal->move(449,3);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

/*

    portVal=new PortValItem(this,mips1.reg_exe_mem->BranchTarget_mem, "BranchTarget_mem");
    portVal->move(485,24);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);
*/

    //WB

    portVal=new PortValItem(this,mips1.reg_mem_wb->memOut_wb, "memOut_wb");
    portVal->move(806,290);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_mem_wb->aluOut_wb, "aluOut_wb");
    portVal->move(806,328);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_mem_wb->MemtoReg_wb, "MemtoReg_wb");
    portVal->move(806,63);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_mem_wb->WriteReg_wb, "WriteReg_wb");
    portVal->move(612,417);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.reg_mem_wb->RegWrite_wb, "RegWrite_wb");
    portVal->move(612,395);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);

    portVal=new PortValItem(this,mips1.rfile->datawr, "WriteVal");
    portVal->move(612,430);
    portVal->setColor(QColor("blue"));
    portValVec.push_back(portVal);


    updateArch();

    setDoubleBuffering(true);
}

/**
 * updates the values of all ports values.
 */
void MIPSarchCanvas::updateArch(void)
{
    unsigned int p,s,addr;
    char instText[200];
    for(p=0; p<portValVec.size(); p++) {
         portValVec[p]->updateVal();
    }
    for(s=0; s<instStage.size(); s++) {
	 if(validpcStage[s]->read() == 1) { // Stage PC is valid
	     if(pcStage[s]->read() < mips1.instmem->size()) { // StagePC is less than size of instmem
	        addr=mips1.instmem->at(pcStage[s]->read());
	        disassemble(addr,instText);
                instStage[s]->setText(instText);
	     }
	     else instStage[s]->setText("nop");
	 }
	 else instStage[s]->setText("bubble");
    }
    update();
}

MIPSarchCanvas::~MIPSarchCanvas()
{
    // no need to delete child widgets, Qt does it all for us
    for(unsigned int p=0; p < portValVec.size(); p++) {
       delete portValVec[p];
       portValVec[p]=0;
    }
}


/**
 * MIPSarch contructor.
 * Creates and sets the MIPSarchcanvas to be displayed, and some
 * GUI functionalities.
 */
MIPSarch::MIPSarch( mips &m, QWidget* parent,  const char* name, Qt::WFlags fl )
    : Q3CanvasView(0, parent, name, fl )
{   
    archCanvas=new MIPSarchCanvas(m,this);
    setCanvas(archCanvas);

    setIcon(QPixmap("mips.xpm"));

    resize(QSize(896+5,455+5));
    setMaximumSize(QSize(896+5,455+5));

    cursor=new QCursor(Qt::PointingHandCursor);
    setCursor(*cursor);

    viewport()->setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
}

/*  
 *  Destroys the object and frees any allocated resources
 */
MIPSarch::~MIPSarch()
{
    // no need to delete child widgets, Qt does it all for us
    delete cursor;
}

/**
 * updates the port values.
 */
void MIPSarch::updateArch(void)
{
     archCanvas->updateArch();
}

/**
 * emits signals when click is inside certain regions
 */
void MIPSarch::contentsMousePressEvent(QMouseEvent *e)
{
/*

    QPoint pos=e->pos();
    if(pos.x() > 80 && pos.x() < 112 
       && pos.y()> 200 && pos.y() < 270)
       emit imemClicked();
    if(pos.x() > 320 && pos.x() < 370 
       && pos.y()> 190 && pos.y() < 300)
       emit regfileClicked();
    if(pos.x() > 590 && pos.x() < 645 
       && pos.y()> 220 && pos.y() < 280)
       emit dmemClicked();
*/
}

/**
 * changes cursor when mouse is over certain regions
 */

void MIPSarch::contentsMouseMoveEvent(QMouseEvent *e)
{
    QPoint pos=e->pos();

//    fprintf(stderr,"x=%4d y=%4d\n",pos.x(),pos.y());

    cursor->setShape(Qt::ArrowCursor);
    setCursor(*cursor);

}

/**
 * This window is not to be closed.
 */
void MIPSarch::closeEvent(QCloseEvent *e)
{
   e->ignore();
}
