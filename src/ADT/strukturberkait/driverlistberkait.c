#include <stdio.h>
#include "listberkait.c"
#include "../mesinbaris/mesinbaris.c"
#include "../mesinkarakter/mesinkarakter.c"
#include "../mesinkata/mesinkata.c"
#include "../list/list.c"
#include "../map/map.c"
#include "../set/set.c"

int main(){

    ListBerkait playlistMarcell;

    CreateEmptyPlaylist(&playlistMarcell);

    
    

    //----------MASUKIN INFO LAGU KE DALAM LINKED LSIT
    infoLagu a = {toKata("Alstrukdat"),toKata("STI vs IF"),toKata("Jason"),0};
    infoLagu b = {toKata("cimahitypebeat"),toKata("STI"),toKata("Afnan"),0};
    infoLagu c = {toKata("PinkVenom"),toKata("BORN PINK"),toKata("BLACKPINk"),0};
    infoLagu d = {toKata("R U Mine?"),toKata("AM"),toKata("Arctic Monkeys"),0};
    infoLagu e = {toKata("Lagu untuk Dia"),toKata("Cibubur"),toKata("Marcell"),0};
    InsVFirst(&playlistMarcell,a);
    InsVLast(&playlistMarcell,b);
    InsVLast(&playlistMarcell,c);
    InsVLast(&playlistMarcell,d);
    InsVLast(&playlistMarcell,e);
    printf("\n==================playlistMarcell(banyak isi playlist = %d)=======\n",NbElmtListBerkait(playlistMarcell));
    PrintNode(playlistMarcell);
    printf("\n================================================================\n");

    printf("\n");


    //----------CEK KEBERADAAN ELEMENT DI DALAM LINKED LIST
    printf("Apakah BLACKPINK ada di dalam playlistMarcell?\n");
    printf("---> %d \n",isPenyanyiAvail(playlistMarcell,c));
    printf("Apakah Marcell ada di dalam playlistMarcell?\n");
    printf("---> %d \n",isPenyanyiAvail(playlistMarcell,e));
    
    printf("Apakah lagu R U Mine? Arctic Monkeys di album AM  ada di dalam playlistMarcell?\n");
    printf("---> %d \n",isSongAvail(playlistMarcell,d));
    printf("Apakah lagu Lagu untuk Dia Marcell di album Cibubur  ada di dalam playlistMarcell?\n");
    printf("---> %d \n",isSongAvail(playlistMarcell,e));
    
    printf("Apakah album STI vs IF  ada di dalam playlistMarcell?\n");
    printf("---> %d \n",isAlbumAvail(playlistMarcell,a));
    printf("Apakah album Cibubur  ada di dalam playlistMarcell?\n");
    printf("---> %d \n",isAlbumAvail(playlistMarcell,e));

    printf("PRINT ISI LAGU :\n");
    address p = playlistMarcell.First;
    while (p != NilNode){
        TulisWord(p->info.Lagu.album);
        TulisWord(p->info.Lagu.judul);
        TulisWord(p->info.Lagu.penyanyi);
        p = p->next;
    }
    

    
    return 0;
}