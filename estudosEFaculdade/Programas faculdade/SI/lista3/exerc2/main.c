#include <stdio.h>

int main(){
    int x= 0; 
    int y = 0;
    int i = 0;
    int  j = 0;
    int a = 0;
    int b = 0; 
    int c = 0;
    //a
    x = (2+1)*6;
    //b
    y = (5 + 1)/2*3;
    //c
    i = j = (2 +3)/4;
   //d
    a = 3+2*(b=7/2);
    //e
    c = 5 + 10%4/2;
    printf("a=%d b=%d c=%d x=%d y=%d i=%d j=%d \n",a, b, c, x, y, i, j);
    return 0;
}

//resultado
//a=9 b=3 c=6 x=18 y=9 i=1 j=1