#include "startup.h"

void checkUser(char User[], char Pass[], int& status,int time)
{
	system("cls");
	studentManagementProgram();
	cout << "Username :";
	cin.getline(User, MAX);
	if(time>1) 	cin.getline(User, MAX);
	cout << "Password :";
	enterPass(Pass);
	convertHash(Pass);
	while (true)
	{
		staff* tempStaff = checkStaff(User, Pass, status);
		student* tempStudent = checkStudent(User, Pass, status);
		lecturer* tempLecturer = checkLecturer(User, Pass, status);
		if (tempStaff != nullptr)
		{
			deleteStaff(tempStaff);
			break;
		}
		if (tempLecturer != nullptr)
		{
			deleteLecturer(tempLecturer);
			break;
		}
		if (tempStudent != nullptr)
		{
			deleteStudent(tempStudent);
			break;
		}
		if (status == 0)
		{
			system("cls");
			studentManagementProgram();
			cout << "Invalid username/password" << endl;
			cout << "Username :";
			cin.getline(User, MAX);
			cout << "Password :";
			enterPass(Pass);
			convertHash(Pass);
		}
	}
}
staff* checkStaff( char User[], char Pass[],int &status)
{
	ifstream inputStaff;
	inputStaff.open("Staff.txt");
	if (!inputStaff.is_open())
	{
		cout << "Can't open file input";
		return nullptr;
	}
	else {
		int num;
		inputStaff >> num;
		// Scan data
		char CheckUser[MAX];
		char CheckPass[MAX];
		inputStaff.getline(CheckUser, MAX);
		inputStaff.getline(CheckUser, MAX);
		inputStaff.getline(CheckPass, MAX);
		if (strncmp(CheckUser, User, MAX) == 0 && strncmp(CheckPass, Pass, MAX) == 0)
		{
			char TempFullName[MAX];
			inputStaff.getline(TempFullName, MAX);
			int sex;
			inputStaff >> sex;
			status = 1;
			return createStaff(User, Pass, TempFullName, sex);;
		}
		for (int i = 1; i < num; i++) {
			inputStaff.ignore(MAX, '\n');
			inputStaff.ignore(MAX, '\n');
			inputStaff.ignore(MAX, '\n');
			inputStaff.getline(CheckUser, MAX);
			inputStaff.getline(CheckPass, MAX);
			if (strncmp(CheckUser, User, MAX) == 0 && strncmp(CheckPass, Pass, MAX) == 0)
			{
				char TempFullName[MAX];
				inputStaff.getline(TempFullName, MAX);
				int sex;
				inputStaff >> sex;
				status = 1;
				return createStaff(User, Pass, TempFullName, sex);;
			}
		}
	}
	inputStaff.close();
	return nullptr;
}

lecturer* checkLecturer(char User[],char Pass[],int &status)
{
	ifstream inputLecturer;
	inputLecturer.open("Lecturer.txt");
	if (!inputLecturer.is_open())
	{
		cout << "Can't open file input";
		return nullptr;
	}
	else {
		int num;
		inputLecturer >> num;
		// Scan data
		char CheckUser[MAX];
		char CheckPass[MAX];
		inputLecturer.getline(CheckUser, MAX);
		inputLecturer.getline(CheckUser, MAX);
		inputLecturer.getline(CheckPass, MAX);
		if (strncmp(CheckUser, User, MAX) == 0 && strncmp(CheckPass, Pass, MAX) == 0)
		{
			char TempFullName[MAX],TempTitle[MAX];
			inputLecturer.getline(TempFullName, MAX);
			inputLecturer.getline(TempTitle, MAX);
			int sex;
			inputLecturer >> sex;
			status = 2;
			return createLecturer(User,Pass,TempFullName,TempTitle,sex);
		}
		for (int i = 1; i < num; i++) {
			inputLecturer.ignore(MAX, '\n');
			inputLecturer.ignore(MAX, '\n');
			inputLecturer.ignore(MAX, '\n');
			inputLecturer.ignore(MAX, '\n');
			inputLecturer.getline(CheckUser, MAX);
			inputLecturer.getline(CheckPass, MAX);
			if (strncmp(CheckUser, User, MAX) == 0 && strncmp(CheckPass, Pass, MAX) == 0)
			{
				char TempFullName[MAX], TempTitle[MAX];
				inputLecturer.getline(TempFullName, MAX);
				inputLecturer.getline(TempTitle, MAX);
				int sex;
				inputLecturer >> sex;
				status = 2;
				return createLecturer(User, Pass, TempFullName, TempTitle, sex);
			}
		}
		inputLecturer.close();
		return nullptr;
	}
}

student* checkStudent(char User[], char Pass[], int& status)
{
	ifstream inputStudent;
	inputStudent.open("Student.txt");
	if (!inputStudent.is_open())
	{
		cout << "Can't open file input";
		return nullptr;
	}
	else {
		int num;
		inputStudent >> num;
		// Scan data
		char CheckUser[1000];
		char CheckPass[1000];
		inputStudent.getline(CheckUser, MAX);
		inputStudent.getline(CheckUser, MAX);
		inputStudent.getline(CheckPass, MAX);
		if (strncmp(CheckUser, User, MAX) == 0 && strncmp(CheckPass, Pass, MAX) == 0)
		{
			char TempFullName[MAX], TempClass[MAX];
			date TempDate;
			inputStudent.getline(TempFullName, MAX);
			inputStudent >> TempDate.year;
			inputStudent >> TempDate.month;
			inputStudent >> TempDate.day;
			inputStudent.getline(TempClass, MAX);
			inputStudent.getline(TempClass, MAX);
			int stdstatus;
			inputStudent >> stdstatus;
			if (stdstatus == 0)
			{
				return nullptr;
			}
			status = 3;
			return createStudent(User, Pass, TempFullName, TempDate, TempClass, stdstatus);
		}
		for (int i = 1; i < num; i++) {
			inputStudent.ignore(MAX, '\n');
			inputStudent.ignore(MAX, '\n');
			inputStudent.ignore(MAX, '\n');
			inputStudent.ignore(MAX, '\n');
			inputStudent.ignore(MAX, '\n');
			inputStudent.getline(CheckUser, MAX);
			inputStudent.getline(CheckPass, MAX);
			if (strncmp(CheckUser, User, MAX) == 0 && strncmp(CheckPass, Pass, MAX) == 0)
			{
				char TempFullName[MAX], TempClass[MAX];
				date TempDate;
				inputStudent.getline(TempFullName, MAX);
				inputStudent >> TempDate.year;
				inputStudent >> TempDate.month;
				inputStudent >> TempDate.day;
				inputStudent.getline(TempClass, MAX);
				inputStudent.getline(TempClass, MAX);
				int stdstatus;
				inputStudent >> stdstatus;
				if (stdstatus == 0)
				{
					return nullptr;
				}
				status = 3;
				return createStudent(User, Pass, TempFullName, TempDate, TempClass, stdstatus);
			}
		}
		inputStudent.close();
		return nullptr;
	}
}

staff* createStaff( char User[], char Pass[], char fullName[], int sex)
{
	staff *Login = new staff;
	Login->user = new char[strlen(User) + 1];
	Login->pass = new char[strlen(Pass) + 1];
	Login->fullname = new char[strlen(fullName) + 1];
	strcpy(Login->user, User);
	strcpy(Login->pass, Pass);
	strcpy(Login->fullname, fullName);
	Login->sex = sex;
	return Login;
}

lecturer *createLecturer(char User[], char Pass[], char fullName[],char Title[], int sex)
{
	lecturer* Login = new lecturer;
	Login->user = new char[strlen(User) + 1];
	Login->pass = new char[strlen(Pass) + 1];
	Login->fullname = new char[strlen(fullName) + 1];
	Login->title = new char[strlen(Title) + 1];
	strcpy(Login->user, User);
	strcpy(Login->pass, Pass);
	strcpy(Login->fullname, fullName);
	strcpy(Login->title, Title);
	Login->sex = sex;
	return Login;
}

student* createStudent(char ID[], char Pass[], char fullName[], date DOB,char StdClass[] ,int stdstatus)
{
	student* Login = new student;
	Login->user = new char[strlen(ID) + 1];
	Login->pass = new char[strlen(Pass) + 1];
	Login->fullname = new char[strlen(fullName) + 1];
	Login->stdclass = new char[strlen(StdClass) + 1];
	strcpy(Login->user, ID);
	strcpy(Login->pass, Pass);
	strcpy(Login->fullname, fullName);
	strcpy(Login->stdclass, StdClass);
	Login->dob.day = DOB.day;
	Login->dob.month = DOB.month;
	Login->dob.year = DOB.year;
	Login->status = stdstatus;
	return Login;
}