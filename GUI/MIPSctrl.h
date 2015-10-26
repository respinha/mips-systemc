// MIPSctrl.h

/**
 * \file MIPScrtl.h
 *
 * Interface of application main window.
 */

#ifndef MIPSCTRL_H
#define MIPSCTRL_H

#include <systemc.h>
#include <q3mainwindow.h>
#include <qworkspace.h>
#include <q3popupmenu.h>

struct mips;

class MIPSarch;
class MIPSmods;
class MIPSimemview;
class MIPSdmemview;
class MIPSregfileview;

/**
 * MIPSctrl is the main widget of MIPS_SystemC application.
 * It defines the menus, toolbar and the workspace where the other
 * widgets (architecture, modules, etc) are displayed as subwindows. 
 * 
 */

class MIPSctrl : public Q3MainWindow
{ 
    Q_OBJECT

public:
    MIPSctrl( sc_signal<bool> &clock, sc_signal<bool> &rset, mips &m, 
              QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    ~MIPSctrl();
protected:
    QWorkspace *mdi;
    Q3PopupMenu *windowsMenu;
public slots:

    // MIPS module control
    void readImem(void);
    void readDmem(void);
    void step(void);
    void reset(void);

    // GUI control
    void showImem(void);
    void showDmem(void);
    void showRegfile(void);

    void about(void);

    // Windows menu
    void windowsMenuAboutToShow();
    void windowsMenuActivated( int id );
private:

    // SystemC
    sc_signal <bool> &clk, &rst;
    mips &mips1;

    // subwindows
    MIPSarch *arch;
    MIPSmods *mods;
    MIPSimemview *imemview;
    MIPSdmemview *dmemview;
    MIPSregfileview *regfileview;
};

#endif // MIPSCTRL_H
