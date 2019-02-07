#include <ctype.h>;
#include "src/Song.h";

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

void setup() {
  warEagle.addLightShow(sizeof(AUBURN_LIGHT_SHOW) / sizeof(AUBURN_LIGHT_SHOW[0]), AUBURN_LIGHT_SHOW);
}

void loop() {
}

void button_press(void) {
  warEagle.play();
}

void button_press_long(void) {
}

void charging_button_press(void) {
  button_press();
}
