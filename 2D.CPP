#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

float trikone[3][3] = { {100+200,150+200,200+200}, {100+200,200+50,200+100}, {1,1,1} };

float result[3][3] = {0};

void matmul(float a[3][3], float b[3][3])
{
	int i,j,k;
	int c[3][3];
	for ( i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			result[i][j]=0;
			for ( k = 0; k < 3; k++)
			{
				result[i][j] +=  a[i][k]*b[k][j];
			}
		}
	}
}

void drawres()
{
	line(result[0][0],result[1][0],result[0][1],result[1][1]);
	line(result[0][0],result[1][0],result[0][2],result[1][2]);
	line(result[0][1],result[1][1],result[0][2],result[1][2]);
}

void shape()
{
	line(trikone[0][0],trikone[1][0],trikone[0][1],trikone[1][1]);
	line(trikone[0][0],trikone[1][0],trikone[0][2],trikone[1][2]);
	line(trikone[0][1],trikone[1][1],trikone[0][2],trikone[1][2]);
}

void translate()
{
	shape();
	cout<<"\nEnter translation in x-direction: ";
	int tx,ty;
	cin>>tx;
	cout<<"\nEnter translation in y-direction: ";
	cin>>ty;
	float translate[3][3] = { {1,0,tx} , {0,1,ty}, {0,0,1} };
	matmul(translate,trikone);
	drawres();
}

void scale()
{
	shape();
	int sx,sy;
	cout<<"\nEnter scale in x-direction: ";
	cin>>sx;
	cout<<"\nEnter scale in y-direction: ";
	cin>>sy;
	float scale[3][3] = { {sx,0,0}, {0,sy,0}, {0,0,1} };
	matmul(scale,trikone);
	drawres();
}

void rotate()
{
	shape();
	int theta;
	cout<<"\nEnter angle of rotation: ";
	cin>>theta;
	float deg = theta*0.01744;
	if (theta > 0)
	{
		float rotate[3][3] = { {cos(deg),sin(deg),0}, {-sin(deg),cos(deg),0}, {0,0,1} };
		matmul(rotate,trikone);
		drawres();
	}
	else
	{
		float rotate1[3][3] = { {cos(deg),-sin(deg),0}, {sin(deg),cos(deg),0}, {0,0,1} };
		matmul(rotate1,trikone);
		drawres();
	}
}

void shear()
{
	shape();
	int shx,shy;
	cout<<"\nEnter shear in x-direction: ";
	cin>>shx;
	cout<<"\nEnter shear in y-direction: ";
	cin>>shy;
	float shear[3][3] = { {1,shx,0}, {shy,1,0}, {0,0,1} };
	matmul(shear,trikone);
	drawres();

}

void reflect()
{
	// float reflect[3][3] = {0};
	shape();
	cout<<"\nReflection about: \n1.x-axis \n2.y-axis \n3.Origin \n4.xy-plane";
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	int ch;
	cout<<"\nEnter choice: ";
	cin>>ch;
	if(ch==1)
	{
		float reflect[3][3] = { {1,0,0}, {0,-1,0}, {0,0,1} };
		matmul(reflect,trikone);
		drawres();
		
	}
	else if(ch==2)
	{
		float reflect[3][3] = { {-1,0,0}, {0,1,0}, {0,0,1} };
		matmul(reflect,trikone);
		drawres();
	}
	else if(ch==3)
	{
		float reflect[3][3] = { {-1,0,0}, {0,-1,0}, {0,0,1} };
		matmul(reflect,trikone);
		drawres();
		
	}
	else if(ch==4)
	{
		float reflect[3][3] = { {1,0,0}, {0,-1,0}, {0,0,1} };
		matmul(reflect,trikone);
		drawres();
	}
	else if(ch==5)
	{
	float reflect[3][3] = { {1,0,0}, {0,-1,0}, {0,0,1} };
	matmul(reflect,trikone);
	drawres();
		
	}


}

int main()
{
	int ch;
	int gd=DETECT,gm;
	do
	{
		clrscr();
		cout<<"\nMenu: \n1.Translation \n2.Scaling \n3.Rotation \n4.Shearing \n5.Reflection \n6.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		switch(ch)
		{
			case 1: translate();
			break;
			case 2: scale();
			break;
			case 3: rotate();
			break;
			case 4: shear();
			break;
			case 5: reflect();
			break;
			case 6: exit(0);
			break;
			default: cout<<"\nWrong choice!!!";

		}getch();
		cleardevice();
		closegraph();
	}while(1);
	return 0;
}