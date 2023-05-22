/******************************************************************************/
/* peripherals.h                                                              */
/* POB                                                                        */
/* 20.05.23                                                                   */
/******************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/******************************************************************************/

#include <sam3x8e.h>
#include <core_cm3.h>
#include "m3TaskGroup.h"


/******************************************************************************/

typedef enum peripheralBlocks_tTag
  {
  PERIPHERAL_LINE_GROUP_A,
  PERIPHERAL_LINE_GROUP_B,
  PERIPHERAL_LINE_GROUP_C,
  PERIPHERAL_LINE_GROUP_D,
  NUMBER_OF_PERIPHERAL_LINE_GROUPS
  } peripheralBlocks_t;

/******************************************************************************/

extern Pmc *peripheralControlBlock;
extern Pio *peripheralLineControlBlock_p[NUMBER_OF_PERIPHERAL_LINE_GROUPS];

/******************************************************************************/

#endif
/******************************************************************************/