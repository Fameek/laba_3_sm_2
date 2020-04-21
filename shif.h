#include <iostream>
#include <fstream>
#include <ctime>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
class cipher {
public:
	virtual void key_generator(string path_alph, string path_save_file) = 0;
	virtual void Encrypt(string path_save_file, string path_key, string path_txt) = 0;
	virtual void decipher(string path_key, string path_encrypt, string path_save_file) = 0;
};

class replacement : public cipher { // замена
private:
	bool FileIsExist(string filePath)
	{
		bool isExist = false;
		ifstream fin(filePath);

		if (fin.is_open()) {

		}
		else {
			isExist = true;
		}

		fin.close();
		return isExist;
	}
	int black_list_check(string bl, int chack, string alph) {
		bool trriger_bl = 0;
		bool trriger_al = 0;
		for (int i = 0; i < bl.size(); i++) {
			if (bl[i] == chack) {
				trriger_bl = 1;
				break;
			}
		}
		for (int i = 0; i < alph.size(); i++) {
			if (alph[i] == chack) {
				trriger_al = 1;
				break;
			}
		}

		
		if (trriger_al == 1) {
			if (trriger_bl == 0) {
				return chack;

			}
			else if (trriger_bl == 1) {
				int back_or_front = rand() % 2;
				if (back_or_front == 0) {
					for (int i = 0; i < alph.size(); i++) {
						bool trriger_win = 0;
						for (int j = 0; j < bl.size(); j++) {
							if (bl[j] == alph[i]) {
								trriger_win = 1;
								break;
							}
						}

						if (trriger_win == 0) {
							int res = alph[i];
							return res;
						}

					}
				}
				if (back_or_front == 1) {
					for (int i = alph.size() - 1; i >= 0; i--) {
						bool trriger_win = 0;
						for (int j = 0; j < bl.size(); j++) {
							if (bl[j] == alph[i]) {
								trriger_win = 1;
								break;
							}
						}

						if (trriger_win == 0) {
							int res = alph[i];
							return res;
						}

					}
				}
			}
		}
		else if (trriger_al == 0) {
			int back_or_front = rand() % 2;
			if (back_or_front == 0) {
				for (int i = 0; i < alph.size(); i++) {
					bool trriger_win = 0;
					for (int j = 0; j < bl.size(); j++) {
						if (bl[j] == alph[i]) {
							trriger_win = 1;
							break;
						}
					}

					if (trriger_win == 0) {
						int res = alph[i];
						return res;
					}

				}
			}
			if (back_or_front == 1) {
				for (int i = alph.size() - 1; i >= 0; i--) {
					bool trriger_win = 0;
					for (int j = 0; j < bl.size(); j++) {
						if (bl[j] == alph[i]) {
							trriger_win = 1;
							break;
						}
					}

					if (trriger_win == 0) {
						int res = alph[i];
						return res;
					}

				}
			}
		}
			
			//for (int i = 32; i < 127; i++) {
			//	trriger = 1;
			//	for (int j = 0; j < bl.size(); j++) {
			//		if (bl[j] == i) {
			//			trriger = 0;
			//			break;
			//		}
			//	}
			//	if (trriger == 1) {
			//		return i;
			//	}

			//}

		
		
		
		
		
		/*int result;
		for (int i = 32; i < 127;i++) {
			if (bl.find(i)) {

			}
			else {
				result = i;
			}
		}

		return result;*/
	}
public:
	void key_generator(string path_alph,string path_save_file) {
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
		if (trriger == 0) {
			ifstream alph_file(path_alph);
			json alph;
			alph_file >> alph;
			alph_file.close();
			auto array_alph = alph.find("alp");			
			if (array_alph != alph.end()) { // если файл правильный
				json key = { {"alg_type", "replacement"},{"key",{}} };
				//key.at("key").push_back(json::array({ "w","f" }));
				//key.at("key").push_back("ds");
				//
				//cout << key;
				string alph_data_str;
				json alph_data = alph.at("alp");
				
				json::iterator it = alph_data.begin();
				for (int i = 0; i < alph.at("alp").size(); i++) { // запись данных библиотеки в стринг
					string tt = *it;
					alph_data_str.push_back(tt[0]);
					it++;	
				}
				string key_data;
				string black_list = "";
				srand(time(0));
				for (int i = 0; i < alph_data_str.size(); i++) {
					int key_int = rand() % 10;
					int minus = key_int % 2;
					if (minus == 0) {
						int chek = alph_data_str[i] - key_int;
						int res = black_list_check(black_list, chek, alph_data_str);
						key_data.push_back(res);
						black_list.push_back(res);
					
					}
					else {
						int chek = alph_data_str[i] + key_int;
						int res = black_list_check(black_list, chek, alph_data_str);
						key_data.push_back(res);
						black_list.push_back(res);
						

					}
				}
				
				for (int i = 0; i < alph_data_str.size(); i++) {
					string aa;
					string ee;
					aa.push_back(alph_data_str[i]);
					ee.push_back(key_data[i]);
					key.at("key").push_back(json::array({ aa,ee }));
				}
				ofstream key_file(path_save_file);
				key_file << key;
				key_file.close();
			}
			else {
				cout << "alph is not correct!" << endl;
			}
		}
		else {
			cout << "ERROR" << endl;
		}
	}



	void Encrypt(string path_save_file, string path_key, string path_txt) {




	}




	void decipher(string path_key, string path_encrypt, string path_save_file) {




	}

};

class rearrangement : public cipher { // перестановка
public:
	void key_generator(string path_alph, string path_save_file) {

	}
	void Encrypt(string path_save_file, string path_key, string path_txt) {


	}
	void decipher(string path_key, string path_encrypt, string path_save_file) {

	}
};

class XOR : public cipher { // Гаммирование
public:
	void key_generator(string path_alph, string path_save_file) {

	}
	void Encrypt(string path_save_file, string path_key, string path_txt) {


	}
	void decipher(string path_key, string path_encrypt, string path_save_file) {

	}
};

