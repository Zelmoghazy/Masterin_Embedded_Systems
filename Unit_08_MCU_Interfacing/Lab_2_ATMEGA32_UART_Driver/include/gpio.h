#ifndef GPIO_H_
#define GPIO_H_

#include "Platform_Types.h"
#include "Macros.h"

#define GPIO_INPUT                 0
#define GPIO_OUTPUT                1

// atmega328p
#define IO_BASE                    0x20
#define GPIO_B_BASE                (0x03 + IO_BASE)
#define GPIO_C_BASE                (0x06 + IO_BASE)
#define GPIO_D_BASE                (0x09 + IO_BASE)

#define GPIO_PIN_0                 ((uint8_t)0x01) 
#define GPIO_PIN_1                 ((uint8_t)0x02) 
#define GPIO_PIN_2                 ((uint8_t)0x04) 
#define GPIO_PIN_3                 ((uint8_t)0x08) 
#define GPIO_PIN_4                 ((uint8_t)0x10) 
#define GPIO_PIN_5                 ((uint8_t)0x20) 
#define GPIO_PIN_6                 ((uint8_t)0x40) 
#define GPIO_PIN_7                 ((uint8_t)0x80) 

#define GPIO_B                     ((gpio_t *)GPIO_B_BASE)
#define GPIO_C                     ((gpio_t *)GPIO_C_BASE)
#define GPIO_D                     ((gpio_t *)GPIO_D_BASE)

#pragma pack(1)
typedef struct gpio_t
{
    vuint8_t PIN;  // Port Input Pins
    vuint8_t DDR;  // Data Direction Register
    vuint8_t PORT; // Data Register
} gpio_t;

void gpio_set_direction(gpio_t *gpio, uint8_t pin, uint8_t dir);
void gpio_write(gpio_t *gpio, uint8_t pin, uint8_t value); 
uint8_t gpio_read(gpio_t* gpio, uint8_t pin); 
uint8_t gpio_read_port(gpio_t* gpio) ;

#endif
