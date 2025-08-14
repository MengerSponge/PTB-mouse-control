// Remember to open Teensy loader in C:/Tools

#include "usb-tether.h"

#define HWSERIAL Serial1

// The following constant determines if each command issues a mouse click or not. To debug/test, set to false.
const bool clickmouse = true;
const bool resizewindows = true;


// The board typically accumulates characters to the comment string. If the control character \ is received, the next character is interpreted as a command.
bool commandmode = false;

const int ledPin = 13;
bool blink = LOW;
String words;

int mode = 1;
// Commands are associated with the "mode" enum type. Send the corresponding ASCII number (0-8) to execute the associated command;
enum mode { COMMENT,        // 0
            RUHE,           // 1
            MESSEN,         // 2
            CORRECTION,     // 3
            REORDER,        // 4
            START,          // 5
            STOP,           // 6
            STOPNOCOMMENT,  // 7
            TEST            // 8
};

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

void loop() {
  int incomingByte;
  int shiftedByte;

  if (HWSERIAL.available() > 0) {
    incomingByte = HWSERIAL.read();

    if (commandmode) {
      shiftedByte = incomingByte - 48;
      switch (shiftedByte) {
        case COMMENT:
          // Reset the accumulated comment string without logging it.
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
          // attempt to replace all text in the comment field with the comment string supplied.
          click_stop(clickmouse);
          click_comment_field(clickmouse);
          delete_comment(1);
          type_comment(words);
          finalize_measurement(6, clickmouse);
          HWSERIAL.print("stop");
          words = "";
          break;
        case STOPNOCOMMENT:
          // the comment field is not edited with this command.
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
          break;
      }
      commandmode = false;
    } else {
      if (incomingByte != 92){
        words += char(incomingByte);
      }
    }
    if (incomingByte == 92) {
      commandmode = true;
    }
  }
}