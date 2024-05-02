#ifndef JUKEBOX_H
#define JUKEBOX_H


#include <string>


using namespace std;


class PlaylistNode {
public:
    
    PlaylistNode(const string& name, const string& description) : name(name), description(description), prev(nullptr), next(nullptr), firstSong(nullptr),          lastSong(nullptr) {}
    
    ~PlaylistNode() {}
    
    string name;
    string description;
    PlaylistNode* prev;
    PlaylistNode* next;
    class SongNode* firstSong;
    class SongNode* lastSong;
};


class SongNode {
public:
    
    SongNode(const string& title, const string& artist) : title(title), artist(artist), prev(nullptr), next(nullptr) {}
    
    SongNode() {}
    
    string title;
    string artist;
    SongNode* prev;
    SongNode* next;
};

class Jukebox {
public:
    
    //Constructor
    Jukebox();
    
    //Destructor
    ~Jukebox();
    
    //Function to play the current song
    void playCurrentSong();
    
    //Functioin to pause the current song 
    void pauseCurrentSong();
    
    //Function to skip to the next track
    void skipToNextTrack();
    
    //Function to skip to the previous track
    void skipToPreviousTrack();
    
    //Function to add a song to the current playlist
    void addSongToPlaylist(const string& tgitle, const string& artist);
    
    //Function to remove a song from the current playlist 
    void removeSongFromPlaylist(const string& title, const string& artist);
    
    //Function to create a new playlist 
    void createPlaylist(const string& name, const string& description);
    
    //Function to delete a playlist
    void deletePlaylist(const string& name);
    
    //Functiuon to select a playlist
    void selectPlaylist(const string& name);
    
    //Function to add a song to the selected playlist
    void addSongToSelectedPlaylist(const string& title, const string& artist);
    
    //Functiuon to remove a song from the selected playlist
    void removeSongFromSelectedPlaylist(const string& title, const string& artist);
    
    
private:
    
    PlaylistNode* firstPlaylist;
    PlaylistNode* currentPlaylist;
    SongNode* currentSong;
    
    PlaylistNode* findPlaylistByName(const string& name);
    
    SongNode* findSongInSelectedPlaylist(const string& title, const string& artist);
    
    void addToFrontOfPlaylist(PlaylistNode* newPlaylist);
    void removeFromPlaylist(PlaylistNode* playlist);
    void addToFrontOfSelectedPlaylist(SongNode* newSong);
    void removeFromSelectedPlaylist(SongNode* song);
    
};
    
    
#endif // JUKEBOX_H