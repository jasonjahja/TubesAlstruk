#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "ADT/list/list.h"
#include "ADT/listdin/listdin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinbaris/mesinbaris.h"
#include "ADT/queue/queue.h"
#include "ADT/set/set.h"
#include "ADT/map/map.h"
#include "ADT/stack/stack.h"
#include "ADT/strukturberkait/listberkait.h"

#include "Spesifikasi/Inisialisasi/Inisialisasi.h"
#include "Spesifikasi/Start/Start.h"
#include "Spesifikasi/Load/Load.h"
#include "Spesifikasi/List/List.h"
#include "Spesifikasi/Play/Play.h"
#include "Spesifikasi/Queue/Queue.h"
#include "Spesifikasi/Song/Song.h"
#include "Spesifikasi/Playlist/Playlist.h"
#include "Spesifikasi/Status/Status.h"
#include "Spesifikasi/Save/Save.h"
#include "Spesifikasi/Help/help.h"
#include "Spesifikasi/Enhance/Enhance.h"

int main() {

    Word word_start = {"START", 5};
    Word word_load = {"LOAD", 4};
    Word word_list = {"LIST", 4};
    Word word_play = {"PLAY", 4};
    Word word_queue = {"QUEUE", 5};
    Word word_song = {"SONG", 4};
    Word word_playlist = {"PLAYLIST", 8};
    Word word_status = {"STATUS", 6};
    Word word_save = {"SAVE", 4};
    Word word_quit = {"QUIT", 4};
    Word word_help = {"HELP", 4};
    Word word_default = {"DEFAULT", 7};
    Word word_swap = {"SWAP", 4};
    Word word_remove = {"REMOVE", 6};
    Word word_clear = {"CLEAR", 5};
    Word word_next = {"NEXT", 4};
    Word word_previous = {"PREVIOUS", 8};
    Word word_create = {"CREATE", 6};
    Word word_add = {"ADD", 3};
    Word word_delete = {"DELETE", 6};
    Word word_album = {"ALBUM", 5};
    Word word_enhance = {"ENHANCE", 7};

    songHistory SH; CreateEmptyStack(&SH);
    CurrentStat CS; CreateEmptyCurrentStat(&CS);
    Queue Q; CreateEmptyQueue(&Q);
    ListofPenyanyi LP; LP = MakeList();
    ListofPlaylist LPl; LPl = CreateListPlaylist();
    Word filename = toKata("test.txt");

    Inisialisasi();

    boolean running = true;
    boolean started = false;

    while (running)
    {
        printf(">> "); 
        GetCommand();

        if (IsWordEq(currentWord, word_start)) {
            if (!started)
            {
                startConfig(&LP);          
                started = true;
            }   
            else
            {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_load)) {
            if (!started) {
                ADVCOMM();
                started = true;
                filename = currentWord;
                Load(&LP, &CS, &Q, &SH, &LPl, currentWord, &started);
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_list)) {
            if (started) {
                ADVCOMM();
                if (IsWordEq(currentWord, word_default)) {
                    list_default(LP);
                }
                else if (IsWordEq(currentWord, word_playlist)) {
                    list_playlist(LPl);
                }
                else
                {
                    printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                    ADVCOMM();
                }
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_play)) {
            if (started) {
                ADVCOMM();
                if (IsWordEq(currentWord, word_song)) {
                    playSong(LP, &CS, &SH, &Q);
                }
                else if (IsWordEq(currentWord, word_playlist)) {
                    playPlaylist(LPl, &CS, &SH, &Q);
                }
                else
                {
                    printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                    ADVCOMM(); ADVCOMM();
                }
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_queue)) {
            if (started) {
                ADVCOMM(); 
                if (IsWordEq(currentWord, word_song)) {
                    if (!started)
                    {
                        printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                        ADVCOMM(); ADVCOMM();
                    }
                    else
                    {   
                        queueSong(LP, &Q);
                    }  
                }
                else if (IsWordEq(currentWord, word_playlist)) {
                    queuePlaylist(LPl, &Q);
                }
                else if (IsWordEq(currentWord, word_swap)) {
                    ADVCOMM(); int id1 = WordtoNum(currentWord); 
                    ADVCOMM(); int id2 = WordtoNum(currentWord); 
                    queueSwap(&Q, id1, id2);
                }
                else if (IsWordEq(currentWord, word_remove)) {
                    ADVCOMM(); int id = WordtoNum(currentWord); 
                    queueRemove(&Q, id);
                }
                else if (IsWordEq(currentWord, word_clear)) {
                    queueClear(&Q);
                }
                else
                {
                    printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                    ADVCOMM();
                }
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
            
        }

        else if (IsWordEq(currentWord, word_song)) {
            if (started) {
                ADVCOMM();
                if (IsWordEq(currentWord, word_next)) {
                    nextSong(&Q, &SH, &CS);
                }
                else if (IsWordEq(currentWord, word_previous)) {
                    prevSong(&Q, &SH, &CS);
                }
                else
                {
                    printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                    ADVCOMM(); ADVCOMM();
                }
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
            
        }

        else if (IsWordEq(currentWord, word_playlist)) {
            if (started) {
                ADVCOMM(); 
                if (IsWordEq(currentWord, word_create)) {
                    playlistCreate(&LPl);
                }
                else if (IsWordEq(currentWord, word_add)) {
                    ADVCOMM();
                    if (IsWordEq(currentWord, word_song)) {
                        playlistAddSong(LPl, LP);
                    }
                    else if (IsWordEq(currentWord, word_album)) {
                        playlistAddAlbum(LPl,LP);
                        PrintNode(*LPl.list);
                    }
                    else
                    {
                        printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                        ADVCOMM(); ADVCOMM(); ADVCOMM();
                    }
                }
                else if (IsWordEq(currentWord, word_swap)) {
                    ADVCOMM(); int id = WordtoNum(currentWord); 
                    ADVCOMM() ; int x = WordtoNum(currentWord); 
                    ADVCOMM() ; int y = WordtoNum(currentWord); 
                    playlistSwap(&LPl, id, x, y);
                }
                else if (IsWordEq(currentWord, word_remove)) {
                    ADVCOMM(); int id = WordtoNum(currentWord);
                    ADVCOMM() ; int n = WordtoNum(currentWord);
                    playlistRemove(&LPl, n, id);
                }
                else if (IsWordEq(currentWord, word_delete)) {
                    playlistDelete(&LPl);
                }
                else
                {
                    printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                    ADVCOMM(); ADVCOMM();
                }
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_status)) {
            if (started) {
                Status(CS, Q);
            } else {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM(); ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_save)) {
            ADVCOMM();
            if (!started)
            {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
            else
            {
                Save(&LP, &LPl, &Q, &SH, &CS, currentWord);
                printf("\nSave file berhasil disimpan.\n\n");
            }
        }

        else if (IsWordEq(currentWord, word_quit)) {
            printf("\nApakah kamu ingin menyimpan data sesi sekarang (Y/N) ? ");
            GetInput();
            if (IsWordEq(currentInput, toKata("Y"))) {
                Save(&LP, &LPl, &Q, &SH, &CS, filename);
            } else if (IsWordEq(currentInput,toKata("N"))){
                printf("\nKamu keluar dari WayangWave.\n");
                printf("Dadah ^_^\n\n");
            }
            running = false;
        }

        else if (IsWordEq(currentWord, word_help)) {
            Help(started);
        }

        else if (IsWordEq(currentWord, word_enhance)) {
            if (!started)
            {
                printf("\nERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
            else
            {
                Enhance(&LPl, LP);
            }
        }

        else if (IsWordEq(currentWord, toKata("display"))) {
            PrintNode(LPl.list[0]);
        }

        else {
            printf("\nCommand tidak diketahui!\n\n");
            ADVCOMM();
        }
    }
    return 0;
}
