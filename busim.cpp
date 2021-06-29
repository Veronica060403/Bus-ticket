#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<string.h>
using namespace std;
int p=0;
class a
{
	char busn[5],driver[10],arrival[5],from[10],to[10],depart[5],seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	int i;
	for(i=80;i>0;i--)
	cout<<ch;
}
void a::install()
{
	cout<<"\n\tEnter bus no: ";
	cin>>bus[p].busn;
	cout<<"\n\tEnter Driver's name: ";
	cin>>bus[p].driver;
	cout<<"\n\tArrival time: ";
	cin>>bus[p].arrival;
	cout<<"\n\tDeparture time: ";
	cin>>bus[p].depart;
	cout<<"\n\tFrom: \t ";
	cin>>bus[p].from;
	cout<<"\n\tTo: \t ";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
	getch();
}
void a::allotment()
{
	int seat;
	char number[5];
	top:
	cout<<"\n\tBus no: ";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\n\tSeat Number: ";
		cin>>seat;
		if(seat>32)
			cout<<"\n\tTher are only 32 seats are available in this bus.";
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			{
				cout<<"\n\tEnter passenger's name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
				cout<<"\n\tThe seat no. is already reserved.\n";
		}
	}
	if(n>p)
	{
		cout<<"\n\tEnter correct bus no.\n";
		goto top;
	}
}
void a::empty()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void a::show()
{
	int n;
	char number[5];
	cout<<"\n\tEnter bus no: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"\n\tBus no: \t"<<bus[n].busn
		<<"\n\tDriver: \t"<<bus[n].driver
		<<"\n\tArrival time: \t"<<bus[n].arrival
		<<"\n\tDeparture time: "<<bus[n].depart
		<<"\n\tFrom: \t"<<bus[n].from
		<<"\n\tTo: \t"<<bus[n].to
		<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1,i,j;
		for(i=0;i<8;i++)
		{
			for(j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
					cout<<"\n\tThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>p)
		cout<<"\n\tEnter correct bus no: ";
}
void a::position(int l)
{
	int i,j,s=0;p=0;
	for(i=0;i<8;i++)
	{
		cout<<"\n";
		for(j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}
			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\n\tThere are "<<p<<" seats empty in bus no: "<<bus[l].busn;
}
void a::avail()
{
	int n;
	for(n=0;n<p;n++)
	{
		vline('*');
		cout<<"\n\tBus no: \t"<<bus[n].busn
		<<"\n\tDriver: \t"<<bus[n].driver
		<<"\n\tArrival time: \t"<<bus[n].arrival
		<<"\n\tDeparture time: "<<bus[n].depart
		<<"\n\tFrom: \t"<<bus[n].from
		<<"\n\tTo: \t"<<bus[n].to
		<<"\n";
	}
}
int main()
{
	system("cls");
	int w;
	while(1)
	{
		cout<<"\n\n\n";
		cout<<"\t1.Install\n"<<"\t2.Reservation\n"<<"\t3.Show\n"<<"\t4.Bus available\n"<<"\t5.Exit\n";
		cout<<"\n\tEnter your choice:---> ";
		cin>>w;
		switch(w)
		{
			case 1:
				bus[p].install();
				break;
			case 2:
				bus[p].allotment();
				break;
			case 3:
				bus[0].show();
				break;
			case 4:
				bus[0].avail();
				break;
			case 5:
				exit(0);
		}
	}
return 0;
}

