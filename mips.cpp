//mips.cpp

/**
 *
 * MIPS module implementation.
 */

#include "mips.h"

/**
 * buils IF stage components 
 */
void mips::buildIF(void)
{
      // Program Counter
      PCreg = new registo ("PCregister");
      PCreg->din(NPC);
      PCreg->dout(PC);
      PCreg->clk(clk);
      PCreg->reset(reset);
      PCreg->enable(enable_pc);

      // Instruction Memory
      instmem = new imem ("imem");
      instmem->addr(PC);
      instmem->inst(inst);

      // Adds 4 to Program Counter
      add4 = new add ("add4"); 

      add4->op1(PC);
      add4->op2(const4);
      add4->res(PC4);

      // Selects Next Program Counter Value (change to MUX4!!!)
      mPC = new mux4< sc_uint<32> > ("mPC");
   
      mPC->sel(pc_sel);
      mPC->PC4(PC4);
      mPC->bta(BranchTarget);
      mPC->jta(JumpTarget);
      mPC->jr(regdata1);
      mPC->dout(NPC);
}

/**
 * buils ID stage components 
 */
void mips::buildID1(void)
{
      // Decodes Instruction
      dec1 = new decode ("decode");
      dec1->inst(inst_id);
      dec1->rs(rs);
      dec1->rt(rt);
      dec1->rd(rd);
      dec1->imm(imm);
      dec1->opcode(opcode);
      dec1->shamt(shamt);
      dec1->funct(funct);
      dec1->jump(jump);

      // Register File
      rfile = new regfile ("regfile");

      rfile->reg1( rs );
      rfile->reg2( rt );
      rfile->regwrite(WriteReg_wb);
      rfile->data1( regdata1 );
      rfile->data2( regdata2 );

      rfile->wr(RegWrite_wb);
      rfile->datawr(WriteVal);

      rfile->clk(clk);
      rfile->reset(reset);

      rfile->enable(enable_rfile);
      
}

void mips::buildID2(void) {

      // Selects Register to Write
      mr = new mux< sc_uint<5> > ("muxRDst");
   
      mr->sel(RegDst);
      mr->din0(rt_id2);
      mr->din1(rd_id2);
      mr->dout(WriteReg);
   
      // 16 to 32 bit signed Immediate extension
      e1 = new ext("ext");
      e1->din(imm_id2);
      e1->dout(imm_ext);

      // Control
      ctrl = new control ("control");

      ctrl->opcode(opcode_id2); 
      ctrl->funct(funct_id2);   
      ctrl->RegDst(RegDst); 
      //ctrl->Branch(Branch);
      ctrl->MemRead(MemRead);
      ctrl->MemWrite(MemWrite);
      ctrl->MemtoReg(MemtoReg);
      ctrl->ALUOp(ALUOp);
      ctrl->ALUSrc(ALUSrc);
      ctrl->RegWrite(RegWrite);
      ctrl->jbr(jbr);

      // shift left 2 imm_ext 
      sl2 = new shiftl2("sl2");
      sl2->din(imm_ext);
      sl2->dout(addr_ext);

/*
      // Adds Branch Immediate to Program Counter + 4
      addbr = new add ("addbr");
   
      addbr->op1(PC4_id2);
      addbr->op2(addr_ext);  
      addbr->res(BranchTarget);

      */

      // Comparator
      comp = new comparator("comparator");
      comp->din0(regdata1);
      comp->din1(regdata2);
      comp->gr(gr);
      comp->le(le);
      comp->eq(eq);

      // Jumps & Branches Control Unit
      ctrl2 = new control_jbr("control_jbr");
      ctrl2->le(le);
      ctrl2->gr(gr);
      ctrl2->eq(eq);
      ctrl2->jbr(jbr);
      ctrl2->select(pc_sel);
      ctrl2->btaken(BranchTaken);

      jbrcalc = new jbrcalculator("jbrcalc");
      jbrcalc->PC4(PC4_id2);
      jbrcalc->addr_ext(addr_ext);
      jbrcalc->jump_id2(jump_id2);
      jbrcalc->jump_target(JumpTarget);
      jbrcalc->br_target(BranchTarget);

}
/**
 * buils EXE stage components 
 */
void mips::buildEXE(void)
{
      // Selects second operand of ALU
      m1 = new mux< sc_uint<32> > ("muxOp");

      m1->sel(ALUSrc_exe);
      m1->din0(regb_exe);
      m1->din1(imm_exe);
      m1->dout(ALUIn2);



      // ALU
      alu1 = new alu("alu");

      alu1->din1(rega_exe);
      alu1->din2(ALUIn2);
      alu1->op(ALUOp_exe);
      alu1->dout(ALUOut);
      //alu1->zero(Zero);

}

/**
 * buils MEM stage components 
 */
void mips::buildMEM(void)
{
      // Data Memory
      datamem = new dmem ("datamem");
   
      datamem->addr(ALUOut_mem);
      datamem->din(regb_mem);
      datamem->dout(MemOut);
      datamem->wr(MemWrite_mem);
      datamem->rd(MemRead_mem);
      datamem->clk(clk);

/*
      // Enables Branch
      a1 = new andgate ("a1");

      a1->din1(Branch_mem);
      a1->din2(Zero_mem);
      a1->dout(BranchTaken);
*/
}

/**
 * buils WB stage components 
 */
void mips::buildWB(void)
{
      // Selects Result
      m2 = new mux< sc_uint<32> > ("muxRes");
   
      m2->sel(MemtoReg_wb);
      m2->din0(ALUOut_wb);
      m2->din1(MemOut_wb);
      m2->dout(WriteVal);

}

/**
 * Instantiates the pipeline registers and calls other functions to
 * buils stage specific components 
 */
void mips::buildArchitecture(void){

      const4 = 4;
      const1 = true;

      buildIF();

      //reg_if_id
      reg_if_id = new reg_if_id_t("reg_if_id");
      reg_if_id->inst_if(inst);
      reg_if_id->inst_id(inst_id);
      reg_if_id->PC4_if(PC4);
      reg_if_id->PC4_id(PC4_id1);
      reg_if_id->PC_if(PC);
      reg_if_id->PC_id(PC_id);
      reg_if_id->valid_if(const1);
      reg_if_id->valid_id(valid_id);
      reg_if_id->clk(clk);
      reg_if_id->reset(reset_ifid);
      reg_if_id->enable(enable_ifid);


      or_reset_ifid = new orgate("or_reset_ifid");
      or_reset_ifid->din1(reset);
      or_reset_ifid->din2(reset_haz_ifid);
      or_reset_ifid->dout(reset_ifid);

      buildID1();


       //reg_id1 id2
      reg_id1_id2 = new reg_id1_id2_t("reg_id1_id2");
      reg_id1_id2->rt(rt);
      reg_id1_id2->rd(rd);
      reg_id1_id2->rs(rs);
      reg_id1_id2->rs_id2(rs_id2);
      reg_id1_id2->rt_id2(rt_id2);
      reg_id1_id2->rd_id2(rd_id2);
      reg_id1_id2->opcode_id1(opcode);
      reg_id1_id2->funct_id1(funct);
      reg_id1_id2->opcode_id2(opcode_id2);
      reg_id1_id2->funct_id2(funct_id2);
      reg_id1_id2->imm_id1(imm);
      reg_id1_id2->imm_id2(imm_id2);
      reg_id1_id2->PC4_id1(PC4_id1);
      reg_id1_id2->PC4_id2(PC4_id2);
      reg_id1_id2->jump_id1(jump);
      reg_id1_id2->jump_id2(jump_id2);

      reg_id1_id2->PC_id1(PC_id);
      reg_id1_id2->PC_id2(PC_id2);
      reg_id1_id2->valid_id1(valid_id);
      reg_id1_id2->valid_id2(valid_id2);

      reg_id1_id2->clk(clk);
      reg_id1_id2->reset(reset_id1id2);
      reg_id1_id2->enable(enable_id1id2);

      or_reset_id1id2 = new orgate("or_reset_id1id2");
      or_reset_id1id2->din1(reset);
      or_reset_id1id2->din2(reset_haz_id1id2);
      or_reset_id1id2->dout(reset_id1id2);


      buildID2();


      //reg_id_exe
      reg_id_exe = new reg_id_exe_t("reg_id_exe");
      reg_id_exe->rega_id(regdata1);
      reg_id_exe->rega_exe(rega_exe);
      reg_id_exe->regb_id(regdata2);
      reg_id_exe->regb_exe(regb_exe);
      reg_id_exe->imm_id(imm_ext);
      reg_id_exe->imm_exe(imm_exe);
      //reg_id_exe->PC4_id(PC4_id2);
      //reg_id_exe->PC4_exe(PC4_exe); 
      reg_id_exe->WriteReg_id(WriteReg);
      reg_id_exe->WriteReg_exe(WriteReg_exe);
      reg_id_exe->MemRead_id(MemRead);
      reg_id_exe->MemRead_exe(MemRead_exe);
      reg_id_exe->MemWrite_id(MemWrite);
      reg_id_exe->MemWrite_exe(MemWrite_exe);
      reg_id_exe->MemtoReg_id(MemtoReg);
      reg_id_exe->MemtoReg_exe(MemtoReg_exe);
      //reg_id_exe->Branch_id(Branch);
      //reg_id_exe->Branch_exe(Branch_exe);
      reg_id_exe->RegWrite_id(RegWrite);
      reg_id_exe->RegWrite_exe(RegWrite_exe);
      reg_id_exe->ALUSrc_id(ALUSrc);
      reg_id_exe->ALUSrc_exe(ALUSrc_exe);
      reg_id_exe->ALUOp_id(ALUOp);
      reg_id_exe->ALUOp_exe(ALUOp_exe);
      reg_id_exe->PC_id(PC_id2);
      reg_id_exe->PC_exe(PC_exe);
      reg_id_exe->valid_id(valid_id2);
      reg_id_exe->valid_exe(valid_exe);
      reg_id_exe->clk(clk);
      reg_id_exe->reset(reset_idexe);
      reg_id_exe->enable(const1);

      or_reset_idexe = new orgate("or_reset_idexe");
      or_reset_idexe->din1(reset);
      or_reset_idexe->din2(reset_haz_idexe);
      or_reset_idexe->dout(reset_idexe);

      buildEXE();

      //reg_exe_mem
      reg_exe_mem = new reg_exe_mem_t("reg_exe_mem");
      reg_exe_mem->aluOut_exe(ALUOut);
      reg_exe_mem->aluOut_mem(ALUOut_mem);
      reg_exe_mem->MemRead_exe(MemRead_exe);
      reg_exe_mem->MemRead_mem(MemRead_mem);
      reg_exe_mem->MemWrite_exe(MemWrite_exe);
      reg_exe_mem->MemWrite_mem(MemWrite_mem);
      reg_exe_mem->MemtoReg_exe(MemtoReg_exe);
      reg_exe_mem->MemtoReg_mem(MemtoReg_mem);
      //reg_exe_mem->Branch_exe(Branch_exe);
      //reg_exe_mem->Branch_mem(Branch_mem);
      reg_exe_mem->RegWrite_exe(RegWrite_exe);
      reg_exe_mem->RegWrite_mem(RegWrite_mem);
      //reg_exe_mem->Zero_exe(Zero);
      //reg_exe_mem->Zero_mem(Zero_mem);
      //reg_exe_mem->BranchTarget_exe(BranchTarget);
      //reg_exe_mem->BranchTarget_mem(BranchTarget_mem);
      reg_exe_mem->regb_exe(regb_exe);
      reg_exe_mem->regb_mem(regb_mem);
      reg_exe_mem->WriteReg_exe(WriteReg_exe);
      reg_exe_mem->WriteReg_mem(WriteReg_mem);
      reg_exe_mem->PC_exe(PC_exe);
      reg_exe_mem->PC_mem(PC_mem);
      reg_exe_mem->valid_exe(valid_exe);
      reg_exe_mem->valid_mem(valid_mem);
      reg_exe_mem->clk(clk);
      reg_exe_mem->reset(reset_exmem);
      reg_exe_mem->enable(const1);

      or_reset_exmem = new orgate("or_reset_exmem");
      or_reset_exmem->din1(reset);
      or_reset_exmem->din2(reset_haz_exmem);
      or_reset_exmem->dout(reset_exmem);
 
      buildMEM();
      
      //reg_mem_wb
      reg_mem_wb = new reg_mem_wb_t("reg_mem_wb");
      reg_mem_wb->aluOut_mem(ALUOut_mem);
      reg_mem_wb->aluOut_wb(ALUOut_wb);
      reg_mem_wb->memOut_mem(MemOut);
      reg_mem_wb->memOut_wb(MemOut_wb);
      reg_mem_wb->MemtoReg_mem(MemtoReg_mem);
      reg_mem_wb->MemtoReg_wb(MemtoReg_wb);
      reg_mem_wb->RegWrite_mem(RegWrite_mem);
      reg_mem_wb->RegWrite_wb(RegWrite_wb);
      reg_mem_wb->WriteReg_mem(WriteReg_mem);
      reg_mem_wb->WriteReg_wb(WriteReg_wb);
      reg_mem_wb->PC_mem(PC_mem);
      reg_mem_wb->PC_wb(PC_wb);
      reg_mem_wb->valid_mem(valid_mem);
      reg_mem_wb->valid_wb(valid_wb);
      reg_mem_wb->clk(clk);
      reg_mem_wb->reset(reset_memwb);
      reg_mem_wb->enable(const1);

      or_reset_memwb = new orgate("or_reset_memwb");
      or_reset_memwb->din1(reset);
      or_reset_memwb->din2(reset_haz_memwb);
      or_reset_memwb->dout(reset_memwb);
 

      buildWB();

      hazard_unit = new hazard("hazard_unit");
      hazard_unit->rs( rs_id2);
      hazard_unit->rt( rt_id2 );
      hazard_unit->WriteReg_exe(WriteReg_exe);
      hazard_unit->WriteReg_wb(WriteReg_wb);
      hazard_unit->RegWrite_exe(RegWrite_exe);
      hazard_unit->WriteReg_mem(WriteReg_mem);
      hazard_unit->RegWrite_mem(RegWrite_mem);
      hazard_unit->RegWrite_wb(RegWrite_wb);
      hazard_unit->enable_pc(enable_pc);
      hazard_unit->enable_ifid(enable_ifid);
      hazard_unit->enable_id1id2(enable_id1id2);
      hazard_unit->reset_id1id2(reset_haz_id1id2);
      hazard_unit->reset_idexe(reset_haz_idexe);
      hazard_unit->reset_ifid(reset_haz_ifid);
      hazard_unit->reset_exmem(reset_haz_exmem);
      hazard_unit->reset_memwb(reset_haz_memwb);
      hazard_unit->MemRead_exe(MemRead_exe);
      hazard_unit->MemRead_mem(MemRead_mem);
      hazard_unit->BranchTaken(BranchTaken);
      hazard_unit->enable_rfile(enable_rfile);
    }

mips::~mips(void)
{
      delete PCreg;
      delete instmem;
      delete add4;
      //delete addbr;
      //delete a1;
      delete mPC;
      delete dec1;
      delete mr;
      delete rfile;
      delete e1;
      delete sl2;
      delete m1;
      delete alu1;
      delete datamem;
      delete m2;
      delete ctrl;
      delete ctrl2;
      delete comp;
      delete jbrcalc;

      delete hazard_unit;
      delete or_reset_idexe;
      delete or_reset_id1id2;
      delete or_reset_ifid;
      delete or_reset_exmem;
      delete or_reset_memwb;
      delete reg_if_id;
      delete reg_id_exe;
      delete reg_id1_id2;
      delete reg_exe_mem;
      delete reg_mem_wb;
}
