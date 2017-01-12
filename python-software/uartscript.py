#!/usr/bin/env python
import serial
import sys


ser = None
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

ser.write("\xAA" + ''.join(chr(int(x, 16)) for x in sys.argv[1:]))

#  print(hex(ord(ser.read())))
