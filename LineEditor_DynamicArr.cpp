#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void LineEditor();

int main()
{
  clrscr();
  LineEditor();
  return 0;
}


void LineEditor()
{
  //ch is a char type to get input from user then check it
  char ch;
  // size --> size of dynamic array in heap
  int size;
  char *Line;
  cout<<"Enter Size of Array = "<<endl;
  cin>>size;
  Line = new char[size];

  int row = 3;
  int col = 1;
  /* flag = 1 is defult to be in do loop,
     When user enter 'Esc' flag = 1
     When user enter 'Enter' the Lineeditor prints the o/p then Exits */
  int flag = 1;
  int i;

  if(Line != NULL)
  {
    // To inisalize array to be null char
    for(i = 0 ; i < size ; i++)
    {
      *(Line+i) = '\0';
    }

    do
    {
      /* We have 3 main cases
	     1- When user enter Printable Character
	     2- When User enter Extended Key ( --> , <-- , home, end)
	     3- When User enter Normal Key ( Enter, Esc ) */

      ch = getch();
      // 1-Printable Character
      if(isprint(ch))
      {
	       // Check that array can accept new character and we don't get out array boundary
	       if(strlen(Line) < size)
	       {
	         *(Line+(col-1)) = ch;
	         gotoxy(col,row);
	         cout<<*(Line+(col-1));
	         col+=1;
	       }
      }
      else
      {
	       // 2-Extended Key
	       if(ch == 0)
	       {
	         ch = getch();
	         switch(ch)
	         {
	           /* Left -->
	           When user Enter --> the cursor goes to the next index  */
	           case 75:
	           {
	             // To check That cursot dosen't move when array is empty
	             if(strlen(Line)> 1)
	             {
		              col-=1;
		              if(col<1)
		              {
		                //To check that cursor dosen't get out array boundary
		                col = 1;
		              }
		              gotoxy(col,row);
	             }
	             break;
	           }
             /* Right <--
	           When user Enter <-- the cursor goes to the previous index  */
	           case 77:
	           {
	             // To check That cursot dosen't move when array is empty
	             if(strlen(Line)> 1)
	             {
		              col+=1;
		              if(col>strlen(Line))
		              {
		                //To check that cursor dosen't get out array boundary
		                col = strlen(Line);
		              }
		              gotoxy(col,row);
	             }
	             break;
	           }
            /* Home
	           When user Enter 'home' the cursor gose to the first index  */
	           case 71:
	           {
	             col = 1;
	             gotoxy(col,row);
	             break;
	           }
            /* End
	           When user Enter 'End' the cursor gose to the last index  */
	           case 79:
	           {
	             col = strlen(Line);
	             gotoxy(col,row);
	             break;
	           }
	         }
	       }
	       else
	       {
	         // 3-Normal Key
	         switch(ch)
	         {
	           /* Enter
	           When user Enter 'Enter' the program prints the content of array
	           then exits  */
	           case 13:
	           {
	             col = 1;
	             gotoxy(col,row);
	             cout<<Line;
	             flag = 0;
	             break;
	           }
            /* Esc
	           When user Enter 'Esc' the program exits  */
	           case 27:  //Esc
	           {
	             flag = 0;
	             break;
	           }
	         }
	       }
      }
    }while(flag == 1 );
    delete(Line);
  }
  else
  {
    cout<<"We have a problem with heap"<<endl;
  }
}
