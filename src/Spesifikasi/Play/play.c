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

    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < BanyakPenyanyi(daftarpenyanyi); i++)
    {
        printf("%d. ", i+1);
        TulisWord(daftarpenyanyi.listpenyanyi[i].namaPenyanyi);
    }

    printf("Masukkan nama penyanyi yang dipilih: ");
    STARTINPCOMMAND(stdin);
    Word input = toKata(currentLine.kalimat);
    int IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, input);

    while (IDPenyanyi == -1)
    {
        printf("Nama penyanyi tidak terdaftar!\n");
        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPCOMMAND(stdin);
        Word input = toKata(currentLine.kalimat);
        IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, input);
    }
    
    if (IDPenyanyi != -1)
    {
        printf("%d\n", IDPenyanyi);
        printf("Daftar Album:\n");
        for (int j = 0; j < BanyakAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album); j++)
        {
            printf("tes");
            printf("%d. ", j+1);
            TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[j].namaAlbum);
        }

        printf("Masukkan nama album yang dipilih: ");
        STARTINPCOMMAND(stdin);
        Word input = toKata(currentLine.kalimat);
        int IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, input);
        
        while (IDAlbum == -1)
        {
            printf("Nama album tidak terdaftar!\n");
            printf("Masukkan nama album yang dipilih: ");
            STARTINPCOMMAND(stdin);
            IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, input);
        }

        if (IDAlbum != -1)
        {
            printf("Daftar Lagu:\n"); 
            for (int k = 0; k < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu); k++)
            {
                printf("%d. ", k+1);
                TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[k].judul);
            }

            printf("Masukkan ID lagu yang dipilih: ");
            STARTINPCOMMAND(stdin);
            Word input = toKata(currentLine.kalimat);
            int IDLagu = WordtoNum(input) - 1;

            while (IDLagu <= -1 && IDLagu > BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
            {
                printf("ID Lagu tidak terdaftar!\n");
                printf("Masukkan ID lagu yang dipilih: ");
                STARTINPCOMMAND(stdin);
                Word input = toKata(currentLine.kalimat);
                IDLagu = WordtoNum(input) - 1;
            }

            if (IDLagu < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
            {
                printf("Memutar lagu \"");
                TulisWordNoNL(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
                printf("\" oleh \"");
                TulisWordNoNL(daftarpenyanyi.listpenyanyi[IDPenyanyi].namaPenyanyi);
                printf("\"\n");
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
    printf("Masukkan ID Playlist: ");
    STARTINPCOMMAND(stdin);
    Word input = toKata(currentLine.kalimat);
    int IDPlaylist = WordtoNum(input) -1;

    while (IDPlaylist <= -1 && IDPlaylist > (daftarplaylist.nEff - 1))
    {
        printf("ID Playlist tidak terdaftar!\n");
        printf("Masukkan ID Playlist: ");
        STARTINPCOMMAND(stdin);
        input = toKata(currentLine.kalimat);
        IDPlaylist = WordtoNum(input) - 1;
    }

    currentSong->playlist = daftarplaylist.namaPlaylist[IDPlaylist];
    currentSong->statusPL = 1;
    currentSong->currentplay.judul = daftarplaylist.list->First->info.Lagu.judul;
    currentSong->currentplay.album = daftarplaylist.list->First->info.Lagu.album;
    currentSong->currentplay.penyanyi = daftarplaylist.list->First->info.Lagu.penyanyi;
    currentSong->currentplay.status = 1;

    address P = daftarplaylist.list[IDPlaylist].First;
    while (Next(P) != NilNode)
    {
        enqueueQueue(queue, Next(P)->info.Lagu.judul, Next(P)->info.Lagu.album, Next(P)->info.Lagu.penyanyi);
        PushStack(history, Next(P)->info.Lagu.judul, Next(P)->info.Lagu.album, Next(P)->info.Lagu.penyanyi);
        P = Next(P);
    }

    printf("Memutar playlist \""); TulisWord(currentSong->playlist); printf("\".\n");
}