#include <stdio.h>
#include "Playlist.h"

// run playlist
// gcc -o Playlist ../../Spesifikasi/Start/Start.c ../../ADT/listdin/listdin.c ../../ADT/strukturberkait/listberkait.c ../../ADT/mesinbaris/mesinbaris.c ../../ADT/mesinkata/mesinkata.c ../../ADT/mesinkarakter/mesinkarakter.c ../../ADT/list/list.c ../../ADT/map/map.c ../../ADT//set/set.c


void playlistCreate(ListofPlaylist *L){
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTINPUT(stdin);
    while (isMemberListPlaylist(*L,currentInput)){
        printf("Nama Playlist sudah ada, masukkan nama lain\n");
        printf("\nMasukkan nama playlist yang ingin dibuat : ");
        STARTINPUT(stdin);
    }
    

    if(!isMemberListPlaylist(*L,currentInput)){
        InsertListPlaylist(L,currentInput);
        printf("\nPlaylist ");
        TulisWordNoNL(currentInput);
        printf(" berhasil dibuat!\n\n");
        printf("Silahkan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n");
    } 

}

void playlistAddSong(ListofPlaylist L,ListofPenyanyi LP){
    if (isEmptyListPlaylist(L)) {
        printf("\nTidak ada playlist yang tersedia!\n\n");
    } else {
        infoLagu lagu;
        printf("\nDaftar Penyanyi : \n");
        DisplayListPenyanyi(LP);
        printf("\nMasukkan Nama Penyanyi yang dipilih : ");

        STARTINPUT(stdin);
        Word penyanyi = currentInput;
        int IDPenyanyi = IndeksPenyanyi(LP,penyanyi);


        while (!isMemberPenyanyi(LP,penyanyi)){
            printf("\nNama penyanyi tidak terdaftar!\n");
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
                printf("\nNama album tidak terdaftar!\n");
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
                    printf("\nID Lagu tidak terdaftar!\n");
                    printf("\nMasukkan ID lagu yang dipilih: ");
                    STARTINPUT(stdin);
                    
                    IDLagu = WordtoNum(currentInput)-1;
                    judulLagu = IndeksSong(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,IDLagu);
                }

                if (IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)) {
                    lagu.Lagu.judul = LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                    printf("\nDaftar Playlist Pengguna :\n");
                    DisplayListPlaylist(&L);
                    printf("\nMasukkan ID Playlist yang dipilih : ");
                    STARTINPUT(stdin);
                
                    int IDPlaylist = WordtoNum(currentInput)-1;
                    Word namaPlaylist = GetListPlaylist(L,IDPlaylist);
                
                    while (!isMemberListPlaylist(L,namaPlaylist)){
                        printf("\nID Playlist tidak terdaftar!\n");
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
}

void playlistAddAlbum(ListofPlaylist L,ListofPenyanyi LP){
    if (isEmptyListPlaylist(L)) {
        printf("\nTidak ada playlist yang tersedia!\n\n");
    } else {
        infoLagu lagu;
        printf("\nDaftar Penyanyi : \n");
        DisplayListPenyanyi(LP);
        printf("\nMasukkan Nama Penyanyi yang dipilih : ");

        STARTINPUT(stdin);
        Word penyanyi = currentInput;
        int IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
        

        while (!isMemberPenyanyi(LP,penyanyi)){
            printf("\nNama penyanyi tidak terdaftar!\n");
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
                printf("\nNama album tidak terdaftar!\n");
                printf("\nMasukkan nama album yang dipilih: ");
                STARTINPUT(stdin);
                namaAlbum = currentInput;
                IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album, namaAlbum);
                
            }
            if (IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
                lagu.Lagu.album = currentInput;
                printf("\nDaftar Playlist Pengguna :\n");
                DisplayListPlaylist(&L);
                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTINPUT(stdin);
            
                int IDPlaylist = WordtoNum(currentInput)-1;
                Word namaPlaylist = GetListPlaylist(L,IDPlaylist);
            
                while (!isMemberListPlaylist(L,namaPlaylist)){
                    printf("\nID Playlist tidak terdaftar!\n");
                    printf("\nMasukkan ID Playlist yang dipilih: ");
                    STARTINPUT(stdin);
                    IDPlaylist = WordtoNum(currentInput)-1;
                    namaPlaylist = GetListPlaylist(L,IDPlaylist);
                }
                if (isMemberListPlaylist(L,namaPlaylist)){
                    lagu.Lagu.status = 0;
                    // InsVLast(&L.list[IDPlaylist],lagu);
                    infoLagu x;
                    int nLagu = BanyakLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu);
                
                    for (int i = 0;i < nLagu;i++){
                            // x.Lagu.album = LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[i].album;
                            x.Lagu.album = lagu.Lagu.album;
                            x.Lagu.judul = LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[i].judul;
                            x.Lagu.penyanyi = lagu.Lagu.penyanyi;
                            // x.Lagu.penyanyi = LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[i].penyanyi;
                            InsVLast(&L.list[IDPlaylist],x);
                        } 

                    }

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

void playlistSwap(ListofPlaylist *L, int idx, int x, int y) {
    ElmtList *p1 = L->list[idx - 1].First;
    ElmtList *p2 = L->list[idx - 1].First;

    // Move to the x-th node
    for (int i = 0; i < x && p1 != NULL; i++) {
        p1 = p1->next;
    }

    // Move to the y-th node
    for (int j = 0; j < y && p2 != NULL; j++) {
        p2 = p2->next;
    }

    // Check if both pointers are not NULL before swapping
    if (p1 != NULL && p2 != NULL) {
        Song temp = p1->info.Lagu;
        p1->info.Lagu = p2->info.Lagu;
        p2->info.Lagu = temp;

        printf("\nBerhasil menukar lagu dengan nama '");
        TulisWordNoNL(p1->info.Lagu.judul);
        printf("' dengan '");
        TulisWordNoNL(p2->info.Lagu.judul);
        printf("' di playlist '");
        TulisWordNoNL(*L->namaPlaylist);
        printf("'.\n\n");
    }
}
void playlistRemove(ListofPlaylist *L,int rowsong,int idx){
    ElmtList *p = L->list[idx-1].First;
    ElmtList *prev = NULL;

    for (int i = 0;i < rowsong-1 && p != NULL;i++){
        prev = p;
        p =p->next;
        
    }
    
    if (p != NULL){
        if (prev == NULL){
            L->list[idx-1].First = p->next;
        } else{
            prev->next = p->next;
        }
    } 
    Dealokasi(&p);
    printf("Lagu berhasil dihapus!\n");
}

void playlistDelete(ListofPlaylist *L){
    if (isEmptyListPlaylist(*L)) {
        printf("\nTidak ada playlist yang tersedia!\n\n");
    } else {
      printf("\nDaftar Playlist Pengguna : \n");
      DisplayListPlaylist(L);

      printf("\nMasukkan ID Playlist yang dipilih : ");
      STARTINPUT(stdin);
      // TulisWord(currentInput);
      int IDPlaylist = WordtoNum(currentInput);
      DeleteListPlaylist(L,IDPlaylist);
    }
    printf("Playlist berhasil dihapus!\n\n");
}



