#include <iostream>
#include <string>
#include <fstream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
	id = -1;
	studentNum = 0;
	students = new int[100];
}

Faculty::~Faculty(){
	
}

void Faculty::initFac(int k){
	id = k; cin.get();
	cout << "Name: ";	getline(cin, name);
	cout << "Level: ";	cin >> level;	cin.get();
	cout << "Department: ";	getline(cin, dept);
}

void Faculty::setId(int myId){
	id = myId;
}

void Faculty::setName(string myName){
	name = myName;
}

void Faculty::setLevel(string myLevel){
	level = myLevel;
}

void Faculty::setDept(string myDept){
	dept = myDept;
}

void Faculty::printRecord(){
	cout << "Faculty ID: " << getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Current Level: " << getLevel() << endl;
	cout << "Department: " << getDept() << endl;
	for(int i = 0; i < studentNum; ++i){
		cout << "Advisee " << i+1 << ": " << getStudent(i) << endl;
	}
	cout << endl;
}

int Faculty::getID(){
	return id;
}

string Faculty::getName(){
	return name;
}

string Faculty::getLevel(){
	return level;
}

string Faculty::getDept(){
	return dept;
}

int Faculty::getStudent(int n){
	return students[n];
}

int* Faculty::getAllStudents(){
	return students;
}

int Faculty::getStudentNum(){
	return studentNum;
}

void Faculty::addStudent(int id){
	if(studentNum >=100) cout << "Cannot hold anymore students.\n";
	else{
		studentNum++;
		for(int i = 0; i < 100; ++i){
			if(students[i] == 0){
				students[i] = id;
				break;
			}
		}
	}
}

void Faculty::removeStudent(int id){
	int temp, check = 0;
	for(int i = 0; i < 100; ++i){
		temp = students[i];
		if(temp == id){
			students[i] = 0;
			check = 1;
			studentNum--;
		}
		if(check == 1) break;
	}
	if(check == 0) cout << "Student not found under this advisor.\n";
	else cout << "Student has been removed from advisor. \n";
}

bool Faculty::isEqual(Faculty n){
	int x = id;
	int y = n.getID();
	if(x=y) return true;
	else return false;
}

bool Faculty::isLesser(Faculty n){
	int x = id;
	int y = n.getID();
	if(x<y) return true;
	else return false;
}

void Faculty::serialize(std::ofstream& file){
	file << getID() << endl;
	file << getName() << endl;
	file << getLevel() << endl;
	file << getDept() << endl;
	for(int i = 0; i < studentNum; ++i) file << getStudent(i) << endl;
}
