
/******************************************************************************/
/* hooks.c                                                                    */
/* POB                                                                        */
/* 18.05.23                                                                   */
/******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"
#include "hooks.h"

/******************************************************************************/
/* This is defined here because the default version is not selected for       */
/* building macro "configUSE_TICK_HOOK" in "FreeRTOSConfig.h"                 */
/******************************************************************************/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
  {
/******************************************************************************/

	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();

	for( ;; );

/******************************************************************************/
  } /* end of vApplicationStackOverflowHook                                   */

/******************************************************************************/
/* This is defined here because the default version is not selected for       */
/* building macro "configUSE_IDLE_HOOK"  in "FreeRTOSConfig.h"                */
/******************************************************************************/

void vApplicationMallocFailedHook( void )
  {
/******************************************************************************/

	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();

	for( ;; );

/******************************************************************************/

  } /* end of vApplicationMallocFailedHook                                    */

/******************************************************************************/
/* IN USE i.e. configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.             */
/******************************************************************************/

unsigned long long osTickCounter   = ((unsigned long long)0),
                   osSecondCounter = ((unsigned long long)0);

void vApplicationTickHook( void )
  {
/******************************************************************************/

	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */

  osTickCounter = osTickCounter + ((unsigned long long)1);

  if (((osTickCounter % configTICK_RATE_HZ) == ((unsigned long long)0)) && (osTickCounter != ((unsigned long long)0)))
    {
    osSecondCounter = osSecondCounter + ((unsigned long long)1);
    }

/******************************************************************************/
  } /* end of vApplicationTickHook                                            */

/******************************************************************************/