#include <stdio.h>
#include "Playlist.h"

// run playlist
// gcc -o Playlist ../../Spesifikasi/Start/Start.c ../../ADT/listdin/listdin.c ../../ADT/strukturberkait/listberkait.c ../../ADT/mesinbaris/mesinbaris.c ../../ADT/mesinkata/mesinkata.c ../../ADT/mesinkarakter/mesinkarakter.c ../../ADT/list/list.c ../../ADT/map/map.c ../../ADT//set/set.c


void playlistCreate(ListofPlaylist *L){
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTINPUT(stdin);
    InsertListPlaylist(L,currentInput);
    printf("\nPlaylist ");
    TulisWordNoNL(currentInput);
    printf(" berhasil dibuat!\n\n");
    printf("Silahkan \nmasukkan lagu - lagu artis terkini kesayangan Anda!\n\n");

}

void playlistAddSong(ListofPlaylist L,ListofPenyanyi LP){
    infoLagu lagu;
    printf("\nDaftar Penyanyi : \n");
    DisplayListPenyanyi(LP);
    printf("\nMasukkan Nama Penyanyi yang dipilih : ");

    STARTINPUT(stdin);
    Word penyanyi = currentInput;
    int IDPenyanyi = IndeksPenyanyi(LP,penyanyi);


    while (!isMemberPenyanyi(LP,penyanyi)){
        printf("Nama penyanyi tidak terdaftar!\n");
        printf("\nMasukkan nama penyanyi yang dipilih: ");
        STARTINPUT(stdin);
        penyanyi = currentInput;
        IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
        printf("Penyanyi >> ");
        TulisWord(penyanyi);

    }
    if (isMemberPenyanyi(LP,penyanyi)){
        lagu.Lagu.penyanyi = currentInput;
        printf("\nDaftar Album oleh ");
        TulisWordNoNL(penyanyi);
        printf(" :\n");
        DisplayListAlbum(LP.listpenyanyi[IDPenyanyi].album);
        printf("\nMasukkan Judul Album yang dipilih : ");

        STARTINPUT(stdin);
        Word namaAlbum = currentInput;
        int IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum);
        

        while (!IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            printf("Nama album tidak terdaftar!\n");
            printf("\nMasukkan nama album yang dipilih: ");
            STARTINPUT(stdin);
            namaAlbum = currentInput;
            IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album, namaAlbum);
            
        }

        if (IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            lagu.Lagu.album = currentInput;
            printf("\nDaftar Lagu Album ");
            TulisWordNoNL(namaAlbum);
            printf(" oleh ");
            TulisWord(penyanyi);
            DisplayListLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu);

            printf("\nMasukkan ID lagu yang dipilih: ");
            STARTINPUT(stdin);
            int IDLagu = WordtoNum(currentInput)-1;
            
            Word judulLagu = IndeksSong(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,IDLagu);

            while (!IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)){
                printf("ID Lagu tidak terdaftar!\n");
                printf("\nMasukkan ID lagu yang dipilih: ");
                STARTINPUT(stdin);
                
                IDLagu = WordtoNum(currentInput)-1;
                judulLagu = IndeksSong(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,IDLagu);
                
            }

            if (IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)){
            
                printf("Nama Lagu >>> ");
                TulisWord(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
                lagu.Lagu.judul = LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                printf("Daftar Playlist Pengguna :\n");
                DisplayListPlaylist(&L);
                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTINPUT(stdin);
            
                int IDPlaylist = WordtoNum(currentInput)-1;
                Word namaPlaylist = GetListPlaylist(L,IDPlaylist);
            
                while (!isMemberListPlaylist(L,namaPlaylist)){
                    printf("ID Playlist tidak terdaftar!\n");
                    printf("\nMasukkan ID Playlist yang dipilih: ");
                    STARTINPUT(stdin);
                    IDPlaylist = WordtoNum(currentInput)-1;
                    namaPlaylist = GetListPlaylist(L,IDPlaylist);
                }
                if (isMemberListPlaylist(L,namaPlaylist)){
                    lagu.Lagu.status = 0;
                    InsVLast(&L.list[IDPlaylist],lagu);
                    printf("\nLagu dengan judul ");
                    printf("'");
                    TulisWordNoNL(judulLagu);
                    printf("'");
                    printf(" pada album ");
                    TulisWordNoNL(namaAlbum);
                    printf(" oleh penyanyi ");
                    TulisWordNoNL(penyanyi);
                    printf(" berhasil ditambahkan ke dalam playlist ");
                    TulisWordNoNL(namaPlaylist);
                    printf(".\n\n");                
                }

            }
        }


    }

}
void playlistAddAlbum(ListofPlaylist L,ListofPenyanyi LP){
    infoLagu lagu;
    printf("\nDaftar Penyanyi : \n");
    DisplayListPenyanyi(LP);
    printf("\nMasukkan Nama Penyanyi yang dipilih : ");

    STARTINPUT(stdin);
    Word penyanyi = currentInput;
    int IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
    

    while (!isMemberPenyanyi(LP,penyanyi)){
        printf("Nama penyanyi tidak terdaftar!\n");
        printf("\nMasukkan nama penyanyi yang dipilih: ");
        STARTINPUT(stdin);
        penyanyi = currentInput;
        IDPenyanyi = IndeksPenyanyi(LP,penyanyi);

    }
    if (isMemberPenyanyi(LP,penyanyi)){
        lagu.Lagu.penyanyi = currentInput;
        printf("\nDaftar Album oleh ");
        TulisWordNoNL(penyanyi);
        printf(" :\n");
        DisplayListAlbum(LP.listpenyanyi[IDPenyanyi].album);
        printf("\nMasukkan Judul Album yang dipilih : ");

        STARTINPUT(stdin);
        Word namaAlbum = currentInput;
        int IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum);
        

        while (!IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            printf("Nama album tidak terdaftar!\n");
            printf("\nMasukkan nama album yang dipilih: ");
            STARTINPUT(stdin);
            namaAlbum = currentInput;
            IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album, namaAlbum);
            
        }
        if (IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
                lagu.Lagu.album = currentInput;
                printf("Daftar Playlist Pengguna :\n");
                DisplayListPlaylist(&L);
                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTINPUT(stdin);
            
                int IDPlaylist = WordtoNum(currentInput)-1;
                Word namaPlaylist = GetListPlaylist(L,IDPlaylist);
            
                while (!isMemberListPlaylist(L,namaPlaylist)){
                    printf("ID Playlist tidak terdaftar!\n");
                    printf("\nMasukkan ID Playlist yang dipilih: ");
                    STARTINPUT(stdin);
                    IDPlaylist = WordtoNum(currentInput)-1;
                    namaPlaylist = GetListPlaylist(L,IDPlaylist);
                }
                if (isMemberListPlaylist(L,namaPlaylist)){
                    lagu.Lagu.status = 0;
                    InsVLast(&L.list[IDPlaylist],lagu);
                    printf("\nAlbum dengan judul ");
                    printf("'");
                    TulisWordNoNL(namaAlbum);
                    printf("'");
                    printf(" berhasil ditambahkan ke dalam playlist ");
                    TulisWordNoNL(namaPlaylist);
                    printf(".\n\n");           
                }

            
        }
    }


}
void playlistSwap(ListofPlaylist *L,int idx,int x,int y){
    ElmtList *p1  =L->list[idx].First; 
    ElmtList *p2  =L->list[idx].First;

    for (int i = 0; i < x;i ++){
        p1 = p1->next;
    }
    for (int i = 0; i < y;i ++){
        p2 = p2->next;
    }

    Song temp = p1->info.Lagu;
    p1->info.Lagu = p2->info.Lagu;
    p2->info.Lagu = temp;

    printf("Berhasil menukar lagu dengan nama '");
    TulisWordNoNL(p1->info.Lagu.judul);
    printf("' dengan '");
    TulisWordNoNL(p2->info.Lagu.judul);
    printf("' di playlist '");
    TulisWordNoNL(*(L->namaPlaylist));
    printf("'.\n");

}
void playlistRemove(ListofPlaylist *L,int rowsong,int idx){
    ElmtList *p = L->list[idx].First;
    ElmtList *prev = NULL;

    for (int i = 0;i <rowsong && p != NULL;i++){
        prev = p;
        p =p->next;
    }
    if (prev == NULL){
        L->list[idx].First = p->next;
    } else{
        prev->next = p->next;
    }
    Dealokasi(&p);


}
void playlistDelete(ListofPlaylist *L){
    printf("Daftar Playlist Pengguna : \n");
    DisplayListPlaylist(L);

    int i = 0;
    printf("\nMasukkan ID Playlist yang dipilih : ");
    STARTINPUT(stdin);
    // TulisWord(currentInput);
    int IDPlaylist = WordtoNum(currentInput);

    printf("Playlist : \n");
    // TulisWord(GetListPlaylist(*L,IDPlaylist-1));

    // ElmtList *curr = L->list;
    // ElmtList *prev = NULL;


    
    // printf("ID Playlist : %d\n",IDPlaylist);
    // printf("Neff : %d\n",L->nEff);
    for (i = 0; i < IDPlaylist; i++){
        // prev = curr;
        // curr = curr->next;
        TulisWord(L->namaPlaylist[i]);
    }
    TulisWord(GetListPlaylist(*L,i));
    printf("...\n");

    // if (prev != NULL){
    //     prev->next = curr->next;
    // } else{
    //     L->list->First = curr->next;
    //     printf("Q\n");
    // }
    // Dealokasi(&curr);
    L->nEff--;
}



