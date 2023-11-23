#include<stdio.h>
#include"queue.h"

boolean IsEmptyQueue (Queue Q)
{
    return ((IDX_HEAD(Q) == IDX_UNDEFQueue) && (IDX_TAIL(Q) == IDX_UNDEFQueue));
}

boolean IsFullQueue (Queue Q)
{
    if ((IsEmptyQueue(Q)))
    {
        return false;
    }
    else 
    {
        return ((IDX_HEAD(Q) == 0) && (IDX_TAIL(Q) == IDX_MAXQueue));
    }
}

int LengthQueue (Queue Q)
{
    if (IsEmptyQueue(Q)) 
    {
        return 0;
    }
    else 
    {
        return ((IDX_TAIL(Q)-IDX_HEAD(Q)) + 1);
    }
}

void CreateEmptyQueue (Queue * Q)
{
    IDX_HEAD(*Q) = IDX_UNDEFQueue;
    IDX_TAIL(*Q) = IDX_UNDEFQueue;
}

void enqueueQueue (Queue * Q, Word song, Word album, Word singer)
{
    if (IsEmptyQueue(*Q))
    {
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
        TAILSONG(*Q) = song;
        TAILALBUM(*Q) = album;
        TAILSINGER(*Q) = singer;
    }
    else
    {
        if (IDX_TAIL(*Q) != IDX_MAXQueue)
        {
            IDX_TAIL(*Q)++;
            TAILSONG(*Q) = song;
            TAILALBUM(*Q) = album;
            TAILSINGER(*Q) = singer;
        }
    }
}

Song dequeueQueue(Queue * Q)
{
    Song lagu;
    if (!IsEmptyQueue(*Q)) {
        lagu.judul = HEADSONG(*Q);
        lagu.album = HEADALBUM(*Q);
        lagu.penyanyi = HEADSINGER(*Q);
        if (LengthQueue(*Q) == 1)
        {
            CreateEmptyQueue(Q);
        }
        else 
        {
            for (int i = 0; i < LengthQueue(*Q)-1; i++) 
            {
                (*Q).song[i] = (*Q).song[i+1];
                (*Q).album[i] = (*Q).album[i+1];
                (*Q).singer[i] = (*Q).singer[i+1];
            }

            IDX_TAIL(*Q)--;
        }
    }

    return lagu;
}

void displayQueue(Queue q) 
{
    printf("[");
    if (!IsEmptyQueue(q)) {
        for (int i = IDX_HEAD(q) ; i <= IDX_TAIL(q) ; i++) {
            printf("{");
            TulisWordNoNL(q.song[i]); printf(",");
            TulisWordNoNL(q.album[i]); printf(",");
            TulisWordNoNL(q.singer[i]);
            printf("}");
            if (i<IDX_TAIL(q)) {
                printf(",");
            }
        }
    }
    printf("]\n");
}