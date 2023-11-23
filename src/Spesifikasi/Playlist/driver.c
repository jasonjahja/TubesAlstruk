#include <stdio.h>
#include "Playlist.c"

int main(){

    ListBerkait playlistMarcell,playlistBersama;
    CreateEmptyPlaylist(&playlistMarcell);
    CreateEmptyPlaylist(&playlistBersama);
    infoLagu a = {toKata("Alstrukdat"),toKata("STI vs IF"),toKata("Jason"),0};
    infoLagu b = {toKata("cimahitypebeat"),toKata("STI"),toKata("Afnan"),0};
    infoLagu c = {toKata("Pink Venom"),toKata("BORN PINK"),toKata("BLACKPINk"),0};
    infoLagu d = {toKata("R U Mine?"),toKata("AM"),toKata("Arctic Monkeys"),0};
    infoLagu e = {toKata("Lagu untuk Dia"),toKata("Cibubur"),toKata("Marcell"),0};
    InsVFirst(&playlistMarcell,a);
    InsVLast(&playlistMarcell,b);
    InsVLast(&playlistMarcell,c);
    InsVLast(&playlistBersama,d);
    InsVLast(&playlistBersama,e);

    ListofPlaylist kumpulanPlaylist = CreateListPlaylist();
    kumpulanPlaylist.namaPlaylist[0] = toKata("playlistMarcell");
    kumpulanPlaylist.list[0] = playlistMarcell;
    kumpulanPlaylist.nEff++;

    kumpulanPlaylist.namaPlaylist[1] = toKata("playlistBersama");
    kumpulanPlaylist.list[1] = playlistBersama;
    kumpulanPlaylist.nEff++;

    // printf("===================LIST PLAYLIST===================\n");
    // DisplayListPlaylist(&kumpulanPlaylist);
    // printf("\n===================playlistMarcell===================\n");
    // PrintNode(playlistMarcell);
    // printf("\n===================playlistBersama===================\n");
    // PrintNode(playlistBersama);

    // printf("\n===================Menukar Lagu===================\n");
    // playlistSwap(&kumpulanPlaylist,0,1,2);
    // printf("\n===================playlistMarcell===================\n");
    // PrintNode(playlistMarcell);
    // printf("\n===================playlistBersama===================\n");
    // PrintNode(playlistBersama);

    // printf("\n===================Menghapus Lagu===================\n");
    // playlistRemove(&kumpulanPlaylist,1,1);
    // printf("\n===================playlistMarcell===================\n");
    // PrintNode(playlistMarcell);
    // printf("\n===================playlistBersama===================\n");
    // PrintNode(playlistBersama);
    // printf("\n===================Menghapus Playlist===================\n");
    // playlistDelete(&kumpulanPlaylist,1);
    // printf("===================LIST PLAYLIST===================\n");
    // DisplayListPlaylist(&kumpulanPlaylist);

    ListofPenyanyi LP = MakeList();
    InsertListPlaylist(&kumpulanPlaylist,toKata("Me"));
    InsertListPlaylist(&kumpulanPlaylist,toKata("Love"));
    InsertListPlaylist(&kumpulanPlaylist,toKata("Indo Koplo"));
    // tambahin penyanyi
    AddPenyanyi(&LP,toKata("John Mayer"));
    AddPenyanyi(&LP,toKata("NOSSTRESS"));
    AddPenyanyi(&LP,toKata("BLACKPINK"));

    // tambahin album
    // John Mayer
    AddAlbum(&LP.listpenyanyi[0].album,toKata("Continuum"));
    AddAlbum(&LP.listpenyanyi[0].album,toKata("The Search for Everything"));
    // Nosstress
    AddAlbum(&LP.listpenyanyi[1].album,toKata("Perspektif Bodoh"));
    AddAlbum(&LP.listpenyanyi[1].album,toKata("Ini Bukan Nosstress"));
    
    // BLACKPINK
    AddAlbum(&LP.listpenyanyi[2].album,toKata("BORN PINK"));

    //tambahin lagu
    //John Mayer.Continuum
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("Gravity"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("Slow Dancing in a Burning Room"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("Belief"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("The Heart of Life"));
    // DisplayListLagu(LP.listpenyanyi[0].album.listalbum[0].listlagu);
    //John Mayer.The Search for Everything
    
    AddLagu(&LP.listpenyanyi[0].album.listalbum[1].listlagu,toKata("Still Feel Like Your Man"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[1].listlagu,toKata("In The Blood"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[1].listlagu,toKata("Moving On and Getting Over"));
    // DisplayListLagu(LP.listpenyanyi[0].album.listalbum[1].listlagu);
    //Nosstress.Perspektif Bodoh
    
    AddLagu(&LP.listpenyanyi[1].album.listalbum[0].listlagu,toKata("Pegang Tanganku"));
    AddLagu(&LP.listpenyanyi[1].album.listalbum[0].listlagu,toKata("Laguku Untukmu"));
    // DisplayListLagu(LP.listpenyanyi[1].album.listalbum[0].listlagu);
    //Nosstress.Ini Bukan Nosstress
    
    AddLagu(&LP.listpenyanyi[1].album.listalbum[1].listlagu,toKata("Semoga Ya"));
    AddLagu(&LP.listpenyanyi[1].album.listalbum[1].listlagu,toKata("Ya, Kamu"));
    // DisplayListLagu(LP.listpenyanyi[1].album.listalbum[1].listlagu);
    //BLACKPINK.BORN PINK
    
    AddLagu(&LP.listpenyanyi[2].album.listalbum[0].listlagu,toKata("Pink Venom"));
    AddLagu(&LP.listpenyanyi[2].album.listalbum[0].listlagu,toKata("Shut Down"));
    AddLagu(&LP.listpenyanyi[2].album.listalbum[0].listlagu,toKata("Tally"));
    // DisplayListLagu(LP.listpenyanyi[2].album.listalbum[0].listlagu);
    // playlistAddSong(kumpulanPlaylist,LP);
    // printf("\n=========================PLAYLIST=========================\n");
    // DisplayListPlaylist(&kumpulanPlaylist);
    // printf("ID Playlist >> ");
    // STARTINPUT(stdin);
    // Word namaPlaylist = GetListPlaylist(kumpulanPlaylist,IDPlaylist);
    // printf("\n=========================ISI PLAYLIST=========================\n");
    // PrintNode(kumpulanPlaylist.list[IDPlaylist]);


    printf("\n=========================PLAYLIST=========================\n");
    printf("banyak playlist = %d\n",kumpulanPlaylist.nEff);
    DisplayListPlaylist(&kumpulanPlaylist);

    // printf("\nDELETE PLAYLIST\n");
    playlistDelete(&kumpulanPlaylist);

    printf("\nPLAYLIST ADD ALBUM\n");
    // playlistAddAlbum(kumpulanPlaylist,LP);
    

    // printf("ID Playlist >> ");
    // STARTINPUT(stdin);
    // int IDPlaylist = WordtoNum(toKata(currentLine.kalimat))-1;
    // IDPlaylist = WordtoNum(toKata(currentLine.kalimat))-1;
    // // namaPlaylist = GetListPlaylist(kumpulanPlaylist,IDPlaylist);
    printf("\n=========================PLAYLIST=========================\n");
    DisplayListPlaylist(&kumpulanPlaylist);
    // PrintNode(kumpulanPlaylist.list[IDPlaylist]);
    return 0;
}