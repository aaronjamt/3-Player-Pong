#!/usr/bin/env python3
import subprocess
import time
import sys

breakpoints = []					# List of all address to breakpoint on.
#breakpoints.append('D748')			# Beginning of code
#breakpoints.append('D9BD')


title = "TilEm Debugger"
get = lambda x: subprocess.check_output(["/bin/bash", "-c", x]).decode("utf-8")
bad = []

while True:
    try:
        windows = [w.split()[0:3] for w in get("wmctrl -lp 2>/dev/null").splitlines() if title in w]
        windows = [window for window in windows if window not in bad]
        if len(windows) > 0:
            window_id = windows[0][0]
            cmd1 = "wmctrl -ir "+window_id+" -b remove,maximized_horz"
            cmd2 = "wmctrl -ir "+window_id+" -b remove,maximized_vert"
            cmd3 = "xdotool windowsize "+window_id+" 50% 100%"
            cmd4 = "xdotool windowmove "+window_id+" 960 0"
            for cmd in [cmd1, cmd2, cmd3, cmd4]:
                try:
                    subprocess.call(["/bin/bash", "-c", cmd])
                except:
                    bad.append(window)
                    time.sleep(0.5)
                    continue
            break
        time.sleep(0.1)
    except:
        time.sleep(0.5)
        
import pyautogui

if len(breakpoints) > 0:
	pyautogui.hotkey('ctrl', 'b')
	time.sleep(0.2)
	pyautogui.press('tab')
	for addr in breakpoints:
		pyautogui.press('return')
		time.sleep(0.1)
		pyautogui.write(addr)
		time.sleep(0.1)
		pyautogui.press(['tab', 'tab'])
		time.sleep(0.1)
		pyautogui.press('return')
		time.sleep(0.1)
	pyautogui.press('esc')
time.sleep(0.1)
pyautogui.press('f5')
