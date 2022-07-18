#include "student.h"
#include "main.h"
using namespace std;

int main() {
	char option;
	char fileName[256] = {0};
	ifstream inFile;
	Student roster[MAX_STUDENTS + 1] = {0};
	int size = 0;
	int capacity = MAX_STUDENTS;
	
	welcome();
	do {
		option = menu();
		switch (option) {
			case 'Q':
				cout << "[done]" << endl;
				break;
			case 'L':
				cout << "Enter file name up to 30 characters: ";
				cin.getline(fileName, 30, '\n');
				if (!(strcmp(fileName, "roster1.txt") == 0 || strcmp(fileName, "roster2.txt") == 0)) {
					strcat(fileName, ".txt");
				}
				inFile.open(fileName);
				if (!inFile) {
					cout << endl;
					cout << "Error opening file." << endl;
					cout << endl;
					break;
				}
				load(inFile, roster, size, capacity);
				cout << endl;
				cout << "[" << size << " records read from " << fileName << "]" << endl;
				cout << endl;
				inFile.close();
				break;
			case 'D':
				display(roster, size);
				break;
			case 'G':
				gpa(roster, size);
				break;
			case 'P':
				pct(roster, size);
				break;
		}
	} while (option != 'Q'); 
}

void welcome() {
	cout << "Welcome to my class management program!" << endl;
	cout << endl;
}

char menu() {
	char selection[256];

	cout << "Please enter one of the following options:" << endl;
	cout << setw(8) << " ";
	cout << setw(10) << left << "LOAD";
	cout << " - Load roster data from an input file" << endl;
	cout << setw(8) << " ";
	cout << setw(10) << left << "DISPLAY";
	cout << " - Display the current roster data" << endl;
	cout << setw(8) << " ";
	cout << setw(10) << left << "GPA";
	cout << " - Display the average GPA for the roster" << endl;
	cout << setw(8) << " ";
	cout << setw(10) << left << "PCT";
	cout << " - Display the Pass, Fail, and Completion percentages" << endl;
	cout << setw(8) << " ";
	cout << setw(10) << left << "QUIT";
	cout << " - End this program" << endl;
	cout << "Enter option: ";
	cin.getline(selection, 256, '\n');
	for (int i = 0; i < strlen(selection); i++) {
		selection[i] = toupper(selection[i]);
	}
	if (strcmp(selection, "LOAD") == 0) {
		return 'L';
	}
	if (strcmp(selection, "DISPLAY") == 0) {
		return 'D';
	}
	if (strcmp(selection, "GPA") == 0) {
		return 'G';
	}
	if (strcmp(selection, "PCT") == 0) {
		return 'P';
	}
	if (strcmp(selection, "QUIT") == 0) {
		return 'Q';
	}
	// only reaches here if input is invalid
	cout << "Unrecognized option \"" << selection << "\"" << endl;
	return 'z';
}
