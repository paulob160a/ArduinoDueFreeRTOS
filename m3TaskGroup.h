/******************************************************************************/
/* m3TaskGroup.h                                                              */
/* POB                                                                        */
/* 18.05.23                                                                   */
/******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

/******************************************************************************/

#ifndef _M3_TASK_GROUP_H_
#define _M3_TASK_GROUP_H_

/******************************************************************************/

#define M3_TASK_ONE_NAME           "m3TaskOne"
#define M3_TASK_TWO_NAME           "m3TaskTwo"
#define M3_TASK_THREE_NAME         "m3TaskThree"
#define M3_TASK_FOUR_NAME          "m3TaskFour"

#define M3_TASK_ONE_TEST_PARAMETER (0x1234)
#define M3_TASK_TWO_TEST_PARAMETER (0x9876)

#define M3_TASK_ONE_PRIORITY       (tskIDLE_PRIORITY + 1)
#define M3_TASK_TWO_PRIORITY       (tskIDLE_PRIORITY + 1)
#define M3_TASK_THREE_PRIORITY     (tskIDLE_PRIORITY + 1)
#define M3_TASK_FOUR_PRIORITY      (tskIDLE_PRIORITY + 1)

#define M3_LED_FLASH_MILLISECONDS  (1000)
#define M3_LED_FLASH_INTERVAL      (M3_LED_FLASH_MILLISECONDS * portTICK_PERIOD_MS) // 84000 ticks = 1000 milliseconds

/******************************************************************************/

typedef struct taskCounters_tTag
  {
  unsigned long long counter1;
  unsigned long long counter2;
  } taskCounters_t;

typedef struct ledFlashControl_tTag
  {
  unsigned long long flashCounter;
  bool               flashControlState;
  } ledFlashControl_t;

/******************************************************************************/

extern taskCounters_t    taskCounters;
extern ledFlashControl_t ledFlashCounter;

/******************************************************************************/

extern void m3TaskOne(void *m3TaskParameters);
extern void m3TaskTwo(void *m3TaskParameters);
extern void m3TaskThree(void *m3TaskParameters);
extern void m3TaskFour(void *m3TaskParameters);

/******************************************************************************/

#endif

/******************************************************************************/