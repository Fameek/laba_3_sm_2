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
				/*string dd;
				cout << "Show key(Y/N)"; cin >> dd;
				if (dd[0] == 'Y' || dd[0] == 'y') {
					cout << "key: " << key_data << endl;
				}*/
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
		bool trriger = 0;
		if (path_key.substr(path_key.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (path_txt.substr(path_txt.find_last_of(".") + 1) != "txt") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "encrypt") {
			trriger = 1;
		}
		if (FileIsExist(path_key)) {
			trriger = 1;
		}
		if (FileIsExist(path_txt)) {
			trriger = 1;
		}
		if (trriger == 0) {
			json key;
			ifstream key_file(path_key);
			key_file >> key;
			key_file.close();
			
			auto type = key.find("alg_type");
			if (type.value() == "replacement") {
				ifstream txt_file(path_txt);
				if (txt_file.peek() != EOF)  // если первый символ не конец файла
				{
					int key_size = key.at("key").size();
					ofstream encrypt_file(path_save_file);
					while (txt_file) {
						string txt_str;
						getline(txt_file, txt_str);
						for (int i = 0; i < txt_str.size(); i++) {
							string simvol;
							simvol.push_back(txt_str[i]);
							for (int j = 0; j < key_size; j++) {								
								if(simvol==key.at("key").at(j).at(0)){
									string simvol_1;
									simvol_1 = key.at("key").at(j).at(1);
									txt_str[i] = simvol_1[0];
									break;
								}

							}
						}
						encrypt_file << txt_str;
						encrypt_file << "\n";
					}
					encrypt_file.close();

				}
				else {
					cout << "txt empty" << endl;
				}
				txt_file.close();
			}
			else {
				cout << "not correct type" << endl;
			}

		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}


	}

	void decipher(string path_key, string path_encrypt, string path_save_file) {
		bool trriger = 0;
		if (path_key.substr(path_key.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "txt") {
			trriger = 1;
		}
		if (path_encrypt.substr(path_encrypt.find_last_of(".") + 1) != "encrypt") {
			trriger = 1;
		}
		if (FileIsExist(path_key)) {
			trriger = 1;
		}
		if (FileIsExist(path_encrypt)) {
			trriger = 1;
		}
		if (trriger == 0) {
			json key;
			ifstream key_file(path_key);
			key_file >> key;
			key_file.close();

			auto type = key.find("alg_type");
			if (type.value() == "replacement") {
				ifstream encrypt_file(path_encrypt);
				if (encrypt_file.peek() != EOF)  // если первый символ не конец файла
				{
					int key_size = key.at("key").size();
					ofstream txt_file(path_save_file);
					while (encrypt_file) {
						string encrypt_str;
						getline(encrypt_file, encrypt_str);
						for (int i = 0; i < encrypt_str.size(); i++) {
							string simvol;
							simvol.push_back(encrypt_str[i]);
							for (int j = 0; j < key_size; j++) {
								if (simvol == key.at("key").at(j).at(1)) {
									string simvol_1;
									simvol_1 = key.at("key").at(j).at(0);
									encrypt_str[i] = simvol_1[0];
									break;
								}

							}
						}
						txt_file << encrypt_str;
						txt_file << "\n";
					}
					txt_file.close();
				}
				else {
					cout << "encrypt empty" << endl;
				}
				encrypt_file.close();
			}
			else {
				cout << "not correct type" << endl;
			}







		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}

	}

};

class permutation : public cipher { // перестановка
private:
	int blak_list_f(string BB, int key_sm, string alph, int val) {
		int minus = key_sm % 2;
		char test;
		int key_sm_2 = 0 - key_sm;
		if (minus == 0) {
			test = alph[val] + key_sm;
		}
		else {
			
			
			test = alph[val] + key_sm_2;
		}
		bool bb_trriger = 0;
		bool alph_trriger = 0;
		for (int i = 0; i < alph.size(); i++) {
			if (test == alph[i]) {
				alph_trriger = 1;
			}
		}
		for (int i = 0; i < BB.size(); i++) {
			if (test == BB[i]) {
				bb_trriger = 1;
			}
		}
		
		if (bb_trriger == 0 && alph_trriger == 1) {
			if (minus == 0) {
				return key_sm;
			}
			else {
				return key_sm_2;
			}
		}
		else {
			test = 126;
			for (int i = 0; i < 40; i++) {
				bb_trriger = 0;
				int rr = rand() % alph.size();
				for (int j = 0; j < BB.size(); j++) {
					if (BB[j] == alph[rr]) {
						bb_trriger = 1;
						break;
					}
				}
				if (bb_trriger == 0) {
					test = alph[rr];
					break;
				}
			}
			if (test == 126) {
				for (int i = 0; i < alph.size(); i++) {
					bb_trriger = 0;
					for (int j = 0; j < BB.size(); j++) {
						if (alph[i] == BB[j]) {
							bb_trriger = 1;
							break;
						}
					}
					if (bb_trriger == 0) {
						test = alph[i];
						break;
					}

				}


			}
			
				int test_int = test;
				int alph_int = alph[val];
				int val_1 = alph_int - test_int;
				
				/*if (val_1 >= 0) {
					*/
					val_1 = 0-val_1;

					return val_1;
				/*}
				else {
					return val_1;
				}*/
			



		}






	}
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
public:
	void key_generator(string path_alph, string path_save_file) {
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
				json key = { {"alg_type", "rearrangement"},{"key",{}} };
				string alph_data_str;
				json alph_data = alph.at("alp");

				json::iterator it = alph_data.begin();
				for (int i = 0; i < alph.at("alp").size(); i++) { // запись данных библиотеки в стринг
					string tt = *it;
					alph_data_str.push_back(tt[0]);
					it++;
				}
				int* key_data = new int[alph_data_str.size()];				
				srand(time(0));
				string black_list;
				for (int i = 0; i < alph_data_str.size(); i++) {
					int key_int = rand() % 5 + 1;
					int cha = blak_list_f(black_list, key_int, alph_data_str, i);
					key_data[i] = cha;
					black_list.push_back(alph_data_str[i] + cha);
					//int minus = key_int % 2;
					//if (minus == 0) {
					//	
					//	int cha = blak_list_f(black_list, key_int, alph_data_str,i);


					//	//int cha = alph_data_str[i] + key_int;
					//	//if (cha > 126) {
					//	//	key_data[i] = -key_int;
					//	//}
					//	//else {
					//	//	key_data[i] = key_int;
					//	//}



					//}
					//else {



					//	//int cha = alph_data_str[i] - key_int;
					//	//if (cha < 32) {
					//	//	key_data[i] = key_int;
					//	//}
					//	//else {
					//	//	key_data[i] = -key_int;
					//	//}




					//}
				}
				/*string dd;
				cout << "Show key(Y/N)"; cin >> dd;
				if (dd[0] == 'Y' || dd[0] == 'y') {
					cout << "key: " << key_data << endl;
				}*/
				for (int i = 0; i < alph_data_str.size(); i++) {
					string aa;
					int ee;
					aa.push_back(alph_data_str[i]);
					ee = key_data[i];
					key.at("key").push_back(json::array({ aa,ee }));
				}
				ofstream key_file(path_save_file);
				key_file << key;
				key_file.close();
				delete [] key_data;






			}
			else {
				cout << "alph is not correct!" << endl;
			}

		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}
	}
	void Encrypt(string path_save_file, string path_key, string path_txt) {
		bool trriger = 0;
		if (path_key.substr(path_key.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (path_txt.substr(path_txt.find_last_of(".") + 1) != "txt") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "encrypt") {
			trriger = 1;
		}
		if (FileIsExist(path_key)) {
			trriger = 1;
		}
		if (FileIsExist(path_txt)) {
			trriger = 1;
		}
		if (trriger == 0) {
			json key;
			ifstream key_file(path_key);
			key_file >> key;
			key_file.close();

			auto type = key.find("alg_type");
			if (type.value() == "rearrangement") {
				ifstream txt_file(path_txt);
				if (txt_file.peek() != EOF)  // если первый символ не конец файла
				{
					int key_size = key.at("key").size();
					ofstream encrypt_file(path_save_file);
					while (txt_file) {
						string txt_str;
						getline(txt_file, txt_str);
						for (int i = 0; i < txt_str.size(); i++) {
							string simvol;
							simvol.push_back(txt_str[i]);
							for (int j = 0; j < key_size; j++) {
								if (simvol == key.at("key").at(j).at(0)) {
									int simvol_1;
									simvol_1 = key.at("key").at(j).at(1);
									txt_str[i] = txt_str[i] + simvol_1;
									break;
								}

							}
						}
						encrypt_file << txt_str;
						encrypt_file << "\n";
					}
					encrypt_file.close();

				}
				else {
					cout << "txt empty" << endl;
				}
				txt_file.close();
			}
			else {
				cout << "not correct type" << endl;
			}

		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}

	}
	void decipher(string path_key, string path_encrypt, string path_save_file) {
		bool trriger = 0;
		if (path_key.substr(path_key.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "txt") {
			trriger = 1;
		}
		if (path_encrypt.substr(path_encrypt.find_last_of(".") + 1) != "encrypt") {
			trriger = 1;
		}
		if (FileIsExist(path_key)) {
			trriger = 1;
		}
		if (FileIsExist(path_encrypt)) {
			trriger = 1;
		}
		if (trriger == 0) {
			json key;
			ifstream key_file(path_key);
			key_file >> key;
			key_file.close();

			auto type = key.find("alg_type");
			if (type.value() == "rearrangement") {
				ifstream encrypt_file(path_encrypt);
				if (encrypt_file.peek() != EOF)  // если первый символ не конец файла
				{
					int key_size = key.at("key").size();
					ofstream txt_file(path_save_file);
					while (encrypt_file) {
						string encrypt_str;
						getline(encrypt_file, encrypt_str);
						for (int i = 0; i < encrypt_str.size(); i++) {
							string simvol;
							simvol.push_back(encrypt_str[i]);
							for (int j = 0; j < key_size; j++) {
								string key_sm = key.at("key").at(j).at(0);
								int key_sdvig = key.at("key").at(j).at(1);

								if (simvol[0] == key_sm[0]+key_sdvig) {
									int simvol_1;
									simvol_1 = key.at("key").at(j).at(1);
									encrypt_str[i] = encrypt_str[i]-simvol_1;
									break;
								}

							}
						}
						txt_file << encrypt_str;
						txt_file << "\n";
					}
					txt_file.close();
				}
				else {
					cout << "encrypt empty" << endl;
				}
				encrypt_file.close();
			}
			else {
				cout << "not correct type" << endl;
			}

		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}

	}
};

class gamming : public cipher { // Гаммирование
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

		
	}
public:
	void key_generator(string path_alph, string path_save_file) {
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
				json key = { {"alg_type", "gamming"},{"key",{}} };
				
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
				/*string dd;
				cout << "Show key(Y/N)"; cin >> dd;
				if (dd[0] == 'Y' || dd[0] == 'y') {
					cout << "key: " << key_data << endl;
				}*/
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
		bool trriger = 0;
		if (path_key.substr(path_key.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (path_txt.substr(path_txt.find_last_of(".") + 1) != "txt") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "encrypt") {
			trriger = 1;
		}
		if (FileIsExist(path_key)) {
			trriger = 1;
		}
		if (FileIsExist(path_txt)) {
			trriger = 1;
		}
		if (trriger == 0) {
			json key;
			ifstream key_file(path_key);
			key_file >> key;
			key_file.close();

			auto type = key.find("alg_type");
			if (type.value() == "gamming") {
				ifstream txt_file(path_txt);
				if (txt_file.peek() != EOF)  // если первый символ не конец файла
				{
					int key_size = key.at("key").size();
					ofstream encrypt_file(path_save_file);
					while (txt_file) {
						string txt_str;
						getline(txt_file, txt_str);
						for (int i = 0; i < txt_str.size(); i++) {																			
							bool txt_trriger = 0;
							string simvol;
							simvol.push_back(txt_str[i]);
							int where_txt_simvol;

							for (int j = 0; j < key_size; j++) {
								if (simvol == key.at("key").at(j).at(0)) {
									where_txt_simvol = j;
									txt_trriger = 1;
									break;
								}
							}
							if (txt_trriger == 1) {
								/*string simvol_key = key.at("key").at(where_txt_simvol).at(1);
								int where_key_simvol;
								for (int j = 0; j < key_size; j++) {
									if (simvol_key == key.at("key").at(j).at(0)) {
										where_key_simvol = j;
										break;
									}
								}*/
								int where_key_simvol;

								if (i >= key_size) {
									int i_2 = i % key_size;
									string simvol_key = key.at("key").at(i_2).at(1);
									
									for (int j = 0; j < key_size; j++) {
										if (simvol_key == key.at("key").at(j).at(0)) {
											where_key_simvol = j;
											break;
										}
									}
								}
								else {
									string simvol_key = key.at("key").at(i).at(1);
									
									for (int j = 0; j < key_size; j++) {
										if (simvol_key == key.at("key").at(j).at(0)) {
											where_key_simvol = j;
											break;
										}
									}
								}
								int sum = where_key_simvol + where_txt_simvol;
								int where_res = sum % key_size;
								string res = key.at("key").at(where_res).at(0);
								txt_str[i] = res[0];

							}
						}








						encrypt_file << txt_str;
						encrypt_file << "\n";
					}

					encrypt_file.close();

				}
				else {
					cout << "txt empty" << endl;
				}
				txt_file.close();
			}
			else {
				cout << "not correct type" << endl;
			}

		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}




	}
	void decipher(string path_key, string path_encrypt, string path_save_file) {

		bool trriger = 0;
		if (path_key.substr(path_key.find_last_of(".") + 1) != "key") {
			trriger = 1;
		}
		if (path_save_file.substr(path_save_file.find_last_of(".") + 1) != "txt") {
			trriger = 1;
		}
		if (path_encrypt.substr(path_encrypt.find_last_of(".") + 1) != "encrypt") {
			trriger = 1;
		}
		if (FileIsExist(path_key)) {
			trriger = 1;
		}
		if (FileIsExist(path_encrypt)) {
			trriger = 1;
		}
		if (trriger == 0) {
			json key;
			ifstream key_file(path_key);
			key_file >> key;
			key_file.close();

			auto type = key.find("alg_type");
			if (type.value() == "gamming") {
				ifstream encrypt_file(path_encrypt);
				if (encrypt_file.peek() != EOF)  // если первый символ не конец файла
				{
					int key_size = key.at("key").size();
					ofstream txt_file(path_save_file);
					while (encrypt_file) {
						string encrypt_str;
						getline(encrypt_file, encrypt_str);
						for (int i = 0; i < encrypt_str.size(); i++) {
							
								bool encrypt_trriger = 0;
								string simvol;
								simvol.push_back(encrypt_str[i]);
								int where_encrypt_simvol;

								for (int j = 0; j < key_size; j++) {
									if (simvol == key.at("key").at(j).at(0)) {
										where_encrypt_simvol = j;
										encrypt_trriger = 1;
										break;
									}
								}
								if (encrypt_trriger == 1) {
									/*string simvol_key = key.at("key").at(where_txt_simvol).at(1);
									int where_key_simvol;
									for (int j = 0; j < key_size; j++) {
										if (simvol_key == key.at("key").at(j).at(0)) {
											where_key_simvol = j;
											break;
										}
									}*/
									int where_key_simvol;

									if (i >= key_size) {
										int i_2 = i % key_size;
										string simvol_key = key.at("key").at(i_2).at(1);

										for (int j = 0; j < key_size; j++) {
											if (simvol_key == key.at("key").at(j).at(0)) {
												where_key_simvol = j;
												break;
											}
										}
									}
									else {
										string simvol_key = key.at("key").at(i).at(1);

										for (int j = 0; j < key_size; j++) {
											if (simvol_key == key.at("key").at(j).at(0)) {
												where_key_simvol = j;
												break;
											}
										}
									}


									int sum = where_encrypt_simvol + key_size - where_key_simvol;
									int where_res = sum % key_size;
									string res = key.at("key").at(where_res).at(0);
									encrypt_str[i] = res[0];

								}
							





						}
						txt_file << encrypt_str;
						txt_file << "\n";
					}
					txt_file.close();
				}
				else {
					cout << "encrypt empty" << endl;
				}
				encrypt_file.close();
			}
			else {
				cout << "not correct type" << endl;
			}







		}
		else {
			cout << "not correct file extension or file is not found" << endl;
		}







	}
};

