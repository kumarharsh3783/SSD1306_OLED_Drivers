/*
 * SSD1306.h
 *
 *  Created on: 06-Jul-2024
 *      Author: kumar
 */

#ifndef SSD1306_H_
#define SSD1306_H_

/******************************
 * Defines
 *****************************/

/* OLED Slave device Address - 0011 1100b */
#define SSD1306_Addr	0x3C

#define SSD1306_Read	1u
#define SSD1306_Write	0u

/* R/W#=1, it is in read mode. R/W#=0, it is in write mode */
#define oled_read(addr)		((addr << 1) | SSD1306_Read)
#define oled_write(addr)    ((addr << 1) | SSD1306_Write)


#endif /* SSD1306_H_ */
