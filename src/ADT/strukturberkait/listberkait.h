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
}infoLagu;
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
/* Mengirim true jika list kosong */

void CreateEmptyPlaylist (ListBerkait *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

address Alokasi (infoLagu X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

boolean isPenyanyiAvail (ListBerkait L, infoLagu X);
/* I.S. P terdefinisi */
/* 
	mengembalikan boolean apakah lagu X ada di L
	true = ada;
	false = tidak ada
*/

boolean isAlbumAvail (ListBerkait L, infoLagu X);
/* I.S. P terdefinisi */
/* 
	mengembalikan boolean apakah album X ada di L
	true = ada;
	false = tidak ada
*/

void insertSongtoPlaylist(ListBerkait L,infoLagu X);

boolean isSongAvail (ListBerkait L, infoLagu X);
/* I.S. P terdefinisi */
/* 
	mengembalikan boolean apakah lagu X ada di L
	true = ada;
	false = tidak ada
*/

void InsVFirst (ListBerkait *L, infoLagu X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (ListBerkait *L, infoLagu X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void DelVFirst (ListBerkait *L, infoLagu *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (ListBerkait *L, infoLagu *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

void InsertFirst (ListBerkait *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (ListBerkait *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (ListBerkait *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void DelFirst (ListBerkait *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelPlaylist (ListBerkait *L, infoLagu X);

void DelLast (ListBerkait *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */

void DelAfter (ListBerkait *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void PrintNode (ListBerkait L);
/* I.S. List mungkin kosong */
/* 
	F.S. Jika list tidak kosong, isi list dicetak menjadi :
	Nama Penyanyi :
	Nama Album :
	Nama Judul Lagu :

*/

int NbElmtListBerkait (ListBerkait L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


void InversListBerkait (ListBerkait *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
void Konkat1 (ListBerkait *L1, ListBerkait *L2, ListBerkait *L3);

#endif