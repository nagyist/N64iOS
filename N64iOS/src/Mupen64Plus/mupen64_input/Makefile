#/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# *   Mupen64plus - Makefile                                                *
# *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
# *   Copyright (C) 2007-2008 Tillin9 Richard42                             *
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
# *   This program is distributed in the hope that it will be useful,       *
# *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
# *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
# *   GNU General Public License for more details.                          *
# *                                                                         *
# *   You should have received a copy of the GNU General Public License     *
# *   along with this program; if not, write to the                         *
# *   Free Software Foundation, Inc.,                                       *
# *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
# Makefile for Mupen64 Input in Mupen64plus.

# include pre-make file with a bunch of definitions
USES_GTK2 = true 
include ../pre.mk

# local CFLAGS, LIBS, and LDFLAGS
CFLAGS += -fpic -DPIC

ifeq ($(GUI),GTK2)
  CFLAGS += $(GTK_FLAGS) -DUSE_GTK
  PLUGIN_LDFLAGS += $(GTK_LIBS)
endif

# list of object files to generate
OBJECTS = main.o

# build targets
all: mupen64_input.dylib

clean:
	rm -f *.o *.dylib

# build rules
.c.o:
	$(CC) -o $@ $(CFLAGS) $(SDL_FLAGS) -c $<

mupen64_input.dylib: $(OBJECTS)
	$(CC) $^ $(LDFLAGS) $(SDL_LIBS) $(PLUGIN_LDFLAGS) -o $@
	$(STRIP) $@

