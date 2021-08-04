LittleBrother is a Linux-based desktop application for monitoring security cameras, and was built with opencv 4.3.0. For some reason, it will not work unless you build and install opencv 4.3.0 with BOTH of the flags WITH_GTK and WITH_GTK_2. Currently trying to figure out how it can have dependencies from both of these. 

This program uses mutt for email notifications:
"sudo apt-get install mutt"
If you do not have it installed, it will not crash, but you will not
receive email notifications. You may have to check your spam folder if you
are not getting the emails. 

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
