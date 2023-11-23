#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void queueSong (ListofPenyanyi daftarpenyanyi, Queue * queue)
{
    if (!IsFullQueue(*queue))
    {
        printf("\nDaftar Penyanyi:\n");
        for (int i = 0; i < BanyakPenyanyi(daftarpenyanyi); i++)
        {
            printf("%d. ", i+1);
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
                printf("%d. ", j+1);
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
                    printf("%d. ", k+1);
                    TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[k].judul);
                }

                printf("\nMasukkan ID lagu yang dipilih: ");
                STARTINPUT(stdin);
                int IDLagu = WordtoNum(currentInput) - 1;

                while (IDLagu <= -1 && IDLagu > BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
                {
                    printf("\nID Lagu tidak terdaftar!\n");
                    printf("\nMasukkan ID lagu yang dipilih: ");
                    STARTINPUT(stdin);
                    IDLagu = WordtoNum(currentInput) - 1;
                }

                if (IDLagu < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
                {
                    Word song = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                    Word album = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].namaAlbum;
                    Word singer = daftarpenyanyi.listpenyanyi[IDPenyanyi].namaPenyanyi;
                    enqueueQueue(queue, song, album, singer);

                    printf("\nMenambahkan lagu. . .\n");
                    printf("\nBerhasil menambahkan lagu \""); TulisWordNoNL(song);
                    printf("\" oleh \""); TulisWordNoNL(singer); printf("\" ke queue.\n\n");
                }
            }
        }
    }

    else
    {
        printf("\nQueue penuh. Tidak dapat menambahkan lagu ke queue.\n\n");
    }
}

void queuePlaylist(ListofPlaylist daftarplaylist, Queue * queue)
{
    printf("\nMasukkan ID Playlist: ");
    STARTINPUT(stdin);
    int IDPlaylist = WordtoNum(currentInput) - 1;
    
    while (IDPlaylist <= -1 || IDPlaylist >= (daftarplaylist.nEff))
    {
        printf("\nID Playlist tidak terdaftar!\n");
        printf("\nMasukkan ID Playlist: ");
        STARTINPUT(stdin);
        IDPlaylist = WordtoNum(currentInput) - 1;
    }

    address P = daftarplaylist.list[IDPlaylist].First;
    int ctr = 0;

    while (P != NilNode)
    {
        ctr++;
        P = Next(P);
    }

    if ((ctr-1) > IDX_MAXQueue)
    {
        printf("\nQueue penuh! Tidak dapat menambahkan lagu ke queue\n\n");
    }
    else
    {
        P = daftarplaylist.list[IDPlaylist].First;
        while (P != NilNode)
        {
            enqueueQueue(queue, P->info.Lagu.judul, P->info.Lagu.album, P->info.Lagu.penyanyi);
            P = Next(P);
        }

        printf("\nBerhasil menambahkan playlist \""); TulisWordNoNL(daftarplaylist.namaPlaylist[IDPlaylist]); printf("\" ke queue.\n\n");
    }
}

void queueSwap (Queue * queue, int id1, int id2)
{
    int idx1 = id1-1;
    int idx2 = id2-1;

    if ((idx1 < 0 || idx1 > (*queue).idxTail) && (idx2 < 0 || idx2 > (*queue).idxTail))
    {
        printf("\nMencari lagu dengan urutan ke %d dan %d dalam queue. . .\n\n", id1, id2);
        printf("Lagu dengan urutan ke %d dan %d tidak ada.\n", id1, id2);
    }
    else if (idx1 < 0 || idx1 > (*queue).idxTail)
    {
        printf("\nMencari lagu dengan urutan ke %d dan %d dalam queue. . .\n\n", id1, id2);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id1);
    }
    else if (idx2 < 0 || idx2 > (*queue).idxTail)
    {
        printf("\nMencari lagu dengan urutan ke %d dan %d dalam queue. . .\n\n", id1, id2);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id2);
    }
    else
    {
        Song temp;
        temp.judul = (*queue).song[idx2];
        temp.album = (*queue).album[idx2];
        temp.penyanyi = (*queue).singer[idx2];

        (*queue).song[idx2] = (*queue).song[idx1];
        (*queue).album[idx2] = (*queue).album[idx1];
        (*queue).singer[idx2] = (*queue).singer[idx1];

        (*queue).song[idx1] = temp.judul;
        (*queue).album[idx1] = temp.album;
        (*queue).singer[idx1] = temp.penyanyi;

        printf("\nMencari lagu dengan urutan ke %d dan %d dalam queue. . .\n\n", id1, id2);
        printf("Lagu \""); TulisWordNoNL((*queue).song[idx2]); 
        printf("\" berhasil ditukar dengan \""); TulisWordNoNL((*queue).song[idx1]); printf("\".\n\n");
    }
}

void queueRemove (Queue * queue, int id)
{
    int idx = id-1;
    if (idx < 0 || idx > (*queue).idxTail)
    {
        printf("\nMencari lagu dengan urutan ke %d dalam queue. . .\n", id);
        printf("\nLagu dengan urutan ke %d tidak ada.\n", id);
    }
    else
    {
        Word song = (*queue).song[idx];
        Word album = (*queue).album[idx];
        Word singer = (*queue).singer[idx];
        dequeueSong(queue, id); 
        printf("\nMencari lagu dengan urutan ke %d dalam queue. . .\n", id);
        printf("\nLagu \""); TulisWordNoNL(song);
        printf("\" oleh \""); TulisWordNoNL(singer);
        printf("\" telah dihapus dari queue.\n\n");
    }
}

void queueClear (Queue * queue)
{
    CreateEmptyQueue(queue);
    printf("\nMengosongkan queue. . .\n");
    printf("\nQueue berhasil dikosongkan.\n\n");
}

void dequeueSong (Queue * queue, int id)
{
    for (int i = id-1; i < IDX_TAIL(*queue); i++)
    {
        (*queue).song[i] = (*queue).song[i+1];
        (*queue).album[i] = (*queue).album[i+1];
        (*queue).singer[i] = (*queue).singer[i+1];
    }

    (*queue).idxTail--;
}