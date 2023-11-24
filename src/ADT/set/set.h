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
/* F.S. Membuat sebuah set SetofSong kosong berkapasitar MaxelSet */

//* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptySet(SetofSong S);
/* Mengirim true jika Set SetofSong kosong */
/* Ciri Set kosong : elemen pertama bernilai Mark */

boolean IsFullSet(SetofSong S);
/* Mengirim true jika Set SetofSong penuh */
/* Ciri Set penuh : elemen terisi sampai MaxElSet */

int BanyakLagu(SetofSong S);
/* Mengirim jumlah lagu atau jumlah Elmt di SetofSong */
/* I.S. Menerima set lagu SetofSong */
/* F.S. Mengirimkan nilai banyaknya lagu dalam SetofSong */

void AddLagu(SetofSong *S, Word Elmt);
/* Menambah Elmt ke SetofSong S */
/* I.S. SetofSong sudah terdeklarasi, mungkin kosong */
/* F.S. Elmt berhasil ditambah ke SetofSong */

void DeleteLagu(SetofSong *S, Word Elmt);
/* Menghapus Elmt dari SetofSong S */
/* I.S. S tidak kosong 
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberLagu(SetofSong S, Word Elmt);
/* Mengirim true jika Elmt termasuk ke SetofSong */

void DisplayListLagu(SetofSong S);
/* Menampilkan judul lagu yang ada di SetofSong S */
/* I.S. M mungkin kosong */
/* F.S. Menampilkan nama ListAlbum */

int IndeksLagu(SetofSong S, Word Elmt);

Word IndeksSong(SetofSong S,int idx);

#endif