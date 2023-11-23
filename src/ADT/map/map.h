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
/* I.S. Sembarang */
/* F.S. Membuat sebuah MapofAlbum kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count bernilai Nil */

/* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptyAlbum(MapofAlbum M);
/* Mengirim true jika Map MapofAlbum kosong */
/* Ciri MapofAlbum kosong : count bernilai Nil */

boolean IsFullAlbum(MapofAlbum M);
/* Mengirim true jika MapofAlbum penuh */
/* Ciri MapofAlbum penuh : count bernilai MaxElMap */

int BanyakAlbum(MapofAlbum M);
/* Mengirimkan nilai banyaknya album pada MapofAlbum */
/* I.S. MapofAlbum mungkin kosong, dan bisa sudah berisi beberap album */
/* F.S. Mengembalikan banyaknya album pada MapofAlbum */

int IndeksAlbum(MapofAlbum M, Word k);
/* Mengembalikan atau mengirimkan indeks nilai Elmt album yang ada dalam MapofAlbum */
/* I.S. Menerima input nama album k */
/* F.S. Mengirimkan nilai indeks dari album k di MapofAlbum 
		Mengirimkan -1 jika album tidak terdapat di MapofAlbum*/

boolean IsMemberAlbum(MapofAlbum M, Word k);
/* Memeriksa apakah sebuah Elmt album k terdapat di MapofAlbum*/
/* Mengirimkan true jika Elmt album k terdapat di MapofAlbum */
/* I.S. Menerima input nama album k */
/* F.S. Mengirimkan true jika nama album terdapat dalam MapofAlbum
		Mengirimkan false jika nama album tidak terdapat dalam MapofAlbum */

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
/* I.S. MapofAlbum sudah terisi */
/* F.S. Mengirimkan */

void DisplayListAlbum (MapofAlbum M);
/* Menampilkan daftar Elmt album yang ada di MapofAlbum */
/* I.S. M mungkin kosong */
/* F.S. Menampilkan nama ListAlbum */

#endif
