//////////////////////////////////////////////////////////////////////////////
// Name:        Autumn Valls
// Assignment:  Assignment 2 - Classes
// Date:        7/27/2022
// Description: A menu driven roster program that is an extension of
//              assignment 1. "Add", "Remove", and "grade" have been added.
// Sources:     None
//////////////////////////////////////////////////////////////////////////////
#include "main.h"

using namespace std;

int main() {

	char option;
	ifstream inFile;
	Student roster[MAX_STUDENTS];
	int size = 0;
	int capacity = MAX_STUDENTS;
	int namesSize = 0;
	int assignmentsSize = 0;
	
	welcome();

	do {

		option = menu();

		switch (option) {
			case 'Q':
				cout << "[done]" << endl;
				break;

			case 'L':
				openFile(inFile, "G-Number");
				loadGnums(inFile, roster, size, capacity);
				cout << endl;
				cout << "[" << size << " G-Numbers loaded]" << endl;
				cout << endl;
				inFile.close();

				openFile(inFile, "names");
				namesSize = loadNames(inFile, roster, size);
				cout << endl;
				cout << "[" << namesSize << " names added to roster]" << endl;
				cout << endl;
				inFile.close();

				openFile(inFile, "assignment");
				assignmentsSize = loadAssignments(inFile, roster, size);
				cout << endl;
				cout << "[" << assignmentsSize << " assignments added]" << endl;
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

			case 'C':
				calculateGrade(roster, size);
				break;

			case 'R':
				remove(roster, size);
				break;

			case 'A':
				add(roster, size, capacity);
				break;
		}

	} while (option != 'Q'); 

}

void welcome() {

	cout << "Welcome to my class management program!" << endl;
	cout << endl;

}

// displays a menu and returns a char for the appropriate option
char menu() {

	char selection[256];

	cout << "Please enter one of the following options:" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "LOAD";
	cout << " - Load roster data from an input file" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "DISPLAY";
	cout << " - Display the current roster data" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "GPA";
	cout << " - Display the average GPA for the roster" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "GRADE";
	cout << " - Display grade information for one student" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "PCT";
	cout << " - Display the Pass, Fail, and Completion percentages" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "REMOVE";
	cout << " - Remove item from a list" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "ADD";
	cout << " - Add item to a list" << endl;
	cout.width(8);
	cout << " ";
	cout.width(10);
	cout << left << "QUIT";
	cout << " - End this program" << endl;
	cout << "Enter option: ";
	cin.getline(selection, MAX_CHARS, '\n');

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
	if (strcmp(selection, "GRADE") == 0) {
		// c for calculate?
		return 'C';
	}
	if (strcmp(selection, "REMOVE") == 0) {
		return 'R';
	}
	if (strcmp(selection, "ADD") == 0) {
		return 'A';
	}

	// only reaches here if input is invalid
	cout << "Unrecognized option \"" << selection << "\"" << endl;
	return 'z';

}

// Opens a text file using ifstream
void openFile(ifstream & inFile, char nameParam[]) {

	char fileName[MAX_CHARS];

	cout << "Enter file name of student " << nameParam << " file up to 30 characters: ";
	cin.getline(fileName, 30, '\n');
	inFile.open(fileName);
	
	if (!inFile) {
		cout << endl;
		cout << "Error opening file." << endl;
		cout << endl;
	}

}

// loads the gnums from gnums.txt
void loadGnums(ifstream & inFile, Student roster[], int & size, int capacity) {
	
	char myGnum[MAX_CHARS + 1];

	inFile.getline(myGnum, MAX_CHARS, '\n');
	roster[size].setGnum(myGnum);
	while(!inFile.eof() && size < capacity) {
		size++;
		inFile.getline(myGnum, MAX_CHARS, '\n');
		roster[size].setGnum(myGnum);
	}

}

// loads the names from names.txt
int loadNames(ifstream & inFile, Student roster[], int size) {
	
	char myName[MAX_CHARS + 1];
	char myGnum[MAX_CHARS + 1];
	char gottenGnum[MAX_CHARS + 1];
	int namesSize = 0;

	inFile.getline(myName, MAX_CHARS, ',');
	inFile.getline(myGnum, MAX_CHARS, '\n');
	for (int i = 0; i < size; i++) {
		roster[i].getGnum(gottenGnum);
		if (strcmp(gottenGnum, myGnum) == 0) {
			roster[i].setName(myName);
		}
	}
	while(!inFile.eof()) {
		namesSize++;
		inFile.getline(myName, MAX_CHARS, ',');
		inFile.getline(myGnum, MAX_CHARS, '\n');
		for (int i = 0; i < size; i++) {
			roster[i].getGnum(gottenGnum);
			if (strcmp(gottenGnum, myGnum) == 0) {
				roster[i].setName(myName);
			}
		}
	}
	return namesSize;

}

// loads the assignments from assignments.txt
int loadAssignments(ifstream & inFile, Student roster[], int size) {

	char myGnum[MAX_CHARS + 1];
	char assignmentName[MAX_CHARS + 1];
	char gottenGnum[MAX_CHARS + 1];
	int myGrade;
	float myWeight;
	int assignmentsSize = 0;

	inFile.getline(myGnum, MAX_CHARS, ',');
	inFile.getline(assignmentName, MAX_CHARS, ',');
	inFile >> myGrade;
	inFile.ignore(1, ',');
	inFile >> myWeight;
	inFile.ignore(1, '\n');
	for (int i = 0; i < size; i++) {
		roster[i].getGnum(gottenGnum);
		if (strcmp(gottenGnum, myGnum) == 0) {
			Assignment a = Assignment(assignmentName, myGrade, myWeight);
			roster[i].addSubmission(a);
		}
	}
	while (!inFile.eof()) {
		assignmentsSize++;
		inFile.getline(myGnum, MAX_CHARS, ',');
		inFile.getline(assignmentName, MAX_CHARS, ',');
		inFile >> myGrade;
		inFile.ignore(1, ',');
		inFile >> myWeight;
		inFile.ignore(1, '\n');
		for (int i = 0; i < size; i++) {
			roster[i].getGnum(gottenGnum);
			if (strcmp(gottenGnum, myGnum) == 0) {
				Assignment a = Assignment(assignmentName, myGrade, myWeight);
				roster[i].addSubmission(a);
			}
		}
		
	}
	return assignmentsSize;
}

// displays all data from all students in current roster
void display(Student roster[], int size) {

	char gottenGnum[MAX_CHARS + 1];
	char gottenName[MAX_CHARS + 1];
	
  if (size == 0) {
    cout << endl;
    cout << "No rosters loaded." << endl;
    cout << endl;
    return;
  }

  for (int i = 0; i < size; i++) {
		roster[i].getGnum(gottenGnum);
		roster[i].getName(gottenName);
		cout << i + 1 << ". " << gottenGnum << " " << gottenName;
		cout << " Final Grade: ";
		if (roster[i].getGrade() < 1) {
			cout << "F" << endl;
		}
		else if (roster[i].getGrade() < 2) {
			cout << "D" << endl;
		}
		else if (roster[i].getGrade() < 3) {
			cout << "C" << endl;
		}
		else if (roster[i].getGrade() < 4) {
			cout << "B" << endl;
		}
		else {
			cout << "A" << endl;
		}
		roster[i].displayAssignments();
  }

}

// caluclates and displays the average gpa for all students in the current roster
void gpa(Student roster[], int size) {

  double averageGPA = 0.0;

  for (int i = 0; i < size; i++) {
		averageGPA += roster[i].getGrade();
  }
	averageGPA /= size;

  cout << endl;
	cout.precision(2);
  cout << fixed << "Average GPA for " << size << " students: ";
  cout << averageGPA << endl;
  cout << endl;

}

// calculates and displays the pass, completion, and fail percentages
// for all students in the current roster
void pct(Student roster[], int size) {

  float numComplete = 0.0;
  float numPassing = 0.0;
  float numNotPassing = 0.0;
  float numAuditing = 0.0;

  for (int i = 0; i < size; i++) {
    if (roster[i].getGrade() == 4) {
      numComplete += 1;
      numPassing += 1;
    }
    if (roster[i].getGrade() == 3) {
      numComplete += 1;
      numPassing += 1;
    }
    if (roster[i].getGrade() == 2) {
      numComplete += 1;
      numPassing += 1;
    }
    if (roster[i].getGrade() == 1) {
      numComplete += 1;
      numNotPassing += 1;
    }
    if (roster[i].getGrade() == 0) {
      numComplete += 1;
      numNotPassing += 1;
    }
  }

  cout << endl; 
	cout.width(25);
	cout << right << "Total Students: ";
	cout.width(3);
  cout << left << size << "(100.0%)" << endl;
	cout.width(25);
	cout << right << "Total Completions: ";
	cout.width(3);
  cout << left << numComplete;
	cout.precision(4);
  cout << "(" << numComplete / size * 100 << "%)" << endl;
	cout.width(25);
  cout << right << "Passing Grades: ";
	cout.width(3);
  cout << left << numPassing;
  cout << "(" << numPassing / size * 100 << "%)" << endl;
	cout.width(250);
  cout << right << "Non-Passing Grades: ";
	cout.width(3);
  cout << left << numNotPassing;
  cout << "(" << numNotPassing / size * 100 << "%)" << endl;
	cout.width(25);
  cout << right << "AUD Grades: ";
	cout.width(3);
  cout << left << numAuditing;
  cout << "(" << numAuditing / size * 100 << "%)" << endl;
  cout << endl;
}

// calculates and displays the grade for a single student in the current roster
void calculateGrade(Student roster[], int size) {

	char option[MAX_CHARS + 1]; 
	char gottenGnum[MAX_CHARS + 1];
	char gottenName[MAX_CHARS + 1];
	bool found = false;

	cout << "Enter Student Name of Student G-Number: ";
	cin.getline(option, MAX_CHARS, '\n');
	for (int i = 0; i < size; i++) {
		roster[i].getGnum(gottenGnum);
		roster[i].getName(gottenName);
		if (strcmp(gottenName, option) == 0 || strcmp(gottenGnum, option) == 0) {
			found = true;
			cout << gottenGnum << " ";
			cout << gottenName << " Grade: ";
			if (roster[i].getGrade() < 1) {
				cout << "F" << endl;
			}
			else if (roster[i].getGrade() < 2) {
				cout << "D" << endl;
			}
			else if (roster[i].getGrade() < 3) {
				cout << "C" << endl;
			}
			else if (roster[i].getGrade() < 4) {
				cout << "B" << endl;
			}
			else {
				cout << "A" << endl;
			}
			roster[i].displayGrades();
		}
	}
	if (found == false) {
		cout << option << " not found!" << endl;
	}
}

// removes a student or assignment of a given student from the current roster
void remove(Student roster[], int & size) {

	char option[MAX_CHARS + 1];
	char optionChar= 'f';
	char studentName[MAX_CHARS + 1];	
	char assignmentName[MAX_CHARS + 1];
	char gottenName[MAX_CHARS + 1];
	bool studentFound = false;
	
	while (optionChar != 'B') {
		cout << "Enter:" << endl;
		cout << "      A or a  - for Assignment" << endl;
		cout << "      S or s  - for Student" << endl;
		cout << "      B or b  - return to previous" << endl;

		cout << "Enter choice: ";
		cin.getline(option, MAX_CHARS, '\n');  
		option[0] = toupper(option[0]);
		while (strlen(option) > 1 || (option[0] != 'A' && option[0] != 'S' && option[0] != 'B')) {
			cout << "Invalid entry. Try again: ";
			cin.getline(option, MAX_CHARS, '\n');
			option[0] = toupper(option[0]);
		}
		optionChar = option[0];

		if (optionChar == 'A') {
			cout << "Enter student name: ";
			cin.getline(studentName, MAX_CHARS, '\n');
			for (int i = 0; i < size; i++) {
				roster[i].getName(gottenName);
				if (strcmp(gottenName, studentName) == 0) {
					studentFound = true;
					cout << "Enter assignment name: ";
					cin.getline(assignmentName, MAX_CHARS, '\n');
					cout << "Removing all records of \"" << assignmentName;
					cout << "\" for \"" << studentName << "\"!" << endl;
					
					roster[i].removeAssignment(assignmentName);
					cout << "done!" << endl;
				}
			}
			if (studentFound == false) {
				cout << "Student not found!" << endl;
			}
		}

		if (optionChar == 'S') {
			cout << "Enter student name: ";
			cin.getline(studentName, MAX_CHARS, '\n');
			for (int i = 0; i < size; i++) {
				roster[i].getName(gottenName);
				if (strcmp(gottenName, studentName) == 0) {
					studentFound = true;
					cout << "Removing all records of \"" << studentName << "\"!" << endl;
					for (int j = 0; j < size; j++) {
						roster[i] = roster[i + 1];
					}
					roster[size] = Student();
					size--;
				}
			}
			if (studentFound == false) {
				cout << "Student not found!" << endl;
			}
					
		}
	}

}

// adds a student or assignment to the current roster
void add(Student roster[], int & size, int capacity) {

	char option[MAX_CHARS + 1];
	char optionChar = 'f';
	char myName[MAX_CHARS + 1];
	char myGnum[MAX_CHARS + 1];
	char assignmentName[MAX_CHARS + 1];
	char gottenName[MAX_CHARS + 1];
	float assignmentWeight;
	int assignmentGrade;
	bool studentFound = false;
	
	
	while (optionChar != 'B') {
		cout << "Enter:" << endl;
		cout << "      A or a  - for Assignment" << endl;
		cout << "      S or s  - for Student" << endl;
		cout << "      B or b  - return to previous" << endl;

		cout << "Enter choice: ";
		cin.getline(option, MAX_CHARS, '\n');  
		option[0] = toupper(option[0]);
		while (strlen(option) > 1 || (option[0] != 'A' && option[0] != 'S' && option[0] != 'B')) {
			cout << "Invalid entry. Try again: ";
			cin.getline(option, MAX_CHARS, '\n');
			option[0] = toupper(option[0]);
		}
		optionChar = option[0];

		if (optionChar == 'S') {
			if (size < capacity) {
				cout << "Enter student name: ";
				cin.getline(myName, MAX_CHARS, '\n');
				cout << "Enter G-Number for " << myName << ": ";
				cin.getline(myGnum, MAX_CHARS, '\n');
				Student s = Student(myName, myGnum);
				roster[size] = s;
				size++;
			}
		}

		if (optionChar == 'A') {
			cout << "Enter student name: ";
			cin.getline(myName, MAX_CHARS, '\n');
			for (int i = 0; i < size; i++) {
				roster[i].getName(gottenName);
				if (strcmp(gottenName, myName) == 0) {
					studentFound = true;
					if (roster[i].getSize() < roster[i].getCapacity()) {
						cout << "Enter assignment name: ";
						cin.getline(assignmentName, MAX_CHARS, '\n');
						cout << "Enter assignment weight: ";
						cin >> assignmentWeight;
						while (!cin || assignmentWeight < 0) {
							cout << "Invalid input! Try again: ";
							cin.clear();
							cin.ignore(MAX_CHARS, '\n');
							cin >> assignmentWeight;
						}
						cout << "Enter assignment grade: ";
						cin >> assignmentGrade;
						while (!cin || assignmentGrade< 0) {
							cout << "Invalid input! Try again: ";
							cin.clear();
							cin.ignore(MAX_CHARS, '\n');
							cin >> assignmentGrade;
						}
						cin.clear();
						cin.ignore(MAX_CHARS, '\n');
						Assignment a = Assignment(assignmentName, assignmentGrade, assignmentWeight);
						roster[i].addSubmission(a);
					}
					else {
						cout << "Not enough space in assignments." << endl;
					}
				}
			}
			if (studentFound == false) {
				cout << "Student not found!" << endl;
			}
					
		}
	}
	
}
