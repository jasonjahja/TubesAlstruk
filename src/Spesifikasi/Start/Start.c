#include <stdio.h>
#include "Start.h"
#include <stdlib.h>

static FILE *pita;

//NOTE, MASIH ADA BEBERAPA PRINT YANG SALAH
//EX : ARTIC MONKEYS (FAVOURITE WORST NIGHTMARE); // nambah ini

// Sentence currentLine; // nambah ini

void startConfig(ListofPenyanyi *ListPenyanyi){
    pita = fopen("../save/config.txt","r");
    
    if (pita == NULL){
        printf("\nGagal membuka file\n");
    }

    STARTFILE(pita);
    int jumlahpenyanyi = atoi(currentLine.kalimat);    
    
    for(int i = 0 ;i < jumlahpenyanyi;i++){
        ADVWORD();
        int jumlahAlbum = WordtoNum(currentWord);  
        ADVSENTENCE();
        AddPenyanyi(ListPenyanyi, toKata(currentLine.kalimat));
        // printf("penyanyi %s: %d\n", currentLine.kalimat, currentLine.lengthsentence);
      
        for (int j = 0; j<jumlahAlbum;j++){
            ADVWORD();
            int banyakLagu = WordtoNum(currentWord);

            ADVSENTENCE();
            AddAlbum(&(ListPenyanyi->listpenyanyi[i].album), toKata(currentLine.kalimat)); 
            // printf("album %s: %d\n", currentLine.kalimat, currentLine.lengthsentence);   
   
            for(int k = 0; k<banyakLagu;k++){
                ADVSENTENCE();
                AddLagu(&(ListPenyanyi->listpenyanyi[i].album.listalbum[j].listlagu), toKata(currentLine.kalimat));
                // printf("lagu %s: %d\n", currentLine.kalimat, currentLine.lengthsentence);
            }
        }
    }
    fclose(pita);
    printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
    // printf("\n");
    // printf("Jumlah Penyanyi: %d\n", BanyakPenyanyi(*ListPenyanyi));
    // printf("LIST PENYANYI : \n");
    // DisplayListPenyanyi(*ListPenyanyi);
    // printf("\n");
    // printf("Jumlah Album: %d\n", BanyakAlbum((ListPenyanyi->listpenyanyi[1].album)));
    // printf("LIST ALBUM ARTICMONKEY: \n");
    // DisplayListAlbum((ListPenyanyi->listpenyanyi[1].album));
    // printf("\n");
    // printf("LIST LAGU FAVORITTAITAITAI: \n");
    // printf("Jumlah Lagu: %d\n", BanyakLagu((ListPenyanyi->listpenyanyi[0].album.listalbum[1].listlagu)));
    // DisplayListLagu((ListPenyanyi->listpenyanyi[0].album.listalbum[1].listlagu));
    // printf("\n");
    
    fclose(pita);
}