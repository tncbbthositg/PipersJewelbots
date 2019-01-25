LED led;
Timer timer;
Buzzer buzzer;
Animation animation;

const int TIME_UNIT_MS = 200;

const char* LETTERS[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
  "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
}

void loop() {
}

void button_press(void) {
  playMessage("I U PIPPY");
}

void playMessage(const char* message) {
  for (int i = 0; i < strlen(message); ++i) {
    playLetter(message[i]);
  }
}

void playLetter(char letter) {
  if (letter == ' ') {
    playSpace();
    return;
  }
  
  int letterIndex = letter - 65;
  const char* code = LETTERS[letterIndex];

  for (int i = 0; i < strlen(code); ++i) {
    if (code[i] == '.') {
      playDot();
    } else {
      playDash();
    }

    timer.pause(TIME_UNIT_MS);
  }

  timer.pause(TIME_UNIT_MS * 2);
}

void playSpace() {
  timer.pause(TIME_UNIT_MS * 7);
}

void playDot() {
  led.turn_on_all(MAGENTA);
  buzzer.custom_buzz(63, TIME_UNIT_MS);
  timer.pause(TIME_UNIT_MS);
  led.turn_off_all();
}

void playDash() {
  led.turn_on_all(PURPLE);
  buzzer.custom_buzz(63, TIME_UNIT_MS * 3);
  timer.pause(TIME_UNIT_MS * 3);
  led.turn_off_all();
}
