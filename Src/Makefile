CXX=g++
LFLAGS        = -m64
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB
OBJECTS       = IndexTerminal.o \
		2DProcessingSrc.o \
		3DProcessingSrc.o \
		InputSrc.o \
		InteractiveSrc.o \
		OutputSrc.o
TARGET        = draw

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) $(INCPATH) -std=c++14

$(TARGET):  $(OBJECTS)  
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS) -std=c++14

.PHONY: clean

clean: 
	rm -f *.o $(TARGET)