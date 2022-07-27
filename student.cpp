//////////////////////////////////////////////////////////////////////////////
// Name:        Autumn Valls
// Assignment:  Assignment 2 - Classes
// Date:        7/27/2022
// Description: This file has the implementations of the member functions
//              for the Student class
// Sources:     None
//////////////////////////////////////////////////////////////////////////////
#include "student.h"

using namespace std;

// constructors
Student::Student() {
	memset(this->name, 0, sizeof(this->name));
	memset(this->gnum, 0, sizeof(this->gnum));
	this->grade = 0;
	this->size = 0;
	this->capacity = MAX_SUBMISSIONS;
}

Student::Student(char myName[], char myGnum[]) {
	strcpy(this->name, myName);
	strcpy(this->gnum, myGnum);
	this->size = 0;
	this->grade = 0;
	this->capacity = MAX_SUBMISSIONS;
}

Student::Student(char myGnum[]) {
	memset(this->name, 0, sizeof(this->name));
	strcpy(this->gnum, myGnum);
	this->size = 0;
	this->grade = 0;
}

// destructor
Student::~Student() {
	memset(this->name, 0, sizeof(this->name));
	memset(this->gnum, 0, sizeof(this->gnum));
	this->grade = 0;
	this->size = 0;
	this->capacity = MAX_SUBMISSIONS;
}

// getters
void Student::getName(char myName[]) {
	strcpy(myName, this->name);
}

void Student::getGnum(char myGnum[]) {
	strcpy(myGnum, this->gnum);
}

float Student::getGrade() {
	float grade = 0;
	for (int i = 0; i < this->size; i++) {
		grade += this->submissions[i].getGrade() * this->submissions[i].getWeight();
	}
	return grade;
}

int Student::getSize() {
	return this->size;
}

int Student::getCapacity() {
	return this->capacity;
}

// setters
void Student::setName(char newName[]) {
	strcpy(this->name, newName);
}

void Student::setGnum(char newGnum[]) {
	strcpy(this->gnum, newGnum);
}

void Student::setGrade(int newGrade) {
	this->grade = newGrade;
}

// this function displays the data of a student's submitted assignments
void Student::displayAssignments() {
	char gottenAssignment[MAX_CHARS + 1];
	for (int i = 0; i < this->size; i++) {
		this->submissions[i].getName(gottenAssignment);
		cout << "    " << this->submissions[i].getGrade();
		cout << " (" << this->submissions[i].getWeight();
		cout << "%) " << gottenAssignment << endl;
	}
}

// given the Assignment parameter, this function adds it to a student's
// submissions array
void Student::addSubmission(Assignment a) {
	this->submissions[this->size++] = a;
}

// given the assignment name parameter, this function searches for a
// student's assignment by the given name and removes it from their
// submissions array
void Student::removeAssignment(char assignmentName[]) {

	bool assignmentFound = false;
	char gottenAssignment[MAX_CHARS + 1];

	for (int i = 0; i < this->size; i++) {
		this->submissions[i].getName(gottenAssignment);
		if (strcmp(gottenAssignment, assignmentName) == 0) {
			assignmentFound = true;
			for (int j = i; j < size; j++) {
				this->submissions[j] = this->submissions[j + 1];
			}
		submissions[size] = Assignment();
		this->size--;
		}
	}
	if (assignmentFound == false) {
		cout << "Assignment " << assignmentName << " not found!" << endl;
	}
}

// this is an alternative way to display assignment data used specifically for
// the GRADE function in main()
void Student::displayGrades() {

	float total = 0;
	char gottenAssignment[MAX_CHARS + 1];

	for (int i = 0; i < this->size; i++) {
		this->submissions[i].getName(gottenAssignment);
		cout << "        ";
		cout << gottenAssignment;
		cout << " Weight: " << this->submissions[i].getWeight() * 100 << "%";
		cout << "  Score: " << this->submissions[i].getGrade();
		cout << " Contribution: " << this->submissions[i].getGrade() * this->submissions[i].getWeight();
		cout << endl;
		total += this->submissions[i].getGrade() * this->submissions[i].getWeight();
	}
	cout << "            Total: " << total << endl;
}

