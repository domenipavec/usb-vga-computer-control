/*
 ## Cypress FX3 Camera Kit Source file (cyfxuvcdscr.c)
 ## ===========================
 ##
 ##  Copyright Cypress Semiconductor Corporation, 2010-2012,
 ##  All Rights Reserved
 ##  UNPUBLISHED, LICENSED SOFTWARE.
 ##
 ##  CONFIDENTIAL AND PROPRIETARY INFORMATION
 ##  WHICH IS THE PROPERTY OF CYPRESS.
 ##
 ##  Use of this file is governed
 ##  by the license agreement included in the file
 ##
 ##     <install>/license/license.txt
 ##
 ##  where <install> is the Cypress software
 ##  installation root directory path.
 ##
 ## ===========================
*/

/*
 * This file contains the USB descriptors for the FX3 HD 720p camera kit
 * application.
 */

#include "uvc.h"

/* Standard High Speed Configuration Descriptor */
const uint8_t CyFxUSBHSConfigDscr[] =
    {

        /* Configuration Descriptor Type */
        0x09,                           /* Descriptor Size */
        CY_U3P_USB_CONFIG_DESCR,        /* Configuration Descriptor Type */
        0xCD,0x00,                      /* Length of this descriptor and all sub descriptors */
        0x02,                           /* Number of interfaces */
        0x01,                           /* Configuration number */
        0x00,                           /* COnfiguration string index */
        0x80,                           /* Config characteristics - Bus powered */
        0xFA,                           /* Max power consumption of device (in 2mA unit) : 500mA */

        /* Interface Association Descriptor */
        0x08,                           /* Descriptor Size */
        CY_FX_INTF_ASSN_DSCR_TYPE,      /* Interface Association Descr Type: 11 */
        0x00,                           /* I/f number of first VideoControl i/f */
        0x02,                           /* Number of Video i/f */
        0x0E,                           /* CC_VIDEO : Video i/f class code */
        0x03,                           /* SC_VIDEO_INTERFACE_COLLECTION : Subclass code */
        0x00,                           /* Protocol : Not used */
        0x00,                           /* String desc index for interface */

        /* Standard Video Control Interface Descriptor */
        0x09,                           /* Descriptor size */
        CY_U3P_USB_INTRFC_DESCR,        /* Interface Descriptor type */
        0x00,                           /* Interface number */
        0x00,                           /* Alternate setting number */
        0x01,                           /* Number of end points */
        0x0E,                           /* CC_VIDEO : Interface class */
        0x01,                           /* CC_VIDEOCONTROL : Interface sub class */
        0x00,                           /* Interface protocol code */
        0x00,                           /* Interface descriptor string index */

        /* Class specific VC Interface Header Descriptor */
        0x0D,                           /* Descriptor size */
        0x24,                           /* Class Specific I/f Header Descriptor type */
        0x01,                           /* Descriptor Sub type : VC_HEADER */
        0x00,0x01,                      /* Revision of class spec : 1.0 */
        0x50,0x00,                      /* Total Size of class specific descriptors (till Output terminal) */
        0x00,0x6C,0xDC,0x02,            /* Clock frequency : 48MHz(Deprecated) */
        0x01,                           /* Number of streaming interfaces */
        0x01,                           /* Video streaming I/f 1 belongs to VC i/f */

        /* Input (Camera) Terminal Descriptor */
        0x12,                           /* Descriptor size */
        0x24,                           /* Class specific interface desc type */
        0x02,                           /* Input Terminal Descriptor type */
        0x01,                           /* ID of this terminal */
        0x01,0x02,                      /* Camera terminal type */
        0x00,                           /* No association terminal */
        0x00,                           /* String desc index : Not used */
        0x00,0x00,                      /* No optical zoom supported */
        0x00,0x00,                      /* No optical zoom supported */
        0x00,0x00,                      /* No optical zoom supported */
        0x03,                           /* Size of controls field for this terminal : 3 bytes */
                                        /* A bit set to 1 indicates that the mentioned Control is
                                         * supported for the video stream in the bmControls field
                                         * D0: Scanning Mode
                                         * D1: Auto-Exposure Mode
                                         * D2: Auto-Exposure Priority
                                         * D3: Exposure Time (Absolute)
                                         * D4: Exposure Time (Relative)
                                         * D5: Focus (Absolute)
                                         * D6: Focus (Relative)
                                         * D7: Iris (Absolute)
                                         * D8: Iris (Relative)
                                         * D9: Zoom (Absolute)
                                         * D10: Zoom (Relative)
                                         * D11: PanTilt (Absolute)
                                         * D12: PanTilt (Relative)
                                         * D13: Roll (Absolute)
                                         * D14: Roll (Relative)
                                         * D15: Reserved
                                         * D16: Reserved
                                         * D17: Focus, Auto
                                         * D18: Privacy
                                         * D19: Focus, Simple
                                         * D20: Window
                                         * D21: Region of Interest
                                         * D22 � D23: Reserved, set to zero
                                         */
        0x00,0x00,0x00,                 /* bmControls field of camera terminal: No controls supported */

        /* Processing Unit Descriptor */
        0x0C,                           /* Descriptor size */
        0x24,                           /* Class specific interface desc type */
        0x05,                           /* Processing Unit Descriptor type */
        0x02,                           /* ID of this terminal */
        0x01,                           /* Source ID : 1 : Conencted to input terminal */
        0x00,0x40,                      /* Digital multiplier */
        0x03,                           /* Size of controls field for this terminal : 3 bytes */
                                        /* A bit set to 1 in the bmControls field indicates that
                                         * the mentioned Control is supported for the video stream.
                                         * D0: Brightness
                                         * D1: Contrast
                                         * D2: Hue
                                         * D3: Saturation
                                         * D4: Sharpness
                                         * D5: Gamma
                                         * D6: White Balance Temperature
                                         * D7: White Balance Component
                                         * D8: Backlight Compensation
                                         * D9: Gain
                                         * D10: Power Line Frequency
                                         * D11: Hue, Auto
                                         * D12: White Balance Temperature, Auto
                                         * D13: White Balance Component, Auto
                                         * D14: Digital Multiplier
                                         * D15: Digital Multiplier Limit
                                         * D16: Analog Video Standard
                                         * D17: Analog Video Lock Status
                                         * D18: Contrast, Auto
                                         * D19 � D23: Reserved. Set to zero.
                                         */
        0x00,0x00,0x00,                 /* bmControls field of processing unit: No control supported */
        0x00,                           /* String desc index : Not used */

        /* Extension Unit Descriptor */
        0x1C,                           /* Descriptor size */
        0x24,                           /* Class specific interface desc type */
        0x06,                           /* Extension Unit Descriptor type */
        0x03,                           /* ID of this terminal */
        0xFF,0xFF,0xFF,0xFF,            /* 16 byte GUID */
        0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,
        0x00,                           /* Number of controls in this terminal */
        0x01,                           /* Number of input pins in this terminal */
        0x02,                           /* Source ID : 2 : Connected to Proc Unit */
        0x03,                           /* Size of controls field for this terminal : 3 bytes */
        0x00,0x00,0x00,                 /* No controls supported */
        0x00,                           /* String desc index : Not used */

        /* Output Terminal Descriptor */
        0x09,                           /* Descriptor size */
        0x24,                           /* Class specific interface desc type */
        0x03,                           /* Output Terminal Descriptor type */
        0x04,                           /* ID of this terminal */
        0x01,0x01,                      /* USB Streaming terminal type */
        0x00,                           /* No association terminal */
        0x03,                           /* Source ID : 3 : Connected to Extn Unit */
        0x00,                           /* String desc index : Not used */

        /* Video Control Status Interrupt Endpoint Descriptor */
        0x07,                           /* Descriptor size */
        CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint Descriptor Type */
        CY_FX_EP_CONTROL_STATUS,        /* Endpoint address and description */
        CY_U3P_USB_EP_INTR,             /* Interrupt End point Type */
        0x40,0x00,                      /* Max packet size = 64 bytes */
        0x08,                           /* Servicing interval : 8ms */

        /* Class Specific Interrupt Endpoint Descriptor */
        0x05,                           /* Descriptor size */
        0x25,                           /* Class Specific Endpoint Descriptor Type */
        CY_U3P_USB_EP_INTR,             /* End point Sub Type */
        0x40,0x00,                      /* Max packet size = 64 bytes */

        /* Standard Video Streaming Interface Descriptor (Alternate Setting 0) */
        0x09,                           /* Descriptor size */
        CY_U3P_USB_INTRFC_DESCR,        /* Interface Descriptor type */
        0x01,                           /* Interface number */
        0x00,                           /* Alternate setting number */
        0x01,                           /* Number of end points : Zero Bandwidth */
        0x0E,                           /* Interface class : CC_VIDEO */
        0x02,                           /* Interface sub class : CC_VIDEOSTREAMING */
        0x00,                           /* Interface protocol code : Undefined */
        0x00,                           /* Interface descriptor string index */

       /* Class-specific Video Streaming Input Header Descriptor */
        0x0E,                           /* Descriptor size */
        0x24,                           /* Class-specific VS I/f Type */
        0x01,                           /* Descriptotor Subtype : Input Header */
        0x01,                           /* 1 format desciptor follows */
        0x29,0x00,                      /* Total size of Class specific VS descr: 41 Bytes */
        CY_FX_EP_BULK_VIDEO,            /* EP address for BULK video data */
        0x00,                           /* No dynamic format change supported */
        0x04,                           /* Output terminal ID : 4 */
        0x01,                           /* Still image capture method 1 supported */
        0x00,                           /* Hardware trigger NOT supported */
        0x00,                           /* Hardware to initiate still image capture NOT supported */
        0x01,                           /* Size of controls field : 1 byte */
        0x00,                           /* D2 : Compression quality supported */


       /* Class specific Uncompressed VS format descriptor */
        0x1B,                           /* Descriptor size */
        0x24,                           /* Class-specific VS I/f Type */
        0x04,                           /* Subtype : uncompressed format I/F */
        0x01,                           /* Format desciptor index (only one format is supported) */
        0x01,                           /* number of frame descriptor followed */
        0x59,0x55,0x59,0x32,            /* GUID used to identify streaming-encoding format: YUY2  */
        0x00,0x00,0x10,0x00,
        0x80,0x00,0x00,0xAA,
        0x00,0x38,0x9B,0x71,
        0x10,                           /* Number of bits per pixel used to specify color in the decoded video frame.
                                           0 if not applicable: 10 bit per pixel */
        0x01,                           /* Optimum Frame Index for this stream: 1 */
        0x08,                           /* X dimension of the picture aspect ratio: Non-interlaced in
			        	   progressive scan */
        0x06,                           /* Y dimension of the picture aspect ratio: Non-interlaced in
					   progressive scan*/
        0x00,                           /* Interlace Flags: Progressive scanning, no interlace */
        0x00,                           /* duplication of the video stream restriction: 0 - no restriction */



       /* Class specific Uncompressed VS Frame descriptor */
        0x1E,                           /* Descriptor size */
        0x24,                           /* Descriptor type*/
        0x05,                           /* Subtype: uncompressed frame I/F */
        0x01,                           /* Frame Descriptor Index */
        0x03,                           /* Still image capture method 1 supported, fixed frame rate */
        0x80,0x02,                      /* Width in pixel: 320-QVGA */
        0xE0,0x01,                      /* Height in pixel 240-QVGA */
        0x00,0x50,0x97,0x31,            /* Min bit rate bits/s. Not specified, taken from MJPEG */
        0x00,0x50,0x97,0x31,            /* Max bit rate bits/s. Not specified, taken from MJPEG */
        0x00,0x60,0x09,0x00,            /* Maximum video or still frame size in bytes(Deprecated) */
        0x2A,0x2C,0x0A,0x00,            /* Default Frame Interval */
        0x01,                           /* Frame interval(Frame Rate) types: Only one frame interval supported */
        0x2A,0x2C,0x0A,0x00,            /* Shortest Frame Interval */

        /* Endpoint Descriptor for BULK Streaming Video Data */
        0x07,                           /* Descriptor size */
        CY_U3P_USB_ENDPNT_DESCR,        /* Endpoint Descriptor Type */
        CY_FX_EP_BULK_VIDEO,            /* Endpoint address and description */
        0x02,                           /* BULK End point */
        (uint8_t)(512 & 0x00FF),        /* High speed max packet size is always 512 bytes. */
        (uint8_t)((512 & 0xFF00)>>8),
        0x01                            /* Servicing interval for data transfers */
    };
