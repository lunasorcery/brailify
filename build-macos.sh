BIN_DIR=bin/macos
mkdir -p $BIN_DIR
clang \
	main.cpp \
	-o $BIN_DIR/brailify \
	-Wall \
	-Isrc/ \
	-std=c++11 \
	-lstdc++ \
	;
