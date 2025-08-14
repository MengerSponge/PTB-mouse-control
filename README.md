# PTB-mouse-control
Teensy control code for SQUID DAQ computer

## Special characters

The board defaults to "character accumulation" mode, where received characters are appended to the comment string.

### \
Enable command mode. The next character will be interpreted as a command. If it is not a valid command (e.g. \9) exit command mode silently.

### |
Newline character. If this character is used in the command string, it will be replaced with an "enter" keypress. || will only generate one newline. If you want more than one new line, you get to go play with pointers.

## Commands

Send commands as ASCII digits to the USB-UART adapter. Teensy will echo back the command (as a string) after executing the requested command.

| ASCII | Command | Echo |
-: | :-----------: | :--:
\0 | COMMENT | comment
\1 | RUHE | ruhe
\2 | MESSEN | messen
\3 | CORRECTION | correction
\4 | REORDER | reorder
\5 | START | start
\6 | STOP | stop
\7 | STOPNOCOMMENT | stop no comment
\8 | TEST | _nothing_

### STOP
Stop does several things in sequence:

 1. Click stop
 2. Select the comment field and delete the existing comment.
 3. Type the accumulated comment string in this field.
 4. Click Okay (window with comments)
 5. Click Okay (window to verify)

### TEST

\8 types the accumulated comment string at the current cursor location.

## Building
To compile this project, follow the instructions for the Teensy 4.1 board:

https://www.pjrc.com/teensy/td_download.html

The Arduino IDE will compile this project, and the Teensy loader will load the compiled code to the Teensy board.

## Notes

The board needs to mount as a keyboard+mouse, which should be set in Tools>"USB Type"

The board is set to a "German" keyboard type. Change this if you're using it in a different locale.

The click coordinates use Windows display coordinates (0,0) is top-left. It is easiest to measure these coordinates with the "AutoHotKey Dash" > "Windows Spy" utility. AutoHotKey is installed on the DAQ computer.
