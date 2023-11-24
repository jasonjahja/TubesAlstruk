#ifndef listlinier_H
#define listlinier_H

#include "../../boolean.h"
#include "../mesinbaris/mesinbaris.h"
#include "../mesinkata/mesinkata.h"
#include "../list/list.h"
#include "../map/map.h"
#include "../set/set.h"

#define NilNode NULL

typedef struct tElmtlist *address;


typedef struct {
    Song Lagu;
} infoLagu;
// typedef infoLagu infotype;

typedef struct tElmtlist { 
	infoLagu info;
	address next;
} ElmtList;

// typedef infoLagu infotype;
typedef struct {
	address First;
} ListBerkait;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Penyanyi(P) (P)->info.Penyanyi
#define Album(P) (P)->info.Album
#define Lagu(P) (P)->info.Lagu


boolean IsEmpty (ListBerkait L);

void CreateEmptyPlaylist (ListBerkait *L);

address Alokasi (infoLagu X);

void Dealokasi (address *P);

boolean isPenyanyiAvail (ListBerkait L, infoLagu X);

boolean isAlbumAvail (ListBerkait L, infoLagu X);

void insertSongtoPlaylist(ListBerkait L,infoLagu X);

boolean isSongAvail (ListBerkait *L, infoLagu X);

void InsVFirst (ListBerkait *L, infoLagu X);

void InsVLast (ListBerkait *L, infoLagu X);

void DelVFirst (ListBerkait *L, infoLagu *X);

void DelVLast (ListBerkait *L, infoLagu *X);

void InsertFirst (ListBerkait *L, address P);

void InsertAfter (ListBerkait *L, address P, address Prec);

void InsertLast (ListBerkait *L, address P);

void DelFirst (ListBerkait *L, address *P);

void DelPlaylist (ListBerkait *L, infoLagu X);

void DelLast (ListBerkait *L, address *P);

void DelAfter (ListBerkait *L, address *Pdel, address Prec);

void PrintNode (ListBerkait L);

int NbElmtListBerkait (ListBerkait L);

void InversListBerkait (ListBerkait *L);

void Konkat1 (ListBerkait *L1, ListBerkait *L2, ListBerkait *L3);

#endif