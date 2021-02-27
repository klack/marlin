<<<<<<< HEAD
THIS WILL VOID YOUR MANUFACTURER WARRANTY

Do not run this firmware on production machines.

This firmware is a community effort and is not affiliated with Tenlog, Hictop, Copymaster or other distributers.
You assume all risk and liablity by installing this firmware.
It is standard practice for a manufacturer to void your warranty for installing a custom firmware.

## BL-Touch Installation and Configuration
- What does this do?
- What can I expect to be different?
- What do I need to buy?
- How do I install the BL-Touch on the printer?
- How to configure...
  - Install BL-Touch Firmware
  - Probe Offsets
  - Z-Alignment (Since we no longer have 2 endstops)
  - Generate bed mesh
  - Enable UBL auto-leveling
  
### What does this do?
BL-Touch is a probe with amazing accuracy. It can detect the slightest pressure, allowing it to tell the distance it is from a contact surface.

In 3D printing, probes are used to do a few things
- Ensure that your Z home is always a certain distance above the build plate, no matter what plate, without having to adjust endstops or screws.
- Generate a mesh of the bed. Essentially, most beds are not perfectly flate, but instead deviate slightly depending on where you are on the plate. The mesh is like a topography of all of those ups and downs. When printing, you can use this mesh so that your first layer, no matter where the head is, will always be the same distance from the plate in all locations, resulting in an amazing adhesion. With something called Z-fade, it will auto flatten out over a certain size so that part measurements are still accurate.

### What can I expect to be different?
Well, a few things...
- Losing both Z endstops.

  OMG CRASH! Well, not really, let's think about things. So currently, you have an endstop for each Z axis. Now that should make your X axis square with your vertical bars right? Sure it will, but it won't make it square with your build plate now will it? What we do using the BL-Touch is something called a Z-alignment.
  
  Z-alignments are cool. The probe will hit the mid-left and mid-right of the plate, and align the 2 Z axis to be parallel to those two points. That becomes your new Z!
  
- WTH Homing routine?

  So about missing those endstops. Well, to make things safe for everyone, we've taken Z-Safe Homing and upped the ante. (Read up on Z-Safe homing if you don't know what that is)
  
  Instead of a z-home, or a z-safe home, we do the z alignment and take the average and make that the Z-home. When combined with the auto-leveling, this gives us a nice homing start for any print.
  
  While this adds an extra 10 seconds or so onto the homing routine, we feel that it's probably a good idea to provide as safe and seamless an experience for users as possible. Just like a home on the normal build, X1 and 2 will be at home locations, Y will be at home location, and Z will be a bit above it's 0. This is because we will be using bed mesh, and when we start printing, Z will come down to the build plate.

### What do I need to buy?
Well, for starters, a BL-Touch! There are many clones out there, which may or may not work as well. The original, which I (Tom F) would advise getting, is from antclabs. BigTreeTech is an authorized reseller of it. [![Website](https://img.shields.io/badge/Amazon-green?style=flat-square)](https://www.amazon.com/gp/product/B08BYP4G7J/)

Besides the Touch, you also need some jumper extension cables. Speaking of Amazon... [![Website](https://img.shields.io/badge/Amazon-green?style=flat-square)](https://www.amazon.com/gp/product/B07GD1TH2K/)

And that's it!

### How do I install the BL-Touch on the printer?

- Mount the BL-Touch to E1.
  Depending on your extruder type, you need to print out a BL-Touch mount! Use supports for only what's touching the build plate.
  - [![Website](https://img.shields.io/badge/Titan-black?style=flat-square)](https://github.com/klack/marlin/blob/BL-Touch/docs/Titan-BL_Touch-Mount.stl)
  - [![Website](https://img.shields.io/badge/Stock-black?style=flat-square)](https://www.thingiverse.com/thing:4726829)
  - Attach the BL-Touch to the mount.
  ![Mount touch](docs/PXL_20210112_202053715.jpg)
  - Attach the mount to the extruder side.
  ![Mount mount](docs/PXL_20210112_202102498.jpg)
- Run your cables from the BL-Touch along the extruder serial cable to the back of the printer. It is nice to use the same color wires as on the BL-Touch.
![Touch wires 1](docs/PXL_20210112_202004002.jpg)
![Touch wires 2](docs/PXL_20210112_202015256.jpg)
- Run the Power(Red), Servo(orange), and Ground(Brown) to the left Z endstop. Run the Sensor(white) to the right Z endstop.
![Draped wires](docs/PXL_20210112_202037819.jpg)
- Unplug your Z endstops. Yep, both of them. You won't need them with the Z-alignment option and we are using the probe as our endstop!
- Plug the wires into each endstop to the correct matchup.
  - Right Endstop
    - Red->Red
    - Green->Orange
    - White->Brown
    ![Right endstop wires](docs/PXL_20210112_201922725.jpg)
  - Left Endstop
    - Black->White
    ![Left endstop wires](docs/PXL_20210112_201846120.jpg)
    
That's it! I taped multiple jumper wires together to make the right length cables. All the plugging in is done above the printer!
    
### How to configure...

#### Install BL-Touch Firmware
Well, you need to install the BL-Touch variant of the LuxURI firmware. There's one for each machine and extruder combo. For instructions on this, see Tenlog's documentation on burning firmware.

#### Probe Offsets
This can be a little tricky.
- Home your X and Y axis, and then your Z axis.
- Move your E1 to the middle of the build plate (155, 155).
- Perform an M401 to deploy your probe. Lower the Z until your probe is almost touching the plate.
- Stow your probe with an M402.
- Place a marker where your probe tip is on the plate. Could be painters tape, dry erase marker, whatever. Be pretty precise.
- Now, move your nozzle tip to that exact position and lower your Z until your nozzle is almost touching the plate.
- Validate the nozzle is right at where the probe was.
- Take note of the new X and Y positions.
- The difference between (155, 155) and the new position is your offsets. Negative X is the probe is to the left of the nozzle, positive to the right. Negative Y is the probe is in front of the nozzle, positive behind.
- Slowly lower your Z axis down to zero without letting it hit your bed. You want 0 to be where you would have the nozzle for first layer. A piece of paper sliding with a little resistance. If you are above that at 0, you need to make your Z offset more negative to get where you want. If you can't make 0 without hitting the bed, it needs to be more positive.

#### Generate bed mesh
G28 - Home your axis.
G29 P0 - This will clear out any bed mesh stored.
G29 P1 - This will begin the mesh generation! Kind of fun to watch. This only does a certain amount at first, usually the center spiral.
G29 P3 T - This will generate the rest of the mesh. Keep running until it won't do anymore.
G29 S1 - Save the mesh to EEPROM.

#### Enable UBL auto-leveling
G29 A F 10.0 - Enables unified bed leveling with a Z-fade of 10. This means it will gradually even the layers to flat until 10mm high where it will be totally flat.
M500 - Save leveling and settings to EEPROM.
=======
# Marlin 3D Printer Firmware

![GitHub](https://img.shields.io/github/license/marlinfirmware/marlin.svg)
![GitHub contributors](https://img.shields.io/github/contributors/marlinfirmware/marlin.svg)
![GitHub Release Date](https://img.shields.io/github/release-date/marlinfirmware/marlin.svg)
[![Build Status](https://github.com/MarlinFirmware/Marlin/workflows/CI/badge.svg?branch=bugfix-2.0.x)](https://github.com/MarlinFirmware/Marlin/actions)

<img align="right" width=175 src="buildroot/share/pixmaps/logo/marlin-250.png" />

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Marlin 2.0

Marlin 2.0 takes this popular RepRap firmware to the next level by adding support for much faster 32-bit and ARM-based boards while improving support for 8-bit AVR boards. Read about Marlin's decision to use a "Hardware Abstraction Layer" below.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Building Marlin 2.0

To build Marlin 2.0 you'll need [Arduino IDE 1.8.8 or newer](https://www.arduino.cc/en/main/software) or [PlatformIO](http://docs.platformio.org/en/latest/ide.html#platformio-ide). Detailed build and install instructions are posted at:

  - [Installing Marlin (Arduino)](http://marlinfw.org/docs/basics/install_arduino.html)
  - [Installing Marlin (VSCode)](http://marlinfw.org/docs/basics/install_platformio_vscode.html).

### Supported Platforms

  Platform|MCU|Example Boards
  --------|---|-------
  [Arduino AVR](https://www.arduino.cc/)|ATmega|RAMPS, Melzi, RAMBo
  [Teensy++ 2.0](http://www.microchip.com/wwwproducts/en/AT90USB1286)|AT90USB1286|Printrboard
  [Arduino Due](https://www.arduino.cc/en/Guide/ArduinoDue)|SAM3X8E|RAMPS-FD, RADDS, RAMPS4DUE
  [LPC1768](http://www.nxp.com/products/microcontrollers-and-processors/arm-based-processors-and-mcus/lpc-cortex-m-mcus/lpc1700-cortex-m3/512kb-flash-64kb-sram-ethernet-usb-lqfp100-package:LPC1768FBD100)|ARM® Cortex-M3|MKS SBASE, Re-ARM, Selena Compact
  [LPC1769](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512kb-flash-64kb-sram-ethernet-usb-lqfp100-package:LPC1769FBD100)|ARM® Cortex-M3|Smoothieboard, Azteeg X5 mini, TH3D EZBoard
  [STM32F103](https://www.st.com/en/microcontrollers-microprocessors/stm32f103.html)|ARM® Cortex-M3|Malyan M200, GTM32 Pro, MKS Robin, BTT SKR Mini
  [STM32F401](https://www.st.com/en/microcontrollers-microprocessors/stm32f401.html)|ARM® Cortex-M4|ARMED, Rumba32, SKR Pro, Lerdge, FYSETC S6
  [STM32F7x6](https://www.st.com/en/microcontrollers-microprocessors/stm32f7x6.html)|ARM® Cortex-M7|The Borg, RemRam V1
  [SAMD51P20A](https://www.adafruit.com/product/4064)|ARM® Cortex-M4|Adafruit Grand Central M4
  [Teensy 3.5](https://www.pjrc.com/store/teensy35.html)|ARM® Cortex-M4|
  [Teensy 3.6](https://www.pjrc.com/store/teensy36.html)|ARM® Cortex-M4|
  [Teensy 4.0](https://www.pjrc.com/store/teensy40.html)|ARM® Cortex-M7|
  [Teensy 4.1](https://www.pjrc.com/store/teensy41.html)|ARM® Cortex-M7|

## Submitting Changes

- Submit **Bug Fixes** as Pull Requests to the ([bugfix-2.0.x](https://github.com/MarlinFirmware/Marlin/tree/bugfix-2.0.x)) branch.
- Follow the [Coding Standards](http://marlinfw.org/docs/development/coding_standards.html) to gain points with the maintainers.
- Please submit your questions and concerns to the [Issue Queue](https://github.com/MarlinFirmware/Marlin/issues).

## Marlin Support

For best results getting help with configuration and troubleshooting, please use the following resources:

- [Marlin Documentation](http://marlinfw.org) - Official Marlin documentation
- [Marlin Discord](https://discord.gg/n5NJ59y) - Discuss issues with Marlin users and developers
- Facebook Group ["Marlin Firmware"](https://www.facebook.com/groups/1049718498464482/)
- RepRap.org [Marlin Forum](http://forums.reprap.org/list.php?415)
- [Tom's 3D Forums](https://forum.toms3d.org/)
- Facebook Group ["Marlin Firmware for 3D Printers"](https://www.facebook.com/groups/3Dtechtalk/)
- [Marlin Configuration](https://www.youtube.com/results?search_query=marlin+configuration) on YouTube

## Credits

The current Marlin dev team consists of:

 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - USA &nbsp; [Donate](http://www.thinkyhead.com/donate-to-marlin)
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - USA
 - Chris Pepper [[@p3p](https://github.com/p3p)] - UK
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - USA
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)] - Netherlands &nbsp; [![Flattr Erik](https://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
>>>>>>> 2.0.x
