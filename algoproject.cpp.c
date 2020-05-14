#include<stdio.h>
float find_pch(int n,int hull[n][n])
{
    int r,c,r0=0,c0=0,i,j,a[n][n];
    float pch=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=hull[i][j];
        }

    }
    int flag=0;

    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            if(hull[r][c]==1)
            {
                flag=1;
               break;
            }
        }
        if(flag==1)
            {
               break;
            }
    }
    r0=r;
    c0=c;

    while(1)
    {

                if(a[r0-1][c0]==1)
                    {pch=pch+1;
                    r0=r0-1;
                    a[r0][c0]=2;}
                else if(a[r0-1][c0+1]==1)
                    {pch=pch+1.414;
                    r0=r0-1;
                    c0=c0+1;
                    a[r0][c0]=2;}
                else if(a[r0][c0+1]==1)
                    {pch=pch+1;
                    c0=c0+1;
                    a[r0][c0]=2;}
                else if(a[r0+1][c0+1]==1)
                    {pch=pch+1.414;
                    r0=r0+1;
                    c0=c0+1;
                    a[r0][c0]=2;}
                else if(a[r0+1][c0]==1)
                    {pch=pch+1;
                    r0=r0+1;
                    a[r0][c0]=2;}
                else if(a[r0+1][c0-1]==1)
                    {pch=pch+1.414;
                    r0=r0+1;
                    c0=c0-1;
                    a[r0][c0]=2;}
                else if(a[r0][c0-1]==1)
                    {pch=pch+1;
                    c0=c0-1;
                    a[r0][c0]=2;}
                else if(a[r0-1][c0-1]==1)
                    {pch=pch+1.414;
                    c0=c0-1;
                    r0=r0-1;
                    a[r0][c0]=2;}
                else
                    break;
    }
    return pch;
}
float find_len(int n,int fig[n][n])
{
int r,c,r0=0,c0=0,i,j,a[n][n],len01;
    float len,pch1=0,pch2=0;
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
        {a[i][j]=fig[i][j];
        }

    }
    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            if(fig[r][c]==1)
            {
               break;
            }
        }
        if(fig[r][c]==1)
            {
               break;
            }
    }
    r0=r;
    c0=c;
    int r1,c1;
                if(a[r0-1][c0]==1)
                    {len01=1;
                    r1=r0-1;
                    c1=c0;}
                else if(a[r0-1][c0+1]==1)
                    {len01=1;
                    r1=r0-1;
                    c1=c0+1;}
                else if(a[r0][c0+1]==1)
                    {len01=1;
                    r1=r0;
                    c1=c0+1;}
                else if(a[r0+1][c0+1]==1)
                    {len01=1;
                    r1=r0+1;
                    c1=c0+1;}
                else if(a[r0+1][c0]==1)
                    {len01=1;
                    r1=r0+1;
                    c1=c0+1;}
               else if(a[r0+1][c0-1]==1)
                    {len01=1;
                    r1=r0+1;
                    c1=c0-1;}
                else if(a[r0][c0-1]==1)
                    {len01=1;
                    c1=c0-1;
                    r1=r0;}
                else if(a[r0-1][c0-1]==1)
                    {len01=1;
                    c1=c0-1;
                    r1=r0-1;}
    a[r0][c0]=2;
    a[r1][c1]=2;

    while(1)
    {

                if(a[r0-1][c0]==1)
                    {pch1=pch1+1;

                    r0=r0-1;
                    a[r0][c0]=2;}
                else if(a[r0-1][c0+1]==1)
                    {pch1=pch1+1.414;

                    r0=r0-1;
                    c0=c0+1;
                    a[r0][c0]=2;}
                else if(a[r0][c0+1]==1)
                    {pch1=pch1+1;

                    c0=c0+1;
                    a[r0][c0]=2;}
                else if(a[r0+1][c0+1]==1)
                    {pch1=pch1+1.414;

                    r0=r0+1;
                    c0=c0+1;
                    a[r0][c0]=2;}
                else if(a[r0+1][c0]==1)
                    {pch1=pch1+1;

                    r0=r0+1;
                    a[r0][c0]=2;}
                else if(a[r0+1][c0-1]==1)
                    {pch1=pch1+1.414;

                    r0=r0+1;
                    c0=c0-1;
                    a[r0][c0]=2;}
                else if(a[r0][c0-1]==1)
                    {pch1=pch1+1;

                    c0=c0-1;
                    a[r0][c0]=2;}
                else if(a[r0-1][c0-1]==1)
                    {pch1=pch1+1.414;

                    c0=c0-1;
                    r0=r0-1;
                    a[r0][c0]=2;}
                else
                    break;
    }
    while(1)
    {

                if(a[r1-1][c1]==1)
                    {pch2=pch2+1;

                    r1=r1-1;
                    a[r1][c1]=2;}
                else if(a[r1-1][c1+1]==1)
                    {pch2=pch2+1.414;

                    r1=r1-1;
                    c1=c1+1;
                    a[r1][c1]=2;}
                else if(a[r1][c1+1]==1)
                    {pch2=pch2+1;

                    c1=c1+1;
                    a[r1][c1]=2;}
                else if(a[r1+1][c1+1]==1)
                    {pch2=pch2+1.414;

                    r1=r1+1;
                    c1=c1+1;
                    a[r1][c1]=2;}
                else if(a[r1+1][c1]==1)
                    {pch2=pch2+1;

                    r1=r1+1;
                    a[r1][c1]=2;}
                else if(a[r1+1][c1-1]==1)
                    {pch2=pch2+1.414;

                    r1=r1+1;
                    c1=c1-1;
                    a[r1][c1]=2;}
                else if(a[r1][c1-1]==1)
                    {pch2=pch2+1;

                    c1=c1-1;
                    a[r1][c1]=2;}
                else if(a[r1-1][c1-1]==1)
                    {pch2=pch2+1.414;

                    c1=c1-1;
                    r1=r1-1;
                    a[r1][c1]=2;}
                else
                    break;
    }
len=pch1+pch2+len01;
return len;

}
float find_area(int n,int fig[n][n])
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

int maxtriangle()
{



}
int main()
{
    int n,i,j;
    //scanf("%d",&n);
    int hull[5][5]={1,1,1,1,1,
                    1,0,0,1,0,
                    1,0,1,0,0,
                    1,1,0,0,0,
                    1,0,0,0,0};
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&hull[i][j]);
        }


    }*/

    float x=find_pch(5,hull);
    float y=find_len(5,hull);
    float z=find_area(5,hull);
    printf("%f\n%f\n%f",x,y,z);
    return 0;
}





