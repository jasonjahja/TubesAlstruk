#include <stdio.h>
#include "Status.h"

void Status (CurrentStat stat, Queue QL) 
{
    if (stat.currentplay.status == 0) // kondisi tidak ada lagu
    { 
        printf("\nNow Playing:\n");
        printf("No songs have been played yet. Please search for a song to begin playback.\n");

        if (QL.idxHead != IDX_UNDEFQueue && QL.idxTail != IDX_UNDEFQueue) // kondisi ada queue
        {
            printf("\nQueue:\n");
            for (int i = QL.idxHead; i <= QL.idxTail ; i++)
            {
                printf("%d. %s - %s - %s\n\n", i+1, QL.singer[i].TabWord, QL.song[i].TabWord, QL.album[i].TabWord);
            }
        }
        else //kondisi tidak ada queue
        {
            printf("\nQueue:\n");
            printf("Your queue is empty.\n\n");
        }
    }
   else // kondisi ada lagu
   {
        if (stat.statusPL == 1) {
            printf("\nCurrent Playlist: %s\n", stat.playlist.TabWord);
        }

        printf("\nNow Playing:\n");
        TulisWordNoNL(stat.currentplay.penyanyi);
        printf(" - ");
        TulisWordNoNL(stat.currentplay.judul);
        printf(" - ");
        TulisWord(stat.currentplay.album);

        printf("\nQueue:\n");
        if (QL.idxHead == IDX_UNDEFQueue && QL.idxTail == IDX_UNDEFQueue) {
            printf("Your queue is empty.\n\n");
        } else {
            for (int i = QL.idxHead; i <= QL.idxTail; i++)
            {
                printf("%d. %s - %s - %s\n", i+1, QL.singer[i].TabWord, QL.song[i].TabWord, QL.album[i].TabWord);
            }
        }
   }
}