LittleBrother is a Linux-based security camera manager, made with gtkmm-2.4
and opencv 3.1.0. It was compiled with the cmake-gui, with the flag WITH_GTK on
and the flag WITH_GTK_2 off. That way it forces the linker to use GTK 3. If you
get undefined errors when compiling and running, then you do not have all of
the libraries that each of these libraries needs. 

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
