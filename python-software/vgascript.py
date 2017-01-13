#!/usr/bin/env python
import cv2
import numpy
import pygame
import serial
from subprocess import call
import time

from keys import keymap, modifiers

WINDOW = 'Usb vga computer control'

ser = None


def format_uint16(i):
    return chr(i & 0xff) + chr((i >> 8) & 0xff)


def scale(i, fs):
    return i*32767//fs


def send(data):
    if ser is None:
        return
    data = '\xAA' + data
    print("Sending: ", [hex(ord(c)) for c in data])
    ser.write(data)


buttonstate = 0
modifiersstate = 0
keys = []


def set_button(i):
    global buttonstate
    buttonstate |= (1 << i)
    print(buttonstate)
    send('\x02' + chr(buttonstate))


def clear_button(i):
    global buttonstate
    buttonstate &= ~(1 << i)
    print(buttonstate)
    send('\x02' + chr(buttonstate))


def set_modifier(k):
    global modifiersstate
    if k in modifiers:
        modifiersstate |= (1 << modifiers[k])


def clear_modifier(k):
    global modifiersstate
    if k in modifiers:
        modifiersstate &= ~(1 << modifiers[k])


def map_key(k):
    if k in keymap:
        return keymap[k]
    else:
        return None


def send_keys():
    data = ''.join(chr(k) for k in keys[:6])
    for i in range(6 - len(data)):
        data += '\x00'
    send('\x04' + data + chr(modifiersstate))


def set_key(k):
    global keys
    set_modifier(k)
    k = map_key(k)
    if k is not None:
        keys.append(k)
    send_keys()


def clear_key(k):
    global keys
    clear_modifier(k)
    k = map_key(k)
    if k is not None:
        keys.remove(k)
    send_keys()


call(["v4l2-ctl", "-v", "height=480", "-v", "width=640", "-v", "pixelformat=YUY2"])

cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

screen = pygame.display.set_mode((640, 480))

error = None
for i in range(3):
    error = None
    try:
        ser = serial.Serial('/dev/ttyACM{n}'.format(n=i), 19200)
        print("Connected to: " + ser.name)
        break
    except serial.serialutil.SerialException as e:
        error = e

if error is not None:
    raise error

t = time.time()
i = 0
while cap.isOpened():
    i += 1
    r, frame = cap.read()
    if i % 10 == 0:
        t1 = time.time()
        print(10/(t1-t))
        t = t1

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
        elif event.type == pygame.MOUSEMOTION:
            x = scale(event.pos[0], 640)
            y = scale(event.pos[1], 480)
            data = '\x01' + format_uint16(x) + format_uint16(y)
            send(data)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:
                data = '\x03' + format_uint16(x) + format_uint16(y) + '\x01'
                send(data)
            elif event.button == 2:
                set_button(2)
            elif event.button == 3:
                set_button(1)
        elif event.type == pygame.MOUSEBUTTONUP:
            if event.button == 1:
                data = '\x03' + format_uint16(x) + format_uint16(y) + '\x00'
                send(data)
            elif event.button == 2:
                clear_button(2)
            elif event.button == 3:
                clear_button(1)
        elif event.type == pygame.KEYDOWN:
            set_key(event.key)
        elif event.type == pygame.KEYUP:
            clear_key(event.key)

        print(event)

    frame = numpy.rot90(frame)
    frame = numpy.flipud(frame)
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    frame = pygame.surfarray.make_surface(frame)
    screen.blit(frame, (0, 0))
    pygame.display.flip()
