#ifndef __LIST_H__
#define __LIST_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../map/map.h"
#include "../mesinbaris/mesinbaris.h"

/* Kamus Umum */
#define MaxElList 5
typedef struct {

    Word namaPenyanyi;
    MapofAlbum album;

} Penyanyi;

typedef struct {

	Penyanyi listpenyanyi[MaxElList]; 

} ListofPenyanyi; 

/* ********** KONSTRUKTOR ********** */
ListofPenyanyi MakeList();
/* I.S. Sembarang */
/* F.S. Membuat sebuah ListofPenyanyi kosong berkapasitas MaxElList */
/* Ciri Map kosong : count bernilai Nil */

//* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptyList(ListofPenyanyi L);
/* Mengirim true jika List ListofPenyanyi kosong */
/* Ciri ListofPenanyi kosong : count bernilai Nil */

boolean IsFullList(ListofPenyanyi L);
/* Mengirim true jika ListofPenyanyi penuh */
/* Ciri ListofPenyanyi penuh : count bernilai MaxElList */

int BanyakPenyanyi (ListofPenyanyi L);
/* Mengirimkan nilai banyaknya Penyanyi pada ListofPenyanyi */
/* I.S. ListofPenyanyi mungkin kosong, dan bisa sudah berisi beberap Penyanyi */
/* F.S. Mengembalikan banyaknya Penyanyi pada ListofPenyanyi */

boolean isMemberPenyanyi(ListofPenyanyi L, Word X);
/* Memeriksa apakah sebuah Elmt Penyanyi X terdapat di ListofPenyanyi */
/* Mengirimkan true jika Elmt Penyanyi X terdapat di ListofPenyanyi */

int IndeksPenyanyi (ListofPenyanyi L, Word X);
/* Mengirimkan indeks nilai Elmt Penyanyi X yang ada dalam ListofPenyanyi */
/* Mengirimkan -1 jika Penyanyi tidak terdapat di ListofPenyanyi*/

Word GetPenyanyi(ListofPenyanyi L, Word singer);
/* Mendapatkan nama album yang sesuai dengan input K di MapofAlbum */
/* I.S. MapofAlbum sudah terisi */
/* F.S. Mengirimkan */

void AddPenyanyi (ListofPenyanyi *L, Word singer);
/* Menambahkan sebuah Elmt Penaynyi singer ke ListofPenyanyi */
/* I.S. ListofPenyanyi mungkin kosong */
/* F.S. Menambahkan Elmt Penyanyi singer ke ListofPenyanyi */

void DelPenyanyi (ListofPenyanyi *L, Word singer);
/* Menghapus sebuah Elmt Penyanyi singer di ListofPenyanyi */
/* I.S. ListofPenyanyi mungkin kosong */
/* F.S. Elmt Penyanyi singer di ListofPenyanyi bukan anggota dari ListofPenyanyi */

void DisplayListPenyanyi (ListofPenyanyi L);
/* Menampilkan daftar Elmt Penyanyi yang ada di ListofPenyanyi */
/* I.S. ListofPenyanyi mungkin kosong */
/* F.S. Menampilkan elemen-elemen ListofPenyanyi */

#endif