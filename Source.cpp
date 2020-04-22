#include "shif.h"

int main() {
	replacement a;
	// a.key_generator("my_alphabet.alph", "replacement.key");
	//a.Encrypt("test.encrypt", "replacement.key", "test.txt");
	a.decipher("replacement.key", "test.encrypt", "test.encrypt.txt");
	return 0;
}