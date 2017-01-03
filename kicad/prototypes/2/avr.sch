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
LIBS:cyusb301x-121bga
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:allegro
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:ir
LIBS:Lattice
LIBS:logo
LIBS:maxim
LIBS:mechanical
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:motor_drivers
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:Oscillators
LIBS:powerint
LIBS:Power_Management
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:zetex
LIBS:Zilog
LIBS:usb3_typeb
LIBS:ncp360snt1g
LIBS:usb3_esd
LIBS:prototype1-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
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
F 2 "Capacitors_SMD:C_0402" H 3988 2900 50  0001 C CNN
F 3 "" H 3950 3050 50  0000 C CNN
	1    3950 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR048
U 1 1 5839DF98
P 3950 4100
F 0 "#PWR048" H 3950 3850 50  0001 C CNN
F 1 "GND" H 3950 3950 50  0000 C CNN
F 2 "" H 3950 4100 50  0000 C CNN
F 3 "" H 3950 4100 50  0000 C CNN
	1    3950 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR049
U 1 1 5839DFB7
P 3950 3250
F 0 "#PWR049" H 3950 3000 50  0001 C CNN
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
F 1 "Crystal-12Mhz" H 7500 3650 50  0000 C CNN
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
F 2 "Capacitors_SMD:C_0805" H 7788 3400 50  0001 C CNN
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
F 2 "Capacitors_SMD:C_0805" H 7788 3900 50  0001 C CNN
F 3 "" H 7750 4050 50  0000 C CNN
	1    7750 4050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR050
U 1 1 5839E255
P 8000 3550
F 0 "#PWR050" H 8000 3300 50  0001 C CNN
F 1 "GND" H 8000 3400 50  0000 C CNN
F 2 "" H 8000 3550 50  0000 C CNN
F 3 "" H 8000 3550 50  0000 C CNN
	1    8000 3550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR051
U 1 1 5839E276
P 8000 4050
F 0 "#PWR051" H 8000 3800 50  0001 C CNN
F 1 "GND" H 8000 3900 50  0000 C CNN
F 2 "" H 8000 4050 50  0000 C CNN
F 3 "" H 8000 4050 50  0000 C CNN
	1    8000 4050
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X06 P2
U 1 1 5839E4CE
P 10100 1150
F 0 "P2" H 10100 1500 50  0000 C CNN
F 1 "CONN_01X06" V 10200 1150 50  0000 C CNN
F 2 "attiny841-spi:ATTINY841-SPI" H 10100 1150 50  0001 C CNN
F 3 "" H 10100 1150 50  0000 C CNN
	1    10100 1150
	1    0    0    -1  
$EndComp
Text GLabel 9800 900  0    60   Input ~ 0
AVR_MISO
Text GLabel 9800 1100 0    60   Input ~ 0
AVR_SCK
Text GLabel 9800 1200 0    60   Input ~ 0
AVR_MOSI
Text GLabel 9800 1300 0    60   Input ~ 0
AVR_RESET
$Comp
L +3.3V #PWR052
U 1 1 5839EC4D
P 3950 2800
F 0 "#PWR052" H 3950 2650 50  0001 C CNN
F 1 "+3.3V" H 3950 2940 50  0000 C CNN
F 2 "" H 3950 2800 50  0000 C CNN
F 3 "" H 3950 2800 50  0000 C CNN
	1    3950 2800
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR053
U 1 1 5839EC77
P 10350 950
F 0 "#PWR053" H 10350 800 50  0001 C CNN
F 1 "+3.3V" H 10350 1090 50  0000 C CNN
F 2 "" H 10350 950 50  0000 C CNN
F 3 "" H 10350 950 50  0000 C CNN
	1    10350 950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR054
U 1 1 5839ED72
P 9850 1450
F 0 "#PWR054" H 9850 1200 50  0001 C CNN
F 1 "GND" H 9850 1300 50  0000 C CNN
F 2 "" H 9850 1450 50  0000 C CNN
F 3 "" H 9850 1450 50  0000 C CNN
	1    9850 1450
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
F 2 "Capacitors_SMD:C_0402" H 6188 4100 50  0001 C CNN
F 3 "" H 6150 4250 50  0000 C CNN
	1    6150 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR055
U 1 1 5839F110
P 6150 4450
F 0 "#PWR055" H 6150 4200 50  0001 C CNN
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
P 10150 2950
AR Path="/5839FABB" Ref="P1"  Part="1" 
AR Path="/5839DEEE/5839FABB" Ref="P1"  Part="1" 
F 0 "P1" H 10350 2750 50  0000 C CNN
F 1 "USB_B" H 10100 3150 50  0000 C CNN
F 2 "Connectors:USB_B" V 10100 2850 50  0001 C CNN
F 3 "" V 10100 2850 50  0000 C CNN
	1    10150 2950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR056
U 1 1 5839FCAF
P 9750 3150
F 0 "#PWR056" H 9750 2900 50  0001 C CNN
F 1 "GND" H 9750 3000 50  0000 C CNN
F 2 "" H 9750 3150 50  0000 C CNN
F 3 "" H 9750 3150 50  0000 C CNN
	1    9750 3150
	1    0    0    -1  
$EndComp
Text GLabel 10000 5450 2    60   Input ~ 0
VGA_SDA
Text GLabel 10000 5300 2    60   Input ~ 0
VGA_SCL
Text GLabel 9800 5300 0    60   Input ~ 0
AVR_SCK
Text GLabel 9800 5450 0    60   Input ~ 0
AVR_MOSI
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
F 2 "Resistors_SMD:R_0805" V 6280 2750 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" V 6330 2950 50  0001 C CNN
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
F 2 "Resistors_SMD:R_0805" V 7730 2650 50  0001 C CNN
F 3 "" H 7800 2650 50  0000 C CNN
	1    7800 2650
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
	9800 1300 9900 1300
Wire Wire Line
	9800 1200 9900 1200
Wire Wire Line
	9800 1100 9900 1100
Wire Wire Line
	9800 900  9900 900 
Wire Wire Line
	9900 1000 10350 1000
Wire Wire Line
	10350 1000 10350 950 
Wire Wire Line
	9900 1400 9850 1400
Wire Wire Line
	9850 1400 9850 1450
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
	6700 2850 8100 2850
Wire Wire Line
	9100 2850 9850 2850
Wire Wire Line
	9750 3050 9850 3050
Wire Wire Line
	9800 5450 10000 5450
Wire Wire Line
	9800 5300 10000 5300
Wire Wire Line
	6100 3050 6950 3050
Wire Wire Line
	6100 3150 6900 3150
Wire Wire Line
	6150 2750 6200 2750
Wire Wire Line
	9750 3150 9750 3050
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
$Comp
L R R2
U 1 1 58652607
P 9900 5100
F 0 "R2" V 9980 5100 50  0000 C CNN
F 1 "47k" V 9900 5100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 9830 5100 50  0001 C CNN
F 3 "" H 9900 5100 50  0000 C CNN
	1    9900 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 5300 9900 5250
Connection ~ 9900 5300
$Comp
L +3.3V #PWR057
U 1 1 586526EB
P 9900 4900
F 0 "#PWR057" H 9900 4750 50  0001 C CNN
F 1 "+3.3V" H 9900 5040 50  0000 C CNN
F 2 "" H 9900 4900 50  0000 C CNN
F 3 "" H 9900 4900 50  0000 C CNN
	1    9900 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 4950 9900 4900
$Comp
L R R3
U 1 1 5865282A
P 9900 5700
F 0 "R3" V 9980 5700 50  0000 C CNN
F 1 "47k" V 9900 5700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 9830 5700 50  0001 C CNN
F 3 "" H 9900 5700 50  0000 C CNN
	1    9900 5700
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR058
U 1 1 5865288C
P 9900 5900
F 0 "#PWR058" H 9900 5750 50  0001 C CNN
F 1 "+3.3V" H 9900 6040 50  0000 C CNN
F 2 "" H 9900 5900 50  0000 C CNN
F 3 "" H 9900 5900 50  0000 C CNN
	1    9900 5900
	-1   0    0    1   
$EndComp
Wire Wire Line
	9900 5550 9900 5450
Connection ~ 9900 5450
Wire Wire Line
	9900 5900 9900 5850
Connection ~ 7800 2850
Wire Wire Line
	7800 2850 7800 2800
Wire Wire Line
	6950 3050 6950 2400
Wire Wire Line
	6950 2400 7800 2400
Wire Wire Line
	7800 2400 7800 2500
$Comp
L USBLC6-2SC6 U2
U 1 1 5868193C
P 8600 3050
F 0 "U2" H 8350 3400 50  0000 C CNN
F 1 "USBLC6-2SC6" H 8600 2700 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 9250 3400 50  0001 C CNN
F 3 "" H 8350 3400 50  0001 C CNN
	1    8600 3050
	1    0    0    1   
$EndComp
Wire Wire Line
	9100 3050 9150 3050
Wire Wire Line
	8050 3050 8100 3050
Wire Wire Line
	9450 3250 9100 3250
Wire Wire Line
	9450 3250 9450 2950
Wire Wire Line
	9450 2950 9850 2950
Wire Wire Line
	7650 3250 7650 2950
$Comp
L GND #PWR059
U 1 1 5869AB92
P 8050 3050
F 0 "#PWR059" H 8050 2800 50  0001 C CNN
F 1 "GND" H 8050 2900 50  0000 C CNN
F 2 "" H 8050 3050 50  0000 C CNN
F 3 "" H 8050 3050 50  0000 C CNN
	1    8050 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 3250 8100 3250
Wire Wire Line
	7650 2950 6550 2950
$Comp
L +5VD #PWR060
U 1 1 586A3C23
P 9150 3050
F 0 "#PWR060" H 9150 2900 50  0001 C CNN
F 1 "+5VD" H 9150 3190 50  0000 C CNN
F 2 "" H 9150 3050 50  0000 C CNN
F 3 "" H 9150 3050 50  0000 C CNN
	1    9150 3050
	0    1    1    0   
$EndComp
$Comp
L +5VD #PWR061
U 1 1 586A3C9E
P 9800 2700
F 0 "#PWR061" H 9800 2550 50  0001 C CNN
F 1 "+5VD" H 9800 2840 50  0000 C CNN
F 2 "" H 9800 2700 50  0000 C CNN
F 3 "" H 9800 2700 50  0000 C CNN
	1    9800 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 2750 9800 2750
Wire Wire Line
	9800 2750 9800 2700
$Comp
L C C68
U 1 1 586A4138
P 10250 3450
F 0 "C68" H 10275 3550 50  0000 L CNN
F 1 "100nF" H 10275 3350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 10288 3300 50  0001 C CNN
F 3 "" H 10250 3450 50  0000 C CNN
	1    10250 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3300 10250 3250
$Comp
L GND #PWR062
U 1 1 586A42A7
P 10250 3650
F 0 "#PWR062" H 10250 3400 50  0001 C CNN
F 1 "GND" H 10250 3500 50  0000 C CNN
F 2 "" H 10250 3650 50  0000 C CNN
F 3 "" H 10250 3650 50  0000 C CNN
	1    10250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3650 10250 3600
$EndSCHEMATC
