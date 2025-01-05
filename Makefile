NAME=cube
CXX=g++
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
CFLAGS=-c -Wall -DDEBUG -g3 -fpermissive -MMD

ifeq ($(OS),Windows_NT)
#LIBS =-lglfw3 -l:glew32.dll -lopengl32 -lm -lglu32 -lgdi32
LIBS =-lglfw3 -lglew32 -lopengl32 -lm -lglu32 -lgdi32
EXECUTABLE = $(NAME).exe
#LDFLAGS=-Wl,--subsystem,windows
else
LIBS = -lX11 -lglfw -lGL -lGLU -lGLEW -lm
EXECUTABLE = $(NAME)
endif

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
	rm -f $(SOURCES:%.cpp=%.d)

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@ $(LIBS)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LIBS)

run: $(EXECUTABLE)
	./$(EXECUTABLE) -sync -gldebug
-include $(SOURCES:%.cpp=%.d)

zip: clean
	zip -r $(NAME) *.h *.cpp *.glsl Makefile
ok: run
	find . -type f -not -name '*.zip' -not -name 'ok' -print0 | xargs -0 rm --
	ok2
