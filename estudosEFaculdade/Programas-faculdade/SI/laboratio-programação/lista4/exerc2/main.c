//programa que mostra as saidas
#include <stdio.h>
int main(){
    int a =1, b=2, c=3,d=4;
    //a
    printf("a:%d b:%d c:%d\n", a+=b+c, b, c);
    //b
    printf("b:%d c:%d d:%d\n", b *=c= d+2, c);
    //c
    printf("d:%d\n", d %= a + a + a);
    //d
    printf("d:%d c:%d b:%d a:%d\n", d -=c -=b -=a, c, b, a);
    //e
    printf("a:%d b:%d c:%d\n",a += b += c += 7,b, c);
    return 0;
}
 /*
    *saida:
    *letra a
    *a:6 b:2 c:3
    *letra b
    *b:12 c:6 d:0
    *letra c
    *d:4
    *letra d
    *d:4 c:0 b:6 a:6
    *letra e
    *a:19 b:13 c:7
    */