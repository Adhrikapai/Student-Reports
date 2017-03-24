#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
//***************************************************************
//                   CLASSES  USED IN PROJECT
//****************************************************************

class admission
{
	private:
		long int admnno;
		char f_name[50];
		char m_name[80];
		int f_no;
		int m_no;
		int hno;
		char hname[50];
		char landmark[50];
		char city[50];
		char state[50];
	public:
		void get()
		{
			cout<<"\nAdmission number: ";
			cin>>admnno;
			cout<<"\nFather's Name: ";
			gets(f_name);
			cout<<"\nMother's Name: ";
			gets(m_name);
			cout<<"\nFather's Phone Number: ";
			cin>>f_no;
			cout<<"\nMother's Phone Number: ";
			cin>>m_no;
			cout<<"\nAddress:\n";
			cin>>hno;
			gets(hname);
			gets(landmark);
			gets(city);
			gets(state);
		}
		void put()
		{
			cout<<"\nAdmission Number: "<<admnno
			    <<"\nFather's Name: "<<f_name
			    <<"\nMother's Name: "<<m_name
			    <<"\nFather's Phone Number: "<<f_no
			    <<"\nMother's Phone Number: "<<m_no
			    <<"\nAddress: \n"
			    <<hno<<"."<<hname<<"\n"<<landmark
			    <<"\n"<<city<<"\n"<<state;
		}
		int retadmno()
		{
			return admnno;
		}
}ad;                                                           
class student
{
	private:
		long int admnno;
		int rollno;
		char name[50];
		float p_marks,c_marks,m_marks,e_marks,cs_marks;
		float per;
		char grade;
		void calculate()
		{
			per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5;
			if(per>=80)
				grade='A';
			else
			if(per>=60)
				grade='B';
			else
			if(per>=50)
				grade='C';
			else
			if(per>=40)
				grade='D';
			else
				grade='F';

		}
	public:
		void getdata()
		{
			cout<<"\nEnter the admission number of student";
			cin>>admnno;
			cout<<"\nEnter the roll number of student";
			cin>>rollno;
			cout<<"\nEnter the name of student";
			gets(name);
			cout<<"\nEnter the marks in physics out of 100: ";
			cin>>p_marks;
			cout<<"\nEnter the marks in chemistry out of 100: ";
			cin>>c_marks;
			cout<<"\nEnter the marks in maths out of 100: ";
			cin>>m_marks;
			cout<<"\nEnter the marks in english out of 100: ";
			cin>>e_marks;
			cout<<"\nEnter the marks in computer science out of 100: ";
			cin>>cs_marks;
			calculate();
		}
		void showdata()
		{
			cout<<"\nRoll number of student: "<<rollno
			    <<"\nName of student: "<<name
			    <<"\nMarks in Physics: "<<p_marks
			    <<"\nMarks in Chemistry: "<<c_marks
			    <<"\nMarks in Maths: "<<m_marks
			    <<"\nMarks in English: "<<e_marks
			    <<"\nMarks in Computer science: "<<cs_marks
			    <<"\nPercentage of student: "<<per
			    <<"\nGrade of student: "<<grade;
		}
		void show_tabular()
		{
			cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks
			    <<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)
			    <<e_marks<<setw(4)<<cs_marks<<setw(4)<<" "<<per<<setw(6)
			    <<" "<<grade<<endl;
		}
		int retrollno()
		{
			return rollno;
		}
		float rettotal()
		{
			return per;
		}
}st;
//***************************************************************
//    	function to write in file
//****************************************************************

void write_student()
{
	ofstream fout("Result.dat",ios::binary|ios::app);
	st.getdata();
	fout.write((char*)&st,sizeof(student));
	fout.close();
	cout<<"\n\nStudent record has been created";
	cin.ignore();
	getch();
}

//***************************************************************
//    	function to display all students list
//****************************************************************

void display_all()
{
	ifstream fin;
	fin.open("Result.dat",ios::binary);
	if(!fin)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD!!!\n\n";
	while(fin.read((char*)&st,sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	fin.close();
	getch();
}
//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	ifstream fin;
	fin.open("Result.dat",ios::binary);
	if(!fin)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	int flag=0;
	while(fin.read((char*)&st,sizeof(student)))
	{
		if(st.retrollno()==n)
		{
			st.showdata();
			flag=1;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n\nrecord does not exist";
	getch();
}
//***************************************************************
//    	function to write in file
//****************************************************************

void write_admn()
{
	ofstream fout("new.dat",ios::binary|ios::app);
	ad.get();
	fout.write((char*)&ad,sizeof(ad));
	fout.close();
	cout<<"\n\nStudent record has been created";
	cin.ignore();
	getch();
}
//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_spad(int n)
{
	ifstream fin;
	fin.open("new.dat",ios::binary);
	if(!fin)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	int flag=0;
	while(fin.read((char*)&ad,sizeof(ad)))
	{
		if(ad.retadmno()==n)
		{
			ad.put();
			flag=1;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n\nrecord does not exist";
	getch();
}

//***************************************************************
//    	function to create a file with all failures
//****************************************************************

void copy()
{
	ifstream fin("Result.dat",ios::binary);
	ofstream fout("Failures.dat",ios::binary);
	while(fin.read((char*)&st,sizeof(st)))
	{
	if(st.rettotal()<40)
		fout.write((char*)&st,sizeof(st));
	}
	fin.close();
	fout.close();
}
//***************************************************************
//    	function to display all failures
//****************************************************************

void dispfile()
{
	ifstream fin("Failures.dat",ios::binary);
	while(fin.read((char*)&st,sizeof(st)))
		st.showdata();
	fin.close();
	getch();
}

//***************************************************************
//    	function to create a file with all distinctions
//****************************************************************

void copy1()
{
	ifstream fin("Result.dat",ios::binary);
	ofstream fout("Distinctions.dat",ios::binary);
	while(fin.read((char*)&st,sizeof(st)))
	{
	if(st.rettotal()>70)
		fout.write((char*)&st,sizeof(st));
	}
	fin.close();
	fout.close();
}

//***************************************************************
//    	function to display all distinctions
//****************************************************************

void dispfile1()
{
	ifstream fin("Distinctions.dat",ios::binary);
	while(fin.read((char*)&st,sizeof(st)))
		st.showdata();
	fin.close();
	getch();
}
//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
	int found=0;
	fstream file;
	file.open("Result.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	while(file.read((char*)&st,sizeof(student))&&found==0)
	{
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter the New Details of student"<<endl;
			st.getdata();
			int pos=(-1)*sizeof(st);
			file.seekp(pos,ios::cur);
			file.write((char*)&st,sizeof(student));
			cout<<"\n\n\tRecord Updated";
			found=1;
		}
	}
	file.close();
	if(found==0)
		cout<<"\n\nRecord NOT found";
	getch();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student(int n)
{
	ifstream fin;
	fin.open("Result.dat",ios::binary);
	if(!fin)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	ofstream fout("Temp.dat",ios::binary);
	int flag=0;
	while(fin.read((char*)&st,sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			fout.write((char*)&st,sizeof(student));
			flag=1;
		}
	}
	if(flag==0)
		cout<<"Record not found";
	else
	{
		cout<<"\n\n\tRecord deleted";
		remove("Result.dat");
		rename("Temp.dat","Result.dat");
	}
	fin.close();
	fout.close();
	getch();
}
//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_ad(int n)
{
	int found=0;
	fstream file;
	file.open("new.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
		while(file.read((char*)&ad,sizeof(ad))&&found==0)
	{
		if(ad.retadmno()==n)
		{
			ad.put();
			cout<<"\n\nPlease Enter the New Details of student"<<endl;
			ad.get();
			int pos=(-1)*sizeof(ad);
			file.seekp(pos,ios::cur);
			file.write((char*)&ad,sizeof(ad));
			cout<<"\n\n\tRecord Updated";
			found=1;
		}
	}
	file.close();
	if(found==0)
		cout<<"\n\nRecord NOT found";
	getch();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_ad(int n)
{
	ifstream fin;
	fin.open("new.dat",ios::binary|ios::in|ios::out);
	if(!fin)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	ofstream fout("Temp.dat",ios::binary);
	fin.seekg(0,ios::beg);
	int flag=0;
	while(fin.read((char*)&ad,sizeof(ad)))
	{
		if(ad.retadmno()!=n)
		{
			fout.write((char*)&ad,sizeof(ad));
			flag=1;
		}
	}
	if(flag==0)
		cout<<"Record not found";
	else
	{
		cout<<"\n\n\tRecord deleted";
		remove("Result.dat");
		rename("Temp.dat","Result.dat");
	}
	fin.close();
	fout.close();
	getch();
}
//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{
	ifstream fin;
	fin.open("Result.dat",ios::binary);
	if(!fin)
	{
		cout<<"File could not be opened!!Press any key...";
		getch();
		return;
	}
	cout<<"\n\nALL STUDENTS RESULT\n\n";
	cout<<"=====================";
	cout<<"\nR.NO   Name       P   C   M   E   CS  percentage   Grade"<<endl;
	while(fin.read((char*)&st,sizeof(student)))
	{
		st.show_tabular();
	}
	fin.close();
	getch();
}
 //***************************************************************
//    	function to display result menu
//****************************************************************

void result()
{
	int ch;
	int rno;
	cout<<"\n\n\n\tRESULT MENU"
	    <<"\n\n\n\t1.Class report"
	    <<"\n\n\t2.Student report card"
	    <<"\n\n\t3.Failures"
	    <<"\n\n\t4.Distinctions"
	    <<"\n\n\t5.Back to main  menu"
	    <<"\n\n\n\tEnter choice: ";
	cin>>ch;
	clrscr();
	switch (ch)
	{
		case 1:class_result();
			break;
		case 2:cout<<"\n\n\tEnter roll number of student: ";
			cin>>rno;
			display_sp(rno);
			break;
		case 3:copy();
			dispfile();
			break;
		case 4:copy1();
			dispfile1();
			break;
		case 5:break;
		default:cout<<"\nWrong Entry";
	}
}

//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
	int ch,num;
	clrscr();
	cout<<"\n\n\n\tENTRY MENU"
	    <<"\n\n\t1.CREATE STUDENT RECORD"
	    <<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS"
	    <<"\n\n\t3.SEARCH STUDENT RECORD"
	    <<"\n\n\t4.MODIFY STUDENT RECORD"
	    <<"\n\n\t5.DELETE STUDENT RECORD"
	    <<"\n\n\t6.BACK TO MAIN MENU"
	    <<"\n\n\tPlease enter your choice";
	cin>>ch;
	clrscr();
	switch(ch)
	{
		case 1:write_student();
			break;
		case 2:display_all();
			break;
		case 3:cout<<"\n\n\tPlease enter roll number";
			cin>>num;
			display_sp(num);
			break;
		case 4: cout<<"\n\n\tPlease enter roll number";
			cin>>num;
			modify_student(num);
			break;
		case 5:cout<<"\n\n\tPlease enter roll number";
			cin>>num;
			delete_student(num);
			break;
		case 6:break;
		default:cout<<"\nWrong Entry";entry_menu();
	}
}

//***************************************************************
//    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admnres()
{
	int ch,num;
	clrscr();
	cout<<"\n\n\n\tADMISSION DETAILS"
	    <<"\n\n\t1.ENTER ADMISSION DETAILS OF STUDENT "
	    <<"\n\n\t2.SEARCH FOR ADMISSION DETAILS"
	    <<"\n\n\t3.MODIFY ADMISSION DETAILS"
	    <<"\n\n\t4.DELETE ADMISSION DETAILS"
	    <<"\n\n\t5.BACK TO MAIN MENU"
	    <<"\n\n\tPlease enter your choice";
	cin>>ch;
	clrscr();
	switch(ch)
	{
		case 1:write_admn();
			break;
		case 2:cout<<"\n\n\tPlease enter admission number";
			cin>>num;
			display_spad(num);
			break;
		case 3: cout<<"\n\n\tPlease enter admission number";
			cin>>num;
			modify_ad(num);
			break;
		case 4:cout<<"\n\n\tPlease enter admission number";
			cin>>num;
			delete_ad(num);
			break;
		case 5:break;
		default:cout<<"\nWrong Entry";entry_menu();
	}
}

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{
	int ch;
	clrscr();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU"
		    <<"\n\n\t1.RESULT MENU"
		    <<"\n\n\t2.ENTRY/EDIT MENU"
		    <<"\n\n\t3.ADMISSION DETAILS"
		    <<"\n\n\t4.EXIT"
		    <<"\n\n\tPlease select your option";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case 1:result();
				break;
			case 2:entry_menu();
				break;
			case 3:admnres();
				break;
			case 4:break;
			default:cout<<"\Wrong Entry";
		}
	}while(ch!=4);
}
