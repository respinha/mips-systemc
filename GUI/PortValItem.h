
/***********************************************
** PortValItem.h
***********************************************/

/* PortValItem.h
 *
 * Canvas Item to Display Port Values
 */

#ifndef PORTVALITEM_H
#define PORTVALITEM_H

#include <q3canvas.h>
#include <systemc.h>

class PortValRead;

/**
 * Canvas Item to display a port value.
 */

class PortValItem: public Q3CanvasText
{
public:
    PortValItem(Q3Canvas *canvas, sc_port_base &bport,char *pname=0);
    virtual ~PortValItem(void);

    void updateVal(void);
private:
    PortValRead *pValRead;
};

#endif
