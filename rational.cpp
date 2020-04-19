#include "natural.h"
#include "integer.h"
#include "rational.h"
//rational_number 
//Q.sign==-1 ��� ������
rational_number read_QQ()
{
	int n, m; char c;
	rational_number Q;
	integer_number Z;
	printf("������� n\n");
	if (scanf("%d%c", &n, &c) == EOF) { printf("scanf error in read_QQ\n"); Q.sign = -1; return Q; }//check
	printf("������� ���������: ");
	Z = read_Z(n);
	if (Z.sign == -1) { printf("read_Z error in read_QQ\n"); Q.sign = -1; return Q; }//check
	printf("������� m\n");
	if (scanf("%d%c", &m, &c) == EOF) { printf("scanf error in read_QQ\n"); Q.sign = -1; return Q; }//check
	printf("������� �����������: ");
	Q.zn = read_NN(m);
	if (Q.zn == NULL) { printf("NULL pointer in read_QQ\n"); Q.sign = -1; return Q; }//check
	Q.m = m;
	Q.n = n;
	Q.ch = Z.numb;
	Q.sign = Z.sign;
	return Q;
}
//-1 � ������ ������
int free_Q(rational_number Q)
{
	if (Q.ch == NULL || Q.zn == NULL) { printf("error in free_Q\n"); return -1; }//check
	delete[]Q.ch; Q.ch = NULL;
	delete[]Q.zn; Q.zn = NULL;
	return 0;
}
//Q.sign==-1 ��� ������
rational_number Qcpy(rational_number Q)
{
	rational_number Q1;
	Q1.ch = new uint8_t[Q.n + 1];
	Q1.zn = new uint8_t[Q.m + 1];
	if (Q1.ch == NULL || Q1.zn == NULL) { printf("pointer error in Qcpy\n"); Q1.sign = -1; return Q1; }//check
	if (numbcpy(Q1.ch, Q.ch, Q.n) == -1) { printf("numbcpy error in Qcpy\n"); Q1.sign = -1; return Q1; }//check
	if (numbcpy(Q1.zn, Q.zn, Q.m) == -1) { printf("numbcpy error in Qcpy\n"); Q1.sign = -1; return Q1; }//check
	Q1.n = Q.n;
	Q1.m = Q.m;
	Q1.sign = Q.sign;
	return Q1;
}
//-1 � ������ ������
int print_QQ(rational_number Q)
{
	integer_number Z = TRANS_Q_Z(Q);
	if (INT_Q_B(Q)) { print_Z(Z); return 0; }
	printf("���������: ");
	if (print_Z(Z) == -1) { printf("error in print_QQ\n"); return -1; }//check
	printf("�����������: ");
	if (print_NN(Q.zn, Q.m) == -1) { printf("error in print_QQ\n"); return -1; }//check
	return 0;
}
//Q.sign==-1 ��� ������
rational_number RED_Q_Q(rational_number Q)
{
	uint8_t* A, * B, * t1;
	int m = Q.m, n = Q.n, p;
	A = new uint8_t[n + 1];
	B = new uint8_t[m + 1];
	numbcpy(A, Q.ch, n);
	numbcpy(B, Q.zn, m);
	A = GCF_NN_N(&A, &B, &n, &m, &p);
	t1 = DIV_NN_N(Q.ch, A, Q.n, p, &Q.n);
	delete[] Q.ch;
	Q.ch = t1;
	t1 = DIV_NN_N(Q.zn, A, Q.m, p, &Q.m);
	delete[] Q.zn;
	Q.zn = t1;
	delete[] A;
	delete[] B;
	return Q;
}
//-1 � ������ ������
int INT_Q_B(rational_number Q)
{//�������� �� ����� �����
	return ((Q.zn[0] == 1) && (Q.m == 1));
}
//Q.sign==-1 ��� ������
rational_number TRANS_Z_Q(integer_number Z)
{
	rational_number Q;
	Q.zn = new uint8_t[2];
	Q.zn[0] = 1;
	Q.m = 1;
	Q.n = Z.length;
	Q.ch = Z.numb;
	Q.sign = Z.sign;
	return Q;
}
//Z.sign==-1 ��� ������
integer_number TRANS_Q_Z(rational_number Q)
{
	integer_number Z;
	Z.length = Q.n;
	Z.numb = Q.ch;
	Z.sign = Q.sign;
	return Z;//������ ����� � ��� �� ������
}
//Q.sign==-1 ��� ������
rational_number ADD_QQ_Q(rational_number Q1, rational_number Q2)
{
	rational_number Q;
	integer_number Z1, Z2, Z;
	uint8_t* temp, * temp1;
	int n1, n2;
	int flag = COM_NN_D(Q1.zn, Q2.zn, Q1.m, Q2.m);
	if (flag) {
		Q.zn = MUL_NN_N(Q1.zn, Q2.zn, Q1.m, Q2.m, &(Q.m));
		temp = MUL_NN_N(Q1.ch, Q2.zn, Q1.n, Q2.m, &n1);
		temp1 = MUL_NN_N(Q2.ch, Q1.zn, Q2.n, Q1.m, &n2);
		Z1.length = n1; Z2.length = n2;
		Z1.numb = temp; Z2.numb = temp1;
		Z1.sign = Q1.sign; Z2.sign = Q2.sign;
		Z = ADD_ZZ_Z(Z1, Z2);
		delete[] temp; delete[] temp1;
	}
	else
	{
		Q.zn = MUL_ND_N(Q1.zn, Q1.m, 1, &(Q.m));
		Z1 = TRANS_Q_Z(Q1); Z2 = TRANS_Q_Z(Q2);
		Z = ADD_ZZ_Z(Z1, Z2);
	}
	Q.ch = Z.numb;
	Q.n = Z.length;
	Q.sign = Z.sign;
	return Q;//������ ����� ������, ������� ����� �� ������� �� �������� ������, ��� ��������, ��� � Q1 � Q2 ����� ����������� ������
}
//Q.sign==-1 ��� ������
rational_number SUB_QQ_Q(rational_number Q1, rational_number Q2)
{
	Q2.sign = (Q2.sign - 1) * (-1);
	rational_number Q = ADD_QQ_Q(Q1, Q2);
	return Q;
}
//Q.sign==-1 ��� ������
rational_number MUL_QQ_Q(rational_number Q1, rational_number Q2)
{
	rational_number Q;
	Q.sign = (Q1.sign ^ Q2.sign);//XOR
	Q.ch = MUL_NN_N(Q1.ch, Q2.ch, Q1.n, Q2.n, &(Q.n));
	Q.zn = MUL_NN_N(Q1.zn, Q2.zn, Q1.m, Q2.m, &(Q.m));
	return Q;
}
//Q.sign==-1 ��� ������
rational_number DIV_QQ_Q(rational_number Q1, rational_number Q2)
{
	rational_number Q;
	Q.ch = Q2.zn;
	Q.zn = Q2.ch;
	Q.m = Q2.n;
	Q.n = Q2.m;
	Q.sign = Q2.sign;
	return MUL_QQ_Q(Q1, Q);
}
int rational()
{
	while (1) {
		printf("������� ����� �������� �������� ���������� � ������������\n1) ���������� �����\n2) �������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����\n3) �������������� ������ � �������\n4) �������������� �������� � ����� (���� ����������� ����� 1)\n5) �������� ������\n6) ��������� ������\n7) ��������� ������\n8) ������� ������ (�������� ������� �� ����)\n");
		int x, n; char c;
		rational_number A, B, res;
		integer_number Z;
		if (scanf("%d", &x) == EOF) return -1;
		if (x == 0) return 0;
		if (x != 3) A = read_QQ();
		switch (x) {
		case 1:
			A = RED_Q_Q(A);
			print_QQ(A);
			free_Q(A);
			break;
		case 2:
			printf("%d\n", INT_Q_B(A));
			free_Q(A);
			break;
		case 3:
			printf("������� n\n");
			if (scanf("%d%c", &n, &c) == EOF) return -1;
			Z = read_Z(n);
			A = TRANS_Z_Q(Z);
			print_QQ(A);
			free_Q(A);
			break;
		case 4:
			if (INT_Q_B(A))
			{
				Z = TRANS_Q_Z(A);
				print_Z(Z);
			}
			free_Q(A);
			break;
		case 5:
			B = read_QQ();
			res = ADD_QQ_Q(A, B);
			res = RED_Q_Q(res);
			print_QQ(res);
			free_Q(A);
			free_Q(B);
			free_Q(res);
			break;
		case 6:
			B = read_QQ();
			res = SUB_QQ_Q(A, B);
			print_QQ(res);
			free_Q(A);
			free_Q(B);
			free_Q(res);
			break;
		case 7:
			B = read_QQ();
			res = MUL_QQ_Q(A, B);
			print_QQ(res);
			free_Q(A);
			free_Q(B);
			free_Q(res);
			break;
		case 8:
			B = read_QQ();
			res = DIV_QQ_Q(A, B);
			print_QQ(res);
			free_Q(A);
			free_Q(B);
			free_Q(res);
			break;
		default: return 0;
			break;
		}
		if (scanf("%c%c", &c, &c) == EOF) return -1;
	}
	return 0;
}