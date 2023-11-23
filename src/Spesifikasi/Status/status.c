#include <stdio.h>
#include "Status.h"

void Status (CurrentStat stat, Queue QL) 
{
    if (stat.currentplay.status == 0) // kondisi tidak ada lagu
    { 
        printf("\nNow Playing:\n");
        printf("No songs have been played yet. Please search for a song to begin playback.\n");

        if (QL.idxHead != IDX_UNDEFQueue && QL.idxTail != IDX_UNDEFQueue) // kondisi tidak ada queue
        {
            printf("\nQueue:\n");
            printf("Your queue is empty.\n");
        }
        else //kondisi ada queue
        {
            printf("\nQueue:\n");
            for (int i = QL.idxHead; i <= QL.idxTail ; i++)
            {
                printf("%d. %s - %s - %s\n", i+1, QL.singer[i].TabWord, QL.song[i].TabWord, QL.album[i].TabWord);
            }
        }
    }
   else // kondisi ada lagu
   {
        if (QL.idxHead == IDX_UNDEFQueue && QL.idxTail == IDX_UNDEFQueue) 
        {
            if (stat.statusPL == 1) 
            {
                printf("\nCurrent Playlist: %s\n", stat.playlist.TabWord);
            }
            printf("\nNow Playing:\n");
            printf("%s - %s - %s\n", QL.singer->TabWord, QL.song->TabWord, QL.album->TabWord);

            printf("\nQueue:\n");
            printf("Your queue is empty.\n");
        }
        else
        {
            if (stat.statusPL == 1) 
            {
                printf("\nCurrent Playlist: %s\n", stat.playlist.TabWord);
            }

            printf("\nNow Playing:\n");
            printf("%s - %s - %s\n", QL.singer->TabWord, QL.song->TabWord, QL.album->TabWord);

            printf("\nQueue:\n");
            for (int i = QL.idxHead; i <= QL.idxTail; i++)
            {
                printf("%d. %s - %s - %s\n", i+1, QL.singer[i].TabWord, QL.song[i].TabWord, QL.album[i].TabWord);
            }
        }
   }
}