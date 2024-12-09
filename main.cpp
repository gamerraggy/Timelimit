#include<iostream>
#include<chrono>
using namespace std;

int main() {
	const int TIME_LIMIT = 60; //time limit in seconds
	auto start = chrono::steady_clock::now(); // record start time
	int timeLeft = 60;
	int room = 1;
	char input;

	while (timeLeft >= 0) {
		//check time
		auto now = chrono::steady_clock::now();
		timeLeft = TIME_LIMIT - chrono::duration_cast<chrono::seconds>(now - start).count();
		cout << "Time left: " << timeLeft << " seconds\n"; //show remaining time

		switch (room) {
		case 1:
			cout << "you are in room 1 you can go (N)orth\n";
			cin >> input;
			if (input == 'N' || input == 'n') room = 2;
			break;
		case 2:
			cout << "you are in room 2 you can go (S)outh\n";
			cin >> input;
			if (input == 'S' || input == 's') room = 1;
			break;

		}
	}
}
