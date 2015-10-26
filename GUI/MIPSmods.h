#ifndef MIPSMODS_H
#define MIPSMODS_H

#include <q3scrollview.h>
//Added by qt3to4:
#include <QCloseEvent>

struct mips;

/**
 * Displays the main modules port values in the form of a table.
 * Displays instruction memory, decode, control, register file, 
 * alu and data memory port values.
 */

class MIPSmods : public Q3ScrollView
{ 
    Q_OBJECT

public:
    MIPSmods( mips &m, QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    ~MIPSmods();
signals:
    void updateModules(void);
protected:
    virtual void closeEvent(QCloseEvent *e);
private:
    mips &mips1;
};

#endif // MIPSMODS_H
