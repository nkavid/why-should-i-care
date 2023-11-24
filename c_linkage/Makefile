build:
	mkdir build

WARNINGS = -Wall -Wextra -Wpedantic -Werror

c_lorem:
	gcc ${WARNINGS} -c lorem.c -o build/$@.o
	ar rcs build/lib$@.a build/$@.o

cpp_lorem:
	g++ ${WARNINGS} -c lorem.cpp -o build/$@.o
	ar rcs build/lib$@.a build/$@.o

extern_c_lorem:
	g++ ${WARNINGS} -c $@.cpp -o build/$@.o
	ar rcs build/lib$@.a build/$@.o

c-lorem-app: c_lorem
	gcc ${WARNINGS} main.c -o build/$@ -Lbuild -lc_lorem

cpp-lorem-app: cpp_lorem
	gcc ${WARNINGS} main.cpp -o build/$@ -Lbuild -lcpp_lorem

all: build c_lorem cpp_lorem extern_c_lorem c-lorem-app cpp-lorem-app

clean:
	rm -rf build

.PHONY: all clean
