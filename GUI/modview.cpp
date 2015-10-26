
/***********************************************
** modview.cpp
***********************************************/

/* modview.cpp
 *
 * Widget that displays module
 */

#include <math.h>

#include "PortValItem.h"
#include "modview.h"

/**
 * ModCanvas contructor.
 */
ModCanvas::ModCanvas(char *name, QObject *parent) : Q3Canvas(parent)
{
        canvas_sizex=150;
        canvas_sizey=20;

        resize(canvas_sizex,canvas_sizey);
        setBackgroundColor(QColor("White"));

        Q3CanvasText *nameLabel=new Q3CanvasText(name,this);
	nameLabel->setTextFlags(Qt::AlignHCenter);
	nameLabel->move(canvas_sizex/2,1);
	nameLabel->setVisible(true);

	setDoubleBuffering(true);
}

void ModCanvas::redrawModule(void)
{
    unsigned int p;
    for(p=0; p<portValVec.size(); p++) {
         portValVec[p]->updateVal();
    }
    update();
}

void ModCanvas::addPort(sc_port_base &newport, char *name)
{
    Q3CanvasText *portLabel=new Q3CanvasText(name,this);
    portLabel->move(5,3+14*(portValVec.size()+1));
    portLabel->setVisible(true);

    PortValItem *portVal=new PortValItem(this,newport,name);
    portVal->move(5+canvas_sizex/2,3+14*(portValVec.size()+1));

    portValVec.push_back(portVal);

    canvas_sizey+=14;
    resize(canvas_sizex,canvas_sizey);

    redrawModule();
}

ModCanvas::~ModCanvas(void)
{
    Q3CanvasItemList list=allItems();
    Q3CanvasItemList::Iterator it = list.begin();
    for (; it != list.end(); ++it) {
            if ( *it )
                delete *it;
    }
}

/**
 * Modview contructor.
 */
ModView::ModView(char *name, QWidget *parent) : Q3CanvasView(0,parent)
{
     modCanvas=new ModCanvas(name,this);
     setCanvas(modCanvas);
     resize(sizeHint());
     setMaximumSize(sizeHint());
     setMinimumSize(sizeHint());
}

void ModView::redrawModule(void)
{
     modCanvas->redrawModule();
}

void ModView::addPort(sc_port_base &newport,char *name)
{
     modCanvas->addPort(newport,name);
     resize(sizeHint());
     setMaximumSize(sizeHint());
     setMinimumSize(sizeHint());
}
