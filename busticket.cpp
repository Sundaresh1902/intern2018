#include <conio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class a
{
    char busno[5], dname[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
    public:
    void registration();
    void booking();
    void empty();
    void display();
    void buses();
    void position(int i);
}
bus[10];
void a::registration()
{

  cout<<"Enter bus no: ";

  cin>>bus[p].busno;

  cout<<"\nEnter dname's name: ";

  cin>>bus[p].dname;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].to;

  bus[p].empty();

  p++;

}

void a::booking()

{

  int seat;

  char number[5];

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;
  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busno, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats busesable in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::display()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busno, number)==0)

    break;

  }

while(n<=p)
{
  cout<<"Bus no: \t"<<bus[n].busno
  <<"\ndname: \t"<<bus[n].dname<<"\n\t\tArrival time: \t"

  <<bus[n].arrival<<"\n\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\n\t\tTo: \t\t"<<

  bus[n].to<<"\n";
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
    break;
   }
    if(n>p)
        cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
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

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busno;

  }

void a::buses()

{


   for(int n=0;n<p;n++)

  {
    cout<<"Bus no:"<<bus[n].busno;
    cout<<"\ndname:"<<bus[n].dname;
    cout<<"\nArrival time:"<<bus[n].arrival;
    cout<<"\nDeparture Time:";
    cout<<bus[n].depart;
    cout<<"\nFrom:"<<bus[n].from;
    cout<<"\nTo:"<<bus[n].to<<"\n";
  }

}

int main()
{
    int w;
    while(1)
    {
        cout<<"1.registration\n\n"<<"2.Reservation\n\n"<<"3.display\n\n"<<"4.Buses busesable. \n\n"<<"5.Exit";cout<<"\n\nEnter your choice:->\n";
        cin>>w;
        switch(w)
        {
            case 1:  bus[p].registration();
                    break;
            case 2:  bus[p].booking();
                    break;
            case 3:  bus[0].display();
                    break;
            case 4:  bus[0].buses();
                    break;
            case 5:  exit(0);
        }
}
return 0;
}
