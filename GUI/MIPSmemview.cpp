//MIPSmemview.cpp

#include "../mem32.h"
#include "MIPSmemview.h"
//Added by qt3to4:
#include <QPixmap>

MIPSmemview::MIPSmemview( mem32 &m, QWidget* parent,  const char* name, Qt::WFlags fl )
    : Q3ListBox( parent, name, fl ), mem(m) 
{   
    setIcon(QPixmap("mips.xpm"));
}

/*  
 *  Destroys the object and frees any allocated resources
 */

void MIPSmemview::initList(void)
{
    unsigned int i;

    setFont(QFont("courier"));
    setSelectionMode(NoSelection);

    clear();

    for(i=0;i<mem.size();i+=4) {
        insertItem(MemItem(i));
    }
}

void MIPSmemview::updateList(void)
{
    unsigned int i;
    int top=topItem();

    for(i=0;i<mem.size();i+=4) {
        changeItem(MemItem(i),i/4);
    }
    setCurrentItem(current());
    setTopItem(top);
}

MIPSmemview::~MIPSmemview()
{
    // no need to delete child widgets, Qt does it all for us
}
