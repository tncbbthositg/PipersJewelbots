#include <ctype.h>;

LED led;
Timer timer;
Buzzer buzzer;
Animation animation;

const int TIME_BETWEEN_NOTES = 60;

struct LightScene {
  ColorLabel sw;
  ColorLabel nw;
  ColorLabel ne;
  ColorLabel se;
};

char* WAR_EAGLE = "whhqhqH rq qhqhhqhqH rq whhqhqH rq qhqqqhq rq >h>h>h HqhhqhqH rq qqhqqhqhqq rq >q rq whhhhhhqhqhh 5q rqrh";
const LightScene AUBURN_LIGHT_SHOW[] = {
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },
};

int lightShowIndex = -0;

void setup() {
}

void loop() {
}

void button_press(void) {
  playSong(260, WAR_EAGLE);
}

void button_press_long(void) {
}

void charging_button_press(void) {
  button_press();
}

void playSong(int tempo, const char* song) {
  const int quarterNote = 60000 / tempo;

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

    double duration = quarterNote * getNoteDuration(note) * multiplier;
    playNote(duration, isRest, isAccented);
  }

  led.turn_off_all();
}

double getNoteDuration(char note) {
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
  int lightShowSize = sizeof(AUBURN_LIGHT_SHOW) / sizeof(AUBURN_LIGHT_SHOW[0]);

  ++lightShowIndex;
  lightShowIndex %= lightShowSize;

  LightScene lightScene = AUBURN_LIGHT_SHOW[lightShowIndex];

  led.turn_on_single(SW, lightScene.sw);
  led.turn_on_single(NW, lightScene.nw);
  led.turn_on_single(NE, lightScene.ne);
  led.turn_on_single(SE, lightScene.se);
}
