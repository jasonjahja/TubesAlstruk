#ifndef queue_H
#define queue_H

#include "../../../src/boolean.h"
#include "../../../src/ADT/queue/queue.h"
#include "../../../src/ADT/list/list.h"
#include "../../../src/ADT/listdin/listdin.h"
#include "../../../src/ADT/map/map.h"
#include "../../../src/ADT/set/set.h"
#include "../../../src/ADT/mesinkata/mesinkata.h"
#include "../../../src/ADT/mesinkarakter/mesinkarakter.h"
#include "../../../src/ADT/mesinbaris/mesinbaris.h"

void queueSong (ListofPenyanyi daftarpenyanyi, Queue * queue);

void queuePlaylist(ListofPlaylist daftarplaylist, Queue * queue);

void queueSwap (Queue * queue, int id1, int id2);

void queueRemove (Queue * queue, int id);

void queueClear (Queue * queue);

void dequeueSong (Queue * queue, int id);

#endif