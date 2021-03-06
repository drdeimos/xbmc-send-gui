CC=g++
LDLIBS=`pkg-config --libs gtk+-3.0 gmodule-2.0`
CFLAGS=-Wall -g `pkg-config --cflags gtk+-3.0 gmodule-2.0`

xbmc-send-gui: xbmc-send-gui.o
	$(CC) $(LDLIBS) xbmc-send-gui.o -o src/xbmc-send-gui

xbmc-send-gui.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp -o xbmc-send-gui.o

clean:
	rm -f src/xbmc-send-gui
	rm -f *.o
