#include <ctype.h>;

LED led;
Timer timer;
Buzzer buzzer;
Animation animation;

const int TEMPO = 260;
const int QUARTER_NOTE = 60000 / TEMPO;
const int TIME_BETWEEN_NOTES = 60;

struct LightShow {
  ColorLabel sw;
  ColorLabel nw;
  ColorLabel ne;
  ColorLabel se;
};

const LightShow LIGHT_SHOWS[] = {
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },
};
const int LIGHT_SHOW_COUNT = sizeof(LIGHT_SHOWS) / sizeof(LIGHT_SHOWS[0]);

int lightShowIndex = -0;

void setup() {
}

void loop() {
}

void button_press(void) {
  playSong("whhqhqH rq qhqhhqhqH rq whhqhqH rq qhqqqhq rq >h>h>h HqhhqhqH rq qqhqqhqhqq rq >q rq whhhhhhqhqhh 5q rqrh");
}

void button_press_long(void) {
}

void charging_button_press(void) {
}

void playSong(const char* song) {
  for (int i = 0; i < strlen(song); ++i) {
    char note = song[i];
    if (note == ' ') { continue; }
    
    bool isRest = false;
    bool isAccented = false;

    if (note == 'r') {
      isRest = true;
      note = song[++i];
    } else if (note == '>') {
      isAccented = true;
      note = song[++i];
    }

    int multiplier = 1;
    if (isdigit(note)) {
      multiplier = note - '0';
      note = song[++i];
    }

    int duration = getNoteDuration(note);
    duration *= multiplier;
    
    playNote(duration, isRest, isAccented);
  }

  led.turn_off_all();
}

int getNoteDuration(char note) {
  int duration = QUARTER_NOTE;

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

void playNote(int duration, bool isRest, bool isAccented) {
  if (isRest) {
    led.turn_off_all();
  } else {
    cycleLightShow();

    int intensity = isAccented ? 127 : 40;
    buzzer.custom_buzz(intensity, duration - TIME_BETWEEN_NOTES);
  }
  
  timer.pause(duration / 2);
  if (isAccented) { led.turn_off_all(); }
  timer.pause(duration / 2);
}

void cycleLightShow() {
  ++lightShowIndex;
  lightShowIndex %= LIGHT_SHOW_COUNT;

  LightShow lightShow = LIGHT_SHOWS[lightShowIndex];

  led.turn_on_single(SW, lightShow.sw);
  led.turn_on_single(NW, lightShow.nw);
  led.turn_on_single(NE, lightShow.ne);
  led.turn_on_single(SE, lightShow.se);
}
