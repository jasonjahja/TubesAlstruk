#include <stdio.h>
#include "listdin.h"

int main() {
    // Create a playlist
    ListofPlaylist myPlaylists = CreateListPlaylist();

    // Insert some playlists
    InsertListPlaylist(&myPlaylists, toKata("Playlist1"));
    InsertListPlaylist(&myPlaylists, toKata("Playlist2"));
    InsertListPlaylist(&myPlaylists, toKata("Playlist3"));

    // Display the playlists
    printf("My Playlists:\n");
    DisplayListPlaylist(&myPlaylists);

    // Check if a playlist is a member
    Word playlistToCheck = toKata("Playlist2");
    if (isMemberListPlaylist(myPlaylists, playlistToCheck)) {
        TulisWordNoNL(playlistToCheck);
        printf(" is in the playlist.\n");
    } else {
        TulisWordNoNL(playlistToCheck);
        printf(" is not in the playlist.\n");
    }

    // Delete a playlist
    DeleteListPlaylist(&myPlaylists, 1);

    // Display the playlists after deletion
    printf("\nAfter Deletion:\n");
    DisplayListPlaylist(&myPlaylists);

    // Deallocate the playlist
    DeallocateListPlaylist(&myPlaylists);

    return 0;
}
