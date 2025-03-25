/*
 * flash.h
 *
 *  Created on: Mar 3, 2025
 *      Author: brand
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"

typedef struct
{
 	GPIO_TypeDef* pin_letter;
	uint16_t pin_num;
}IC_Pin;

void reset_ic(SPI_HandleTypeDef *hspi1, int flash_chip_num);
void flash_read_jedec_id(SPI_HandleTypeDef *hspi1, int flash_chip_num);

const IC_Pin FLASH_P_HOLD = (Flash_IC_Pin){.pin_letter = GPIOC, .pin_num = GPIO_PIN_6};
const IC_Pin FLASH_P_CHIP_SELECT = (Flash_IC_Pin){.pin_letter = GPIOA, .pin_num = GPIO_PIN_0};
const IC_Pin FLASH_P_WRITE_PROTECT = (Flash_IC_Pin){.pin_letter = GPIC, .pin_num = GPIO_PIN_2};

const uint8_t FLASH_RESET = 0xFF;
const uint8_t FLASH_WRITE_ENABLE = 0x06;
const uint8_t FLASH_WRITE_DISABLE = 0x04;
const uint8_t FLASH_PAGE_READ = 0x13;
const uint8_t FLASH_READ_FROM_CACHE = 0x03;
const uint8_t FLASH_PROGRAM_EXECUTE = 0x10;
const uint8_t FLASH_PROGRAM_LOAD = 0x02;
const uint8_t FLASH_PROGRAM_LOAD_RANDOM = 0x84;
const uint8_t FLASH_BLOCK_ERASE = 0xD8;
const uint8_t FLASH_READ_STATUS_REGISTER = 0x0F;
const uint8_t FLASH_WRITE_STATUS_REGISTER = 0x1F;
const uint8_t FLASH_READ_JEDEC_ID = 0x9F;


#endif /* INC_FLASH_H_ */
