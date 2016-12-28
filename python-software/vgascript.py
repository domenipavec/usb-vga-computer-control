#!/usr/bin/env python
import cv2
import time
from subprocess import call

call(["v4l2-ctl", "-v", "height=480", "-v", "width=640", "-v", "pixelformat=YUY2"])

cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

t = time.time()
i = 0
while cap.isOpened():
    i += 1
    r, frame = cap.read()
    if i % 10 == 0:
        t1 = time.time()
        print(10/(t1-t))
        t = t1
    #  frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    #  frame[:, :, 2] = 0
    #  frame[:, :, 1] = 0
    #  print(frame[-50, -50, :])

    cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

