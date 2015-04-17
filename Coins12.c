static const WEIGHENTRY weighTable[] = {
	#define WA(a,l,r,eq,le,gr)	{ l, r, { eq, le, gr } },
	#include "wa.h"
};

WEIGHACTION Solve(Weigh weigh)
{
	WEIGHACTION	wa = WA_1;
	wa = weighTable[wa].result[ weigh( weighTable[wa].left, weighTable[wa].right ) ];
	wa = weighTable[wa].result[ weigh( weighTable[wa].left, weighTable[wa].right ) ];
	return weighTable[wa].result [ weigh( weighTable[wa].left, weighTable[wa].right ) ] ;
}

