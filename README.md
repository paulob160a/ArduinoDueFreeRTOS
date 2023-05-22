# ArduinoDueFreeRTOS
A simple "blinky"-style project demonstrating FreeRTOS running on an Arduino Due

Never could find an example of FreeRTOS running on Arduino Due. Am about to say goodbye to 
the Due in favour of the Adafruit M7 Metro but before walking into the Atmel sunset I just 
wanted to have a clear, if very simple, exposition that worked. I have used FreeRTOS 
commercially on other processor families but for hobbyist stuff I usually go bare...metal.

This demo uses Rowley CrossWorks for ARM release 4.10.2.2023033100.52918. Sorry, it is not 
free but the hobbyist version, which I use, is very reasonable. Since the 64-bit version 
releases it is about the best there is (and I have used Atmel Studio - pretty good, Keil - 
competent but uninspiring, IAR - just say no!, Segger - a pale echo of CrossWorks from 
yesteryear and others I can't even be bothered to remember). Now if only Visual Studio had 
a native ARM cross-compiler and debugger suite...

FreeRTOS is version v202212.01. Kudos to Richard Barry and my old mucker Andy Longhurst, 
both at Wittenstein.

My small contribution are the files main.c, m3TaskGroup.c/.h, hooks.c/.h (mostly FreeRTOS 
code) and peripherals.h (using the ARM CMSIS 5 definitions and macros). Here you will find 
unprotected global variables - execution order is not critical here. But please explore 
the mutex/critical region methods of FreeRTOS before trying to use it in anger.

The chip startup code belongs to Rowley and is only for example here as it is protected by 
their licensing conditions.

Any files that appear to be missing are not - just root around in the Rowley and CMSIS 5 
directories.

The project details i.e. layout and properties are presented here as screenshots rendered 
in .pdf. There is also a sort of build verification screenshot.

My coding style is rigorous to anal, I hate 'C' coding shortcuts and poor layout. I also 
hate implicit...anything and "magic numbers". The code layout uses Rowley defaults for 
tabs (which I also hate!) and all the boring character stuff. An old colleague of mine 
had the following golden rule and I recommend it : "Do not try to second-guess the 
compiler!".

Embedded software geeks of the world, I salute you! And me of course, about as geekish 
as they come in the presence of a microcontroller.

--------------------------------------------------------------------------------------------------






