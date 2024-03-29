 /**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if HAS_STATUS_MESSAGE

#include "../gcode.h"
#include "../../lcd/marlinui.h"

/**
 * M117: Set LCD Status Message
 */
void GcodeSuite::M117() {

  if (parser.string_arg && parser.string_arg[0])
    { 
      ui.set_status(parser.string_arg);  
      MYSERIAL1.print("//lux:M117 "); MYSERIAL1.print(parser.string_arg);MYSERIAL1.write(13);
      #ifdef SERIAL_PORT_2
        MYSERIAL2.print("//lux:M117 "); MYSERIAL2.print(parser.string_arg);MYSERIAL2.write(13);
      #endif
      #ifdef SERIAL_PORT_3
        MYSERIAL3.print("//lux:M117 "); MYSERIAL3.print(parser.string_arg);MYSERIAL3.write(13);
      #endif
    }
else
  ui.reset_status();
}
#endif
