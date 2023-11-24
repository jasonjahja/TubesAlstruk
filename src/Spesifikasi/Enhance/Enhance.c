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
        Word NamaPL = GetListPlaylist(*LPl, WordtoNum(currentInput));

        while (!isMemberListPlaylist(*LPl, NamaPL)){
            printf("\nID Playlist tidak terdaftar!\n");
            printf("\nMasukkan ID Playlist yang dipilih: ");
            STARTINPUT(stdin);
            NamaPL = GetListPlaylist(*LPl, WordtoNum(currentInput));
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
                    printf("Menambahkan lagu rekomendasi: \"%s\" ke dalam playlist.\n", LP.listpenyanyi[IDSinger].album.listalbum[IDAlbum].listlagu.Lagu[IDSong].judul.TabWord);
                    playlistAddSong(*LPl, LP);
                    count++;
                }
            }

            printf("\nPlaylist \"%s\" berhasil di-enhance!\n", NamaPL.TabWord);
        }
    }
}