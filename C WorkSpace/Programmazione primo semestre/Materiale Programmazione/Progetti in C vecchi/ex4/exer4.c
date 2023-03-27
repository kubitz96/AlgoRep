#include <stdio.h>

int main(void)
{
float x,y,z;

printf("Inserire le misure dei 3 lati di un triangolo\n");
scanf("%f %f %f",&x,&y,&z);

if(x==y && y==z){
printf("il triangolo e' equilatero\n");}
else if(x==y || x==z || y==z ){
printf("il triangolo e' isoscele\n");}
else{
printf("il triangolo e' scaleno\n");}

return 0;
}
