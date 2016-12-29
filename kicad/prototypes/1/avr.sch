EESchema Schematic File Version 2
LIBS:prototype1-rescue
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
Sheet 4 5
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
L ATTINY841-SSU IC1
U 1 1 5839DF0A
P 5050 3450
F 0 "IC1" H 4200 4200 50  0000 C CNN
F 1 "ATTINY841-SSU" H 5750 2700 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5050 3250 50  0000 C CIN
F 3 "" H 5050 3450 50  0000 C CNN
	1    5050 3450
	1    0    0    -1  
$EndComp
$Comp
L C C36
U 1 1 5839DF60
P 3950 3050
F 0 "C36" H 3975 3150 50  0000 L CNN
F 1 "100nF" H 3975 2950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3988 2900 50  0001 C CNN
F 3 "" H 3950 3050 50  0000 C CNN
	1    3950 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR053
U 1 1 5839DF98
P 3950 4100
F 0 "#PWR053" H 3950 3850 50  0001 C CNN
F 1 "GND" H 3950 3950 50  0000 C CNN
F 2 "" H 3950 4100 50  0000 C CNN
F 3 "" H 3950 4100 50  0000 C CNN
	1    3950 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR054
U 1 1 5839DFB7
P 3950 3250
F 0 "#PWR054" H 3950 3000 50  0001 C CNN
F 1 "GND" H 3950 3100 50  0000 C CNN
F 2 "" H 3950 3250 50  0000 C CNN
F 3 "" H 3950 3250 50  0000 C CNN
	1    3950 3250
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5839E10A
P 7500 3800
F 0 "Y1" H 7500 3950 50  0000 C CNN
F 1 "Crystal" H 7500 3650 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 7500 3800 50  0001 C CNN
F 3 "" H 7500 3800 50  0000 C CNN
	1    7500 3800
	0    1    1    0   
$EndComp
$Comp
L C C38
U 1 1 5839E176
P 7750 3550
F 0 "C38" H 7775 3650 50  0000 L CNN
F 1 "22pF" H 7775 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7788 3400 50  0001 C CNN
F 3 "" H 7750 3550 50  0000 C CNN
	1    7750 3550
	0    1    1    0   
$EndComp
$Comp
L C C39
U 1 1 5839E1D4
P 7750 4050
F 0 "C39" H 7775 4150 50  0000 L CNN
F 1 "22pF" H 7775 3950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7788 3900 50  0001 C CNN
F 3 "" H 7750 4050 50  0000 C CNN
	1    7750 4050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR055
U 1 1 5839E255
P 8000 3550
F 0 "#PWR055" H 8000 3300 50  0001 C CNN
F 1 "GND" H 8000 3400 50  0000 C CNN
F 2 "" H 8000 3550 50  0000 C CNN
F 3 "" H 8000 3550 50  0000 C CNN
	1    8000 3550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR056
U 1 1 5839E276
P 8000 4050
F 0 "#PWR056" H 8000 3800 50  0001 C CNN
F 1 "GND" H 8000 3900 50  0000 C CNN
F 2 "" H 8000 4050 50  0000 C CNN
F 3 "" H 8000 4050 50  0000 C CNN
	1    8000 4050
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X06 P2
U 1 1 5839E4CE
P 9850 1950
F 0 "P2" H 9850 2300 50  0000 C CNN
F 1 "CONN_01X06" V 9950 1950 50  0000 C CNN
F 2 "attiny841-spi:ATTINY841-SPI" H 9850 1950 50  0001 C CNN
F 3 "" H 9850 1950 50  0000 C CNN
	1    9850 1950
	1    0    0    -1  
$EndComp
Text GLabel 9550 1700 0    60   Input ~ 0
AVR_MISO
Text GLabel 9550 1900 0    60   Input ~ 0
AVR_SCK
Text GLabel 9550 2000 0    60   Input ~ 0
AVR_MOSI
Text GLabel 9550 2100 0    60   Input ~ 0
AVR_RESET
$Comp
L +3.3V #PWR057
U 1 1 5839EC4D
P 3950 2800
F 0 "#PWR057" H 3950 2650 50  0001 C CNN
F 1 "+3.3V" H 3950 2940 50  0000 C CNN
F 2 "" H 3950 2800 50  0000 C CNN
F 3 "" H 3950 2800 50  0000 C CNN
	1    3950 2800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR058
U 1 1 5839EC77
P 10100 1750
F 0 "#PWR058" H 10100 1600 50  0001 C CNN
F 1 "+3.3V" H 10100 1890 50  0000 C CNN
F 2 "" H 10100 1750 50  0000 C CNN
F 3 "" H 10100 1750 50  0000 C CNN
	1    10100 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR059
U 1 1 5839ED72
P 9600 2250
F 0 "#PWR059" H 9600 2000 50  0001 C CNN
F 1 "GND" H 9600 2100 50  0000 C CNN
F 2 "" H 9600 2250 50  0000 C CNN
F 3 "" H 9600 2250 50  0000 C CNN
	1    9600 2250
	1    0    0    -1  
$EndComp
Text GLabel 6200 4050 2    60   Input ~ 0
AVR_RESET
Text GLabel 6200 3450 2    60   Input ~ 0
AVR_MOSI
Text GLabel 6200 3350 2    60   Input ~ 0
AVR_MISO
Text GLabel 6200 3250 2    60   Input ~ 0
AVR_SCK
$Comp
L C C37
U 1 1 5839EFD2
P 6150 4250
F 0 "C37" H 6175 4350 50  0000 L CNN
F 1 "100nF" H 6175 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6188 4100 50  0001 C CNN
F 3 "" H 6150 4250 50  0000 C CNN
	1    6150 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR060
U 1 1 5839F110
P 6150 4450
F 0 "#PWR060" H 6150 4200 50  0001 C CNN
F 1 "GND" H 6150 4300 50  0000 C CNN
F 2 "" H 6150 4450 50  0000 C CNN
F 3 "" H 6150 4450 50  0000 C CNN
	1    6150 4450
	1    0    0    -1  
$EndComp
Text GLabel 6200 3950 2    60   Input ~ 0
AVR_RXD
Text GLabel 6200 3550 2    60   Input ~ 0
AVR_TXD
$Comp
L USB_B-RESCUE-prototype1 P1
U 1 1 5839FABB
P 8250 2950
AR Path="/5839FABB" Ref="P1"  Part="1" 
AR Path="/5839DEEE/5839FABB" Ref="P1"  Part="1" 
F 0 "P1" H 8450 2750 50  0000 C CNN
F 1 "USB_B" H 8200 3150 50  0000 C CNN
F 2 "Connect:USB_B" V 8200 2850 50  0001 C CNN
F 3 "" V 8200 2850 50  0000 C CNN
	1    8250 2950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR061
U 1 1 5839FCAF
P 7850 3150
F 0 "#PWR061" H 7850 2900 50  0001 C CNN
F 1 "GND" H 7850 3000 50  0000 C CNN
F 2 "" H 7850 3150 50  0000 C CNN
F 3 "" H 7850 3150 50  0000 C CNN
	1    7850 3150
	1    0    0    -1  
$EndComp
NoConn ~ 7950 2750
NoConn ~ 8350 3250
$Comp
L CONN_01X02 P4
U 1 1 583A099B
P 10200 3800
F 0 "P4" H 10200 3950 50  0000 C CNN
F 1 "CONN_01X02" V 10300 3800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 10200 3800 50  0001 C CNN
F 3 "" H 10200 3800 50  0000 C CNN
	1    10200 3800
	0    1    1    0   
$EndComp
$Comp
L CONN_01X02 P3
U 1 1 583A0A31
P 10200 3150
F 0 "P3" H 10200 3300 50  0000 C CNN
F 1 "CONN_01X02" V 10300 3150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 10200 3150 50  0001 C CNN
F 3 "" H 10200 3150 50  0000 C CNN
	1    10200 3150
	0    -1   -1   0   
$EndComp
Text GLabel 10300 3550 2    60   Input ~ 0
VGA_SDA
Text GLabel 10300 3400 2    60   Input ~ 0
VGA_SCL
Text GLabel 10100 3400 0    60   Input ~ 0
AVR_SCK
Text GLabel 10100 3550 0    60   Input ~ 0
AVR_MOSI
$Comp
L TEST_1P W3
U 1 1 583A0E28
P 6600 3050
F 0 "W3" H 6600 3320 50  0000 C CNN
F 1 "TEST_1P" H 6600 3250 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 6800 3050 50  0001 C CNN
F 3 "" H 6800 3050 50  0000 C CNN
	1    6600 3050
	0    1    1    0   
$EndComp
$Comp
L TEST_1P W4
U 1 1 583A0EAB
P 6900 3150
F 0 "W4" H 6900 3420 50  0000 C CNN
F 1 "TEST_1P" H 6900 3350 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 7100 3150 50  0001 C CNN
F 3 "" H 7100 3150 50  0000 C CNN
	1    6900 3150
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 583A13EC
P 6350 2750
F 0 "R13" V 6430 2750 50  0000 C CNN
F 1 "68R" V 6350 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6280 2750 50  0001 C CNN
F 3 "" H 6350 2750 50  0000 C CNN
	1    6350 2750
	0    -1   -1   0   
$EndComp
$Comp
L R R14
U 1 1 583A1449
P 6400 2950
F 0 "R14" V 6480 2950 50  0000 C CNN
F 1 "68R" V 6400 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6330 2950 50  0001 C CNN
F 3 "" H 6400 2950 50  0000 C CNN
	1    6400 2950
	0    -1   -1   0   
$EndComp
$Comp
L R R15
U 1 1 583A1687
P 7800 2650
F 0 "R15" V 7880 2650 50  0000 C CNN
F 1 "1k5" V 7800 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7730 2650 50  0001 C CNN
F 3 "" H 7800 2650 50  0000 C CNN
	1    7800 2650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR062
U 1 1 583A183A
P 7800 2450
F 0 "#PWR062" H 7800 2300 50  0001 C CNN
F 1 "+3.3V" H 7800 2590 50  0000 C CNN
F 2 "" H 7800 2450 50  0000 C CNN
F 3 "" H 7800 2450 50  0000 C CNN
	1    7800 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2850 3950 2850
Wire Wire Line
	3950 2800 3950 2900
Connection ~ 3950 2850
Wire Wire Line
	4000 4050 3950 4050
Wire Wire Line
	3950 4050 3950 4100
Wire Wire Line
	3950 3250 3950 3200
Wire Wire Line
	7250 4050 7600 4050
Wire Wire Line
	7500 4050 7500 3950
Wire Wire Line
	7250 3550 7600 3550
Wire Wire Line
	7500 3550 7500 3650
Wire Wire Line
	7250 3750 7250 3550
Wire Wire Line
	6100 3750 7250 3750
Connection ~ 7500 3550
Wire Wire Line
	6100 3850 7250 3850
Wire Wire Line
	7250 3850 7250 4050
Connection ~ 7500 4050
Wire Wire Line
	7900 4050 8000 4050
Wire Wire Line
	7900 3550 8000 3550
Wire Wire Line
	9550 2100 9650 2100
Wire Wire Line
	9550 2000 9650 2000
Wire Wire Line
	9550 1900 9650 1900
Wire Wire Line
	9550 1700 9650 1700
Wire Wire Line
	9650 1800 10100 1800
Wire Wire Line
	10100 1800 10100 1750
Wire Wire Line
	9650 2200 9600 2200
Wire Wire Line
	9600 2200 9600 2250
Wire Wire Line
	6100 4050 6200 4050
Wire Wire Line
	6200 3450 6100 3450
Wire Wire Line
	6200 3350 6100 3350
Wire Wire Line
	6200 3250 6100 3250
Wire Wire Line
	6150 4100 6150 4050
Connection ~ 6150 4050
Wire Wire Line
	6150 4450 6150 4400
Wire Wire Line
	6100 3950 6200 3950
Wire Wire Line
	6100 3550 6200 3550
Wire Wire Line
	6700 2850 7950 2850
Wire Wire Line
	6550 2950 7950 2950
Wire Wire Line
	7850 3050 7950 3050
Wire Wire Line
	10250 3600 10250 3550
Wire Wire Line
	10250 3550 10300 3550
Wire Wire Line
	10300 3400 10250 3400
Wire Wire Line
	10250 3400 10250 3350
Wire Wire Line
	10100 3400 10150 3400
Wire Wire Line
	10150 3400 10150 3350
Wire Wire Line
	10150 3600 10150 3550
Wire Wire Line
	10150 3550 10100 3550
Wire Wire Line
	6600 3050 6100 3050
Wire Wire Line
	6100 3150 6900 3150
Wire Wire Line
	6150 2750 6200 2750
Wire Wire Line
	7800 2850 7800 2800
Connection ~ 7800 2850
Wire Wire Line
	7850 3150 7850 3050
Wire Wire Line
	7800 2500 7800 2450
Wire Wire Line
	6700 2850 6700 2750
Wire Wire Line
	6700 2750 6500 2750
Wire Wire Line
	6250 2950 6200 2950
Wire Wire Line
	6200 2950 6200 2850
Wire Wire Line
	6200 2850 6100 2850
Wire Wire Line
	6150 2750 6150 2950
Wire Wire Line
	6150 2950 6100 2950
$EndSCHEMATC
