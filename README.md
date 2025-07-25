# PTB-mouse-control
Teensy control code for SQUID DAQ computer

## Commands

Send commands as ASCII digits to the USB-UART adapter. Teensy will echo back the command (as a string) after executing the requested command.

| ASCII | Command | Echo |
-: | :-----------: | :--:
0 | COMMENT | comment
1 | RUHE | ruhe
2 | MESSEN | messen
3 | CORRECTION | correction
4 | REORDER | reorder
5 | START | start
6 | STOP | stop
7 | COMMENTLOG| _nothing_


### STOP
Stop executes three mouse clicks:

 1. Click stop
 2. Click Okay (window with comments)
 3. Click Okay (window to verify)

## Building
To compile this project, follow the instructions for the Teensy 4.1 board:

https://www.pjrc.com/teensy/td_download.html

The Arduino IDE will compile this project, and the Teensy loader will load the compiled code to the Teensy board.

## Notes

The board needs to mount as a keyboard+mouse, which should be set in Tools>"USB Type"

The click coordinates use Windows display coordinates (0,0) is top-left. It is easiest to measure these coordinates with the "AutoHotKey Dash" > "Windows Spy" utility. AutoHotKey is installed on the DAQ computer.
