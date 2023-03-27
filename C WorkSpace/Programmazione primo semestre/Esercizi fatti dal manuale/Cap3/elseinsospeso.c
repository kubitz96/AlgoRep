#include<stdio.h>

int main()
{
    int x, y;
    x = 5;
    y = 8;               //7d
                                        //@@@@@    caso a
                                        //$$$$$
                                        //&&&&& senza parentesi (se non ci sono il secondo if viene
                                        // visto come interno)
if ( y == 8 )       //{b c  d                   
if ( x == 5 )
puts( "@@@@@" );    //}b c  d
else                //{b c
puts( "#####" );
puts( "$$$$$" );       //c}
puts( "&&&&&" );    //b} c

return 0;
}