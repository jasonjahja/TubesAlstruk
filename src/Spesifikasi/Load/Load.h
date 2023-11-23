#ifndef __Load_H__
#define __Load_H__

#include <stdio.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/mesinbaris/mesinbaris.h"
#include "../../ADT/list/list.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/map/map.h"
//#include "../ADT/strukturberkait/listberkait.h"
#include "../../ADT/set/set.h"
#include "../../Spesifikasi/Play/Play.h"
#include "../../Spesifikasi/Playlist/Playlist.h"

void Load(ListofPenyanyi *ListPenyanyi, CurrentStat *CS, Queue *Q, songHistory *SH, ListofPlaylist *LPl, Word CW, boolean *started);
#endif