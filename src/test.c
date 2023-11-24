// gcc -o driver Spesifikasi/Start/Start.c Spesifikasi/Help/Help.c Spesifikasi/List/List.c Spesifikasi/Play/Play.c Spesifikasi/Queue/Queue.c Spesifikasi/Save/Save.c Spesifikasi/Song/Song.c Spesifikasi/Load/Load.c ADT/list/list.c ADT/listdin/listdin.c ADT/map/map.c ADT/mesinbaris/mesinbaris.c ADT/mesinkata/mesinkata.c ADT/mesinkarakter/mesinkarakter.c ADT/queue/queue.c ADT/set/set.c ADT/stack/stack.c ADT/strukturberkait/listberkait.c test.c

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinbaris/mesinbaris.h"

int main() {
    Word a = {"jason", 5};
    GetCommand();
    if (IsWordEq(currentWord, a)) {
        printf("%s\n", currentWord.TabWord);
        printf("benar\n");
        ADVCOMM();
        // if(IsWordEq(currentWord, b)) {
        //     printf("%s\n", currentWord.TabWord);
        //     printf("benar\n");
        // }
    }
    else {
        printf("salah\n");
    }
    return 0;
}
