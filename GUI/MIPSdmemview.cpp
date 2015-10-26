//MIPSdmemview.cpp

#include "../dmem.h"

#include "MIPSdmemview.h"

MIPSdmemview::MIPSdmemview( dmem &m, QWidget* parent,  const char* name, Qt::WFlags fl )
    : MIPSmemview( m, parent, name, fl )
{   
    initList();
}

QString MIPSdmemview::MemItem(unsigned int i)
{
    unsigned int Val;
    QString HexVal, ListStr;

    //address
    HexVal.setNum(i,16);
    ListStr+=HexVal.rightJustify(4)+":";

    //Data
    Val=mem.at(i);
    HexVal.setNum((unsigned) Val,16);
    ListStr=ListStr+HexVal.rightJustify(8);

    return ListStr;
}

/**  
 *  Inserts one MemItem in ListBox for each word in memory.
 *  Determines maximum sizes of widget.
 */
void MIPSdmemview::initList()
{
    MIPSmemview::initList();

    // resize and setMaximumSize
    Q3ListBoxItem *first=firstItem();
    if(first) {
       if(mem.size()>0 && mem.size()<80) {
          resize(first->width(this)+20,first->height(this)*mem.size()/4+4);
       }
       else resize(first->width(this)+20,100);
       setMaximumSize(first->width(this)+20,first->height(this)*mem.size()/4+4);
    }
}

