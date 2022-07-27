//////////////////////////////////////////////////////////////////////////////
// Name:        Autumn Valls
// Assignment:  Assignment 2 - Classes
// Date:        7/27/2022
// Description: This file contains the implementations of the member
//              functions of the Assignment class
// Sources:     None            
//////////////////////////////////////////////////////////////////////////////
#include "assignment.h"

using namespace std;

// constructors
Assignment::Assignment() {
	memset(this->name, 0, sizeof(this->name));
	this->grade = 0;
	this->weight = 0.0;
	memset(this->gnum, 0, sizeof(this->gnum));
}

Assignment::Assignment(char myName[], int myGrade, float myWeight) {
	strcpy(this->name, myName);
	this->grade = myGrade;
	this->weight = myWeight;
}

Assignment::~Assignment() {
	memset(this->name, 0, sizeof(this->name));
	this->grade = 0;
	this->weight = 0.0;
	memset(this->gnum, 0, sizeof(this->gnum));
}

// overload equals operator
void Assignment::operator = (const Assignment & myAssignment) {
	strcpy(this->name, myAssignment.name);
	this->grade = myAssignment.grade;
	this->weight = myAssignment.weight;
	strcpy(this->gnum, myAssignment.gnum);
}

// getters
void Assignment::getName(char myName[]) {
	strcpy(myName, this->name);
}

int Assignment::getGrade() {
	return this->grade;
}

float Assignment::getWeight() {
	return this->weight;
}

void Assignment::getGnum(char myGnum[]) {
	strcpy(myGnum, this->gnum);
}

// setters
void Assignment::setName(char newName[]) {
	strcpy(this->name, newName);
}

void Assignment::setGrade(int newGrade) {
	this->grade = newGrade;
}

void Assignment::setWeight(float newWeight) {
	this->weight = newWeight;
}
