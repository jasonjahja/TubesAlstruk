/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdio.h>
#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinbaris/mesinbaris.h"


#define NMax 100
#define BLANK ' '
#define NewLine '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean endWord;
extern Word currentWord;
extern Word currentInput;

void IgnoreBlanks();
/*  Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(FILE* input);
/*  I.S. :  currentChar sembarang
    F.S. :  endWord = true, dan currentChar = '.';
            atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/*  I.S. :  currentChar sembarang
    F.S. :  endWord = true, dan currentChar = ' ';
            atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

void CopyWord();
/* Fungsi untuk mengakuisisi kata dari input dan menyimpannya dalam variabel */

boolean isEndWord();
/* Fungsi yang mengembalikan nilai boolean dan menunjukkan proses akuisis kata */

void GetCommand();

void IgnoreNewLine();
/*  Mengabaikan satu atau beberapa NewLine
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ NewLine atau currentChar = MARK */

void CopyWordToVar(Word *kata1, Word kata2);

void TulisWord(Word kata);
/* Fungsi untuk menyalin isi dari suatu kata yang sedang diakuisisi ke variabel lainnya */
/* Fungsi ini bekerja dengan mengkopi panjang dan isi dari kata2 ke kata1 */

void GetInput();
/* Fungsi untuk membaca input dari pengguna */
/* Fungsi ini menggunakan prosedur STARTINPUT */

void TulisWordNoNL(Word kata);
/* Fungsi untuk menyalin isi dari suatu kata yang sedang diakuisisi ke variabel lainnya,
    bedanya tanpa dengan tulisword biasa tidak ditambahkan NewLine setelahnya */
/* Fungsi ini bekerja dengan mengkopi panjang dan isi dari kata2 ke kata1 */

boolean IsWordEq (Word kata1, Word kata2);
/* Fungsi untuk membandingkan dua kata */

int WordtoNum (Word kata);
/* Fungsi untuk mengubah kata dalam bentuk string menjadi tipe integer */

void ResetKalimat();

void ResetWord();
/* Fungsi yang bertujuan untuk mengembalikan nilai variabel ke dalam keadaan awal atau kosong */

void STARTINPUT(FILE* input);
/* Fungsi yang bertujuan untuk memulai proses pembacaan input dari file */

void CopyInput();
/* Fungsi untuk mengakuisisi masukan dari pengguna hingga menemukan ';' dan menyimpan ke dalam variabel */

void ResetInput();
/* Fungsi untuk mengembalikan variabel ke */

Word toKata(char *str); 
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */

Word intToWord(int n);
/* Fungsi untuk mengubah angka dalam tipe integer menjadi word */

void IgnoreTK();
/*  Mengabaikan satu atau beberapa ';'
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ ';' atau currentChar = MARK */

int stringLength(char *str);
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */

#endif
