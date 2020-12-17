#include<iostream>
#include<string.h>
#include<iomanip>
#include <windows.h>
using namespace std;

struct student  
{
	char name[50]; 
    int matNo;
    char nameMom[50];
    char nameDad[50];
    char course[50];
    int salaryM;
    int salaryD;
    int rsttype;
    double cgpa[5];
    double Avgcgpa;
    
};  
 
struct anc
{
	char name[50];
 	int matNo;
};
 
void inputData(student[], int, int);
void searchName(student[], int, char[], int, int);
void FindAnc(student [], int, int);
void searchCourse(student [], int, int, int&, int&);
int tIncome(student [], int, int);
void sorting(student [], int, int, int, int, int&, int&);
  
int main()
{
	student s[50];
 	anc list[50];
 	char search[50];
	int key, choice, user, numP, cs=0, at=0, b40, countR=0, countN=0, typeR;
	
	cout << "Press any key to start or 0 to exit: ";
	cin >> key;
	Sleep(100);
	system ("cls");
	
	while (key!=0)
	{
		cout << "\n\n\n\n\n\n \t\t                      Main Menu \n\n\n ";
		cout << "                                       User Type \n\n";
		cout << "                                       1. Admin \n";
		cout << "                                       2. User \n";
		cout << "                                       3. Exit from system \n\n\n";
		cout << "                                       Option: ";
		cin >> user;
		Sleep(200);
		system ("cls");
		
		if(user==1)
		{
			cout << "\n\n\n\n\n\n";
			cout << "                                   Hi admin!\n\n\n\n\n";
			cout << "                                   Please choose what you want to do: \n\n\n";
			cout << "                                   1. Search name of student\n";
			cout << "                                   2. Find ANC list \n";
			cout << "                                   3. Find number of students from CS110 and AT110 \n";
			cout << "                                   4. Find number of students from B40, M40, T20 \n";
			cout << "                                   5. Find list of students by type of resident \n";
			cout << "                                   6. Exit from system \n";
			cout << "\n\n                               Choice: ";
			cin >> choice;
			
			Sleep(200);
			system ("cls");
			
			if(choice==1)
			{
 				cout<<"Enter name of student to be searched : ";
 				cin.ignore();
 				cin.getline(search, 50);	
 				cout << endl << endl;
				searchName(s, 3, search, 50, numP);
			}
			
			else if(choice==2)
				FindAnc(s,3, numP);
				
			else if(choice==3)
			{
				searchCourse(s, 3, numP, cs, at);
				cout << endl << endl;
				
				cout << "THE NUMBER OF STUDENTS FROM CS110 : " << cs << endl;
				cout << "THE NUMBER OF STUDENTS FROM AT110 : " << at << endl;	
			}
			
			else if(choice==4)
			{
				b40=tIncome(s, 3, numP);
				cout << "TOTAL B40 CATEGORY : " << b40 << endl ;
			}
			
			else if(choice==5)
			{
				cout<<"Enter type of resident that you want to search (Resident[1] / Non-Resident[2]): "; 
				cin >> typeR;
				cout << endl;
				sorting(s, 3, numP, typeR, 20, countR, countN);
	
				cout<<endl;
				cout<<"Total number student that resident: "<<countR<<endl;
				cout<<"Total number student that non-resident: "<<countN<<endl;
			}
			
			else if(choice==6)
				cout << "Please press 0 to exit from our system. Thank you!\n";
				
			else 
				cout << "Please press 0 to exit from our system. Thank you!\n";
			
		}
		
		else if(user==2)
		{
			cout << "\n\n\n\n\n\n\n ";
			cout << "                                 Hello new user! \n\n\n\n";
			cout << "                            Enter the number on how many people that want to fill in the student's record: \n\n";
			cout << "                            P/S: Must not above 50 people. \n\n";
			cout << "                            Number of people: ";
			cin >> numP;
			Sleep(200);
			system ("cls");
			
			cout << "\n\n\n\n\n\n\n\n\n";
			cout << "                                     Please choose what you want to do: \n\n";
			cout << "                                     1. Input data\n";
			cout << "                                     2. Exit from system\n\n";
			cout << "                                     Choice: ";
			cin >> choice;
			
			system ("cls");
			
			if(choice==1)
			{
				inputData(s, 3, numP);
				cout << "Thank you for your cooperation!\n";
			}
			
			else if(choice==2)
				cout << " Please press 0 to exit from our system. Thank you!\n";
				
			else 
				cout << " Please press 0 to exit from our system. Thank you!\n";
	
 			cout << endl;
 			
		}
		
		else
			cout << "Please press 0 to exit from our system. Thank you!\n";
		
		cout << "\n\n\n";
		cout << "Press any key to continue to main menu or 0 to exit: ";
		cin >> key;
		system ("cls");
		
	}
	
	cout << "***************************Thank you for using our system! Have a nice day peeps :)*************************\n";
 	
 	
 	return 0;
}
 
void inputData(student s[], int sizeN, int numP)
{
 	for(int i=0; i<numP; i++)
 	{
 		cout << "Student " << i+1 << " record: \n";
 		cout << endl;
 		cin.ignore();
 		cout<<"ENTER FULL NAME                                        : ";
 		cin.getline(s[i].name,50);
 		
 		cout<<"ENTER MATRICS NUMBER                                   : ";
 		cin>>s[i].matNo;
 		cin.ignore();
 		
 		cout<<"ENTER MOTHER'S NAME                                    : ";
 		cin.getline(s[i].nameMom,50);
 		
 		cout<<"ENTER FATHER'S NAME                                    : ";
 		cin.getline(s[i].nameDad,50);
 		
 		cout<<"ENTER COURSE (CS110 / AT110)                           : ";
 		cin.getline(s[i].course,50);
 		
 		cout<<"ENTER MOTHER'S SALARY (RM)                             : ";
 		cin>>s[i].salaryM;
 		
 		cout<<"ENTER FATHER'S SALARY (RM)                             : ";
 		cin>>s[i].salaryD;
 		cin.ignore();
 		
 		cout<<"ENTER TYPE OF RESIDENT (RESIDENT[1] / NON RESIDENT[2]) : ";
 		cin >> s[i].rsttype;
 		
 		for(int j=0;j<5;j++)
 		{
 			cout<<"ENTER CGPA FOR SEMESTER " << j+1 << "                              : ";
 			cin>>s[i].cgpa[j];
		}
 		
 		cout << endl;
 		Sleep(400);
 		system ("cls");
 		
	 }
}
 
void searchName(student s[], int sizeN, char searchName[], int size1, int numP)
{
 	bool found=false;
 	int ind;
 	
 	for(int i=0; i<numP; i++)
 	{
 		
 		if(strcmpi(s[i].name, searchName)==0)
 		{
 			found=true;
 			ind=i;
		}
	}
	 
	if(found==true)
	{
	 	double Sumcgpa=0;
	 	
	 	cout<<"NAME                       : " << s[ind].name << endl;
	 	cout<<"MATRICS NUMBER             : " << s[ind].matNo << endl;
	 	
	 	for(int j=0;j<5;j++)
 		{ 
 			cout<<"CGPA FOR SEMESTER " << j+1 << "        : " << s[ind].cgpa[j] << endl;
 			Sumcgpa=Sumcgpa+s[ind].cgpa[j];
		}
	 	cout<<"TOTAL CGPA FOR 5 SEMESTERS : " <<Sumcgpa<<endl;
	}
	 
	else 
	{
	 	cout<<"ERROR! "<<endl;
	}
}
 
void FindAnc(student s[], int sizeN, int numP)
{
	double Avgcgpa;

   	cout<<"LIST OF VICE CHANSELLOR'S AWARDS"<<endl;
   	cout<<endl;
	cout<<"         _____________________________________________________________________________" << endl;
    cout<<"         |      NAME                  |      MATRIX NUMBER       |    AVERAGE CGPA   |" << endl;
	cout<<"         =============================================================================" << endl;
	
    for(int i=0;i<numP;i++)
 	{
	  	double Sumcgpa=0;
	  	
 		for(int j=0;j<5;j++)
 		{
 			Sumcgpa=Sumcgpa+s[i].cgpa[j];
 		}
 		
 		s[i].Avgcgpa=Sumcgpa/5;
 		
 		if(s[i].Avgcgpa>=3.5 && s[i].Avgcgpa<=4.0)                  
 		{
			cout << setw(20) << s[i].name << setw(30);
			cout << s[i].matNo << setw(25);
			cout << s[i].Avgcgpa<<endl;	
 			
		}
	}	
}

void searchCourse(student s[], int sizeN, int numP, int& cs, int& at)
{
	cout << "     LIST NAME STUDENTS FROM CS110 " << endl ;
	cout << "     ==============================" << endl ;
	for (int i=0; i<numP; i++)
	{
		if (strcmpi(s[i].course,"CS110")==0)
		{
			cout << "   - " << s[i].name << endl;
			cs++ ;
		}
	}
	cout << endl << endl;
	
	cout << "     LIST NAME STUDENTS FROM AT110 " << endl ;
	cout << "     ==============================" << endl ;
	for (int i=0; i<numP; i++)
	{
		if (strcmpi(s[i].course,"AT110")==0)
		{
			cout << "   - " << s[i].name << endl ;
			at++ ;
		}
	}
}

int tIncome(student s[], int sizeN, int numP)
{
	double total[numP]={0.00};
	int b40=0, t20=0, m40=0;
	for (int i=0; i<numP; i++)
	{
		total[numP] = (s[i].salaryM + s[i].salaryD)/2 ;
		if(total[numP] <= 3860.00)
			b40++;
		else if (total[numP] > 3860.00 && total[numP] <=8319.00)
			m40++;
		else if (total[numP] > 8319.00)
			t20++;
	
		cout << endl ;
	}
	cout << "TOTAL T20 CATEGORY : " << t20 << endl ;
	cout << "TOTAL M20 CATEGORY : " << m40 << endl ;
	
	return b40;
}

void sorting(student s[], int sizeN, int numP, int typeR, int size1, int&countR, int&countN)
{
	char temp[20];
	
	for(int pass = 1; pass<numP; pass++) 
	{
		for(int i = 0; i <numP-pass; i++)
		{
			if( strcmpi(s[i].name, s[i+1].name) > 0 )
			{
				strcpy(temp, s[i].name);
				strcpy(s[i].name, s[i+1].name);
				strcpy(s[i+1].name, temp);
			}
		}
	}
	
	countR=0, countN=0;
	
	for(int i=0; i<numP; i++)
	{
		if(s[i].rsttype==1)
			countR++;
		
		else if(s[i].rsttype==2)
			countN++;	
	}
	
	if(typeR==1)
	{
		cout << "List name of student live as resident: \n\n";
		cout<<"            ___________________________________________________________________________________________"<<endl;
		cout<<"            |      ID NUMBER            |              NAMES                  |   TYPE OF RESIDENT    |"<<endl;
		cout<<"            ==========================================================================================="<<endl;
		
		for(int i = 0; i <numP; i++)
		{
				if(s[i].rsttype==1)
					cout << setw(20) << s[i].matNo << setw(30) << s[i].name << setw(30) << "Resident\n";
		}
	}

	else if(typeR==2)
	{
		cout << "List name of student live as non-resident: \n\n";
		cout<<"            ___________________________________________________________________________________________"<<endl;
		cout<<"            |      ID NUMBER            |          NAMES                   |     TYPE OF RESIDENT   |"<<endl;
		cout<<"            ==========================================================================================="<<endl;
		
		for(int i = 0; i <numP; i++)
		{
			if(s[i].rsttype==2)
				cout << setw(20) << s[i].matNo << setw(30) << s[i].name << setw(30) << "Non-Resident\n";
		}
	}
	
	else
		cout << "There's no record about that!\n";
}


       		 
