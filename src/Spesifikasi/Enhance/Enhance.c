#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Enhance.h"

void Enhance(ListofPlaylist * LPl, ListofPenyanyi LP)
{
    srand(time(NULL));
    if (isEmptyListPlaylist(*LPl)) {
        printf("\nTidak ada playlist yang tersedia!\n\n");
    } else {
        printf("\nDaftar playlist yang kamu miliki: \n");
        DisplayListPlaylist(LPl);

        printf("\nMasukkan id playlist yang ingin di-enhance: ");
        STARTINPUT(stdin);
        int ID = WordtoNum(currentInput)-1;
        Word NamaPL =  GetListPlaylist(*LPl, ID);
        // CopyWordToVar(&NamaPL, LPl->namaPlaylist[ID]);
        // Word NamaPL = LPl->namaPlaylist[ID];

        while (!isMemberListPlaylist(*LPl, NamaPL)){
            ResetInput();
            printf("\nID Playlist tidak terdaftar!\n");
            printf("\nMasukkan ID Playlist yang dipilih: ");
            STARTINPUT(stdin);
            int idx = WordtoNum(currentInput)-1;
            NamaPL = GetListPlaylist(*LPl, idx);
        }

        if (isMemberListPlaylist(*LPl, NamaPL)){
            int songAdded = rand() % 3;
            int count = 0;
            ResetInput();
            
            while (count <= songAdded)
            {
                srand(time(NULL));
                int IDSinger = rand() % BanyakPenyanyi(LP);
                int IDAlbum = rand() % BanyakAlbum(LP.listpenyanyi[IDSinger].album);
                int IDSong = rand() % BanyakLagu(LP.listpenyanyi[IDSinger].album.listalbum[IDAlbum].listlagu);

                infoLagu x;
                x.Lagu.penyanyi = LP.listpenyanyi[IDSinger].namaPenyanyi;
                x.Lagu.album = LP.listpenyanyi[IDSinger].album.listalbum[IDAlbum].namaAlbum;
                x.Lagu.judul = LP.listpenyanyi[IDSinger].album.listalbum[IDAlbum].listlagu.Lagu[IDSong].judul;
                x.Lagu.status = 0;

                if (!isSongAvail(LPl->list, x))
                {
                    printf("\nMenambahkan lagu rekomendasi: \"");
                    TulisWordNoNL(LP.listpenyanyi[IDSinger].album.listalbum[IDAlbum].listlagu.Lagu[IDSong].judul);
                    printf("\" ke dalam playlist.\n");
                    printf("\n-----------SEBELUM DI INSERT : -------------\n");
                    PrintNode(LPl->list[ID]);
                    // printf("%d\n", ID);
                    InsVLast(&((*LPl).list[ID]), x);

                    printf("-----------SETELAH DI INSERT : -------------\n");
                    PrintNode(LPl->list[ID]);
                }
                count++;
            }

            printf("\nPlaylist \"");
            printf("\" berhasil di-enhance!\n\n");
        }
    }
}