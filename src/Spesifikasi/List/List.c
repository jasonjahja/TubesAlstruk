#include <stdio.h>
#include "List.h"

void list_default(ListofPenyanyi L)
{  
    printf("\nDaftar Penyanyi :\n");
    for (int i = 0; i < BanyakPenyanyi(L); i++)
    {
        printf("\t %d. ", i+1);
        TulisWord(L.listpenyanyi[i].namaPenyanyi);
    }
    printf("\nIngin melihat album yang ada? (Y/N) : ");
    STARTINPUT(stdin);

    while (!IsWordEq(currentInput, toKata("Y")) && !IsWordEq(currentInput, toKata("N")))
    {
        ResetInput();
        printf("\nCommand tidak diketahui!\n");
        printf("\nIngin melihat album yang ada? (Y/N) : ");
        STARTINPUT(stdin);
    }

    if (IsWordEq(currentInput, toKata("Y"))) 
    {
        printf("\nPilih penyanyi untuk melihat album mereka : ");
        STARTINPUT(stdin);

        while (!isMemberPenyanyi(L, currentInput))
        {
            ResetInput();
            printf("\nPenyanyi tidak terdapat pada List!\n");

            printf("\nDaftar Penyanyi :\n");
            for (int i = 0; i < BanyakPenyanyi(L); i++)
            {
                printf("\t %d. ", i+1);
                TulisWord(L.listpenyanyi[i].namaPenyanyi);
            }

            printf("\nPilih penyanyi untuk melihat album mereka : ");
            STARTINPUT(stdin);
        }

        int idxlagu = IndeksPenyanyi(L, currentInput);
        
        printf("\nDaftar Album oleh %s : \n", currentInput.TabWord);
        for (int j = 0; j < BanyakAlbum(L.listpenyanyi[idxlagu].album); j++)
        {
            printf("\t %d. ", j+1);
            TulisWord(L.listpenyanyi[idxlagu].album.listalbum[j].namaAlbum);
        }

        printf("\nIngin melihat lagu yang ada? (Y/N) : ");
        STARTINPUT(stdin); 

        while (!IsWordEq(currentInput, toKata("Y")) && !IsWordEq(currentInput, toKata("N")))
        {
            ResetInput();
            printf("\nCommand tidak diketahui!\n");
            printf("\nIngin melihat album yang ada? (Y/N) : ");
            STARTINPUT(stdin);
        }

        if (IsWordEq(currentInput, toKata("Y")))
        {
            printf("\nPilih album untuk melihat lagu yang ada di album : ");
            STARTINPUT(stdin);

            while (!IsMemberAlbum(L.listpenyanyi[idxlagu].album, currentInput))
            {
                ResetInput();
                printf("\nPenyanyi tidak memiliki Album tersebut!\n");

                printf("\nDaftar Album oleh %s : \n", currentInput.TabWord);
                for (int j = 0; j < BanyakAlbum(L.listpenyanyi[idxlagu].album); j++)
                {
                    printf("\t %d. ", j+1);
                    TulisWord(L.listpenyanyi[idxlagu].album.listalbum[j].namaAlbum);
                }
                printf("\nPilih album untuk melihat lagu yang ada di album : ");
                STARTINPUT(stdin);
            }

            int idxalbum = IndeksAlbum(L.listpenyanyi[idxlagu].album, currentInput);

            printf("\nDaftar lagu di %s: \n",currentInput.TabWord);
            for (int k = 0; k < BanyakLagu(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].listlagu); k++)
            {
                printf("\t %d. ", k+1);
                TulisWord(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].listlagu.Lagu[k].judul);
            }
        }
    }
    printf("\n");
}

// void list_playlist(ListofPlaylist L)
// {
    
// }