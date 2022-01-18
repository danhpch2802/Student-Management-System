#ifndef _STARTUP_H_
#define _STARTUP_H_
#define MAX 1000
#define _CRT_SECURE_NO_WARNINGS 1
#define ENTER 13
#define TAB 9
#define BKSP 8
#define WINWIDTH 113
#define WINHEIGHT 1000
#define _WIN32_WINNT 0x0502
#define MAINICON 101    

#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include<ctime> 
#include <fcntl.h>
#include <io.h>
#include "Crypto++/sha.h"
#include "Crypto++/filters.h"
#include "Crypto++/base64.h"
#include "resource.h"

using namespace std;


struct date {
	int year, month, day;
};
struct staff {
	char* user;
	char* pass;
	char* fullname;
	int sex;
};
struct lecturer {
	char* user;
	char* pass;
	char* fullname;
	char* title;
	int sex;
};
struct student {
	char* user;
	char* pass;
	char* fullname;
	date dob;
	char* stdclass;
	int status;
};
struct ClassNode
{
	char ClassId[10];
	ClassNode* Next;
};

struct StudentText
{
	char ID[10], Name[100], Password[100], Class[10], DateOfBirth[11];
	int Status;
};

struct Semester
{
	char* schoolyear;
	char* smt;
};

struct ptime
{
	int hour, minute;
};

struct Course
{
	char* courseID;
	char* courseName;
	char* cClass;
	lecturer ltr;
	date begin;
	date end;
	ptime start;
	ptime finish;
	int dayofWeek;
	char* room;
};

struct period
{
	date d;
	ptime start, finish;
	int checkin = -1;
};

struct checkIn
{
	student* check;
	period prd[10];
	float midterm = -1, final = -1, bonus = -1, total = -1;
	int courseStt=1;
};

void checkUser(char User[], char Pass[], int& status,int time);
staff* checkStaff(char User[], char Pass[], int& status);
lecturer* checkLecturer(char User[], char Pass[], int& status);
student* checkStudent(char User[], char Pass[], int& status);
staff* createStaff(char User[], char Pass[], char fullName[], int sex);
lecturer* createLecturer(char User[], char Pass[], char fullName[], char Title[], int sex);
student* createStudent(char ID[], char Pass[], char fullName[], date DOB, char StdClass[], int stdstatus);
void viewProfileStaff(staff* Login);
void viewProfileLecturer(lecturer* Login);
void viewProfileStudent(student* Login);
void deleteLecturer(lecturer*& Login);
void deleteStudent(student*& Login);
void deleteStaff(staff*& Login);
void saveStaffNewPass(staff* Login);
staff* changePassStaff(staff*& Login);
lecturer* changePassLecturer(lecturer*& Login);
student* changePassStudent(student*& Login);
void saveStaffNewPass(staff* Login, char newPass[MAX]);
void saveLecturerNewPass(lecturer* Login, char newPass[MAX]);
void saveStudentNewPass(student* Login, char newPass[MAX]);
void enterPass(char Pass[]);

// staff
void AddStudentManually();
void RemoveAStudent();
void ViewClassList();
void ViewStudentInClass();
void CreateSemester();
void AddNewCourse();
void importClass();
void updateNumStudent(int num);
void editExisingStudent();
void Changestudentclass();
void loadclassmoveinto(char FileName[], int& nstudent, StudentText*& StudentList);
void EditStudent(int nstudent, StudentText*& StudentList, int id, char tempPass[], char tempDOB[], char tempName[]);

// Course
void DeleteSemesterList(Semester*& SemesterList, int nsemester);
void DeleteSchedule(Course*& Schedule, int ncourse);
void DeleteCheckIn(checkIn*& CheckList, int ncheck);
void AddNewCourse();
void AddNewStudentToCourse();
void deleteCourse();
date findTheNextDate(date a);
bool checkleap(int year);
void viewAttendance();
void updateNumCourse(char globalPath[], int globalNum);
bool fileHasData(ifstream &fin);
void viewAllLecturers();
checkIn* inputCheckIn(ifstream& input, int& count, Course crs);
void createStudentSchedule(Course crs, checkIn*& student);
bool CheckNewStudent(int ncourse, checkIn* List, char id[]);
void outputCheckIn(ofstream& output, char outputFile[], int count, checkIn* list);
checkIn* loadCheckInFromFile(ifstream& input, int count);
void saveStudentSchedule(Course crs, char outputFile[]);
void viewAllCoursesInASemester();
void outputCheckInExisted(ofstream& output, char outputFile[], int count1, int count2, int total, checkIn* list, checkIn* list2);
void importCourse();
void AddLecturerFromImport(lecturer*& ltr, int& nlecturer, lecturer& NewLecturer);
void AddCourseImported(Course*& Schedule, int& ncourse, char ClassID[], Semester* SemesterList, char importID[], char importName[],
	lecturer importLtr, char importClass[], char importRoom[], date importBeginD, int importDOTW, ptime importStart, ptime importEnd);
int convertStringDOTW(char* pch);
void viewStudentsOfACourse();
void viewScoreboardOfACourse();
void exportScoreboardToCSV();
void exportAttendanceToCSV();
void importScoreboardFromCSV();
bool CheckStudentInCourse(checkIn* CheckList, int ncheck, char studentID[]);
bool CheckNewCourse(int ncourse, Course* Schedule, char id[]);
void LoadCheckList(checkIn*& CheckList, int& ncheck, char CourseFile[]);
void LoadSchedule(char ScheduleFile[], Course*& Schedule, int& ncourse);
void LoadSemester(int& nsemester, Semester*& SemesterList);
void GetCourseFile(char CourseFile[], Semester* SemesterList, char ClassID[], char CourseID[]);
void GetScheduleFile(char ScheduleFile[], Semester* SemesterList, char ClassID[]);
void SaveCheckList(checkIn* CheckList, int ncheck, char CourseFile[]);
void removeStudentfromCourse();
void editCourse();
void editattendance();
void editscoreboard();

// student
void StudentViewSchedule(student* login);
void StudentViewScore(student* login);
void StudentViewCheckIn(student* login);
void StudentCheckIn(student* login);
int getMonth(char* pch);
void getCurrentDate(date& dCur, ptime& tCur);
int distanceyear(int y);
int distancemonth(int m, int y);
int calTime(ptime cal);
void StudentCheckIn(student* login);

// UI
void studentManagementProgram();
void gotoxy();
void loadingScreen();
void changeColor(int i);
void menu();

//Hash
void convertHash(char tempPass[]);
std::string SHA256HashString(std::string aString);
#endif