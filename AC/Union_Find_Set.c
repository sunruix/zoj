/*author: ¡ı∂¨Ïœ(tester)*/
/*algorithm: 1.Quick-sort the computers(infected by virus) by level
             2.in d day, union the computers(infected) whose defense level<=d and have not been 
               infected!
             3.in d day, after union the computers which can be unioned, judge the every blocks can be 
               infected by any type virus, if can, choose the smallest type*/
/*hint: I'm not programmer , so I write comments briefly ^_^ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zx[4]={0,-1,0,1},zy[4]={-1,0,1,0};
int n,m,minx,miny,mxy,CaseNum;
int Matrix[501][501],Pm[501][501];
struct Data{
	int x,y;
	int Level;
}a[501*501];
int lena;

int Ans_type[501*501];

int Bcj[501*501],fm[501*501][3];

int getx(int d)  /*following 3 functions are designed to change 2-dimension  to 1-dimension or 1-2.*/
{
	return d/m;
}

int gety(int d)
{
	return d%m;
}

int Coor(int x,int y)
{
	return x*m+y;
}

int Find(int d)  
{
	if (Bcj[d]<0) return d;
		else return Bcj[d] = Find(Bcj[d]);
}

int Contagious(int x, int y)  /*judge a computer is infected,if yes return viru's type, else a minus number*/
{
	int tmp = Find(Coor(x,y));
	return Matrix[getx(tmp)][gety(tmp)];
}

void Union(int x1,int y1,int x2,int y2)
{
	int d1 = Coor(x1,y1);
	int d2 = Coor(x2,y2);
	int r1 = Find(d1);
	int r2 = Find(d2);
	if (r1 == r2) return;
	else
	{
		int tmp = Matrix[getx(r1)][gety(r1)];
		int tmp2[3] = {fm[r1][0],fm[r1][1],fm[r1][2]};
		if (fm[r2][0]<tmp2[0]) {tmp2[0]=fm[r2][0]; tmp2[1]=fm[r2][1]; tmp2[2]=fm[r2][2];}
		if (Matrix[getx(r2)][gety(r2)] >0 ) tmp = Matrix[getx(r2)][gety(r2)];
		if (Bcj[r1]<Bcj[r2]) {
					Bcj[r1] += Bcj[r2];
					Bcj[r2] = r1;
				    fm[r1][0] = tmp2[0]; fm[r1][1] = tmp2[1]; fm[r1][2] = tmp2[2];
					if (tmp>0) Matrix[getx(r1)][gety(r1)]=tmp;
					}
				else
				     {
					Bcj[r2] += Bcj[r1];
					Bcj[r1] = r2;
					fm[r2][0] = tmp2[0]; fm[r2][1] = tmp2[1]; fm[r2][2] = tmp2[2];
					if (tmp>0) Matrix[getx(r2)][gety(r2)]=tmp;
                    }
	}
}

void Init()
{
	lena=0;
	int i,j,x;
	for (i = 0; i<n; i++)
	for (j = 0; j<m; j++)
	{
		scanf("%d",&x);
		Matrix[i][j] = x;
		Pm[i][j] = x;
		if (x<0)
		{
			a[lena].x = i;
			a[lena].y = j;
			a[lena].Level = x;
   			lena++;
		}
	}

	for (i = 0; i<501*501; i++) /*initialization*/
	{
		fm[i][0] = 32768888;
		Bcj[i] = -1;
		Ans_type[i] = 0;
	}
}

void Kp(int l,int r)  /*quick sort*/
{
	int i = l,j = r;
	int mid = a[(l+r) / 2].Level;
	struct Data tmp;
	do
	{
		while (a[i].Level > mid) i++;
		while (a[j].Level < mid) j--;
		if (i<=j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			    i++;
			    j--;
              }
	}while(i<=j);
	if (i<r) Kp(i,r);
	if (j>l) Kp(l,j);
}

void Deal(int x, int y)   /*union the computer with (x,y)computer  
                            if their defense level<=d and have not been infected!*/
{
	int i,xx,yy,tmp,min=32768888;
	for (i=0; i<4; i++)
	{
		xx = x+zx[i];
		yy = y+zy[i];
		if (xx>=0 && xx<n && yy>=0 && yy<m)
		{
			tmp = Contagious(xx,yy);
			if (tmp>0 && tmp < min) { min=tmp; minx=xx; miny=yy;}
			if (tmp<0 && Pm[x][y]<=Pm[xx][yy]) Union(x,y,xx,yy);
		}
	}
	mxy = min;
}

void Solve()
{
     /*fm[] record that, if one block can be infected, fm[][0] is the min type and f[][1],f[][2] is the computer to union*/
	int i,j,st,tmp;
	st = 0;
	Deal(a[0].x,a[0].y);
	tmp = Find(Coor(a[0].x,a[0].y));
			if (mxy!=32768888 && mxy<fm[tmp][0]) 
			{
				fm[tmp][0] = mxy;
				fm[tmp][1] = minx;
				fm[tmp][2] = miny;
			}
			
	for (i=1; i<lena; i++)
	{
		if (a[i].Level != a[st].Level)
		{
			for (j=st; j<i; j++)
			{
				tmp = Find(Coor(a[j].x,a[j].y));
				if (fm[tmp][0]!=32768888) Union(a[j].x,a[j].y,fm[tmp][1],fm[tmp][2]);
			}
			st = i;
        }
			Deal(a[i].x,a[i].y);
			tmp = Find(Coor(a[i].x,a[i].y));
			if (mxy!=32768888 && mxy<fm[tmp][0])
			{
				fm[tmp][0] = mxy;
				fm[tmp][1] = minx;
				fm[tmp][2] = miny;
			}
	}
	for (j=st; j<i; j++)
	{
		tmp = Find(Coor(a[j].x,a[j].y));
		if (fm[tmp][0]!=32768888) Union(a[j].x,a[j].y,fm[tmp][1],fm[tmp][2]);	
	}
}

void tj()  /*calculate the number of computers infected by each type viru */
{
     int i,j,x;
     for (i=0; i<n; i++)
     {
     for (j=0; j<m; j++)
       Ans_type[Contagious(i,j)]++;       
     }
}


void Out()   /*output the result*/
{
     int q,x,i;
     if (CaseNum>1) printf("\n");
     printf("Scenario #%d\n",CaseNum);
     scanf("%d",&q);
     for (i=0; i<q; i++)
     {
         scanf("%d",&x);
         printf("%d\n",Ans_type[x]);
     }
}

int main()
{
    freopen("pj3.in","r",stdin);
    freopen("pj3.out","w",stdout);
	while (1==1)
	{
        scanf("%d %d",&n,&m);
        if (n==0 && m==0) break;
        CaseNum++;
		Init();
		if (lena>=1)
        {
           Kp(0,lena-1);
		   Solve();
        }
		tj();
		Out();
	}
}
