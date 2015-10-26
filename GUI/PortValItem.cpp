
/***********************************************
** PortValItem.cpp
***********************************************/

/* PortValItem.cpp
 */

#include "PortValRead.h"

#include "PortValItem.h"


PortValItem::PortValItem(Q3Canvas *canvas, sc_port_base &bport, char *pname) 
     : Q3CanvasText(canvas)
{
    pValRead=new PortValRead(bport,pname);
    setTextFlags(Qt::AlignTop | Qt::AlignLeft);
    setVisible(true);
}

PortValItem::~PortValItem(void)
{
    delete pValRead;
}

void PortValItem::updateVal(void)
{
    QString HexVal;

    HexVal.setNum(pValRead->read(),16);
    
    setText(HexVal);
}
