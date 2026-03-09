run:
	clang++ -std=c++20 main.cc -o main
	./main

check:
	valgrind --leak-check=full --show-leak-kinds=all ./main
	clang-check main.cc -- -std=c++20 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wnull-dereference -Wdouble-promotion -Wimplicit-fallthrough
