#include <stdio.h>
#include <stdint.h>
#define S "\x1b[34m"
#define Z "\x1b[32m"
#define G "\x1b[33m"
#define SR "\x1b[90m"
#define RD "\x1b[31m"
#define RS "\x1b[0m"
#define RAZR 31
int main ()
{
uint32_t a, b, res;
char op;
while (1)
{
if (scanf(" %i %c %i", &a, &op, &b ) != 3) return 1;
printf("\n");
printf(SR"%4s %8s %3s %7s %3s %7s %2s %8s\n"RS,"31","18","17","16","15","8","7","0");                                                                     
printf(SR"%4s %8s %2s %8s %2s %8s %2s %8s"RS,"|","|","|","|","|","|","|","|"); 
printf("\n");
// первая переменная разлаживаем на биты
printf("   ");
for(int i = RAZR; i >=0; i --)
{
        if ((a >> i) & 1){printf(Z"1"RS );}
        else {printf("0" );}
        if ((i % 4) == 0)
        {
                printf("  " );
        }
}
printf(Z">%d\n"RS, a );
printf(RD"%53c\n"RS, op );
//вторая переменная разлаживаем на биты
printf("   ");
for(int i = RAZR; i >=0; i --)
{
        if ((b >> i) & 1){printf(S"1"RS );}                                                 else {printf("0" );}
        if ((i % 4) == 0)
        {
                printf("  " );
        }                                                                            }
printf(S">%d\n"RS, b);
printf("\n" );
// выбор оператора
switch (op)
{
        case '&': res = a & b; break;
        case '|': res = a | b; break;
        case '^': res = a ^ b; break;
        case '<': res = a << b; break;
	case '>': res = a >> b; break;               
	case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '/': res = a / b; break;
        case '*': res = a * b; break;
        case '~': res = ~ a; break;

}
// результат разлаживаем на биты
printf("   ");
for(int i = RAZR; i >=0; i --)/
{
        if ((res >> i) & 1){printf(G"1"RS );}
        else { printf("0" );}
        if ((i % 4) == 0)
        {
                printf("  " );
        }

}
printf(G">%d\n"RS, res );
printf("\n" );
}
return 0 ;
}

