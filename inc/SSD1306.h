/*
 * SSD1306.h
 *
 *  Created on: Sep 21, 2024
 *      Author: kumar
 */

#ifndef SRC_SSD1306_H_
#define SRC_SSD1306_H_

/* TYPEDEFs */
typedef unsigned char 		uint8;
typedef unsigned short 		uint16;
typedef unsigned int		uint32;

/* MACRO DEFINITIONs */

#define SSD1306_ADDRESS_78  1u

/* I2C Bus Interface Selection Pins ON */
#if (SSD1306_ADDRESS_78)
#define SSD1306_ADDR		(uint8)0x3C
#else
#define SSD1306_ADDR		(uint8)0x3D
#endif
/* R/W#=1, it is in read mode */
/* No read mode available for serial interface in SSD1306 */
#define oled_read(x)		(uint8)((x << 1) | 1)
/* R/W#=0, it is in write mode */
#define oled_write(x)		(uint8)(x << 1)

/* Control Byte format
 * Co D/C 0 0 0 0 0 0
 * ********************/
/* Co bit set as logic 0, the transmission of the following information will contain data bytes only */
#define Continuation_bit	0
#define Co 					Continuation_bit

/* D/C# bit set to logic 1, the following data byte as a data which will be stored at the GDDRAM */
#define DataByte_Data			1
/* D/C# bit is set to logic 0, it defines the following data byte as a command */
#define DataByte_Command			0

#define SSD1306_CTRL_CMD	(uint8)((Co << 8) | (DataByte_Command << 7))
#define SSD1306_CTRL_DATA	(uint8)((Co << 8) | (DataByte_Data << 7))

/* Commands for SSD1306 */

/** Fundamental commands **/
#define SET_CONTRAST_CONTROL	0x81

#define RESUME_RAM_DISPLAY		0xA4
#define ENTIRE_DISPLAY_ON		0xA5

#define NORMAL_DISPLAY			0xA6
#define INVERSE_DISPLAY			0xA7

#define OFF						0u
#define ON						1u
#define DISPLAY(x)				(0xAE | (x & 0x01))

#define DISPLAY_OFF				0xAE
#define DISPLAY_ON_NORMAL		0xAF

/** Scrolling commands **/
/* Continous Horizontal Scroll Setup */
#define RIGHT_HORIZONTAL_SCROLL	0x26
#define LEFT_HORIZONTAL_SCROLL	0x27

/* Continuous Vertical and Horizontal scroll Setup */
#define VERTICAL_RIGHT_HORIZONTAL_SCROLL	0x29
#define VERTICAL_LEFT_HORIZONTAL_SCROLL		0x2A

#define DEACTIVATE_SCROLL		0x2E
#define ACTIVATE_SCROLL			0x2F

#define SET_VERTICAL_SCROLL_AREA	0xA3

/** Addressing Setting Commands **/
#define SET_MEM_ADDRESS_MODE		0x20

/* Horizontal and vertical Addressing Mode Macros */
#define HORIZONTAL_ADDRESS_MODE_SEL	0x00
#define VERTICAL_ADDRESS_MODE_SEL	0x01

#define HV_ADDR_MODE_COL_START_END	0x21

#define HV_ADDR_MODE_PAGE_START_END	0x22

/* Page Addressing Mode Macros */
#define PAGE_ADDRESS_MODE_SEL		0x02

#define	PAGE_ADDR_MODE_LOW_COL_ADDR(x)		(x & 0x0F)
#define PAGE_ADDR_MODE_HIGH_COL_ADDR(x)		(0x10 | (x & 0x0F))
#define PAGE_ADDR_MODE_SET_PAGE_START(y)	(0xB0 | (y & 0x07))

/** Hardware Configuration Commands **/
#define SET_DISPLAY_START_ROWLINE(x)		(0x40 | (x & 0x3F))
#define SET_SEGMENT_REMAP					0xA1
#define SET_MUX_RATIO						0xA8
#define SET_COM_REMAP						0xC8
#define SET_DISPLAY_OFFSET					0xD3
#define SET_COM_PIN_HW_CONFIG				0xDA

/** Timing & Driving Scheme Setting Commands **/
#define SET_DIV_RATIO_OSC_FREQ				0xD5

#define	NOP									0xE3

/** Charge Pump Settings **/
#define CHARGE_PUMP_SETTING					0x8D

#define ENABLE_CHARGE_PUMP					0x14
#define DISABLE_CHARGE_PUMP					0x10


/* FUNCTION DECLARATIONS */
void	OLED_INIT(void);

void	SSD1306_I2C_SEND(uint8 control_byte, uint8 data_byte);
void 	OLED_SET_CURSOR(uint8 x, uint8 y);
void 	OLED_CLEAR();
#endif /* SRC_SSD1306_H_ */
