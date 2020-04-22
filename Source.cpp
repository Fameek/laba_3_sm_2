#include "shif.h"

int main() {

		cout << "\tMain menu" << endl;
		cout << "1) Encrypt/Decrypt" << endl;
		cout << "2) Generate key" << endl;
		int i;
		cin >> i; cout << endl;
		if (i == 1) {
			i = 0;
			cout << "\tEncrypt/Decrypt" << endl;
			cout << "1) Encrypt" << endl;
			cout << "2) Decrypt" << endl;
			cin >> i;
			if (i == 1) {
				i = 0;
				cout << "\tChoose type" << endl;
				cout << "1) replacement cipher" << endl;
				cout << "2) permutation cipher " << endl;
				cout << "3) gamma encryption" << endl;
				cin >> i; cout << endl;
				if (i == 1) {
					cout << "\t replacement cipher" << endl;
					replacement a;
					string path_txt;
					string path_save_file;
					string path_key;
					cout << "Enter file path for encryption(.txt) :"; cin >> path_txt; cout << endl;
					cout << "Enter the path to save the file(.encrypt) :"; cin >> path_save_file; cout << endl;
					cout << "Enter key path(.key) :"; cin >> path_key; cout << endl;
					a.Encrypt(path_save_file, path_key, path_txt);
					
					cout << "Finish" << endl;
					
					
				}
				else if (i == 2) {
					cout << "\t permutation cipher" << endl;
					permutation a;
					string path_txt;
					string path_save_file;
					string path_key;
					cout << "Enter file path for encryption(.txt) : "; cin >> path_txt; cout << endl;
					cout << "Enter the path to save the file(.encrypt)  "; cin >> path_save_file; cout << endl;
					cout << "Enter key path(.key) : "; cin >> path_key; cout << endl;
					a.Encrypt(path_save_file, path_key, path_txt);
					fstream ff(path_save_file);
					if (ff.is_open()) {
						cout << "Finish" << endl;
					}
					ff.close();


				}
				else if (i == 3) {
					cout << "\t gamma encryption" << endl;
					gamming a;
					string path_txt;
					string path_save_file;
					string path_key;
					cout << "Enter file path for encryption(.txt) : "; cin >> path_txt; cout << endl;
					cout << "Enter the path to save the file(.encrypt)  "; cin >> path_save_file; cout << endl;
					cout << "Enter key path(.key) : "; cin >> path_key; cout << endl;
					a.Encrypt(path_save_file, path_key, path_txt);
					fstream ff(path_save_file);
					if (ff.is_open()) {
						cout << "Finish" << endl;
					}
					ff.close();



				}


			}
			else if (i == 2) {
				i = 0;
				cout << "\tChoose type" << endl;
				cout << "1) replacement cipher" << endl;
				cout << "2) permutation cipher " << endl;
				cout << "3) gamma encryption" << endl;
				cin >> i; cout << endl;
				if (i == 1) {
					cout << "\t replacement cipher" << endl;
					replacement a;
					string path_encrupt;
					string path_save_file;
					string path_key;
					cout << "Enter the path to the file to decrypt(.encrypt) :"; cin >> path_encrupt; cout << endl;
					cout << "Enter the path to save the file(.txt) :"; cin >> path_save_file; cout << endl;
					cout << "Enter key path(.key) :"; cin >> path_key; cout << endl;
					a.decipher(path_key, path_encrupt, path_save_file);
					fstream ff(path_save_file);
					if (ff.is_open()) {
						cout << "Finish" << endl;
					}
					ff.close();
				}
				else if (i == 2) {
					cout << "\t permutation cipher" << endl;
					permutation a;
					string path_encrupt;
					string path_save_file;
					string path_key;
					cout << "Enter the path to the file to decrypt(.encrypt) :"; cin >> path_encrupt; cout << endl;
					cout << "Enter the path to save the file(.txt) :"; cin >> path_save_file; cout << endl;
					cout << "Enter key path(.key) :"; cin >> path_key; cout << endl;
					a.decipher(path_key, path_encrupt, path_save_file);
					fstream ff(path_save_file);
					if (ff.is_open()) {
						cout << "Finish" << endl;
					}
					ff.close();

				}
				else if (i == 3) {
					cout << "\t gamma encryption" << endl;
					gamming a;
					string path_encrupt;
					string path_save_file;
					string path_key;
					cout << "Enter the path to the file to decrypt(.encrypt) :"; cin >> path_encrupt; cout << endl;
					cout << "Enter the path to save the file(.txt) :"; cin >> path_save_file; cout << endl;
					cout << "Enter key path(.key) :"; cin >> path_key; cout << endl;
					a.decipher(path_key, path_encrupt, path_save_file);
					fstream ff(path_save_file);
					if (ff.is_open()) {
						cout << "Finish" << endl;
					}
					ff.close();



				}

			}

		}
		else if (i == 2) {
			i = 0;
			cout << "\tGenerate key" << endl;
			cout << "1) replacement cipher" << endl;
			cout << "2) permutation cipher " << endl;
			cout << "3) gamma encryption" << endl;
			cin >> i; cout << endl;
			if (i == 1) {
				cout << "\t replacement cipher" << endl;
				replacement a;
				string path_alph;
				string path_save_file;
				cout << "Enter the path to the alphabet(.alph): "; cin >> path_alph; cout << endl;
				cout << "Enter the path to save key file(.key): "; cin >> path_save_file; cout << endl;
				a.key_generator(path_alph, path_save_file);
				fstream ff(path_save_file);
				if (ff.is_open()) {
					cout << "Finish" << endl;
				}
				ff.close();
			}
			else if (i == 2) {
				cout << "\t permutation cipher" << endl;
				permutation a;
				string path_alph;
				string path_save_file;
				cout << "Enter the path to the alphabet(.alph): "; cin >> path_alph; cout << endl;
				cout << "Enter the path to save key file(.key): "; cin >> path_save_file; cout << endl;
				a.key_generator(path_alph, path_save_file);
				fstream ff(path_save_file);
				if (ff.is_open()) {
					cout << "Finish" << endl;
				}
				ff.close();


			}
			else if (i == 3) {
				cout << "\t gamma encryption" << endl;
				gamming a;
				string path_alph;
				string path_save_file;
				cout << "Enter the path to the alphabet(.alph): "; cin >> path_alph; cout << endl;
				cout << "Enter the path to save key file(.key): "; cin >> path_save_file; cout << endl;
				a.key_generator(path_alph, path_save_file);
				fstream ff(path_save_file);
				if (ff.is_open()) {
					cout << "Finish" << endl;
				}
				ff.close();



			}


		}
		





	
	return 0;
}