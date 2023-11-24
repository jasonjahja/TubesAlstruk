#include <stdio.h>
#include <stdlib.h>
#include "Enhance.h"

void Enhance(ListofPlaylist * LPl, ListofPenyanyi LP)
{
    if (isEmptyListPlaylist(*LPl)) {
        printf("\nTidak ada playlist yang tersedia!\n\n");
    } else {
        printf("\nDaftar playlist yang kamu miliki: \n");
        DisplayListPlaylist(LPl);

        printf("\nMasukkan id playlist yang ingin di-enhance: ");
        STARTINPUT(stdin);
        int ID = WordtoNum(currentInput)-1;
        Word NamaPL;
        CopyWordToVar(&NamaPL, LPl->namaPlaylist[ID]);
        // Word NamaPL = LPl->namaPlaylist[ID];

        while (!isMemberListPlaylist(*LPl, NamaPL)){
            printf("\nID Playlist tidak terdaftar!\n");
            printf("\nMasukkan ID Playlist yang dipilih: ");
            STARTINPUT(stdin);
            NamaPL = GetListPlaylist(*LPl, WordtoNum(currentInput)-1);
        }

        if (isMemberListPlaylist(*LPl, NamaPL)){
            int songAdded = rand() % 3;
            int count = 0;
            
            while (count < songAdded)
            {
                int IDSinger = rand() % BanyakPenyanyi(LP);
                int IDAlbum = rand() % BanyakAlbum(LP.listpenyanyi->album);
                int IDSong = rand() % BanyakLagu(LP.listpenyanyi->album.listalbum->listlagu);

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
                    printf("%d\n", ID);
                    PrintNode(LPl->list[ID]);
                    InsVLast(&((*LPl).list[ID]), x);
                    PrintNode(LPl->list[ID]);
                    count++;
                }
            }

            printf("\nPlaylist \"");
            TulisWordNoNL(NamaPL);
            printf("\" berhasil di-enhance!\n\n");
        }
    }
}