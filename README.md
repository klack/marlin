THIS WILL VOID YOUR MANUFACTURER WARRANTY

Do not run this firmware on production machines.

This firmware is a community effort and is not affiliated with Tenlog, Hictop, Copymaster or other distributers.
You assume all risk and liablity by installing this firmware.
It is standard practice for a manufacturer to void your warranty for installing a custom firmware.

## BL-Touch Installation and Configuration
- What does this do?
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

### What do I need to buy?
Well, for starters, a BL-Touch! There are many clones out there, which may or may not work as well. The original, which I (Tom F) would advise getting, is from antclabs. BigTreeTech is an authorized reseller of it. [![Website](https://img.shields.io/badge/Amazon-green?style=flat-square)](https://www.amazon.com/gp/product/B08BYP4G7J/)

Besides the Touch, you also need some jumper extension cables. Speaking of Amazon... [![Website](https://img.shields.io/badge/Amazon-green?style=flat-square)](https://www.amazon.com/gp/product/B07GD1TH2K/)

And that's it!

### How do I install the BL-Touch on the printer?

- Mount the BL-Touch to E1.
  Depending on your extruder type, you need to print out a BL-Touch mount!
  - [![Website](https://img.shields.io/badge/Titan-black?style=flat-square)](https://github.com/klack/marlin/blob/BL-Touch/docs/Titan-BL_Touch-Mount.stl)
  - [![Website](https://img.shields.io/badge/Stock-black?style=flat-square)](https://thingiverse.com)
  - Attach the BL-Touch to the mount.
  ![Mount touch](docs/PXL_20210112_202053715.jpg)
  - Attach the mount to the extruder side.
  ![Mount mount](docs/PXL_20210112_202102498.jpg)
- Run your cables from the BL-Touch along the extruder serial cable to the back of the printer. It is nice to use the same color wires as on the BL-Touch.
![Mount mount](docs/PXL_20210112_202004002.jpg)
![Mount mount](docs/PXL_20210112_202015256.jpg)
- Run the Power(Red), Servo(orange), and Ground(Brown) to the left Z endstop. Run the Sensor(white) to the right Z endstop.
![Mount mount](docs/PXL_20210112_202037819.jpg)
- Unplug your Z endstops. Yep, both of them. You won't need them with the Z-alignment option and we are using the probe as our endstop!
- Plug the wires into each endstop to the correct matchup.
  - Right Endstop
    - Red->Red
    - Green->Orange
    - White->Brown
    ![Mount mount](docs/PXL_20210112_201922725.jpg)
  - Left Endstop
    - Black->White
    ![Mount mount](docs/PXL_20210112_201846120.jpg)
    
That's it! I taped multiple jumper wires together to make the right length cables. All the plugging in is done above the printer!
    
### How to configure...

#### Install BL-Touch Firmware
Well, you need to install the BL-Touch variant of the LuxURI firmware. There's one for each machine and extruder combo. For instructions on this, see Tenlog's documentation on burning firmware.

#### Probe Offsets
This can be a little tricky.
- Home your X and Y axis, and then your Z axis.
  - WOAH! Why did my head just go to the center of the bed to home Z?
    -This is called Z-Safe Homing. It ensures that no matter your current offsets, your probe will actually touch the bed and not outside of it.
- Place a marker where your probe just touched the plate. Could be painters tape, dry erase marker, whatever. Be pretty precise.
- Take note of your current X and Y positions.
- Now, move your nozzle tip to that exact position.
- Take note of the new X and Y positions.
- the difference is your offsets. Negative X is the probe is to the left of the nozzle, positive to the right. Negative Y is the probe is in front of the nozzle, positive behind.
- Slowly lower your Z axis down to zero without letting it hit your bed. You want 0 to be where you would have the nozzle for first layer. A piece of paper sliding with a little resistance. If you are above that at 0, you need to make your Z offset more negative to get where you want. If you can't make 0 without hitting the bed, it needs to be more positive.

#### Z-Alignment (Since we no longer have 2 endstops)
G34 - That's it! It will make sure your X-axis is completely level to the plate.

#### Generate bed mesh
G28 - Home your axis.
G29 P0 - This will clear out any bed mesh stored.
G29 P1 - This will begin the mesh generation! Kind of fun to watch. This only does a certain amount at first, usually the center spiral.
G29 P3 T - This will generate the rest of the mesh. Keep running until it won't do anymore.
G29 S1 - Save the mesh to EEPROM.

#### Enable UBL auto-leveling
G29 A F 10.0 - Enables unified bed leveling with a Z-fade of 10. This means it will gradually even the layers to flat until 10mm high where it will be totally flat.
M500 - Save leveling and settings to EEPROM.
