/******************************************************************************/
/* m3TaskGroup.c                                                              */
/* POB                                                                        */
/* 18.05.23                                                                   */
/******************************************************************************/

#include <stdbool.h>
#include <debugio.h>
#include <sam3x8e.h>
#include <core_cm3.h>
#include "FreeRTOS.h"
#include "task.h"
#include "m3TaskGroup.h"
#include "peripherals.h"

/******************************************************************************/

taskCounters_t     taskCounters    = { ((unsigned long long)0), ((unsigned long long)0) };

ledFlashControl_t  ledFlashCounter = { ((unsigned long long)0), false };

/******************************************************************************/

void m3TaskOne(void *m3TaskParameters)
  {
/******************************************************************************/

  while(true)
    {
    ((taskCounters_t *)m3TaskParameters)->counter1 = 
    ((taskCounters_t *)m3TaskParameters)->counter1 + ((unsigned long long)1);
    }

/******************************************************************************/
  } /* end of m3TaskOne                                                       */

/******************************************************************************/

void m3TaskTwo(void *m3TaskParameters)
  {
/******************************************************************************/

  while(true)
    {
    ((taskCounters_t *)m3TaskParameters)->counter2 = 
    ((taskCounters_t *)m3TaskParameters)->counter2 + ((unsigned long long)1);
    }

/******************************************************************************/
  } /* end of m3TaskTwo                                                       */

/******************************************************************************/

void m3TaskThree(void *m3TaskParameters)
  {
/******************************************************************************/

  while(true)
    {
    debug_printf(" Task 1 Counter = %llu Task 2 Counter = %llu\n", (unsigned long long)((taskCounters_t *)m3TaskParameters)->counter1, (unsigned long long)((taskCounters_t *)m3TaskParameters)->counter2);
    }

/******************************************************************************/
  } /* end of m3TaskThree                                                     */

/******************************************************************************/

void m3TaskFour(void *m3TaskParameters)
  {
/******************************************************************************/

  while(true)
    {
    if (((ledFlashControl_t *)m3TaskParameters)->flashControlState == true)
      {
      ((ledFlashControl_t *)m3TaskParameters)->flashControlState = false;

      peripheralLineControlBlock_p[PERIPHERAL_LINE_GROUP_B]->PIO_CODR = PIO_ODR_P27;
      }
    else
      {
      ((ledFlashControl_t *)m3TaskParameters)->flashControlState = true;

      peripheralLineControlBlock_p[PERIPHERAL_LINE_GROUP_B]->PIO_SODR = PIO_ODR_P27;
      }

    vTaskDelay(M3_LED_FLASH_INTERVAL);
    }

/******************************************************************************/
  } /* end of m3TaskFour                                                      */

/******************************************************************************/