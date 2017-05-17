make: brailify

brailify: main.cpp
	clang main.cpp -o brailify -Wall -std=c++11 -lstdc++

clean:
	rm -f brailify
