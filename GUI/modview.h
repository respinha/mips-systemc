
/***********************************************
** modview.h
***********************************************/

/** 
 * \file modview.h
 *
 * Interface of Widget that displays a module.
 */

#ifndef MODVIEW_H
#define MODVIEW_H

#include <vector>
#include <q3canvas.h>
#include <systemc.h>

using std::vector;

class PortValItem;

/**
 * Canvas to be displayed by ModView Widget.
 */

class ModCanvas: public Q3Canvas
{
public:
    ModCanvas(char *name=0, QObject *parent=0);
    virtual ~ModCanvas(void);
    void redrawModule(void);

    void addPort(sc_port_base &newport, char *name=0);
private:
    vector<PortValItem *> portValVec;

    int unit, canvas_sizex, canvas_sizey;
};

/**
 * Widget that displays module port values in the form of a table.
 */

class ModView: public Q3CanvasView
{
  Q_OBJECT
public:
    ModView(char *name=0, QWidget *parent=0);
    void addPort(sc_port_base &newport, char *name=0);
public slots:
    void redrawModule(void);
private:
    ModCanvas *modCanvas;
};

#endif
