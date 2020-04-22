#include "shif.h"

int main() {
	/*replacement a;
	a.key_generator("my_alphabet.alph", "replacement.key");
	a.Encrypt("test.encrypt", "replacement.key", "test.txt");
	a.decipher("replacement.key", "test.encrypt", "test.encrypt.txt");*/
	/*rearrangement v;
	v.key_generator("my_alphabet.alph", "rearrangement.key");
	v.Encrypt("test_2.encrypt", "rearrangement.key", "test.txt");
	v.decipher("rearrangement.key", "test_2.encrypt", "test_2.encrypt.txt");*/
	gamming r;
	r.key_generator("my_alphabet.alph", "gamming.key");
	r.Encrypt("test_3.encrypt", "gamming.key", "test.txt");
	r.decipher("gamming.key", "test_3.encrypt", "test_3.encrypt.txt");
	return 0;
}