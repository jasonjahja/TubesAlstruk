# TUGAS BESAR ALGORITMA STRUKTUR DATA STI 2023
## DESKRIPSI PROGRAM (。・∀・)ノ
Program ini merupakan hasil tugas besar Alstrukdat STI. Program "WayangWave" ini merupakan program yang dapat digunakan untuk memutar lagu dan membuat playlist lagu. Program ini juga memuat informasi mengenai artis, album yang dimiliki artis tersebut dan lagu-lagu yang dimuat didalam album tersebut. Dalam menjalankan tiap fiturnya, user dapat menggunakan command-command yang ada yang dapat di lihat pada fitur Help. 

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
