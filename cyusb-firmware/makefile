## Copyright Cypress Semiconductor Corporation, 2016-2017,
## All Rights Reserved
## UNPUBLISHED, LICENSED SOFTWARE.
##
## CONFIDENTIAL AND PROPRIETARY INFORMATION
## WHICH IS THE PROPERTY OF CYPRESS.
##
## Use of this file is governed
## by the license agreement included in the file
##
##      <install>/license/license.txt
##
## where <install> is the Cypress software
## installation root directory path.
##

FX3FWROOT=${HOME}/Cypress/cyfx3sdk

all:compile

include $(FX3FWROOT)/fw_build/fx3_fw/fx3_build_config.mak

MODULE = usb-vga-computer-control

SOURCE = main.c \
	uvc.c 			\
	cyfxuvcdscr.c		\
	i2c.c		\
	tvp7002.c \
	cyfxtx.c \
	usb_descriptors.c

ifeq ($(CYFXBUILD),arm)
SOURCE_ASM=cyfx_startup.S
else
SOURCE_ASM=cyfx_gcc_startup.S
endif

C_OBJECT=$(SOURCE:%.c=./%.o)
A_OBJECT=$(SOURCE_ASM:%.S=./%.o)

EXES = $(MODULE).$(EXEEXT)

$(MODULE).$(EXEEXT): $(A_OBJECT) $(C_OBJECT)
	$(LINK)

cyfxtx.c:
	cp $(FX3FWROOT)/fw_build/fx3_fw/cyfxtx.c .

cyfx_startup.S:
	cp $(FX3FWROOT)/fw_build/fx3_fw/cyfx_startup.S .

cyfx_gcc_startup.S:
	cp $(FX3FWROOT)/fw_build/fx3_fw/cyfx_gcc_startup.S .

usb_descriptors.c: usb_descriptors.c.j2
	usbgen -o usb_descriptors.c usb_descriptors.c.j2

$(C_OBJECT) : %.o : %.c
	$(COMPILE)

$(A_OBJECT) : %.o : %.S
	$(ASSEMBLE)

clean:
	rm -f ./$(MODULE).$(EXEEXT)
	rm -f ./$(MODULE).map
	rm -f ./*.o
	rm -f cyfxtx.c cyfx_startup.S cyfx_gcc_startup.S
	rm usb_descriptors.c

$(MODULE).img: $(EXES)
	$(FX3FWROOT)/util/elf2img/elf2img -i $(EXES) -o $(MODULE).img -v

compile: $(C_OBJECT) $(A_OBJECT) $(EXES) $(MODULE).img

#[]#
