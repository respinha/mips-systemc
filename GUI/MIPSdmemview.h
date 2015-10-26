#ifndef MIPSDMEMVIEW_H
#define MIPSDMEMVIEW_H

#include <q3listbox.h>

#include "MIPSmemview.h"

class dmem;

/**
 * Visualization of data memory contents.
 */

class MIPSdmemview : public MIPSmemview
{ 
    Q_OBJECT

public:
    MIPSdmemview( dmem &m, QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
public slots:
    virtual void initList(void);
protected:
    virtual QString MemItem(unsigned int i);
};

#endif // MIPSDMEMVIEW_H
