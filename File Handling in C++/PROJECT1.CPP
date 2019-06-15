//------------------------------------------------------
//			HEADER FILES
//------------------------------------------------------

#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>

//-----------------------------------------------------
//          STRUCTURE FOR FEATURES OF CARS
//-----------------------------------------------------
struct Features
{
	char colour[20];
	int fueltype;
	float mileage;
	int maxspeed;
	int seatingcap;
};
//-----------------------------------------------------
//			BASE CLASS 'CARS'
//-----------------------------------------------------
class Cars
{
	int CNo;
	char Name[50];
	double Price;
	Features Ft;
	int NumSold;
	public :
		void carno();
		void New_Car();
		void View_Car();
		void modification();

		//Accessor functions of class Cars
		int Cno()
		{
			return CNo;
		}
		char *Cname()
		{
			return Name;
		}
		double CPrice()
		{
			return Price;
		}
		int Fuel()
		{
			return Ft.fueltype;
		}
};
//------------------------------------------------------
//			CLASS 'User'
//-----------------------------------------------------
class User
{
	int Uno;
	char UName[30];
	char UPass[8];
	public:
		void accno();
		void create_acc();
		void view_acc();
		void list_acc();
		void modify_acc();
		void delete_acc();

		//Accessor functions of class User
		int UNo()
		{
			return Uno;
		}
		char *User_Name()
		{
			return UName;
		}
		char *User_Pass()
		{
			return UPass;
		}

};
//------------------------------------------------------
//			CLASS 'FAVOURITES'
//-----------------------------------------------------
class Favourites
{
	public:
	int Ano;
	char AName[30];
	char Car_Name[30];
	double Price;
	void Write_Fav_to_file();
	void View_Fav(int);
};

//------------------------------------------------------
//	     GLOBAL DECLARATION OF STREAM AND CLASS
//                         OBJECTS
//------------------------------------------------------
fstream f;
Cars C;
User U;
Favourites Fav;

//-----------------------------------------------------
//           FUNCTION PROTOTYPES
//-----------------------------------------------------

void Write_Car();
void Modify_Car();
void Delete_car(int);
int Fav_Car();
void Search_Cars();
void View_All();
void View_One(int);
void ADMIN_MENU();
void USER_MENU();
void login();
void admin_login();
void homepage();
void intro();
void Help();

//------------------------------------------------------
//			MEMBER FUNCTIONS OF CLASS 'CARS'
//------------------------------------------------------

//Member function to find new car no.
void Cars :: carno()
{
	f.open("CARS_FILE.TXT", ios::in);
	f.seekg(0,ios::beg);
	int count=0;
	while(f.read((char*)&C, sizeof(Cars)))
	{
		if(f.eof())
			break;
		count=CNo;
	}
	f.close();
	CNo = count+1;
}

//Member function to Input information of new Car Entry
void  Cars :: New_Car()
{
	cout<<"\nENTER THE DETAILS OF THE CAR : ";
	carno();
	cout<<"\n\tNAME : ";
	gets(Name);
	cout<<"\tDescription : ";
	cout<<"\n\t\tCOLOUR : ";
	gets(Ft.colour);
	cout<<"\t\tMILEAGE : ";
	cin>>Ft.mileage;
	cout<<"\t\tSEATING CAPACITY : ";
	cin>>Ft.seatingcap;
	cout<<"\t\tMAXIMUM SPEED : ";
	cin>>Ft.maxspeed;
	cout<<"\t\tFUEL TYPE : ";
	cout<<"\n\t\t\t(1) Petrol";
	cout<<"\n\t\t\t(2) Diesel";
	cout<<"\n\t\t\t(3) CNG";
	cout<<"\n\t\t\t(4) LPG";
	cout<<"\n\t\t\t(5) Electric\n\t\t\t";
	cin>>Ft.fueltype;
	cout<<"\tPRICE : ";
	cin>>Price;
}

//Member function to View information of Car Entry
void Cars :: View_Car()
{
	cout<<"\n\t\t---DETAILS OF CAR--- ";
	cout<<"\n\tCar No. : "<<CNo;
	cout<<"\n\tNAME : "<<(Name);
	cout<<"\n\n\tDescription : ";
	cout<<"\n\t\tCOLOUR : "<<(Ft.colour);
	cout<<"\n\t\tMILEAGE : "<<Ft.mileage<<" kmpl";
	cout<<"\n\t\tSEATING CAPACITY : "<<Ft.seatingcap<<" seater";
	cout<<"\n\t\tMAXIMUM SPEED : "<<Ft.maxspeed<<" kmph";
	cout<<"\n\t\tFUEL TYPE : ";
	if(Ft.fueltype==1)
		cout<<" Petrol.";
	if(Ft.fueltype==2)
		cout<<" Diesel.";
	if(Ft.fueltype==3)
		cout<<" CNG.";
	if(Ft.fueltype==4)
		cout<<" LPG.";
	if(Ft.fueltype==5)
		cout<<" Electric.";
	cout<<"\n\tPRICE : Rs. "<<Price;
}

//Member function to Modify information of Car Entry
void Cars :: modification()
{
	char nm[20];
	int mk;
	double d;
	cout<<"\nNew Name : (Press '0'to retain old one)"<<endl;
	cin>>nm;
	if(strcmp(nm,"0")!=0)
		strcpy(Name,nm);
	cout<<"\nNew Colour : (Press '0'to retain old one)"<<endl;
	cin>>nm;
	if(strcmp(nm,"0")!=0)
		strcpy(Ft.colour,nm);
	cout<<"\nNew Mileage : (Press '0'to retain old one)"<<endl;
	cin>>mk;
	if(mk!=0)
		Ft.mileage = mk;
	cout<<"\nNew Seating capacity : (Press '0'to retain old one)"<<endl;
	cin>>mk;
	if(mk!=0)
		Ft.seatingcap = mk;
	cout<<"\nNew Maximum speed : (Press '0'to retain old one)"<<endl;
	cin>>mk;
	if(mk!=0)
		Ft.maxspeed = mk;
	cout<<"\nNew Fuel type : (Press '0'to retain old one)"<<endl;
	cout<<"\n\t\t\t(1) Petrol";
	cout<<"\n\t\t\t(2) Diesel";
	cout<<"\n\t\t\t(3) CNG";
	cout<<"\n\t\t\t(4) LPG";
	cout<<"\n\t\t\t(5) Electric\n\t\t\t";
	cin>>mk;
	if(mk!=0)
		Ft.fueltype=mk;
	cout<<"\nNew Price : (Press '0'to retain old one)"<<endl;
	cin>>d;
	if(d!=0)
		Price = d;
}

//------------------------------------------------------
//			MEMBER FUNCTIONS OF CLASS 'USER'
//------------------------------------------------------

//Member function to find new Account No.
void User:: accno()
{
	f.open("USER_FILE.TXT", ios::in);
	f.seekg(0,ios::beg);
	int count=0;
	while(f.read((char*)&U, sizeof(User)))
	count=Uno;
	f.close();
	Uno = count + 1;
}

//Member function to Input information of new Account
void User :: create_acc()
{
	char c[20];
	accno();
	cout<<"\n\n\t\t-----REGISTER TO KRAZZY KARS-----";
	cout<<"\n\n\tAccount No. : "<<Uno;
	cout<<"\n\tEnter your name : ";
	gets(UName);
	cout<<"\tEnter Password : ";
	for(int i=0;i<20;i++)
	{
		c[i]=getch();
		if(c[i]=='\r')
		{
			c[i] = '\0';
			break;
		}
		cout<<"*";
	}
	strcpy(UPass,c);

}

//Member function to View information of Account
void User :: view_acc()
{
	cout<<"\n\n\tAccount No. : "<<Uno;
	cout<<"\n\tAccount name : "<<UName;
	cout<<"\n\tPassword : "<<UPass;
}

//Member function to View list of user Accounts
void User::list_acc()
{
	clrscr();
	f.open("USER_FILE.TXT", ios::in);
	cout<<"\n\n  ACCOUNT NO.\t USER NAME";
	while (f.read((char *)&U, sizeof(User)))
	{
		if(f.eof())
		break;
		cout<<"\n\t"<<Uno;
		cout<<"\t   "<<UName;
	}
	f.close();
	getch();
}

//Member function to Modify information of Account
void User :: modify_acc()
{
	int n,pos;
	n = Uno;
	f.open("USER_FILE.TXT",ios::in|ios::out);
	f.seekg(0);
	while(f)
	{
		pos = f.tellg();
		f.read((char*)&U,sizeof(User));
		if(U.UNo()==n)
		{
			view_acc();
			cout<<"\n\nEnter new details : "<<endl;
			char n[20];
			cout<<"\nNew Name : (Press '.'to retain old one)"<<endl;
			cin>>n;
			if(strcmp(n,".")!=0)
			strcpy(UName,n);
			cout<<"\nNew Password : (Press '.'to retain old one)"<<endl;
			cin>>n;
			if(strcmp(n,".")!=0)
			strcpy(UPass,n);
			f.seekp(pos);
			f.write((char*)&U,sizeof(User));
			cout<<"\n\n\t Record Updated";
			break;
		}
	}
	f.close();
	getch();
}

//Member function to Delete information of Account
void User :: delete_acc()
{
	f.open("USER_FILE.TXT", ios::in);
	ofstream f2("temp.txt",ios::out|ios::app);
	int n;
	char confirm = 'n';
	n = Uno;
	while(f.read((char *)&U, sizeof(User)))
	{
		if(U.UNo()==n)
		{
			U.view_acc();
			cout<<"\n\nAre you sure, you want to delete your account?(y/n) : ";
			cin>>confirm;
			if(confirm == 'n')
			{
				f2.write((char *)&U, sizeof(U));
			}
		}
		else
		{
			f2.write((char*)&U, sizeof(U));
		}
	}
	f.close();
	f2.close();
	remove("USER_FILE.TXT");
	rename("temp.txt","USER_FILE.TXT");
	getch();
	if(confirm=='n')
	{
		 clrscr();
		 USER_MENU();
	}
	else
	{
		 clrscr();
		 homepage();
	}
}

//------------------------------------------------------
//			MEMBER FUNCTIONS OF CLASS 'FAVOURITES'
//------------------------------------------------------

//Member function to Write new Favourites to text file
void Favourites :: Write_Fav_to_file()
{
	f.open("FAV_FILE.TXT",ios::out|ios::app);
	f.write((char*)&Fav,sizeof(Fav));
	f.close();
}

//Member function to View Favourites of a user
void Favourites :: View_Fav(int n)
{
	int ch = 0, c=1;
	clrscr();
	fstream f2;
	f2.open("FAV_FILE.TXT",ios::in);
	cout<<"\n   --------M Y    F A V O U R I T E S-------";
	cout<<"\n\n\t SNo.\t  Car Brand\t    Price";
	while(f2.read((char*)&Fav,sizeof(Favourites)))
	{
		if(Fav.Ano==n)
		{
			ch=1;
			cout<<"\n\t  "<<c<<".\t  "<<Fav.Car_Name<<"\t\t  Rs."<<Fav.Price;
			c++;
		}
	}
	f2.close();
	if(ch==0)
	cout<<"\n\nNO FAVOUTRITES TO DISPLAY!!!";
	cout<<"\n\n   Press <Enter> to continue..";
	getch();
}

//------------------------------------------------------
//          FUNCTION TO ADD NEW CAR ENTRY TO FILE
//------------------------------------------------------
void Write_Car()
{
	C.New_Car();
	f.open("CARS_FILE.TXT",ios::out|ios::app);
	f.write((char*)&C,sizeof(Cars));
	cout<<"\n\nCar No. "<<C.Cno()<<" Has Been Entered.";
	f.close();
	getch();
}
//------------------------------------------------------
//			FUNCTION TO MODIFY CAR ENTRY
//------------------------------------------------------
void Modify_Car()
{
	clrscr();
	int n,pos,found=0;
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter The Car No.";
	cin>>n;
	f.open("CARS_FILE.TXT",ios::in|ios::out);
	while(f)
	{
		pos = f.tellg();
		f.read((char*)&C,sizeof(Cars));
		if(C.Cno()==n)
		{
			C.View_Car();
			cout<<"\n\nPlease Enter The New Details of CAR.\n"<<endl;
			C.modification();
			f.seekp(pos);
			f.write((char*)&C,sizeof(C));
			cout<<"\n\n\t Record Updated";
			found = 1;
			break;
		}
	}
	f.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();
}

//------------------------------------------------------
//			FUNCTION TO DELETE CAR ENTRY
//------------------------------------------------------

void Delete_car(int n)
{
	ifstream f1("CARS_FILE.TXT", ios::in);
	ofstream f2("TEMP.txt",ios::out);
	char confirm = 'n';
	while(f1.read((char*)&C, sizeof(Cars)))
	{
		if(C.Cno()==n)
		{
			C.View_Car();
			cout<<"\n\nAre you sure, you want to delete this entry?(y/n)";
			cin>>confirm;
			if(confirm != 'y'&& confirm != 'Y')
			{
			 f2.write((char*)&C, sizeof(C));
			}
		}
		else
		{
			f2.write((char*)&C, sizeof(C));
		}
	}
	f1.close();
	f2.close();
	remove("CARS_FILE.TXT");
	rename("TEMP.txt","CARS_FILE.TXT");
}


//------------------------------------------------------
//          FUNCTION TO ADD CAR TO FAVOURITES
//------------------------------------------------------
int Fav_Car()
{
	Fav.Write_Fav_to_file();
	cout<<"\n\nYOU HAVE ADDED THIS CAR TO YOUR FAVOURITES!!";
	return 0;
}

//------------------------------------------------------
//          FUNCTION TO FILTER SEARCH AND VIEW
//------------------------------------------------------

void Search_Cars()
{
	clrscr();
	char c=' ';
	cout<<"\n\n\t\t\t----NEW CARS 2012----";
	cout<<"\n\n\t(1) View By brand. ";
	cout<<"\n\t(2) View By budget.";
	cout<<"\n\t(3) View By Fuel Type.";
	cout<<"\n\t(4) Back.";
	cout<<"\n\t(5) Exit.";
	cout<<"\n\nEnter your choice..";
	cin>>c;
	switch(c)
	{
		case '1':
		{
			clrscr();
			int c;
			cout<<"\n\t\tSELECT BRAND : \n";
			f.open("CARS_FILE.TXT",ios::in);
			while(f.read((char*)&C, sizeof(Cars)))
			{
				 cout<<"   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
			}
			f.close();
			int n;
			char found = 'N';
			cout<<"\nEnter the car no.";
			cin>>n;
			f.open("CARS_FILE.TXT",ios::in);
			while(f.read((char*)&C,sizeof(Cars)))
			{
				if(C.Cno()==n)
				{
					found = 'Y';
					clrscr();
					C.View_Car();
					strcpy(Fav.Car_Name, C.Cname());
					Fav.Price = C.CPrice();
					f.close();
					cout<<"\n\n\tEnter (1) ADD THIS CAR TO 'MY FAVOURITES'.";
					cout<<"\n\t      (2) TO GO BACK.\n\t";
					cin>>c;
					if(c==1)
					{
						Fav_Car();
						getch();
						Search_Cars();
					}
					else
					{
						Search_Cars();
					}
				}
			}
			if(found=='N')
			{
				f.close();
				cout<<"\n\tINVALID ENTRY!!\n\t(Press ENTER to continue.)";
				getch();
				Search_Cars();
			}
		}
		break;

		case '2':
		{
			clrscr();
			cout<<"\n\t\tSELECT CAR PRICE : \n";
			cout<<"\n\t(1) 1 lakh - 5 lakh.";
			cout<<"\n\t(2) 5 lakh - 10 lakh.";
			cout<<"\n\t(3) 10 lakh - 20 lakh.";
			cout<<"\n\t(4) 20 lakh - 50 lakh.";
			cout<<"\n\t(5) 50 lakh plus.";
			int s, chk=0;
			cout<<"\n\nEnter your choice.";
			cin>>s;
			f.open("CARS_FILE.TXT",ios::in);
			switch(s)
			{
				case 1:
				{
					cout<<"\nThe cars in your budget are : \n";
					f.seekg(0);
					while(f.read((char*)&C, sizeof(Cars)))
					{
						if(C.CPrice()>=100000.0 && C.CPrice()<500000.0)
						{
							chk=1;
							cout<<"\n   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
						}
					}
					f.close();
				}
				break;
				case 2:
				{
					cout<<"\nThe cars in your budget are : \n";
					f.seekg(0);
					while(f.read((char*)&C, sizeof(Cars)))
					{
						if(C.CPrice()>=500000.0 && C.CPrice()<1000000.0)
						{
							cout<<"\n   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
							chk=1;
						}
					}
					f.close();
				}
				break;
				case 3:
				{
					cout<<"\nThe cars in your budget are : \n";
					f.seekg(0);
					while(f.read((char*)&C, sizeof(Cars)))
					{
						if(C.CPrice()>=1000000.0 && C.CPrice()<2000000.0)
						{
							cout<<"\n   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
							chk=1;
						}
					}
					f.close();
				}
				break;
				case 4:
				{
					cout<<"\nThe cars in your budget are : \n";
					f.seekg(0);
					while(f.read((char*)&C, sizeof(Cars)))
					{
						if(C.CPrice()>=2000000.0 && C.CPrice()<5000000.0)
						{
							cout<<"   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
							chk=1;
						}
					}
					f.close();
				}
				break;
				case 5:
				{
					cout<<"\nThe cars in your budget are : \n";
					f.seekg(0);
					while(f.read((char*)&C, sizeof(Cars)))
					{
						if(C.CPrice()>=5000000.0)
						{
							cout<<"\n   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
							chk=1;
						}
					}
					f.close();
				}
				break;
				default :
					cout<<"\n\n\tINVALID ENTRY!!!";
					cout<<"\n\t(Press any key to continue.)";
					f.close();
					getch();
					Search_Cars();
			}
			char found = 'N';
			if(chk==0)
			{
				cout<<"\nNO CARS TO DISPLAY!!!";
				getch();
				Search_Cars();
			}
			else
			{
				int n,c;
				cout<<"\nEnter the car no.";
				cin>>n;
				f.open("CARS_FILE.TXT",ios::in);
				while(f.read((char*)&C,sizeof(Cars)))
				{
					if(C.Cno()==n)
					{
						found = 'Y';
						clrscr();
						C.View_Car();
						strcpy(Fav.Car_Name, C.Cname());
						Fav.Price = C.CPrice();
						f.close();
						cout<<"\n\n\tEnter (1) ADD THIS CAR TO 'MY FAVOURITES'.";
						cout<<"\n\t      (2) TO GO BACK.  ";
						cin>>c;
						if(c==1)
						{
							Fav_Car();
							getch();
							Search_Cars();
						}
						else
							Search_Cars();
					}
				}
			}
			f.close();
			if(found=='N')
			{
				cout<<"\n\tINVALID ENTRY!!\n\t(Press ENTER to continue.)";
				getch();
				Search_Cars();
			}
		}
		break;

		case '3':
		{
			clrscr();
			int t, chk=0;
			cout<<"\n\t\tSELECT FUEL TYPE : \n";
			cout<<"\n\t(1) Petrol";
			cout<<"\n\t(2) Diesel";
			cout<<"\n\t(3) CNG";
			cout<<"\n\t(4) LPG";
			cout<<"\n\t(5) Electric";
			cin>>t;
			switch(t)
			{
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				{
					f.open("CARS_FILE.TXT",ios::in);
					cout<<"\nYour options are : \n";
					while(f.read((char*)&C, sizeof(Cars)))
					{
						if(t==C.Fuel())
						{
						cout<<"   ("<<C.Cno()<<") "<<C.Cname()<<"\n";
						chk=1;
						}
					}
				}
				f.close();
				break;
				default:
				{
					cout<<"\n\t\tINVALID OPTION!!.";
					cout<<"\n\t\tPress ENTER to continue.";
					getch();
					Search_Cars();
				}
			}
			if(chk==0)
			{
				cout<<"\nNO CARS TO DISPLAY!!!";
				getch();
				Search_Cars();
			}
			int n,c;
			char found = 'N';
			cout<<"\nEnter the car no.";
			cin>>n;
			f.open("CARS_FILE.TXT",ios::in);
			while(f.read((char*)&C,sizeof(Cars)))
			{
				if(C.Cno()==n)
				{
					found = 'Y';
					clrscr();
					C.View_Car();
					strcpy(Fav.Car_Name, C.Cname());
					Fav.Price = C.CPrice();
					f.close();
					cout<<"\n\n\tEnter (1) ADD THIS CAR TO 'MY FAVOURITES'";
					cout<<"\n\t      (2) TO GO BACK.  ";
					cin>>c;
					if(c==1)
					{
						Fav_Car();
						getch();
						Search_Cars();
					}
					else
					{
						Search_Cars();
					}

				}
			}
			if(found=='N')
			{
				f.close();
				cout<<"\n\tINVALID ENTRY!!\n\t(Press ENTER to continue.)";
				getch();
				Search_Cars();
			}
		}
		break;

		case '4':
			USER_MENU();
		case '5':
			exit(0);
		default:
			Search_Cars();
	}

}
//------------------------------------------------------
//			FUNCTION TO VIEW ALL ENTRIES
//------------------------------------------------------
void View_All()
{
	clrscr();
	cout<<"\n\n\n\t\tDISPLAY ALL CARS!!!\n\n";
	f.open("CARS_FILE.TXT",ios::in);
	while(f.read((char*)&C,sizeof(Cars)))
	{
		C.View_Car();
		cout<<"\n\n------------------------------------------\n";
		getch();
	}
	f.close();
	getch();
}
//------------------------------------------------------
//			FUNCTION TO VIEW ONE ENTRY
//------------------------------------------------------
void View_One(int n)
{
	int ch = 0;
	f.open("CARS_FILE.TXT",ios::in);
	while(f.read((char*)&C,sizeof(Cars)))
	{
		if(C.Cno()==n)
		{
			clrscr();
			C.View_Car();
			ch=1;
			break;
		}
	}
	f.close();
	if(ch==0)
	cout<<"\n\nCAR NOT PRESENT!!!";
	getch();
}

//------------------------------------------------------
//			ADMINISTRATOR MENU of program
//------------------------------------------------------
void ADMIN_MENU()
{
	clrscr();
	void homepage();
	char ch;
	cout<<"\n\n\t\t----WELCOME ADMINISTRATOR----";
	cout<<"\n\n\n\t(1)    Add new CAR entry.";
	cout<<"\n\t(2)    Modify Car entry.";
	cout<<"\n\t(3)    Delete Car entry.";
	cout<<"\n\t(4)    View cars.";
	cout<<"\n\t(5)    View specific car.";
	cout<<"\n\t(6)    View list of USER accounts. ";
	cout<<"\n\t(7)    Log Out";
	cout<<"\n\t(8)    Exit.";
	cout<<"\n\n\n\tPlease Enter your choice --> ";
		cin>>ch;
		switch(ch)
		{
			case '1':
				clrscr();
				Write_Car();
				ADMIN_MENU();
				clrscr();
				break;

			case '2':
				clrscr();
				Modify_Car();
				ADMIN_MENU();
				clrscr();
				break;

			case '3':
				clrscr();
				int n;
				cout<<"\n\t\t----LIST OF CARS----\n";
				f.open("CARS_FILE.TXT",ios::in);
				while(f.read((char*)&C, sizeof(Cars)))
				{
					 cout<<"\t"<<C.Cno()<<") "<<C.Cname()<<"\n";
				}
				f.close();
				cout<<"\nEnter the car no. to delete car entry... ";
				cin>>n;
				Delete_car(n);
				clrscr();
				ADMIN_MENU();
				break;

			case '4':
				clrscr();
				View_All();
				clrscr();
				ADMIN_MENU();
				break;

			case '5':
				clrscr();
				int c;
				cout<<"\n\t\t----LIST OF CARS----\n";
				f.open("CARS_FILE.TXT",ios::in);
				while(f.read((char*)&C, sizeof(Cars)))
				{
					 cout<<"\t"<<C.Cno()<<") "<<C.Cname()<<"\n";
				}
				f.close();
				cout<<"\nEnter the Car No. to view details of the car : ";
				cin>>c;
				View_One(c);
				clrscr();
				ADMIN_MENU();
				break;


			case '6':
				clrscr();
				fstream f1;
				cout<<"\n\t-----LIST OF USER ACCOUNTS-----";
				f1.open("USER_FILE.TXT", ios::in);
				U.list_acc();
				f1.close();
				ADMIN_MENU();
				break;

			case '7':
				clrscr();
				homepage();

			case '8':
				exit(0);

			default :
				clrscr();
				ADMIN_MENU();
		}
}
//------------------------------------------------------
//			FUNCTION 'USER_MENU'
//------------------------------------------------------
void USER_MENU()
{
	char ch;
	clrscr();
	f.open("USER_FILE.TXT", ios::in);
	cout<<"\n\n\t\t----WELCOME "<<U.User_Name()<<" ----";
	strcpy(Fav.AName,U.User_Name());
	Fav.Ano = U.UNo();
	f.close();
	cout<<"\n\n\n\t(1)  View all cars.";
	cout<<"\n\t(2)  Search cars.";
	cout<<"\n\t(3)  View My Favourites.";
	cout<<"\n";
	cout<<"\n\t(4)  Modify account details.";
	cout<<"\n\t(5)  Delete account.";
	cout<<"\n\t(6)  LOG OUT and go Back to Main Menu.";
	cout<<"\n\t(7)  Exit.";
	cout<<"\n\n\n\tPlease Enter your choice --> ";
		cin>>ch;
		switch(ch)
		{
			case '1':
				clrscr();
				View_All();
				int n,c;
				clrscr();
				cout<<"\nEnter (1) To add to 'MY FAVOURITES'.";
				cout<<"\n      (2) To go back.  ";
				cin>>n;
				if(n==1)
				{
					clrscr();
					cout<<"\n\t\t----LIST OF CARS----\n";
					f.open("CARS_FILE.TXT",ios::in);
					while(f.read((char*)&C, sizeof(Cars)))
					{
						cout<<"\t"<<C.Cno()<<") "<<C.Cname()<<"\n";
					}
					f.close();
					cout<<"\nEnter car no. to add to 'MY FAVOURITES': ";
					cin>>n;
					f.open("CARS_FILE.TXT",ios::in);
					while(f.read((char*)&C,sizeof(Cars)))
					{
						if(C.Cno()==n)
						{
							clrscr();
							C.View_Car();
							strcpy(Fav.Car_Name, C.Cname());
							Fav.Price = C.CPrice();
							f.close();
							cout<<"\n\n\tEnter (1) To add to 'MY FAVOURITES'";
							cout<<"\n\t      (2) To go back.  ";
							cin>>c;
							if(c==1)
							{
								Fav_Car();
								getch();
							}
						}
					}
				}
				clrscr();
				USER_MENU();
				break;

			case '2':
				clrscr();
				Search_Cars();
				USER_MENU();
				break;

			case '3':
				clrscr();
				Fav.View_Fav(Fav.Ano);
				USER_MENU();
				break;

			case '4':
				clrscr();
				U.modify_acc();
				USER_MENU();
				break;

			case '5':
				clrscr();
				U.delete_acc();
				break;

			case '6':
				clrscr();
				homepage();
				break;

			case '7':
				exit(0);

			default :
				clrscr();
				USER_MENU();
				break;
		}
		clrscr();

}
//------------------------------------------------------
//				LOGIN FUNCTION
//------------------------------------------------------
void login()
{
	char name[20];
	char pass[20];
	char a,c[20];
	strcpy(name,"NULL");
	strcpy(pass,"NULL");
	clrscr();
	cout<<"\n\n\t\tENTER THE USER NAME : ";
	gets(name);
	cout<<"\n\t\tENTER THE PASSWORD : ";
	for(int i=0;i<20;i++)
	{
		c[i]=getch();
		if(c[i]=='\r')
		{
			c[i] = '\0';
			break;
		}
		cout<<"*";
	}
	strcpy(pass,c);
	f.open("USER_FILE.TXT",ios::in);
	while(!f.eof())
	{
		if(f.eof())
		{
			cout<<"\n\tSORRY !! WRONG PASSWORD OR USERNAME. PLEASE RE-ENTER ";
			cout<<"\n\n\tPRESS # TO GO BACK TO MAIN MENU.";
			cout<<"\n\tPRESS ANY OTHER KEY TO RETRY\n\t\t...";
			cin>>a;
			if(a=='#')
			{
				 getch();
				 clrscr();
				 homepage();
			}
			else
			{
				 getch();
				 login();
			}
		 break;
		}
		f.read((char*)&U,sizeof(User));
		if(!strcmp(name,U.User_Name()))
		{
			if(f.eof())
			{
				f.close();
				cout<<"\n\tSORRY !! WRONG PASSWORD OR USERNAME. PLEASE RE-ENTER ";
				cout<<"\n\n\tPRESS # TO GO BACK TO MAIN MENU.";
				cout<<"\n\tPRESS ANY OTHER KEY TO RETRY\n\t\t...";
				cin>>a;
				if(a=='#')
				{
					clrscr();
					homepage();
				}
				else
				{
					login();
				}
			}
			else if(!strcmp(pass,U.User_Pass()))
			{
				USER_MENU();
				break;
			}
		}
		else if(f.eof())
		{
			f.close();
			cout<<"\n\tSORRY !! WRONG PASSWORD OR USERNAME. PLEASE RE-ENTER ";
			cout<<"\n\n\tPRESS # TO GO BACK TO MAIN MENU.";
			cout<<"\n\tPRESS ANY OTHER KEY TO RETRY\n\t\t...";
			cin>>a;
			if(a=='#')
			{
				clrscr();
				homepage();
			}
			else
			{

			 login();
			}
		}
	 }
	 f.close();
	 getch();
}
//------------------------------------------------------
//                     FUNCTION 'ADMIN LOGIN'
//------------------------------------------------------
void admin_login()
{
	clrscr();
	char apass[20];
	char a,c[20];
	cout<<"\n\n\tENTER ADMIN PASSWORD : ";
	for(int i=0;i<20;i++)
	{
		c[i]=getch();
		if(c[i]=='\r')
		{
			c[i] = '\0';
			break;
		}
		cout<<"*";
	}
	strcpy(apass,c);
	if(!strcmp(apass,"CARS"))
	{
		ADMIN_MENU();
	}
	else
	{
		cout<<"\n\tINCORRECT ADMIN PASSWORD . PLEASE RE-ENTER .\n";
		cout<<"\n\n\tPRESS # TO GO BACK TO MAIN MENU.";
		cout<<"\n\tPRESS ANY OTHER KEY TO RETRY";
		cin>>a;
		if(a=='#')
		{
			 clrscr();
			 homepage();
		}
		else
		{
			 admin_login();
		}

	}
	getch();
}

//------------------------------------------------------
//                     FUNCTION 'HOMEPAGE'
//------------------------------------------------------
void homepage()
{
	char choice;
	do
	{
		cout<<"\n\n\t_________________________________________________________________";
		cout<<"\n\n\n\t\t\t----WELCOME TO KRAZZY KARS----";
		cout<<"\n\t\tKRAZZY KARS is the best place to search for your";
		cout<<"\n\t\t\tfavourite cars in India.";
		cout<<"\n\n\n\t\t~~~LOGIN TO VIEW THE BRAND NEW CARS OF 2012!~~~ ";
		cout<<"\n\n\n\n\t(1) Create account";
		cout<<"\n\t(2) Login";
		cout<<"\n\t(3) Exit";
		cout<<"\n\n\n\t _________________________________________________________________";
		cout<<"\n\t\t\t\t\t\t(*)ADMIN MENU  (#)HELP\n\n\t";
		cout<<"\n\t Please enter your choice --> \t";
		cin>>choice;
		switch(choice)
			{
				case '1' :
					clrscr();
					U.create_acc();
					f.open("USER_FILE.TXT",ios::out|ios::app);
					f.write((char*)&U,sizeof(User));
					cout<<"\n\n\tYour Account has been Created.";
					f.close();
					getch();
					USER_MENU();
					break;

				case '2' :
					 login();
					 clrscr();
					 break;

				case '3':
					exit(0);

				case '*':
					admin_login();

				case '#':
					Help();

				default :
					clrscr();

			}
			clrscr();
	}while(choice!='3');
	getch();
}



//------------------------------------------------------
//			INTRODUCTION FUNCTION
//------------------------------------------------------
void intro()
{
	clrscr();
	gotoxy(12,3);
	cout<<"\n\t\tษออออออออออออออออออออออออออออออออออออออออออออป";
	cout<<"\n\t\tบ            W E L C O M E   T O             บ";
	cout<<"\n\t\tบ                                            บ";
	cout<<"\n\t\tบ   C A R   S H O W R O O M  P R O J E C T   บ";
	cout<<"\n\t\tศออออออออออออออออออออออออออออออออออออออออออออผ";
	gotoxy(49,15);
	cout<<"Compiled By : ";
	gotoxy(54,16);
	cout<<"Neha Pai";
	gotoxy(54,17);
	cout<<"Pradnya Soman";
	gotoxy(54,18);
	cout<<"Ishan Shah";
	gotoxy(54,19);
	cout<<"Samadrita Saha";
	gotoxy(12,22);
	cout<<"__________________________________________________________";
	gotoxy(12,23);
	cout<<"Press any key to continue...";
	getch();
	clrscr();
}


//------------------------------------------------------
//          Function to display HELP about project
//------------------------------------------------------
void Help()
{
	clrscr();
	cout<<"\n";
	cout<<"\n   ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
	cout<<"\n   บ W E L C O M E   T O  C A R   S H O W R O O M  P R O J E C T บ";
	cout<<"\n   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	cout<<"\n\n\t   This project is an application based on a car showroom.";
	cout<<"\n\tCustomers can access information and add cars to their list of ";
	cout<<"\n\t   their favourites only after creating their account.";
	cout<<"\n\n  In the main menu : ";
	cout<<"\n      Press 1 : To create an account by entering the Username and Password";
	cout<<"\n      Press 2 : To Login with your existing Username and Password";
	cout<<"\n\n  ~ After you LOGIN you can search for Your favourite car depending on brand,";
	cout<<"\n           budget or fuel type. You can also View your favourite cars.";
	cout<<"\n           You can also modify your account details or delete your account.";
	cout<<"\n\n  ~ If you are an administrator : ";
	cout<<"\n           You can add new cars, modify car entries, delete car entries, view ";
	cout<<"\n           the cars or view list of user accounts.";
	getch();
}


//------------------------------------------------------
//			FUNCTION 'MAIN'
//------------------------------------------------------
void main()
{
	 clrscr();
	 intro();
	 homepage();
	 getch();
}

