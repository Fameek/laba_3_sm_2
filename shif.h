#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
class cipher {
public:
	virtual void key_generator(string path_alph, string file_name, string path_save_file) = 0;
	virtual void Encrypt(string path_save_file, string path_key, string path_txt) = 0;
	virtual void decipher(string path_key, string path_encrypt, string path_save_file) = 0;
};

class replacement : public cipher { // замена
private:
	bool FileIsExist(string filePath)
	{
		bool isExist = false;
		ifstream fin(filePath.c_str());

		if (fin.is_open())
			isExist = true;

		fin.close();
		return isExist;
	}
public:
	void key_generator(string path_alph, string file_name, string path_save_file) {
		bool trriger = 0;
		if (path_alph.substr(path_alph.find_last_of(".") + 1) != "alph") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (FileIsExist(path_alph)) {
			trriger = 1;
		}


	}



	void Encrypt(string path_save_file, string path_key, string path_txt) {




	}




	void decipher(string path_key, string path_encrypt, string path_save_file) {




	}

};

class rearrangement : public cipher { // перестановка
public:
	void key_generator(string path_alph, string file_name, string path_save_file) {

	}
	void Encrypt(string path_save_file, string path_key, string path_txt) {


	}
	void decipher(string path_key, string path_encrypt, string path_save_file) {

	}
};

class XOR : public cipher { // Гаммирование
public:
	void key_generator(string path_alph, string file_name, string path_save_file) {

	}
	void Encrypt(string path_save_file, string path_key, string path_txt) {


	}
	void decipher(string path_key, string path_encrypt, string path_save_file) {

	}
};

