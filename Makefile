all: bin/brailify

bin/brailify: main.cpp
	mkdir -p bin/
	$(CXX) main.cpp -std=c++17 -lstdc++ -o bin/brailify -Wall -Wextra -Wpedantic

install: bin/brailify
	cp bin/brailify /usr/local/bin/brailify

clean:
	rm -rf bin/

.PHONY: all install clean
