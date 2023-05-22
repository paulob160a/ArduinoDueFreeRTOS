/*****************************************************************************
 * Copyright (c) 2013 Rowley Associates Limited.                             *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include "SAM_Series.h"

#if defined(_SAM3N_SERIES)

#include "CMSIS/Device/ATMEL/sam3n/source/system_sam3n.c"

#elif defined(_SAM3S_SERIES)

#include "CMSIS/Device/ATMEL/sam3s/source/system_sam3s.c"

#elif defined(_SAM3SD8_SERIES)

#include "CMSIS/Device/ATMEL/sam3sd8/source/system_sam3sd8.c"

#elif defined(_SAM3U_SERIES)

#include "CMSIS/Device/ATMEL/sam3u/source/system_sam3u.c"

#elif defined(_SAM3XA_SERIES)

#include "CMSIS/Device/ATMEL/sam3xa/source/system_sam3xa.c"

#elif defined(_SAM4E_SERIES)

#include "CMSIS/Device/ATMEL/sam4e/source/system_sam4e.c"

#elif defined(_SAM4L_SERIES)

#include "CMSIS/Device/ATMEL/sam4l/source/system_sam4l.c"

#elif defined(_SAM4N_SERIES)

#include "CMSIS/Device/ATMEL/sam4n/source/system_sam4n.c"

#elif defined(_SAM4S_SERIES)

#include "CMSIS/Device/ATMEL/sam4s/source/system_sam4s.c"

#elif defined(_SAM4SP_SERIES)

#include "CMSIS/Device/ATMEL/sam4sp/source/system_sam4sp.c"

#elif defined(_SAMD20_SERIES)

#include "CMSIS/Device/ATMEL/samd20/source/system_samd20.c"

#elif defined(_SAMD21_SERIES)

#include "CMSIS/Device/ATMEL/samd21/source/system_samd21.c"

#elif defined(_SAMG51_SERIES)

#include "CMSIS/Device/ATMEL/samg51/source/system_samg51.c"

#elif defined(_SAMG53_SERIES)

#include "CMSIS/Device/ATMEL/samg53/source/system_samg53.c"

#elif defined(_SAMG54_SERIES)

#include "CMSIS/Device/ATMEL/samg54/source/system_samg54.c"

#elif defined(_SAMG55_SERIES)

#include "CMSIS/Device/ATMEL/samg55/source/system_samg55.c"

#elif defined(_SAMR21_SERIES)

#include "CMSIS/Device/ATMEL/samr21/source/system_samr21.c"

#else

#error unknown series

#endif

