#!/usr/bin/env python3
import subprocess
import time
import sys

breakpoints = []					# List of all address to breakpoint on.
#breakpoints.append('D748')				# Beginning of code
#breakpoints.append('D943')

resolution = subprocess.check_output(["/bin/bash", "-c", "xrandr | grep \"*\""]).decode("utf-8")
resolution = resolution.strip().split(" ")[0].split("x")
resolution = (int(resolution[0]), int(resolution[1]))

title = "TilEm Debugger"
get = lambda x: subprocess.check_output(["/bin/bash", "-c", x]).decode("utf-8")
bad = []

while True:
    try:
        windows = [w.split()[0:3] for w in get("wmctrl -lp 2>/dev/null").splitlines() if title in w]
        windows = [window for window in windows if window not in bad]
        if len(windows) > 0:
            window_id = windows[0][0]
            cmds = []
            cmds.append("wmctrl -ir "+window_id+" -b remove,maximized_horz")
            cmds.append("wmctrl -ir "+window_id+" -b remove,maximized_vert")
            cmds.append("xdotool windowsize "+window_id+" 50% 100%")
            cmds.append("xdotool windowmove "+window_id+" " + str(int(resolution[0]/2)) + " 0")
            cmds.append("xdotool windowactivate "+window_id)
            for cmd in cmds:
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
	time.sleep(0.1)
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
time.sleep(0.05)
pyautogui.press('f5')
