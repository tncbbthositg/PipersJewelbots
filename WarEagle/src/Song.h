#ifndef SONG_h
#define SONG_h

#include "Arduino.h"

#include "LightScene.h"

class Song {
  public: 
    Song(unsigned int tempo, const char* music);
    void addLightShow(unsigned int lightShowSize, const LightScene* lightShow);
    void play();

  private:
    static const int TIME_BETWEEN_NOTES = 60;

    unsigned int tempo;
    const char* music;
    
    const LightScene* lightShow;
    unsigned int lightShowSize = 0;
    unsigned int lightShowIndex = -1;

    double getNoteDuration(char note);
    void playNote(unsigned int duration, bool isRest, bool isAccented);
    void cycleLightShow();
};

#endif