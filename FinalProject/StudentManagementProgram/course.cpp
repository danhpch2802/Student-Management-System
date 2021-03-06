#include "startup.h"

void LoadSemester(int& nsemester, Semester*& SemesterList)
{
	ifstream fin;
	fin.open("Semester.txt");
	if (!fin.is_open() || !fileHasData(fin))
	{
		fin.close();
		return;
	}
	fin >> nsemester;
	char temp[10];
	SemesterList = new Semester[nsemester];
	for (int i = 0; i < nsemester; i++)
	{
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		SemesterList[i].schoolyear = new char[size(temp)];
		strcpy(SemesterList[i].schoolyear, temp);
		fin.getline(temp, 4, '\n');
		SemesterList[i].smt = new char[size(temp)];
		strcpy(SemesterList[i].smt, temp);
	}
	fin.close();
}

void SaveSemester(int nsemester, Semester* SemesterList)
{
	ofstream fout;
	fout.open("Semester.txt");
	if (!fout.is_open())
	{
		cout << "Cannot open output file" << endl;
	}
	else
	{
		fout << nsemester << endl;
		for (int i = 0; i < nsemester; i++)
		{
			fout << SemesterList[i].schoolyear << endl;
			fout << SemesterList[i].smt << endl;
		}
	}
	fout.close();
}

void GetScheduleFile(char ScheduleFile[], Semester* SemesterList, char ClassID[])
{
	strcpy(ScheduleFile, SemesterList[0].schoolyear);
	strcat(ScheduleFile, "-");
	strcat(ScheduleFile, SemesterList[0].smt);
	strcat(ScheduleFile, "-Schedule-");
	strcat(ScheduleFile, ClassID);
	strcat(ScheduleFile, ".txt");
}

void LoadSchedule(char ScheduleFile[], Course*& Schedule, int& ncourse)
{
	ifstream fin;
	fin.open(ScheduleFile);
	if (!fin.is_open() || !fileHasData(fin))
	{
		fin.close();
		return;
	}
	fin >> ncourse;
	char temp[100];
	Schedule = new Course[ncourse];
	for (int i = 0; i < ncourse; i++)
	{
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		Schedule[i].courseID = new char[strlen(temp) + 1];
		strcpy(Schedule[i].courseID, temp);
		fin.getline(temp, 100, '\n');
		Schedule[i].courseName = new char[strlen(temp) + 1];
		strcpy(Schedule[i].courseName, temp);
		fin.getline(temp, 10, '\n');
		Schedule[i].cClass = new char[strlen(temp) + 1];
		strcpy(Schedule[i].cClass, temp);
		fin.getline(temp, 20, '\n');
		Schedule[i].ltr.user = new char[strlen(temp) + 1];
		strcpy(Schedule[i].ltr.user, temp);
		fin.getline(temp, 100, '\n');
		Schedule[i].ltr.fullname = new char[strlen(temp) + 1];
		strcpy(Schedule[i].ltr.fullname, temp);
		fin.getline(temp, 10, '\n');
		Schedule[i].ltr.title = new char[strlen(temp) + 1];
		strcpy(Schedule[i].ltr.title, temp);
		fin >> Schedule[i].ltr.sex;
		fin >> Schedule[i].begin.year;
		fin >> Schedule[i].begin.month;
		fin >> Schedule[i].begin.day;
		fin >> Schedule[i].end.year;
		fin >> Schedule[i].end.month;
		fin >> Schedule[i].end.day;
		fin >> Schedule[i].dayofWeek;
		fin >> Schedule[i].start.hour;
		fin >> Schedule[i].start.minute;
		fin >> Schedule[i].finish.hour;
		fin >> Schedule[i].finish.minute;
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		Schedule[i].room = new char[strlen(temp) + 1];
		strcpy(Schedule[i].room, temp);
	}
	fin.close();
}

void LoadLecturer(lecturer*& ltr, int& nlecturer)
{
	ifstream fin;
	fin.open("Lecturer.txt");
	if (!fin.is_open() || !fileHasData(fin))
	{
		fin.close();
		return;
	}
	fin >> nlecturer;
	char temp[100];
	ltr = new lecturer[nlecturer];
	for (int i = 0; i < nlecturer; i++)
	{
		fin.getline(temp, 20, '\n');
		fin.getline(temp, 20, '\n');
		ltr[i].user = new char[strlen(temp) + 1];
		strcpy(ltr[i].user, temp);
		fin.getline(temp, 100, '\n');
		ltr[i].pass = new char[strlen(temp) + 1];
		strcpy(ltr[i].pass, temp);
		fin.getline(temp, 100, '\n');
		ltr[i].fullname = new char[strlen(temp) + 1];
		strcpy(ltr[i].fullname, temp);
		fin.getline(temp, 20, '\n');
		ltr[i].title = new char[strlen(temp) + 1];
		strcpy(ltr[i].title, temp);
		fin >> ltr[i].sex;
		fin.getline(temp, 20, '\n');
	}
	fin.close();
}

void SaveSchedule(char ScheduleFile[], Course* Schedule, int ncourse)
{
	ofstream fout;
	fout.open(ScheduleFile);
	if (!fout.is_open())
	{
		cout << "Cannot open output file" << endl;
	}
	else
	{
		fout << ncourse << endl;
		for (int i = 0; i < ncourse; i++)
		{
			fout << Schedule[i].courseID << endl;
			fout << Schedule[i].courseName << endl;
			fout << Schedule[i].cClass << endl;
			fout << Schedule[i].ltr.user << endl;
			fout << Schedule[i].ltr.fullname << endl;
			fout << Schedule[i].ltr.title << endl;
			fout << Schedule[i].ltr.sex << endl;
			fout << setfill('0') << setw(2) << Schedule[i].begin.year << " ";
			fout << setfill('0') << setw(2) << Schedule[i].begin.month << " ";
			fout << setfill('0') << setw(2) << Schedule[i].begin.day << endl;
			fout << setfill('0') << setw(2) << Schedule[i].end.year << " ";
			fout << setfill('0') << setw(2) << Schedule[i].end.month << " ";
			fout << setfill('0') << setw(2) << Schedule[i].end.day << endl;
			fout << Schedule[i].dayofWeek << endl;
			fout << setfill('0') << setw(2) << Schedule[i].start.hour << " ";
			fout << setfill('0') << setw(2) << Schedule[i].start.minute << endl;
			fout << setfill('0') << setw(2) << Schedule[i].finish.hour << " ";
			fout << setfill('0') << setw(2) << Schedule[i].finish.minute << endl;
			fout << Schedule[i].room << endl << endl;
		}
	}
	fout.close();
}

void SaveLecturer(lecturer* ltr, int nlecturer)
{
	ofstream fout;
	fout.open("lecturer.txt");
	if (!fout.is_open())
	{
		cout << "Cannot open output file" << endl;
	}
	else
	{
		fout << nlecturer << endl;
		for (int i = 0; i < nlecturer; i++)
		{
			fout << ltr[i].user << endl;
			fout << ltr[i].pass << endl;
			fout << ltr[i].fullname << endl;
			fout << ltr[i].title << endl;
			fout << ltr[i].sex << endl << endl;
		}
	}
	fout.close();
}

bool CheckNewCourse(int ncourse, Course* Schedule, char id[])
{
	for (int i = 0; i < ncourse; i++)
	{
		if (strcmp(Schedule[i].courseID, id) == 0)
		{
			return false;
		}
	}
	return true;
}

bool CheckNewLecturer(int nlecturer, lecturer* ltr, lecturer& NewLecturer)
{
	char t[100];
	for (int i = 0; i < nlecturer; i++)
	{
		if (strcmp(ltr[i].fullname, NewLecturer.fullname) == 0)
		{
			strcpy(t, ltr[i].pass);
			NewLecturer.pass = new char[strlen(t) + 1];
			strcpy(NewLecturer.pass, t);
			strcpy(t, ltr[i].user);
			NewLecturer.user = new char[strlen(t) + 1];
			strcpy(NewLecturer.user, t);
			strcpy(t, ltr[i].title);
			NewLecturer.title = new char[strlen(t) + 1];
			strcpy(NewLecturer.title, t);
			NewLecturer.sex = ltr[i].sex;
			return false;
		}
	}
	return true;
}

void AddLecturer(lecturer*& ltr, int& nlecturer, lecturer& NewLecturer)
{
	char tmp[100];
	lecturer* NewltrList = new lecturer[nlecturer + 1];
	for (int i = 0; i < nlecturer; i++)
	{
		strcpy(tmp, ltr[i].user);
		NewltrList[i].user = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].user, tmp);
		strcpy(tmp, ltr[i].fullname);
		NewltrList[i].fullname = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].fullname, tmp);
		strcpy(tmp, ltr[i].pass);
		NewltrList[i].pass = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].pass, tmp);
		strcpy(tmp, ltr[i].title);
		NewltrList[i].title = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].title, tmp);
		NewltrList[i].sex = ltr[i].sex;
	}
	strcpy(tmp, NewLecturer.fullname);
	NewltrList[nlecturer].fullname = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].fullname, tmp);
	cout << "Username: ";
	cin.getline(tmp, 100, '\n');
	NewltrList[nlecturer].user = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].user, tmp);
	NewLecturer.user = new char[strlen(tmp) + 1];
	strcpy(NewLecturer.user, tmp);
	convertHash(tmp);
	NewltrList[nlecturer].pass = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].pass, tmp);
	cout << "Title: ";
	cin.getline(tmp, 20, '\n');
	NewltrList[nlecturer].title = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].title, tmp);
	NewLecturer.title = new char[strlen(tmp) + 1];
	strcpy(NewLecturer.title, tmp);
	cout << "Gender 1/0: ";
	cin >> NewltrList[nlecturer].sex;
	NewLecturer.sex = NewltrList[nlecturer].sex;
	for (int i = 0; i < nlecturer; i++)
	{
		delete[] ltr[i].fullname;
		delete[] ltr[i].pass;
		delete[] ltr[i].title;
		delete[] ltr[i].user;
	}
	if (nlecturer > 0)
	{
		delete[] ltr;
	}
	nlecturer++;
	ltr = NewltrList;
}

void AddCourse(Course*& Schedule, int& ncourse, char ClassID[], Semester* SemesterList)
{
	char temp[100];
	Course* NewSchedule;
	cout << "ID new course: ";
	cin.getline(temp, 10, '\n');
	if (!CheckNewCourse(ncourse, Schedule, temp))
	{
		cout << "This ID belongs to another course\nUpdate course 1/0 ?";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			char outputFile[50];
			strcpy(outputFile, SemesterList->schoolyear);
			strcat(outputFile, "-");
			strcat(outputFile, SemesterList->smt);
			strcat(outputFile, "-");
			for (int i = 0; i < ncourse; i++)
			{
				if (strcmp(Schedule[i].courseID, temp) == 0)
				{
					saveStudentSchedule(Schedule[i], outputFile);
					return;
				}
			}
		}
	}
	else
	{
		NewSchedule = new Course[ncourse + 1];
		NewSchedule[ncourse].courseID = new char[strlen(temp) + 1];
		strcpy(NewSchedule[ncourse].courseID, temp);
		for (int i = 0; i < ncourse; i++)
		{
			strcpy(temp, Schedule[i].courseID);
			NewSchedule[i].courseID = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].courseID, temp);
			strcpy(temp, Schedule[i].courseName);
			NewSchedule[i].courseName = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].courseName, temp);
			strcpy(temp, Schedule[i].cClass);
			NewSchedule[i].cClass = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].cClass, temp);
			strcpy(temp, Schedule[i].ltr.user);
			NewSchedule[i].ltr.user = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].ltr.user, temp);
			strcpy(temp, Schedule[i].ltr.fullname);
			NewSchedule[i].ltr.fullname = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].ltr.fullname, temp);
			strcpy(temp, Schedule[i].ltr.title);
			NewSchedule[i].ltr.title = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].ltr.title, temp);
			NewSchedule[i].ltr.sex = Schedule[i].ltr.sex;
			NewSchedule[i].begin.year = Schedule[i].begin.year;
			NewSchedule[i].begin.month = Schedule[i].begin.month;
			NewSchedule[i].begin.day = Schedule[i].begin.day;
			NewSchedule[i].end.year = Schedule[i].end.year;
			NewSchedule[i].end.month = Schedule[i].end.month;
			NewSchedule[i].end.day = Schedule[i].end.day;
			NewSchedule[i].dayofWeek = Schedule[i].dayofWeek;
			NewSchedule[i].start.hour = Schedule[i].start.hour;
			NewSchedule[i].start.minute = Schedule[i].start.minute;
			NewSchedule[i].finish.hour = Schedule[i].finish.hour;
			NewSchedule[i].finish.minute = Schedule[i].finish.minute;
			strcpy(temp, Schedule[i].room);
			NewSchedule[i].room = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].room, temp);
		}
		strcpy(temp, ClassID);
		NewSchedule[ncourse].cClass = new char[strlen(temp) + 1];
		strcpy(NewSchedule[ncourse].cClass, temp);
		cout << "\nLecturer's name: ";
		cin.getline(temp, 100, '\n');
		NewSchedule[ncourse].ltr.fullname = new char[strlen(temp) + 1];
		strcpy(NewSchedule[ncourse].ltr.fullname, temp);
		lecturer* ltr;
		int nlecturer = 0;
		LoadLecturer(ltr, nlecturer);
		if (CheckNewLecturer(nlecturer, ltr, NewSchedule[ncourse].ltr))
		{
			AddLecturer(ltr, nlecturer, NewSchedule[ncourse].ltr);
			SaveLecturer(ltr, nlecturer);
			cin.ignore(100, '\n');
		}
		for (int i = 0; i < nlecturer; i++)
		{
			delete[] ltr[i].fullname;
			delete[] ltr[i].pass;
			delete[] ltr[i].title;
			delete[] ltr[i].user;
		}
		if (nlecturer > 0)
		{
			delete[] ltr;
		}
		cout << "Course name: ";
		cin.getline(temp, 100, '\n');
		NewSchedule[ncourse].courseName = new char[strlen(temp) + 1];
		strcpy(NewSchedule[ncourse].courseName, temp);
		cout << "Room: ";
		cin.getline(temp, 10, '\n');
		NewSchedule[ncourse].room = new char[strlen(temp) + 1];
		strcpy(NewSchedule[ncourse].room, temp);
		cout << "Beginning Date:\nY: ";
		cin >> NewSchedule[ncourse].begin.year;
		cout << "M: ";
		cin >> NewSchedule[ncourse].begin.month;
		cout << "D :";
		cin >> NewSchedule[ncourse].begin.day;
		NewSchedule[ncourse].end = findTheNextDate(NewSchedule[ncourse].begin);
		for (int i = 0; i < 62; i++)
		{
			NewSchedule[ncourse].end = findTheNextDate(NewSchedule[ncourse].end);
		}
		cout << "Day of week: ";
		cin >> NewSchedule[ncourse].dayofWeek;
		cout << "Starting time:\nh: ";
		cin >> NewSchedule[ncourse].start.hour;
		cout << "m: ";
		cin >> NewSchedule[ncourse].start.minute;
		cout << "Finishing time:\nh: ";
		cin >> NewSchedule[ncourse].finish.hour;
		cout << "m: ";
		cin >> NewSchedule[ncourse].finish.minute;
		if (ncourse != 0)
		{
			DeleteSchedule(Schedule, ncourse);
		}
		Schedule = NewSchedule;
		ncourse++;
		char outputFile[50];
		strcpy(outputFile, SemesterList->schoolyear);
		strcat(outputFile, "-");
		strcat(outputFile, SemesterList->smt);
		strcat(outputFile, "-");
		saveStudentSchedule(Schedule[ncourse - 1], outputFile);
	}
}

void GetCourseFile(char CourseFile[], Semester* SemesterList, char ClassID[], char CourseID[])
{
	strcpy(CourseFile, SemesterList[0].schoolyear);
	strcat(CourseFile, "-");
	strcat(CourseFile, SemesterList[0].smt);
	strcat(CourseFile, "-");
	strcat(CourseFile, ClassID);
	strcat(CourseFile, "-");
	strcat(CourseFile, CourseID);
	strcat(CourseFile, "-Student.txt");
}

void LoadStudent(student*& StudentList, int& nstudent)
{
	ifstream fin;
	fin.open("Student.txt");
	if (!fin.is_open() || !fileHasData(fin))
	{
		fin.close();
		return;
	}
	fin >> nstudent;
	char temp[100];
	StudentList = new student[nstudent];
	for (int i = 0; i < nstudent; i++)
	{
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		StudentList[i].user = new char[strlen(temp) + 1];
		strcpy(StudentList[i].user, temp);
		fin.getline(temp, 100, '\n');
		StudentList[i].pass = new char[strlen(temp) + 1];
		strcpy(StudentList[i].pass, temp);
		fin.getline(temp, 100, '\n');
		StudentList[i].fullname = new char[strlen(temp) + 1];
		strcpy(StudentList[i].fullname, temp);
		fin >> StudentList[i].dob.year;
		fin >> StudentList[i].dob.month;
		fin >> StudentList[i].dob.day;
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		StudentList[i].stdclass = new char[strlen(temp) + 1];
		strcpy(StudentList[i].stdclass, temp);
		fin >> StudentList[i].status;
		fin.getline(temp, 10, '\n');
	}
	fin.close();
}

void LoadCheckList(checkIn*& CheckList, int& ncheck, char CourseFile[])
{
	ifstream fin;
	fin.open(CourseFile);
	if (!fin.is_open() || !fileHasData(fin))
	{
		fin.close();
		return;
	}
	fin >> ncheck;
	char temp[100];
	CheckList = new checkIn[ncheck];
	for (int i = 0; i < ncheck; i++)
	{
		CheckList[i].check = new student;
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		CheckList[i].check->user = new char[strlen(temp) + 1];
		strcpy(CheckList[i].check->user, temp);
		fin.getline(temp, 100, '\n');
		CheckList[i].check->pass = new char[strlen(temp) + 1];
		strcpy(CheckList[i].check->pass, temp);
		fin.getline(temp, 100, '\n');
		CheckList[i].check->fullname = new char[strlen(temp) + 1];
		strcpy(CheckList[i].check->fullname, temp);
		fin >> CheckList[i].check->dob.year;
		fin >> CheckList[i].check->dob.month;
		fin >> CheckList[i].check->dob.day;
		fin.getline(temp, 10, '\n');
		fin.getline(temp, 10, '\n');
		CheckList[i].check->stdclass = new char[strlen(temp) + 1];
		strcpy(CheckList[i].check->stdclass, temp);
		fin >> CheckList[i].check->status;
		fin >> CheckList[i].midterm;
		fin >> CheckList[i].final;
		fin >> CheckList[i].bonus;
		fin >> CheckList[i].total;
		for (int j = 0; j < 10; j++)
		{
			fin >> CheckList[i].prd[j].d.year;
			fin >> CheckList[i].prd[j].d.month;
			fin >> CheckList[i].prd[j].d.day;
			fin >> CheckList[i].prd[j].start.hour;
			fin >> CheckList[i].prd[j].start.minute;
			fin >> CheckList[i].prd[j].finish.hour;
			fin >> CheckList[i].prd[j].finish.minute;
			fin >> CheckList[i].prd[j].checkin;
		}
		fin >> CheckList[i].courseStt;
		fin.getline(temp, 10, '\n');
	}
	fin.close();
}

bool CheckExistingStudent(student* StudentList, int nstudent, char ID[])
{
	for (int i = 0; i < nstudent; i++)
	{
		if (strcmp(StudentList[i].user, ID) == 0 && StudentList[i].status == 1)
		{
			return true;
		}
	}
	return false;
}

bool CheckStudentInCourse(checkIn* CheckList, int ncheck, char studentID[])
{
	for (int i = 0; i < ncheck; i++)
	{
		if (strcmp(CheckList[i].check->user, studentID) == 0 && CheckList[i].courseStt == 1)
		{
			return true;
		}
	}
	return false;
}

void AddCourseStudent(student* StudentList, checkIn*& CheckList, Course* Schedule, int nstudent, int& ncheck, int ncourse, char courseId[], char studentId[])
{
	if (!CheckExistingStudent(StudentList, nstudent, studentId))
	{
		cout << "This student does not exist";
		return;
	}
	if (CheckStudentInCourse(CheckList, ncheck, studentId))
	{
		cout << "This student is already in course";
		return;
	}
	checkIn* NewCheckList = new checkIn[ncheck + 1];
	for (int i = 0; i < ncheck; i++)
	{
		NewCheckList[i].check = new student;
		NewCheckList[i].check->dob = CheckList[i].check->dob;
		NewCheckList[i].check->status = CheckList[i].check->status;
		NewCheckList[i].check->pass = new char[strlen(CheckList[i].check->pass) + 1];
		strcpy(NewCheckList[i].check->pass, CheckList[i].check->pass);
		NewCheckList[i].check->fullname = new char[strlen(CheckList[i].check->fullname) + 1];
		strcpy(NewCheckList[i].check->fullname, CheckList[i].check->fullname);
		NewCheckList[i].check->stdclass = new char[strlen(CheckList[i].check->stdclass) + 1];
		strcpy(NewCheckList[i].check->stdclass, CheckList[i].check->stdclass);
		NewCheckList[i].check->user = new char[strlen(CheckList[i].check->user) + 1];
		strcpy(NewCheckList[i].check->user, CheckList[i].check->user);
		NewCheckList[i].courseStt = CheckList[i].courseStt;
		NewCheckList[i].final = CheckList[i].final;
		NewCheckList[i].bonus = CheckList[i].bonus;
		NewCheckList[i].midterm = CheckList[i].midterm;
		NewCheckList[i].total = CheckList[i].total;
		for (int j = 0; j < 10; j++)
		{
			NewCheckList[i].prd[j].d = CheckList[i].prd[j].d;
			NewCheckList[i].prd[j].checkin = CheckList[i].prd[j].checkin;
			NewCheckList[i].prd[j].finish = CheckList[i].prd[j].finish;
			NewCheckList[i].prd[j].start = CheckList[i].prd[j].start;
		}
	}
	DeleteCheckIn(CheckList, ncheck);
	CheckList = NewCheckList;
	for (int i = 0; i < nstudent; i++)
	{
		if (strcmp(StudentList[i].user, studentId) == 0)
		{
			CheckList[ncheck].check = new student;
			CheckList[ncheck].check->dob = StudentList[i].dob;
			CheckList[ncheck].check->status = StudentList[i].status;
			CheckList[ncheck].check->pass = new char[strlen(StudentList[i].pass) + 1];
			strcpy(CheckList[ncheck].check->pass, StudentList[i].pass);
			CheckList[ncheck].check->fullname = new char[strlen(StudentList[i].fullname) + 1];
			strcpy(CheckList[ncheck].check->fullname, StudentList[i].fullname);
			CheckList[ncheck].check->stdclass = new char[strlen(StudentList[i].stdclass) + 1];
			strcpy(CheckList[ncheck].check->stdclass, StudentList[i].stdclass);
		}
	}
	CheckList[ncheck].check->user = new char[strlen(studentId) + 1];
	strcpy(CheckList[ncheck].check->user, studentId);
	CheckList[ncheck].courseStt = 1;
	for (int i = 0; i < ncourse; i++)
	{
		if (strcmp(Schedule[i].courseID, courseId) == 0)
		{
			CheckList[ncheck].prd[0].d = Schedule[i].begin;
			CheckList[ncheck].prd[0].start = Schedule[i].start;
			CheckList[ncheck].prd[0].finish = Schedule[i].finish;
		}
	}
	CheckList[ncheck].prd[0].checkin = -1;
	for (int i = 1; i < 10; i++)
	{
		CheckList[ncheck].prd[i].d = findTheNextDate(CheckList[ncheck].prd[i - 1].d);
		for (int j = 0; j < 6; j++)
		{
			CheckList[ncheck].prd[i].d = findTheNextDate(CheckList[ncheck].prd[i].d);
		}
		CheckList[ncheck].prd[i].start = CheckList[ncheck].prd[i - 1].start;
		CheckList[ncheck].prd[i].finish = CheckList[ncheck].prd[i - 1].finish;
		CheckList[ncheck].prd[i].checkin = -1;
	}
	ncheck++;
}

void SaveCheckList(checkIn* CheckList, int ncheck, char CourseFile[])
{
	ofstream fout;
	fout.open(CourseFile);
	if (!fout.is_open())
	{
		cout << "Cannot open output file" << endl;
	}
	else
	{
		fout << ncheck << endl;
		for (int i = 0; i < ncheck; i++)
		{
			fout << CheckList[i].check->user << endl;
			fout << CheckList[i].check->pass << endl;
			fout << CheckList[i].check->fullname << endl;
			fout << setfill('0') << setw(2) << CheckList[i].check->dob.year << " ";
			fout << setfill('0') << setw(2) << CheckList[i].check->dob.month << " ";
			fout << setfill('0') << setw(2) << CheckList[i].check->dob.day << endl;
			fout << CheckList[i].check->stdclass << endl;
			fout << CheckList[i].check->status << endl;
			fout << CheckList[i].midterm << endl;
			fout << CheckList[i].final << endl;
			fout << CheckList[i].bonus << endl;
			fout << CheckList[i].total << endl;
			for (int j = 0; j < 10; j++)
			{
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].d.year << " ";
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].d.month << " ";
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].d.day << " ";
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].start.hour << " ";
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].start.minute << " ";
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].finish.hour << " ";
				fout << setfill('0') << setw(2) << CheckList[i].prd[j].finish.minute << " ";
				fout << CheckList[i].prd[j].checkin << endl;
			}
			fout << CheckList[i].courseStt << endl << endl;
		}
	}
	fout.close();
}

void DeleteSemesterList(Semester*& SemesterList, int nsemester)
{
	for (int i = 0; i < nsemester; i++)
	{
		delete[] SemesterList[i].schoolyear;
		delete[] SemesterList[i].smt;
	}
	if (nsemester > 0)
	{
		delete[] SemesterList;
	}
}

void DeleteCheckIn(checkIn*& CheckList, int ncheck)
{
	for (int i = 0; i < ncheck; i++)
	{
		deleteStudent(CheckList[i].check);
	}
	if (ncheck > 0)
	{
		delete[]CheckList;
	}
}

void DeleteSchedule(Course*& Schedule, int ncourse)
{
	for (int i = 0; i < ncourse; i++)
	{
		delete[] Schedule[i].courseID;
		delete[] Schedule[i].courseName;
		delete[] Schedule[i].cClass;
		delete[] Schedule[i].room;
		delete[] Schedule[i].ltr.fullname;
		delete[] Schedule[i].ltr.title;
		delete[] Schedule[i].ltr.user;
	}
	if (ncourse > 0)
	{
		delete[] Schedule;
	}
}

// cau 13
void CreateSemester()
{
	Semester* SemesterList;
	int nsemester = 0;
	LoadSemester(nsemester, SemesterList);
	cout << "Schoolyear: ";
	cin.getline(SemesterList[0].schoolyear, 10, '\n');
	cout << "Semester: ";
	cin.getline(SemesterList[0].smt, 4, '\n');
	SaveSemester(nsemester, SemesterList);
	DeleteSemesterList(SemesterList, nsemester);
}

// cau 15
void AddNewCourse()
{
	Semester* SemesterList;
	Course* Schedule;
	char ScheduleFile[50], ClassID[10];
	int nsemester = 0, ncourse = 0;
	LoadSemester(nsemester, SemesterList);
	if (nsemester == 0)
	{
		cout << "Semester list is empty\n";
		return;
	}
	cin.ignore(100, '\n');
	cout << "Enter class of new course: ";
	cin.getline(ClassID, 10, '\n');
	GetScheduleFile(ScheduleFile, SemesterList, ClassID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	AddCourse(Schedule, ncourse, ClassID, SemesterList);
	SaveSchedule(ScheduleFile, Schedule, ncourse);
	DeleteSemesterList(SemesterList, nsemester);
	DeleteSchedule(Schedule, ncourse);
}

// cau 19
void AddNewStudentToCourse()
{
	student* StudentList;
	Semester* SemesterList;
	checkIn* CheckList;
	Course* Schedule;
	char CourseFile[50], ScheduleFile[50], ClassID[10], CourseID[20], StudentID[10];
	int nsemester = 0, nstudent = 0, ncheck = 0, ncourse = 0;
	LoadSemester(nsemester, SemesterList);
	if (nsemester == 0)
	{
		cout << "Semester list is empty\n";
		return;
	}
	cout << "Enter class of course: ";
	cin.getline(ClassID, 10, '\n');
	cin.getline(ClassID, 10, '\n');
	cout << "Enter course Id: ";
	cin.getline(CourseID, 20, '\n');
	cout << endl;
	GetScheduleFile(ScheduleFile, SemesterList, ClassID);
	GetCourseFile(CourseFile, SemesterList, ClassID, CourseID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	if (ncourse == 0)
	{
		DeleteSemesterList(SemesterList, nsemester);
		cout << "The schedule of this class is empty\n";
		return;
	}
	LoadStudent(StudentList, nstudent);
	if (nstudent == 0)
	{
		DeleteSemesterList(SemesterList, nsemester);
		DeleteSchedule(Schedule, ncourse);
		cout << "List of students is empty" << endl;
		return;
	}
	LoadCheckList(CheckList, ncheck, CourseFile);
	if (CheckNewCourse(ncourse, Schedule, CourseID))
	{
		cout << "This course does not exist";
	}
	else
	{
		cout << "Enter student Id: ";
		cin.getline(StudentID, 10, '\n');
		AddCourseStudent(StudentList, CheckList, Schedule, nstudent, ncheck, ncourse, CourseID, StudentID);
		SaveCheckList(CheckList, ncheck, CourseFile);
	}
	DeleteSemesterList(SemesterList, nsemester);
	for (int i = 0; i < nstudent; i++)
	{
		delete[] StudentList[i].fullname;
		delete[] StudentList[i].pass;
		delete[] StudentList[i].stdclass;
		delete[] StudentList[i].user;
	}
	if (nstudent > 0)
	{
		delete[] StudentList;
	}
	DeleteCheckIn(CheckList, ncheck);
	DeleteSchedule(Schedule, ncourse);
}


// cau 17
void deleteCourse() 
{
	char tempYear[20], tempSem[20], tempClass[20];
	cout << "\n\n--Course Info To Delete--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;

	ofstream tempCourse;
	ifstream courseIn;

	char courseFile[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-Schedule-");
	strcat(courseFile, tempClass);
	strcat(courseFile, ".txt");

	cout << "\nOpening " << courseFile << endl;
	Sleep(2000);
	tempCourse.open("tempC.txt");
	courseIn.open(courseFile);

	if (!fileHasData(courseIn))
	{
		cout << "Error opening file" << endl;
		return;
	}
	else
	{
		char tempID[MAX];//input Id
		char tempCourseID[MAX], tempCourseName[MAX], tempClass[MAX], tempUser[MAX], tempLecture[MAX], tempTitle[MAX], tempRoom[MAX];


		cout << "Enter the ID of the course you want to delete: ";
		cin.getline(tempID, MAX, '\n');
		cin.getline(tempID, MAX, '\n'); 
		int numCourse;
		courseIn >> numCourse;
		courseIn.getline(tempCourseID, MAX);//read first blank line

		if (numCourse == 0)
		{
			cout << "No course has been added" << endl;
			return;
		}

		for (int i = 0; i < numCourse; i++)
		{
			courseIn.getline(tempCourseID, MAX);

			if (strncmp(tempID, tempCourseID, MAX) == 0)
			{
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
				courseIn.ignore(MAX, '\n');
			}
			else
			{
				courseIn.getline(tempCourseName, MAX);
				courseIn.getline(tempClass, MAX);
				courseIn.getline(tempUser, MAX);
				courseIn.getline(tempLecture, MAX);
				courseIn.getline(tempTitle, MAX);

				int gender;
				courseIn >> gender;

				date dstart, dfin;
				courseIn >> dstart.year;
				courseIn >> dstart.month;
				courseIn >> dstart.day;
				courseIn >> dfin.year;
				courseIn >> dfin.month;
				courseIn >> dfin.day;
				int tempdayOfWeek;
				courseIn >> tempdayOfWeek;

				ptime tstart, tfin;
				courseIn >> tstart.hour;
				courseIn >> tstart.minute;
				courseIn >> tfin.hour;
				courseIn >> tfin.minute;

				courseIn.getline(tempRoom, MAX);
				courseIn.getline(tempRoom, MAX);

				tempCourse << tempCourseID << endl;
				tempCourse << tempCourseName << endl;
				tempCourse << tempClass << endl;
				tempCourse << tempUser << endl;
				tempCourse << tempLecture << endl;
				tempCourse << tempTitle << endl;
				tempCourse << gender << endl;
				tempCourse << dstart.year << " " << dstart.month << " " << dstart.day << endl;
				tempCourse << dfin.year << " " << dfin.month << " " << dfin.day << endl;
				tempCourse << tempdayOfWeek << endl;
				tempCourse << tstart.hour << " " << tstart.minute << endl;
				tempCourse << tfin.hour << " " << tfin.minute << endl;
				tempCourse << tempRoom << endl;
				tempCourse << '\n';
				courseIn.ignore(MAX, '\n');
			}
		}

		courseIn.close();
		tempCourse.close();
		remove(courseFile);
		rename("tempC.txt", courseFile);
		updateNumCourse(courseFile,numCourse);
		cout << "Course has been removed" << endl;
	}
}

void updateNumCourse(char globalPath[],int globalNum)
{
	ifstream input;
	ofstream tempFile;
	input.open(globalPath);
	tempFile.open("temp.txt");

	tempFile << globalNum - 1 << endl; //delete numCourse by 1 when delete a course

	char temp[MAX];
	while (input.getline(temp, MAX))
	{
		if (temp == "\n") continue;
		tempFile << temp << endl;
	}
	tempFile.close();
	input.close();
	remove(globalPath);
	rename("temp.txt", globalPath);
}

// cau 20
void viewAllCoursesInASemester()
{
	ifstream fin;

	char tempYear[20], tempSem[20], tempClass[20];
	cout << "\n\n--Semester Info To View Courses--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;

	char courseFile[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-Schedule-");
	strcat(courseFile, tempClass);
	strcat(courseFile, ".txt");


	cout << "\nOpening " << courseFile << endl;
	Sleep(2000);
	fin.open(courseFile);

	if (!fileHasData(fin))
	{
		cout << "File is empty" << endl;
		return;
	}

	cout << "--List of Courses In This Semester--" << endl;
	int numCourse;
	fin >> numCourse;

	char tempCourseID[MAX], tempCourseName[MAX], tempclass[MAX], tempUser[MAX], tempLecture[MAX], tempTitle[MAX], tempRoom[MAX];
	fin.getline(tempCourseID, MAX);
	for (int i = 0; i < numCourse; i++)
	{
		fin.getline(tempCourseID, MAX);
		fin.getline(tempCourseName, MAX);
		fin.getline(tempclass, MAX);
		fin.getline(tempUser, MAX);
		fin.getline(tempLecture, MAX);
		fin.getline(tempTitle, MAX);
		int gender;
		fin >> gender;

		date dstart, dfin;
		fin >> dstart.year;
		fin >> dstart.month;
		fin >> dstart.day;
		fin >> dfin.year;
		fin >> dfin.month;
		fin >> dfin.day;
		int tempdayOfWeek;
		fin >> tempdayOfWeek;

		ptime tstart, tfin;
		fin >> tstart.hour;
		fin >> tstart.minute;
		fin >> tfin.hour;
		fin >> tfin.minute;

		fin.getline(tempRoom, MAX);
		fin.getline(tempRoom, MAX);
		fin.ignore(MAX, '\n');

		cout << tempCourseID << endl;
		cout << tempCourseName << endl;
		cout << tempclass << endl;
		cout << tempUser << endl;
		cout << tempLecture << endl;
		cout << tempTitle << endl;
		if (gender == 0) cout << "Male" << endl;
		else cout << "Female" << endl;
		cout << dstart.year << " " << dstart.month << " " << dstart.day << endl;
		cout << dfin.year << " " << dfin.month << " " << dfin.day << endl;
		cout << tempdayOfWeek << endl;
		cout << tstart.hour << " " << tstart.minute << endl;
		cout << tfin.hour << " " << tfin.minute << endl;
		cout << tempRoom << endl;
		cout << '\n';
	}
	fin.close();
}

// cau 21, 29
void viewStudentsOfACourse()
{
	char tempYear[20], tempSem[20], tempClass[20], tempID[20];
	cout << "\n\n--Course Info To View Students--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;
	cout << "Course ID: ";
	cin >> tempID;

	ifstream courseIn;

	char courseFile[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-");
	strcat(courseFile, tempClass);
	strcat(courseFile, "-");
	strcat(courseFile, tempID);
	strcat(courseFile, "-Student.txt");

	courseIn.open(courseFile);
	cout << "\nOpening " << courseFile << endl;

	Sleep(2000);

	if (!fileHasData(courseIn))
	{
		cout << "List is empty" << endl;
		return;
	}

	char tempStudentID[MAX], tempFullName[MAX], tempstdclass[MAX];
	int numSt;
	courseIn >> numSt;

	for (int i = 0; i < numSt; i++)
	{
		courseIn.getline(tempStudentID, MAX);
		courseIn.getline(tempStudentID, MAX);
		courseIn.ignore(MAX, '\n'); //ignore pass
		courseIn.getline(tempFullName, MAX);

		date tempdob;
		courseIn >> tempdob.year >> tempdob.month >> tempdob.day;

		courseIn.getline(tempstdclass, MAX);
		courseIn.getline(tempstdclass, MAX);

		int sstatus; //student status
		courseIn >> sstatus;

		float tmidterm, tfinal, tbonus, ttotal;
		courseIn >> tmidterm;
		courseIn >> tfinal;
		courseIn >> tbonus;
		courseIn >> ttotal;

		period p[10];
		for (int j = 0; j < 10; j++)
			courseIn >> p[j].d.year >> p[j].d.month >> p[j].d.day >> p[j].start.hour >> p[j].start.minute >> p[j].finish.hour >> p[j].finish.minute >> p[j].checkin;


		int cstatus; //course status
		courseIn >> cstatus;

		//print student list
		cout << endl;
		cout << tempStudentID << endl;
		cout << tempFullName << endl;
		cout << tempdob.year << " " << tempdob.month << " " << tempdob.day << endl;

		cout << '\n';
		courseIn.ignore(MAX, '\n');
	}
	courseIn.close();
}

// cau 22, 30
void viewAttendance()
{
	char tempYear[20], tempSem[20], tempClass[20], tempID[20];
	cout << "\n\n--Course Info To View Attendance--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;
	cout << "Course ID: ";
	cin >> tempID;

	ifstream courseIn;

	char courseFile[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-");
	strcat(courseFile, tempClass);
	strcat(courseFile, "-");
	strcat(courseFile, tempID);
	strcat(courseFile, "-Student.txt");

	courseIn.open(courseFile);
	cout << "\nOpening " << courseFile << endl;
	
	Sleep(2000);

	if (!fileHasData(courseIn))
	{
		cout << "List is empty" << endl;
		return;
	}

	char tempStudentID[MAX], tempFullName[MAX], tempstdclass[MAX];
	int numSt;
	courseIn >> numSt;

	for (int i = 0; i < numSt; i++)
	{
		courseIn.getline(tempStudentID, MAX);
		courseIn.getline(tempStudentID, MAX);
		courseIn.ignore(MAX, '\n'); //ignore pass
		courseIn.getline(tempFullName, MAX);

		date tempdob;
		courseIn >> tempdob.year >> tempdob.month >> tempdob.day;

		courseIn.getline(tempstdclass, MAX);
		courseIn.getline(tempstdclass, MAX);

		int sstatus;
		courseIn >> sstatus;

		float tmidterm, tfinal, tbonus, ttotal;
		courseIn >> tmidterm;
		courseIn >> tfinal;
		courseIn >> tbonus;
		courseIn >> ttotal;

		period p[10];
		for (int j = 0; j < 10; j++)
			courseIn >> p[j].d.year >> p[j].d.month >> p[j].d.day >> p[j].start.hour >> p[j].start.minute >> p[j].finish.hour >> p[j].finish.minute >> p[j].checkin;
		

		int cstatus; //course status
		courseIn >> cstatus;

		//print attendance list
		cout << endl;
		cout << tempStudentID << endl;
		for (int r = 0; r < 10; r++)
		{
			cout << p[r].d.year << " " << p[r].d.month << " " << p[r].d.day << " " << p[r].start.hour << " " << p[r].start.minute << " " << p[r].finish.hour << " " << p[r].finish.minute << " " << p[r].checkin;
			cout << endl;
		}

		cout << '\n';
		courseIn.ignore(MAX, '\n');
	}
	courseIn.close();
}

// cau 23
void viewAllLecturers()
{
	ifstream fin;
	fin.open("Lecturer.txt");
	if (!fileHasData(fin))
	{
		cout << "File is empty" << endl;
		return;
	}

	cout << "--List of Lecturers--" << endl;
	int numLecturer;
	fin >> numLecturer;

	char tempUser[MAX], tempPass[MAX], tempFullName[MAX], tempTitle[MAX];
	int sex;
	for (int i = 0; i < numLecturer; i++)
	{
		fin.getline(tempUser, MAX);
		fin.getline(tempUser, MAX);
		fin.getline(tempPass, MAX); 
		fin.getline(tempFullName, MAX);
		fin.getline(tempTitle, MAX);
		fin >> sex;
		fin.ignore(MAX, '\n');

		cout << tempUser << endl;
		// no printing pass
		cout << tempFullName << endl;
		cout << tempTitle << endl;
		if (sex == 0)
			cout << "Male" << endl;
		else cout << "Female" << endl;
		cout << '\n';
	}
	fin.close();
}

//cau 24, 34
void viewScoreboardOfACourse()
{
	char tempYear[20], tempSem[20], tempClass[20], tempID[20];
	cout << "\n\n--Course Info To View Scoreboard--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;
	cout << "Course ID: ";
	cin >> tempID;

	ifstream courseIn;

	char courseFile[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-");
	strcat(courseFile, tempClass);
	strcat(courseFile, "-");
	strcat(courseFile, tempID);
	strcat(courseFile, "-Student.txt");

	courseIn.open(courseFile);
	cout << "\nOpening " << courseFile << endl;

	Sleep(2000);

	if (!fileHasData(courseIn))
	{
		cout << "List is empty" << endl;
		return;
	}

	char tempStudentID[MAX], tempFullName[MAX], tempstdclass[MAX];
	int numSt;
	courseIn >> numSt;

	for (int i = 0; i < numSt; i++)
	{
		courseIn.getline(tempStudentID, MAX);
		courseIn.getline(tempStudentID, MAX);
		courseIn.ignore(MAX, '\n'); //ignore pass
		courseIn.getline(tempFullName, MAX);

		date tempdob;
		courseIn >> tempdob.year >> tempdob.month >> tempdob.day;

		courseIn.getline(tempstdclass, MAX);
		courseIn.getline(tempstdclass, MAX);

		int sstatus;
		courseIn >> sstatus;

		float tmidterm, tfinal, tbonus, ttotal;
		courseIn >> tmidterm;
		courseIn >> tfinal;
		courseIn >> tbonus;
		courseIn >> ttotal;

		period p[10];
		for (int j = 0; j < 10; j++)
			courseIn >> p[j].d.year >> p[j].d.month >> p[j].d.day >> p[j].start.hour >> p[j].start.minute >> p[j].finish.hour >> p[j].finish.minute >> p[j].checkin;


		int cstatus; //course status
		courseIn >> cstatus;

		//print score list
		cout << endl;
		cout << tempStudentID << endl;
		cout << "Midterm: " << tmidterm << endl;
		cout << "Final: " << tfinal << endl;
		cout << "Bonus: " << tbonus << endl;
		cout << "Total: " << ttotal << endl;

		cout << '\n';
		courseIn.ignore(MAX, '\n');
	}
	courseIn.close();
}

// cau 25
void exportScoreboardToCSV()
{
	char tempYear[20], tempSem[20], tempClass[20], tempID[20];
	cout << "\n\n--Course Info To Export Scoreboard--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;
	cout << "Course ID: ";
	cin >> tempID;

	ifstream courseIn;
	ofstream courseOut;

	char courseFile[MAX], courseOutput[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-");
	strcat(courseFile, tempClass);
	strcat(courseFile, "-");
	strcat(courseFile, tempID);
	strcat(courseFile, "-Student.txt");

	strcpy(courseOutput, tempYear);
	strcat(courseOutput, "-");
	strcat(courseOutput, tempSem);
	strcat(courseOutput, "-");
	strcat(courseOutput, tempClass);
	strcat(courseOutput, "-");
	strcat(courseOutput, tempID);
	strcat(courseOutput, "-Scoreboard.csv");

	courseIn.open(courseFile);
	courseOut.open(courseOutput);
	cout << "\nOpening " << courseFile << endl;
	Sleep(2000);
	cout << "\nOpening " << courseOutput << endl;
	Sleep(2000);

	if (!fileHasData(courseIn))
	{
		cout << "List is empty" << endl;
		return;
	}

	courseOut << "No,Student ID,Full name,Midterm,Final,Bonus,Total" << endl;
	char tempStudentID[MAX], tempFullName[MAX], tempstdclass[MAX];
	int numSt;
	courseIn >> numSt;

	for (int i = 0; i < numSt; i++)
	{
		courseIn.getline(tempStudentID, MAX);
		courseIn.getline(tempStudentID, MAX);
		courseIn.ignore(MAX, '\n'); //ignore pass
		courseIn.getline(tempFullName, MAX);

		date tempdob;
		courseIn >> tempdob.year >> tempdob.month >> tempdob.day;

		courseIn.getline(tempstdclass, MAX);
		courseIn.getline(tempstdclass, MAX);

		int sstatus;
		courseIn >> sstatus;

		float tmidterm, tfinal, tbonus, ttotal;
		courseIn >> tmidterm;
		courseIn >> tfinal;
		courseIn >> tbonus;
		courseIn >> ttotal;

		period p[10];
		for (int j = 0; j < 10; j++)
			courseIn >> p[j].d.year >> p[j].d.month >> p[j].d.day >> p[j].start.hour >> p[j].start.minute >> p[j].finish.hour >> p[j].finish.minute >> p[j].checkin;


		int cstatus; //course status
		courseIn >> cstatus;

		//export scoreboard
		courseOut << i + 1 << ",";
		courseOut << tempStudentID << "," <<tempFullName<<","<< tmidterm << "," << tfinal << "," << tbonus << "," << ttotal << endl;
		courseIn.ignore(MAX, '\n');
	}
	courseIn.close();
	courseOut.close();
	cout << "Scoreboard has been exported to " << courseOutput << endl;
}

// cau 27
void exportAttendanceToCSV()
{
	char tempYear[20], tempSem[20], tempClass[20], tempID[20];
	cout << "\n\n--Course Info To Export Attendance--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;
	cout << "Course ID: ";
	cin >> tempID;

	ifstream courseIn;
	ofstream courseOut;

	char courseFile[MAX], courseOutput[MAX];
	strcpy(courseFile, tempYear);
	strcat(courseFile, "-");
	strcat(courseFile, tempSem);
	strcat(courseFile, "-");
	strcat(courseFile, tempClass);
	strcat(courseFile, "-");
	strcat(courseFile, tempID);
	strcat(courseFile, "-Student.txt");

	strcpy(courseOutput, tempYear);
	strcat(courseOutput, "-");
	strcat(courseOutput, tempSem);
	strcat(courseOutput, "-");
	strcat(courseOutput, tempClass);
	strcat(courseOutput, "-");
	strcat(courseOutput, tempID);
	strcat(courseOutput, "-Attendance.csv");

	courseIn.open(courseFile);
	courseOut.open(courseOutput);
	cout << "\nOpening " << courseFile << endl;
	Sleep(2000);
	cout << "\nOpening " << courseOutput << endl;
	Sleep(2000);

	if (!fileHasData(courseIn))
	{
		cout << "List is empty" << endl;
		return;
	}

	courseOut << "No,Student ID,Year,Month,Day,Start Hour,Start Minute,End Hour,End Minute,Attendance Status" << endl;
	char tempStudentID[MAX], tempFullName[MAX], tempstdclass[MAX];
	int numSt;
	courseIn >> numSt;

	for (int i = 0; i < numSt; i++)
	{
		courseIn.getline(tempStudentID, MAX);
		courseIn.getline(tempStudentID, MAX);
		courseIn.ignore(MAX, '\n'); //ignore pass
		courseIn.getline(tempFullName, MAX);

		date tempdob;
		courseIn >> tempdob.year >> tempdob.month >> tempdob.day;

		courseIn.getline(tempstdclass, MAX);
		courseIn.getline(tempstdclass, MAX);

		int sstatus;
		courseIn >> sstatus;

		float tmidterm, tfinal, tbonus, ttotal;
		courseIn >> tmidterm;
		courseIn >> tfinal;
		courseIn >> tbonus;
		courseIn >> ttotal;

		period p[10];
		for (int j = 0; j < 10; j++)
			courseIn >> p[j].d.year >> p[j].d.month >> p[j].d.day >> p[j].start.hour >> p[j].start.minute >> p[j].finish.hour >> p[j].finish.minute >> p[j].checkin;


		int cstatus; //course status
		courseIn >> cstatus;

		//export attendance
		for (int r = 0; r < 10; r++)
		{
			courseOut << i + 1 << "," << tempStudentID << ",";
			courseOut << p[r].d.year << "," << p[r].d.month << "," << p[r].d.day << "," << p[r].start.hour << "," << p[r].start.minute << "," << p[r].finish.hour << "," << p[r].finish.minute << "," << p[r].checkin;
			courseOut << endl;
		}
		courseOut<< '\n';
		courseIn.ignore(MAX, '\n');
	}
	courseIn.close();
	courseOut.close();
	cout << "Attendance list has been exported to " << courseOutput << endl;
}

//cau 32
void importScoreboardFromCSV()
{
	char tempYear[20], tempSem[20], tempClass[20], tempID[20];
	cout << "\n\n--CSV file info to get Scoreboard--" << endl;
	cout << "Course year: (yyyy-yyyy) ";
	cin >> tempYear;
	cout << "Course semester: ";
	cin >> tempSem;
	cout << "Class: ";
	cin >> tempClass;
	cout << "Course ID: ";
	cin >> tempID;

	ifstream courseIn, studentIn;
	ofstream courseOut;

	char courseFile[MAX], studentOutput[MAX], studentFile[MAX];
	char temp[MAX], * pch;
	strcpy(courseFile, tempClass);
	strcat(courseFile, "-");
	strcat(courseFile, tempID);
	strcat(courseFile, "-Scoreboard.csv");

	strcpy(studentOutput, tempYear);
	strcat(studentOutput, "-");
	strcat(studentOutput, tempSem);
	strcat(studentOutput, "-");
	strcat(studentOutput, tempClass);
	strcat(studentOutput, "-");
	strcat(studentOutput, tempID);
	strcat(studentOutput, "-Student.txt");


	cout << "\nOpening " << courseFile << endl;
	Sleep(2000);
	cout << "\nOpening " << studentOutput << endl;
	Sleep(2000);
	courseOut.open("tempS.txt");
	courseIn.open(courseFile);
	studentIn.open(studentOutput);

	if (!fileHasData(courseIn) && !fileHasData(studentIn))
	{
		cout << "Error opening file" << endl;
		return;
	}

	char importID[MAX], importName[MAX], importmidterm[MAX], importfinal[MAX], importbonus[MAX], importtotal[MAX];
	char tempStudentID[MAX], tempPass[MAX], tempFullName[MAX], tempstdclass[MAX];
	int numSt;

	//read student.txt file
	studentIn >> numSt;
	courseOut << numSt << endl;
	courseIn.getline(temp, MAX);
	for (int i = 0; i < numSt; i++)
	{
		studentIn.getline(tempStudentID, MAX);
		studentIn.getline(tempStudentID, MAX);
		studentIn.getline(tempPass, MAX);
		studentIn.getline(tempFullName, MAX);

		date tempdob;
		studentIn >> tempdob.year >> tempdob.month >> tempdob.day;

		studentIn.getline(tempstdclass, MAX);
		studentIn.getline(tempstdclass, MAX);

		int sstatus; //student status
		studentIn >> sstatus;

		float tmidterm, tfinal, tbonus, ttotal;
		studentIn >> tmidterm;
		studentIn >> tfinal;
		studentIn >> tbonus;
		studentIn >> ttotal;
		period p[10];
		for (int j = 0; j < 10; j++)
			studentIn >> p[j].d.year >> p[j].d.month >> p[j].d.day >> p[j].start.hour >> p[j].start.minute >> p[j].finish.hour >> p[j].finish.minute >> p[j].checkin;
		int cstatus; //course status
		studentIn >> cstatus;

		//read scoreboard.csv file
		courseIn.getline(temp, MAX);
			pch = strtok(temp, ",");
			pch = strtok(NULL, ",");
			strcpy(importID, pch);
			pch = strtok(NULL, ",");
			strcpy(importName, pch);
			pch = strtok(NULL, ",");
			strcpy(importmidterm, pch);
			pch = strtok(NULL, ",");
			strcpy(importfinal, pch);
			pch = strtok(NULL, ",");
			strcpy(importbonus, pch);
			pch = strtok(NULL, ",");
			strcpy(importtotal, pch);

		//copy from txt to temp
			courseOut << tempStudentID << endl;
			courseOut << tempPass << endl;
			courseOut << tempFullName << endl;
			courseOut << setfill('0') << setw(2) << tempdob.year << " " << setfill('0') << setw(2) << tempdob.month << " " << setfill('0') << setw(2) << tempdob.day << endl;
			courseOut << tempstdclass << endl;
			courseOut << sstatus << endl;
			//change temp score
			courseOut << importmidterm << endl;
			courseOut << importfinal << endl;
			courseOut << importbonus << endl;
			courseOut << importtotal << endl;

			for (int r = 0; r < 10; r++)
			{
				courseOut << setfill('0') << setw(2) << p[r].d.year << " " << setfill('0') << setw(2) << p[r].d.month << " " << setfill('0') << setw(2) << p[r].d.day << " "
					<< setfill('0') << setw(2) << p[r].start.hour << " " << setfill('0') << setw(2) << p[r].start.minute << " "
					<< setfill('0') << setw(2) << p[r].finish.hour << " " << setfill('0') << setw(2) << p[r].finish.minute << " "
					<< p[r].checkin << endl;
			}
			courseOut << cstatus << endl;
			courseOut << endl;
		studentIn.ignore(MAX, '\n');
	}

	courseIn.close();
	studentIn.close();
	courseOut.close();
	remove(studentOutput);
	rename("tempS.txt", studentOutput);
	cout << "File imported successfully!" << endl;
}

date findTheNextDate(date a)
{
	int day = a.day, month = a.month, year = a.year;
	date b;
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (day == 30)
		{
			month++;
			day = 01;
			break;
		}
		else
		{
			day++;
			break;
		}
	}
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	{
		if (day == 31)
		{
			month++;
			day = 01;
			break;
		}
		else
		{
			day++;
			break;
		}
	}
	case 12:
	{
		if (day == 31)
		{
			year++;
			day = 01, month = 01;
			break;
		}
		else
		{
			day++;
			break;
		}
	}
	case 2:
	{
		if (((checkleap(year) == false) && (day == 28)) || ((checkleap(year) == true) && (day == 29)))
		{
			day = 01, month = 03;
			break;
		}
		else
		{
			day++;
			break;
		}
	}
	}
	b.day = day, b.month = month, b.year = year;
	return b;
}

bool checkleap(int year)
{
	if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0))
		return true;
	else
		return false;
}

void createStudentSchedule(Course crs,checkIn&student)
{

	date temp;
	temp.day = crs.begin.day;
	temp.month = crs.begin.month;
	temp.year = crs.begin.year;
	for (int i = 0; i < 10; i++)
	{
		student.prd[i].d.day = temp.day;
		student.prd[i].d.month = temp.month;
		student.prd[i].d.year = temp.year;
		student.prd[i].start.hour = crs.start.hour;
		student.prd[i].start.minute = crs.start.minute;
		student.prd[i].finish.hour = crs.finish.hour;
		student.prd[i].finish.minute = crs.finish.minute;
		temp = findTheNextDate(temp);
		temp = findTheNextDate(temp);
		temp = findTheNextDate(temp);
		temp = findTheNextDate(temp);
		temp = findTheNextDate(temp);
		temp = findTheNextDate(temp);
		temp = findTheNextDate(temp);
	}
}

bool fileHasData(ifstream& fin)
{
	if (!fin.is_open()) return false;
	if (fin.peek() == std::ifstream::traits_type::eof()) {
		fin.close();
		return false;
	}
	else return true;
}

checkIn *inputCheckIn(ifstream &input,  int& count,Course crs)
{
	input >> count;
	checkIn *list = new checkIn[count];
	StudentText temp;
	for (int i = 0; i < count; i++)
	{
		date tempDOB;
		createStudentSchedule(crs,list[i]);
		input.getline(temp.ID, MAX);
		input.getline(temp.ID, MAX);
		input.getline(temp.Password, MAX);
		input.getline(temp.Name, MAX);
		input >> tempDOB.year;
		input >> tempDOB.month;
		input >> tempDOB.day;
		input.getline(temp.Class, MAX);
		input.getline(temp.Class, MAX);
		input >> temp.Status;
		list[i].check = createStudent(temp.ID, temp.Password, temp.Name, tempDOB, temp.Class, temp.Status);
		input.ignore(MAX, '\n');
	}
	input.close();
	return list;
}
void outputCheckIn(ofstream& output, char outputFile[],int count,checkIn* list)
{
	output.open(outputFile);
	output << count<< endl;
	for (int i = 0; i < count; i++)
	{
		output << list[i].check->user << endl;
		output << list[i].check->pass << endl;
		output << list[i].check->fullname << endl;
		output << setfill('0') << setw(2) << list[i].check->dob.year << " " << setfill('0') << setw(2) << list[i].check->dob.month << " " << setfill('0') << setw(2) << list[i].check->dob.day << endl;
		output << list[i].check->stdclass << endl;
		output << list[i].check->status << endl;
		output << list[i].midterm << endl;
		output << list[i].final << endl;
		output << list[i].bonus << endl;
		output << list[i].total << endl;
		for (int j = 0; j < 10; j++)
		{
			output << setfill('0') << setw(2) << list[i].prd[j].d.year << " " << setfill('0') << setw(2) << list[i].prd[j].d.month << " " << setfill('0') << setw(2) << list[i].prd[j].d.day << " "
				<< setfill('0') << setw(2) << list[i].prd[j].start.hour << " " << setfill('0') << setw(2) << list[i].prd[j].start.minute << " "
				<< setfill('0') << setw(2) << list[i].prd[j].finish.hour << " " << setfill('0') << setw(2) << list[i].prd[j].finish.minute << " "
				<< list[i].prd[j].checkin << endl;
		}
		output << list[i].courseStt << endl;
		output << '\n';
	}
	output.close();
}


bool CheckNewStudent(int nstudent, checkIn* List, char id[])
{
	for (int i = 0; i < nstudent; i++)
	{
		if (strcmp(List[i].check->user, id) == 0)
		{
			return false;
		}
	}
	return true;
}

checkIn* loadCheckInFromFile(ifstream &input, int count)
{
	if (!fileHasData(input))
	{
		return nullptr;
	}
	checkIn* list = new checkIn[count];
	for (int i = 0; i < count; i++)
	{
		StudentText temp;
		date tempDOB;
		input.getline(temp.ID, MAX);
		input.getline(temp.ID, MAX);
		input.getline(temp.Password, MAX);
		input.getline(temp.Name, MAX);
		input >> tempDOB.year;
		input >> tempDOB.month;
		input >> tempDOB.day;
		input.getline(temp.Class, MAX);
		input.getline(temp.Class, MAX);
		input >> temp.Status;
		list[i].check = createStudent(temp.ID, temp.Password, temp.Name, tempDOB, temp.Class, temp.Status);
		input >> list[i].midterm;
		input >> list[i].final;
		input >> list[i].bonus;
		input >> list[i].total;
		for (int j = 0; j < 10; j++)
		{
			input >> list[i].prd[j].d.year;
			input >> list[i].prd[j].d.month;
			input >> list[i].prd[j].d.day;
			input >> list[i].prd[j].start.hour;
			input >> list[i].prd[j].start.minute;
			input >> list[i].prd[j].finish.hour;
			input >> list[i].prd[j].finish.minute;
			input >> list[i].prd[j].checkin;
		}
		input >> list[i].courseStt;
		input.ignore(MAX, '\n');
	}
	return list;
}

void saveStudentSchedule(Course crs, char outputFile[])
{
	char filename[MAX];
	strcpy(filename, "Student-");
	strcat(filename, crs.cClass);
	strcat(filename, ".txt");
	ifstream input;
	input.open(filename);
	if (!fileHasData(input))
	{
		cout << "Can't find existing student of	" << crs.cClass << " class\n";
		return;
	}
	int count1;
	checkIn* list = inputCheckIn(input, count1, crs);
	ifstream output;
	strcat(outputFile, crs.cClass);
	strcat(outputFile, "-");
	strcat(outputFile, crs.courseID);
	strcat(outputFile, "-Student.txt");
	output.open(outputFile);
	if (!fileHasData(output))
	{
		ofstream output;
		outputCheckIn(output, outputFile, count1, list);
	}
	else
	{
		int count2,checkNew=0,total;
		output >> count2;
		checkIn* list2 = loadCheckInFromFile(output, count2);
		output.close();
		if (list2 == nullptr)
		{
			for (int i = 0; i < count1; i++)
			{
				deleteStudent(list[i].check);
			}
			delete[]list;
			cout << "Error occured 1" << endl;
			return;
		}
		for (int i = 0; i < count1; i++)
		{

			if (CheckNewStudent(count2, list2, list[i].check->user)) checkNew++;
		}
		if (checkNew != 0)
		{
			output.close();
			int total = checkNew + count2;
			ofstream output;
			outputCheckInExisted(output, outputFile, count2, count1, total, list2, list);
		}
		for (int i = 0; i < count2; i++)
		{
			deleteStudent(list2[i].check);
		}
		delete[]list2;
	}
	for (int i = 0; i < count1; i++)
	{
		deleteStudent(list[i].check);
	}
	delete[]list;
}

bool CheckUniqueCourseID(Course* Schedule, int ncourse, char ID[], int choice)
{
	for (int i = 0; i < ncourse; i++)
	{
		if (strcmp(Schedule[i].courseID,ID) == 0 && i != choice)
		{
			return false;
		}
	}
	return true;
}

//cau 16
void editCourse() {
	int ncourse = 0, nsemester = 0, nlecturer = 0, choice, choice2;
	char ScheduleFile[50], ClassID[10], OldCourseFile[50], NewCourseFile[50], temp[100];
	Semester* semlist;
	Course* Schedule;
	lecturer* ltr;
	cout << "Editing exist course" << endl;
	cout << "Enter class ID:";
	cin.getline(ClassID, 10);
	cin.getline(ClassID, 10);
	LoadSemester(nsemester, semlist);
	if (nsemester == 0)
	{
		cout << "Semester list is empty\n";
		return;
	}
	GetScheduleFile(ScheduleFile, semlist, ClassID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	if (ncourse == 0)
	{
		DeleteSemesterList(semlist, nsemester);
		cout << "Schedule is empty\n";
		return;
	}
	cout << "\n" << "List of course" << endl;
	for (int i = 0; i < ncourse; i++) {
		cout << i << "-" << Schedule[i].courseID << endl;
	}
	cout << "Choose Course ID:";
	cin >> choice;
	cout << "\n" << "Course current ID:" << Schedule[choice].courseID << endl;
	cout << "Course current name:" << Schedule[choice].courseName << endl;
	cout << "Do you wish to edit this course? 0 - No / 1 - Yes" << endl;
	cout << "Enter your choice:";
	cin >> choice2;
	if (choice2 == 1) {
		GetCourseFile(OldCourseFile, semlist, ClassID, Schedule[choice].courseID);
		cout << "Enter course ID:";
		delete[] Schedule[choice].courseID;
		cin.getline(temp, 100, '\n');
		cin.getline(temp, 100, '\n');
		Schedule[choice].courseID = new char[strlen(temp) + 1];
		strcpy(Schedule[choice].courseID, temp);
		while (!CheckUniqueCourseID(Schedule, ncourse, Schedule[choice].courseID, choice))
		{
			cout << "This ID is already taken. Please input a new one.\nEnter course ID:";
			delete[] Schedule[choice].courseID;
			cin.getline(temp, 100, '\n');
			Schedule[choice].courseID = new char[strlen(temp) + 1];
			strcpy(Schedule[choice].courseID, temp);
		}

		GetCourseFile(NewCourseFile, semlist, ClassID, Schedule[choice].courseID);
		rename(OldCourseFile, NewCourseFile);
		cout << "Enter course name:";
		delete[] Schedule[choice].courseName;
		cin.getline(temp, 100, '\n');
		Schedule[choice].courseName = new char[strlen(temp) + 1];
		strcpy(Schedule[choice].courseName, temp);

		cout << "Enter lecture full name:";
		delete[] Schedule[choice].ltr.fullname;
		cin.getline(temp, 100, '\n');
		Schedule[choice].ltr.fullname = new char[strlen(temp) + 1];
		strcpy(Schedule[choice].ltr.fullname, temp);
		LoadLecturer(ltr, nlecturer);
		if (CheckNewLecturer(nlecturer, ltr, Schedule[choice].ltr))
		{
			AddLecturer(ltr, nlecturer, Schedule[choice].ltr);
			SaveLecturer(ltr, nlecturer);
		}
		if (nlecturer > 0)
		{
			for (int i = 0; i < nlecturer; i++)
			{
				delete[] ltr[i].fullname;
				delete[] ltr[i].pass;
				delete[] ltr[i].title;
				delete[] ltr[i].user;
			}
			delete[] ltr;
		}

		cout << "Enter course begin day (YYYY MM DD):";
		cin >> Schedule[choice].begin.year;
		cin >> Schedule[choice].begin.month;
		cin >> Schedule[choice].begin.day;
		Schedule[choice].end = findTheNextDate(Schedule[choice].begin);
		for (int i = 0; i < 62; i++)
		{
			Schedule[choice].end = findTheNextDate(Schedule[choice].end);
		}

		cout << "Enter course day of week:";
		cin >> Schedule[choice].dayofWeek;

		cout << "Enter course start time (hh mm):";
		cin >> Schedule[choice].start.hour;
		cin >> Schedule[choice].start.minute;

		cout << "Enter course end time (hh mm):";
		cin >> Schedule[choice].finish.hour;
		cin >> Schedule[choice].finish.minute;
		cout << "Enter classroom:";
		delete[] Schedule[choice].room;
		cin.getline(temp, 100, '\n');
		cin.getline(temp, 100, '\n');
		Schedule[choice].room = new char[strlen(temp) + 1];
		strcpy(Schedule[choice].room, temp);
	}
	else {
		cout << "Cancel editing course!" << endl;
	}
	SaveSchedule(ScheduleFile, Schedule, ncourse);
	DeleteSemesterList(semlist, nsemester);
	DeleteSchedule(Schedule, ncourse);
}

void outputCheckInExisted(ofstream& output, char outputFile[], int count2,int count1,int total, checkIn* list2,checkIn* list1)
{
	output.open(outputFile);
	output << total << endl;
	for (int i = 0; i < count2; i++)
	{
		output << list2[i].check->user << endl;
		output << list2[i].check->fullname << endl;
		output << setfill('0') << setw(2) << list2[i].check->dob.year << " " << setfill('0') << setw(2) << list2[i].check->dob.month << " " << setfill('0') << setw(2) << list2[i].check->dob.day << endl;
		output << list2[i].check->stdclass << endl;
		output << list2[i].check->status << endl;
		output << list2[i].midterm << endl;
		output << list2[i].final << endl;
		output << list2[i].bonus << endl;
		output << list2[i].total << endl;
		for (int j = 0; j < 10; j++)
		{
			output << setfill('0') << setw(2) << list2[i].prd[j].d.year << " " << setfill('0') << setw(2) << list2[i].prd[j].d.month << " " << setfill('0') << setw(2) << list2[i].prd[j].d.day << " "
				<< setfill('0') << setw(2) << list2[i].prd[j].start.hour << " " << setfill('0') << setw(2) << list2[i].prd[j].start.minute << " "
				<< setfill('0') << setw(2) << list2[i].prd[j].finish.hour << " " << setfill('0') << setw(2) << list2[i].prd[j].finish.minute << " "
				<< list2[i].prd[j].checkin << endl;
		}
		output << list2[i].courseStt << endl;
		output << '\n';
	}
	for (int i = 0; i < count1; i++)
	{ 
		if (CheckNewStudent(count2, list2, list1[i].check->user))
		{
			output << list1[i].check->user << endl;
				output << list1[i].check->fullname << endl;
				output << setfill('0') << setw(2) << list1[i].check->dob.year << " " << setfill('0') << setw(2) << list1[i].check->dob.month << " " << setfill('0') << setw(2) << list1[i].check->dob.day << endl;
				output << list1[i].check->stdclass << endl;
				output << list1[i].check->status << endl;
				output << list1[i].midterm << endl;
				output << list1[i].final << endl;
				output << list1[i].bonus << endl;
				output << list1[i].total << endl;
			for (int j = 0; j < 10; j++)
			{
				output << setfill('0') << setw(2) << list1[i].prd[j].d.year << " " << setfill('0') << setw(2) << list1[i].prd[j].d.month << " " << setfill('0') << setw(2) << list1[i].prd[j].d.day << " "
					<< setfill('0') << setw(2) << list1[i].prd[j].start.hour << " " << setfill('0') << setw(2) << list1[i].prd[j].start.minute << " "
					<< setfill('0') << setw(2) << list1[i].prd[j].finish.hour << " " << setfill('0') << setw(2) << list1[i].prd[j].finish.minute << " "
					<< list1[i].prd[j].checkin << endl;
			}
			output << list1[i].courseStt << endl;
			output << '\n';
		}
	}
	output.close();
}

void AddCourseImported(Course*& Schedule, int& ncourse, char ClassID[], Semester* SemesterList,char importID[],char importName[],
	lecturer importLtr,char importClass[],char importRoom[],date importBeginD,int importDOTW,ptime importStart,ptime importEnd)
{
	char temp[MAX];
	Course* NewSchedule;
	if (!CheckNewCourse(ncourse, Schedule, importID))
	{
		cout << importID << " already existed\nUpdate course 1/0 ?";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			char outputFile[50];
			strcpy(outputFile, SemesterList->schoolyear);
			strcat(outputFile, "-");
			strcat(outputFile, SemesterList->smt);
			strcat(outputFile, "-");
			for (int i = 0; i < ncourse; i++)
			{
				if (strcmp(Schedule[i].courseID, importID) == 0)
				{
					saveStudentSchedule(Schedule[i], outputFile);
					return;
				}
			}
		}
	}
	else
	{
		NewSchedule = new Course[ncourse + 1];
		NewSchedule[ncourse].courseID = new char[strlen(importID) + 1];
		strcpy(NewSchedule[ncourse].courseID, importID);
		for (int i = 0; i < ncourse; i++)
		{
			strcpy(temp, Schedule[i].courseID);
			NewSchedule[i].courseID = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].courseID, temp);
			strcpy(temp, Schedule[i].courseName);
			NewSchedule[i].courseName = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].courseName, temp);
			strcpy(temp, Schedule[i].cClass);
			NewSchedule[i].cClass = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].cClass, temp);
			strcpy(temp, Schedule[i].ltr.user);
			NewSchedule[i].ltr.user = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].ltr.user, temp);
			strcpy(temp, Schedule[i].ltr.fullname);
			NewSchedule[i].ltr.fullname = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].ltr.fullname, temp);
			strcpy(temp, Schedule[i].ltr.title);
			NewSchedule[i].ltr.title = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].ltr.title, temp);
			NewSchedule[i].ltr.sex = Schedule[i].ltr.sex;
			NewSchedule[i].begin.year = Schedule[i].begin.year;
			NewSchedule[i].begin.month = Schedule[i].begin.month;
			NewSchedule[i].begin.day = Schedule[i].begin.day;
			NewSchedule[i].end.year = Schedule[i].end.year;
			NewSchedule[i].end.month = Schedule[i].end.month;
			NewSchedule[i].end.day = Schedule[i].end.day;
			NewSchedule[i].dayofWeek = Schedule[i].dayofWeek;
			NewSchedule[i].start.hour = Schedule[i].start.hour;
			NewSchedule[i].start.minute = Schedule[i].start.minute;
			NewSchedule[i].finish.hour = Schedule[i].finish.hour;
			NewSchedule[i].finish.minute = Schedule[i].finish.minute;
			strcpy(temp, Schedule[i].room);
			NewSchedule[i].room = new char[strlen(temp) + 1];
			strcpy(NewSchedule[i].room, temp);
		}
		strcpy(temp, ClassID);
		NewSchedule[ncourse].cClass = new char[strlen(temp) + 1];
		strcpy(NewSchedule[ncourse].cClass,importClass);
		NewSchedule[ncourse].ltr.fullname = new char[strlen(importLtr.fullname) + 1];
		strcpy(NewSchedule[ncourse].ltr.fullname, importLtr.fullname);
		lecturer* ltr;
		int nlecturer = 0;
		LoadLecturer(ltr, nlecturer);
		if (CheckNewLecturer(nlecturer, ltr, NewSchedule[ncourse].ltr))
		{
			NewSchedule[ncourse].ltr.user = new char[strlen(importLtr.user) + 1];
			strcpy(NewSchedule[ncourse].ltr.user, importLtr.user);
			NewSchedule[ncourse].ltr.title = new char[strlen(importLtr.title) + 1];
			strcpy(NewSchedule[ncourse].ltr.title, importLtr.title);
			NewSchedule[ncourse].ltr.sex = importLtr.sex;
			AddLecturerFromImport(ltr, nlecturer, NewSchedule[ncourse].ltr);
			SaveLecturer(ltr, nlecturer);
		}
		for (int i = 0; i < nlecturer; i++)
		{
			delete[] ltr[i].fullname;
			delete[] ltr[i].pass;
			delete[] ltr[i].title;
			delete[] ltr[i].user;
		}
		if (nlecturer > 0)
		{
			delete[] ltr;
		}
		NewSchedule[ncourse].courseName = new char[strlen(importName) + 1];
		strcpy(NewSchedule[ncourse].courseName, importName);
		NewSchedule[ncourse].room = new char[strlen(importRoom) + 1];
		strcpy(NewSchedule[ncourse].room, importRoom);
		NewSchedule[ncourse].begin.year=importBeginD.year;
		NewSchedule[ncourse].begin.month= importBeginD.month;
		NewSchedule[ncourse].begin.day= importBeginD.day;
		NewSchedule[ncourse].end = findTheNextDate(NewSchedule[ncourse].begin);
		for (int i = 0; i < 62; i++)
		{
			NewSchedule[ncourse].end = findTheNextDate(NewSchedule[ncourse].end);

		}
	
		NewSchedule[ncourse].dayofWeek=importDOTW;
		NewSchedule[ncourse].start.hour=importStart.hour;
		NewSchedule[ncourse].start.minute=importStart.minute;
		NewSchedule[ncourse].finish.hour=importEnd.hour;
		NewSchedule[ncourse].finish.minute=importEnd.minute;
		if (ncourse != 0)
		{
			DeleteSchedule(Schedule, ncourse);
		}
		Schedule = NewSchedule;
		ncourse++;
		char outputFile[50];
		strcpy(outputFile, SemesterList->schoolyear);
		strcat(outputFile, "-");
		strcat(outputFile, SemesterList->smt);
		strcat(outputFile, "-");
		saveStudentSchedule(Schedule[ncourse - 1], outputFile);
	}
}

void AddLecturerFromImport(lecturer*& ltr, int& nlecturer, lecturer &NewLecturer)
{
	char tmp[100];
	lecturer* NewltrList = new lecturer[nlecturer + 1];
	for (int i = 0; i < nlecturer; i++)
	{
		strcpy(tmp, ltr[i].user);
		NewltrList[i].user = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].user, tmp);
		strcpy(tmp, ltr[i].fullname);
		NewltrList[i].fullname = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].fullname, tmp);
		strcpy(tmp, ltr[i].pass);
		NewltrList[i].pass = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].pass, tmp);
		strcpy(tmp, ltr[i].title);
		NewltrList[i].title = new char[strlen(tmp) + 1];
		strcpy(NewltrList[i].title, tmp);
		NewltrList[i].sex = ltr[i].sex;
	}
	strcpy(tmp, NewLecturer.fullname);
	NewltrList[nlecturer].fullname = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].fullname, tmp);
	strcpy(tmp, NewLecturer.user);
	NewltrList[nlecturer].user = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].user, tmp);
	convertHash(tmp);
	NewltrList[nlecturer].pass = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].pass, tmp);
	NewLecturer.pass = new char[strlen(tmp) + 1];
	strcpy(NewLecturer.pass, tmp);
	strcpy(tmp, NewLecturer.title);
	NewltrList[nlecturer].title = new char[strlen(tmp) + 1];
	strcpy(NewltrList[nlecturer].title, tmp);
	NewltrList[nlecturer].sex= NewLecturer.sex  ;
	for (int i = 0; i < nlecturer; i++)
	{
		delete[] ltr[i].fullname;
		delete[] ltr[i].pass;
		delete[] ltr[i].title;
		delete[] ltr[i].user;
	}
	if (nlecturer > 0)
	{
		delete[] ltr;
	}
	nlecturer++;
	ltr = NewltrList;
}

void importCourse()
{
	Semester* SemesterList;
	Course* Schedule;
	ifstream input;
	char temp[MAX],*pch;
	char ScheduleFile[50], ClassID[10];
	string importFile;
	int nsemester, ncourse=0;
	LoadSemester(nsemester, SemesterList);
	cin.ignore(100, '\n');
	cout << "Enter class of new course: ";
	cin.getline(ClassID, 10, '\n');
	GetScheduleFile(ScheduleFile, SemesterList, ClassID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	cout << "Enter CSV path :";
	cin >> importFile;
	input.open(importFile.c_str());
	if (!fileHasData(input) ){
		cout << "Can't open " << importFile;
		return ;
	}
	input.getline(temp, MAX);
	while (input.getline(temp, MAX))
	{
		char importID[MAX], importName[MAX], importCclass[MAX], importRoom[MAX],tempDBeg[MAX];
		lecturer importLtr;
		ptime importStart, importEnd;
		date importBeginD;
		int importDOTW;
		pch = strtok(temp, ",");
		pch = strtok(NULL, ",");
		strcpy(importID, pch);
		pch = strtok(NULL, ",");
		strcpy(importName, pch);
		pch = strtok(NULL, ",");
		strcpy(importCclass, pch);
		pch = strtok(NULL, ",");
		importLtr.user = new char[strlen(pch) + 1];
		strcpy(importLtr.user, pch);
		pch = strtok(NULL, ",");
		importLtr.fullname = new char[strlen(pch) + 1];
		strcpy(importLtr.fullname, pch);
		pch = strtok(NULL, ",");
		importLtr.title = new char[strlen(pch) + 1];
		strcpy(importLtr.title, pch);
		pch = strtok(NULL, ",");
		if (strcmp(pch, "Male") == 0) importLtr.sex = 0;
		else importLtr.sex = 1;
		pch = strtok(NULL, ",");
		strcpy(tempDBeg, pch);
		pch = strtok(NULL, ",");
		pch = strtok(NULL, ",");
		importDOTW = convertStringDOTW(pch);
		pch = strtok(NULL, ",");
		importStart.hour = atoi(pch);
		pch = strtok(NULL, ",");
		importStart.minute = atoi(pch);
		pch = strtok(NULL, ",");
		importEnd.hour = atoi(pch);
		pch = strtok(NULL, ",");
		importEnd.minute = atoi(pch);
		pch = strtok(NULL, ",");
		strcpy(importRoom, pch);
		pch = strtok(tempDBeg, "/");
		importBeginD.day=atoi(pch);
		pch = strtok(NULL, "/");
		importBeginD.month = atoi(pch);
		pch = strtok(NULL, "/");
		importBeginD.year = atoi(pch);
		AddCourseImported(Schedule, ncourse, ClassID, SemesterList, importID, importName, importLtr, importCclass, importRoom, importBeginD, importDOTW, importStart, importEnd);
		delete[] importLtr.fullname;
		delete[] importLtr.title;
		delete[] importLtr.user;
	}

	SaveSchedule(ScheduleFile, Schedule, ncourse);
	DeleteSemesterList(SemesterList, nsemester);
	DeleteSchedule(Schedule, ncourse);
	input.close();
	cout << "\nImport courses from " << importFile << " successfully" << endl;
}

int convertStringDOTW(char* pch)
{
	if (strcmp(pch, "SUN") == 0) return 1;
	if (strcmp(pch, "MON")==0) return 2;
	if (strcmp(pch, "TUS") == 0) return 3;
	if (strcmp(pch, "WED") == 0) return 4;
	if (strcmp(pch, "THU") == 0) return 5;
	if (strcmp(pch, "FRI") == 0) return 6;
	if (strcmp(pch, "SAT") == 0) return 7;

}

//cau 18
void removeStudentfromCourse() {
	int ncourse, nsemester, ncheck, choice, choice2;
	char ScheduleFile[50], CourseFile[50], ClassID[10], CourseID[10];
	Semester* semlist;
	Course* Schedule;
	checkIn* CheckList;

	cout << "Remove a student from course" << endl;
	cout << "Enter class ID:";
	cin.getline(ClassID, 10, '\n');
	cin.getline(ClassID, 10, '\n');


	LoadSemester(nsemester, semlist);
	SaveSemester(nsemester, semlist);

	GetScheduleFile(ScheduleFile, semlist, ClassID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	SaveSchedule(ScheduleFile, Schedule, ncourse);

	cout << "\nList of course" << endl;
	for (int i = 0; i < ncourse; i++) {
		cout << i << "-" << Schedule[i].courseID << endl;
	}

	cout << "Enter your choice:";
	cin >> choice;

	strcpy(CourseID, Schedule[choice].courseID);
	GetCourseFile(CourseFile, semlist, ClassID, CourseID);
	LoadCheckList(CheckList, ncheck, CourseFile);

	char ID[10];
	cout << "Enter student ID:";
	cin.get();
	cin.getline(ID, 10, '\n');


	for (int i = 0; i < ncheck; i++) {
		if (atoi(ID) == atoi(CheckList[i].check->user)) {
			cout << "Student ID:" << CheckList[i].check->user << endl;
			cout << "Student full name:" << CheckList[i].check->fullname << endl;
			cout << "Student day of birth:" << CheckList[i].check->dob.day << "-" << CheckList[i].check->dob.month << "-" << CheckList[i].check->dob.year << endl;

			cout << "Do you want to remove student from this course? 0 - No / 1 - Yes" << endl;
			cout << "Your choice:";
			cin >> choice2;

			if (choice2 == 1) {
				CheckList[i].courseStt = 0;
				cout << "Remove student from this course successfully!" << endl;
			}
			else {
				cout << "Cancel remove student from this course!" << endl;
			}
		}
	}
	SaveCheckList(CheckList, ncheck, CourseFile);

	DeleteSemesterList(semlist, nsemester);
	DeleteSchedule(Schedule, ncourse);
	DeleteCheckIn(CheckList, ncheck);
}

//cau 31, 33
void editattendance() {
	int ncourse = 0, nsemester = 0, ncheck = 0, choice, choice2;
	char ScheduleFile[50], CourseFile[50], ClassID[10], CourseID[10];
	Semester* semlist;
	Course* Schedule;
	checkIn* CheckList;

	cout << "Editting attendance" << endl;
	cout << "Enter class ID:";
	cin.getline(ClassID, 10, '\n');
	cin.getline(ClassID, 10, '\n');

	LoadSemester(nsemester, semlist);
	if (nsemester == 0)
	{
		cout << "Semester list is empty\n";
		return;
	}

	GetScheduleFile(ScheduleFile, semlist, ClassID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	if (ncourse == 0)
	{
		cout << "Schedule is empty\n";
		DeleteSemesterList(semlist, nsemester);
		return;
	}

	cout << "\nList of course" << endl;
	for (int i = 0; i < ncourse; i++) {
		cout << i << "-" << Schedule[i].courseID << endl;
	}

	cout << "Enter your choice:";
	cin >> choice;

	strcpy(CourseID, Schedule[choice].courseID);
	GetCourseFile(CourseFile, semlist, ClassID, CourseID);
	LoadCheckList(CheckList, ncheck, CourseFile);
	if (ncheck == 0)
	{
		cout << "Check list is empty\n";
		DeleteSchedule(Schedule, ncourse);
		DeleteSemesterList(semlist, nsemester);
		return;
	}

	char ID[10];
	cout << "Enter student ID:";
	cin.get();
	cin.getline(ID, 10, '\n');


	for (int i = 0; i < ncheck; i++) {
		if (strcmp(CheckList[i].check->user, ID) == 0) {
			cout << "Student full name:" << CheckList[i].check->fullname << endl;
			cout << " Attendance " << endl;
			cout << "Year" << '\t' << "Month" << '\t' << "Day" << '\t' << "Start hour" << '\t' << "Start minute" << '\t' << "End hour" << '\t' << "End minute" << '\t' << "Attendace status" << '\n';

			for (int j = 0; j < 10; j++) {
				cout << CheckList[i].prd[j].d.year << '\t' << CheckList[i].prd[j].d.month << '\t' << CheckList[i].prd[j].d.day << '\t'
					<< CheckList[i].prd[j].start.hour << '\t' << '\t' << CheckList[i].prd[j].start.minute << '\t' << '\t' <<
					CheckList[i].prd[j].finish.hour << '\t' << '\t' << CheckList[i].prd[j].finish.minute << '\t' << '\t' << CheckList[i].prd[j].checkin << '\n';
			}

			cout << "Do you want to edit this student attendance? 0 - No / 1 - Yes" << endl;
			cout << "Your choice:";
			cin >> choice2;

			if (choice2 == 1) {
				for (int j = 0; j < 10; j++) {
					cout << CheckList[i].prd[j].d.year << "-" << CheckList[i].prd[j].d.month << "-" << CheckList[i].prd[j].d.day << " check in :";
					cin >> CheckList[i].prd[j].checkin;
				}
				cout << "Edit student attendance successfully!" << endl;
			}
			else {
				cout << "Cancel edit student attendance!" << endl;
			}
		}
	}
	SaveCheckList(CheckList, ncheck, CourseFile);
	DeleteSemesterList(semlist, nsemester);
	DeleteSchedule(Schedule, ncourse);
	DeleteCheckIn(CheckList, ncheck);
}

void editscoreboard() {
	int ncourse = 0, nsemester = 0, ncheck = 0, choice, choice2;
	char ScheduleFile[50], CourseFile[50], ClassID[10], CourseID[10];
	Semester* semlist;
	Course* Schedule;
	checkIn* CheckList;

	cout << "Editting scoreboard" << endl;
	cout << "Enter class ID:";
	cin.getline(ClassID, 10, '\n');
	cin.getline(ClassID, 10, '\n');

	LoadSemester(nsemester, semlist);
	if (nsemester == 0)
	{
		cout << "Semester list is empty\n";
		return;
	}

	GetScheduleFile(ScheduleFile, semlist, ClassID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	if (ncourse == 0)
	{
		cout << "Schedule is empty\n";
		DeleteSemesterList(semlist, nsemester);
		return;
	}

	cout << "\nList of course" << endl;
	for (int i = 0; i < ncourse; i++) {
		cout << i << "-" << Schedule[i].courseID << endl;
	}

	cout << "Enter your choice:";
	cin >> choice;

	strcpy(CourseID, Schedule[choice].courseID);
	GetCourseFile(CourseFile, semlist, ClassID, CourseID);
	LoadCheckList(CheckList, ncheck, CourseFile);
	if (ncheck == 0)
	{
		cout << "Check list is empty\n";
		DeleteSchedule(Schedule, ncourse);
		DeleteSemesterList(semlist, nsemester);
		return;
	}

	char ID[10];
	cout << "Enter student ID:";
	cin.get();
	cin.getline(ID, 10, '\n');


	for (int i = 0; i < ncheck; i++) {
		if (strcmp(CheckList[i].check->user, ID) == 0) {
			cout << "Student ID:" << CheckList[i].check->user << endl;
			cout << "Student full name:" << CheckList[i].check->fullname << endl;
			cout << " Score board" << endl;
			cout << "Midterm" << '\t' << "Final" << '\t' << "Bonus" << '\t' << "Total" << '\n';
			cout << CheckList[i].midterm << '\t' << CheckList[i].final << '\t' << CheckList[i].bonus << '\t' << CheckList[i].total << '\n';

			cout << "Do you want to edit this student's score board? 0 - No / 1 - Yes" << endl;
			cout << "Your choice:";
			cin >> choice2;

			if (choice2 == 1) {
				cout << "New Midterm:";
				cin >> CheckList[i].midterm;
				cout << "New Final:";
				cin >> CheckList[i].final;
				cout << "New Bonus:";
				cin >> CheckList[i].bonus;
				cout << "New Total:";
				cin >> CheckList[i].total;
				cout << "Edit student scoreboard successfully!" << endl;
			}
			else {
				cout << "Cancel edit student scoreboard!" << endl;
			}
		}
	}
	SaveCheckList(CheckList, ncheck, CourseFile);

	DeleteSemesterList(semlist, nsemester);
	DeleteSchedule(Schedule, ncourse);
	DeleteCheckIn(CheckList, ncheck);
}