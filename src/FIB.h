// FIB.h
// Define in-memory data structures for reading MS USHORT's .DOC File Information Block
// Adapted from https://msdn.microsoft.com/en-us/library/office/dd952676(v=office.14).aspx

#ifndef FIB_H_INCLUDED
#define FIB_H_INCLUDED

#include <fstream>
#include <iostream>
#include "dtypes.h"

#define _SET_BITS_1 0
#define _SET_BITS_3 0
#define _SET_BITS_4 0

#define ERR_LCBSTSHF_W97 0x3

#pragma pack(push, 1)
struct Fib
{
	struct FibBase
	{
		USHORT wIdent;
		USHORT nFib;
		USHORT unused;
		USHORT lid;
		USHORT pnNext;
		BYTE fDot : 1;
		BYTE fGlsy : 1;
		BYTE fComplex : 1;
		BYTE fHasPic : 1;
		BYTE cQuickSaves : 4;
		BYTE fEncrypted : 1;
		BYTE fWhichTblStm : 1;
		BYTE fReadOnlyRecommended : 1;
		BYTE fWriteReservation : 1;
		BYTE fExtChar : 1;
		BYTE fLoadOverride : 1;
		BYTE fFarEast : 1;
		BYTE fObfuscated : 1;
		USHORT nFibBack;
		ULONG lkey;
		BYTE envr;
		BYTE fMac : 1;
		BYTE fEmptySpecial : 1;
		BYTE fLoadOverridePage : 1;
		BYTE reserved1 : 1;
		BYTE reserved2 : 1;
		BYTE fSpare0 : 3;
		USHORT reserved3;
		USHORT reserved4;
		ULONG reserved5;
		ULONG reserved6;

		FibBase();
		~FibBase();

		VOID readFibBase(std::ifstream&);

		VOID process_fibBase();
	} base; // struct FibBase;
	USHORT csw;
	struct FibRgW97
	{
		USHORT reserved1;
		USHORT reserved2;
		USHORT reserved3;
		USHORT reserved4;
		USHORT reserved5;
		USHORT reserved6;
		USHORT reserved7;
		USHORT reserved8;
		USHORT reserved9;
		USHORT reserved10;
		USHORT reserved11;
		USHORT reserved12;
		USHORT reserved13;
		USHORT lidFE;    // review processsing of this member

		FibRgW97();
		~FibRgW97();

		VOID readFibRgW(std::ifstream &);

	} fibRgW; // struct FibRgW97	
	USHORT cslw;
	struct FibRgLw97
	{
		ULONG cbMac;
		ULONG reserved1;
		ULONG reserved2;
		LONG ccpText;
		LONG ccpFtn;
		LONG ccpHdd;
		ULONG reserved3;
		LONG ccpAtn;
		LONG ccpEdn;
		LONG ccpTxbx;
		LONG ccpHdrTxbx;
		ULONG reserved4;
		ULONG reserved5;
		ULONG reserved6;
		ULONG reserved7;
		ULONG reserved8;
		ULONG reserved9;
		ULONG reserved10;
		ULONG reserved11;
		ULONG reserved12;
		ULONG reserved13;
		ULONG reserved14;

		FibRgLw97();
		~FibRgLw97();

		VOID readFibRgLw(std::ifstream&);
		VOID process_fibRgLw();

	} fibRgLw; // struct FibRgLw97
	USHORT cbRgFcLcb;
	union FibRgFcLcb
	{
		struct FibRgFcLcb97
		{
			ULONG fcStshfOrig;
			ULONG lcbStshfOrig;
			ULONG fcStshf;
			ULONG lcbStshf;
			ULONG fcPlcffndRef;
			ULONG lcbPlcffndRef;
			ULONG fcPlcffndTxt;
			ULONG lcbPlcffndTxt;
			ULONG fcPlcfandRef;
			ULONG lcbPlcfandRef;
			ULONG fcPlcfandTxt;
			ULONG lcbPlcfandTxt;
			ULONG fcPlcfSed;
			ULONG lcbPlcfSed;
			ULONG fcPlcPad;
			ULONG lcbPlcPad;
			ULONG fcPlcfPhe;
			ULONG lcbPlcfPhe;
			ULONG fcSttbfGlsy;
			ULONG lcbSttbfGlsy;
			ULONG fcPlcfGlsy;
			ULONG lcbPlcfGlsy;
			ULONG fcPlcfHdd;
			ULONG lcbPlcfHdd;
			ULONG fcPlcfBteChpx;
			ULONG lcbPlcfBteChpx;
			ULONG fcPlcfBtePapx;
			ULONG lcbPlcfBtePapx;
			ULONG fcPlcfSea;
			ULONG lcbPlcfSea;
			ULONG fcSttbfFfn;
			ULONG lcbSttbfFfn;
			ULONG fcPlcfFldMom;					// refers to offset for PlcFld
			ULONG lcbPlcfFldMom;
			ULONG fcPlcfFldHdr;
			ULONG lcbPlcfFldHdr;
			ULONG fcPlcfFldFtn;
			ULONG lcbPlcfFldFtn;
			ULONG fcPlcfFldAtn;
			ULONG lcbPlcfFldAtn;
			ULONG fcPlcfFldMcr;
			ULONG lcbPlcfFldMcr;
			ULONG fcSttbfBkmk;
			ULONG lcbSttbfBkmk;
			ULONG fcPlcfBkf;
			ULONG lcbPlcfBkf;
			ULONG fcPlcfBkl;
			ULONG lcbPlcfBkl;
			ULONG fcCmds;
			ULONG lcbCmds;
			ULONG fcUnused1;
			ULONG lcbUnused1;
			ULONG fcSttbfMcr;
			ULONG lcbSttbfMcr;
			ULONG fcPrDrvr;
			ULONG lcbPrDrvr;
			ULONG fcPrEnvPort;
			ULONG lcbPrEnvPort;
			ULONG fcPrEnvLand;
			ULONG lcbPrEnvLand;
			ULONG fcWss;
			ULONG lcbWss;
			ULONG fcDop;
			ULONG lcbDop;
			ULONG fcSttbfAssoc;
			ULONG lcbSttbfAssoc;
			ULONG fcClx;
			ULONG lcbClx;
			ULONG fcPlcfPgdFtn;
			ULONG lcbPlcfPgdFtn;
			ULONG fcAutosaveSource;
			ULONG lcbAutosaveSource;
			ULONG fcGrpXstAtnOwners;
			ULONG lcbGrpXstAtnOwners;
			ULONG fcSttbfAtnBkmk;
			ULONG lcbSttbfAtnBkmk;
			ULONG fcUnused2;
			ULONG lcbUnused2;
			ULONG fcUnused3;
			ULONG lcbUnused3;
			ULONG fcPlcSpaMom;
			ULONG lcbPlcSpaMom;
			ULONG fcPlcSpaHdr;
			ULONG lcbPlcSpaHdr;
			ULONG fcPlcfAtnBkf;
			ULONG lcbPlcfAtnBkf;
			ULONG fcPlcfAtnBkl;
			ULONG lcbPlcfAtnBkl;
			ULONG fcPms;
			ULONG lcbPms;
			ULONG fcFormFldSttbs;
			ULONG lcbFormFldSttbs;
			ULONG fcPlcfendRef;
			ULONG lcbPlcfendRef;
			ULONG fcPlcfendTxt;
			ULONG lcbPlcfendTxt;
			ULONG fcPlcfFldEdn;
			ULONG lcbPlcfFldEdn;
			ULONG fcUnused4;
			ULONG lcbUnused4;
			ULONG fcDggInfo;
			ULONG lcbDggInfo;
			ULONG fcSttbfRMark;
			ULONG lcbSttbfRMark;
			ULONG fcSttbfCaption;
			ULONG lcbSttbfCaption;
			ULONG fcSttbfAutoCaption;
			ULONG lcbSttbfAutoCaption;
			ULONG fcPlcfWkb;
			ULONG lcbPlcfWkb;
			ULONG fcPlcfSpl;
			ULONG lcbPlcfSpl;
			ULONG fcPlcftxbxTxt;
			ULONG lcbPlcftxbxTxt;
			ULONG fcPlcfFldTxbx;
			ULONG lcbPlcfFldTxbx;
			ULONG fcPlcfHdrtxbxTxt;
			ULONG lcbPlcfHdrtxbxTxt;
			ULONG fcPlcffldHdrTxbx;
			ULONG lcbPlcffldHdrTxbx;
			ULONG fcStwUser;
			ULONG lcbStwUser;
			ULONG fcSttbTtmbd;
			ULONG lcbSttbTtmbd;
			ULONG fcCookieData;
			ULONG lcbCookieData;
			ULONG fcPgdMotherOldOld;
			ULONG lcbPgdMotherOldOld;
			ULONG fcBkdMotherOldOld;
			ULONG lcbBkdMotherOldOld;
			ULONG fcPgdFtnOldOld;
			ULONG lcbPgdFtnOldOld;
			ULONG fcBkdFtnOldOld;
			ULONG lcbBkdFtnOldOld;
			ULONG fcPgdEdnOldOld;
			ULONG lcbPgdEdnOldOld;
			ULONG fcBkdEdnOldOld;
			ULONG lcbBkdEdnOldOld;
			ULONG fcSttbfIntlFld;
			ULONG lcbSttbfIntlFld;
			ULONG fcRouteSlip;
			ULONG lcbRouteSlip;
			ULONG fcSttbSavedBy;
			ULONG lcbSttbSavedBy;
			ULONG fcSttbFnm;
			ULONG lcbSttbFnm;
			ULONG fcPlfLst;
			ULONG lcbPlfLst;
			ULONG fcPlfLfo;
			ULONG lcbPlfLfo;
			ULONG fcPlcfTxbxBkd;
			ULONG lcbPlcfTxbxBkd;
			ULONG fcPlcfTxbxHdrBkd;
			ULONG lcbPlcfTxbxHdrBkd;
			ULONG fcDocUndoUSHORT9;
			ULONG lcbDocUndoUSHORT9;
			ULONG fcRgbUse;
			ULONG lcbRgbUse;
			ULONG fcUsp;
			ULONG lcbUsp;
			ULONG fcUskf;
			ULONG lcbUskf;
			ULONG fcPlcupcRgbUse;
			ULONG lcbPlcupcRgbUse;
			ULONG fcPlcupcUsp;
			ULONG lcbPlcupcUsp;
			ULONG fcSttbGlsyStyle;
			ULONG lcbSttbGlsyStyle;
			ULONG fcPlgosl;
			ULONG lcbPlgosl;
			ULONG fcPlcocx;
			ULONG lcbPlcocx;
			ULONG fcPlcfBteLvc;
			ULONG lcbPlcfBteLvc;
			ULONG dwLowDateTime;
			ULONG dwHighDateTime;
			ULONG fcPlcfLvcPre10;
			ULONG lcbPlcfLvcPre10;
			ULONG fcPlcfAsumy;
			ULONG lcbPlcfAsumy;
			ULONG fcPlcfGram;
			ULONG lcbPlcfGram;
			ULONG fcSttbListNames;
			ULONG lcbSttbListNames;
			ULONG fcSttbfUssr;
			ULONG lcbSttbfUssr;

			FibRgFcLcb97();
			~FibRgFcLcb97();

			VOID readFibRgFcLcb97(std::ifstream &);
			VOID process_FibRgFcLcb97();
		} fibRgFcLcb97;          // struct FibRgFcLcb97
		struct FibRgFcLcb2000
		{
			FibRgFcLcb97 rgFcLcb97;
			ULONG fcPlcfTch;
			ULONG lcbPlcfTch;
			ULONG fcRmdThreading;
			ULONG lcbRmdThreading;
			ULONG fcMid;
			ULONG lcbMid;
			ULONG fcSttbRgtplc;
			ULONG lcbSttbRgtplc;
			ULONG fcMsoEnvelope;
			ULONG lcbMsoEnvelope;
			ULONG fcPlcfLad;
			ULONG lcbPlcfLad;
			ULONG fcRgDofr;
			ULONG lcbRgDofr;
			ULONG fcPlcosl;
			ULONG lcbPlcosl;
			ULONG fcPlcfCookieOld;
			ULONG lcbPlcfCookieOld;
			ULONG fcPgdMotherOld;
			ULONG lcbPgdMotherOld;
			ULONG fcBkdMotherOld;
			ULONG lcbBkdMotherOld;
			ULONG fcPgdFtnOld;
			ULONG lcbPgdFtnOld;
			ULONG fcBkdFtnOld;
			ULONG lcbBkdFtnOld;
			ULONG fcPgdEdnOld;
			ULONG lcbPgdEdnOld;
			ULONG fcBkdEdnOld;
			ULONG lcbBkdEdnOld;

			FibRgFcLcb2000();
			~FibRgFcLcb2000();

			VOID readFibRgFcLcb2000(std::ifstream &);
			VOID process_FibRgFcLcb2000();

		} fibRgFcLcb2000;     // struct FibRgFcLcb2000
		struct FibRgFcLcb2002
		{
			FibRgFcLcb2000 rgFcLcb2000;
			ULONG fcUnused1;
			ULONG lcbUnused1;
			ULONG fcPlcfPgp;
			ULONG lcbPlcfPgp;
			ULONG fcPlcfuim;
			ULONG lcbPlcfuim;
			ULONG fcPlfguidUim;
			ULONG lcbPlfguidUim;
			ULONG fcAtrdExtra;
			ULONG lcbAtrdExtra;
			ULONG fcPlrsid;
			ULONG lcbPlrsid;
			ULONG fcSttbfBkmkFactoid;
			ULONG lcbSttbfBkmkFactoid;
			ULONG fcPlcfBkfFactoid;
			ULONG lcbPlcfBkfFactoid;
			ULONG fcPlcfcookie;
			ULONG lcbPlcfcookie;
			ULONG fcPlcfBklFactoid;
			ULONG lcbPlcfBklFactoid;
			ULONG fcFactoidData;
			ULONG lcbFactoidData;
			ULONG fcDocUndo;
			ULONG lcbDocUndo;
			ULONG fcSttbfBkmkFcc;
			ULONG lcbSttbfBkmkFcc;
			ULONG fcPlcfBkfFcc;
			ULONG lcbPlcfBkfFcc;
			ULONG fcPlcfBklFcc;
			ULONG lcbPlcfBklFcc;
			ULONG fcSttbfbkmkBPRepairs;
			ULONG lcbSttbfbkmkBPRepairs;
			ULONG fcPlcfbkfBPRepairs;
			ULONG lcbPlcfbkfBPRepairs;
			ULONG fcPlcfbklBPRepairs;
			ULONG lcbPlcfbklBPRepairs;
			ULONG fcPmsNew;
			ULONG lcbPmsNew;
			ULONG fcODSO;
			ULONG lcbODSO;
			ULONG fcPlcfpmiOldXP;
			ULONG lcbPlcfpmiOldXP;
			ULONG fcPlcfpmiNewXP;
			ULONG lcbPlcfpmiNewXP;
			ULONG fcPlcfpmiMixedXP;
			ULONG lcbPlcfpmiMixedXP;
			ULONG fcUnused2;
			ULONG lcbUnused2;
			ULONG fcPlcffactoid;
			ULONG lcbPlcffactoid;
			ULONG fcPlcflvcOldXP;
			ULONG lcbPlcflvcOldXP;
			ULONG fcPlcflvcNewXP;
			ULONG lcbPlcflvcNewXP;
			ULONG fcPlcflvcMixedXP;
			ULONG lcbPlcflvcMixedXP;

			FibRgFcLcb2002();
			~FibRgFcLcb2002();

			VOID readFibRgFcLcb2002(std::ifstream &);
			VOID process_FibRgFcLcb2002();
		} fibRgFcLcb2002;    // struct FibRgFcLcb2002
		struct FibRgFcLcb2003
		{
			FibRgFcLcb2002 rgFcLcb2002;
			ULONG fcHplxsdr;
			ULONG lcbHplxsdr;
			ULONG fcSttbfBkmkSdt;
			ULONG lcbSttbfBkmkSdt;
			ULONG fcPlcfBkfSdt;
			ULONG lcbPlcfBkfSdt;
			ULONG fcPlcfBklSdt;
			ULONG lcbPlcfBklSdt;
			ULONG fcCustomXForm;
			ULONG lcbCustomXForm;
			ULONG fcSttbfBkmkProt;
			ULONG lcbSttbfBkmkProt;
			ULONG fcPlcfBkfProt;
			ULONG lcbPlcfBkfProt;
			ULONG fcPlcfBklProt;
			ULONG lcbPlcfBklProt;
			ULONG fcSttbProtUser;
			ULONG lcbSttbProtUser;
			ULONG fcUnused;
			ULONG lcbUnused;
			ULONG fcPlcfpmiOld;
			ULONG lcbPlcfpmiOld;
			ULONG fcPlcfpmiOldInline;
			ULONG lcbPlcfpmiOldInline;
			ULONG fcPlcfpmiNew;
			ULONG lcbPlcfpmiNew;
			ULONG fcPlcfpmiNewInline;
			ULONG lcbPlcfpmiNewInline;
			ULONG fcPlcflvcOld;
			ULONG lcbPlcflvcOld;
			ULONG fcPlcflvcOldInline;
			ULONG lcbPlcflvcOldInline;
			ULONG fcPlcflvcNew;
			ULONG lcbPlcflvcNew;
			ULONG fcPlcflvcNewInline;
			ULONG lcbPlcflvcNewInline;
			ULONG fcPgdMother;
			ULONG lcbPgdMother;
			ULONG fcBkdMother;
			ULONG lcbBkdMother;
			ULONG fcAfdMother;
			ULONG lcbAfdMother;
			ULONG fcPgdFtn;
			ULONG lcbPgdFtn;
			ULONG fcBkdFtn;
			ULONG lcbBkdFtn;
			ULONG fcAfdFtn;
			ULONG lcbAfdFtn;
			ULONG fcPgdEdn;
			ULONG lcbPgdEdn;
			ULONG fcBkdEdn;
			ULONG lcbBkdEdn;
			ULONG fcAfdEdn;
			ULONG lcbAfdEdn;
			ULONG fcAfd;
			ULONG lcbAfd;

			FibRgFcLcb2003();
			~FibRgFcLcb2003();

			VOID readFibRgFcLcb2003(std::ifstream &);
			VOID process_FibRgFcLcb2003();

		} fibRgFcLcb2003;    // struct FibRgFcLcb2003
		struct FibRgFcLcb2007
		{
			FibRgFcLcb2003 rgFcLcb2003;
			ULONG fcPlcfmthd;
			ULONG lcbPlcfmthd;
			ULONG fcSttbfBkmkMoveFrom;
			ULONG lcbSttbfBkmkMoveFrom;
			ULONG fcPlcfBkfMoveFrom;
			ULONG lcbPlcfBkfMoveFrom;
			ULONG fcPlcfBklMoveFrom;
			ULONG lcbPlcfBklMoveFrom;
			ULONG fcSttbfBkmkMoveTo;
			ULONG lcbSttbfBkmkMoveTo;
			ULONG fcPlcfBkfMoveTo;
			ULONG lcbPlcfBkfMoveTo;
			ULONG fcPlcfBklMoveTo;
			ULONG lcbPlcfBklMoveTo;
			ULONG fcUnused1;
			ULONG lcbUnused1;
			ULONG fcUnused2;
			ULONG lcbUnused2;
			ULONG fcUnused3;
			ULONG lcbUnused3;
			ULONG fcSttbfBkmkArto;
			ULONG lcbSttbfBkmkArto;
			ULONG fcPlcfBkfArto;
			ULONG lcbPlcfBkfArto;
			ULONG fcPlcfBklArto;
			ULONG lcbPlcfBklArto;
			ULONG fcArtoData;
			ULONG lcbArtoData;
			ULONG fcUnused4;
			ULONG lcbUnused4;
			ULONG fcUnused5;
			ULONG lcbUnused5;
			ULONG fcUnused6;
			ULONG lcbUnused6;
			ULONG fcOssTheme;
			ULONG lcbOssTheme;
			ULONG fcColorSchemeMapping;
			ULONG lcbColorSchemeMapping;

			FibRgFcLcb2007();
			~FibRgFcLcb2007();

			VOID readFibRgFcLcb2007(std::ifstream &);
			VOID process_FibRgFcLcb2007();

		} fibRgFcLcb2007;    // struct FibRgFcLcb2007

		FibRgFcLcb();
		~FibRgFcLcb();

	} fibRgFcLcbBlob; // union FibRgFcLcb
	USHORT cswNew;
	struct FibRgCswNew
	{
		USHORT nFibNew;
		union FibRgCswNewData
		{
			struct FibRgCswNewData2000
			{
				USHORT cQuickSavesNew;

				FibRgCswNewData2000();
				~FibRgCswNewData2000();

				VOID readFibRgCswNewData2000(std::ifstream &);
				VOID process_FibRgCswNewData2000();

			} fibRgCswNewData2000; // struct FibRgCswNewData2000

			struct FibRgCswNewData2007
			{
				FibRgCswNewData2000 rgCswNewData2000;
				USHORT lidThemeOther;
				USHORT lidThemeFE;
				USHORT lidThemeCS;

				FibRgCswNewData2007();
				~FibRgCswNewData2007();

				VOID readFibRgCswNewData2007(std::ifstream &);
				// nothing to process
			} fibRgCswNewData2007; // struct FibRgCswNewData2007

			FibRgCswNewData();
			~FibRgCswNewData();
		} rgCswNewData; // union FibRgCswNewData

		FibRgCswNew();
		~FibRgCswNew();

		VOID readFibRgCswNew(std::ifstream&);
	} fibRgCswNew; // struct FibRgCswNew

	Fib();
	~Fib();

	VOID readFib(std::ifstream&);
	inline USHORT determine_nFib_use() const;
	inline VOID skip_fields(std::ifstream&, ULONG) const;
	inline VOID adjust_file_pointer(std::ifstream&, USHORT, USHORT) const;
	inline static BYTE assignBits(BYTE, BYTE, int);

}; // struct Fib
#pragma pack(pop)
#endif // !FIB_H_INCLUDED