/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_GPIO_IRQ_API_H
#define MBED_GPIO_IRQ_API_H

#include "device.h"

#if DEVICE_INTERRUPTIN

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    IRQ_NONE,
    IRQ_RISE,
    IRQ_FALL
} gpio_irq_event;

typedef enum {
    IRQ_LOW_VOLTAGE_DETECT = 0,
    IRQ_CACHE = 1,
    IRQ_RESERVED = 2,
    IRQ_POWER_MANAGER = 3,
    IRQ_PICU0 = 4,
    IRQ_PICU1 = 5,
    IRQ_PICU2 = 6,
    IRQ_PICU3 = 7,
    IRQ_PICU4 = 8,
    IRQ_PICU5 = 9,
    IRQ_PICU6 = 10,
    IRQ_PICU12 = 11,
    IRQ_PICU15 = 12,
    IRQ_COMPARATORS = 13,
    IRQ_SWITCH_CAPS = 14,
    IRQ_I2C = 15,
    IRQ_CAN = 16,
    IRQ_TIMER0 = 17,
    IRQ_TIMER1 = 18,
    IRQ_TIMER2 = 19,
    IRQ_TIMER3 = 20
} gpio_irq_vectorlines;

typedef enum {
    PICU0_IRQ_LINE = IRQ_PICU0,
    PICU1_IRQ_LINE = IRQ_PICU1,
    PICU2_IRQ_LINE = IRQ_PICU2,
    PICU3_IRQ_LINE = IRQ_PICU3,
    PICU4_IRQ_LINE = IRQ_PICU4,
    PICU5_IRQ_LINE = IRQ_PICU5,
    PICU6_IRQ_LINE = IRQ_PICU6,
    PICU12_IRQ_LINE = IRQ_PICU12,
    PICU15_IRQ_LINE = IRQ_PICU15
} gpio_irq_piculines;


typedef struct gpio_irq_s gpio_irq_t;

typedef void (*gpio_irq_handler)(uint32_t id, gpio_irq_event event);
#ifndef EMUNO
int  gpio_irq_init(gpio_irq_t *obj, PinName pin, gpio_irq_handler handler, uint32_t id);
#else
int  gpio_irq_init(gpio_irq_t *obj, PinName pin, gpio_irq_handler handler, uint64_t id);
#endif
void gpio_irq_free(gpio_irq_t *obj);
void gpio_irq_set (gpio_irq_t *obj, gpio_irq_event event, uint32_t enable);
void gpio_irq_enable(gpio_irq_t *obj);
void gpio_irq_disable(gpio_irq_t *obj);

#ifdef __cplusplus
}
#endif

#endif

#endif
