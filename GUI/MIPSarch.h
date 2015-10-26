//MIPSarch.h

/**
 * \file MIPSarch.h
 *
 * Interface of widget that displays architecture.
 */

#ifndef MIPSARCH_H
#define MIPSARCH_H

#include <vector>
#include <q3canvas.h>
//Added by qt3to4:
#include <QMouseEvent>
#include <QCloseEvent>

using std::vector;

struct mips;

class QCloseEvent;
class QCursor;

class PortValItem;
class PortValRead;


/**
 * MIPSarchCanvas is the Canvas that includes the MIPS architecture and is
 * viewed in MIPSarch Widget.
 */

class MIPSarchCanvas: public Q3Canvas
{
public:
    MIPSarchCanvas(mips &m, QObject *parent);
    virtual ~MIPSarchCanvas(void);
    void updateArch(void);
private:
    mips &mips1;
    vector < PortValItem * > portValVec;
    vector < Q3CanvasText * > instStage;
    vector < PortValRead * > pcStage;
    vector < PortValRead * > validpcStage;
};

/**
 * MIPSarch is the Widget that displays the MIPS architecture.
 * MIPSarch is the Canvas View where the MIPSarchCanvas is displayed.
 * MIPSarch manages the user interface with the architecture visualization.
 */

class MIPSarch : public Q3CanvasView
{ 
    Q_OBJECT

public:
    MIPSarch( mips &m, QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    virtual ~MIPSarch();

public slots:
    void updateArch(void);
signals: 
    void imemClicked(void);
    void dmemClicked(void);
    void regfileClicked(void);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void contentsMousePressEvent(QMouseEvent *e);
    virtual void contentsMouseMoveEvent(QMouseEvent *e);
private:
    MIPSarchCanvas *archCanvas;
    QCursor *cursor;
};

#endif // MIPSARCH_H
