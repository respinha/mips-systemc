#include "control_jbr.h"

/* jbr output: sets if the operation is a jump or a branch (3 bits):
  *   0: None
  *   1: beq
  *   2: bne
  *   3: bgtz
  *   4: blez
  *   5: j
  *   6: jr
*/

void control_jbr::entry() {
	switch(jbr.read()) {
		case 0: // none
			select.write(0);
			btaken.write(0);
			break;

		case 1: // beq
			select.write(2 * eq.read());
			btaken.write(eq.read());
			break;

		case 2: // bne
			select.write(2 * !eq.read());
			btaken.write(!eq.read());
			break;

		case 3: // bgtz
			select.write(2 * gr.read());
			btaken.write(gr.read());
			break;

		case 4: // blez
			select.write(2 * le.read());
			btaken.write(le.read());
			break;

		case 5: // j
			select.write(3);
			btaken.write(1);
			break;
		case 6: // jr
			select.write(1);
			btaken.write(1);
			break;

	}
}