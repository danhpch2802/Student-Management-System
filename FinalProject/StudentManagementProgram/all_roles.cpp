#include "startup.h"

void viewProfileStaff(staff *Login)
{
	cout << "UserName :" << Login->user << endl;
	cout << "Full name :" << Login->fullname << endl;
	cout << "Sex :";
	if (Login->sex == 0) cout << "Male" << endl;
	else cout << "Female" << endl;
}

void viewProfileLecturer(lecturer* Login)
{
	cout << "UserName :" << Login->user << endl;
	cout << "Full name :" << Login->fullname << endl;
	cout << "Title :" << Login->title << endl;
	cout << "Sex :";
	if (Login->sex == 0) cout << "Male" << endl;
	else cout << "Female" << endl;
}

void viewProfileStudent(student* Login)
{
	cout << "UserName :" << Login->user << endl;
	cout << "Full name :" << Login->fullname << endl;
	cout << "DOB :" << Login->dob.year << " " << Login->dob.month << " " << Login->dob.day << endl;
	cout << "Class :" << Login->stdclass << endl;
	cout << "Status :";
	if (Login->status != 0) cout << "Active" << endl;
	else cout << "Inactive" << endl;
}

void deleteStaff(staff*& Login)
{
	delete[]Login->user;
	delete[]Login->fullname;
	delete[]Login->pass;
	delete Login;
}

void deleteLecturer(lecturer*& Login)
{
	delete[]Login->user;
	delete[]Login->fullname;
	delete[]Login->pass;
	delete[]Login->title;
	delete Login;
}

void deleteStudent(student*& Login)
{
	delete[]Login->user;
	delete[]Login->fullname;
	delete[]Login->pass;
	delete[]Login->stdclass;
	delete Login;
}

staff* changePassStaff(staff*& Login)
{
	char tempPass[MAX], tempPass1[MAX], tempPass2[MAX];
	while (true)
	{
		cout << "Enter old password :";
		enterPass(tempPass);
		convertHash(tempPass);
		if (strcmp(tempPass, Login->pass) != 0) cout << "\nOld password entered incorrectly" << endl;
		else break;
	};
	while (true) {
		cout << "\nEnter new password :";
		enterPass(tempPass1);
		convertHash(tempPass1);

		cout << "\nConfirm new password:";
		enterPass(tempPass2);
		convertHash(tempPass2);

		if (strcmp(tempPass1, tempPass2) != 0) cout << "\nNew Password and confirmed new password is different" << endl;
		else if (strcmp(tempPass, tempPass1) == 0) cout << "\nNew Password must different from old password" << endl;
		else break;
	};
	saveStaffNewPass(Login,tempPass1);
	delete[]Login->pass;
	Login->pass = new char[strlen(tempPass1) + 1];
	strcpy(Login->pass, tempPass1);
	return Login;
}

lecturer* changePassLecturer(lecturer*& Login)
{
	char tempPass[MAX], tempPass1[MAX], tempPass2[MAX];
	while (true)
	{
		cout << "Enter old password :";
		enterPass(tempPass);
		convertHash(tempPass);
		if (strcmp(tempPass, Login->pass) != 0) cout << "\nOld password entered incorrectly" << endl;
		else break;
	};
	while (true) {
		cout << "\nEnter new password :";
		enterPass(tempPass1);
		convertHash(tempPass1);

		cout << "\nConfirm new password:";
		enterPass(tempPass2);
		convertHash(tempPass2);

		if (strcmp(tempPass1, tempPass2) != 0) cout << "\nNew Password and confirmed new password is different" << endl;
		else if (strcmp(tempPass, tempPass1) == 0) cout << "\nNew Password must different from old password" << endl;
		else break;
	};
	saveLecturerNewPass(Login, tempPass1);
	delete[]Login->pass;
	Login->pass = new char[strlen(tempPass1) + 1];
	strcpy(Login->pass, tempPass1);
	return Login;
}

student* changePassStudent(student*& Login)
{
	char tempPass[MAX], tempPass1[MAX], tempPass2[MAX];
	while (true)
	{
		cout << "Enter old password :";
		enterPass(tempPass);
		convertHash(tempPass);
		if (strcmp(tempPass, Login->pass) != 0) cout << "\nOld password entered incorrectly" << endl;
		else break;
	};
	while (true) {
		cout << "\nEnter new password :";
		enterPass(tempPass1);
		convertHash(tempPass1);

		cout << "\nConfirm new password:";
		enterPass(tempPass2);
		convertHash(tempPass2);

		if (strcmp(tempPass1, tempPass2) != 0) cout << "\nNew Password and confirmed new password is different" << endl;
		else if (strcmp(tempPass, tempPass1) == 0) cout << "\nNew Password must different from old password" << endl;
		else break;
	};
	saveStudentNewPass(Login, tempPass1);
	delete[]Login->pass;
	Login->pass = new char[strlen(tempPass1) + 1];
	strcpy(Login->pass, tempPass1);
	return Login;
}

void saveStaffNewPass(staff* Login, char newPass[MAX])
{
	ifstream inputStaff;
	ofstream tempStaff;
	inputStaff.open("Staff.txt");
	tempStaff.open("temp.txt");
	if (!inputStaff.is_open() && !tempStaff.is_open())
	{
		cout << "Can't open file input";
		return;
	}
	else {
		int num;
		inputStaff >> num;
		// Scan data
		char CheckUser[MAX];
		char CheckPass[MAX];
		tempStaff << num << endl;
		for (int i = 0; i < num; i++) {
			inputStaff.getline(CheckUser, MAX);
			inputStaff.getline(CheckUser, MAX);
			inputStaff.getline(CheckPass, MAX);
			if (strncmp(CheckUser, Login->user, MAX) != 0)
			{
				char TempFullName[MAX];
				inputStaff.getline(TempFullName, MAX);
				int sex;
				inputStaff >> sex;
				tempStaff << CheckUser << endl;
				tempStaff << CheckPass << endl;
				tempStaff << TempFullName << endl;
				tempStaff << sex << endl;
				tempStaff << '\n';
				inputStaff.ignore(MAX, '\n');

			}
			else
			{
				inputStaff.ignore(MAX, '\n');
				inputStaff.ignore(MAX, '\n');
			}
		}
		inputStaff.close();
		tempStaff << Login->user << endl;
		tempStaff << newPass << endl;
		tempStaff << Login->fullname << endl;
		tempStaff << Login->sex << endl;
		tempStaff << '\n';
		tempStaff.close();
		remove("Staff.txt");
		rename("temp.txt", "Staff.txt");
	}
}

void saveLecturerNewPass(lecturer* Login, char newPass[MAX])
{
	ifstream inputLecturer;
	ofstream tempLecturer;
	inputLecturer.open("Lecturer.txt");
	tempLecturer.open("temp.txt");
	if (!inputLecturer.is_open() && !tempLecturer.is_open())
	{
		cout << "Can't open file input";
		return;
	}
	else {
		int num;
		inputLecturer >> num;
		// Scan data
		char CheckUser[MAX];
		char CheckPass[MAX];
		tempLecturer << num << endl;
		for (int i = 0; i < num; i++) {
			inputLecturer.getline(CheckUser, MAX);
			inputLecturer.getline(CheckUser, MAX);
			inputLecturer.getline(CheckPass, MAX);
			if (strncmp(CheckUser, Login->user, MAX) != 0)
			{
				char TempFullName[MAX];
				char TempTitle[MAX];
				inputLecturer.getline(TempFullName, MAX);
				inputLecturer.getline(TempTitle, MAX);
				int sex;
				inputLecturer >> sex;
				tempLecturer << CheckUser << endl;
				tempLecturer << CheckPass << endl;
				tempLecturer << TempFullName << endl;
				tempLecturer << TempTitle << endl;
				tempLecturer << sex << endl;
				tempLecturer << '\n';
				inputLecturer.ignore(MAX, '\n');

			}
			else
			{
				inputLecturer.ignore(MAX, '\n');
				inputLecturer.ignore(MAX, '\n');
				inputLecturer.ignore(MAX, '\n');
			}
		}
		inputLecturer.close();
		tempLecturer << Login->user << endl;
		tempLecturer << newPass << endl;
		tempLecturer << Login->fullname << endl;
		tempLecturer << Login->title<<endl;
		tempLecturer << Login->sex << endl;
		tempLecturer << '\n';
		tempLecturer.close();
		remove("Lecturer.txt");
		rename("temp.txt", "Lecturer.txt");
	}
}

void saveStudentNewPass(student* Login, char newPass[MAX])
{
	ifstream inputStudent;
	ofstream tempStudent;
	inputStudent.open("Student.txt");
	tempStudent.open("temp.txt");
	if (!inputStudent.is_open() && !tempStudent.is_open())
	{
		cout << "Can't open file input";
		return;
	}
	else {
		int num;
		inputStudent >> num;
		// Scan data
		char CheckUser[MAX];
		char CheckPass[MAX];
		tempStudent << num << endl;
		for (int i = 0; i < num; i++) {
			inputStudent.getline(CheckUser, MAX);
			inputStudent.getline(CheckUser, MAX);
			inputStudent.getline(CheckPass, MAX);
			if (strncmp(CheckUser, Login->user, MAX) != 0)
			{
				date TempDOB;
				char TempFullName[MAX],TempClass[MAX];
				inputStudent.getline(TempFullName, MAX);
				inputStudent >> TempDOB.year;
				inputStudent >> TempDOB.month;
				inputStudent >> TempDOB.day;
				inputStudent.getline(TempClass, MAX);
				inputStudent.getline(TempClass, MAX);
				int stdstatus;
				inputStudent >> stdstatus;
				tempStudent << CheckUser << endl;
				tempStudent << CheckPass << endl;
				tempStudent << TempFullName << endl;
				tempStudent << setfill('0') << setw(2) << TempDOB.year<<" "<< setfill('0') << setw(2) << TempDOB.month<<" "<< setfill('0') << setw(2) << TempDOB.day << endl;
				tempStudent << TempClass << endl;
				tempStudent << stdstatus << endl;
				tempStudent << '\n';
				inputStudent.ignore(MAX, '\n');
			}
			else
			{
				inputStudent.ignore(MAX, '\n');
				inputStudent.ignore(MAX, '\n');
				inputStudent.ignore(MAX, '\n');
				inputStudent.ignore(MAX, '\n');
			}
		}
		inputStudent.close();
		tempStudent << Login->user << endl;
		tempStudent << newPass << endl;
		tempStudent << Login->fullname << endl;
		tempStudent << setfill('0') << setw(2) << Login->dob.year<<" "<< setfill('0') << setw(2) << Login->dob.month<<" "<< setfill('0') << setw(2) << Login->dob.day << endl;
		tempStudent << Login->stdclass << endl;
		tempStudent << Login->status << endl;
		tempStudent << '\n';
		tempStudent.close();
		remove("Student.txt");
		rename("temp.txt", "Student.txt");
	}
}

void enterPass(char Pass[])
{
	int p = 0;
	char ch;
	while (true)
	{
		ch = _getch();
		if (ch == ENTER || ch == TAB)
		{
			Pass[p] = '\0';
			break;;
		}
		else if (ch == BKSP)
		{
			if (p > 0)
			{
				p--;
				cout << "\b \b";
			}
		}
		else
		{
			Pass[p++] = ch;
			cout << "* \b";
		}
	}
}