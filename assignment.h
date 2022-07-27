#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

const int MAX_CHARS = 30;

class Assignment {

	private:
		char name[MAX_CHARS + 1];
		int grade;
		float weight;
		char gnum[MAX_CHARS + 1];

	public:
		Assignment();
		Assignment(char myName[], int myGrade, float myWeight);
		~Assignment();
		void operator = (const Assignment & myAssignment);
		void getName(char myName[]);
		int getGrade();
		float getWeight();
		void getGnum(char myGnum[]);
		void setName(char newName[]);
		void setGrade(int newGrade);
		void setWeight(float newWeight);

};

#endif
