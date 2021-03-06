#include "startup.h"


void LoadClasses(int& nclass, ClassNode*& ClassList)
{
	ifstream fin;
	fin.open("Class.txt");
	if (!fin.is_open())
	{
		cout << "Cannot load list of classes" << endl;
	}
	else
	{
		fin >> nclass;
		ClassList = new ClassNode;
		fin >> ClassList->ClassId;
		ClassList->Next = nullptr;
		ClassNode* cur = ClassList;
		for (int i = 0; i < nclass - 1; i++)
		{
			cur->Next = new ClassNode;
			cur = cur->Next;
			fin >> cur->ClassId;
			cur->Next = nullptr;
		}
	}
	fin.close();
}

void DeleteAllClassNode(ClassNode*& pClass)
{
	ClassNode* tmp = pClass;
	while (pClass != nullptr)
	{
		pClass = pClass->Next;
		delete tmp;
		tmp = pClass;
	}
}

void DisplayClassList(int nclass, ClassNode* ClassList)
{
	cout << "List of classes: " << endl << endl;
	for (int i = 0; i < nclass; i++)
	{
		cout << i + 1 << " - " << ClassList->ClassId << endl;
		ClassList = ClassList->Next;
	}
}

void GetFileName(int ClassNumber, char FileName[])
{
	int nclass;
	ClassNode* ClassList = nullptr;
	LoadClasses(nclass, ClassList);
	ClassNode* cur = ClassList;
	for (int i = 1; i < ClassNumber; i++)
	{
		cur = cur->Next;
	}
	FileName = strcat(FileName, cur->ClassId);
	FileName = strcat(FileName, ".txt");
	DeleteAllClassNode(ClassList);
}

void LoadStudentsInClass(char FileName[], int& nstudent, StudentText*& StudentList)
{
	fstream fin(FileName);
	if (!fin.is_open())
	{
		nstudent = 0;
	}
	else
	{
		fin >> nstudent;
		StudentList = new StudentText[nstudent];
		char status[2];
		int i = 0;
		while (i < nstudent)
		{
			fin.getline(StudentList[i].ID, 10, '\n');
			fin.getline(StudentList[i].ID, 10, '\n');
			fin.getline(StudentList[i].Password, 50, '\n');
			fin.getline(StudentList[i].Name, 100, '\n');
			fin.getline(StudentList[i].DateOfBirth, 11, '\n');
			fin.getline(StudentList[i].Class, 10, '\n');
			fin.getline(status, 2, '\n');
			StudentList[i].Status = atoi(status);
			i++;
		}
	}
}

void DisplayStudentList(int nstudent, StudentText* StudentList)
{
	cout << endl << "List of students in class: " << endl << endl;
	for (int i = 0; i < nstudent; i++)
	{
		if (StudentList[i].Status != 0)
		{
			cout << "Id: " << StudentList[i].ID << endl;
			cout << "Fullname: " << StudentList[i].Name << endl;
			cout << "Date of birth: " << StudentList[i].DateOfBirth << endl;
			cout << endl;
		}
	}
}

void RemoveStudent(int nstudent, StudentText*& StudentList, int id)
{
	for (int i = 0; i < nstudent; i++)
	{
		if (atoi(StudentList[i].ID) == id && StudentList[i].Status != 0)
		{
			StudentList[i].Status = 0;
		}
	}
}

void SaveStudentList(char FileName[], int nstudent, StudentText* StudentList)
{
	ofstream fout;
	fout.open(FileName);
	if (!fout.is_open())
	{
		cout << "Cannot open output file" << endl;
	}
	else
	{
		fout << nstudent << endl;
		for (int i = 0; i < nstudent; i++)
		{
			fout << StudentList[i].ID << endl;
			fout << StudentList[i].Password << endl;
			fout << StudentList[i].Name << endl;
			fout << StudentList[i].DateOfBirth << endl;
			fout << StudentList[i].Class << endl;
			fout << StudentList[i].Status << endl << endl;
		}
	}
	fout.close();
}

bool CheckNewStudent(int nstudent, StudentText* StudentList, StudentText NewStudent)
{
	for (int i = 0; i < nstudent; i++)
	{
		if (atoi(StudentList[i].ID) == atoi(NewStudent.ID) && StudentList[i].ID != 0)
		{
			return false;
		}
	}
	return true;
}

void GetPassword(char password[], char dob[])
{
	int j = 0;
	for (int i = 0; i < strlen(dob); i++)
	{
		if (dob[i] != ' ')
		{
			password[j] = dob[i];
			j++;
		}
	}
	password[j] = '\0';
}

void GetClass(int ClassNumber, char Class[])
{
	int nclass;
	ClassNode* ClassList = nullptr;
	LoadClasses(nclass, ClassList);
	ClassNode* cur = ClassList;
	for (int i = 1; i < ClassNumber; i++)
	{
		cur = cur->Next;
	}
	strcpy(Class, cur->ClassId);
	DeleteAllClassNode(ClassList);
}

void AddStudent(int& nstudent, StudentText*& StudentList, StudentText NewStudent)
{
	StudentText* NewStudentList = new StudentText[nstudent + 1];
	for (int i = 0; i < nstudent; i++)
	{
		NewStudentList[i] = StudentList[i];
	}
	if(nstudent>0) delete[]StudentList;
	StudentList = NewStudentList;
	StudentList[nstudent] = NewStudent;
	nstudent++;
}



// cau 11
void ViewClassList()
{
	cout << endl;
	int nclass;
	ClassNode* ClassList = nullptr;
	LoadClasses(nclass, ClassList);
	DisplayClassList(nclass, ClassList);
	DeleteAllClassNode(ClassList);
}

// cau 12
void ViewStudentInClass()
{
	ViewClassList();
	char FileName[20] = "Student-";
	int ClassNumber, nstudent;
	StudentText* StudentList;
	cout << endl << "Select which class to view students list: ";
	cin >> ClassNumber;
	GetFileName(ClassNumber, FileName);
	LoadStudentsInClass(FileName, nstudent, StudentList);
	if (nstudent > 0)
	{
		DisplayStudentList(nstudent, StudentList);
		delete[] StudentList;
	}
}

// cau 9
void RemoveAStudent()
{
	ViewClassList();
	char FileName[20] = "Student-", StudentFile[12] = "Student.txt";
	int ClassNumber, nstudent = -1, allstudent = -1;
	StudentText* StudentList, * AllStudent;
	cout << endl << "Select which class to remove student from: ";
	cin >> ClassNumber;
	GetFileName(ClassNumber, FileName);
	LoadStudentsInClass(FileName, nstudent, StudentList);
	LoadStudentsInClass(StudentFile, allstudent, AllStudent);
	int id;
	int choice;
	cout << endl << "Id: ";
	cin >> id;
	if (nstudent > 0)
	{
		for (int i = 0; i < nstudent; i++)
		{
			if (atoi(StudentList[i].ID) == id && StudentList[i].Status != 0)
			{
				cout << "Fullname: " << StudentList[i].Name << endl;
				cout << "Date of birth: " << StudentList[i].DateOfBirth << endl;
				cout << endl << "Do you want to remove this student? ";
				cin >> choice;
				if (choice == 1)
				{
					StudentList[i].Status = 0;
					RemoveStudent(allstudent, AllStudent, id);
					cout << "Student has been removed";
				}
				else
				{
					cout << "Removal has been canceled";
				}
				SaveStudentList(FileName, nstudent, StudentList);
				SaveStudentList(StudentFile, allstudent, AllStudent);
				if (nstudent > 0)
				{
					delete[] StudentList;
				}
				if (allstudent > 0)
				{
					delete[] AllStudent;
				}
				return;
			}
		}
		cout << "Student does not exist";
		SaveStudentList(FileName, nstudent, StudentList);
		SaveStudentList(StudentFile, allstudent, AllStudent);
		if (nstudent > 0)
		{
			delete[] StudentList;
		}
		if (allstudent > 0)
		{
			delete[] AllStudent;
		}
	}
}

// cau 7
void AddStudentManually()
{
	cin.ignore(100,'\n');
	ViewClassList();
	char FileName[20] = "Student-", StudentFile[12] = "Student.txt";
	int ClassNumber, nstudent = -1, allstudent = -1;
	StudentText* StudentList, * AllStudent;
	cout << endl << "Select which class to add student: ";
	cin >> ClassNumber;
	GetFileName(ClassNumber, FileName);
	LoadStudentsInClass(FileName, nstudent, StudentList);
	LoadStudentsInClass(StudentFile, allstudent, AllStudent);
	StudentText NewStudent;
	cout << "Id: ";
	cin.ignore(100, '\n');
	cin.get(NewStudent.ID, 100, '\n');
	if (nstudent >= 0)
	{
		if (CheckNewStudent(allstudent, AllStudent, NewStudent))
		{
			cout << "Name: ";
			cin.ignore(100, '\n');
			cin.get(NewStudent.Name, 100, '\n');
			cout << "Date of birth (yyyy mm dd) : ";
			cin.ignore(100, '\n');
			cin.get(NewStudent.DateOfBirth, 11, '\n');
			GetPassword(NewStudent.Password, NewStudent.DateOfBirth);
			convertHash(NewStudent.Password);
			GetClass(ClassNumber, NewStudent.Class);
			NewStudent.Status = 1;
			AddStudent(allstudent, AllStudent, NewStudent);
			SaveStudentList(StudentFile, allstudent, AllStudent);
			AddStudent(nstudent, StudentList, NewStudent);
			SaveStudentList(FileName, nstudent, StudentList);
		}
		else
		{
			cout << "\nThis student is already in class\n";
		}
		if (nstudent > 0)
		{
			delete[] StudentList;
		}
		if (allstudent > 0)
		{
			delete[] AllStudent;
		}
	}
}

void importClass() 
{
	ifstream input;
	string fileName;
	char Class[MAX];
	char StudentClassFile[MAX] = "Student-", StudentFile[MAX] = "Student.txt";
	int nstudents = -1, allstudent = -1;
	StudentText* StudentList, * AllStudent, NewStudent;
	int num = 0;
	cout << "Class :";
	cin.getline(Class, MAX);
	cin.getline(Class, MAX);
	strcat(StudentClassFile, Class);
	strcat(StudentClassFile, ".txt");
	LoadStudentsInClass(StudentClassFile, nstudents, StudentList);
	LoadStudentsInClass(StudentFile, allstudent, AllStudent);
	cout << "CSV file path :";
	cin >> fileName;
	input.open(fileName.c_str());
	if (!input.is_open()) {
		cout << "Can't open " << fileName;
		return ;
	}
	char temp[MAX], * pch;
	input.getline(temp, MAX);
	while (input.getline(temp, MAX))
	{
		pch = strtok(temp, ",");
		pch = strtok(NULL, ",");
		strcpy(NewStudent.ID, pch);
		pch = strtok(NULL, ",");
		strcpy(NewStudent.Name, pch);
		pch = strtok(NULL, ",");
		strcpy(NewStudent.DateOfBirth, pch);
		strcpy(NewStudent.Class, Class);
		char tempDOB[MAX];
		char tempPass[MAX];
		strcpy(tempDOB, NewStudent.DateOfBirth);
		pch = strtok(tempDOB, "/");
		strcpy(tempPass, pch);
		strcpy(NewStudent.DateOfBirth, pch);
		strcat(NewStudent.DateOfBirth, " ");
		pch = strtok(NULL, "/");
		strcat(NewStudent.DateOfBirth, pch);
		strcat(NewStudent.DateOfBirth, " ");
		strcat(tempPass, pch);
		pch = strtok(NULL, "/");
		strcat(tempPass, pch);
		strcat(NewStudent.DateOfBirth, pch);
		strcpy(NewStudent.Password, tempPass);
		convertHash(NewStudent.Password);
		NewStudent.Status = 1;
		if (CheckNewStudent(allstudent, AllStudent, NewStudent))
		{
			AddStudent(allstudent, AllStudent, NewStudent);
			SaveStudentList(StudentFile, allstudent, AllStudent);
			if (nstudents != 0)
			{
				AddStudent(nstudents, StudentList, NewStudent);
				SaveStudentList(StudentClassFile, nstudents, StudentList);
			}
			else
			{
				StudentList = new StudentText[1];
				strcpy(StudentList[0].ID, NewStudent.ID);
				strcpy(StudentList[0].Name, NewStudent.Name);
				strcpy(StudentList[0].Password, NewStudent.Password);
				strcpy(StudentList[0].Class, NewStudent.Class);
				strcpy(StudentList[0].DateOfBirth, NewStudent.DateOfBirth);
				StudentList[0].Status = NewStudent.Status;
				++nstudents;
			}
			num++;
		}
		else
		{
			cout <<"\n"<<NewStudent.ID << " already existed" << endl;
		}
	}

	if (nstudents > 0)
	{
		delete[] StudentList;
	}
	if (allstudent > 0)
	{
		delete[] AllStudent;
	}
	cout << "\n" << num << " students imported successfully\n";
	input.close();
}

void editExisingStudent()
{
	ViewClassList();
	char FileName[20] = "Student-", StudentFile[12] = "Student.txt";
	int ClassNumber, nstudent = -1, allstudent = -1;
	StudentText* StudentList, * AllStudent;
	cout << endl << "Select which class to edit student from: ";
	cin >> ClassNumber;
	GetFileName(ClassNumber, FileName);
	LoadStudentsInClass(FileName, nstudent, StudentList);
	LoadStudentsInClass(StudentFile, allstudent, AllStudent);
	int id;
	int choice;
	cout << endl << "Id: ";
	cin >> id;
	if (nstudent > 0)
	{
		for (int i = 0; i < nstudent; i++)
		{
			if (atoi(StudentList[i].ID) == id && StudentList[i].Status != 0)
			{
				cin.ignore(MAX, '\n');
				cout << "\nEnter new pass :";
				enterPass(StudentList[i].Password);
				convertHash(StudentList[i].Password);
				cout << "\nEnter new name :";
				cin.getline(StudentList[i].Name, MAX);
				cout << "Enter new DOB (yyyy mm dd) :";
				cin.getline(StudentList[i].DateOfBirth, MAX);
				EditStudent(allstudent, AllStudent, id, StudentList[i].Password, StudentList[i].DateOfBirth, StudentList[i].Name);
				SaveStudentList(FileName, nstudent, StudentList);
				SaveStudentList(StudentFile, allstudent, AllStudent);
				cout << "\n" << StudentList[i].ID << " has been edited" << endl;
				if (nstudent > 0)
				{
					delete[] StudentList;
				}
				if (allstudent > 0)
				{
					delete[] AllStudent;
				}
				return;
			}
		}
		cout << "Student does not exist";
		SaveStudentList(FileName, nstudent, StudentList);
		SaveStudentList(StudentFile, allstudent, AllStudent);
		if (nstudent > 0)
		{
			delete[] StudentList;
		}
		if (allstudent > 0)
		{
			delete[] AllStudent;
		}
	}
}

//cau 10

void loadclassmoveinto(char FileName[], int& nstudent, StudentText*& StudentList) {
	fstream fin(FileName);
	if (!fin.is_open())
	{
		nstudent = 0;
	}
	else
	{
		fin >> nstudent;
		nstudent = nstudent + 1;
		StudentList = new StudentText[nstudent];
		char status[2];
		int i = 0;
		while (i < nstudent)
		{
			fin.getline(StudentList[i].ID, 10, '\n');
			fin.getline(StudentList[i].ID, 10, '\n');
			fin.getline(StudentList[i].Password, 50, '\n');
			fin.getline(StudentList[i].Name, 100, '\n');
			fin.getline(StudentList[i].DateOfBirth, 11, '\n');
			fin.getline(StudentList[i].Class, 10, '\n');
			fin.getline(status, 2, '\n');
			StudentList[i].Status = atoi(status);
			i++;
		}
	}
}

void Changestudentclass() {
	char FileName1[20] = "Student-", FileName2[20] = "Student-", StudentFile[12] = "Student.txt", clss[10];
	int ClassNumber, nstudent = -1, allstudent = -1, loaded = 0;
	StudentText* StudentList1, * StudentList2, * AllStudent;
	StudentText newstd;
	LoadStudentsInClass(StudentFile, allstudent, AllStudent);
	if (allstudent == 0)
	{
		cout << "Cannot load student list\n";
		return;
	}
	int id;
	cout << "ID: ";
	cin >> id;
	if (allstudent > 0)
	{
		for (int i = 0; i < allstudent; i++)
		{
			if (atoi(AllStudent[i].ID) == id && AllStudent[i].Status != 0)
			{
				cout << "Fullname: " << AllStudent[i].Name << endl;
				cout << "Class: " << AllStudent[i].Class << endl;
				cout << endl;
				ViewClassList();
				cout << "Which class current?";
				cout << "Enter your choice:";
				cin >> ClassNumber;
				GetFileName(ClassNumber, FileName1);
				LoadStudentsInClass(FileName1, nstudent, StudentList1);
				if (nstudent == 0)
				{
					cout << "Cannot load current student list\n";
					return;
				}
				for (int j = 0; j < nstudent; j++) 
				{
					if (atoi(StudentList1[j].ID) == id && StudentList1[j].Status != 0) {
						strcpy(newstd.ID, StudentList1[j].ID);
						strcpy(newstd.Name, StudentList1[j].Name);
						strcpy(newstd.Password, StudentList1[j].Password);
						strcpy(newstd.DateOfBirth, StudentList1[j].DateOfBirth);
						strcpy(newstd.Class, StudentList1[j].Class);
						newstd.Status = StudentList1[j].Status;
						StudentList1[j].Status = 0;
						loaded = 1;
					}
				}
				SaveStudentList(FileName1, nstudent, StudentList1);
				if (nstudent > 0)
				{
					delete[] StudentList1;
				}
				if (loaded == 0)
				{
					cout << "Student is not in this class\n";
					return;
				}
				cout << "Which class move into?" << endl;
				cout << "Enter your choice:";
				cin >> ClassNumber;
				cout << "Confirm name of the class:";
				cin.get();
				cin.getline(AllStudent[i].Class, MAX);
				GetFileName(ClassNumber, FileName2);
				loadclassmoveinto(FileName2, nstudent, StudentList2);
				cout << "moving\n";
				if (nstudent == 0)
				{
					nstudent = 1;
					StudentList2 = new StudentText[1];
				}
				StudentList2[nstudent - 1] = newstd;
				strcpy(StudentList2[nstudent - 1].Class, AllStudent[i].Class);
				StudentList2[nstudent - 1].Status = 1;
				cout << "moved";
				SaveStudentList(FileName2, nstudent, StudentList2);
				if (nstudent > 0)
				{
					delete[] StudentList2;
				}
				SaveStudentList(StudentFile, allstudent, AllStudent);
				if (allstudent>0)
				{
					delete[] AllStudent;
				}
				return;
			}
		}
	}
}

void EditStudent(int nstudent, StudentText*& StudentList, int id,char tempPass[],char tempDOB[],char tempName[])
{
	for (int i = 0; i < nstudent; i++)
	{
		if (atoi(StudentList[i].ID) == id && StudentList[i].Status != 0)
		{
			strcpy(StudentList[i].Password,tempPass) ;
			strcpy(StudentList[i].DateOfBirth, tempDOB);
			strcpy(StudentList[i].Name, tempName);
		}
	}
}