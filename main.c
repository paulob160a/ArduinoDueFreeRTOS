/******************************************************************************/
/* main.c                                                                     */
/* POB                                                                        */
/* 18.05.23                                                                   */
/*                                                                            */
/* A simple demonstration of FreeRTOS running on an Arduino Due. The          */
/* operating system is used to instantiate a small group of tasks which keep  */
/* a couple of free-running counters, display the timers' progress and flash  */
/* the Due LED 'L' with a one-second duty-cycle (good ole Blinky!)            */
/*                                                                            */
/* A tiny subset of the ARM CMSIS peripheral control registers are used to    */
/* set-up and flash LED 'L'                                                   */
/*                                                                            */
/* NOTE : macro"_SAM3X8E_" is defined by the IDE. This selects starting-up of */
/* the system clocks during the startup code prior to "main()"                */
/*                                                                            */
/* Ref : D:\FreeRTOS\FreeRTOSv202212.01\FreeRTOS\Demo\CORTEX_ATSAM3X_Atmel_   */
/* Studio\src                                                                 */
/******************************************************************************/

#include <debugio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sam3x8e.h>
#include <core_cm3.h>
#include "FreeRTOS.h"
#include "task.h"
#include "hooks.h"
#include "m3TaskGroup.h"
#include "peripherals.h"

/******************************************************************************/

Pmc *peripheralControlBlock = PMC; // points to the peripheral maps

Pio *peripheralLineControlBlock_p[NUMBER_OF_PERIPHERAL_LINE_GROUPS] = // physical block addresses
  {
  ((Pio *)0x400E0E00U),
  ((Pio *)0x400E1000U),
  ((Pio *)0x400E1200U),
  ((Pio *)0x400E1400U)
  };

/******************************************************************************/

void main(void)
  {
/******************************************************************************/

  // Switch on peripheral block 'B' to enable LED 'L'
  peripheralControlBlock->PMC_PCER0 = (1 << ID_PIOB);

  // Switch on the LED
  peripheralLineControlBlock_p[PERIPHERAL_LINE_GROUP_B]->PIO_PER  = PIO_PER_P27;

  // Pull-up the control line
  peripheralLineControlBlock_p[PERIPHERAL_LINE_GROUP_B]->PIO_PUER = PIO_PUER_P27;

  // Switch on the output
  peripheralLineControlBlock_p[PERIPHERAL_LINE_GROUP_B]->PIO_OER  = PIO_OER_P27;

  xTaskCreate(m3TaskOne,
              M3_TASK_ONE_NAME,
              configMINIMAL_STACK_SIZE,
              (void *)&taskCounters,
              M3_TASK_ONE_PRIORITY,
              NULL);

  xTaskCreate(m3TaskTwo,
              M3_TASK_TWO_NAME,
              configMINIMAL_STACK_SIZE,
              (void *)&taskCounters,
              M3_TASK_TWO_PRIORITY,
              NULL);

  xTaskCreate(m3TaskThree,
              M3_TASK_THREE_NAME,
              configMINIMAL_STACK_SIZE,
              (void *)&taskCounters,
              M3_TASK_THREE_PRIORITY,
              NULL);

  xTaskCreate(m3TaskFour,
              M3_TASK_FOUR_NAME,
              configMINIMAL_STACK_SIZE,
              (void *)&ledFlashCounter,
              M3_TASK_FOUR_PRIORITY,
              NULL);


  debug_printf(" Task 1 Counter = %llu Task 2 Counter = %llu\n", (unsigned long long)taskCounters.counter1, (unsigned long long)taskCounters.counter2);

  vTaskStartScheduler();

/******************************************************************************/
  } /* end of main                                                            */

/******************************************************************************/
