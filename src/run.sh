#!/bin/sh
make clean
make
ls ../song | grep *.mp3 > song.txt
./main
