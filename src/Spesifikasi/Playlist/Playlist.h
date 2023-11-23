#ifndef __Playlist_H__
#define __Playlist_H__

#include "../../boolean.h"
#include "../../Spesifikasi/Start/Start.h"
#include "../../ADT/listdin/listdin.h"
#include "../../ADT/strukturberkait/listberkait.h"
#include "../../ADT/mesinbaris/mesinbaris.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/list/list.h"
#include "../../ADT/map/map.h"
#include "../../ADT//set/set.h"

void playlistCreate(ListofPlaylist *L);
void playlistAddSong(ListofPlaylist L,ListofPenyanyi LP);
// void playlistAddAlbum(ListofPlaylist *L,ListofPenyanyi LP);
void playlistSwap(ListofPlaylist *L,int idx,int x,int y);
void playlistRemove(ListofPlaylist *L,int rowsong,int idx);
void playlistDelete(ListofPlaylist *L);

#endif