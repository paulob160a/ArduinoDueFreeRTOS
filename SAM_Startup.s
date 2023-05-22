/*****************************************************************************
 * Copyright (c) 2012 Rowley Associates Limited.                             *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include "SAM_Series.h"

#if defined(_SAM3N_SERIES)

#include "SAM3N_Startup.s"

#elif defined(_SAM3S_SERIES)

#include "SAM3S_Startup.s"

#elif defined(_SAM3SD8_SERIES)

#include "SAM3SD8_Startup.s"

#elif defined(_SAM3U_SERIES)

#include "SAM3U_Startup.s"

#elif defined(_SAM3XA_SERIES)

#include "SAM3XA_Startup.s"

#elif defined(_SAM4E_SERIES)

#include "SAM4E_Startup.s"

#elif defined(_SAM4L_SERIES)

#include "SAM4L_Startup.s"

#elif defined(_SAM4N_SERIES)

#include "SAM4N_Startup.s"

#elif defined(_SAM4S_SERIES)

#include "SAM4S_Startup.s"

#elif defined(_SAM4SP_SERIES)

#include "SAM4SP_Startup.s"

#elif defined(_SAMD20_SERIES)

#include "SAMD20_Startup.s"

#elif defined(_SAMD21_SERIES)

#include "SAMD21_Startup.s"

#elif defined(_SAMG51_SERIES)

#include "SAMG51_Startup.s"

#elif defined(_SAMG53_SERIES)

#include "SAMG53_Startup.s"

#elif defined(_SAMG54_SERIES)

#include "SAMG54_Startup.s"

#elif defined(_SAMG55_SERIES)

#include "SAMG55_Startup.s"

#elif defined(_SAMR21_SERIES)

#include "SAMR21_Startup.s"

#else

#error unknown series

#endif

