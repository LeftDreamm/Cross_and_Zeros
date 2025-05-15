// Крестики_нолики.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char check_win(char mas[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (mas[i][0] == mas[i][1] && mas[i][1] == mas[i][2] && mas[i][0] != ' ')
			return mas[i][0];
		if (mas[0][i] == mas[1][i] && mas[1][i] == mas[2][i] && mas[0][i] != ' ')
			return mas[0][i];
	}
	if (mas[0][0] == mas[1][1] && mas[1][1] == mas[2][2] && mas[0][0] != ' ')
		return mas[0][0];
	if (mas[0][2] == mas[1][1] && mas[1][1] == mas[2][0] && mas[0][2] != ' ')
		return mas[0][2];

	return ' ';
}

bool is_draw(char mas[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mas[i][j] == ' ')
				return false;
		}
	}
	return true;
}

void print(char mas[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mas[i][j];
			if (j < 2) cout << "|";
		}
		cout << endl;
		if (i < 2) cout << "-+-+-" << endl;
	}
}

void enter(char mas[3][3], char symbol) {
	int x, y;
	while (true) {
		cout << "Введите ряд (1-3): ";
		cin >> x;
		cout << "Введите колонну (1-3): ";
		cin >> y;
		x -= 1;
		y -= 1;
		if (x >= 0 && x < 3 && y >= 0 && y < 3) {
			if (mas[x][y] == ' ') {
				mas[x][y] = symbol;
				break;
			}
			else {
				cout << "Клетка занята. Введите другую." << endl;
			}
		}
		else {
			cout << "Неправильные координаты. Попробуйте снова." << endl;
		}
	}
}

void bot_turn(char mas[3][3], char symbol) {
	char bot_symbol = (symbol == 'O') ? 'X' : 'O';
	int rand_x, rand_y;
	bool flag = false;

	while (!flag) {
		rand_x = rand() % 3;
		rand_y = rand() % 3;
		if (mas[rand_x][rand_y] == ' ') {
			mas[rand_x][rand_y] = bot_symbol;
			flag = true;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand((time(nullptr)));
	int flag;
	char symbol;
	char mas[3][3] = 
	{ 
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '} 
	};

	cout << "Крестики (1) нолики (0): ";
	cin >> flag;
	if (flag == 1) symbol = 'X';
	else symbol = 'O';

	while (true) {

		print(mas);
		enter(mas, symbol);
		char winner = check_win(mas);
		if (winner != ' ') {
			print(mas);
			cout << "Победил: " << winner << endl;
			break;
		}
		if (is_draw(mas)) {
			print(mas);
			cout << "Ничья" << endl;
			break;
		}

		bot_turn(mas, symbol);
		winner = check_win(mas);
		if (winner != ' ') {
			print(mas);
			cout << "Победил : " << winner << endl;
			break;
		}
		if (is_draw(mas)) {
			print(mas);
			cout << "Ничья" << endl;
			break;
		}
	}
	return 0;
}

