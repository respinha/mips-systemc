#ifndef MIPSMEMVIEW_H
#define MIPSMEMVIEW_H

#include <systemc.h>
#include <q3listbox.h>

class mem32;

/**
 * Base class for the visualization of memory elements contents.
 */

class MIPSmemview : public Q3ListBox
{ 
    Q_OBJECT

public:
    MIPSmemview( mem32 &m, QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    virtual ~MIPSmemview();
public slots:
    virtual void updateList(void);
    virtual void initList(void);

protected:
    virtual QString MemItem(unsigned int i)=0;
    virtual unsigned int current(void){ return 0; };

    mem32 &mem;
};

#endif // MIPSMEMVIEW_H
