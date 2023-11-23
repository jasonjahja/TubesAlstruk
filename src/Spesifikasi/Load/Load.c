#include <stdio.h>
#include <stdlib.h>
#include "Load.h"

static FILE *pita;
// Sentence currentLine;

void Load(ListofPenyanyi *ListPenyanyi, CurrentStat *CS, Queue *Q, songHistory *SH, ListofPlaylist *LPl, Word CW, boolean *started) {
    const char *parent_dir = "../save";
    char path[255];
    snprintf(path,sizeof(path),"%s/%s",parent_dir,CW.TabWord);
    FILE *pita = fopen(path,"r");
    if (pita == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n\n");
        *started = false;
        fclose(pita);
    } else {
        (STARTFILE(pita));
        
        int jumlahpenyanyi = atoi(currentLine.kalimat);
        // printf(" --> jumlah PENYANYI = %d\n",jumlahpenyanyi);    

        // printf("\n LOOP JUMLAH PENYANYI \n");    
        for(int i = 0;i < jumlahpenyanyi;i++) {
            ADVWORD();
            int jumlahAlbum = WordtoNum(currentWord);
            // print jumlah album penyanyi

            ADVSENTENCE();
            // print penyanyi
            AddPenyanyi(ListPenyanyi, toKata(currentLine.kalimat));
            // di sini nanti penyanyi disimpen ke List
            // AddPenyanyi(&ListPenyanyi,currentLine.kalimat);

        
            // printf("\n LOOP JUMLAH ALBUM \n");    
            for (int j = 0; j<jumlahAlbum;j++) {
                ADVWORD();
                int banyakLagu = WordtoNum(currentWord);
                
                // Jumlah lagu di satu album
                ADVSENTENCE();
                AddAlbum(&ListPenyanyi->listpenyanyi[i].album, toKata(currentLine.kalimat));

                // Nama album

                // printf("DUARRRR!!!! = >>>");
                // di sini nanti masukin album ke Map
                // printf(" --> jumlah ALBUM = %d\n",jumlahAlbum);
                // printf("\n LOOP JUMLAH LAGU \n");    
                for(int k = 0; k<banyakLagu;k++) {
                    ADVSENTENCE();
                    // printf("lagu = %d\n",banyakLagu);
                    
                    AddLagu(&ListPenyanyi->listpenyanyi[i].album.listalbum[j].listlagu, toKata(currentLine.kalimat));
                    // printf(" --> jumlah LAGU = %d\n",banyakLagu);
                    // di sini nanti lagu disimpen ke Set
                    // InsertSet(&Lagu,currentWord);
                }
                
            }

        }
        // ADVSENTENCE();
        // DisplayListPenyanyi(ListPenyanyi);
        // printf("SELESAI\n");
        //printf("\nDUARRRR!!!! = >>>\n");

        ADVLINE(); //lanjut ke baris selanjutnya, ke lagu yang sedang dimainkan

        //CREATEEMPTYQUEUE();
        ADVRECORD();
        CS->currentplay.penyanyi = toKata(currentLine.kalimat);
        //print lagu yang sedang dimainkan, penyanyi
        //Sentence namaPenyanyi = currenLine;

        ADVRECORD();
        CS->currentplay.judul = toKata(currentLine.kalimat);
        //print lagu yang sedang dimainkan, album
        //Sentence namaAlbum = currentLine;

        ADVRECORD();
        CS->currentplay.album = toKata(currentLine.kalimat);
        //print lagu yang sedang dimainkan, lagu
        //Sentence namaLagu = currentLine;
        //enqueueQueue(INISIALISASIQUEUE, namaPenyanyi, namaAlbum, namaLagu);

        ADVWORD(); //lanjut ke baris selanjutnya

        int rQueue = WordtoNum(currentWord);

        //printf("\nJUMLAH RIWAYAT LAGU DALAM QUEUE:");
        // print jumlah riwayat lagu dalam queue

        ADVLINE(); //lanjut ke baris selanjutnya, isi riwayat lagu dalam queue

        //printf("\nLOOP RIWAYAT LAGU:\n");
        for (int l = 0; l < rQueue; l++) {
            ADVRECORD();
            Q->singer[l] = toKata(currentLine.kalimat);
            //Sentence namaPenyanyi = currentLine;
            

            ADVRECORD();
            Q->album[l] = toKata(currentLine.kalimat);
            //Sentence namaAlbum = currentLine;
            

            ADVRECORD();
            Q->song[l] = toKata(currentLine.kalimat);
            //Sentence namaLagu = currentLine;
            

            //enqueueQueue(INISIALISASIQUEUE, namaPenyanyi, namaAlbum, namaLagu);

            ADVLINE(); //lanjut ke lagu selanjutnya yang isinya riwayat lagu dalam queue
            //printf("\n=====\n");
        }
        
        ADVWORD(); //lanjut ke baris jumlah record riwayat pemutaran lagu
        int rPemutarLagu = WordtoNum(currentWord);

        //printf("\nJUMLAH RECORD RIWAYAT PEMUTARAN LAGU:");
        // print jumlah record riwayat pemutaran lagu

        ADVLINE(); //lanjut ke baris selanjutnya, isi riwayat pemutaran lagu

        //CREATEEMPTYSTACK();
        //printf("\nLOOP RECORD RIWAYAT PEMUTARAN LAGU:\n");
        for (int m = 0; m < rPemutarLagu; m++) {
            ADVRECORD(); 
            SH->singer[m] = toKata(currentLine.kalimat);
            //Sentence namaPenyanyi = currentLine;
            

            ADVRECORD(); 
            SH->album[m] = toKata(currentLine.kalimat);
            //Sentence namaAlbum = currentLine;
            

            ADVRECORD(); 
            SH->song[m] = toKata(currentLine.kalimat);
            //Sentence namaLagu = currentLine;
            

            //PushStack(INISIALISASISTACK, namaPenyanyi, namaAlbum, namaLagu);

            ADVLINE(); //lanjut ke baris selanjutnya
        }

        ADVWORD();
        int jPlaylist = WordtoNum(currentWord); //jumlah playlist
        //printf("\nLOOP JUMLAH PLAYLIST:");
        //print jumlah playlist

        //CreateListDin();
        for (int n = 0; n < jPlaylist; n++) {
            ADVWORD();
            int jLagu = WordtoNum(currentWord); //jumlah lagu dalam playlist
            //printf("\nJUMLAH LAGU DALAM PLAYLIST:");
            //print jumlah lagu dalam playlist

            ADVSENTENCE();
            LPl->namaPlaylist[n] = toKata(currentLine.kalimat);
            //print nama playlist
            //insertLast_ListDin(currentLine);

            ADVLINE();

            //CreateEmpty(); //createempty list berkait
            //printf("\nLOOP NAMA LAGU:\n");

            // for (int o = 0; o < jLagu; o++) {
            address p = LPl->list[n].First;
            while(p != NilNode){
                //infoType Data
                ADVRECORD(); TulisKalimat(currentLine);
                Word singer = toKata(currentLine.kalimat);
                //Data.namaPenyanyi = currentLine;
                
                ADVRECORD(); TulisKalimat(currentLine);
                Word album = toKata(currentLine.kalimat);
                //Data.namaAlbum = currentLine;
                

                ADVRECORD(); TulisKalimat(currentLine);
                Word song = toKata(currentLine.kalimat);
                //Data.namaLagu = currentLine;
                
                //InsVLast();

                infoLagu x;
                x.Lagu.judul = song;
                x.Lagu.penyanyi = singer;
                x.Lagu.album = album;


                InsVLast(&((*LPl).list[n]), x);
                ADVLINE();
                p = Next(p); 
            }
        }

        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n\n");

        // printf("\n");
        // DisplayListPenyanyi(*ListPenyanyi);
        // printf("%s\n", ListPenyanyi->listpenyanyi[0].namaPenyanyi.TabWord);
        // printf("\n");
        // DisplayListAlbum(ListPenyanyi->listpenyanyi[1].album);
        // printf("\n");
        // DisplayListLagu(ListPenyanyi->listpenyanyi[1].album.listalbum[0].listlagu);
        // printf("\n");
        fclose(pita);
    }
}

// int main() {
//     load();
//     return 0;
// }
        // for (int a = 0; a < 3; a++) {
        //     ADVRECORD();
        //     TulisKalimat(currentLine); //agar print penyanyi;album;lagu dapat terpisah
        
        // }

            // for (int a = 0; a < 3; a++) {
            //     ADVRECORD();
            //     TulisKalimat(currentLine); //print nama nama lagu dalam playlist agar terpisah dari penyanyi;album;lagu
                
            // }