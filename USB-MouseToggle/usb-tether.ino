void window_minimize(int blinks) {
  digitalWrite(ledPin, LOW);

  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_DOWN);
  Keyboard.send_now();

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  flashcount(blinks, 125);
  // Keyboard.set_modifier(MODIFIERKEY_CTRL);
}

void window_fullscreen(int blinks) {
  digitalWrite(ledPin, LOW);

  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_UP);
  Keyboard.send_now();

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  flashcount(blinks, 125);
  // Keyboard.set_modifier(MODIFIERKEY_CTRL);
}

void flashcount(int blinks, int blinktime) {
  int flashes;
  digitalWrite(ledPin, LOW);  // turn the LED off
  for (flashes = 0; flashes < blinks; flashes++) {
    digitalWrite(ledPin, HIGH);  // set the LED on
    delay(blinktime);
    digitalWrite(ledPin, LOW);  // turn the LED off
    if (flashes < blinks) {
      delay(blinktime);
    }
  }
}

void click_ruhe(int blinks, bool sendclick) {
  // top left:  ( 5, 54)
  // bot right: (74, 74)
  // target:    (50, 68)

  // set focused application to windows bar
  Mouse.moveTo(1370, 1189);
  Mouse.click();
  delay(40);
  // 126-Kanal menu bar location
  // top left: (483, 1171)
  // bottom left: (513, 1195)
  // target (495, 1180)
  Mouse.moveTo(495, 1180);
  Mouse.click();
  delay(40);

  window_fullscreen(8);
  Mouse.moveTo(50, 68);
  if (sendclick) {
    Mouse.click();
  }
  window_minimize(8);
  flashcount(blinks, 200);
}

void click_messen(int blinks, bool sendclick) {
  // top left:  ( 79, 103)
  // bot right: (141, 123)
  // target:    (120, 110)

  // set focused application to windows bar
  Mouse.moveTo(1370, 1189);
  Mouse.click();
  delay(40);

  // 126-Kanal menu bar location
  // top left: (483, 1171)
  // bottom left: (513, 1195)
  // target (495, 1180)
  Mouse.moveTo(495, 1180);
  Mouse.click();
  delay(40);

  window_fullscreen(8);
  // windowmode(8, 1);
  Mouse.moveTo(120, 110);
  if (sendclick) {
    Mouse.click();
  }

  window_minimize(8);


  flashcount(blinks, 200);
}

void click_correction(int blinks, bool sendclick) {
  // top left:  (841, 1119)
  // bot right: (905, 1147)
  // target:    (870, 1130)
  Mouse.moveTo(870, 1130);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks, 500);
}

void click_reorder(int blinks, bool sendclick) {
  // top left:  (1879, 545)
  // bot right: (1917, 568)
  // target:    (1900, 555)
  Mouse.moveTo(1900, 555);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks, 500);
}

void click_start(int blinks, bool sendclick) {
  // top left:  (53, 103)
  // bot right: (74, 124)
  // target:    (65, 110)
  Mouse.moveTo(65, 110);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks, 500);
}

void click_stop(bool sendclick) {
  // stop, comment, finalize
  // 1) Stop
  // top left:  (80, 104)
  // bot right: (100, 123)
  // target:    (90, 110)
  Mouse.moveTo(90, 110);
  delay(50);
  if (sendclick) {
    Mouse.click();
  }
  delay(400);
}

void finalize_measurement(int blinks, bool sendclick){
  // 2) Comment
  // Ok button
  // top left:  (858, 828)
  // bot right: (942, 846)
  // target:    (900, 833)
  Mouse.moveTo(900, 833);
  delay(1);
  Mouse.move(-1, -1);
  delay(1);
  Mouse.move(1, 1);
  delay(50);
  if (sendclick) {
    Mouse.click();
  }
  delay(400);
  // 3) Finalize;
  // top left:  (953, 631)
  // bot right: (1033, 647)
  // target:    (1000, 640)
  Mouse.moveTo(1000, 640);
  delay(1);
  Mouse.move(-1, -1);
  delay(1);
  Mouse.move(1, 1);
  delay(50);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks, 500);
}

void type_comment(String say) {
  delay(200);
  char *token = strtok(say.c_str(), "|");
  // char delimiters[] = ":|";
  while (token != NULL) {
    Keyboard.print(token);
    token = strtok(NULL, "|");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  }
  // Keyboard.print(say);
}

void delete_comment(int blinks){

  for (int i=0; i<20; i++){
    Keyboard.press(KEY_DOWN);
    Keyboard.release(KEY_DOWN);
    delay(40);
  }
  Keyboard.press(KEY_END);
  Keyboard.release(KEY_END);
  delay(50);

  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_HOME);
  Keyboard.send_now();
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_UP);
  Keyboard.send_now();
  for (int i=0; i<20; i++){
    delay(50);
    Keyboard.send_now();
  }
  for (int i=0; i<30; i++){
  Keyboard.press(KEY_BACKSPACE);
  Keyboard.release(KEY_BACKSPACE);
  delay(40);
  }
  // flashcount(blinks, 125);
}

void click_comment_field(bool sendclick){
  // top left:  (740, 583)
  // bot right: (1159, 639)
  // target:    (1000, 600)
  Mouse.moveTo(1000, 610);
  delay(1);
  Mouse.move(-1, -1);
  delay(1);
  Mouse.move(1, 1);
  delay(50);
  if (sendclick) {
    Mouse.click();
  }
}