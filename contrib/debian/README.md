
Debian
====================
This directory contains files used to package frequencyd/frequency-qt
for Debian-based Linux systems. If you compile frequencyd/frequency-qt yourself, there are some useful files here.

## frequency: URI support ##


frequency-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install frequency-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your frequency-qt binary to `/usr/bin`
and the `../../share/pixmaps/frequency128.png` to `/usr/share/pixmaps`

frequency-qt.protocol (KDE)

