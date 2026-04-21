#include <stdio.h>
#define S "\x1b[34m"
#define Z "\x1b[32m"
#define G "\x1b[33m"
#define RS "\x1b[0m"

#define RAZR 15 //разрядность
int main ()
{
int a, b, res;
char op;
scanf(" %i %c %i", &a, &op, &b );
printf("\n\n");
// первая переменная разлаживаем на биты
for(int i = RAZR; i >=0; i --)
{
	if ((a >> i) & 1){printf(Z" 1"RS );}
	else {printf(" 0" );} 
        if (i == 8)
        {
                printf("  " );
        }
}
printf("\n\n" );
//вторая переменная разлаживаем на биты 
for(int i = RAZR; i >=0; i --)
{
	if ((b >> i) & 1){printf(S" 1"RS );} 
        else {printf(" 0" );}
        if (i == 8)
        {
                printf("  " );
        }
}
printf("\n\n" );
// выбор оператора 
switch (op)
{
	case '&': res = a & b; break;
	case '|': res = a | b; break;
	case '^': res = a ^ b; break;
        case '<': res = a << b; break;
	case '>': res = a >> b; break;
	
}
// результат разлаживаем на биты 
for(int i = RAZR; i >=0; i --)
{
	if ((res >> i) & 1){printf(G" 1"RS );}
        else { printf(" 0" );}
        if (i == 8)
        {
                printf("  " );
        }

}
printf("\n\n" );
return 0 ;
}
	
		  
 
