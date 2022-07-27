#ifndef STUDENT_H
#define STUDENT_H

#include "assignment.h"

using namespace std;

const int MAX_SUBMISSIONS = 10;

class Student {

	private:
		char name[MAX_CHARS + 1];
		char gnum[MAX_CHARS + 1];
		int size, capacity, grade;
		Assignment submissions[MAX_SUBMISSIONS];

	public:
		Student();
		Student(char name[], char gnum[]);
		Student(char gnum[]);
		~Student();
		void getName(char myName[]);
		void getGnum(char myGnum[]);
		float getGrade();
		int getSize();
		int getCapacity();
		void setName(char newName[]);
		void setGnum(char newGnum[]);
		void setGrade(int newGrade);
		void displayAssignments();
		void addSubmission(Assignment a);
		void removeAssignment(char assignmentName[]);
		void displayGrades();
		void addAssignment(Assignment a);

};

#endif
