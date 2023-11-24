#ifndef SAVE_H
#define SAVE_H

#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/strukturberkait/listberkait.h"
#include "../../ADT/mesinbaris/mesinbaris.h"
#include "../../ADT/list/list.h"
#include "../../ADT/map/map.h"
#include "../../ADT/set/set.h"
#include "../../Spesifikasi/List/List.h"
#include "../../Spesifikasi/Play/Play.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/stack/stack.h"
#include "../../ADT/listdin/listdin.h"

void Save(ListofPenyanyi *LP,ListofPlaylist *listPlaylist,Queue *queueLagu,songHistory *songHistory,CurrentStat *status, Word fileName);

#endif