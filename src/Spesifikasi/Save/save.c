#include <stdio.h>
#include <stdlib.h>
#include "Save.h"

static FILE *pita;

void Save(ListofPenyanyi *LP,const char *filename){
    const char *parent_dir = "../save";
    char path[255];
    snprintf(path,sizeof(path),"%s/%s",parent_dir,filename);

    pita = fopen(path,"w");

    if (pita == NULL){
        printf("GAGAL MENYIMPAN FILE");        
    }

    fprintf(pita,"%d\n",BanyakPenyanyi(*LP));

    for(int i = 0; i < BanyakPenyanyi(*LP);i++){
        // currentWord = LP->listpenyanyi[i].namaPenyanyi;
        CopyWordToVar(&currentWord,LP->listpenyanyi[i].namaPenyanyi);
        // fprintf(pita,"panjang kata penyanyi = %d\n",currentWord.Length);
        fprintf(pita,"%d %s\n",BanyakAlbum(LP->listpenyanyi[i].album),currentWord.TabWord);
        ResetWord();
        for (int j = 0; j < BanyakAlbum(LP->listpenyanyi[i].album);j++){
            // currentWord = LP->listpenyanyi[i].album.listalbum[j].namaAlbum;
            CopyWordToVar(&currentWord,LP->listpenyanyi[i].album.listalbum[j].namaAlbum);
            // fprintf(pita,"panjang kata album = %d\n",currentWord.Length);
            fprintf(pita,"%d %s\n",BanyakLagu(LP->listpenyanyi[i].album.listalbum[j].listlagu),currentWord.TabWord);
            ResetWord();
            for (int k = 0; k < BanyakLagu(LP->listpenyanyi[i].album.listalbum[j].listlagu);k++){
                // currentWord = LP->listpenyanyi[i].album.listalbum[j].listlagu.Lagu[k].judul;
                CopyWordToVar(&currentWord,LP->listpenyanyi[i].album.listalbum[j].listlagu.Lagu[k].judul);
                // fprintf(pita,"panjang kata lagu = %d\n",currentWord.Length);
                fprintf(pita,"%s\n",currentWord.TabWord);
                ResetWord();
            }
        }
    }
}

// int main(){
//     ListofPenyanyi mySingers = MakeList();

//     // Add the first singer
//     Word singer1 = toKata("Marcellinoooooo");
//     AddPenyanyi(&mySingers, singer1);

//     // Add albums for the first singer
//     MapofAlbum albums1 = CreateEmptyAlbum();
//     Word album1_1 = toKata("Me");
//     Word album1_2 = toKata("You");

//     AddAlbum(&albums1, album1_1);
//     AddAlbum(&albums1, album1_2);

//     // Add songs for each album
//     SetofSong songs1_1 = CreateEmptySet();
//     Word song1_1_1 = toKata("Sendiri");
//     Word song1_1_2 = toKata("Berdua");
//     Word song1_1_3 = toKata("Berdiri");

//     AddLagu(&songs1_1, song1_1_1);
//     AddLagu(&songs1_1, song1_1_2);
//     AddLagu(&songs1_1, song1_1_3);

//     SetofSong songs1_2 = CreateEmptySet();
//     Word song1_2_1 = toKata("Jalan Kaki");
//     Word song1_2_2 = toKata("Jalan Jalan");
//     Word song1_2_3 = toKata("Kaki Jalan");

//     AddLagu(&songs1_2, song1_2_1);
//     AddLagu(&songs1_2, song1_2_2);
//     AddLagu(&songs1_2, song1_2_3);

//     // Add albums to the singer
//     int singerIndex1 = IndeksPenyanyi(mySingers, singer1);
//     mySingers.listpenyanyi[singerIndex1].album = albums1;

//     // Add Songs to the album
//     mySingers.listpenyanyi[singerIndex1].album.listalbum[0].listlagu = songs1_1;
//     mySingers.listpenyanyi[singerIndex1].album.listalbum[1].listlagu = songs1_2;

//     // Add the second singer
//     Word singer2 = toKata("Afnan");
//     AddPenyanyi(&mySingers, singer2);

//     // Add albums for the second singer
//     MapofAlbum albums2 = CreateEmptyAlbum();
//     Word album2_1 = toKata("Cimahi Type Beat");
//     Word album2_2 = toKata("Afnan VS Everybody");

//     AddAlbum(&albums2, album2_1);
//     AddAlbum(&albums2, album2_2);

//     // Add songs for each album
//     SetofSong songs2_1 = CreateEmptySet();
//     Word song2_1_1 = toKata("Cimahi");
//     Word song2_1_2 = toKata("Rumah");
//     Word song2_1_3 = toKata("Motor");

//     AddLagu(&songs2_1, song2_1_1);
//     AddLagu(&songs2_1, song2_1_2);
//     AddLagu(&songs2_1, song2_1_3);

//     SetofSong songs2_2 = CreateEmptySet();
//     Word song2_2_1 = toKata("Kirik");
//     Word song2_2_2 = toKata("Jalan");
//     Word song2_2_3 = toKata("Kiw, Ares!");

//     AddLagu(&songs2_2, song2_2_1);
//     AddLagu(&songs2_2, song2_2_2);
//     AddLagu(&songs2_2, song2_2_3);


//     int singerIndex2 = IndeksPenyanyi(mySingers, singer2);
//     mySingers.listpenyanyi[singerIndex2].album = albums2;

//     mySingers.listpenyanyi[singerIndex2].album.listalbum[0].listlagu = songs2_1;
//     mySingers.listpenyanyi[singerIndex2].album.listalbum[1].listlagu = songs2_2;

//     Save(&mySingers,"TestSaveMarcell.txt");

//     return 0;
// }