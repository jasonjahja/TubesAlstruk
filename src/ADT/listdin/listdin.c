#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
ListofPlaylist CreateListPlaylist()
{
    ListofPlaylist l;
    l.list = (ListBerkait *)malloc(Sizelist * sizeof(ListBerkait));
    l.namaPlaylist = (Word *)malloc(Sizelist * sizeof(Word));
    l.Capacity = Sizelist;
    l.nEff = 0;
    return l;
}

void DeallocateListPlaylist(ListofPlaylist *l)
{
    free((*l).namaPlaylist);
    (*l).nEff = 0;
    (*l).Capacity = 0;
}

int LengthListPlaylist(ListofPlaylist l)
{
    return l.nEff;
}

boolean isEmptyListPlaylist(ListofPlaylist l)
{
    return l.nEff == 0;
}

boolean isMemberListPlaylist(ListofPlaylist l, Word X)
{
    for (int i = 0; i < LengthListPlaylist(l); i++)
    {
        if(IsWordEq(l.namaPlaylist[i], X))
        {
            return true;
        }
    }
    return false;
}

int IndexListPlaylist(ListofPlaylist l, Word val)
{
    if (isMemberListPlaylist(l, val))
    {
        int count = 0;
        for (int i = 0; i< LengthListPlaylist(l); i++)
        {
            if (IsWordEq(l.namaPlaylist[count], val))
            {
                return count;
            }
            count++;
        }
    }
    return -1;
}


Word GetListPlaylist(ListofPlaylist l, int idx)
{
    return l.namaPlaylist[idx];
}

void InsertListPlaylist(ListofPlaylist *l, Word val)
{
    CreateEmptyPlaylist(&((*l).list[(*l).nEff]));
    (*l).namaPlaylist[(*l).nEff] = val;
    (*l).nEff++;
}

void DeletePlaylist(ListBerkait *L)
{
    address current = L->First;
    address nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void DeleteListPlaylist(ListofPlaylist *l, int idx) {
    if (idx > 0 && idx <= l->nEff) {
        int i;
        // Deallocate the playlist name
        for (i = idx-1; i < l->nEff; i++) {
            l->namaPlaylist[i] = l->namaPlaylist[i + 1];
            // printf(">> ");
            // TulisWord(l->namaPlaylist[i]);
        }
        // Deallocate the associated linked list
        DeletePlaylist(&(l->list[idx]));
        // Decrement the number of elements in the list
        l->nEff--;
    } else {
        printf("Error: Invalid index for deletion.\n");
    }
}

void CopyPlaylist(ListBerkait lin, ListBerkait *lout)
{
    CreateEmptyPlaylist(lout);
    (*lout).First = lin.First;
}

void DisplayListPlaylist(ListofPlaylist *l)
{
    for (int i = 0; i < LengthListPlaylist(*l);i++)
    {
        printf("     %d. ",i+1);
        TulisWordNoNL((*l).namaPlaylist[i]);
        printf("\n");
    }
}