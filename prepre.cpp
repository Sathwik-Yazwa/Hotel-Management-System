#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<vector>
using namespace std;

class bills
    {
    public:
    int b,r_charge,food,oc,r_day,room,ch;
    float t,ser,total;
    string custm_name;

}bil;


class customer:public bills
{
public:
    vector<long long int>teleno;
    vector<int>roomno;
    vector<string>name;
    vector<string>address;
}cus;


class hotelattendent
{
    public:
        vector<int>item;
vector<string>order;
vector<long long int>ordtel;
        int option;
void orderdelivery()
{
       string orderofcustomer;
    long long int ordercustomer;
    int cost=0,i,x,t,a;
cout<<"enter  the telephone number of the customer "<<endl;
cin>>ordercustomer;
x=0;
for(i=0;i<ordtel.size();i++)
{
    if(ordercustomer==ordtel[i])
    {
        x=1;
        cost=item[i];
        t=i;
        break;
    }
}
if(x==0)
ordtel.push_back(ordercustomer);
cout<<"enter the type of order : /roomservice/foodservice"<<endl;
cin>>orderofcustomer;
if(orderofcustomer=="foodservice")
{
    while(1)
    {
    cout<<"1.idle : 50/-"<<endl;
    cout<<"2.dosa : 100/-"<<endl;
    cout<<"3.meals: 200/-"<<endl;
    cout<<"4.exit"<<endl;
    cout<<"enter your option"<<endl;
    cin>>option;
    if(option==1)
    cost=cost+50;
    if(option==2)
    cost=cost+100;
    if(option==3)
    cost=cost+200;
    if(option==4)
        break;
    }
    if(x==0)
    item.push_back(cost);
    else
        item[t]=cost;
}
order.push_back(orderofcustomer);
cout<<"successfully order is taken"<<endl;
}
}hat;

class chef:public hotelattendent
{
public:
    void prepareorder()
    {
        int i,j;
        cout<<"prepared order for customers"<<endl;
        for(i=0;i<order.size();i++)
        {
            if(order[i]=="foodservice")
            {
                         cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"CUSTOMER NO:    "<<ordtel[i]<<endl;
	cout<<"customer order: "<<"foodservice"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;


            }
        }
        getch();
    }
}che;

class Manager
{
public:
    vector<string>staffname;
    vector<long long int>stafftel;

    void add_staff(string staname,long long int statel)
    {
    staffname.push_back(staname);
    stafftel.push_back(statel);
    cout<<endl;
    cout<<"staff is registered successfully"<<endl;
    cout<<endl;
    cout<<"press enter to continue to login"<<endl;
    getch();
    }

    void displaystaff()
    {
        int i;
        for(i=0;i<staffname.size();i++)
        {
            cout<<"----------------------------------------"<<endl;
            cout<<"STAFF MEMBER NAME :"<<staffname[i]<<"|"<<"TELEPHONE NO:"<<stafftel[i]<<endl;
            cout<<"----------------------------------------"<<endl;
        }
        cout<<endl;
        cout<<"press enter to continue to login page"<<endl;
        getch();
    }
}man;

class receptionist:public customer,public chef
{
public:
    int ch;

    vector<int>check_inmonth;
    vector<int>check_inyear;
    vector<string>roomtype;
    vector<int>room_charge;
    vector<int>check_indate;
    vector<int>check_outdate;
    bills bil;

	void add_customer(string nam,string add,long long int tel,int yer,int mon,int dat,string typ)
	{
	    name.push_back(nam);
	    address.push_back(add);
	    teleno.push_back(tel);
	roomtype.push_back(typ);
	if(typ=="AC")
	{
	    room_charge.push_back(5000);
        cout<<"room_charge: "<<5000<<endl;
	}
	else if(typ=="NAC")
    {
        room_charge.push_back(4000);
        cout<<"room_charge: "<<4000<<endl;
    }
  check_inyear.push_back(yer);
  check_inmonth.push_back(mon);
  check_indate.push_back(dat);
cout<<endl;
  cout<<"successfully customer added"<<endl;
  cout<<endl;
  cout<<"press enter to continue to login page"<<endl;
getch();
	}
	void checkout_customer(string feedback,long long int tel)
	{
	    int i,s,x;
      for(i=0;i<name.size();i++)
      {x=0;
          if(tel==teleno[i])
          {x=1;
            name.erase(name.begin()+i);
            address.erase(address.begin()+i);
             teleno.erase(teleno.begin()+i);
             check_inyear.erase(check_inyear.begin()+i);
            check_inmonth.erase(check_inmonth.begin()+i);
             check_indate.erase(check_indate.begin()+i);
             roomtype.erase(roomtype.begin()+i);
             room_charge.erase(room_charge.begin()+i);
          }

      }
      if(x==0)
        cout<<"entered number is not found"<<endl;
      else
      {
      cout<<endl;
      cout<<"customer checked out successfully"<<endl;
      cout<<endl;
      }
      cout<<"press enter to continue"<<endl;
      getch();

	}
	void display_customer()
	{int temp1=0;
cout<<"\t\t\t\t----------------------------------------"<<endl;
cout<<"\t\t\t\t\tCUSTOMER DETAILS"<<endl;
cout<<"\t\t\t\t----------------------------------------"<<endl;
	    while(temp1<name.size())
        {
            cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"CUSTOMER NAME: "<<name[temp1]<<"|"<<"ADDRESS: "<<address[temp1]<<"|"<<"TELEPHONE NO: "<<teleno[temp1]<<"|"<<"YEAR: "<<check_inyear[temp1]<<endl;
	cout<<"MONTH: "<<check_inmonth[temp1]<<"|"<<"DATE: "<<check_indate[temp1]<<"|"<<"ROOMTYPE: "<<roomtype[temp1]<<"|"<<"ROOMCHARGE: "<<room_charge[temp1]<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
	temp1++;
	}
	cout<<endl;
	cout<<"press enter to continue to login page"<<endl;
	getch();
	}
	void room_detail()
	{
cout<<"rooms present :"<<10<<endl;
cout<<"rooms booked  :"<<teleno.size()<<endl;
getch();
	}
	void generate_bill(long long int phoneno,int chekout)
        {
             int i,cal=1,j,ord,temp,x;
            for(i=0;i<teleno.size();i++)
            {x=0;
                if(phoneno==teleno[i])
                {x=1;
                    for(j=0;j<ordtel.size();j++)
                    {
                        if(ordtel[j]==phoneno)
                        {
                         if(order[j]=="foodservice")
                         {
                             cout<<"foodcost : "<<item[j]<<endl;
                             temp=item[j];
                             break;
                         }
                        }
                    }
                    cal=chekout-check_indate[i];
                    if(roomtype[i]=="AC")
                    cal=cal*500;
                    else
                        cal=cal*400;
                       cal=cal+temp;
                    cout<<"name of the customer:          "<<name[i]<<endl;
                    cout<<"address of the customer:       "<<address[i]<<endl;
                    cout<<"telephone of the customer:     "<<teleno[i]<<endl;
                    cout<<"checkindate of the customer:   "<<check_indate[i]<<endl;
                    cout<<"checkoutdate of the customer:  "<<chekout<<endl;
                    cout<<"roomtype of the customer:      "<<roomtype[i]<<endl;
                    cout<<"charge of the customer:        "<<cal<<endl;
                    break;
                }
            }
            if(x==0)
                cout<<"entered number is not found"<<endl;
            cout<<endl;
            cout<<"press enter to continue to login page"<<endl;
            getch();
	}
}rep;

class food
{
public:
    string item;
};


class room
{
public:
    string location;
    int roomno;

};


class AC:public room
{
};


class nonAC:public room
{
};


class stock
{

};
//prototypes
int stafflogin(string,char []);
int managerlogin(string,char []);
void login_pageofsta(receptionist );
void login_pageofman(Manager );
main()
{
    time_t t;
    int ch;
    int expect,test;
    string username;
    char pass[10];
    char cha;
    int returnman,returnsta,i,k;
        system("cls");
cout<<  endl << endl << endl<< endl;
	cout<<"                             WELCOME TO TAJ HOTEL  "<<endl;
	cout<<"  	                            SUATHKAL,NITK       "<< endl;
	cout<<"                             INDIVIDUAL  ASSINGMENT         "<< endl;
	cout<<"                                       ON                   "<< endl;
	cout<<"                       HOTEL MANAGEMENT SYSTEM in C++  "<< endl;
	cout<<"              ____________________________________________________  "<< endl;
	cout<<  endl << endl << endl<< endl;
	cout<<"                  SUBMITTED BY:		      SUBMITTED TO:     "<<endl;
	cout<<"                   Kalyan Kumar          Ms. Raksha mam   "<<endl;
	cout<<  endl << endl;
	cout<<"              Press Enter to continue...." << endl << endl << endl << endl;
    getch();


while(1){
    t=time(NULL);
	cout<<"\n                                                        "<<ctime(&t);
	t -= 24L*60L*60L;
	char choice;
	cout<<  endl << endl << endl<< endl;
	cout<<"                            LOGIN SCREEN\n";
	cout<<"              ____________________________________________________  "<< endl;
	cout<<"                          1.Administrator Login\n";
	cout<<"                          2.staff Login\n";
	cout<<"                          3.Exit\n";
	cout<<"\n\n\n";
	cout<<"Enter Choice::   ";
	cin>>choice;
    switch(choice)
	{
	case'1':
		system("cls");
		cout<<"\t\t\t\t\tMANAGER LOGIN"<<endl;
		cout<<endl;
		cout<<"\t\t\t\t\tenter username = ";
        cin>>username;
        cout<<endl;
        cout<<"\t\t\t\t\tenter 5 digit password = ";
		for(i=0;i<5;i++)
            cin>>pass[i];
		returnman=managerlogin(username,pass);
		if(returnman==10)
		login_pageofman(man);
		break;
	case '2':
	    system("cls");
	    cout<<"\t\t\t\t\tSTAFF LOGIN"<<endl;
	    cout<<endl;
	    cout<<"\t\t\t\t\tenter username = ";
        cin>>username;
        cout<<endl;
        cout<<"\t\t\t\t\tenter 5 digit password = ";
	    for(i=0;i<5;i++)
            cin>>pass[i];
		returnsta=stafflogin(username,pass);
		if(returnsta==10)
		login_pageofsta(rep);
		break;
	case'3':
		exit(0);
		break;
	default:
		cout<<"wrong choice entered";
	}
    }
}

int stafflogin(string username,char pass[])
{
int status;
        cout<<endl;
		if(username=="staff"&&pass[0]=='s'&&pass[1]=='t'&&pass[2]=='a'&&pass[3]=='f'&&pass[4]=='f')
		{
			cout<<"\t\t\t-----------------access granted----------------"<<endl;
		    cout<<"\t\t\t-----------------press enter to continue to login page-------"<<endl;
		    getch();
		    status=10;
    }
    else
    {
        cout<<endl;
        cout<<"there is a mistake in login"<<endl;
        cout<<endl;
        cout<<"press enter to continue"<<endl;
        getch();
        status=20;
    }
return status;
}
int managerlogin(string username,char pass[])
{
    int status;
        cout<<endl;
		if(username=="admin"&&pass[0]=='a'&&pass[1]=='d'&&pass[2]=='m'&&pass[3]=='i'&&pass[4]=='n')
		{
		    cout<<"---------------------access granted-----------------"<<endl;
		    cout<<"---------------------press enter to continue to login page--------"<<endl;
		    getch();
		    status=10;
		}
		else
        {
            cout<<endl;
        cout<<"there is a mistake in login"<<endl;
        cout<<endl;
        cout<<"press enter to continue"<<endl;
        getch();
        status=20;
        }
        return status;
}

void login_pageofsta(receptionist s)
	{
	    string nam,add;
	    long long int tel;
	    int yer,mon,dat,cha;
	    string typ;
	    string feedback;
	    long long int phoneno;
	    int checkout;
	    int x,k;
while(1)
    {
        int ch;
        system("cls");
    cout<<"--------------------------loggedin successfully--------------------------"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"                               HOTEL TAJ                                 "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"1.add customer                       |5.display all customers"<<endl;
    cout<<"2.checkout customer                  |6.generate bill"<<endl;
    cout<<"3.exit                               |7.chef"<<endl;
    cout<<"4.room details                       |8.hotel attendant "<<endl;
    cout<<endl;
    cout<<"enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        cout<<"enter the name of the customer"<<endl;
	    cin>>nam;
	    cout<<"enter the address of the customer"<<endl;
	    cin>>add;
	    cout<<"enter the telephone no of customer"<<endl;
	    cin>>tel;
        do
        {cout<<"\nEnter Room Type :(AC=5000;NAC=4000) ";
        cin>>typ;
        if(typ=="AC"||typ=="NAC")
            ;
        else
        {
            cout<<"invalid roomtype"<<endl;
        }
        }while(!(typ=="AC"||typ=="NAC"));
    do{
            x=0;
             cout<<"\nYear : ";
        cin>>yer;
        cout<<"\nMonth : ";
        cin>>mon;
        cout<<"\nDate : ";
        cin>>dat;
    if((mon==2) && (dat>29))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    x=1;
  }
  if((mon>12)||(dat>31))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    x=1;
  }
  if((mon==4||mon==6||mon==9||mon==11) && (dat>30))
      {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    x=1;
  }
  if((yer%4)!=0 && (mon==2) && (dat>28))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    x=1;
  }}while(x==1);
        s.add_customer(nam,add,tel,yer,mon,dat,typ);
        break;
    case 2:
          cout<<"enter the telephone of the customer"<<endl;
          cin>>tel;
          cout<<"submit feedback[as good or average]"<<endl;
          cin>>feedback;
        s.checkout_customer(feedback,tel);
        break;
    case 3:
        return;
        break;
    case 5:
        system("cls");
        s.display_customer();
        break;
    case 4:
        s.room_detail();
        break;
    case 6:
          cout<<"enter the telephone of the customer"<<endl;
            cin>>phoneno;
            cout<<"enter the check out date of the given customer"<<endl;
            cin>>checkout;
        s.generate_bill(phoneno,checkout);
        break;
    case 7:
        s.prepareorder();
        break;
    case 8:
        s.orderdelivery();
        break;
    }}
}

void login_pageofman(Manager m)
{
    int ch;
    string staffname;
    long long int statel;
    while(1){
    system("cls");
    cout<<"--------------------------loggedin successfully--------------------------"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"                               HOTEL TAJ                                 "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"1.add staffmember             |2.display staffmembers            |3.exit"<<endl;
    cout<<endl;
    cout<<"enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"enter the name of staff"<<endl;
    cin>>staffname;
    cout<<"enter the tel no of staff"<<endl;
    cin>>statel;
    m.add_staff(staffname,statel);
    break;
    case 2:
        m.displaystaff();
        break;
    case 3:
        return;
        break;
        default :cout<<"invalid option"<<endl;
        break;
    }
    }
}
