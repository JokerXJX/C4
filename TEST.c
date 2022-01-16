#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	char cstring[100] = { 0 };
//	int iword = 1;
//	int index = 0;
//	char blank;
//	gets(cstring);
//	if (cstring[0] == '\0')
//		printf("No char\n");
//	else if (cstring[0] == ' ')
//		printf("First is blank\n");
//	else
//	{
//		for (index = 0; cstring[index] != '\0'; index++)
//		{
//			blank = cstring[index];
//			if (blank == ' ')
//			{
//				iword++;
//			}
//		}
//	}
//	printf("%d\n", iword);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 1;
//	int j = 1;
//	float a[100] = { 0 };
//	float b[100] = { 0 };
//	int sum = 0;
//	printf("\nEnter the number of players:\n");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		printf("now player %d\n", i);
//		scanf("please input score:\n");
//		for (; j < 5 * n + 1; j++)
//		{
//			scanf("%f", &a[j]);
//			sum += a[j];
//			if (j % 5 == 0)
//				break;
//		}
//		b[i] = sum;
//		sum = 0;
//		j++;
//	}
//	j = 1;
//	printf("player     jA    jB    jC    jD    jE     total\n");
//	for (i = 1; i <= n; i++)
//	{
//		printf("player %d", i);
//		for (; j < 5 * n + 1; j++)
//		{
//			printf("%6.1f", a[j]);
//			if (j % 5 == 0)
//			{
//				break;
//			}
//		}
//		printf("%8.1f\n", b[i]);
//		j++;
//	}
//	return 0;
//}

//int main()
//{
//	int x = 16;
//	int n = 0;
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		printf("%d", x - 6);
//		break;
//	case 2:
//		printf("%d", x - 4);
//		break;
//	case 3:
//		printf("%d", x - 2);
//		break;
//	case 4:
//		printf("%d", x );
//		break;
//	case 5:
//		printf("%d", x + 2);
//		break;
//	default:
//		printf("ÊäÈë´íÎó\n");
//		break;
//	}
//	return 0;
//}


int gys(int x, int y)
{
	return y ? gys(y, x % y) : x;
}

int gbs(int x, int y)
{
	return x / gys(x, y) * y;
}

void yuefen(int fz, int fm)
{
	int s = gys(fz, fm);
	fz /= s;
	fm /= s;
	printf("the result is %d%d\n", fz, fm);
}

void add(int a, int b, int c, int d)
{
	int u1, u2, v = gbs(b, d), fz1, fm1;
	u1 = v / b * a;
	u2 = v / d * c;
	fz1 = u1 + u2;
	fm1 = v;
	yuefen(fz1, fm1);
}

void sub(int a, int b, int c, int d)
{
	int u1, u2, v = gbs(b, d), fz1, fm1;
	u1 = v / b * a;
	u2 = v / d * c;
	fz1 = u1 - u2;
	fm1 = v;
	yuefen(fz1, fm1);
}

void mul(int a, int b, int c, int d)
{
	int u1, u2;
	u1 = a * c;
	u2 = b * d;
	yuefen(u1, u2);
}

void div(int a, int b, int c, int d)
{
	int u1, u2;
	u1 = a * d;
	u2 = b * c;
	yuefen(u1, u2);
}
int main()
{
	char op;
	int a, b, c, d;
	scanf("%d,%d,%c,%d,%d", &a, &b, &op, &c, &d);
	switch (op)
	{
	case '+':add(a, b, c, d); break;
	case '-':sub(a, b, c, d); break;
	case '*':mul(a, b, c, d); break;
	case '/':div(a, b, c, d); break;
	}
	return 0;
}