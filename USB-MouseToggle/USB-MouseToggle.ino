// Remember to open Teensy loader in C:/Tools

#include "usb-tether.h"

#define HWSERIAL Serial1

// The following constant determines if each command issues a mouse click or not. To debug/test, set to false.
const bool clickmouse = true;
const bool resizewindows = true;

const int ledPin = 13;
bool blink = LOW;
String words;

int mode = 1;
// Commands are associated with the "mode" enum type. Send the corresponding ASCII number (0-6) to execute the associated command;
enum mode { COMMENT, // !
            RUHE, // "
            MESSEN, // #
            CORRECTION, // $
            REORDER, // %
            START, // &
            STOP, // '
            STOPNOCOMMENT, // (
            TEST // )
            };

// CAUTION: Because the board interprets commands serially and uses numbers as the control characters, you *cannot* use numbers in your comment.
// If you want computer-generated numbers, consider Bit shifting them by 10 places

void setup() {
  Mouse.screenSize(1920, 1200);  
  HWSERIAL.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // turn the LED off
  for (int flashes = 0; flashes < 6; flashes++) {
    digitalWrite(ledPin, HIGH);  // set the LED on
    delay(200);
    digitalWrite(ledPin, LOW);  // turn the LED off
    delay(200);
  }
}

// incomingByte shift: 48 for digits 0-9
// incomingByte shift: 33 for characters
// NEWCOMMENT, // !
// RUHE, // "
// MESSEN, // #
// CORRECTION, // $
// REORDER, // %
// START, // &
// STOP, // '
// COMMENTLOG, // (
// TEST // )

void loop() {
  int incomingByte;
  int shiftedByte;

  if (HWSERIAL.available() > 0) {
    incomingByte = HWSERIAL.read();

    shiftedByte = incomingByte - 33;
    switch (shiftedByte) {
      case COMMENT:
        HWSERIAL.print("Accumulating comment.");
        // words = "";
        words = "";
        break;

      case RUHE:
        click_ruhe(1, clickmouse);
        HWSERIAL.print("ruhe");
        break;

      case MESSEN:
        click_messen(2, clickmouse);
        HWSERIAL.print("messen");
        break;

      case CORRECTION:
        click_correction(3, clickmouse);
        HWSERIAL.print("correction");
        break;

      case REORDER:
        click_reorder(4, clickmouse);
        HWSERIAL.print("reorder");
        break;
      
      case START:
        click_start(5, clickmouse);
        HWSERIAL.print("start");
        break;

      case STOP:
        click_stop(clickmouse);
        click_comment_field(clickmouse);
        delete_comment(1);
        type_comment(words);
        finalize_measurement(6, clickmouse);
        HWSERIAL.print("stop");
        words = "";
        break;
      case STOPNOCOMMENT:
        click_stop(clickmouse);
        finalize_measurement(6, clickmouse);
        HWSERIAL.print("stop no comment");
        break;
      case TEST:
        type_comment(words);
        words = "";
        HWSERIAL.print("test typing");
        break;
      default:
        // HWSERIAL.print("comments incoming");
        words +=char(incomingByte);
        // HWSERIAL.print(words);
        break;
    }
  }
}