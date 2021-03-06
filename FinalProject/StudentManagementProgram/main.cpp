#include "startup.h"

int main()
{
	SetConsoleTitle(TEXT("Student Management System"));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE buff = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD sizeOfBuff;
	sizeOfBuff.X = 170;
	sizeOfBuff.Y = 100;
	SetConsoleScreenBufferSize(buff, sizeOfBuff);
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { SetWindowPos(hwnd, 0, 0, 0, 1000, 700, SWP_SHOWWINDOW | SWP_NOMOVE); }
	changeColor(11);
	loadingScreen();
	int status = 0, time = 0;
	int func;
	do {
		func = 1;
		if (time != 0) {
			system("cls");
			studentManagementProgram();
			cout << "1.Login\n0.Exit\nEnter function :";
			cin >> func;
		}
		if (func == 0)
		{
			return 0;
		}
		else if (func == 1)
		{
			++time;
			char User[MAX], Pass[MAX];
			checkUser(User, Pass, status, time);
			switch (status)
			{
			case 1:
			{
				staff* Login = checkStaff(User, Pass, status);
				do {
					system("cls");
					studentManagementProgram();
					cout << Login->fullname << "\n";
					cout << "1.Show menu\n2.View profile info\n3.Change password\n4.Logout" << endl;
					cout << "Choose function :";
					cin >> func;
					switch (func)
					{
					case 1:
						do {
							system("cls");
							menu();
							cout << "Functions:\n\n1.Import students\n2.Add student\n3.Edit student\n4.Remove student\n";
							cout << "5.Change student's class\n6.View list of classes\n7.View list of students in class\n";
							cout << "8.Create new semester\n9.Remove a course\n10.View attendance list\n11.View all lecturers\n";
							cout << "12.Add new course\n13.View all courses of a semester\n14.Import course\n15.View students of a course\n";
							cout << "16.View scoreboard of a course\n17.Export a scoreboard to CSV file\n18.Export attendance list to a CSV file\n";
							cout << "19.Remove specific student from a course\n20.Edit an existing course\n21.Add student to course\n0.Exit";
							cout << "\nChoose function :";
							cin >> func;
							switch (func)
							{
							case 1:
							{
								system("cls");
								menu();
								importClass();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 2:
							{
								system("cls");
								menu();
								AddStudentManually();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 3:
							{
								system("cls");
								menu();
								editExisingStudent();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 4:
							{
								system("cls");
								menu();
								RemoveAStudent();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 5:
							{
								system("cls");
								menu();
								Changestudentclass();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 6:
							{
								system("cls");
								menu();
								ViewClassList();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 7:
							{
								system("cls");
								menu();
								ViewStudentInClass();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 8:
							{
								system("cls");
								menu();
								CreateSemester();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 9:
							{
								system("cls");
								menu();
								deleteCourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 10:
							{
								system("cls");
								menu();
								viewAttendance();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 11:
							{
								system("cls");
								menu();
								viewAllLecturers();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 12:
							{
								system("cls");
								menu();
								AddNewCourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 13:
							{
								system("cls");
								menu();
								viewAllCoursesInASemester();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 14:
							{
								system("cls");
								menu();
								importCourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 15:
							{
								system("cls");
								menu();
								viewStudentsOfACourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 16:
							{
								system("cls");
								menu();
								viewScoreboardOfACourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 17:
							{
								system("cls");
								menu();
								exportScoreboardToCSV();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 18:
							{
								system("cls");
								menu();
								exportAttendanceToCSV();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 19:
							{
								system("cls");
								menu();
								removeStudentfromCourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 20:
							{
								system("cls");
								menu();
								editCourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 21:
							{
								system("cls");
								menu();
								AddNewStudentToCourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							}
						} while (func != 0);
						break;
					case 2:
					{
						system("cls");
						studentManagementProgram();
						viewProfileStaff(Login);
						cout << "\nPress Any Key to Continue\n";
						_getch();
						break;
					}
					case 3:
					{
						system("cls");
						studentManagementProgram();
						changePassStaff(Login);
						cout << "\nPress Any Key to Continue\n";
						_getch();
						break;
					}
					case 4:
					{
						system("cls");
						deleteStaff(Login);
						break;
					}
					}
				} while (func != 4);
				break;
			}
			case 2:
			{
				lecturer* Login = checkLecturer(User, Pass, status);
				do {
					system("cls");
					studentManagementProgram();
					cout << Login->fullname << "\n";
					cout << "1.Show menu\n2.View profile info\n3.Change password\n4.Logout" << endl;
					cout << "Choose function :";
					cin >> func;
					switch (func)
					{
					case 1:
						do {
							system("cls");
							menu();
							cout << "1.View attendance list of a course.\n2.View list of students of a course\n3.View scoreboard\n4.Import scoreboard from csv file\n5.Edit student attendance\n6.Edit student scoreboard\n0.Exit\n";
							cout << "\nChoose function :";
							cin >> func;
							switch (func)
							{
							case 1:
								system("cls");
								menu();
								viewAttendance();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							case 2:
								system("cls");
								menu();
								viewStudentsOfACourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							case 3:
								system("cls");
								menu();
								viewScoreboardOfACourse();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							case 4:
								system("cls");
								menu();
								importScoreboardFromCSV();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							case 5:
								system("cls");
								menu();
								editattendance();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							case 6:
								system("cls");
								menu();
								editscoreboard();
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
						} while (func != 0);
						break;
					case 2:
					{
						system("cls");
						studentManagementProgram();
						viewProfileLecturer(Login);
						cout << "\nPress Any Key to Continue\n";
						_getch();
						break;
					}
					case 3:
					{
						system("cls");
						studentManagementProgram();
						changePassLecturer(Login);
						cout << "\nPress Any Key to Continue\n";
						_getch();
						break;
					}
					case 4:
					{
						system("cls");
						deleteLecturer(Login);
						break;
					}
					}
				} while (func != 4);
				break;
			}
			case 3:
			{
				student* Login = checkStudent(User, Pass, status);
				do {
					system("cls");
					studentManagementProgram();
					cout << Login->fullname << "\n";
					cout << "1.Show menu\n2.View profile info\n3.Change password\n4.Logout" << endl;
					cout << "Choose function :";
					cin >> func;
					switch (func)
					{
					case 1:
						do {
							system("cls");
							menu();
							cout << "\n1.Check in\n2.View check in\n3.View schedule\n4.View score\n0.Exit\n";
							cout << "Choose function :";
							cin >> func;
							switch (func)
							{
							case 1:
							{
								system("cls");
								menu();
								StudentCheckIn(Login);
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 2:
							{
								system("cls");
								menu();
								StudentViewCheckIn(Login);
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 3:
							{
								system("cls");
								menu();
								system("cls");
								StudentViewSchedule(Login);
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							case 4:
							{
								system("cls");
								menu();
								system("cls");
								StudentViewScore(Login);
								cout << "\nPress Any Key to Continue\n";
								_getch();
								break;
							}
							}
						} while (func != 0);
						break;
					case 2:
					{
						system("cls");
						studentManagementProgram();
						viewProfileStudent(Login);
						cout << "\nPress Any Key to Continue\n";
						_getch();
						break;
					}
					case 3:
					{
						system("cls");
						studentManagementProgram();
						changePassStudent(Login);
						cout << "\nPress Any Key to Continue\n";
						_getch();
						break;
					}
					case 4:
					{
						system("cls");
						deleteStudent(Login);
						break;
					}
					}
				} while (func != 4);
				break;
			}
			}
		}
	} while (func != 0);

}