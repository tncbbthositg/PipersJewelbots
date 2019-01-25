LED led;
Timer timer;
Buzzer buzzer;
Animation animation;

void setup() {
  // put your setup code here, to run once:
  animation.rainbows();
  animation.rainbows();
  animation.rainbows();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void button_press(void) {
  showColors(3);
//
//  animation.rainbows();
//  animation.rainbows();

}

void button_press_long(void) {
}

void charging_button_press(void) {
}

void showColors(int seconds) {
  led.turn_on_single(SW, RED);
  led.turn_on_single(NW, GREEN);
  led.turn_on_single(NE, BLUE);
  led.turn_on_single(SE, PURPLE);

  timer.pause(seconds * 1000);
  led.turn_off_all();
}
