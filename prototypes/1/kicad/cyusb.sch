EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:TI_tvp7002pzp
LIBS:vga
LIBS:prototype1-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_02X20 P5
U 1 1 583A355A
P 3350 3550
F 0 "P5" H 3350 4600 50  0000 C CNN
F 1 "CONN_02X20" V 3350 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20" H 3350 2600 50  0001 C CNN
F 3 "" H 3350 2600 50  0000 C CNN
	1    3350 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X20 P6
U 1 1 583A35EB
P 5150 3550
F 0 "P6" H 5150 4600 50  0000 C CNN
F 1 "CONN_02X20" V 5150 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20" H 5150 2600 50  0001 C CNN
F 3 "" H 5150 2600 50  0000 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR063
U 1 1 583A3689
P 3350 4700
F 0 "#PWR063" H 3350 4450 50  0001 C CNN
F 1 "GND" H 3350 4550 50  0000 C CNN
F 2 "" H 3350 4700 50  0000 C CNN
F 3 "" H 3350 4700 50  0000 C CNN
	1    3350 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR064
U 1 1 583A370D
P 5150 4700
F 0 "#PWR064" H 5150 4450 50  0001 C CNN
F 1 "GND" H 5150 4550 50  0000 C CNN
F 2 "" H 5150 4700 50  0000 C CNN
F 3 "" H 5150 4700 50  0000 C CNN
	1    5150 4700
	1    0    0    -1  
$EndComp
Text GLabel 2950 3500 0    60   Input ~ 0
AVR_TXD
Text GLabel 2950 3600 0    60   Input ~ 0
AVR_RXD
Text GLabel 4750 4500 0    60   Input ~ 0
TVP_I2C_SDA
Text GLabel 5550 4500 2    60   Input ~ 0
TVP_I2C_SCL
Text GLabel 5550 4400 2    60   Input ~ 0
G0
Text GLabel 5550 4300 2    60   Input ~ 0
G1
Text GLabel 5550 4200 2    60   Input ~ 0
G2
Text GLabel 5550 4100 2    60   Input ~ 0
G3
Text GLabel 5550 4000 2    60   Input ~ 0
G4
Text GLabel 5550 3900 2    60   Input ~ 0
G5
Text GLabel 5550 3800 2    60   Input ~ 0
G6
Text GLabel 5550 3700 2    60   Input ~ 0
G7
Text GLabel 5550 3600 2    60   Input ~ 0
B0
Text GLabel 5550 3500 2    60   Input ~ 0
B1
Text GLabel 5550 3400 2    60   Input ~ 0
B2
Text GLabel 5550 3300 2    60   Input ~ 0
B3
Text GLabel 5550 3200 2    60   Input ~ 0
B4
Text GLabel 5550 3100 2    60   Input ~ 0
B5
Text GLabel 5550 3000 2    60   Input ~ 0
B6
Text GLabel 5550 2900 2    60   Input ~ 0
B7
Text GLabel 3700 4400 2    60   Input ~ 0
R0
Text GLabel 3700 4300 2    60   Input ~ 0
R1
Text GLabel 3700 4200 2    60   Input ~ 0
R2
Text GLabel 3700 4100 2    60   Input ~ 0
R3
Text GLabel 3700 4000 2    60   Input ~ 0
R4
Text GLabel 3700 3900 2    60   Input ~ 0
R5
Text GLabel 3700 3800 2    60   Input ~ 0
R6
Text GLabel 3700 3700 2    60   Input ~ 0
R7
Text GLabel 4750 4300 0    60   Input ~ 0
TVP_DATACLK
Text GLabel 4750 3000 0    60   Input ~ 0
TVP_HSOUT
Text GLabel 4750 2900 0    60   Input ~ 0
TVP_VSOUT
Wire Wire Line
	3100 3200 3050 3200
Wire Wire Line
	3050 3200 3050 4600
Wire Wire Line
	3050 3300 3100 3300
Wire Wire Line
	3050 3400 3100 3400
Connection ~ 3050 3300
Wire Wire Line
	3050 3800 3100 3800
Connection ~ 3050 3400
Wire Wire Line
	3050 4000 3100 4000
Connection ~ 3050 3800
Wire Wire Line
	3050 4500 3100 4500
Connection ~ 3050 4000
Wire Wire Line
	3600 4500 3650 4500
Wire Wire Line
	3650 4500 3650 4600
Wire Wire Line
	3650 4600 3050 4600
Connection ~ 3050 4500
Wire Wire Line
	3350 4700 3350 4600
Connection ~ 3350 4600
Wire Wire Line
	4900 2800 4850 2800
Wire Wire Line
	4850 2800 4850 4600
Wire Wire Line
	4850 4400 4900 4400
Wire Wire Line
	5400 2800 5450 2800
Wire Wire Line
	5450 2800 5450 4600
Wire Wire Line
	5450 4600 4850 4600
Connection ~ 4850 4400
Wire Wire Line
	5150 4700 5150 4600
Connection ~ 5150 4600
Wire Wire Line
	3100 3600 2950 3600
Wire Wire Line
	3100 3500 2950 3500
Wire Wire Line
	4750 4500 4900 4500
Wire Wire Line
	5400 4500 5550 4500
Wire Wire Line
	5550 3700 5400 3700
Wire Wire Line
	5550 3800 5400 3800
Wire Wire Line
	5550 3900 5400 3900
Wire Wire Line
	5550 4000 5400 4000
Wire Wire Line
	5400 4100 5550 4100
Wire Wire Line
	5550 4200 5400 4200
Wire Wire Line
	5550 4300 5400 4300
Wire Wire Line
	5550 4400 5400 4400
Wire Wire Line
	5400 2900 5550 2900
Wire Wire Line
	5400 3000 5550 3000
Wire Wire Line
	5400 3100 5550 3100
Wire Wire Line
	5400 3200 5550 3200
Wire Wire Line
	5400 3300 5550 3300
Wire Wire Line
	5400 3400 5550 3400
Wire Wire Line
	5400 3500 5550 3500
Wire Wire Line
	5400 3600 5550 3600
Wire Wire Line
	3700 3700 3600 3700
Wire Wire Line
	3700 3800 3600 3800
Wire Wire Line
	3600 3900 3700 3900
Wire Wire Line
	3600 4000 3700 4000
Wire Wire Line
	3600 4100 3700 4100
Wire Wire Line
	3600 4200 3700 4200
Wire Wire Line
	3600 4300 3700 4300
Wire Wire Line
	3600 4400 3700 4400
Wire Wire Line
	4750 4300 4900 4300
Text GLabel 4750 4000 0    60   Input ~ 0
TVP_PWDN
Text GLabel 4750 4100 0    60   Input ~ 0
TVP_RESET
$Comp
L +3.3V #PWR065
U 1 1 583A5602
P 3050 2550
F 0 "#PWR065" H 3050 2400 50  0001 C CNN
F 1 "+3.3V" H 3050 2690 50  0000 C CNN
F 2 "" H 3050 2550 50  0000 C CNN
F 3 "" H 3050 2550 50  0000 C CNN
	1    3050 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2600 3050 2600
Wire Wire Line
	3050 2600 3050 2550
Wire Wire Line
	4750 3000 4900 3000
Wire Wire Line
	4750 2900 4900 2900
Wire Wire Line
	4750 4100 4900 4100
Wire Wire Line
	4750 4000 4900 4000
$EndSCHEMATC
