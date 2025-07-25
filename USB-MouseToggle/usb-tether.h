#pragma once

#define HWSERIAL Serial1

void flashcount(int blinks);

void click_ruhe(int blinks, bool sendclick);
void click_messen(int blinks, bool sendclick);
void click_correction(int blinks, bool sendclick);
void click_reorder(int blinks, bool sendclick);
void click_start(int blinks, bool sendclick);
void click_stop(int blinks, bool sendclick);
void type_comment(String say);