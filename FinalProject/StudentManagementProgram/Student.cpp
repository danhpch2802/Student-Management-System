#include "startup.h"

struct Class
{
	char* classID;
};

void LoadClassesList(Class*& ClassList, int& nclass)
{
	ifstream fin;
	fin.open("Class.txt");
	if (!fin.is_open() || !fileHasData(fin))
	{
		fin.close();
		return;
	}
	char temp[100];
	fin >> nclass;
	ClassList = new Class[nclass];
	fin.getline(temp, 100, '\n');
	for (int i = 0; i < nclass; i++)
	{
		fin.getline(temp, 100, '\n');
		ClassList[i].classID = new char[strlen(temp) + 1];
		strcpy(ClassList[i].classID, temp);
	}
	fin.close();
}

void PrintDayOfWeek(int a)
{
	switch (a)
	{
	default:
		break;
	case 1:
	{
		cout << "Sunday ";
		break;
	}
	case 2:
	{
		cout << "Monday ";
		break;
	}
	case 3:
	{
		cout << "Tuesday ";
		break;
	}
	case 4:
	{
		cout << "Wednesday ";
		break;
	}
	case 5:
	{
		cout << "Thursday ";
		break;
	}
	case 6:
	{
		cout << "Friday ";
		break;
	}
	case 7:
	{
		cout << "Saturday ";
		break;
	}
	}
}



// cau 38
void StudentViewScore(student* login)
{
	Semester* SemesterList;
	checkIn* CheckList;
	Course* Schedule;
	int nsemester = 0, ncheck = 0, ncourse = 0;
	char CourseFile[50], ScheduleFile[50], ClassID[10], CourseID[20], StudentID[10];
	LoadSemester(nsemester, SemesterList);
	if (nsemester == 0)
	{
		cout << "Semester list is unavailable\n";
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
		cout << "The schedule of this class is unavailable\n";
		return;
	}
	LoadCheckList(CheckList, ncheck, CourseFile);
	if (ncheck == 0)
	{
		DeleteSchedule(Schedule, ncourse);
		DeleteSemesterList(SemesterList, nsemester);
		cout << "This course is unavailable\n";
		return;
	}
	if (CheckNewCourse(ncourse, Schedule, CourseID))
	{
		cout << "\nThis course does not exist";
	}
	else
	{
		if (!CheckStudentInCourse(CheckList, ncheck, login->user))
		{
			cout << "\nYou are not in this course";
		}
		else
		{
			for (int i = 0; i < ncheck; i++)
			{
				if (strcmp(CheckList[i].check->user, login->user) == 0)
				{
					cout << "\nYour score for this course:\nMidterm: " << CheckList[i].midterm << "\nFinal: "
						<< CheckList[i].final << "\nBonus: " << CheckList[i].bonus << "\nTotal: "
						<< CheckList[i].total << endl;
				}
			}
		}
	}
	DeleteSchedule(Schedule, ncourse);
	DeleteCheckIn(CheckList, ncheck);
	DeleteSemesterList(SemesterList, nsemester);
}


//cau 37
void StudentViewSchedule(student* login)
{
	cout << "Your schedule:\n\n";
	Semester* SemesterList;
	Class* ClassList;
	Course* Schedule;
	checkIn* CheckList;
	int nclass = 0, ncourse = 0, ncheck = 0, nsemester = 0;
	char ScheduleFile[50], CourseFile[50], SMT[20];
	LoadClassesList(ClassList, nclass);
	if (nclass == 0)
	{
		cout << "Class list is unavailable\n";
		return;
	}
	LoadSemester(nsemester, SemesterList);
	if (nsemester == 0)
	{
		if (nclass > 0)
		{
			for (int i = 0; i < nclass; i++)
			{
				delete[] ClassList[i].classID;
			}
			delete[] ClassList;
		}
		cout << "Semester list is unavailable\n";
		return;
	}
	strcpy(SMT, SemesterList->schoolyear);
	strcat(SMT, "-");
	strcat(SMT, SemesterList->smt);
	strcat(SMT, "-");
	for (int i = 0; i < nclass; i++)
	{
		strcpy(ScheduleFile, SMT);
		strcat(ScheduleFile, "Schedule-");
		strcat(ScheduleFile, ClassList[i].classID);
		strcat(ScheduleFile, ".txt");
		LoadSchedule(ScheduleFile, Schedule, ncourse);
		for (int j = 0; j < ncourse; j++)
		{
			strcpy(CourseFile, SMT);
			strcat(CourseFile, ClassList[i].classID);
			strcat(CourseFile, "-");
			strcat(CourseFile, Schedule[j].courseID);
			strcat(CourseFile, "-Student.txt");
			LoadCheckList(CheckList, ncheck, CourseFile);
			if (CheckStudentInCourse(CheckList, ncheck, login->user))
			{
				cout << "Course id: " << Schedule[j].courseID << endl;
				cout << "Course name: " << Schedule[j].courseName << endl;
				cout << "Time: ";
				PrintDayOfWeek(Schedule[j].dayofWeek);
				cout << Schedule[j].start.hour << ":" << Schedule[j].start.minute << "-"
					<< Schedule[j].finish.hour << ":" << Schedule[j].finish.minute << endl;
				cout << "Room: " << Schedule[j].room << endl << endl;
			}
			DeleteCheckIn(CheckList, ncheck);
			ncheck = 0;
		}
		DeleteSchedule(Schedule, ncourse);
		ncourse = 0;
	}
	if (nclass > 0)
	{
		for (int i = 0; i < nclass; i++)
		{
			delete[] ClassList[i].classID;
		}
		delete[] ClassList;
	}
	DeleteSemesterList(SemesterList, nsemester);
	DeleteSchedule(Schedule, ncourse);
	DeleteCheckIn(CheckList, ncheck);
}

void StudentViewCheckIn(student* login)
{
	Semester* SemesterList;
	checkIn* CheckList;
	Course* Schedule;
	int nsemester = 0, ncheck = 0, ncourse = 0;
	char CourseFile[50], ScheduleFile[50], ClassID[10], CourseID[20], StudentID[10];
	LoadSemester(nsemester, SemesterList);
	cout << "Enter class of course: ";
	cin.getline(ClassID, 10, '\n');
	cin.getline(ClassID, 10, '\n');
	cout << "Enter course Id: ";
	cin.getline(CourseID, 20, '\n');
	cout << endl;
	GetScheduleFile(ScheduleFile, SemesterList, ClassID);
	GetCourseFile(CourseFile, SemesterList, ClassID, CourseID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	LoadCheckList(CheckList, ncheck, CourseFile);
	if (CheckNewCourse(ncourse, Schedule, CourseID))
	{
		cout << "\nThis course does not exist";
	}
	else
	{
		if (!CheckStudentInCourse(CheckList, ncheck, login->user))
		{
			cout << "\nYou are not in this course";
		}
		else
		{
			for (int i = 0; i < ncheck; i++)
			{
				if (strcmp(CheckList[i].check->user, login->user) == 0)
				{
					for (int j = 0; j < 10; j++)
					{
						if (CheckList[i].prd[j].checkin == 1)
							cout << CheckList[i].prd[j].d.year << " " << CheckList[i].prd[j].d.month << " " << CheckList[i].prd[j].d.day << " : Present" << endl;
						else if(CheckList[i].prd[j].checkin == 0)
							cout << CheckList[i].prd[j].d.year << " " << CheckList[j].prd[i].d.month << " " << CheckList[i].prd[j].d.day << " : Absent" << endl;
						else 
							cout << CheckList[i].prd[j].d.year << " " << CheckList[i].prd[j].d.month << " " << CheckList[i].prd[j].d.day << " : " << endl;

					}
				}
			}
		}
	}
	for (int i = 0; i < nsemester; i++)
	{
		delete[]SemesterList[i].schoolyear;
		delete[]SemesterList[i].smt;
	}
	delete[]SemesterList;
	for (int i = 0; i < ncourse; i++)
	{
		delete[]Schedule[i].cClass;
		delete[]Schedule[i].courseID;
		delete[]Schedule[i].courseName;
		delete[]Schedule[i].ltr.fullname;
		delete[]Schedule[i].ltr.user;
		delete[]Schedule[i].ltr.title;
		delete[]Schedule[i].room;
	}
	delete[]Schedule;
	for (int i = 0; i < ncheck; i++)
	{
		deleteStudent(CheckList[i].check);
	}
	delete[]CheckList;
}

void StudentCheckIn(student* login)
{
	Semester* SemesterList;
	checkIn* CheckList;
	Course* Schedule;
	date dCur;
	ptime tCur;
	getCurrentDate(dCur, tCur);
	int curDate = dCur.day + distanceyear(dCur.year) + distancemonth(dCur.month, dCur.year);
	int curTime = calTime(tCur);
	int nsemester = 0, ncheck = 0, ncourse = 0;
	char CourseFile[50], ScheduleFile[50], ClassID[10], CourseID[20], StudentID[10];
	int flag = 0;
	LoadSemester(nsemester, SemesterList);
	cout << "Enter class of course: ";
	cin.getline(ClassID, 10, '\n');
	cin.getline(ClassID, 10, '\n');
	cout << "Enter course Id: ";
	cin.getline(CourseID, 20, '\n');
	cout << endl;
	GetScheduleFile(ScheduleFile, SemesterList, ClassID);
	GetCourseFile(CourseFile, SemesterList, ClassID, CourseID);
	LoadSchedule(ScheduleFile, Schedule, ncourse);
	LoadCheckList(CheckList, ncheck, CourseFile);
	if (CheckNewCourse(ncourse, Schedule, CourseID))
	{
		cout << "\nThis course does not exist";
	}
	else
	{
		if (!CheckStudentInCourse(CheckList, ncheck, login->user))
		{
			cout << "\nYou are not in this course";
		}
		else
		{
			for (int i = 0; i < ncheck; i++)
			{
				if (strcmp(CheckList[i].check->user, login->user) == 0)
				{
					for (int j = 0; j < 10; j++)
					{
						if (CheckList[i].prd[j].checkin != -1)
						{
							continue;
						}

						else
						{
							int checkDate = CheckList[i].prd[j].d.day + distanceyear(CheckList[i].prd[j].d.year) + distancemonth(CheckList[i].prd[j].d.month, CheckList[i].prd[j].d.year);
							int finTime = calTime(CheckList[i].prd[j].finish);
							int strtTime = calTime(CheckList[i].prd[j].start);
							if (curDate > checkDate)
							{
								CheckList[i].prd[j].checkin = 0;
								continue;
							}
							if (curDate == checkDate)
							{
								if (strtTime <= curTime && curTime<= finTime)
								{
									cout << "Check in successfully on " << CheckList[i].prd[j].d.year << " " << CheckList[i].prd[j].d.month << " " << CheckList[i].prd[j].d.day << endl;
									CheckList[i].prd[j].checkin = 1;
									flag = 1;
									break;
								}
								if ( curTime > finTime)
								{
									cout << "Check in unsuccessfully on " << CheckList[i].prd[j].d.year << " " << CheckList[i].prd[j].d.month << " " << CheckList[i].prd[j].d.day << endl;
									CheckList[i].prd[j].checkin = 0;
									break;
								}
								if (curTime < finTime)
								{
									cout << "Can't check in on " << CheckList[i].prd[j].d.year << " " << CheckList[i].prd[j].d.month << " " << CheckList[i].prd[j].d.day <<" yet"<<endl;
									break;
								}
							}
							

						}
					}
				}
			}
		}
	}
	if (flag==0)
	{
		cout << "No period of " << CourseID << " of " << ClassID << " on " << dCur.year << " " << dCur.month << " " << dCur.day << endl;;
	}
	SaveCheckList(CheckList, ncheck, CourseFile);
	for (int i = 0; i < nsemester; i++)
	{
		delete[]SemesterList[i].schoolyear;
		delete[]SemesterList[i].smt;
	}
	delete[]SemesterList;
	for (int i = 0; i < ncourse; i++)
	{
		delete[]Schedule[i].cClass;
		delete[]Schedule[i].courseID;
		delete[]Schedule[i].courseName;
		delete[]Schedule[i].ltr.fullname;
		delete[]Schedule[i].ltr.user;
		delete[]Schedule[i].ltr.title;
		delete[]Schedule[i].room;
	}
	delete[]Schedule;
	for (int i = 0; i < ncheck; i++)
	{
		deleteStudent(CheckList[i].check);
	}
	delete[]CheckList;
}

void getCurrentDate(date& dCur, ptime& tCur)
{
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);
	ti->tm_year;
	char temp[MAX];
	strcpy(temp, asctime(ti));
	char* pch;
	pch = strtok(temp, " ");
	pch = strtok(NULL, " ");
	dCur.month = getMonth(pch);
	pch = strtok(NULL, " ");
	dCur.day = atoi(pch);
	pch = strtok(NULL, " ");
	strcpy(temp, pch);
	pch = strtok(NULL, " ");
	dCur.year = atoi(pch);
	pch = strtok(temp, ":");
	tCur.hour = atoi(pch);
	pch = strtok(NULL, ":");
	tCur.minute = atoi(pch);
}

int getMonth(char* pch)
{
	if (strcmp(pch, "Jan") == 0) return 1;
	if (strcmp(pch, "Feb") == 0) return 2;
	if (strcmp(pch, "Mar") == 0) return 3;
	if (strcmp(pch, "Apr") == 0) return 4;
	if (strcmp(pch, "May") == 0) return 5;
	if (strcmp(pch, "Jun") == 0) return 6;
	if (strcmp(pch,"Jul") == 0) return 7;
	if (strcmp(pch, "Aug") == 0) return 8;
	if (strcmp(pch, "Sep") == 0) return 9;
	if (strcmp(pch, "Oct") == 0) return 10;
	if (strcmp(pch, "Nov") == 0) return 11;
	if (strcmp(pch, "Dec") == 0) return  12;
}

int distanceyear(int y)
{
	int year = 1900;
	int i;
	int k = 0;
	while (year <= (y - 1))
	{
		if (checkleap(year) == true)
		{
			i = 366;
		}
		else
		{
			i = 365;
		}
		k = (k + i);
		year++;
	}
	return k;
}

int distancemonth(int m, int y)
{
	int month = 1;
	int i = 0;
	int k = 0;
	while (month <= m)
	{
		switch ((month - 1))
		{
		case 0:
			i = 0;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			i = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			i = 30;
			break;
		case 2:
		{
			if (checkleap(y) == true)
				i = 29;
			else
				i = 28;
			break;
		}
		}
		k = k + i;
		month++;
	}
	return k;
}

int calTime(ptime cal)
{
	return cal.hour * 60 + cal.minute;
}