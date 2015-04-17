#ifndef COINS12_H
#define COINS12_H
// COINS as bit masks
#define	A 	(1 << 1)
#define	B	(1 << 2)
#define	C	(1 << 3)
#define	D	(1 << 4)
#define	E	(1 << 5)
#define	F	(1 << 6)
#define	G	(1 << 7)
#define	H	(1 << 8)
#define	I	(1 << 9)
#define	J	(1 << 10)
#define	K	(1 << 11)
#define	L	(1 << 12)
typedef unsigned int 	COINS;

typedef enum {
	// Weighings
	#define WA(a,l,r,eq,le,gr)	WA_##a,
	#include "wa.h"

	// Results H=heavy, L=light
	WA_X,	// impossible
	WA_AH, WA_AL,
	WA_BH, WA_BL,
	WA_CH, WA_CL,
	WA_DH, WA_DL,
	WA_EH, WA_EL,
	WA_FH, WA_FL,
	WA_GH, WA_GL,
	WA_HH, WA_HL,
	WA_IH, WA_IL,
	WA_JH, WA_JL,
	WA_KH, WA_KL,
	WA_LH, WA_LL,
} WEIGHACTION;

typedef enum {
	WEIGHRESULT_EQUAL, WEIGHRESULT_LESS, WEIGHRESULT_GREATER,
	WEIGHRESULT_COUNT
} WEIGHRESULT;

typedef struct {
	COINS		left;
	COINS		right;
	WEIGHACTION	result[WEIGHRESULT_COUNT];
} WEIGHENTRY;
// Weigh and return WEIGHRESULT_xxx
typedef WEIGHRESULT (*Weigh)(COINS left, COINS right);

extern WEIGHACTION Solve(Weigh weigh);
#endif