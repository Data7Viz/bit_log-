#include <stdio.h>
int main ()
{
	int var1, var2, res;
	char op;
	scanf("%d %c %d", &var1, &op, &var2);

	// первая переменная разлаживаем на биты
	for (int i = 7; i >= 0; i --) 
	{ 
		printf(" %d", (var1 >> i) & 1); 
	}
	printf("\n\n");

	// вторая переменная разлаживаем на биты
	for (int i = 7; i >= 0; i --)
        {
                printf(" %d", (var2 >> i) & 1);
        }
        printf("\n\n");

	// результат разлаживаем на биты 
	for (int i = 7; i >= 0; i --)
	{
		if (op == '&')
		{
			printf(" %d", ((var1 & var2) >> i) & 1);
		}
		else if (op == '|')                                                                   {                                                                                             printf(" %d", ((var1 | var2) >> i) & 1);                                      }
		else if (op == '^')                                                                   {                                                                                             printf(" %d", ((var1 ^ var2) >> i) & 1);                                      }
	}
	printf ("\n\n");
} 
