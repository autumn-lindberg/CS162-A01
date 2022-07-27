#ifndef MAIN_H
#define MAIN_H

#include "student.h"

const int MAX_STUDENTS = 30;

void welcome();
char menu();
int main();
void openFile(ifstream & inFile, char nameParam[]);
void loadGnums(ifstream & inFile, Student roster[], int & size, int capacity);
int loadNames(ifstream & inFile, Student roster[], int size);
int loadAssignments(ifstream & inFile, Student roster[], int size);
void display(Student roster[], int size);
void gpa(Student roster[], int size);
void pct(Student roster[], int size);
void calculateGrade(Student roster[], int size);
void remove(Student roster[], int & size);
void add(Student roster[], int & size, int capacity);

#endif
