#include "Play.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyCurrentStat (CurrentStat *current)
{
    current->currentplay.judul = Mark;
    current->currentplay.album = Mark;
    current->currentplay.penyanyi = Mark;
    current->currentplay.status = 0;
    current->playlist = Mark;
    current->statusPL = 0;
}

void playSong (ListofPenyanyi daftarpenyanyi, CurrentStat * currentSong, songHistory * history, Queue * queue)
{
    CreateEmptyStack(history);
    CreateEmptyQueue(queue);

    printf("\nDaftar Penyanyi:\n");
    for (int i = 0; i < BanyakPenyanyi(daftarpenyanyi); i++)
    {
        printf("    %d. ", i+1);
        TulisWord(daftarpenyanyi.listpenyanyi[i].namaPenyanyi);
    }

    printf("\nMasukkan nama penyanyi yang dipilih: ");
    STARTINPUT(stdin);
    int IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, currentInput);

    while (IDPenyanyi == -1)
    {
        printf("\nNama penyanyi tidak terdaftar!\n");
        printf("\nMasukkan nama penyanyi yang dipilih: ");
        STARTINPUT(stdin);
        IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, currentInput);
    }
    
    if (IDPenyanyi != -1)
    {
        printf("\nDaftar Album:\n");
        for (int j = 0; j < BanyakAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album); j++)
        {
            printf("    %d. ", j+1);
            TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[j].namaAlbum);
        }

        printf("\nMasukkan nama album yang dipilih: ");
        STARTINPUT(stdin);
        int IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, currentInput);
        
        while (IDAlbum == -1)
        {
            printf("\nNama album tidak terdaftar!\n");
            printf("\nMasukkan nama album yang dipilih: ");
            STARTINPUT(stdin);
            IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, currentInput);
        }

        if (IDAlbum != -1)
        {
            printf("\nDaftar Lagu:\n"); 
            for (int k = 0; k < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu); k++)
            {
                printf("    %d. ", k+1);
                TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[k].judul);
            }

            printf("\nMasukkan ID lagu yang dipilih: ");
            STARTINPUT(stdin);
            int IDLagu = WordtoNum(currentInput) - 1;

            while (IDLagu == -1 || IDLagu >= BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
            {
                printf("\nID Lagu tidak terdaftar!\n");
                printf("\nMasukkan ID lagu yang dipilih: ");
                STARTINPUT(stdin);
                IDLagu = WordtoNum(currentInput) - 1;
            }

            if (IDLagu < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
            {
                printf("\nMemutar lagu \"");
                TulisWordNoNL(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
                printf("\" oleh \"");
                TulisWordNoNL(daftarpenyanyi.listpenyanyi[IDPenyanyi].namaPenyanyi);
                printf("\"\n\n");
                currentSong->currentplay.judul = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                currentSong->currentplay.album = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].namaAlbum;
                currentSong->currentplay.penyanyi = daftarpenyanyi.listpenyanyi[IDPenyanyi].namaPenyanyi;
                currentSong->currentplay.status = 1;
            }
        }
    }    
}

void playPlaylist(ListofPlaylist daftarplaylist, CurrentStat * currentSong, songHistory * history, Queue * queue)
{
    printf("\nDaftar Playlist: \n");
    DisplayListPlaylist(&daftarplaylist);
    
    printf("\nMasukkan ID Playlist: ");
    STARTINPUT(stdin);
    int IDPlaylist = WordtoNum(currentInput) -1;

    while (IDPlaylist <= -1 && IDPlaylist > (daftarplaylist.nEff - 1))
    {
        printf("\nID Playlist tidak terdaftar!\n");
        printf("\nMasukkan ID Playlist: ");
        STARTINPUT(stdin);
        IDPlaylist = WordtoNum(currentInput) - 1;
    }

    address P = daftarplaylist.list[IDPlaylist].First;

    currentSong->playlist = daftarplaylist.namaPlaylist[IDPlaylist];
    currentSong->statusPL = 1;
    currentSong->currentplay.judul = daftarplaylist.list[IDPlaylist].First->info.Lagu.judul;
    currentSong->currentplay.album = daftarplaylist.list[IDPlaylist].First->info.Lagu.album;
    currentSong->currentplay.penyanyi = daftarplaylist.list[IDPlaylist].First->info.Lagu.penyanyi;
    currentSong->currentplay.status = 1;

    while (Next(P) != NilNode)
    {
        enqueueQueue(queue, Next(P)->info.Lagu.judul, Next(P)->info.Lagu.album, Next(P)->info.Lagu.penyanyi);
        PushStack(history, Next(P)->info.Lagu.judul, Next(P)->info.Lagu.album, Next(P)->info.Lagu.penyanyi);
        P = Next(P);
    }

    printf("\nMemutar playlist \""); TulisWordNoNL(currentSong->playlist); printf("\".\n\n");
}