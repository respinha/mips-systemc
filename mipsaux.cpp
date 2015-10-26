
// mipsaux.cpp

#include <stdio.h>
#include <string.h>

void disassemble(unsigned cod, char *decod)
{
    unsigned opcode=0, rs,rt,rd,imm,shamt,funct,target;
    bool imm_signed;
    char inst[20];
    
    opcode = (cod>>26);

    if(opcode==0) { //R-Format

       rs    =  ( cod & 0x03e00000 ) >> 21;
       rt    =  ( cod & 0x001f0000 ) >> 16;
       rd    =  ( cod & 0x0000f800 ) >> 11;
       shamt =  ( cod & 0x000007c0 ) >>  5;
       funct =    cod & 0x0000003f;

       switch(funct) {
          case  0: strcpy(inst,"sll"); break;
          case  2: strcpy(inst,"srl"); break;
          case  3: strcpy(inst,"sra"); break;
          case  4: strcpy(inst,"sllv"); break;
	  /* some are missing here */
	  case  8: strcpy(inst,"jr"); break;
	  case  9: strcpy(inst,"jalr"); break;
	  case 12: strcpy(inst,"syscall"); break;
	  case 13: strcpy(inst,"break"); break;
	  /* some are missing here */
          case 32: strcpy(inst,"add"); break;
          case 33: strcpy(inst,"addu"); break;
          case 34: strcpy(inst,"sub"); break;
          case 35: strcpy(inst,"subu"); break;
          case 36: strcpy(inst,"and"); break;
          case 37: strcpy(inst,"or"); break;
	  /* some are missing here */
          case 42: strcpy(inst,"slt"); break;
          case 43: strcpy(inst,"sltu"); break;
	  default: strcpy(decod,"unknown"); return;
       }
       sprintf(decod,"%s $%d,$%d,$%d",inst,rd,rs,rt);
    } else if(opcode < 4) { //J-Format

       target = (cod & 0x3ffffff) << 2;

       switch(opcode) {
          case  2: strcpy(inst,"j");   break;
          case  3: strcpy(inst,"jal");  break;
	  default: strcpy(decod,"unknown"); return;
       }
           
       sprintf(decod,"%s 0x%x",inst,target);
    } else if(opcode < 16) { //I-Format

       rs    =  ( cod & 0x03e00000 ) >> 21;
       rt    =  ( cod & 0x001f0000 ) >> 16;
       imm   =    cod & 0x0000ffff;
       imm_signed=false;
       
       switch(opcode) {
          case  4: strcpy(inst,"beq");   imm_signed =true; break;
          case  5: strcpy(inst,"bne");   imm_signed =true; break;
          case  6: strcpy(inst,"blez");  imm_signed =true; break;
          case  7: strcpy(inst,"bgtz");  imm_signed =true; break;
          case  8: strcpy(inst,"addi");  imm_signed =true; break;
          case  9: strcpy(inst,"addiu"); break;
          case 10: strcpy(inst,"slti");  imm_signed =true; break;
          case 11: strcpy(inst,"sltiu"); break;
          case 12: strcpy(inst,"andi");  break;
          case 13: strcpy(inst,"ori");   break;
          case 14: strcpy(inst,"xori");  break;
          case 15: strcpy(inst,"lui");   break;
	  default: strcpy(decod,"unknown"); return;
       }

       // add sign to imm
       if(imm_signed && (imm & 0x8000)) imm|=0xffff0000;

       sprintf(decod,"%s $%d,$%d,%d",inst,rs,rt,imm);
    /* some opcodes are missing here */
    } else if(opcode > 31 && opcode < 44) { //I-Format

       rs    =  ( cod & 0x03e00000 ) >> 21;
       rt    =  ( cod & 0x001f0000 ) >> 16;
       imm   =    cod & 0x0000ffff;
       imm_signed=false;
       
       switch(opcode) {
	  case 32: strcpy(inst,"lb");  imm_signed=true; break;
	  case 33: strcpy(inst,"lh");  imm_signed=true; break;
	  case 34: strcpy(inst,"lwl"); imm_signed=true; break;
	  case 35: strcpy(inst,"lw");  imm_signed=true; break;
	  /* some are missing here */
	  case 43: strcpy(inst,"sw");  imm_signed=true; break;
	  /* some are missing here */
	  default: strcpy(decod,"unknown"); return;
       }

       // add sign to imm
       if(imm_signed && (imm & 0x8000)) imm|=0xffff0000;

       sprintf(decod,"%s $%d,%d($%d)",inst,rt,imm,rs);
    } else {
       /* some opcodes are missing */
       sprintf(decod,"%s","unknown");
    }
}

