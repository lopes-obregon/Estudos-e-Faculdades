#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415
/*protótipo da função*/
void calculoArea(float raio);
int main()
{
    float raio;
    printf("entre com o raio: ");
    scanf("%f", &raio);
    calculoArea(raio);
    return 0;
}
void calculoArea(float raio){
    float  area =  PI * pow(raio, 2);
    printf("Resultado do raio eh :%f", area);
}
