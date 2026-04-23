#include <stdio.h>
#include <stdint.h>
#define S "\x1b[34m"
#define Z "\x1b[32m"
#define G "\x1b[33m"
#define SR "\x1b[90m"
#define RD "\x1b[31m"
#define BR "\x1b[36m"
#define RS "\x1b[0m"

int main ()
{
uint64_t a, b, res, dec = 1;
int raz;
char op;

//выбираем колличество разрядов
printf("Введите колличество разрядов : ");
if (scanf(" %d", &raz) != 1) return 1;

//вводим число оператор число
if (scanf(" %li %c %li", &a, &op, &b ) != 3) return 1;
printf("\n");

//значение переменных выбранный оператор 
printf(Z"%8ld"RS, a);
printf(RD"%3c"RS, op);
printf(S"%3ld"RS, b);

//блок определения оператора 
switch (op)
{       case '&': res = a & b; break;
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
printf(G" = %2ld\n\n"RS, res);
for(int i = 0; i <= raz; i ++)
{
	//номер разряда
	printf(SR"raz %2d"RS, i);
	
	//переменная a разлаживаем на биты 1 зелёные 0 белые
	if (((a >> i) & 1) == 1) { printf(Z"%6s"RS, "  1"); } 
	else { printf ("%6s", "  0"); } 
	
	//переменна b разлаживаем на биты 1 синие 0 белые 
	if (((b >> i) & 1) == 1) { printf(S"%6s"RS, "  1"); }
        else { printf ("%6s", "  0"); }
        
	//переменная res разлаживаем на биты 1 жёлтые 0 белые
	if (((res >> i) & 1) == 1) { printf(G"%6s"RS, "  1"); }  
	else { printf ("%6s", "  0"); }
	
	//вывод DEC HEX 
	printf(BR"        %-10lu"RS, dec << i);
	printf(SR"          %-10lx"RS, dec << i);

	printf("\n");
	
}

return 0;
} 

        
