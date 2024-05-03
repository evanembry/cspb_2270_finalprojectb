#include <iostream>
#include "../code/Jukebox.h"

using namespace std;

int main(){
    
    Jukebox jukebox;
    
    int choice = 0;
    
    while (true) 
    {
        cout << "Jukebox Main Menu" << endl;
        cout << "1. Play current song" << endl;
        cout << "2. Pause current song" << endl;
        cout << "3. Skip to next track" << endl;
        cout << "4. Skip to previous track" << endl;
        cout << "5. Remove a song from the current playlist" << endl;
        cout << "6. Create a new playlist" << endl;
        cout << "7. Delete a playlist" << endl;
        cout << "8. Select a playlist" << endl;
        cout << "9. Add a song to the selected playlist" << endl;
        cout << "10. Remove a song from the selected playlist" << endl;
        cout << "11. Select a song in the current playlist" << endl;
        cout << "12. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                jukebox.playCurrentSong();
                break;
            case 2:
                jukebox.pauseCurrentSong();
                break;
            case 3:
                jukebox.skipToNextTrack();
                break;
            case 4:
                jukebox.skipToPreviousTrack();
                break;
            

                
            case 5: {
                string title, artist;
                cout << "Enter title of the song to remove: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist of the song to remove: ";
                getline(cin, artist);
                jukebox.removeSongFromPlaylist(title, artist);
                break;
            }
                
            case 6: {
                string name, description;
                cout << "Enter name of the playlist: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter description of the playlist: ";
                getline(cin, description);
                jukebox.createPlaylist(name, description);
                break;
            }
                
            case 7: {
                string name;
                cout << "Enter name of the playlist to delete; ";
                cin.ignore();
                getline(cin, name);
                jukebox.deletePlaylist(name);
                break;
            }
                
            case 8: {
                string name;
                cout << "Enter name of the playlist to select: ";
                cin.ignore();
                getline(cin, name);
                jukebox.selectPlaylist(name);
                break;
            }
                
            case 9: {
                string title, artist;
                cout << "Enter title of the song: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist of the song: ";
                getline(cin, artist);
                jukebox.addSongToSelectedPlaylist(title, artist);
                break;
            }
                
            case 10: {
                string title, artist;
                cout << "Enter title of the song to remove: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist of the song to remove: ";
                getline(cin, artist);
                jukebox.removeSongFromSelectedPlaylist(title, artist);
                break;
                
            }
                
            case 11: {
                string title, artist;
                cout << "Enter title of the song: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist of the song: ";
                getline(cin, artist);
                jukebox.selectSong(title, artist);
                break;
            }
                
     
                
            case 12:
                
                cout << "Exiting Jukebox. Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    
    return 0;
}


                
                
        
        