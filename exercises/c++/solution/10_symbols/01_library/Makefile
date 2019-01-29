CXX = c++
LANG = ITALIANO
CFLAGS = -fPIC -Wall -Wextra  -g
EXE=main
SRC = source/main.cc 
OBJ = $(SRC:.c=.o)
SRCH = include/hello.cc
OBJH = include/hello.o 

install: main
all: libhello.so ${EXE}

${EXE}:libhello.so ${SRC}
	$(CXX) ${SRC} -o $@ -lhello -I include -L.

libhello.so:$(OBJH)
	$(CXX) -shared -o $@ $^
%.o:%.cc
	$(CXX) ${CFLAGS} -D$(LANG) -o $@ -c $< -Iinclude


clean:
	-rm -f libhello.so ${OBJS} $(SRCS:.c=.d)


