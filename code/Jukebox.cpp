

#include "Jukebox.h"
#include <iostream>




Jukebox::Jukebox() : firstPlaylist(nullptr), currentPlaylist(nullptr), currentSong(nullptr) {}

Jukebox::~Jukebox() {}

void Jukebox::playCurrentSong() {
    if (currentSong)
    {
        cout << "Playing: " << currentSong->title << " - " << currentSong->artist << endl;
    }
    
    else
    {
        cout << "No song is currently selected." << endl;
    }
}

void Jukebox::pauseCurrentSong() {
    if (currentSong)
    {
        cout << "Song paused: " << currentSong->title << " - " << currentSong->artist << endl;
    }
    else
    {
        cout << "No Song is currently selected." << endl;
    }
}

void Jukebox::skipToNextTrack() {
    if (currentSong && currentSong->next)
    {
        currentSong = currentSong->next;
        playCurrentSong();
    }
    
    else
    {
        cout << "No next track available." << endl;
    }
}

void Jukebox::skipToPreviousTrack() {
    if (currentSong && currentSong->prev)
    {
        currentSong = currentSong->prev;
        playCurrentSong();
    }
    
    else
    {
        cout << "No previous track available." << endl;
    }
}

void Jukebox::createPlaylist(const string& name, const string& description) {
    PlaylistNode* newPlaylist = new PlaylistNode(name, description);
    addToFrontOfPlaylist(newPlaylist);
}

void Jukebox::deletePlaylist(const string& name)
{
    PlaylistNode* playlistToDelete = findPlaylistByName(name);
    removeFromPlaylist(playlistToDelete);
}

void Jukebox::selectPlaylist(const string& name) {
    currentPlaylist = findPlaylistByName(name);
}


void Jukebox::addSongToSelectedPlaylist(const string& title, const string& artist) {
    if (!currentPlaylist)
    {
        cout << "No playlist selected." << endl;
        return;
    }
    
    SongNode*  newSong = new SongNode(title, artist);
    addToFrontOfSelectedPlaylist(newSong);
}

void Jukebox::removeSongFromSelectedPlaylist(const string& title, const string& artist) {
    if (!currentPlaylist)
    {
        cout << "No playlist selected." << endl;
        return;
    }
    
    SongNode* songToRemove = findSongInSelectedPlaylist(title, artist);
    removeFromSelectedPlaylist(songToRemove);
}



PlaylistNode* Jukebox::findPlaylistByName(const string& name) {
    PlaylistNode* cursor = firstPlaylist;
    while (cursor) 
    {
        if (cursor->name == name) 
        {
            return cursor;
        }
        cursor = cursor->next;
    }
    
    return nullptr;
}

SongNode* Jukebox::findSongInSelectedPlaylist(const string& title, const string& artist) {
    
    if (!currentPlaylist) 
    {
        return nullptr;
    }
    
    SongNode* cursor = currentPlaylist->firstSong;
    while (cursor) 
    {
        if (cursor->title == title && cursor->artist == artist)
        {
            return cursor;
        }
        
        cursor = cursor->next;
    }
    
    return nullptr;
}

void Jukebox::addToFrontOfPlaylist(PlaylistNode* newPlaylist) 
{
    if (!newPlaylist)
    {
        return;
    }
    
    if  (!firstPlaylist)
    {
        firstPlaylist = newPlaylist;
        currentPlaylist = newPlaylist;
        newPlaylist->prev = nullptr;
        newPlaylist->next = nullptr;
    }
    
    else
    {
        newPlaylist->next = firstPlaylist;
        newPlaylist->prev = nullptr;
        firstPlaylist->prev = newPlaylist;
        firstPlaylist = newPlaylist;
    }
    
}


void Jukebox::removeFromPlaylist(PlaylistNode* playlist) {
    if (!playlist || !firstPlaylist) 
    {
        return;
    }
    
    if (playlist == firstPlaylist) 
    {
        if (playlist->next)
        {
            firstPlaylist = playlist->next;
            firstPlaylist->prev = nullptr;
        }
        else
        {
            firstPlaylist = nullptr;
            currentPlaylist = nullptr;
        }
        
    }
    
    else 
    {
        if (playlist->prev) 
        {
            playlist->prev->next = playlist->next;
        }
        
        if (playlist->next)
        {
            playlist->next->prev = playlist->prev;
        }
    }
    
    delete playlist;
}

void Jukebox::addToFrontOfSelectedPlaylist(SongNode* newSong)
{
    if (!newSong || !currentPlaylist)
    {
        return;
    }
    
    if (!currentPlaylist->firstSong)
    {
        currentPlaylist->firstSong = newSong;
        currentPlaylist->lastSong = newSong;
        newSong->prev = nullptr;
        newSong->next = nullptr;
    }
    
    else
    {
        newSong->next = currentPlaylist->firstSong;
        newSong->prev = nullptr;
        currentPlaylist->firstSong->prev = newSong;
        currentPlaylist->firstSong = newSong;
    }
}


void Jukebox::removeFromSelectedPlaylist(SongNode* song)
{
    if (!song || !currentPlaylist || !currentPlaylist->firstSong)
    {
        return;
    }
    
    if (song == currentPlaylist->firstSong)
    {
        if (song->next)
        {
            currentPlaylist->firstSong = song->next;
            currentPlaylist->firstSong->prev = nullptr;
        }
        
        else 
        {
            currentPlaylist->firstSong = nullptr;
            currentPlaylist->lastSong = nullptr;
        }
        
    }
    
    else
    {
        if (song->prev)
        {
            song->prev->next = song->next;
        }
        
        if (song->next)
        {
            song->next->prev = song->prev;
        }
    }
    
    delete song;
}


void Jukebox::selectSong(const string& title, const string& artist)
{
    currentSong = findSongInSelectedPlaylist(title, artist);
    
    if (currentSong) 
    {
        cout << "Selected song: " << currentSong->title << " - " << currentSong->artist << endl;
    }
    
    else 
    {
        cout << "Song not found in the selected playlist." << endl;
    }
    
}



void Jukebox::removeSongFromPlaylist(const string& title, const string& artist) {
    if (!currentPlaylist)
    {
        cout << "No playlist selected." << endl;
        return;
    }
    
    SongNode* songToRemove = findSongInSelectedPlaylist(title, artist);
    removeFromSelectedPlaylist(songToRemove);
}
    
    





    

    





