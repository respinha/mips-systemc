//main.cpp

/**
 * \file main.cpp
 *
 * defines \c sc_main function where all SystemC programs start.
 */
#include <systemc.h>

#include <qapplication.h>
#include "GUI/MIPSctrl.h"

#include "mips.h"

/**
 * \mainpage MIPS_SystemC
 * \section intro Introduction
 *
 * \c MIPS_SystemC is a MIPS simulator that uses SystemC to model a
 * MIPS pipelined architecture. The architecture is identical to 
 * the one presented
 * in "Computer Organization %and Design" by Hennessy&Patterson. 
 * \c MIPS_SystemC has a graphical user interface that allows %control of 
 * program execution
 * %and displays some of the signal values inside the architecture.
 *
 * \section compile Compiling
 *
 * To compile \c MIPS_SystemC you need SystemC 2.0.1
 * %and Qt version 2.x installed in your system.
 *
 * You must also define the environment variables \c QTDIR %and \c SYSTEMC. The 
 * correct value of these variables depend on the instalation of
 * Qt %and SystemC. As an example, \c QTDIR %and \c SYSTEMC may be initialised,
 * using the bash shell, by issuing the following commands:
 *
 *   <tt>export QTDIR=/usr/local/qt2</tt>
 *
 *   <tt>export SYSTEMC=/usr/local/systemc-2.0.1</tt>
 *
 * If those libraries are installed run \c make.
 *
 * \section run Running
 *
 *    To run \c MIPS_SystemC execute:
 *
 *    \c MIPS_SystemC
 *
 *    The initial contents of instruction memory %and data memory 
 *    can be changed by editing files \c instmem.hex %and \c datamem.dat, 
 *    respectively. These files are formatted as lists of hexadecimal
 *    numbers. (JLA:)
 * 
 */

/**
 * \c MIPS_SystemC \c sc_main, instantiates the \c mips module %and creates the
 * Qt application that manages the user interface.
 */
int sc_main(int argc, char *argv[])
{	
   sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);

   sc_signal <bool> clk;
   sc_signal <bool> reset;

   printf("\n\nMIPS Simulator using SystemC - v0.6.6\nAveiro University - 2014\n");

   // Create Qt application
   QApplication app(argc,argv);

   mips Mips1("MIPS");
   Mips1.clk(clk);
   Mips1.reset(reset);

   sc_initialize();

   // Create Control Widget
   MIPSctrl Appctrl(clk, reset, Mips1);

   // Reset
   Appctrl.reset();

   //Set Main Widget
   Appctrl.show();
   app.setMainWidget(&Appctrl);

   //Main Event Loop
   return app.exec();
}

