#include "stdio.h"
#include "stdlib.h"
#include "listberkait.h"

boolean IsEmpty (ListBerkait L)
{
  return L.First == NilNode;
}

void CreateEmptyPlaylist (ListBerkait *L)
{
  L->First = NilNode;
}
address Alokasi (infoLagu X)
{
  address P = (address) malloc(1 * sizeof (ElmtList));
  if (P != NilNode) {
    Info(P) = X;
    Next(P) = NilNode;
    return P;
  } {
    return NilNode;
  }
}

void Dealokasi (address *P)
{
  free(*P);
}

boolean isPenyanyiAvail (ListBerkait L, infoLagu X){
  address P;
  boolean bFound = false;

  if (!IsEmpty(L)) {
    P = First(L);
    while (!bFound && P != NilNode) {
      if (IsWordEq(X.Lagu.penyanyi,P->info.Lagu.penyanyi)) {
        bFound = true;
      } else {
        P = Next(P);
      }
    }

    if (bFound) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}
boolean isAlbumAvail (ListBerkait L, infoLagu X){
  address P;
  boolean bFound = false;

  if (!IsEmpty(L)) {
    P = First(L);
    while (!bFound && P != NilNode) {
      if (IsWordEq(X.Lagu.album,P->info.Lagu.album)) {
        bFound = true;
      } else {
        P = Next(P);
      }
    }

    if (bFound) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}


boolean isSongAvail (ListBerkait L, infoLagu X){
  address P;
  boolean bFound = false;

  if (!IsEmpty(L)) {
    P = First(L);
    while (!bFound && P != NilNode) {
      if (IsWordEq(X.Lagu.penyanyi,P->info.Lagu.penyanyi)) {
        bFound = true;
      } else {
        P = Next(P);
      }
    }

    if (bFound) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}

//=================INSERT/DEL infolagu============================
void InsVFirst (ListBerkait *L, infoLagu X){
  address P = Alokasi(X);
  if (P != NilNode) {
    InsertFirst(L, P);
  }
}

void InsVLast (ListBerkait *L, infoLagu X)
{
  address P = Alokasi(X);
  if (P != NilNode) {
    InsertLast(L, P);
  }
}

void DelVFirst (ListBerkait *L, infoLagu *X)
{
  address P = First(*L);
  *X = Info(P);
  First(*L) = Next(P);
  Dealokasi(&P);
}

void DelVLast (ListBerkait *L, infoLagu *X)

{
  address P = First(*L);
  address Prec = NilNode;

  while (Next(P) != NilNode) {
    Prec = P;
    P = Next(P);
  }

  *X = Info(P);
  if (Prec != NilNode) {
    Next(Prec) = NilNode;
  } else {
    First(*L) = NilNode;
  }
  Dealokasi(&P);
}

void InsertFirst (ListBerkait *L, address P)
{
  Next(P) = First(*L);
  First(*L) = P;
}

void InsertAfter (ListBerkait *L, address P, address Prec)
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (ListBerkait *L, address P)

{
  address Last;

  if (IsEmpty(*L)) {
    InsertFirst(L, P);
  } else {
    Last = First(*L);
    while (Next(Last) != NilNode) {
      Last = Next(Last);
    }
    // Next(Last) = Last;
    InsertAfter(L,P,Last);
  }
}


void DelFirst (ListBerkait *L, address *P)
{
  *P = First(*L);
  First(*L) = Next(First(*L));
  Next(*P) = NilNode;
}

// Siapa tau butuh, btw belum dibuat algoritmanya

// void DelPlaylist (ListBerkait *L, infoLagu X)
// {

//   address Prec;
//   address P;
//   boolean bFound = false;

//   if (!IsEmpty(*L)) {
//     IsWordEq(toKata())
//     if (X == Info(First(*L))) {
//       DelFirst(L, &P);
//       Dealokasi(&P);
//     } else {
//       P = First(*L);
//       while (!bFound && P != NilNode) {
//         if (Info(P) == X) {
//           bFound = true;
//         } else {
//           Prec = P;
//           P = Next(P);
//         }
//       }

//       if (bFound) {
//         DelAfter(L, &P, Prec);
//         Dealokasi(&P);
//       }
//     }
//   }
// }

void DelLast (ListBerkait *L, address *P)

{
  address Last = First(*L);
  address PrecLast = NilNode;

  while (Next(Last) != NilNode) {
    PrecLast = Last;
    Last = Next(Last);
  }

  *P = Last;
  if (PrecLast == NilNode) {
    First(*L) = NilNode;
  } else {
    Next(PrecLast) = NilNode;
  }
}

void DelAfter (ListBerkait *L, address *Pdel, address Prec)

{
  *Pdel = Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = NilNode;
}


void PrintNode (ListBerkait L){
  address P;
  boolean isFirst = true;

  // printf("[");
  if (!IsEmpty(L)) {
    P = First(L);
    while (P != NilNode) {
      if (!isFirst) {
        printf("\n");
      }
      printf("Nama Penyanyi : ");
      TulisWord(P->info.Lagu.penyanyi);
    
      printf("Nama Album : ");
      TulisWord(P->info.Lagu.album);
      printf("Nama Judul Lagu Pertama : ");
      TulisWord(P->info.Lagu.judul);
      isFirst = false;
      P = Next(P);
    }
  }
  // printf("]\n");
}
int NbElmtListBerkait (ListBerkait L)
{
  int cnt = 0;
  address P;

  if (!IsEmpty(L)) {
    P = First(L);
    while (P != NilNode) {
      cnt++;
      P = Next(P);
    }
  }

  return cnt;
}

void InversListBerkait (ListBerkait *L)
{
	address P;
	address Prec = NilNode;
	address Succ;
	
	if (!IsEmpty(*L)) {
		P = First(*L);
		while (P != NilNode) {
			Succ = Next(P);
			Next(P) = Prec;
			Prec = P;
			P = Succ;
		}
		First(*L) = Prec;
	}
}