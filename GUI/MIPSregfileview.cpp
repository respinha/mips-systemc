//MIPSregfileview.cpp

#include "../regfile.h"
#include "MIPSregfileview.h"

MIPSregfileview::MIPSregfileview( regfile &m, QWidget* parent,  const char* name, Qt::WFlags fl )
    : MIPSmemview( m, parent, name, fl )
{   
    initList();

    Q3ListBoxItem *first=firstItem();
    if(first) {
       if(mem.size()>0 && mem.size()<80) {
          resize(first->width(this)+4,first->height(this)*mem.size()/4+4);
       }
       else resize(first->width(this)+30,first->height(this)*10+4);
       setMaximumSize(first->width(this)+30,first->height(this)*mem.size()/4+30);
    }
}

QString MIPSregfileview::MemItem(unsigned int i)
{
    unsigned int Val;
    QString Aux, ListStr;

    //regnum
    ListStr="$";
    Aux.setNum(i/4,10);
    ListStr+=Aux+":";
    ListStr=ListStr.rightJustify(4);

    //Data
    Val=mem.at(i);
    Aux.setNum((unsigned) Val,16);
    ListStr=ListStr+Aux.rightJustify(8);

    return ListStr;
}

