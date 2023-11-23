#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void queueSong (ListofPenyanyi daftarpenyanyi, Queue * queue)
{
    if (!IsFullQueue(*queue))
    {
        printf("Daftar Penyanyi:\n");
        for (int i = 0; i < BanyakPenyanyi(daftarpenyanyi); i++)
        {
            printf("%d. ", i+1);
            TulisWord(daftarpenyanyi.listpenyanyi[i].namaPenyanyi);
        }

        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTWORD(stdin);
        int IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, currentWord);

        while (IDPenyanyi == -1)
        {
            printf("Nama penyanyi tidak terdaftar!\n");
            printf("Masukkan nama penyanyi yang dipilih: ");
            STARTWORD(stdin);
            IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, currentWord);
        }

        if (IDPenyanyi != -1)
        {
            printf("Daftar Album:\n");
            for (int j = 0; j < BanyakAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album); j++)
            {
                printf("%d. ", j+1);
                TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[j].namaAlbum);
            }

            printf("Masukkan nama album yang dipilih: ");
            STARTWORD(stdin);
            int IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, currentWord);
            
            while (IDAlbum == -1)
            {
                printf("Nama album tidak terdaftar!\n");
                printf("Masukkan nama album yang dipilih: ");
                STARTWORD(stdin);
                IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, currentWord);
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
                STARTWORD(stdin);
                int IDLagu = WordtoNum(currentWord) - 1;

                while (IDLagu <= -1 && IDLagu > BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
                {
                    printf("ID Lagu tidak terdaftar!\n");
                    printf("Masukkan ID lagu yang dipilih: ");
                    STARTWORD(stdin);
                    IDLagu = WordtoNum(currentWord) - 1;
                }

                if (IDLagu < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
                {
                    Word song = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                    Word album = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].namaAlbum;
                    Word singer = daftarpenyanyi.listpenyanyi[IDPenyanyi].namaPenyanyi;
                    enqueueQueue(queue, song, album, singer);

                    printf("Menambahkan lagu. . .\n");
                    printf("Berhasil menambahkan lagu \""); TulisWordNoNL(song);
                    printf("\" oleh \""); TulisWordNoNL(singer); printf("\" ke queue.\n");
                }
            }
        }
    }

    else
    {
        printf("Queue penuh. Tidak dapat menambahkan lagu ke queue.\n");
    }
}

void queuePlaylist();

void queueSwap (Queue * queue, int id1, int id2)
{
    int idx1 = id1-1;
    int idx2 = id2-1;

    if ((idx1 < 0 || idx1 > (*queue).idxTail) && (idx2 < 0 || idx2 > (*queue).idxTail))
    {
        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu dengan urutan ke %d dan %d tidak ada.\n", id1, id2);
    }
    else if (idx1 < 0 || idx1 > (*queue).idxTail)
    {
        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id1);
    }
    else if (idx2 < 0 || idx2 > (*queue).idxTail)
    {
        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
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

        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu \""); TulisWordNoNL((*queue).song[idx2]); 
        printf("\" berhasil ditukar dengan \""); TulisWordNoNL((*queue).song[idx1]); printf("\".");
    }
}

void queueRemove (Queue * queue, int id)
{
    int idx = id-1;
    if (idx < 0 || idx > (*queue).idxTail)
    {
        printf("Mencari lagu dengan urutan ke %d dalam queue. . .\n", id);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
    }
    else
    {
        Word song = (*queue).song[idx];
        Word album = (*queue).album[idx];
        Word singer = (*queue).singer[idx];
        dequeueSong(queue, id); 
        printf("Mencari lagu dengan urutan ke %d dalam queue. . .\n", id);
        printf("Lagu \""); TulisWordNoNL(song);
        printf("\" oleh \""); TulisWordNoNL(singer);
        printf("\" telah dihapus dari queue.\n");
    }
}

void queueClear (Queue * queue)
{
    CreateEmptyQueue(queue);
    printf("Mengosongkan queue. . .\n");
    printf("Queue berhasil dikosongkan.\n");
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