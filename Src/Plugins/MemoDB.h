#pragma once

#define LocalizedAppInfoStr			1000

typedef struct {
   UInt16	renamedCategories;		// bitfield of categories with a different name
	char	categoryLabels[dmRecNumCategories][dmCategoryLength];
	UInt8	categoryUniqIDs[dmRecNumCategories];
	UInt8	lastUniqID;			// Uniq IDs generated by the device are between
									// 0 - 127.  Those from the PC are 128 - 255.
	UInt8	reserved1;			// from the compiler word aligning things
	UInt16	reserved2;
	UInt16	reserved3;
	UInt8	sortOrder;
	UInt8	reserved;
} MemoAppInfoType;

typedef MemoAppInfoType * MemoAppInfoPtr;


// Sort orders
#define soUnsorted		0
#define soAlphabetic		1


typedef struct {
	char 	note;		// null terminated
	UInt8	reserved;
} MemoDBRecordType;

typedef MemoDBRecordType * MemoDBRecordPtr;

typedef struct {
	Char *				note;
} MemoItemType;

typedef MemoItemType * MemoItemPtr;


#ifdef __cplusplus
extern "C" {
#endif


//-------------------------------------------------------------------
// Routines
//-------------------------------------------------------------------
extern Err		MemoAppInfoInit(DmOpenRef dbP);

extern Err		MemoNewRecord(DmOpenRef dbP, MemoItemPtr item, UInt16 *index);

extern Err		MemoChangeSortOrder(DmOpenRef dbP, UInt8 sortOrder);

extern UInt8	MemoGetSortOrder (DmOpenRef dbP);

extern void		MemoSort (DmOpenRef dbP);

extern Err		MemoSortRecord (DmOpenRef dbP, UInt16 * indexP);

extern Err		MemoGetDatabase (DmOpenRef *dbPP, UInt16 mode);

#ifdef __cplusplus
}
#endif
