# W7500x_StdPeriph_Lib

The W7500x Standard Peripherals Library is a complete package, consisting of device drivers for all of the standard device peripherals, for W7500x  devices 32-bit Flash microcontrollers.

This library is a firmware package which contains a collection of routines, data structures and macros covering the features of W7500x peripherals. It includes a description of the device drivers plus a set of examples for each peripheral. The firmware library allows any device to be used in the user application without the need for in-depth study of each peripheral’s specifications.

Using the Standard Peripherals Library has two advantages: it saves significant time that would otherwise be spent in coding, while simultaneously reducing application development and integration costs.

The W7500x Standard Peripherals Library is full CMSIS compliant.

## Supported devices and toolchains

### Supported W7500x devices

The Standard Peripherals Library supports [W7500](https://wizwiki.net/wiki/doku.php?id=products:w7500:start) and [W7500P](https://wizwiki.net/wiki/doku.php?id=products:w7500p:start) devices.

### Supported toolchains

The Standard Peripherals Library supports the following toolchains:
- MDK-ARM 
- GNU MCU Eclipse

For the GNU MCU Eclipse development environment, see the https://github.com/Wiznet/W7500x_StdPeriph_Lib/wiki page.

## How to use the Library

### Create a project

Create a project on your toolchain(or use the template project provided within the Library, under 
Project\W7500x_StdPeriph_Templates)

### Configure w7500x.h

The Library entry point is w7500x.h (under Libraries\CMSIS\Device\WIZnet\W7500\Include), user has to include it in the application main and configure it:

- Select the target product to be used, comment/uncomment the right define:
  ```
  /* Uncomment the line below according to the target W7500x device used in your
   application
   */
  #if !defined (W7500) && !defined (W7500P)
  #define W7500
  //#define W7500P
  #endif
  ```
- Select the target system clock source to be used, comment/uncomment the right define:
  ```
  /**
   * @brief In the following line adjust the value of External oscillator clock (8MHz ~ 24MHz)
   used in your application

   Tip: If you want to use the Internal 8MHz RC oscillator clock, uncomment the line below.
   */
  //#define OCLK_VALUE 12000000UL
  ```
- Change the PLL value to be used.
  ```
  /**
   * @brief In the following line adjust the value of PLL
   */
  #define PLL_VALUE 1
  ```
  
### Add the system_w7500x.c

Add the system_w7500x.c (under Libraries\CMSIS\Device\WIZnet\W7500\Source) file in your application, this file provide functions to setup the W7500x system.

## How to use the Examples

### Copy and Paste

Copy all source files from under Projects\W7500x_StdPeriph_Examples\xxx\xxx folder to the under src folder.

### Configure main.h

- Select the target board to be used, comment/uncomment the right define:
  ```
  /* Uncomment the line below according to the target EVB board of W7500x used in
   your application
   */
  #if !defined (USE_WIZWIKI_W7500_EVAL) && !defined (USE_WIZWIKI_W7500P_EVAL) && !defined (USE_WIZWIKI_W7500_ECO_EVAL)
  #define USE_WIZWIKI_W7500_EVAL
  //#define USE_WIZWIKI_W7500P_EVAL
  //#define USE_WIZWIKI_W7500_ECO_EVAL
  //#define USE_MY_EVAL
  #if defined (USE_WIZWIKI_W7500_EVAL)
  #define USING_UART1
  #else
  #define USING_UART2
  #endif
  #endif
  ```
## Revision History

### v1.0.0
- First release

### v1.0.1
- Fix some bugs for GPIO function
