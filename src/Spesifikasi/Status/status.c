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
                printf("%d. ", i+1);
                TulisWordNoNL(QL.singer[i]);
                printf(" - ");
                TulisWordNoNL(QL.song[i]);
                printf(" - ");
                TulisWord(QL.album[i]);
            }
            printf("\n");
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
            printf("\nCurrent Playlist:\n");
            TulisWord(stat.playlist);
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
                printf("%d. ", i+1);
                TulisWordNoNL(QL.singer[i]);
                printf(" - ");
                TulisWordNoNL(QL.song[i]);
                printf(" - ");
                TulisWord(QL.album[i]);
            }
            printf("\n");
        }
   }
}