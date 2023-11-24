#ifndef __set_H__
#define __set_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

/*Kamus Umum*/
#define MaxElSet 20
extern const Word Mark; 

typedef struct
{ 
    Word judul;
    Word album;
    Word penyanyi;
    int status;
} Song;

typedef struct
{
    Song Lagu[MaxElSet];
} SetofSong;

/* ********** KONSTRUKTOR ********** */
SetofSong CreateEmptySet();
/* Membuat sebuah set SetofSong kosong berkapasitar MaxelSet */
/* Ciri Set kosong : semua elemen judul, album, dan penyanyi berupa Mark dan statusnya 0  */

//* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptySet(SetofSong S);
/* Mengirim true jika Set SetofSong kosong */
/* Ciri Set kosong : status bernilai 0 */

boolean IsFullSet(SetofSong S);
/* Mengirim true jika Set SetofSong penuh */
/* Ciri Set penuh : elemen mengisi seluruh kapasitas */

boolean IsMemberLagu(SetofSong S, Word Elmt);
/* Mengirim true jika Elmt termasuk ke SetofSong */
/* I.S. Menerima input Elmt */
/* F.S. Mengirimkan true jika nama lagu terdapat dalam SetofSong
		Mengirimkan false jika nama lagu tidak terdapat dalam SetofSong */

int BanyakLagu(SetofSong S);
/* Mengirim jumlah lagu atau jumlah Elmt di SetofSong */

void AddLagu(SetofSong *S, Word Elmt);
/* Menambah Elmt ke SetofSong S */
/* I.S. SetofSong sudah terdeklarasi, mungkin kosong */
/* F.S. Elmt berhasil ditambah ke SetofSong */

void DeleteLagu(SetofSong *S, Word Elmt);
/* Menghapus Elmt dari SetofSong S */
/* I.S. S tidak kosong 
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

void DisplayListLagu(SetofSong S);
/* Menampilkan judul lagu yang ada di SetofSong S */
/* I.S. M mungkin kosong */
/* F.S. Menampilkan nama ListAlbum */

int IndeksLagu(SetofSong S, Word Elmt);

Word IndeksSong(SetofSong S,int idx);

#endif