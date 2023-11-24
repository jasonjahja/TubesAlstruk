#include <stdio.h>
#include <stdlib.h>
#include "Save.h"

static FILE *pita;

void Save(ListofPenyanyi *LP,ListofPlaylist *listPlaylist,Queue *queueLagu,songHistory *songHistory,CurrentStat *status,const char *filename){
    const char *parent_dir = "../../../save";
    char path[255];
    snprintf(path,sizeof(path),"%s/%s",parent_dir,filename);

    pita = fopen(path,"w");

    if (pita == NULL){
        printf("\nGAGAL MENYIMPAN FILE\n\n");        
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

    CopyWordToVar(&currentWord,status->currentplay.penyanyi);
    fprintf(pita,"%s;",currentWord.TabWord);
    ResetWord();

    
    CopyWordToVar(&currentWord,status->currentplay.album);
    fprintf(pita,"%s;",currentWord.TabWord);
    ResetWord();
    
    CopyWordToVar(&currentWord,status->currentplay.judul);
    fprintf(pita,"%s\n",currentWord.TabWord);
    ResetWord();

    if (queueLagu->idxTail != IDX_UNDEFQueue){
        fprintf(pita,"%d\n",queueLagu->idxTail+1);
    }
    for (int i = 0 ; i <= queueLagu->idxTail;i ++){
        CopyWordToVar(&currentWord,queueLagu->singer[i]);
        fprintf(pita,"%s;",currentWord.TabWord);
        ResetWord();

        CopyWordToVar(&currentWord,queueLagu->album[i]);
        fprintf(pita,"%s;",currentWord.TabWord);
        ResetWord();
        
        CopyWordToVar(&currentWord,queueLagu->song[i]);
        fprintf(pita,"%s\n",currentWord.TabWord);
        ResetWord();

        
    }

    if (songHistory->TOP > 0){
        fprintf(pita,"%d\n",songHistory->TOP+1);
    }

    for (int j = songHistory->TOP; j >=0;j--){
        CopyWordToVar(&currentWord,songHistory->singer[j]);
        fprintf(pita,"%s;",currentWord.TabWord);
        ResetWord();
    
        CopyWordToVar(&currentWord,songHistory->album[j]);
        fprintf(pita,"%s;",currentWord.TabWord);
        ResetWord();

        CopyWordToVar(&currentWord,songHistory->song[j]);
        fprintf(pita,"%s\n",currentWord.TabWord);
        ResetWord();
    }

    if (listPlaylist->nEff > 0){
        fprintf(pita,"%d\n",listPlaylist->nEff);
    }
    for(int k = 0; k < listPlaylist->nEff;k++){
        address p = listPlaylist->list[k].First;
        int ctr = 0;

        while (p != NilNode){
            ctr += 1;
            p = p->next;
        }

        if (ctr == 0){
            CopyWordToVar(&currentWord,listPlaylist->namaPlaylist[k]);
            fprintf(pita,"%d %s ",ctr,currentWord.TabWord);
            ResetWord();
        } else{
            CopyWordToVar(&currentWord,listPlaylist->namaPlaylist[k]);
            fprintf(pita,"%d %s\n",ctr,currentWord.TabWord);
            ResetWord();
        }

        address laguPlaylist = listPlaylist->list[k].First;

        for (int l = 0; l < ctr;l++){
            
            CopyWordToVar(&currentWord,laguPlaylist->info.Lagu.penyanyi);
            fprintf(pita,"%s;",currentWord.TabWord);
            ResetWord();
    
            
            CopyWordToVar(&currentWord,laguPlaylist->info.Lagu.album);
            fprintf(pita,"%s;",currentWord.TabWord);
            ResetWord();

            
            CopyWordToVar(&currentWord,laguPlaylist->info.Lagu.judul);
            fprintf(pita,"%s\n",currentWord.TabWord);
            ResetWord();
            laguPlaylist = laguPlaylist->next;
        }

    }
    fclose(pita);
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

//     // Queue
//     Queue playlist;
//     CreateEmptyQueue(&playlist);

//     // Enqueue some songs
//     enqueueQueue(&playlist, toKata("Alstrukdat"),toKata("STI vs IF"),toKata("Jason"));
//     enqueueQueue(&playlist, toKata("cimahitypebeat"),toKata("STI"),toKata("Afnan"));
//     enqueueQueue(&playlist, toKata("Pink Venom"),toKata("BORN PINK"),toKata("BLACKPINK"));

//     // Enqueue more songs
//     enqueueQueue(&playlist, toKata("R U Mine?"),toKata("AM"),toKata("Arctic Monkeys"));
//     enqueueQueue(&playlist, toKata("Lagu untuk Dia"),toKata("Cibubur"),toKata("Marcell"));

//     //List Berkait
//     ListBerkait playlistMarcell,playlistBersama;
//     CreateEmptyPlaylist(&playlistMarcell);
//     CreateEmptyPlaylist(&playlistBersama);
//     infoLagu a = {toKata("Alstrukdat"),toKata("STI vs IF"),toKata("Jason"),0};
//     infoLagu b = {toKata("cimahitypebeat"),toKata("STI"),toKata("Afnan"),0};
//     infoLagu c = {toKata("Pink Venom"),toKata("BORN PINK"),toKata("BLACKPINk"),0};
//     infoLagu d = {toKata("R U Mine?"),toKata("AM"),toKata("Arctic Monkeys"),0};
//     infoLagu e = {toKata("Lagu untuk Dia"),toKata("Cibubur"),toKata("Marcell"),0};
//     InsVFirst(&playlistMarcell,a);
//     InsVLast(&playlistMarcell,b);
//     InsVLast(&playlistMarcell,c);
//     InsVLast(&playlistBersama,d);
//     InsVLast(&playlistBersama,e);

//     ListofPlaylist kumpulanPlaylist = CreateListPlaylist();
//     kumpulanPlaylist.namaPlaylist[0] = toKata("playlistMarcell");
//     kumpulanPlaylist.list[0] = playlistMarcell;
//     kumpulanPlaylist.nEff++;

//     kumpulanPlaylist.namaPlaylist[1] = toKata("playlistBersama");
//     kumpulanPlaylist.list[1] = playlistBersama;
//     kumpulanPlaylist.nEff++;

//     // Add playlists to the collection


//     // SongHistory
//     songHistory historyStack;
//     CreateEmptyStack(&historyStack);

//     // Add songs to the history stack
//     PushStack(&historyStack, toKata("Song1"), toKata("Album1"), toKata("Singer1"));
//     PushStack(&historyStack, toKata("Lagu duaaaaa"), toKata("ALBUM DUAAAAAA"), toKata("NYANYI DUAAAAAA"));
//     PushStack(&historyStack, toKata("505"), toKata("Favourite Worst Nightmare"), toKata("Arctic Monkeys"));

//     // currentStat

//     ListofPenyanyi daftarpenyanyi; // Assume this is initialized with actual data
//     ListofPlaylist daftarplaylist; // Assume this is initialized with actual data
//     CurrentStat currentSong;
//     songHistory history;
//     Queue queue;

//     CreateEmptyCurrentStat(&currentSong);

//     // Example 1: Play a specific song
//     // playSong(daftarpenyanyi, &currentSong, &history, &queue);


//     Save(&mySingers,&kumpulanPlaylist,&playlist,&historyStack,&currentSong,"TestSaveMarcell.txt");

//     return 0;
// }