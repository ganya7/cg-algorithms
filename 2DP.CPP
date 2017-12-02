#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int xc = getmaxx()/2;
int yc = getmaxy()/2;
double result[3][3];
// double trikone[3][3] = { {100,100,1}, {150,50,1}, {200,100,1}};
double trikone[4][4] = { {200,200,1}, {300,200,1}, {300,300,1}, {220,310,1} };
void matmul(double trans[3][3]){
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
				result[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					result[i][j] += trikone[i][k] * trans[k][j];
				}
		}	
	}
}

void drawres(){
	/*line(300+result[0][0],result[0][1],300+result[1][0],result[1][1]);
	line(300+result[0][0],result[0][1],300+result[2][0],result[2][1]);
	line(300+result[1][0],result[1][1],300+result[2][0],result[2][1]);*/
	line(xc+result[0][0],yc-result[0][1],xc+result[1][0],yc-result[1][1]);
	line(xc+result[0][0],yc-result[0][1],xc+result[3][0],yc-result[3][1]);
	line(xc+result[1][0],yc-result[1][1],xc+result[2][0],yc-result[2][1]);
	line(xc+result[2][0],yc-result[2][1],xc+result[3][0],yc-result[3][1]);
}

void shape()
{
	/*line(trikone[0][0],trikone[0][1],trikone[1][0],trikone[1][1]);
	line(trikone[0][0],trikone[0][1],trikone[2][0],trikone[2][1]);
	line(trikone[1][0],trikone[1][1],trikone[2][0],trikone[2][1]);*/
	line(xc+trikone[0][0],yc-trikone[0][1],xc+trikone[1][0],yc-trikone[1][1]);
	line(xc+trikone[0][0],yc-trikone[0][1],xc+trikone[3][0],yc-trikone[3][1]);
	line(xc+trikone[1][0],yc-trikone[1][1],xc+trikone[2][0],yc-trikone[2][1]);
	line(xc+trikone[2][0],yc-trikone[2][1],xc+trikone[3][0],yc-trikone[3][1]);
}


void translate(){
	double tx,ty;
	cout<<"\nEnter x translate:";
	cin>>tx;
	cout<<"\nEnter y translate:";
	cin>>ty;
	double trans[3][3] = { {1,0,0}, {0,1,0}, {tx,ty,1} };
	matmul(trans);
	cout<<"\nAfter translate: ";
	drawres();
}

void rotate(){
	double theta;
	cout<<"\nEnter angle of rotation: ";
	cin>>theta;
	double deg = (theta * 3.14) / 180;
	if (theta > 0)
	{
		double rotate[3][3] = { {cos(deg),sin(deg),0}, {-sin(deg),cos(deg),0}, {0,0,1} };
		matmul(rotate);
		drawres();
	}
	else
	{
		double rotate1[3][3] = { {cos(deg),-sin(deg),0}, {sin(deg),cos(deg),0}, {0,0,1} };
		matmul(rotate1);
		drawres();
	}
}
void shear(){
	double shx,shy;
	cout<<"\nEnter shear in x direction";
	cin>>shx;
	cout<<"\nEnter shear in y direction";
	cin>>shy;
	double shear[3][3] = { {1,shx,0}, {shy,1,0}, {0,0,1} };
	matmul(shear);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"shx: "<<shear[0][1];
	cout<<"\nshy: "<<shear[1][0];
	drawres();

}

void scale(){
	double sx,sy;
	cout<<"\nEnter scale in x: ";
	cin>>sx;
	cout<<"\nEnter scale in x: ";
	cin>>sy;
	double sc[3][3] = { {sx,0,0}, {0,sy,0}, {0,0,1} };
	matmul(sc);
	drawres();
}

void reflect(){

	double refl[3][3] = { {-1,0,0}, {0,1,0}, {0,0,1} };
	matmul(refl);
	cout<<"\nmultuplied";
	drawres();
}

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	//cout<<"\nBefore rotate: ";
	// cout<<"\nBefore translate: ";
	// cout<<xc<<" "<<getmaxx();
	// line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	//xc = getmaxx()/2;w
	//yc = getmaxy()/2;
	xc=0;
	yc=0;
	line(xc,0,xc,getmaxy());
	line(0,yc,getmaxx(),yc);
	shape();
	// translate();
	// rotate();
	setcolor(RED);
	//translate();
	//rotate();
	// rotate();
	shear();
       //reflect();
	// scale();
	getch();
}