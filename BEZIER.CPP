#include<iostream.h>
#include<conio.h>
//#include<math.h>
#include<graphics.h>

double power(double a, int b)
{
	double result=1.0;
		while(b>0)
		{
			result*=a;
			b--;
		}
		return result;
}

int binomialCoeff(int n, int k)
{
	int res = 1;

    // Since C(n, k) = C(n, n-k)
	if ( k > n - k )
		k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

void bezier(int *x, int *y,int n)
{
	double t,xt=0.0,yt=0.0;
	int i,deg;


	for(t = 0.0; t < 1.0; t += 0.0001)
	{
		xt=0.0;
		yt=0.0;
		for(deg = 0; deg < n; deg++)
		{
			xt += binomialCoeff(n-1,deg) * power(1-t,n-1-deg) * power(t,deg) * x[deg];
			yt += binomialCoeff(n-1,deg) * power(1-t,n-1-deg) * power(t,deg) * y[deg];
		}
		putpixel(xt,yt,RED);
	}

	for (i=0; i<n; i++)
	{
		putpixel (x[i], y[i], YELLOW);
		if(i<n-1)
			line(x[i],y[i],x[i+1],y[i+1]);
	}
}

void main()
{
	int gd=DETECT,gm;
	int *x,*y;
	int i,n;
	initgraph(&gd,&gm,"c:\\TC\\BGI");
	cout<<"\nEnter number of control points: ";
	cin>>n;
	x = new int[n];
	y = new int[n];
	cout<<"\nEnter "<<n<<" pairs of (x,y) control points:\n ";
	for(i = 0; i < n; i++)
	{
		cout<<"\nEnter control point "<<i+1<<": ";
		cin>>x[i]>>y[i];
	}
	bezier(x,y,n);
	getch();
	closegraph();
	clrscr();
}