/* CG Practical Assignments - Mini Project

******************SNAKE GAME********************

Name: Vaishnavi Anant Gurav
Rollno: SC222

Problem Statement:
Make an animation clip or game. Use OOP concepts.
*/

#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

//class named snakegame
class snakegame
{
	public:
		void init();
		int snake();
		int endfunc(int e,int a);
		void close();
};

//method to initialize graph
void snakegame::init()
{
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
}

//method for snake function
int snakegame::snake()
{
    int rx=200,ry=200,x[200],y[200],d;
    
	//x and y array for snake size 200 initializing them to zero
	for(int i = 0;i < 200 ; i++)
	{
        x[i]=0;
        y[i]=0;
    }
    
    //Food intake
    int f=1;
    int chk = 700;
    
    //directions
    int dir=1;
    
    setfillstyle(1,1);//(style,color)
	//snakes head to 200
	x[0]=200,y[0]=200;
    d=1;

	// lenth of snake 
    int length = 1;
	
	for(;;)
	{

	    setfillstyle(1,0);
	    bar(0,0,640,480);
	    setfillstyle(1,2);
		//bars around
	    bar(0,0,640,10);
	    bar(0,0,10,480);
	    bar(0,480,640,470);
	    bar(630,10,640,480);
	    
		// food taken?
		if(x[0]==rx && y[0]==ry )
		{
		    length += 1;
		    f=f+1;
		    setfillstyle(1,0);
			//drawing black bar over food (food disapper)
		    bar(rx,ry,rx+10,ry+10);
		
		    //make food
		    do{
			//coordiated of food
			rx = (1+rand()%630);
			ry = (1+rand()%470);
		    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);
		
			//divide for round nos
		    rx=rx/10;
		    rx=rx*10;
		    ry=ry/10;
		    ry=ry*10;
		    setfillstyle(1,2);
		}

		//food bar
	    bar(rx,ry,rx+10,ry+10);

		//keys for directions
	    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
	    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
	    else if(GetAsyncKeyState(VK_UP)){ d=3;}
	    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
	    else{d=0;}
	    
		//change in position when key pressed
	    switch(d)
		{
			//no key pressed
			case 0:
				if(dir==1){x[0]=x[0]+10;}
			    else if(dir==2){x[0]=x[0]-10;}
			    else if(dir==3){ y[0]=y[0]-10;}
			    else if(dir==4) {y[0]=y[0]+10;}
			    else{d=0;}
			    break;
			//right
			case 1:
				x[0]=x[0]+10;
			    dir=1;
			    break;
			//left
			case 2:
				x[0]= x[0]-10;
			    dir=2;
			    break;
			//top
			case 3:
				dir=3;
			    y[0]=y[0]-10;
			    break;
			//bottom
			case 4:
				dir=4;
			    y[0]= y[0]+10;
			    break;
		}
		    
	    
		//move body 
    	for(int i = 0; i < length;i++)
		{
        	bar(x[i],y[i],x[i]+10,y[i]+10);
    	}
    	for(int i= 199; i >0;i--)
		{
	        x[i] = x[i-1];
	        y[i] = y[i -1];
	    }
	    delay(100);

		//call snake die
	    if(x[0] >= 640 || x[0]<=0|| y[0]<=0 || y[0]>=480)
		{
		    endfunc(f,0);
	    	break;
    	}
		//defining chk variable
	    for(int i = 2; i < length;i++)
		{
	        if(x[0] == x[i] && y[0] == y[i])
			{
	            chk = i;
	            break;
	        }
	    }
	    if(x[0] == x[chk] && y[0] == y[chk])
		{
		    endfunc(f,1);
		    break;
	    }
	    
	}
}

//method to close graph
void snakegame::close()
{
    getch();
    closegraph();
}

//method to display end of game
int snakegame::endfunc(int e,int a)   //death of snake
{
    setfillstyle(1,5);
    e=e-2;
    bar(0,0,640,470);
    system("cls");
    if(a == 0){
        printf("You died outside the boundary!!!\n");
    }
    else if(a == 1){
        printf("You died into yourself!!!\n");
    }
    printf("Your score is : %d\n", e);
    getch();
    return 0;
}

//main function
int main()
{
	//object snake1 of class snakegame
	snakegame snake1;
	snake1.init();
	snake1.snake();
	snake1.close();
}


