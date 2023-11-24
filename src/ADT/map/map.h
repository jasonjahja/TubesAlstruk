#ifndef __map_H__
#define __map_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../set/set.h"
#include "../mesinbaris/mesinbaris.h"

/* Kamus Umum */
#define MaxElMap 7
extern const Word Mark;

typedef struct
{
	Word namaAlbum;
	SetofSong listlagu;
	
} Album;

typedef struct
{
	Album listalbum[MaxElMap];

} MapofAlbum;

/* ********** KONSTRUKTOR ********** */
MapofAlbum CreateEmptyAlbum();
/* Membuat sebuah MapofAlbum kosong berkapasitas MaxElMap */
/* Ciri Map kosong : isi semua elemennya berupa Mark */

/* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptyAlbum(MapofAlbum M);
/* Mengirim true jika Map MapofAlbum kosong */
/* Ciri MapofAlbum kosong : isi elemen pertamanya berupa Mark */

boolean IsFullAlbum(MapofAlbum M);
/* Mengirim true jika MapofAlbum penuh */
/* Ciri MapofAlbum penuh : elemen mengisi seluruh kapasitas */

int BanyakAlbum(MapofAlbum M);
/* Mengirimkan nilai banyaknya album pada MapofAlbum */
/* I.S. MapofAlbum mungkin kosong, dan bisa sudah berisi beberap album */
/* F.S. Mengembalikan banyaknya album pada MapofAlbum */

int IndeksAlbum(MapofAlbum M, Word k);
/* Mengembalikan atau mengirimkan indeks nilai Elmt album yang ada dalam MapofAlbum */

boolean IsMemberAlbum(MapofAlbum M, Word k);
/* Memeriksa apakah sebuah Elmt album k terdapat di MapofAlbum*/
/* Mengirimkan true jika Elmt album k terdapat di MapofAlbum */

void AddAlbum(MapofAlbum *M, Word k);
/* Menambahkan sebuah Elmt k ke MapofAlbum */
/* I.S. MapofAlbum mungkin kosong */
/* F.S. Menambahkan Elmt k ke MapofAlbum */

void DelAlbum(MapofAlbum *M, Word k);
/* Menghapus sebuah Elmt album di MapofAlbum */
/* I.S. MapofAlbum mungkin kosong */
/* F.S. Elmt k di MapofAlbum bukan anggota dari MapofAlbum */

Sentence GetAlbum(MapofAlbum M, Sentence k);
/* Mendapatkan nama album yang sesuai dengan input K di MapofAlbum */

void DisplayListAlbum (MapofAlbum M);
/* Menampilkan daftar Elmt album yang ada di MapofAlbum */
/* I.S. M mungkin kosong */
/* F.S. Menampilkan nama ListAlbum */

#endif
