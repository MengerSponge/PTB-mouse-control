#pragma once

#define HWSERIAL Serial1

void window_fullscreen(int blinks);
void window_minimize(int blinks);
void flashcount(int blinks, unsigned int blinktime);

void click_ruhe(int blinks, bool sendclick);
void click_messen(int blinks, bool sendclick);
void click_correction(int blinks, bool sendclick);
void click_reorder(int blinks, bool sendclick);
void click_start(int blinks, bool sendclick);
void click_stop(bool sendclick);
void finalize_measurement(int blinks, bool sendclick);
void type_comment(String say);
void delete_comment(int blinks);