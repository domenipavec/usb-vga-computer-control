#!/usr/bin/env python
import serial
import sys


ser = None
for i in range(3):
    try:
        ser = serial.Serial('/dev/ttyACM{n}'.format(n=i), 19200)
    except serial.serialutil.SerialException:
        pass

    print("Connected to: " + ser.name)


if len(sys.argv) == 2:
    ser.write(sys.argv[1])
else:
    print("Usage: ./uartscript.py data")

print(hex(ord(ser.read())))
