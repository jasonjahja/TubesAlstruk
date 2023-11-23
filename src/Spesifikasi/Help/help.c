#include <stdio.h>
#include "../../boolean.h"

void Help (boolean entered) {
    printf("\n=====================================================[ Menu Help WayangWave ]=======================================================\n\n");
    // Ketika perintah dipanggil sebelum memasuki sesi
    if (!entered) {
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD <filename> -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }

    // Ketika perintah dipanggil setelah memasuki sesi
    else {
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1a. LIST DEFAULT -> Untuk melihat list penyanyi, album, dan lagu yang ada\n");
    printf("1b. LIST PLAYLIST -> Untuk menampilkan playlist yang ada pada pengguna\n");
    printf("2a. PLAY SONG -> Untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu\n");
    printf("2b. PLAY PLAYLIST -> Untuk memainkan lagu berdasarkan id playlist\n");
    printf("3a. QUEUE SONG -> Untuk menambahkan lagu ke dalam queue\n");
    printf("3b. QUEUE PLAYLIST -> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
    printf("3c. QUEUE SWAP <x> <y> -> Untuk menukar lagu pada urutan ke x dan juga urutan ke y\n");
    printf("3d. QUEUE REMOVE <id> -> Untuk menghapus lagu dari queue\n");
    printf("3e. QUEUE CLEAR -> Untuk mengosongkan queue\n");
    printf("4a. SONG NEXT -> Untuk memutar lagu yang berada di dalam queue\n");
    printf("4b. SONG PREVIOUS -> Untuk memutar lagu yang terakhir kali diputar\n");
    printf("5a. PLAYLIST CREATE-> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n");
    printf("5b. PLAYLIST ADD -> Untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna\n");
    printf("5c. PLAYLIST SWAP <x> <y> -> Untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id\n");
    printf("5d. PLAYLIST REMOVE <id> <n> -> Untuk menghapus lagu dengan urutan n pada playlist dengan index id\n");
    printf("5e. PLAYLIST DELETE -> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna\n");
    printf("6.  STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n");
    printf("7.  SAVE <filename> -> Untuk menyimpan state ke dalam file\n");
    printf("8. QUIT -> Untuk keluar dari sesi\n");
    }

    printf("\n====================================================================================================================================\n\n");
}