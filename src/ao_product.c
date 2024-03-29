/*
 * Copyright © 2009 Keith Packard <keithp@keithp.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */

#include "ao.h"
#include "ao_product.h"

/* Defines which mark this particular AltOS product */

const char ao_version[AO_MAX_VERSION] = AO_iVersion_STRING;
const char ao_manufacturer[] = AO_iManufacturer_STRING;
const char ao_product[] = AO_iProduct_STRING;

#define LE_WORD(x)    ((x)&0xFF),((uint8_t) (((uint16_t) (x))>>8))

#if HAS_USB
#include "ao_usb.h"
/* USB descriptors in one giant block of bytes */
__code __at(0x00aa) uint8_t ao_usb_descriptors [] =
{
	/* Device descriptor */
	0x12,
	AO_USB_DESC_DEVICE,
	LE_WORD(0x0110),	/*  bcdUSB */
	0x02,			/*  bDeviceClass */
	0x00,			/*  bDeviceSubClass */
	0x00,			/*  bDeviceProtocol */
	AO_USB_CONTROL_SIZE,	/*  bMaxPacketSize */
	LE_WORD(0xFFFE),	/*  idVendor */
	LE_WORD(AO_idProduct_NUMBER),	/*  idProduct */
	LE_WORD(0x0100),	/*  bcdDevice */
	0x01,			/*  iManufacturer */
	0x02,			/*  iProduct */
	0x03,			/*  iSerialNumber */
	0x01,			/*  bNumConfigurations */

	/* Configuration descriptor */
	0x09,
	AO_USB_DESC_CONFIGURATION,
	LE_WORD(67),		/*  wTotalLength */
	0x02,			/*  bNumInterfaces */
	0x01,			/*  bConfigurationValue */
	0x00,			/*  iConfiguration */
	0xC0,			/*  bmAttributes */
	0x32,			/*  bMaxPower */

	/* Control class interface */
	0x09,
	AO_USB_DESC_INTERFACE,
	0x00,			/*  bInterfaceNumber */
	0x00,			/*  bAlternateSetting */
	0x01,			/*  bNumEndPoints */
	0x02,			/*  bInterfaceClass */
	0x02,			/*  bInterfaceSubClass */
	0x01,			/*  bInterfaceProtocol, linux requires value of 1 for the cdc_acm module */
	0x00,			/*  iInterface */

	/* Header functional descriptor */
	0x05,
	CS_INTERFACE,
	0x00,			/*  bDescriptor SubType Header */
	LE_WORD(0x0110),	/*  CDC version 1.1 */

	/* Call management functional descriptor */
	0x05,
	CS_INTERFACE,
	0x01,			/* bDescriptor SubType Call Management */
	0x01,			/* bmCapabilities = device handles call management */
	0x01,			/* bDataInterface call management interface number */

	/* ACM functional descriptor */
	0x04,
	CS_INTERFACE,
	0x02,			/* bDescriptor SubType Abstract Control Management */
	0x02,			/* bmCapabilities = D1 (Set_line_Coding, Set_Control_Line_State, Get_Line_Coding and Serial_State) */

	/* Union functional descriptor */
	0x05,
	CS_INTERFACE,
	0x06,			/* bDescriptor SubType Union Functional descriptor */
	0x00,			/* bMasterInterface */
	0x01,			/* bSlaveInterface0 */

	/* Notification EP */
	0x07,
	AO_USB_DESC_ENDPOINT,
	AO_USB_INT_EP|0x80,	/* bEndpointAddress */
	0x03,			/* bmAttributes = intr */
	LE_WORD(8),		/* wMaxPacketSize */
	0x0A,			/* bInterval */

	/* Data class interface descriptor */
	0x09,
	AO_USB_DESC_INTERFACE,
	0x01,			/* bInterfaceNumber */
	0x00,			/* bAlternateSetting */
	0x02,			/* bNumEndPoints */
	0x0A,			/* bInterfaceClass = data */
	0x00,			/* bInterfaceSubClass */
	0x00,			/* bInterfaceProtocol */
	0x00,			/* iInterface */

	/* Data EP OUT */
	0x07,
	AO_USB_DESC_ENDPOINT,
	AO_USB_OUT_EP,		/* bEndpointAddress */
	0x02,			/* bmAttributes = bulk */
	LE_WORD(AO_USB_OUT_SIZE),/* wMaxPacketSize */
	0x00,			/* bInterval */

	/* Data EP in */
	0x07,
	AO_USB_DESC_ENDPOINT,
	AO_USB_IN_EP|0x80,	/* bEndpointAddress */
	0x02,			/* bmAttributes = bulk */
	LE_WORD(AO_USB_IN_SIZE),/* wMaxPacketSize */
	0x00,			/* bInterval */

	/* String descriptors */
	0x04,
	AO_USB_DESC_STRING,
	LE_WORD(0x0409),

	/* iManufacturer */
	AO_iManufacturer_LEN,
	AO_USB_DESC_STRING,
	AO_iManufacturer_UCS2,

	/* iProduct */
	AO_iProduct_LEN,
	AO_USB_DESC_STRING,
	AO_iProduct_UCS2,

	/* iSerial */
	AO_iSerial_LEN,
	AO_USB_DESC_STRING,
	AO_iSerial_UCS2,

	/* Terminating zero */
	0
};
#endif
