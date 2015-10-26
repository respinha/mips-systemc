// MIPSctrl.cpp
//
// application main window
//
// creates menus, toolbar and child windows
//

#include <qapplication.h>
#include <q3toolbar.h>
#include <q3popupmenu.h>
#include <q3action.h>
#include <qmenubar.h>
#include <qmessagebox.h>
#include <q3filedialog.h>
//Added by qt3to4:
#include <QPixmap>

#include "../mips.h"

#include "MIPSmods.h"
#include "MIPSarch.h"
#include "MIPSimemview.h"
#include "MIPSdmemview.h"
#include "MIPSregfileview.h"

#include "MIPSctrl.h"

#include "readimem.xpm"
#include "readdmem.xpm"
#include "cycle.xpm"
#include "reset.xpm"
#include "instmem.xpm"
#include "datamem.xpm"
#include "regs.xpm"

/** 
 * MIPSctrl contructor.
 */
MIPSctrl::MIPSctrl( sc_signal<bool> &clock, sc_signal<bool> &rset, mips &m, QWidget* parent,  const char* name, Qt::WFlags fl )
    : Q3MainWindow( parent, name, fl ), clk(clock), rst(rset), mips1(m)
{
	setCaption("MIPS_SystemC");

	mdi = new QWorkspace( this, "workspace" );
	mdi->setBackgroundMode( Qt::PaletteDark );
	mdi->resize(900,400);

        //// Main menus
	//file
	Q3PopupMenu *fileMenu = new Q3PopupMenu( this );
	menuBar()->insertItem( "&File", fileMenu );

	//file
	Q3PopupMenu *viewMenu = new Q3PopupMenu( this );
	menuBar()->insertItem( "&View", viewMenu );

        //windows 
        windowsMenu = new Q3PopupMenu( this );
        windowsMenu->setCheckable( TRUE );
        connect( windowsMenu, SIGNAL( aboutToShow() ),
    	         this, SLOT( windowsMenuAboutToShow() ) );
        menuBar()->insertItem( "&Windows", windowsMenu );

	menuBar()->insertSeparator();

        //help
	Q3PopupMenu *helpMenu = new Q3PopupMenu( this );
	helpMenu->insertItem("&About", this, SLOT(about()), Qt::Key_F1);
	menuBar()->insertItem( "&Help", helpMenu );

        //// Toolbar
	Q3ToolBar *MipsToolBar = new Q3ToolBar( this );
	addToolBar( MipsToolBar, "MIPSctrl" );


        //// Subwindows
	//architecture
        MIPSarch *arch = new MIPSarch(mips1, mdi);
	arch->setCaption( "Arch");

        connect(arch,SIGNAL(imemClicked()), SLOT(showImem()));
        connect(arch,SIGNAL(dmemClicked()), SLOT(showDmem()));
        connect(arch,SIGNAL(regfileClicked()), SLOT(showRegfile()));

	mdi->addWindow(arch);

	//module ports
        mods = new MIPSmods(mips1, mdi);
	mods->setCaption( "Modules");

	mdi->addWindow(mods);

        //instruction memory
        imemview = new MIPSimemview(*mips1.instmem, 
			            mips1.instmem->addr,
			            mips1.reg_if_id->PC_id,
			            mips1.reg_if_id->valid_id,
			            mips1.reg_id_exe->PC_exe,
			            mips1.reg_id_exe->valid_exe,
			            mips1.reg_exe_mem->PC_mem,
			            mips1.reg_exe_mem->valid_mem,
			            mips1.reg_mem_wb->PC_wb,
			            mips1.reg_mem_wb->valid_wb,
				    mdi);
	imemview->setCaption( "InstMem" );

	mdi->addWindow(imemview);
	imemview->hide();


        //data memory
        dmemview = new MIPSdmemview(*mips1.datamem, mdi);
	dmemview->setCaption( "DataMem" );

	mdi->addWindow(dmemview);
	dmemview->hide();

        //registers 
        regfileview = new MIPSregfileview(*mips1.rfile, mdi);
	regfileview->setCaption( "RegisterFile" );

	mdi->addWindow(regfileview);
	regfileview->hide();

	mdi->setActiveWindow(arch);

        //// Actions
	Q3Action *action = 0;

	//read instruction memory
	QPixmap Icon= QPixmap(readimem_xpm);
	QIcon IconSet = QIcon(Icon);
	action = new Q3Action( "Read Imem", IconSet, "Read &Inst. Mem.", Qt::Key_F2, this );
	connect( action, SIGNAL( activated() ), SLOT( readImem() ) );
	action->addTo( fileMenu );
	action->addTo( MipsToolBar );

	connect(action,SIGNAL(activated()),mods,SIGNAL(updateModules()));
	connect(action,SIGNAL(activated()),arch,SLOT(updateArch()));
	connect(action,SIGNAL(activated()),imemview,SLOT(initList()));
	connect(action,SIGNAL(activated()),imemview,SLOT(updateList()));
	connect(action,SIGNAL(activated()),regfileview,SLOT(updateList()));

	//read data memory
	Icon= QPixmap(readdmem_xpm);
	IconSet = QIcon(Icon);
	action = new Q3Action( "Read Dmem", IconSet, "Read &Data Mem.", Qt::Key_F3, this );
	connect( action, SIGNAL( activated() ), SLOT( readDmem() ) );
	action->addTo( fileMenu );
	action->addTo( MipsToolBar );

	connect(action,SIGNAL(activated()),mods,SIGNAL(updateModules()));
	connect(action,SIGNAL(activated()),arch,SLOT(updateArch()));
	connect(action,SIGNAL(activated()),dmemview,SLOT(initList()));
	connect(action,SIGNAL(activated()),dmemview,SLOT(updateList()));
	connect(action,SIGNAL(activated()),regfileview,SLOT(updateList()));

	//cycle
	Icon= QPixmap(cycle_xpm);
	IconSet = QIcon(Icon);
	action = new Q3Action( "Cycle", IconSet, "&Cycle", Qt::Key_F10, this );
	connect( action, SIGNAL( activated() ), SLOT( step() ) );
	action->addTo( fileMenu );
	action->addTo( MipsToolBar );

	connect(action,SIGNAL(activated()),mods,SIGNAL(updateModules()));
	connect(action,SIGNAL(activated()),arch,SLOT(updateArch()));
	connect(action,SIGNAL(activated()),imemview,SLOT(updateList()));
	connect(action,SIGNAL(activated()),dmemview,SLOT(updateList()));
	connect(action,SIGNAL(activated()),regfileview,SLOT(updateList()));

        //reset
	Icon= QPixmap(reset_xpm);
	IconSet = QIcon(Icon);
	action = new Q3Action( "Reset", IconSet, "&Reset", Qt::Key_F2, this );
	connect( action, SIGNAL( activated() ), SLOT( reset() ) );
	action->addTo( fileMenu );
	action->addTo( MipsToolBar );

	connect(action,SIGNAL(activated()),mods,SIGNAL(updateModules()));
	connect(action,SIGNAL(activated()),arch,SLOT(updateArch()));
	connect(action,SIGNAL(activated()),imemview,SLOT(updateList()));
	connect(action,SIGNAL(activated()),regfileview,SLOT(updateList()));

	//view Imem
	Icon= QPixmap(instmem_xpm);
	IconSet = QIcon(Icon);
	action = new Q3Action( "View Instr. Memory", IconSet, "&Instr. Memory", Qt::Key_F6, this );
	connect( action, SIGNAL( activated() ), SLOT( showImem() ) );
	action->addTo( viewMenu );
	action->addTo( MipsToolBar );

	//view Dmem
	Icon= QPixmap(datamem_xpm);
	IconSet = QIcon(Icon);
	action = new Q3Action( "View Data Memory", IconSet, "&Data Memory", Qt::Key_F7, this );
	connect( action, SIGNAL( activated() ), SLOT( showDmem() ) );
	action->addTo( viewMenu );
	action->addTo( MipsToolBar );

	//view Registers
	Icon= QPixmap(regs_xpm);
	IconSet = QIcon(Icon);
	action = new Q3Action( "View Registers", IconSet, "&Registers", Qt::Key_F8, this );
	connect( action, SIGNAL( activated() ), SLOT( showRegfile() ) );
	action->addTo( viewMenu );
	action->addTo( MipsToolBar );


        //exit
	action = new Q3Action( "Exit", "E&xit", 0, this );
	fileMenu->insertSeparator();
	action->addTo( fileMenu );
	connect( action, SIGNAL( activated() ), qApp, SLOT( closeAllWindows() ) );

	setCentralWidget( mdi );

	resize(900,500);
}

/*  
 *  Destroys the object and frees any allocated resources
 */
MIPSctrl::~MIPSctrl()
{
    // no need to delete child widgets, Qt does it all for us
}

/**
 * Read Instruction Memory contents from file
 */
void MIPSctrl::readImem()
{
	QString filename = Q3FileDialog::getOpenFileName(".","Program Files (*.hex);;All files (*)",this,
			                                "Open file dialog","Choose INSTRUCTION Memory contents");

	if(!filename.isEmpty()) {
	    mips1.instmem->init_memory(filename.latin1());
	    mips1.instmem->entry();
	    reset();
	}
}

/**
 * Read Data Memory contents from file
 */
void MIPSctrl::readDmem()
{
	QString filename = Q3FileDialog::getOpenFileName(".","Data Files (*.dat);;All files (*)",this,
			                                "Open file dialog","Choose DATA Memory contents");
	if(!filename.isEmpty()) {
	    mips1.datamem->init_memory(filename.latin1());
	    mips1.datamem->read_mem();
	    reset();
	}
}

/**
 * one clock cycle.
 */
void MIPSctrl::step()
{
    clk.write(0);
    sc_cycle(1);

    clk.write(1);
    sc_cycle(1);
}

/**
 * assert reset signal and step one clock cycle.
 */
void MIPSctrl::reset()
{
    rst.write(1);
    clk.write(0);
    sc_cycle(1);

    clk.write(1);
    sc_cycle(1);

    rst.write(0);
}

/**
 * shows intruction memory window.
 */
void MIPSctrl::showImem()
{
    if(!imemview->isVisible())
         imemview->show();
    imemview->setFocus();
}

/**
 * shows data memory window.
 */
void MIPSctrl::showDmem()
{
    if(!dmemview->isVisible())
         dmemview->show();
    dmemview->setFocus();
}

/**
 * shows registers window.
 */
void MIPSctrl::showRegfile()
{
    if(!regfileview->isVisible())
        regfileview->show();
    regfileview->setFocus();
}

void MIPSctrl::windowsMenuAboutToShow()
{
    windowsMenu->clear();
    int cascadeId = windowsMenu->insertItem("&Cascade", mdi, SLOT(cascade() ) );
    int tileId = windowsMenu->insertItem("&Tile", mdi, SLOT(tile() ) );
    if ( mdi->windowList().isEmpty() ) {
	windowsMenu->setItemEnabled( cascadeId, FALSE );
	windowsMenu->setItemEnabled( tileId, FALSE );
    }
    windowsMenu->insertSeparator();
    QWidgetList windows = mdi->windowList();
    for ( int i = 0; i < int(windows.count()); ++i ) {
	int id = windowsMenu->insertItem(windows.at(i)->caption(),
					 this, SLOT( windowsMenuActivated( int ) ) );
	windowsMenu->setItemParameter( id, i );
	windowsMenu->setItemChecked( id, mdi->activeWindow() == windows.at(i) );
    }
}

void MIPSctrl::windowsMenuActivated( int id )
{
    QWidget* w = mdi->windowList().at( id );
    if ( w ) {
	if(!w->isVisible()) w->show();
	w->setFocus();
    }
}

void MIPSctrl::about(void)
{
    QMessageBox::about(this,"About MIPS_SystemC",
         "<b>MIPS_SystemC v0.6.6</b><br>"
	 "Copyright 2014<br>"
	 "Nuno Lau<br>"
	 "Universidade de Aveiro<br>"
	 "nunolau@ua.pt"
	 );

}
