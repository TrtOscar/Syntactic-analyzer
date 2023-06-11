/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char a[4];
	char b[4];
	char c[4];
	char d[4];
};
void A(node siyuan[], int& sinum, int& j, char ch[], int& i, int& sign);
void E(node siyuan[], int& sinum, int& j, char EE[], char ch[], int& i, int& sign);
void F(node siyuan[], int& sinum, int& j, char FF[], char ch[], int& i, int& sign);
void T(node siyuan[], int& sinum, int& j, char TT[], char ch[], int& i, int& sign);
void V(node siyuan[], int& sinum, int& j, char VV[], char ch[], int& i, int& sign);
void t(node siyuan[], int& sinum, int& j, char FF[], char ch[], int& i, int& sign);
void e(node siyuan[], int& sinum, int& j, char TT[], char ch[], int& i, int& sign);
void newtemp(int& j, char x[])
{
	x[0] = 'T';
	if (j <= 57)
	{
		x[1] = j;
		x[2] = '\0';
	}
	else
	{
		x[1] = 49;
		x[2] = j - 9;
		x[3] = '\0';
	}
	j++;
}
void print(char ch[])
{
	int i;
	i = 0;
	while (1)
	{
		if (ch[i] == '\0')break;
		printf("%c", ch[i]);
		i++;
	}
}
void emit(node siyuan[], int sinum)
{
	int i = 0;
	for (i = 0; i < sinum; i++)
	{
		print(siyuan[i].d);
		printf(":=");
		print(siyuan[i].b);
		if (strcmp(":=", siyuan[i].a) != 0)
		{
			print(siyuan[i].a);
			print(siyuan[i].c);
		}
		printf("     (");
		print(siyuan[i].a);
		printf(",");
		print(siyuan[i].b);
		printf(",");
		print(siyuan[i].c);
		printf(",");
		print(siyuan[i].d);
		printf(")\n");
	}
}
void siyuanshi(node siyuan[], int& sinum, char a[], char b[], char c[], char d[])
{
	strcpy(siyuan[sinum].a, a);
	strcpy(siyuan[sinum].b, b);
	strcpy(siyuan[sinum].c, c);
	strcpy(siyuan[sinum].d, d);
	sinum++;
}
void V(node siyuan[], int& sinum, int& j, char VV[], char ch[], int& i, int& sign)
{
	i++;
	if (ch[i] <= 'z' && ch[i] >= 'a')
	{
		VV[0] = ch[i];
		VV[1] = '\0';
		return;
	}
	else
	{
		sign = 0;
		return;
	}
}
void F(node siyuan[], int& sinum, int& j, char JJ[], char ch[], int& i, int& sign)
{
	i++;
	if (ch[i] == '(')
	{
		char EE[4];
		E(siyuan, sinum, j, EE, ch, i, sign);
		if (sign == 0)return;
		i++;
		if (ch[i] == ')')
		{
			strcpy(JJ, EE);
			return;
		}
		else { sign = 0; return; }
	}
	else
	{
		char VV[4];
		i--;
		V(siyuan, sinum, j, VV, ch, i, sign);
		if (sign == 0)return;
		strcpy(JJ, VV);
	}
}
void t(node siyuan[], int& sinum, int& j, char FF[], char ch[], int& i, int& sign)
{
	char a[4];
	i++;
	if (ch[i] == '*' || ch[i] == '/')
	{
		a[0] = ch[i];
		a[1] = '\0';
		char FF1[4];

		F(siyuan, sinum, j, FF1, ch, i, sign);
		if (sign == 0)return;
		char FFNEW[4];
		newtemp(j, FFNEW);
		siyuanshi(siyuan, sinum, a, FF, FF1, FFNEW);
		t(siyuan, sinum, j, FFNEW, ch, i, sign);
		if (sign == 0)return;
		strcpy(FF, FFNEW);
	}
	else i--;
}
void T(node siyuan[], int& sinum, int& j, char TT[], char ch[], int& i, int& sign)
{
	char FF[4], tt[4];
	F(siyuan, sinum, j, FF, ch, i, sign);
	if (sign == 0)return;
	strcpy(TT, FF);
	t(siyuan, sinum, j, FF, ch, i, sign);
	if (sign == 0)return;
	strcpy(TT, FF);
}
void e(node siyuan[], int& sinum, int& j, char TT[], char ch[], int& i, int& sign)
{
	int z;
	char a[4];
	i++;
	if (ch[i] == '+' || ch[i] == '-')
	{
		a[0] = ch[i];
		a[1] = '\0';
		char TT1[4];

		T(siyuan, sinum, j, TT1, ch, i, sign);
		if (sign == 0)return;
		char TTNEW[4];
		newtemp(j, TTNEW);
		siyuanshi(siyuan, sinum, a, TT, TT1, TTNEW);
		e(siyuan, sinum, j, TTNEW, ch, i, sign);
		if (sign == 0)return;
		strcpy(TT, TTNEW);
	}
	else i--;
	return;
}
void E(node siyuan[], int& sinum, int& j, char EE[], char ch[], int& i, int& sign)
{
	char TT[4];
	T(siyuan, sinum, j, TT, ch, i, sign);
	if (sign == 0)return;
	strcpy(EE, TT);
	e(siyuan, sinum, j, TT, ch, i, sign);
	strcpy(EE, TT);
	if (sign == 0)return;
}
void A(node siyuan[], int& sinum, int& j, char ch[], int& i, int& sign)
{
	char VV[4], EE[4], a[4], b[4];
	V(siyuan, sinum, j, VV, ch, i, sign);
	if (sign == 0)return;
	i++;
	if (ch[i] != ':') { sign = 0; return; }
	else
	{
		i++;
		if (ch[i] != '=') { sign = 0; return; }
	}
	E(siyuan, sinum, j, EE, ch, i, sign);
	a[0] = ':'; a[1] = '='; a[2] = '\0'; b[0] = '-'; b[1] = '\0';
	siyuanshi(siyuan, sinum, a, EE, b, VV);
}
int main()
{
	node siyuan[100];
	int sinum = 0;
	int l;
	int j = 49;
	int sign = 1;
	char ch[100];
	int i = -1;
	scanf("%s", ch);
	l = strlen(ch);
	A(siyuan, sinum, j, ch, i, sign);
	if (sign == 0 || i < l - 1)
		printf("error");
	else
		emit(siyuan, sinum);
	return 0;
}
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <ctype.h> // islower函数的头文件
using namespace std;

//A -> V := E
//E -> E + T | E - T | T
//T -> T * F | T / F | F
//F -> V | ( E )
//V -> a | b | c | d | e .... | z

void AllLine(); // A -> V := E
void Expression(); // E -> TE'（E和E1、T和T1消除了左递归）
void Expression1(); // E' -> + TE'| - TE'| null
void Term(); // T -> FT'
void Term1(); // T' -> * FT'| / FT' | null
void Factor(); // F -> V | ( E )
void Verbal(); // V -> a | b | c | d | e .... | z

char str[50], n = '1'; // str[50]用于存放输入的赋值表达式
char Table[50][3]; // 产生中间代码所需的符号表
int FLAG, i; // i为是str[50]中当前读入符号的下标，FLAG用于判断当前的表达式是否有错
int listorder = 0; // 符号表的下标

void AllLine()//A->V:=E
{
	Verbal();
	if (str[i] == ':' && str[i + 1] == '=') // 判断赋值号是否拼写错误
	{
		i += 2; // 赋值号正确，则从表达式开始解析
		Expression();
		printf("%s:=%s", Table[listorder - 2], Table[listorder - 1]); // 处理最后一个字符，即表达式赋值符号前面那个字母
		printf("     (:=,%s,-,%s)\n", Table[listorder - 1], Table[listorder - 2]);
	}
	else
	{
		printf("Error! Incorrect Operator!\n"); // 赋值号拼写错误
		FLAG = 1;
		system("pause");
		exit(0);
	}
}
void Verbal() // V -> a | b | c | d | e .... | z
{
	if (islower(str[i])) // 判断字母str[i]是不是小写字母
	{
		Table[listorder][0] = str[i]; // 把读取的小写字母存入符号表
		Table[listorder][1] = '\0';
		listorder++;
		i++;
	}
	else
	{
		printf("Operation Error!\n"); // 运算对象错误
		FLAG = 1;
		system("pause");
		exit(0);
	}
}
void Expression() // E -> TE'
{
	if (FLAG == 0)
	{
		Term(); // 项， T -> FT'
		Expression1(); // 表达式：E' -> + TE'| - TE'| null    ！
	}
}
void Term() // T -> FT'
{
	if (FLAG == 0)
	{
		Factor(); // 因子，F -> V | ( E )
		Term1(); // T' -> * FT'| / FT' | null
	}
}
void Expression1() // E' -> + TE' | - TE' | null
{
	int p;
	if (FLAG == 0)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			p = i; // p记录+-时i的值
			i++;
			Term();
			char ch[3];
			ch[0] = 'T';
			ch[1] = n;
			ch[2] = '\0';
			if (str[p] == '+')
			{
				printf("%s:=%s+%s", ch, Table[listorder - 2], Table[listorder - 1]); // 输出三地址代码
				printf("     (+,%s,%s,%s)\n", Table[listorder - 2], Table[listorder - 1], ch); // 输出四元式
			}
			else
			{
				printf("%s:=%s-%s", ch, Table[listorder - 2], Table[listorder - 1]);
				printf("     (-,%s,%s,%s)\n", Table[listorder - 2], Table[listorder - 1], ch);
			}
			strcpy(Table[listorder - 2], ch); // 将当前结果归结式放在字符表中
			listorder--;
			n++;
			Expression1();
		}
	}
}
void Term1() // T' -> * FT' | / FT' | null
{
	int p;
	if (FLAG == 0)
	{
		if (str[i] == '*' || str[i] == '/')
		{
			p = i;
			i++;
			Factor();
			char ch[3];
			ch[0] = 'T';
			ch[1] = n;
			ch[2] = '\0';
			if (str[p] == '*')
			{
				printf("%s:=%s*%s", ch, Table[listorder - 2], Table[listorder - 1]);
				printf("     (*,%s,%s,%s)\n", Table[listorder - 2], Table[listorder - 1], ch);
			}
			else
			{
				printf("%s:=%s/%s", ch, Table[listorder - 2], Table[listorder - 1]);
				printf("     (/,%s,%s,%s)\n", Table[listorder - 2], Table[listorder - 1], ch);
			}
			strcpy(Table[listorder - 2], ch);
			listorder--;
			n++;
			Term1();
		}
	}
}
void Factor() // F -> V | ( E )
{
	if (FLAG == 0)
	{
		if (str[i] == '(')
		{
			i++;
			Expression();
			if (str[i] == ')')
				i++;
			else
			{
				printf("Error! Incorrect Expression!\n"); // Error! Lack of ')'?
				FLAG = 1;
				system("pause");
				exit(0);
			}
		}
		else if (islower(str[i])) // 判断str[i]是否是小写字母
			Verbal();
		else
		{
			printf("Error! Incorrect Expression! \n");
			FLAG = 1;
			system("pause");
			exit(0);
		}
	}
}
int main()
{
	FLAG = 0; // FLAG用于指示赋值表达式是否出错
	i = 0;
	scanf("%s", str);
	if (str[0] == '\0') // 没有输入时直接退出
	{
		return 0;
	}
	AllLine();
	if (str[i] != '\0' && FLAG == 0)
	{
		printf("Error! Incorrect Expression! \n"); // Error! Lack of '('?
		system("pause");
		exit(0);
	}
	system("pause");
	return 0;
}