#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct Point
{
    int x, y;
};
Point p0;

int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   int o = orientation(p0, *p1, *p2);
   if (o == 0)
    {
        return (distSq(p0, *p2) > distSq(p0, *p1))? -1 : 1;
   }

   return (o == 1)? -1: 1;
}
float find_area(int n,int fig[5][5])
{
   int r,c,i,j,a[n][n];
    float area=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=fig[i][j];
        }

    }
    int row;

    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            if(a[r][c]==1)
            {
                row=r+1;
              while(a[row][c]!=1)
              {
                  if(row<n)
                  {
                      row++;
                      }
                  else if(row>=n)
                  {   row=r+1;
                      break;
                  }

              }

              area=(area+row-r);
            }

        }


    }
    return area;
}
void bresenhems(int x1,int y1,int x2,int y2,int hull[5][5])
{
    float m=(float)(y2-y1)/(x2-x1);
    if(m<0)
    {
        if((x1<x2 && m>=-1)||(m<-1&&x1>x2))
            {
                int temp;
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y2;
        y2=y1;
        y1=temp;
            }
            if(m<-1)
            {
                int temp;
                temp=x1;
                x1=y1;
                y1=temp;
                temp=x2;
                x2=y2;
                y2=temp;
            }
        int dx=x2-x1,dy=y2-y1,dt=(2*(dy+dx)),ds=(2*dy),d=-((2*dy)+dx);
        while(x1>=x2)
        {cout<<"--"<<x1<<y1<<"--\n";
            if(m<=0&&m>=-1)
            hull[x1][y1]=1;
            else
                hull[y1][x1]=1;
            x1--;
            if(d<0)
            {
                y1++;
                d=d-dt;
            }
            else
                d=d-ds;
        }
    }
    else{
            if(x1>x2)
            {
                int temp;
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y2;
        y2=y1;
        y1=temp;
            }
    if(m>1)
    {
        int temp;
        temp=x1;
        x1=y1;
        y1=temp;
        temp=x2;
        x2=y2;
        y2=temp;
    }
    int dx=x2-x1,dy=y2-y1,dt=(2*(dy-dx)),ds=(2*dy);
    int d=((2*dy)-dx);
    while(x1<=x2)
        {cout<<"--"<<x1<<y1<<"--\n";
    if(m<=1&&m>=0)
        hull[x1][y1]=1;
    else if(m>=1)
        hull[y1][x1]=1;
            x1++;
            if(d<0)
                d=d+ds;
            else
            {
                y1++;
                d=d+dt;
            }
}
    }
}

int arrea(Point A,Point B,Point C)
{
    int hull[5][5];   //size?
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            hull[i][j]=0;
    }
    float area;
    hull[A.x][A.y]=1;
    hull[B.x][B.y]=1;
    hull[C.x][C.y]=1;
    cout<<A.x<<"\t"<<A.y<<endl;
    cout<<B.x<<"\t"<<B.y<<endl;
    cout<<C.x<<"\t"<<C.y<<endl;
    bresenhems(A.x,A.y,B.x,B.y,hull);cout<<"\nneext\n";
    bresenhems(B.x,B.y,C.x,C.y,hull);cout<<"\nneext\n";
    bresenhems(A.x,A.y,C.x,C.y,hull);cout<<"\nneext\n";
    area=find_area(5,hull); //n?
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout<<hull[i][j]<<"  ";
        cout<<endl;
    }
    cout<<area<<endl;
    cout<<endl<<endl;
    return area;

}

int maxtriangle()
{
    int hull[5][5]={0,0,0,0,1,
                    0,0,0,1,1,
                    0,0,1,0,1,
                    0,0,0,1,1,
                    0,0,0,0,1};
    int k=0;
    Point p[8];  //generalization required here
    int c=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++){
            if(hull[i][j]==1)
            {
                p[k].x=i;
                p[k].y=j;
                k++;
            }
        }
    }

   int n = sizeof(p)/sizeof(p[0]);
   int ymin = p[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = p[i].y;

     if ((y < ymin) || (ymin == y &&
         p[i].x < p[min].x))
        ymin = p[i].y, min = i;
   }

   swap(p[0], p[min]);

   p0 = p[0];

   qsort(&p[1], n-1, sizeof(Point), compare);
   for(int i=0;i<n;i++)
    cout<<endl<<p[i].x<<p[i].y<<endl;
    Point A,B,C;
    int f=0,g=f+1,h=g+1;
    A=p[f],B=p[g],C=p[h];
    Point bA=A,bB=B,bC=C;
    while(true)
    {
        while(true)
        {
            while(arrea(A,B,C)<=arrea(A,B,p[h+1]))
            {
                if(h<n)
                    C=p[++h];
                else
                    break;
            }
            cout<<"2**************"<<endl;
            if(arrea(A,B,C)<=arrea(A,p[g+1],C))
            {
                if(g<n){
                B=p[++g];
                continue;
                }
                else
                    break;
            }
            else
                break;
            cout<<"3***********************"<<endl;

        }
        if(arrea(A,B,C)>arrea(bA,bB,bC))
            bA=A,bB=B,bC=C;
        if(f<n)
        A=p[++f];
        else
            break;
        if(A.x==B.x && A.y==B.y){
                if(g<n)
            B=p[++g];
            else
                break;
            }
        if(B.x==C.x && B.y==C.y){
                if(h<n)
            C=p[++h];
            else
                break;}
    }
    int a=arrea(bA,bB,bC);
    cout<<endl<<"AREA:"<<a<<"***************"<<endl;
    return a;
}
int main()
{
    maxtriangle();
}
