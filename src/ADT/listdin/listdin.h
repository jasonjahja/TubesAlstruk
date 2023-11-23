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
/* I.S. Sembarang */
/* F.S. Membuat sebuah ListofPlaylist kosong berkapasitas SizeList */
/* Ciri List kosong : count bernilai Nil */

void DeallocateListPlaylist(ListofPlaylist *l);
/* I.S. ListofPlaylist l terdefinisi */
/* F.S. ListofPlaylist l dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address l */

/* ********** FUNGSI-FUNGSI ********** */
int LengthListPlaylist(ListofPlaylist l);
/* Mengirim nilai banyaknya Playlist di ListofPlaylist*/

boolean isEmptyListPlaylist(ListofPlaylist l);
/* Mengirim true jika List ListofPlaylist kosong */
/* Ciri ListofPlaylist kosong : l.nEFF = 0 */

boolean isMemberListPlaylist(ListofPlaylist l, Word X);
/* Memeriksa apakah sebuah Elmt Playlist X terdapat di ListofPlaylist */
/* Mengirimkan true jika Elmt Playlist X terdapat di ListofPlaylist */
/* I.S.  Menerima input nama Playlist X */
/* F.S.  Mengirimkan true jika nama Playlist terdapat dalam ListofPlaylist
		   Mengirimkan false jika nama Playlist tidak terdapat dalam ListofPlaylist */

int IndexListPlaylist(ListofPlaylist l, Word val);
/* Mengirimkan indeks nilai Elmt Playlist val yang ada dalam ListofPlaylist */
/* I.S.  Menerima input nama Playlist val */
/* F.S.  Mengirimkan nilai indeks dari Playlist val di ListofPlaylist
         Mengirimkan -1 jika Playlist tidak terdapat di ListofPlaylist */

Word GetListPlaylist(ListofPlaylist l, int idx);
/* Fungsi untuk mendapatkan kapasitas yang tersedia. 
   Prekondisi: ListofPlaylist terdefinisi */

void InsertListPlaylist(ListofPlaylist *l, Word val);
/* Fungsi untuk menyisipkan playlist baru ke dalam ListofPlaylist */
/* I.S.  */
/* F.S.  */

void CopyPlaylist(ListBerkait lin, ListBerkait *lout);
/* Fungsi untuk membuat salinan dari ListofPlaylist yang ada */
/* I.S.  ListofPlaylist sudah terdefisnisi */
/* F.S.  ListofPlaylit baru terdefinisi, salinan dari yang lama */

void DeleteListPlaylist(ListofPlaylist *l, int idx); 

void DeletePlaylist(ListBerkait *L);

void DisplayListPlaylist(ListofPlaylist *l);
/* Menampilkan daftar Elmt Playlist yang ada di ListofPlaylist */
/* I.S. ListofPlaylist mungkin kosong */
/* F.S. Menampilkan elemen-elemen ListofPlaylist */

#endif