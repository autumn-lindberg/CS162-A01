#include "student.h"
using namespace std;

Student initStudent() {
	Student newStudent = {};
	memset(newStudent.name, 0, sizeof(newStudent.name));
	memset(newStudent.gnum, 0, sizeof(newStudent.name));
	memset(newStudent.grade, 0, sizeof(newStudent.name));
	return newStudent;
}

void load(ifstream & inFile, Student roster[], int & size, int capacity) {
	size = 0;
	for (int i = 0; i < capacity; i++) {
		roster[i] = initStudent();
	}
	roster[size] = initStudent();
	inFile.getline(roster[size].name, MAX_CHARS, ',');
	inFile.getline(roster[size].gnum, MAX_CHARS, ',');
	inFile.getline(roster[size].grade, MAX_CHARS, '\n');
	while (!inFile.eof() && size < capacity) {
		size++;
		roster[size] = initStudent();
		inFile.getline(roster[size].name, 256, ',');
		inFile.getline(roster[size].gnum, 256, ',');
		inFile.getline(roster[size].grade, 256, '\n');
	}
}

void display(Student roster[], int size) {
	if (size == 0) {
		cout << endl;
		cout << "No rosters loaded." << endl;
		cout << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << setw(10) << left << i + 1;
		cout << setw(25) << left << roster[i].name;
		cout << setw(15) << left << roster[i].gnum;
		cout << setw(3) << left << roster[i].grade << endl;
	}
}

void gpa(Student roster[], int size) {
	double averageGPA = 0;
	double sizeCopy = 1.0 * size;
	for (int i = 0; i < size; i++) {
		if (strcmp(roster[i].grade, "A") == 0) {
			averageGPA += 4;
		}
		if (strcmp(roster[i].grade, "B") == 0) {
			averageGPA += 3;
		}
		if (strcmp(roster[i].grade, "C") == 0) {
			averageGPA += 2;
		}
		if (strcmp(roster[i].grade, "D") == 0) {
			averageGPA += 1;
		}
		if (strcmp(roster[i].grade, "P") == 0) {
			averageGPA += 2;
		}
		if (strcmp(roster[i].grade, "AUD") == 0) {
			sizeCopy--;
		}
	}
	averageGPA = averageGPA / sizeCopy;

	cout << endl;
	cout << setprecision(2) << fixed << "Average GPA for " << static_cast<int>(sizeCopy) << " students: ";
	cout << averageGPA << endl;
	cout << endl;
}

void pct(Student roster[], int size) {
	double completionPercentage = 0;
	double passingPercentage = 0;
	double nonPassingPercentage = 0;
	double auditPercentage = 0;
	int numComplete = 0;
	int numPassing = 0;
	int numNotPassing = 0;
	int numAuditing = 0;

	for (int i = 0; i < size; i++) {
		if (strcmp(roster[i].grade, "I") == 0) {
			numNotPassing += 1;
		}
		if (strcmp(roster[i].grade, "A") == 0) {
			numComplete += 1;
			numPassing += 1;
		}
		if (strcmp(roster[i].grade, "B") == 0) {
			numComplete += 1;
			numPassing += 1;
		}
		if (strcmp(roster[i].grade, "C") == 0) {
			numComplete += 1;
			numPassing += 1;
		}
		if (strcmp(roster[i].grade, "D") == 0) {
			numComplete += 1;
			numNotPassing += 1;
		}
		if (strcmp(roster[i].grade, "F") == 0) {
			numComplete += 1;
			numNotPassing += 1;
		}
		if (strcmp(roster[i].grade, "NP") == 0) {
			numComplete += 1;
			numNotPassing += 1;
		}
		if (strcmp(roster[i].grade, "P") == 0) {
			numComplete += 1;
			numPassing += 1;
		}
		if (strcmp(roster[i].grade, "W") == 0) {
			numNotPassing += 1;
		}
		if (strcmp(roster[i].grade, "AUD") == 0) { 
			numComplete += 1;
			numAuditing += 1;
		}
	}

	completionPercentage = numComplete / size;
	passingPercentage = numPassing / size;
	nonPassingPercentage = numNotPassing / size;
	auditPercentage = numAuditing / size;

	cout << endl; cout << setw(25) << right << "Total Students: "; 
	cout << setw(3) << left << size << "(100.0%)" << endl;
	cout << setw(25) << right << "Total Completions: ";
	cout << setw(3) << left << numComplete;
	cout << "(" << completionPercentage << ")" << endl;
	cout << setw(25) << right << "Passing Grades: ";
	cout << setw(3) << left << numPassing;
	cout << "(" << passingPercentage << ")" << endl;
	cout << setw(25) << right << "Non-Passing Grades: ";
	cout << setw(3) << left << numNotPassing;
	cout << "(" << nonPassingPercentage << ")" << endl;
	cout << setw(25) << right << "AUD Grades: ";
	cout << setw(3) << left << numAuditing;
	cout << "(" << auditPercentage << ")" << endl;
	cout << endl;
}
