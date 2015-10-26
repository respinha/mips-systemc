QT              += qt3support
TEMPLATE	= app
CONFIG		+= qt thread release 
HEADERS		= mips.h\
                  imem.h decode.h regfile.h alu.h dmem.h control.h\
		  mem32.h mux.h reg.h add.h gates.h ext.h shiftl2.h\
		  regT.h reg_id_exe.h reg_exe_mem.h reg_mem_wb.h\
		  hazard.h\
		  mipsaux.h\
		  GUI/MIPSctrl.h\
		  GUI/MIPSarch.h GUI/MIPSmods.h GUI/modview.h\
		  GUI/MIPSimemview.h GUI/MIPSregfileview.h GUI/MIPSdmemview.h GUI/MIPSmemview.h\
		  GUI/PortValItem.h GUI/PortValRead.h\
		  GUI/cycle.xpm GUI/reset.xpm \
		  GUI/regs.xpm GUI/datamem.xpm GUI/instmem.xpm \
		  GUI/readimem.xpm GUI/readdmem.xpm
SOURCES		= main.cpp mips.cpp\
                  imem.cpp decode.cpp regfile.cpp alu.cpp dmem.cpp control.cpp\
		  mem32.cpp reg.cpp add.cpp gates.cpp ext.cpp shiftl2.cpp\
		  hazard.cpp\
		  mipsaux.cpp\
		  GUI/MIPSctrl.cpp\ 
		  GUI/MIPSarch.cpp GUI/MIPSmods.cpp GUI/modview.cpp\
		  GUI/MIPSimemview.cpp GUI/MIPSdmemview.cpp GUI/MIPSregfileview.cpp GUI/MIPSmemview.cpp\
		  GUI/PortValItem.cpp GUI/PortValRead.cpp\
		  
INCLUDEPATH     = $(SYSTEMC)/include
LIBS            += -L$(SYSTEMC)/lib-linux64 -L$(SYSTEMC)/lib-linux -lsystemc
unix:TMAKE_UIC  = /usr/bin/uic
TARGET		= MIPS_SystemC

QMAKE_CXXFLAGS +=-fpermissive
QMAKE_CXXFLAGS_RELEASE +=-fpermissive
QMAKE_CFLAGS +=-fpermissive
QMAKE_CFLAGS_RELEASE +=-fpermissive
#The following line was inserted by qt3to4
QT +=  
