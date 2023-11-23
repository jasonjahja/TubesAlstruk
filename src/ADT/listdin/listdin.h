#ifndef __LISTDIN_H__
#define __LISTDIN_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinbaris/mesinbaris.h"
#include "../strukturberkait/listberkait.h"

/*  Kamus Umum */
#define Sizelist 10
typedef struct
{
   Word *namaPlaylist;
   ListBerkait *list;
   int nEff;       
   int Capacity;   

} ListofPlaylist;


/* ********** KONSTRUKTOR ********** */
ListofPlaylist CreateListPlaylist();

void DeallocateListPlaylist(ListofPlaylist *l);

/* ********** FUNGSI-FUNGSI ********** */
int LengthListPlaylist(ListofPlaylist l);

boolean isEmptyListPlaylist(ListofPlaylist l);

boolean isMemberListPlaylist(ListofPlaylist l, Word X);

int IndexListPlaylist(ListofPlaylist l, Word val);

Word GetListPlaylist(ListofPlaylist l, int idx);

void InsertListPlaylist(ListofPlaylist *l, Word val);

void CopyPlaylist(ListBerkait lin, ListBerkait *lout);

void DeleteListPlaylist(ListofPlaylist *l, Word val);

void DisplayListPlaylist(ListofPlaylist *l);

#endif