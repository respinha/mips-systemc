
/***********************************************
** PortValRead.cpp
***********************************************/

#include "PortValRead.h"


PortValRead::PortValRead(sc_port_base &bport, char *pname) 
{
    port=&bport;
    Name=pname;
}

/*
 * returns the value of a port if it is of type sc_uint
 */
unsigned PortValRead::read(void)
{
    if(dynamic_cast<sc_in <sc_uint<32> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<32> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<32> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<32> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<31> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<31> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<31> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<31> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<30> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<30> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<30> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<30> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<29> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<29> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<29> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<29> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<28> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<28> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<28> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<28> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<27> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<27> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<27> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<27> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<26> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<26> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<26> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<26> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<25> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<25> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<25> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<25> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<24> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<24> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<24> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<24> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<23> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<23> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<23> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<23> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<22> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<22> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<22> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<22> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<21> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<21> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<21> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<21> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<20> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<20> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<20> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<20> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<19> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<19> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<19> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<19> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<18> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<18> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<18> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<18> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<17> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<17> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<17> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<17> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<16> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<16> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<16> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<16> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<15> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<15> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<15> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<15> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<14> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<14> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<14> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<14> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<13> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<13> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<13> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<13> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<12> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<12> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<12> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<12> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<11> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<11> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<11> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<11> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<10> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<10> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<10> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<10> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<9> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<9> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<9> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<9> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<8> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<8> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<8> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<8> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<7> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<7> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<7> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<7> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<6> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<6> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<6> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<6> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<5> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<5> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<5> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<5> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<4> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<4> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<4> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<4> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<3> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<3> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<3> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<3> > *>(port)->read());

    if(dynamic_cast<sc_in <sc_uint<2> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in <sc_uint<2> > *>(port)->read());
    if(dynamic_cast<sc_out <sc_uint<2> > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out <sc_uint<2> > *>(port)->read());

    if(dynamic_cast<sc_in < bool > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_in < bool > *>(port)->read());
    if(dynamic_cast<sc_out < bool > *>(port)!=0)
        return (unsigned)(dynamic_cast<sc_out < bool > *>(port)->read());

    fprintf(stderr,"ERROR: reading unsupported port type\n");
    exit(0);

    return 0;
}

char const *PortValRead::name(void)
{
    return Name.c_str();
}
