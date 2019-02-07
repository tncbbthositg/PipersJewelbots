#include <string.h>
#include <cctype>

#include "Song.h"

Buzzer buzzer;
Timer timer;
LED led;

Song::Song(unsigned int tempo, const char* music) : tempo(tempo), music(music) { };

void Song::addLightShow(unsigned int lightShowSize, const LightScene* lightShow) {
  this->lightShowSize = lightShowSize;
  this->lightShow = lightShow;
}

void Song::play() {
  const int quarterNote = 60000 / tempo;

  for (int i = 0; i < strlen(music); ++i) {
    char note = music[i];
    if (note == ' ') { continue; }
    
    bool isRest = false;
    bool isAccented = false;

    if (note == 'r') {
      isRest = true;
      note = music[++i];
    } else if (note == '>') {
      isAccented = true;
      note = music[++i];
    }

    int multiplier = 1;
    if (isdigit(note)) {
      multiplier = note - '0';
      note = music[++i];
    }

    double duration = quarterNote * getNoteDuration(note) * multiplier;
    playNote(duration, isRest, isAccented);
  }

  led.turn_off_all();
};

double Song::getNoteDuration(char note) {
  double duration = 1.0;

  switch(note) {
    case 'S':
    case 's':
      duration /= 4;
      break;

    case 'E':
    case 'e':
      duration /= 2;
      break;

    case 'Q':
    case 'q':
      break;

    case 'H':
    case 'h':
      duration *= 2;
      break;

    case 'W':
    case 'w':
      duration *= 4;
      break;
  }

  if (isupper(note)) {
    duration *= 1.5;
  }

  return duration;
}

void Song::playNote(unsigned int duration, bool isRest, bool isAccented) {
  if (isRest) {
    led.turn_off_all();
  } else {
    if (lightShowSize > 0) {
      cycleLightShow();
    }

    int intensity = isAccented ? 127 : 40;
    buzzer.custom_buzz(intensity, duration - TIME_BETWEEN_NOTES);
  }
  
  timer.pause(duration / 2);
  if (isAccented) { led.turn_off_all(); }
  timer.pause(duration / 2);
}

void Song::cycleLightShow() {
  ++lightShowIndex;
  lightShowIndex %= lightShowSize;

  LightScene lightScene = lightShow[lightShowIndex];

  led.turn_on_single(SW, lightScene.sw);
  led.turn_on_single(NW, lightScene.nw);
  led.turn_on_single(NE, lightScene.ne);
  led.turn_on_single(SE, lightScene.se);
}