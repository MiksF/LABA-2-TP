#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "task2.h"
using namespace std;

//void task2() {
//	// Открываем файл для чтения
//	ifstream inputFile("task2.txt");
//
//	// Проверяем, успешно ли открыт файл
//	if (!inputFile.is_open()) {
//		cerr << "Error opening the file\n";
//	}
//
//	// Считываем строки из файла и выводим те, которые содержат двузначные числа
//	string line;
//	while (getline(inputFile, line)) {
//		istringstream iss(line);
//		string word;
//		bool containsTwoDigitNumber = false;
//
//		while (iss >> word) {
//			try {
//				// Пробуем преобразовать слово в число
//				int number = stoi(word);
//
//				// Проверяем, является ли число двузначным
//				if (number >= 10 && number <= 99) {
//					containsTwoDigitNumber = true;
//					break;  // Найдено двузначное число, выходим из цикла
//				}
//			}
//			catch (invalid_argument&) {
//				// Проигнорировать, если слово не является числом
//			}
//		}
//
//		// Выводим строку, если она содержит двузначное число
//		if (containsTwoDigitNumber) {
//			cout << line << '\n';
//		}
//	}
//
//	// Закрываем файл
//	inputFile.close();
//}


void task2() {
	ifstream fin("task2.txt", ios::in);
	try {
		if (!fin.is_open()) {
			exception error("File didn't open");
			throw error;
		}
		if (fin.peek() == EOF) {
			exception empty("File is empty");
			throw empty;
		}
		// Считываем строки из файла и выводим те, которые содержат двузначные числа
		string line;
		while (getline(fin, line)) {
			istringstream iss(line);
			string word;
			bool containsTwoDigitNumber = false;

			while (iss >> word) {
				try {
					// Пробуем преобразовать слово в число
					int number = stoi(word);

					// Проверяем, является ли число двузначным
					if (number >= 10 && number <= 99) {
						containsTwoDigitNumber = true;
						break;  // Найдено двузначное число, выходим из цикла
					}
				}
				catch (invalid_argument&) {
					// Проигнорировать, если слово не является числом
				}
			}

			// Выводим строку, если она содержит двузначное число
			if (containsTwoDigitNumber) {
				cout << line << '\n';
			}
		}
	}
	catch (exception& error)
	{
		cout << error.what() << endl;
		fin.close();
	}
}