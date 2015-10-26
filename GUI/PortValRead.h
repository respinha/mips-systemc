
/***********************************************
** PortValRead.h
***********************************************/

/* PortValRead.h
 *
 * Allows access to port integer values
 */

#ifndef PORTVALREAD_H
#define PORTVALREAD_H

#include <string>
#include <systemc.h>

using std::string;

/**
 * Gives access to port values.
 */

class PortValRead
{
public:
    PortValRead(sc_port_base &bport, char *pname=0);
    unsigned int read(void);
    char const *name(void);
private:
    sc_port_base *port;
    string Name;
};

#endif
