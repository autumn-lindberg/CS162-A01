#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;
const int MAX_CHARS = 100;

struct Student {
	char name[MAX_CHARS + 1];
	char gnum[MAX_CHARS + 1];
	char grade[MAX_CHARS + 1];
};

Student initStudent();
void load(ifstream & inFile, Student roster[], int & size, int capacity);
void display(Student roster[], int size);
void gpa(Student roster[], int size);
void pct(Student roster[], int size);
#endif
