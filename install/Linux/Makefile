##
## Makefile for racer in /home/zgore/Projects/cpp_2017/Indie_studio/install/Linux
##
## Made by Pierre Zawadil
## Login   <pierre.zawadil@epitech.eu>
##
## Started on  Thu Jun  8 15:15:53 2017 Pierre Zawadil
## Last update Fri Jun  9 17:54:33 2017 DaZe
##


all	:	help

help	:
		@echo "\033[0;31mRun 'make install' to install the Game !"

install	:
		@echo "\033[0;31m[WELCOME TO FRATERNITY STUDIO INSTALLER]"
		@echo "\033[0;33m[INSTALLING LIBRARIES]\033[0;32m"

		sudo cp libIrrlicht.so.1.8.4 /usr/local/lib/
		sudo cp libIrrKlang.so /usr/local/lib/

		sudo ln -s -f /usr/local/lib/libIrrlicht.so.1.8.4 /usr/local/lib/libIrrlicht.so.1.8
		sudo ln -s -f /usr/local/lib/libIrrlicht.so.1.8 /usr/local/lib/libIrrlicht.so

		@echo "\033[0;33m[CREATING GAME DIRECTORY]\033[0;32m"

		mkdir ~/Racer
		mkdir ~/Racer/Saves
		mkdir ~/Racer/Config

		ldconfig -n ~/Racer

		cp Racer ~/Racer/
		cp Racer.sh ~/Racer/

		@echo "\033[0;33m[CREATING BINARY IN /USR/BIN]\033[0;32m"

		sudo ln -sf ~/Racer/Racer.sh /usr/bin/Racer

		@echo "\033[0;33m[DECOMPRESSING ASSETS]\033[0;32m"

		cp assets.tar ~/Racer
		cd ~/Racer && tar -xvf assets.tar

		@echo "\033[0;33m[INSTALLATION COMPLETE]\033[0;32m"

		@echo "\033[0;31m/!\\ You must have these packages installed : \n\033[0;34mbuild-essential xserver-xorg-dev x11proto-xf86vidmode-dev libxxf86vm-dev mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev libxext-dev libxcursor-dev"

.PHONY	: all install help
