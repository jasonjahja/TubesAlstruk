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

//* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptySet(SetofSong S);

boolean IsFullSet(SetofSong S);

int BanyakLagu(SetofSong S);

void AddLagu(SetofSong *S, Word Elmt);

void DeleteLagu(SetofSong *S, Word Elmt);

boolean IsMemberLagu(SetofSong S, Word Elmt);

void DisplayListLagu(SetofSong S);

int IndeksLagu(SetofSong S, Word Elmt);

Word IndeksSong(SetofSong S,int idx);

#endif