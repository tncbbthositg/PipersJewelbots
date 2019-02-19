#include <ctype.h>;
#include "src/Song.h";

#define ARRAY_SIZE(array) sizeof(array) / sizeof(array[0])

Animation animation;

Song warEagle(280, "whhqhqH rq qhqhhqhqH rq whhqhqH rq qhqqqhq rq >h>h>h HqhhqhqH rq qqhqqhqhqq rq >q rq whhhhhhqhqhh 5q rqrh");
const LightScene AUBURN_LIGHT_SHOW[] = {
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },
  { ORANGE, BLUE, ORANGE, BLUE },
  { BLUE, ORANGE, BLUE, ORANGE },

  { ORANGE, ORANGE, ORANGE, ORANGE },
  
  { BLUE, ORANGE, ORANGE, ORANGE },
  { ORANGE, BLUE, ORANGE, ORANGE },
  { ORANGE, ORANGE, BLUE, ORANGE },
  { ORANGE, ORANGE, ORANGE, BLUE },
  { ORANGE, ORANGE, BLUE, ORANGE },
  { ORANGE, BLUE, ORANGE, ORANGE },
  { BLUE, ORANGE, ORANGE, ORANGE },

  { ORANGE, ORANGE, ORANGE, ORANGE },
  
  { BLUE, BLUE, ORANGE, ORANGE },
  { ORANGE, ORANGE, BLUE, BLUE },
  { BLUE, BLUE, ORANGE, ORANGE },
  { ORANGE, ORANGE, BLUE, BLUE },
  { BLUE, BLUE, ORANGE, ORANGE },
  { ORANGE, ORANGE, BLUE, BLUE },
  
  { ORANGE, BLUE, BLUE, ORANGE },
  { BLUE, ORANGE, ORANGE, BLUE },
  { ORANGE, BLUE, BLUE, ORANGE },
  { BLUE, ORANGE, ORANGE, BLUE },
  { ORANGE, BLUE, BLUE, ORANGE },
  { BLUE, ORANGE, ORANGE, BLUE },

  { ORANGE, ORANGE, ORANGE, ORANGE },
};

Song letItGo(138, "ee6e ee5e re eeqeeqqqeq re ee6e ee7e eqqQq8e >Q>Q>4q q>Q>Q>4q ee>Q>Q>8q eqeeeeeee e7e");
const LightScene LET_IT_GO_LIGHT_SHOW[] = {
  { PURPLE, OFF, OFF, OFF },
  { PURPLE, PURPLE, OFF, OFF },
  { PURPLE, PURPLE, PURPLE, OFF },
  { PURPLE, PURPLE, PURPLE, PURPLE },

  { PURPLE, BLUE, PURPLE, PURPLE },
  { PURPLE, PURPLE, PURPLE, BLUE },
  { BLUE, PURPLE, PURPLE, PURPLE },
  { PURPLE, PURPLE, BLUE, PURPLE },
  { PURPLE, BLUE, PURPLE, PURPLE },
  { PURPLE, PURPLE, PURPLE, BLUE },
  { BLUE, PURPLE, PURPLE, PURPLE },
  { PURPLE, PURPLE, BLUE, PURPLE },

  { OFF, WHITE, OFF, OFF },  
  { OFF, OFF, OFF, WHITE },  
  { OFF, OFF, WHITE, OFF },  
  { OFF, OFF, OFF, WHITE },  
  { WHITE, OFF, OFF, OFF },  
  { OFF, OFF, WHITE, OFF },  
  { OFF, WHITE, OFF, OFF },  
  { OFF, OFF, OFF, WHITE },  
};

Song* songs[] = { &warEagle, &letItGo };
const unsigned int songCount = ARRAY_SIZE(songs);
int currentSong = -1;

void setup() {
  warEagle.addLightShow(ARRAY_SIZE(AUBURN_LIGHT_SHOW), AUBURN_LIGHT_SHOW);
  letItGo.addLightShow(ARRAY_SIZE(LET_IT_GO_LIGHT_SHOW), LET_IT_GO_LIGHT_SHOW);
}

void loop() {
}

void button_press(void) {
  currentSong = ++currentSong % songCount;
  Song* song = songs[currentSong];

  song->play();
}

void button_press_long(void) {
}

void charging_button_press(void) {
  button_press();
}
