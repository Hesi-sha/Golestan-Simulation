#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;
void TeacherFunctions();
void StusentFunctions(int id);
void ShowLessons(char [][20], int num);
void IdCheck();
void exit();
void UserBack();

struct Students{
    char StudentFirstName[20];
    char StudentLastName[20];
    int StudentID;
    int StudentYear;
    int NumOfLessons;
    bool GradeCheck1= false;
    bool GradeCheck2= false;
    bool GradeCheck3= false;
    bool GradeCheck4= false;
    bool GradeCheck5= false;
    double GPA=0;
    double lesson1grade,lesson2grade,lesson3grade,lesson4grade,lesson5grade;
};
const int num=5;
Students stu[num];
int one=0,two=0,three=0,four=0,five=0;
int FuncNum,LessonsNum=5,check;
char NameLessons[10][20];
char TeacherFirstName[20];
char TeacherLastName[20];
int Lesson1[10];
int Lesson2[10];
int Lesson3[10];
int Lesson4[10];
int Lesson5[10];
int TeacherID;

int main() {

    int choose,sign;
    int flag1=0,flag2=0;
    menu:
    cout << "\nChoose:\n(1) Signup\n(2) Login\n";
    cout<<"-----------------"<<endl;
    log:
    cout<<"Enter the number: "<<endl;
    cin>>choose;
    if (choose==1){
        ok:
        cout << "\nSignup as a:\n(1) Teacher\n(2) Students\n(0) Back\n";
        cout<<"-----------------"<<endl;
        cout<<"Enter the number: "<<endl;
        cin>>sign;

        if (sign==1){
            cout<<"-----------------------------"<<endl;
            cout<<"Enter the teacher first name: "<<endl;
            cin>>TeacherFirstName;
            cout<<"Enter the teacher last name: "<<endl;
            cin>>TeacherLastName;
            cout<<"Enter the teacher ID: "<<endl;
            cin>>TeacherID;
            flag1=1;
            UserBack();
            goto ok;
        }

        if (sign==2){
            cout<<"---------------------------------------"<<endl;
            for (int i = 0; i < num; ++i) {
                cout << "Enter the student "<< "number " << i+1 << " first name: " << endl;
                cin>>stu[i].StudentFirstName;
                cout << "Enter the student "<< "number " << i+1 << " last name: " << endl;
                cin>>stu[i].StudentLastName;
                cout << "Enter the student "<< "number " << i+1 << " ID: " << endl;
                cin >> stu[i].StudentID;
                cout << "Enter the student "<< "number " << i+1 << " Entry year: (96-97-98)" << endl;
                cin >> stu[i].StudentYear;
                cout<<"--------------------------------------------------"<<endl;
            }
            flag2=1;
            UserBack();
            goto ok;
        }

        if (sign==0)
            goto menu;
    }

    if (choose==2) {
        if (flag1 == 1 && flag2 == 1)
            IdCheck();
        if (flag1 == 0 && flag2 == 0) {
            cout << "You did not SIGNUP the teacher and students yet!\n";
            goto log;
        }
        if (flag1 == 1 && flag2 == 0) {
            cout << "You did not SIGNUP the students yet!\n";
            goto log;
        }
        if (flag1 == 0 && flag2 == 1) {
            cout << "You did not SIGNUP the teacher yet!\n";
            goto log;
        }
    }
    return 0;
}


void TeacherFunctions() {

    int x;
    Here:
    cout << "*******************************" << endl << "Welcome Professor " << TeacherFirstName<<" "<< TeacherLastName << endl<< "*******************************";
    cout << endl << endl << "[Teacher Guide]" << endl << "-------------------------------------------" << endl;
    cout << "Choose the NUMBER of your desired activity: " << endl;
    cout << "0. For Back to ID LOGIN." << endl;
    cout << "1. For enter the lessons." << endl;
    cout << "2. For enter the grade of students." << endl;
    cout << "3. For Check the entry year of students."<<endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter the number: " << endl;
    cin >> FuncNum;

    if (FuncNum == 0)
        IdCheck();

    if (FuncNum == 1) {
        cout << "Enter "<<LessonsNum<<" lessons for offer to students: " << endl;
        for (int i = 0; i < LessonsNum; ++i) {
            cout << "The lesson number " << i + 1 << " :" << endl;
            cin >> NameLessons[i];
        }
        exit();
        IdCheck();
    }

    if (FuncNum == 2) {
        grades:
        cout << endl <<"Choose the NUMBER of the lesson that you want to enter the grade of students: " << endl;
        ShowLessons(NameLessons, LessonsNum);
        cout << endl << "Enter '0' to Back!" << endl << endl;
        cout << "Enter the number: " << endl;
        cin >> x;
        if (x == 0)
            goto Here;

        if (x == 1) {
            for (int i = 0; i < one; ++i) {
                for (int j = 0; j < num; ++j) {
                    if (Lesson1[i] == stu[j].StudentID) {
                        cout << "Enter " << NameLessons[0] << " grade for Mr. " << stu[j].StudentFirstName << " "
                             << stu[j].StudentLastName << ": " << endl;
                        cin >> stu[j].lesson1grade;
                        stu[j].GradeCheck1=true;
                    }
                }
            }
            UserBack();
            goto grades;
        }

        if (x == 2) {
            for (int i = 0; i < two; ++i) {
                for (int j = 0; j < num; ++j) {
                    if (Lesson2[i] == stu[j].StudentID) {
                        cout << "Enter " << NameLessons[1] << " grade for Mr. " << stu[j].StudentFirstName << " "
                             << stu[j].StudentLastName << ": " << endl;
                        cin >> stu[j].lesson2grade;
                        stu[j].GradeCheck2=true;
                    }
                }
            }
            UserBack();
            goto grades;
        }

        if (x == 3) {
            for (int i = 0; i < three; ++i) {
                for (int j = 0; j < num; ++j) {
                    if (Lesson3[i] == stu[j].StudentID) {
                        cout << "Enter " << NameLessons[2] << " grade for Mr. " << stu[j].StudentFirstName << " "
                             << stu[j].StudentLastName << ": " << endl;
                        cin >> stu[j].lesson3grade;
                        stu[j].GradeCheck3=true;
                    }
                }
            }
            UserBack();
            goto grades;
        }

        if (x == 4) {
            for (int i = 0; i < four; ++i) {
                for (int j = 0; j < num; ++j) {
                    if (Lesson4[i] == stu[j].StudentID) {
                        cout << "Enter " << NameLessons[3] << " grade for Mr. " << stu[j].StudentFirstName << " "
                             << stu[j].StudentLastName << ": " << endl;
                        cin >> stu[j].lesson4grade;
                        stu[j].GradeCheck4=true;
                    }
                }
            }
            UserBack();
            goto grades;
        }

        if (x == 5) {
            for (int i = 0; i < five; ++i) {
                for (int j = 0; j < num; ++j) {
                    if (Lesson5[i] == stu[j].StudentID) {
                        cout << "Enter " << NameLessons[4] << " grade for Mr. " << stu[j].StudentFirstName << " "
                             << stu[j].StudentLastName << ": " << endl;
                        cin >> stu[j].lesson5grade;
                        stu[j].GradeCheck5=true;
                    }
                }
            }
            UserBack();
            goto grades;
        }
    }

    if (FuncNum == 3){
        int year,count1=1,count2=1,count3=1;
        over:
        cout<<endl<<"Enter your desired year(96-97-98) to show the list of entry students: "<<endl;
        cout << "or Enter '0' to Back!" << endl;
        cin>>year;
        cout<<endl;
        if (year==0)
            goto Here;

        if (year == 96){
            for (int i = 0; i < num; ++i) {
                if (stu[i].StudentYear==96){
                    cout<<"------------------"<<endl;
                    cout<<count1++<<". "<<stu[i].StudentFirstName<<" "<<stu[i].StudentLastName<<endl;
                    cout<<"------------------"<<endl;
                }
            }
            cout<<endl;
            UserBack();
            goto over;
        }

        if (year == 97){
            for (int i = 0; i < num; ++i) {
                if (stu[i].StudentYear==97){
                    cout<<"------------------"<<endl;
                    cout<<count2++<<". "<<stu[i].StudentFirstName<<" "<<stu[i].StudentLastName<<endl;
                    cout<<"------------------"<<endl;
                }
            }
            cout<<endl;
            UserBack();
            goto over;
        }

        if (year == 98){
            for (int i = 0; i < num; ++i) {
                if (stu[i].StudentYear==98){
                    cout<<"------------------"<<endl;
                    cout<<count3++<<". "<<stu[i].StudentFirstName<<" "<<stu[i].StudentLastName<<endl;
                    cout<<"------------------"<<endl;
                }
            }
            cout<<endl;
            UserBack();
            goto over;
        }
    }
}


void StusentFunctions(int id) {

    int numstu, x, numofless, lesson;
    for (int i = 0; i < num; ++i) {
        if (id == stu[i].StudentID)
            x = i;
    }

    user:
    cout << endl <<"******************************" << endl << " Welcome Mr. " << stu[x].StudentFirstName << " "<< stu[x].StudentLastName << endl << "******************************";
    cout << endl << endl << "[Student Guide]" << endl << "-------------------------------------------" << endl;
    cout << "Choose the NUMBER of your desired activity: " << endl;
    cout << "0. For Back to ID LOGIN." << endl;
    cout << "1. Show my profile." << endl;
    cout << "2. Show the lessons list for selecting." << endl;
    cout << "3. Show Report of grades." << endl;
    cout << "4. Show my FAILED lessons." << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter the number: " << endl;
    cin >> numstu;

    if (numstu == 0)
        IdCheck();

    if (numstu == 1) {
        cout<<endl<<"---------------------"<<endl;
        cout << "First name: " << stu[x].StudentFirstName << endl << "Last name: " << stu[x].StudentLastName << endl;
        cout << "ID: " << stu[x].StudentID << endl << "Entry year: " << stu[x].StudentYear << endl;
        cout << "---------------------" << endl <<endl;
        UserBack();
        goto user;
    }

    if (numstu == 2) {
        cout << "++++++++++++++" << endl;
        ShowLessons(NameLessons, LessonsNum);
        cout << "++++++++++++++" << endl;
        cout << "How many lessons do you want to select?" << endl;
        cin >> numofless;
        stu[x].NumOfLessons=numofless;
        for (int i = 0; i < numofless; ++i) {
            cout << "Enter the number of lesson " << i + 1 << " that you want:" << endl;
            cin >> lesson;
            if (lesson == 1)
                Lesson1[one++] = stu[x].StudentID;
            if (lesson == 2)
                Lesson2[two++] = stu[x].StudentID;
            if (lesson == 3)
                Lesson3[three++] = stu[x].StudentID;
            if (lesson == 4)
                Lesson4[four++] = stu[x].StudentID;
            if (lesson == 5)
                Lesson5[five++] = stu[x].StudentID;
        }
        UserBack();
        goto user;
    }

    if (numstu == 3) {
        stu[x].GPA=0;
        cout<<endl;
        if (stu[x].GradeCheck1 == true)
        { cout << NameLessons[0] << ": " << stu[x].lesson1grade << endl; stu[x].GPA+=stu[x].lesson1grade;}
        if (stu[x].GradeCheck2 == true)
        { cout << NameLessons[1] << ": " << stu[x].lesson2grade << endl; stu[x].GPA+=stu[x].lesson2grade;}
        if (stu[x].GradeCheck3 == true)
        { cout << NameLessons[2] << ": " << stu[x].lesson3grade << endl; stu[x].GPA+=stu[x].lesson3grade;}
        if (stu[x].GradeCheck4 == true)
        { cout << NameLessons[3] << ": " << stu[x].lesson4grade << endl; stu[x].GPA+=stu[x].lesson4grade;}
        if (stu[x].GradeCheck5 == true)
        { cout << NameLessons[4] << ": " << stu[x].lesson5grade << endl; stu[x].GPA+=stu[x].lesson5grade;}
        cout<<endl;
        cout<<"+------------+"<<endl;
        printf("| GPA: %.2f |",stu[x].GPA/stu[x].NumOfLessons);
        cout<<endl<<"+------------+"<<endl;
        cout<<endl;
        UserBack();
        goto user;
    }

    if (numstu == 4) {
        int fail=0;
        if (stu[x].GradeCheck1 == true && stu[x].lesson1grade<10)
            {cout << NameLessons[0] << ": " << stu[x].lesson1grade << " (Failed)" <<endl;  fail=1;}
        if (stu[x].GradeCheck2 == true && stu[x].lesson2grade<10)
            {cout << NameLessons[1] << ": " << stu[x].lesson2grade << " (Failed)" <<endl;  fail=1;}
        if (stu[x].GradeCheck3 == true && stu[x].lesson3grade<10)
            {cout << NameLessons[2] << ": " << stu[x].lesson3grade << " (Failed)" <<endl;  fail=1;}
        if (stu[x].GradeCheck4 == true && stu[x].lesson4grade<10)
            {cout << NameLessons[3] << ": " << stu[x].lesson4grade << " (Failed)" <<endl;  fail=1;}
        if (stu[x].GradeCheck5 == true && stu[x].lesson5grade<10)
            {cout << NameLessons[4] << ": " << stu[x].lesson5grade << " (Failed)" <<endl;  fail=1;}
        if (fail==0)
            cout<<"Congratulations:) You have no failed lesson!"<<endl;
        cout<<endl;
        UserBack();
        goto user;
    }
}


void exit(){
    cout << "Enter '0' to Exit!" << endl;
    do {
        cin >> check;
        if (check != 0)
            cout << "Enter '0' to Exit!" << endl;
    } while (check != 0);
}


void UserBack(){
    cout<<"Enter '0' to Back!"<<endl;
    do {
        cin>>check;
        if (check!=0)
            cout<<"Enter '0' to Back!"<<endl;
    }while (check!=0);
}


void ShowLessons(char lessons[][20], int num) {
    char les[20];
    for (int i = 0; i < num; ++i) {
        strcpy(les, lessons[i]);
        cout << i + 1 << ". " << les << endl;
    }
}


void IdCheck(){
    int ID;
    string id;
    cout<<endl<<"                 **********"<<endl<<"                  Welcome!"<<endl<<"                 **********";
    cout<<endl<<endl<<"Please enter your ID: "<<"\t";
    cout<<"or Enter '0' to EXIT!"<<endl;
    cin>>ID;
    if (ID == 0){
        cout<<"Are you sure you wanna lEAVE?  Write[Yes or No]"<<endl;
        cin>>id;
        if (id=="Yes" || id=="YES" || id=="yes") {
            cout<<endl<<"+----------------+";
            cout << endl << "| GOOD BYE... =) |" << endl;
            cout<<"+----------------+"<<endl;
            getch();
            exit(0);
        }
        else
            IdCheck();
    }
    else {
        if (ID == TeacherID)
            TeacherFunctions();
        else
            StusentFunctions(ID);
    }
}