#ifdef WA
WA(1)
WA(21) WA(311) WA(312) WA(313)
WA(22) WA(321) WA(322) WA(323)
WA(23) WA(331) WA(332) WA(333)
#undef WA
#else

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
	WEIGHRESULT_EQUAL, WEIGHRESULT_LESS, WEIGHRESULT_GREATER,
	WEIGHRESULT_COUNT
} WEIGHRESULT;

typedef enum {
	// Weighings
	#define WA(x)	WA_##x,
	#include "Coins12.c"

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

typedef struct {
	COINS		left;
	COINS		right;
	WEIGHACTION	result[WEIGHRESULT_COUNT];
} WEIGHENTRY;

static const WEIGHENTRY weighTable[] = {
	//		left				right				EQUAL	LESS	GREATER
	//		A B C D E F G H I J K L		A B C D E F G H I J K L

	{/*WA_1*/	A|B|C|D|0|0|0|0|0|0|0|0,	0|0|0|0|E|F|G|H|0|0|0|0,	WA_21,	WA_22,	WA_23	},

	{/*WA_21*/	A|0|0|0|0|0|0|0|I|0|0|0,	0|0|0|0|0|0|0|0|0|J|K|0,	WA_311,	WA_312,	WA_313	},
	{/*WA_311*/	A|0|0|0|0|0|0|0|0|0|0|0,	0|0|0|0|0|0|0|0|0|0|0|L,	WA_X,	WA_LH,	WA_LL	},
	{/*WA_312*/	0|0|0|0|0|0|0|0|0|J|0|0,	0|0|0|0|0|0|0|0|0|0|K|0,	WA_IL,	WA_KH,	WA_JH	},
	{/*WA_313*/	0|0|0|0|0|0|0|0|0|J|0|0,	0|0|0|0|0|0|0|0|0|0|K|0,	WA_IH,	WA_JL,	WA_JL	},

	{/*WA_22*/	A|B|0|0|E|0|0|0|0|0|0|0,	0|0|C|0|0|F|0|0|0|0|0|L,	WA_321,	WA_322,	WA_323	},
	{/*WA_321*/	0|0|0|0|0|0|G|0|0|0|0|0,	0|0|0|0|0|0|0|H|0|0|0|0,	WA_DH,	WA_GL,	WA_HL	},
	{/*WA_322*/	0|0|C|0|0|0|0|0|0|0|0|0,	0|0|0|0|0|0|0|0|0|0|0|L,	WA_EL,	WA_X,	WA_CH	},
	{/*WA_323*/	A|0|0|0|0|0|0|0|0|0|0|0,	0|B|0|0|0|0|0|0|0|0|0|0,	WA_FL,	WA_BH,	WA_AH	},

	{/*WA_23*/	A|B|0|0|E|0|0|0|0|0|0|0,	0|0|C|0|0|F|0|0|0|0|0|L,	WA_331,	WA_332,	WA_333	},
	{/*WA_331*/	0|0|0|0|0|0|G|0|0|0|0|0,	0|0|0|0|0|0|0|H|0|0|0|0,	WA_DL,	WA_HH,	WA_GH	},
	{/*WA_332*/	A|0|0|0|0|0|0|0|0|0|0|0,	0|B|0|0|0|0|0|0|0|0|0|0,	WA_FH,	WA_AL,	WA_AH	},
	{/*WA_333*/	0|0|C|0|0|0|0|0|0|0|0|0,	0|0|0|0|0|0|0|0|0|0|0|L,	WA_EH,	WA_CL,	WA_X	},
};

// Weigh and return WEIGHRESULT_xxx
typedef WEIGHRESULT (*Weigh)(COINS left, COINS right)

WEIGHRESULT Solve(Weigh weigh)
{
	WEIGHACTION	wa = WA_1;
	wa = weighTable[wa].result[weigh(weighTable[wa].left, weighTable[wa].right)];
	wa = weighTable[wa].result[weigh(weighTable[wa].left, weighTable[wa].right)];
	return weigh(weighTable[wa].left, weighTable[wa].right);
}
#endif // WA
