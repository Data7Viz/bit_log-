#include <stdio.h>
#include <stdint.h>
#define S "\x1b[34m"
#define Z "\x1b[32m"
#define G "\x1b[33m"
#define SR "\x1b[90m"
#define RD "\x1b[31m"
#define RS "\x1b[0m"
#define RAZR 15
int main ()
{
uint16_t a, b, res;
char op;
while (1)
{
if (scanf(" %hi %c %hi", &a, &op, &b ) != 3) return 1;
printf("\n");
printf(SR"%2s %13s %3s %13s\n"RS, "15", "8", "7", "0");
printf(SR"%2s %13s %3s %13s\n"RS, "|", "|", "|", "|");
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
printf(Z" >%d\n"RS, a );
printf(RD"%37c\n"RS, op );
//вторая переменная разлаживаем на биты
for(int i = RAZR; i >=0; i --)
{
        if ((b >> i) & 1){printf(S" 1"RS );}                                                 else {printf(" 0" );}
        if (i == 8)
        {
                printf("  " );
        }                                                                            }
printf(S" >%d\n"RS, b);
printf("\n" );
// выбор оператора
switch (op)
{
        case '&': res = a & b; break;
        case '|': res = a | b; break;
        case '^': res = a ^ b; break;
	case '<': res = a << b; break;                                            case '>': res = a >> b; break;                                            case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '/': res = a / b; break;
        case '*': res = a * b; break;
        case '~': res = ~ a; break;

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
printf(G" >%d\n"RS, res );
printf("\n" );
}
return 0 ;
}

