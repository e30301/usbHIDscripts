from GDI_effects.GDI import *
import time
import random
import win32api
import ctypes as c

g = c.windll.gdi32
d = c.windll.user32.GetDC(0)


def main():
    last_x, last_y = win32api.GetCursorPos()
    last_time = time.perf_counter()
    keys_down = set()

    while True:
        x, y = win32api.GetCursorPos()
        now = time.perf_counter()

        distance = ((x - last_x) ** 2 + (y - last_y) ** 2) ** 0.5
        dt = now - last_time
        speed = distance / dt if dt > 0 else 0

        last_x, last_y = x, y

        if speed > 0:
            Effects.glitch_screen(repeat=5)

        for key in range(8, 256):
            is_down = bool(win32api.GetAsyncKeyState(key) & 0x8000)

            if is_down and key not in keys_down:
                keys_down.add(key)

                x_offset = random.randint(-50, 50)
                y_offset = random.randint(-50, 50)

                g.StretchBlt(
                    d,
                    x_offset, y_offset,
                    1900, 1060,
                    d,
                    0, 0,
                    1920, 1080,
                    0xCC0020
                )

            elif not is_down:
                keys_down.discard(key)

        last_time = now


if __name__ == "__main__":
    main()
