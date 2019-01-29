CXX = c++
CFLAGS = -fPIC -Wall -Wextra  
EXE=main
SRC = source/main.cc 
OBJ = $(SRC:.c=.o)
SRCH = include/hello.cc
OBJH = include/hello.o 


all: libhello.so ${EXE}

${EXE}:libhello.so ${SRC}
	$(CXX) ${SRC} -o $@ -lhello -I include -L.

libhello.so:$(OBJH)
	$(CXX) -shared -o $@ $^
%.o:%.cc
	$(CXX) ${CFLAGS}  -o $@ -c $< -Iinclude


clean:
	-rm -f libhello.so  ${OBJS} 


