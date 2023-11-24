# TUGAS BESAR ALGORITMA STRUKTUR DATA STI 2023
## DESKRIPSI PROGRAM (。・∀・)ノ
Program ini merupakan hasil tugas besar Alstrukdat STI. Program "WayangWave" ini merupakan program yang dapat digunakan untuk memutar lagu dan membuat playlist lagu. Program ini juga memuat informasi mengenai artis, album yang dimiliki artis tersebut dan lagu-lagu yang dimuat didalam album tersebut. Dalam menjalankan tiap fiturnya, user dapat menggunakan command-command yang ada yang dapat di lihat pada fitur `Help`. 
Command-command yang dapat digunakan, antara lain:
1. `START` : untuk masuk sesi baru
2. `LOAD` : untuk memulai sesi berdasarkan file konfigurasi
3. `HELP` : untuk melihat informasi command-command yang dapat dilihat
4. `LIST DEFAULT` : untuk melihat list penyanyi, album, dan lagu yang ada
5. `LIST PLAYLIST` : untuk menampilkan playlist yang ada pada pengguna
6. `QUEUE SONG` : untuk menambahkan lagu ke dalam queue
7. `QUEUE PLAYLIST` : untuk menambahkan lagu yang ada dalam playlist ke dalam queue
8. `QUEUE SWAP` <x> <y> : untuk menukar lagu pada urutan ke x dan juga urutan ke y
9. `QUEUE REMOVE` <id> : untuk menghapus lagu dari queue
10. `QUEUE CLEAR` : untuk mengosongkan queue
11. `SONG NEXT` : untuk memutar lagu yang berada di dalam queue
12. `SONG PREVIOUS` : untuk memutar lagu yang terakhir kali diputar
13. `PLAYLIST CREATE`: untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna
14. `PLAYLIST ADD ALBUM` : untuk menambahkan lagu-lagu pada Album ke suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna
15. `PLAYLIST ADD SONG` : untuk menambahkan lagu ke suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna
16. `PLAYLIST SWAP` <x> <y> : untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id
17. `PLAYLIST REMOVE` <id> <n> : untuk menghapus lagu dengan urutan n pada playlist dengan index id
18. `PLAYLIST DELETE` : untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna
19. `STATUS` : untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar
20. `SAVE` <filename> : untuk menyimpan state ke dalam file
21. `QUIT` : untuk keluar dari sesi

## ANGGOTA KELOMPOK 
- Gracya Tio Damena Sidabutar / 18222110
- Moh Afnan Fawaz / 18222111
- Gabriel Marcellino Joestiawan / 18222115
- Jason Jahja / 18222116
- Hanan Fitra Salam / 18222133

## HOW TO USE (´･ω･`)?
- Buka terminal
- Ketik "cd src" jika belum masuk ke src directory
- Ketik kode ini:
    gcc -o main Spesifikasi/Start/Start.c Spesifikasi/Help/Help.c Spesifikasi/List/List.c Spesifikasi/Play/Play.c Spesifikasi/Queue/Queue.c Spesifikasi/Save/Save.c Spesifikasi/Song/Song.c Spesifikasi/Load/Load.c ADT/list/list.c ADT/listdin/listdin.c ADT/map/map.c ADT/mesinbaris/mesinbaris.c ADT/mesinkata/mesinkata.c ADT/mesinkarakter/mesinkarakter.c ADT/queue/queue.c ADT/set/set.c ADT/stack/stack.c ADT/strukturberkait/listberkait.c main.c Spesifikasi/Status/status.c Spesifikasi/Inisialisasi/Inisialisasi.c Spesifikasi/Playlist/Playlist.c

    ./main


## STRUKTUR PROGRAM
```
├───docs
├───save    # file-file yang disimpan oleh user
└───src
    ├───ADT            # Implementasi ADT-ADT yang digunakan untuk semua command
    │   ├───list
    │   ├───listdin
    │   ├───map
    │   ├───mesinbaris
    │   ├───mesinkarakter
    │   ├───mesinkata
    │   ├───queue
    │   ├───set
    │   ├───stack
    │   └───strukturberkait
    ├───Spesifikasi     # Implementasi semua command
    │   ├───Help
    │   ├───Insialisasi
    │   ├───List
    │   ├───Load
    │   ├───Play
    │   ├───Playlist
    │   ├───Queue
    │   ├───Save
    │   ├───Start
    │   └───Status
    ├───main.c  # memanggil semua fungsi spesifikasi
    ├───boolean.h
    └───MakeFile
```
