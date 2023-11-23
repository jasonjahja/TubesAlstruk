#include <stdio.h>
#include "set.h"
#include "../mesinkata/mesinkata.h"

/* ********* IMPLEMENTASI FUNGSI-FUNGSI ********* */
SetofSong CreateEmptySet()
{
    SetofSong S;
    for (int i = 0 ; i < MaxElSet ; i++)
    {
        S.Lagu[i].judul = Mark;
        S.Lagu[i].album = Mark;
        S.Lagu[i].penyanyi = Mark;
        S.Lagu[i].status = 0;
    }
    return S;
}

boolean IsEmptySet(SetofSong S)
{
    return (S.Lagu[0].status == 0);
}

boolean IsFullSet(SetofSong S)
{
    return (IsWordEq(S.Lagu[BanyakLagu(S)-1].judul, Mark));
}

boolean IsMemberLagu(SetofSong S, Word Elmt)
{
    for (int i = 0; i < BanyakLagu(S); i++)
    {
        if (IsWordEq(S.Lagu[i].judul, Elmt))
        {
            return true;
        }
    }
    return false;
}

int BanyakLagu(SetofSong S)
{
    int count = 0;
    for (int i = 0; i < MaxElSet; i++)
    {
        if (IsWordEq(S.Lagu[i].judul, Mark))
        {
            return count;
        }
        count++;
    }
    return count;
}

void AddLagu(SetofSong *S, Word Elmt)
{
    if(!IsMemberLagu(*S, Elmt))
    {
        (*S).Lagu[BanyakLagu(*S)].judul = Elmt;
    }
}

void DeleteLagu(SetofSong *S, Word Elmt)
{
    int idx = 0;
    if (IsMemberLagu(*S, Elmt))
    {
        // while (IsWordEq((*S).Lagu[idx].judul, Elmt))
        while (!IsWordEq((*S).Lagu[idx].judul, Elmt))
        {
            idx++;
        }
        while (idx < BanyakLagu(*S))
        {
            CopyWordToVar(&(*S).Lagu[idx].judul, (*S).Lagu[idx+1].judul); 
            
            idx++;
        }
        CopyWordToVar(&(*S).Lagu[idx].judul, Mark);

    }
}

void DisplayListLagu(SetofSong S)
{
    for (int i = 0; i < BanyakLagu(S); i++)
    {
        printf("     %d. ",i+1);
        TulisWord(S.Lagu[i].judul);
    }
}

Word IndeksSong(SetofSong S,int idx){
    return (S.Lagu[idx].judul);
}