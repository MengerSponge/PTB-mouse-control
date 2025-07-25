void flashcount(int blinks) {
  int flashes;
  digitalWrite(ledPin, LOW);  // turn the LED off
  for (flashes = 0; flashes < blinks; flashes++) {
    digitalWrite(ledPin, HIGH);  // set the LED on
    delay(500);
    digitalWrite(ledPin, LOW);  // turn the LED off
    delay(500);
  }
}

void click_ruhe(int blinks, bool sendclick) {
// top left:  ( 8, 928)
// bot right: (78, 945)
// target:    (43, 936)
  // unsigned short midx = 43;
  // unsigned short midy = 936;
  Mouse.moveTo(43, 936);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks);
}

void click_messen(int blinks, bool sendclick) {
// top left:  ( 80, 975)
// bot right: (144, 994)
// target:    (110, 980)
  Mouse.moveTo(110, 980);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks);
}

void click_correction(int blinks, bool sendclick) {
// top left:  (841, 1119)
// bot right: (905, 1147)
// target:    (870, 1130)
  Mouse.moveTo(870, 1130);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks);
}

void click_reorder(int blinks, bool sendclick) {
// top left:  (1879, 545)
// bot right: (1917, 568)
// target:    (1900, 555)
  Mouse.moveTo(1900, 555);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks);
}

void click_start(int blinks, bool sendclick) {
// top left:  (53, 103)
// bot right: (74, 124)
// target:    (65, 110)
  Mouse.moveTo(65, 110);
  if (sendclick) {
    Mouse.click();
  }
  flashcount(blinks);
}

void click_stop(int blinks, bool sendclick) {
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
  // 2) Comment
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
  flashcount(blinks);
}

void type_comment(String say) {
  delay(2000);
  Keyboard.print(say);
}