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
#include <ctype.h> // islower������ͷ�ļ�
using namespace std;

//A -> V := E
//E -> E + T | E - T | T
//T -> T * F | T / F | F
//F -> V | ( E )
//V -> a | b | c | d | e .... | z

void AllLine(); // A -> V := E
void Expression(); // E -> TE'��E��E1��T��T1��������ݹ飩
void Expression1(); // E' -> + TE'| - TE'| null
void Term(); // T -> FT'
void Term1(); // T' -> * FT'| / FT' | null
void Factor(); // F -> V | ( E )
void Verbal(); // V -> a | b | c | d | e .... | z

char str[50], n = '1'; // str[50]���ڴ������ĸ�ֵ���ʽ
char Table[50][3]; // �����м��������ķ��ű�
int FLAG, i; // iΪ��str[50]�е�ǰ������ŵ��±꣬FLAG�����жϵ�ǰ�ı��ʽ�Ƿ��д�
int listorder = 0; // ���ű���±�

void AllLine()//A->V:=E
{
	Verbal();
	if (str[i] == ':' && str[i + 1] == '=') // �жϸ�ֵ���Ƿ�ƴд����
	{
		i += 2; // ��ֵ����ȷ����ӱ��ʽ��ʼ����
		Expression();
		printf("%s:=%s", Table[listorder - 2], Table[listorder - 1]); // �������һ���ַ��������ʽ��ֵ����ǰ���Ǹ���ĸ
		printf("     (:=,%s,-,%s)\n", Table[listorder - 1], Table[listorder - 2]);
	}
	else
	{
		printf("Error! Incorrect Operator!\n"); // ��ֵ��ƴд����
		FLAG = 1;
		system("pause");
		exit(0);
	}
}
void Verbal() // V -> a | b | c | d | e .... | z
{
	if (islower(str[i])) // �ж���ĸstr[i]�ǲ���Сд��ĸ
	{
		Table[listorder][0] = str[i]; // �Ѷ�ȡ��Сд��ĸ������ű�
		Table[listorder][1] = '\0';
		listorder++;
		i++;
	}
	else
	{
		printf("Operation Error!\n"); // ����������
		FLAG = 1;
		system("pause");
		exit(0);
	}
}
void Expression() // E -> TE'
{
	if (FLAG == 0)
	{
		Term(); // � T -> FT'
		Expression1(); // ���ʽ��E' -> + TE'| - TE'| null    ��
	}
}
void Term() // T -> FT'
{
	if (FLAG == 0)
	{
		Factor(); // ���ӣ�F -> V | ( E )
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
			p = i; // p��¼+-ʱi��ֵ
			i++;
			Term();
			char ch[3];
			ch[0] = 'T';
			ch[1] = n;
			ch[2] = '\0';
			if (str[p] == '+')
			{
				printf("%s:=%s+%s", ch, Table[listorder - 2], Table[listorder - 1]); // �������ַ����
				printf("     (+,%s,%s,%s)\n", Table[listorder - 2], Table[listorder - 1], ch); // �����Ԫʽ
			}
			else
			{
				printf("%s:=%s-%s", ch, Table[listorder - 2], Table[listorder - 1]);
				printf("     (-,%s,%s,%s)\n", Table[listorder - 2], Table[listorder - 1], ch);
			}
			strcpy(Table[listorder - 2], ch); // ����ǰ������ʽ�����ַ�����
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
		else if (islower(str[i])) // �ж�str[i]�Ƿ���Сд��ĸ
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
	FLAG = 0; // FLAG����ָʾ��ֵ���ʽ�Ƿ����
	i = 0;
	scanf("%s", str);
	if (str[0] == '\0') // û������ʱֱ���˳�
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