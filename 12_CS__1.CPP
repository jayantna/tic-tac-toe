#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<iomanip.h>

int winner(char [3][3],char , char);          //Fuction prototype
class scr
 { char result1,result2;
  public:
   void win(char,char);
   void dispwin();
 }reslt;

class menu
{ public:
 char plr1[20],plr2[20];

  void play();
  void instructn();
  void about();
  void getname()
   { gets(plr1);
     gets(plr2);
   }

  class player
   {
      int handle1,handle2,c1,c2;

     public:
      int loc;
      void gethandle(char);

      int puthandle1()
	{return (handle1);}

      int puthandle2()
	{return (handle2);}

	int coordinate1()
	{return c1;}

	int coordinate2()
	{return c2;}


   }a,b;
 }p;

void main()
 {
    clrscr();
    int optn,insname=0;
  do
  {  clrscr();
     textcolor(YELLOW+BLINK);
     gotoxy(35,1);
     cprintf("Tic-Tac-Toe\n");
     textcolor(BLUE+GREEN);
     gotoxy(2,2);
     cprintf("1. Start Game\n");
     textcolor(BLUE+RED);
     gotoxy(2,3);
     cprintf("2. Instructions \n");
     textcolor(10);
     gotoxy(2,4);
     cprintf("3. Last Five Scores\n");
     textcolor(9);
     gotoxy(2,5);
     cprintf("4. About The Game\n");
     textcolor(11);
     gotoxy(2,6);
     cprintf("5. Exit\n\n");
     cout<<"Enter your choice: ";
     optn=getch();
     switch(optn)
      {
       case '1':if(insname==0)
		{
		clrscr();
		cout<<"Enter Two Players Name";
		p.getname();
		insname++;
		}
		p.play();
		break;
       case '2':clrscr();
		p.instructn();
		break;
       case '3':clrscr();
		reslt.dispwin();
		break;
       case '4':clrscr();
		p.about();
		break;
       default: break;
      }
  }
 while(optn!='5');
}

void menu:: play()
{  // variable declaration and graph draw
    int gd=DETECT,gm,r,l,m,i,turn=1,n,flag,h1,h2,k=0;
    char ch,grid[3][3];
    const char p1='x',p2='o';
    initgraph(&gd,&gm,"c:/turboc3/bgi");
    rectangle(200,200,400,400);
    line(270,200,270,400);
    line(330,200,330,400);
    line(200,270,400,270);
    line(200,340,400,340);
    settextstyle(3,0,5);
   //

r:
    n=10;
    if (turn%2==0)
       { gotoxy(31,7); cout<<p.plr2<<" turn(O)    "; }
    else
     { gotoxy(31,7); cout<<p.plr1 <<" turn(X)     "; }
    turn++;
    if(ch==27)
      goto mainmenu;
    while(kbhit()==0&&n!=0)            //Timer
     {
      gotoxy(34,12);
      cout<<"Timer: "<<setw(2)<<n--;
      sound(2000);
      delay(10);
      nosound();
      delay(990);
     }
    if(kbhit()!=0)
     {
       ch=getch();
       gotoxy(33,9);
       cout<<"Last turn: "<<ch<<endl<<"\t\t\t    ";
      switch(ch)                             //Set graph coordinate
	{

	  case '7':l=225,m=220;//
	     break;
	  case '8':l=295,m=220;//
	     break;
	  case '9':l=360,m=220;//
	     break;
	  case '4':l=225,m=280;//
	     break;
	  case '5':l=295,m=280;//
	     break;
	  case '6':l=360,m=280;//
	     break;
	  case '1':l=225,m=350;//
	     break;
	  case '2':l=295,m=350;//
	     break;
	  case '3':l=360,m=350;//
	  default:
	     break;
	}

    settextstyle(3,0,5);               //Players Symbol Font
    if(turn%2!=0)                      //Player 2
      {
	b.gethandle(ch);
	h1=b.puthandle1();
	h2=b.puthandle2();
	l=b.coordinate1();
	m=b.coordinate2();
	grid[h1][h2]=p2;
	outtextxy(l,m,"O");
	k++;
	flag=winner(grid,p1,p2);
	if(flag==1||flag==2)
	goto s;
       }
    else                                 //Player 1
       {
	a.gethandle(ch);
	h1=a.puthandle1();
	h2=a.puthandle2();
	l=a.coordinate1();
	m=a.coordinate2();
	grid[h1][h2]=p1;
	outtextxy(l,m,"X");
	k++;
	flag=winner(grid,p1,p2);
	if(flag==1||flag==2)
	goto s;
       }
    if(k==9)
      { gotoxy(35,8);
	cout<<"Game Draw";
	reslt.win('D','D');
	goto s;}
    goto r;
     }
s:

    if(n==0&&turn%2!=0)                             //if no turn played
    {
      gotoxy(30,7);
      cout<<p.plr1<<" is the winner";
      reslt.win('W','L');
    }
    if(n==0&&turn%2==0)                             //if no turn played
    {
     gotoxy(30,7);
     cout<<p.plr2<<" is the winner";
     reslt.win('L','W');
    }
mainmenu:
    getch();
    closegraph();
    restorecrtmode();

}

void menu::instructn()
{
 textcolor(BLUE+RED);
 gotoxy(35,2);
 cprintf("GAME INSTRUCIONS\n");
 gotoxy(1,4);
 cout<<"It is a Two player game.Player 1 has a chance to play first.Each Player\n" ;
 cout<<"has 10 seconds to play his shot.If any player is fail to play his shot in\n";
 cout<<"10 seconds then the other player will be declared as winner.Players can make\n";
 cout<<"their choice with the help of numpad given in your keyboard.Boxes are numbered\n";
 cout<<"same as numbering of numpad.";
 cout<<"\nPress Esc key to leave game\nPress any key to continue...";
 getch();

}

void menu::about()
{
 textcolor(9);
 gotoxy(1,2);
 cout<<"Made by :";
 textcolor(9);
 {
  gotoxy(4,3);
  cprintf("ANIRUDH ROY(12123)");
  gotoxy(4,4);
  cprintf("JAYANT NAGLE(12129)");
  gotoxy(4,5);
  cprintf("K.PRATYUSH KUMAR (12130)\n");
  gotoxy(4,6);
  cprintf("Rajat Singh (12139)\n");
  cout<<"Press any key to continue...";
 }
 getch();
}

void player::gethandle(char loc)
    {

	switch(loc)
	{
		case '1':
		      handle1=2;
		      handle2=0;
		      c1=225,c2=350;
		      break;
		case '2':
		      handle1=2;
		      handle2=1;
		      c1=295,c2=350;
		      break;
		case '3':
		      handle1=2;
		      handle2=2;
		      c1=360,c2=350;
		      break;
		case '4':
		      handle1=1;
		      handle2=0;
		      c1=225,c2=280;
		      break;
		case '5':
		      handle1=1;
		      handle2=1;
		      c1=295,c2=280;
		      break;
		case '6':
		      handle1=1;
		      handle2=2;
		      c1=360,c2=280;
		      break;
		case '7':
		      handle1=0;
		      handle2=0;
		      c1=225,c2=220;
		      break;
		case '8':
		      handle1=0;
		      handle2=1;
		      c1=295,c2=220;
		      break;
		case '9':
		      handle1=0;
		      handle2=2;
		      c1=360,c2=220;
		      break;
	}
     }

int winner(char grid[3][3],char p1, char p2)
 {
    //horizontal
    int i,win=0;
    for(i=0;i<3;i++)
    {
      if(grid[i][0]==grid[i][1])
	{
	 if(grid[i][1]==grid[i][2])
	  {
	   if(grid[i][1]==p1)
	     {cout<<p.plr1<<" is the winner\n";win= 1;
	      reslt.win('W','L');}
	   else
	     {cout<<p.plr2<<" is the winner\n";win= 2;
	      reslt.win('L','W');}
	  }
	}
	 else
	  continue;

     }

    //Vertical
    for(i=0;i<3;i++)
    {
      if(grid[0][i]==grid[1][i])
	{
	 if(grid[1][i]==grid[2][i])
	   {
	    if(grid[1][i]==p1)
	      {cout<<p.plr1<<" is the winner\n";win= 1;
	       reslt.win('W','L');}
	    else
	      {cout<<p.plr2<<" is the winner\n";win= 2;
	       reslt.win('L','W');}
	   }
	}
      else
	continue;

    }

    //Diagonal
    if(grid[0][0]==grid[1][1])
      {
       if(grid[1][1]==grid[2][2])
	 {
	  if(grid[1][1]==p1)
	    {cout<<p.plr1<<" is the winner\n";win= 1;
	     reslt.win('W','L');}
	  else
	    {cout<<p.plr2<<" is the winner\n";win= 2;
	     reslt.win('L','W');}
	 }
      }

    if(grid[0][2]==grid[1][1])
      {
       if(grid[1][1]==grid[2][0])
	 {
	  if(grid[1][1]==p1)
	    {cout<<p.plr1<<" is the winner\n";win= 1;
	     reslt.win('W','L');}
	  else
	    {cout<<p.plr2<<" is the winner\n";win= 2;
	     reslt.win('L','W');}
	 }
      }
  return win;
 }

void scr::win(char a,char b)
    { int sno=1;
      char result1=a,result2=b;
      char line1[50],line2[50],line3[50],line4[50];
      ofstream fout("temp.txt",ios::app|ios::out);
      ofstream foutp("score.txt",ios::out|ios::app);
      ifstream fin("score.txt",ios::in);

      fout<<"sno\tPlayer1 \t\tPlayer2\n";
      int pos=fout.tellp();
      if(result1=='W'&&result2=='L')
       {
	 fout<<sno<<"\t"<<p.plr1<<" win\t\t"<<p.plr2<<" lose"<<endl;
       }
      else if(result1=='L'&&result2=='W')
       {
	 fout<<sno<<"\t"<<p.plr1<<" lose\t\t"<<p.plr2<<" win"<<endl;
       }
      else
       {
	 fout<<sno<<"\t"<<p.plr1<<" draw\t\t"<<p.plr2<<" draw"<<endl;
       }
      fin.seekg(pos+1,ios::beg);

      fin.getline(line1,51);
      gotoxy(2,1);
      fout<<"2";
      fout<<line1<<endl;

      fin.seekg(1,ios::cur);
      fin.getline(line2,50);
      gotoxy(3,1);
      fout<<"3";
      fout<<line2<<endl;

      fin.seekg(1,ios::cur);
      fin.getline(line3,51);
      gotoxy(4,1);
      fout<<"4";
      fout<<line3<<endl;

      fin.seekg(1,ios::cur);
      fin.getline(line4,51);
      gotoxy(5,1);
      fout<<"5";
      fout<<line4<<endl;

      fout.close();
      fin.close();
      remove("score.txt");
      rename("temp.txt","score.txt");

    }

void scr::dispwin()
 {
  char line1[50],line2[50],line3[50],line4[50],line5[50],line6[50];
  ifstream fin("score.txt",ios::in);
  fin.getline(line1,50);
  cout<<line1<<endl;
  fin.getline(line2,50);
  cout<<line2<<endl;
  fin.getline(line3,50);
  cout<<line3<<endl;
  fin.getline(line4,50);
  cout<<line4<<endl;
  fin.getline(line5,50);
  cout<<line5<<endl;
  fin.getline(line6,50);
  cout<<line6<<endl;
  getch();
 }