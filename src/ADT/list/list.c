#include <stdio.h>
#include "list.h"

/* ********** IMPELEMNTASI FUNGSI ********** */
ListofPenyanyi MakeList()
{
    ListofPenyanyi L;
    for (int i = 0 ; i < MaxElList ; i++)
    {
        L.listpenyanyi[i].namaPenyanyi = Mark;
        for (int j = 0; j < MaxElMap; j++)
        {
            L.listpenyanyi[i].album.listalbum[j].namaAlbum = Mark;
            for (int k = 0; k < MaxElSet; k++)
            {
                L.listpenyanyi[i].album.listalbum[j].listlagu.Lagu[k].judul= Mark;
            }  
        }
    }
    return L;
}

boolean IsEmptyList(ListofPenyanyi L)
{
    return (IsWordEq(L.listpenyanyi[0].namaPenyanyi, Mark));
}

boolean IsFullList(ListofPenyanyi L)
{
    return (!IsWordEq(L.listpenyanyi[BanyakPenyanyi(L)-1].namaPenyanyi, Mark));
}

int BanyakPenyanyi (ListofPenyanyi L)
{
    int count = 0;
    for (int i = 0; i < MaxElList; i++)
    {
        if (IsWordEq(L.listpenyanyi[i].namaPenyanyi, Mark))
        {
            break;
        }
        count++;
    }
    return count;
}

void AddPenyanyi (ListofPenyanyi *L, Word singer)
{
    
    int index = BanyakPenyanyi(*L);
    if (BanyakPenyanyi(*L) < MaxElList)
    {
        CopyWordToVar(&(*L).listpenyanyi[index].namaPenyanyi, singer);
        index++;
    }
}


Word GetPenyanyi(ListofPenyanyi L, Word singer)
{
    for (int i = 0; i < MaxElList; i++)
    {
        if (IsWordEq(L.listpenyanyi[i].namaPenyanyi, singer))
        {
            return singer;
        }
    }
    return singer;
}

int IndeksPenyanyi (ListofPenyanyi L, Word X)
{
    int idx = 0;
    for (int i = 0; i < MaxElList; i++)
    {
        if (IsWordEq(X, L.listpenyanyi[i].namaPenyanyi))
        {
            return idx;
        }
        else
        {
            idx++;
        }
    }
    return -1;
}



boolean isMemberPenyanyi(ListofPenyanyi L, Word X)
{
    for (int i = 0; i < MaxElList; i++)
    {
        if (IsWordEq(X, L.listpenyanyi[i].namaPenyanyi))
        {
            return true;
        }
    }
    return false;
}

void DisplayListPenyanyi (ListofPenyanyi L)
{
    for (int i = 0 ; i < BanyakPenyanyi(L); i++)
    {
        printf("%d. ", i+1);
        TulisWord(L.listpenyanyi[i].namaPenyanyi);
    }
}