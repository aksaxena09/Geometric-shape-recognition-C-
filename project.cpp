#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<stack>
#include<math.h>
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{
    int hull[][]=convexHull();
    float len=find_len(n,img);  //n is size of square matrix. correct it here
    float pch=find_pch(n,hull);     //n size of convex hull
    float area=find_area(n,hull);
    float frac=len/pch;
    float frac1=frac-0.5,frac2=frac-1;
    float value;
    if(frac1>frac2)
        value=frac2;
    else
        value=frac1;
    if(value==frac1)
        cout<<"open shape typically straight lines";
    else if(value==frac2)
    {
        cout<<"likely to be a closed shape. Have patience now it will take time to determine which closed shape coz its artificial intelligence bro";
        float thinness=((pch*pch)/area);
        if(thinness==12.5663706)
            cout<<"circle most probably";
        int tri_area=maxtriangle(); //bhejo isme jo bhejna hai ullu.
        float tri=(area/tri_area);
        if(tri==1)
            cout<<"it's a triangle baby";
        int per=min_rect(); //bhejo parameters nd it must return perimeter of enclosing rectangle.
        float rat=(pch/per);
        if(rat==1)
            cout<<"congrats you have reached the final stage. it's a rectangle, chalo nikalo ab.bye-bye tata see you next janam";
    }

}
