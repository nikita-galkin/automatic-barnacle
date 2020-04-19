#include "natural.h"
#include "integer.h"// � ������ ������� ������� ����������� ������� ������� ����� �� ������ 0
//res.sign==-1 ��� ������
integer_number read_Z(int n)
{
	integer_number A; char c;
	if (n <= 0) { printf("error invalid n in read_Z\n"); A.sign = -1; return A; }//check
	A.length = n;
	if (scanf("%c", &c) == EOF) { printf("error scanf read_Z\n"); A.sign = -1; return A; }
	if (c == '-') {
		A.sign = 1; A.numb = read_NN(n);
		if (A.numb == NULL) { printf("error NULL pointer read_Z\n"); A.sign = -1; return A; }//check
	}
	else {
		A.sign = 0;	A.numb = new uint8_t[n + 2];
		if (A.numb == NULL) { printf("error NULL pointer read_Z\n"); A.sign = -1; return A; }//check
		A.numb[n - 1] = c - '0';
		for (int i = n - 2; i >= 0; i--) {
			if (scanf("%c", &c) == EOF) { printf("error scanf read_Z\n"); A.sign = -1; return A; }
			A.numb[i] = c - '0';
			if (A.numb[i] > 9) { printf("numb error read_Z\n"); A.sign = -1; return A; }//check
		}
	}
	return A;//����� ��������� �� ������, ��������� �������
}
//-1 ��� ������
int print_Z(integer_number A)
{
	if (A.sign == -1) { printf("������ �������� ������ print_z\n"); return -1; }//check
	if (A.numb == NULL) { printf("������ ��������� print_z\n"); return -1; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ print_z\n"); return -1; }//check
	if (A.sign) printf("-");
	if (print_NN(A.numb, A.length) == -1) { printf("������ ������ print_Z\n"); return -1; }
	return 0;
}
//res.sign==-1 ��� ������
integer_number ABS_Z_N(integer_number A)
{
	if (A.sign == -1) { printf("������ �������� ������ ABS_Z_N\n"); return A; }//check
	if (A.numb == NULL) { printf("������ ��������� ABS_Z_N\n"); A.sign = -1; return A; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length >= MAXSIZE) { printf("������ �������� ������ ABS_Z_N\n"); A.sign = -1; return A; }//check
	A.sign = 0;
	return A;
}
//-1 ��� ������
int POZ_Z_D(integer_number A)
{
	if (A.sign == -1) { printf("������ �������� ������ POZ_Z_D\n"); return -1; }//check
	if (A.numb == NULL) { printf("������ ��������� POZ_Z_D\n"); return -1; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ POZ_Z_D\n"); A.sign = -1; return -1; }//check
	if ((A.length == 1) && (A.numb[0] == 0)) return 0;
	if (A.sign) return 1;
	return 2;
}
//res.sign==-1 ��� ������
integer_number MUL_ZM_Z(integer_number A)
{
	if (A.sign == -1) { printf("������ �������� ������ MUL_ZM_N\n"); return A; }//check
	if (A.numb == NULL) { printf("������ ��������� MUL_ZM_N\n"); A.sign = -1; return A; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ MUL_ZM_N\n"); A.sign = -1; return A; }//check
	A.sign = (A.sign - 1) * (-1);
	return A;
}
//res.sign==-1 ��� ������
integer_number TRANS_N_Z(uint8_t* AA, int n)
{
	integer_number A;
	if (AA == NULL) { printf("������ ��������� TRANZ_N_Z\n"); A.sign = -1; return A; }//check
	int MAXSIZE = _msize(AA);
	if (n <= 0 || n > MAXSIZE) { printf("������ �������� ������ TRANZ_N_Z\n"); A.sign = -1; return A; }//check
	A.length = n; A.sign = 0; A.numb = AA;
	return A;//������ ��������� � ��� �� �������
}
//NULL ��� ������
uint8_t* TRANZ_Z_N(integer_number A, int* n)
{
	if (A.sign == -1) { printf("������ �������� ������ TRANZ_Z_N\n"); return NULL; }//check
	if (A.numb == NULL) { printf("������ ��������� TRANZ_Z_N\n"); return NULL; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ TRANZ_Z_N\n"); return NULL; }//check
	*n = A.length;
	return A.numb;
}
//res.sign==-1 ��� ������
integer_number ADD_ZZ_Z(integer_number A, integer_number B)
{
	integer_number Z;
	Z.numb = NULL; Z.length = -1;
	if (B.sign == -1) { printf("������ �������� ������ ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (A.sign == -1) { printf("������ �������� ������ ADD_ZZ_Z\n"); Z.sign = -1;  return Z; }//check
	if (B.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (A.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	MAXSIZE = _msize(B.numb);
	if (B.length <= 0 || B.length > MAXSIZE) { printf("������ �������� ������ ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (A.sign == B.sign)
	{
		Z.sign = A.sign;
		Z.numb = ADD_NN_N(A.numb, B.numb, A.length, B.length, &Z.length);
		if (Z.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		MAXSIZE = _msize(Z.numb);
		if (Z.length <= 0 || Z.length > MAXSIZE) { printf("������ �������� ������ ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		return Z;
	}
	int flag = COM_NN_D(A.numb, B.numb, A.length, B.length);
	if (flag == -1) { printf("COM error ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (!flag)
	{
		Z.sign = 0;
		Z.length = 1;
		Z.numb = new uint8_t[2];
		if (Z.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		Z.numb[0] = 0;
		return Z;
	}
	Z.sign = !(A.sign + flag == 2);
	flag--;
	if (flag)
	{
		A.numb = SUB_NN_N(A.numb, B.numb, A.length, B.length, &Z.length);
		Z.numb = new uint8_t[Z.length + 1];
		if (A.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		MAXSIZE = _msize(A.numb);
		if (Z.length > MAXSIZE || Z.length <= 0) { printf("������ ������������ ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		if (Z.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		if (numbcpy(Z.numb, A.numb, Z.length) == -1) { printf("numbcpy error ADD_ZZ_Z\n"); Z.sign = -1; return Z; }
	}
	else
	{
		B.numb = SUB_NN_N(B.numb, A.numb, B.length, A.length, &Z.length);
		Z.numb = new uint8_t[Z.length + 1];
		if (B.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		MAXSIZE = _msize(B.numb);
		if (Z.length > MAXSIZE || Z.length <= 0) { printf("������ ������������ ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		if (Z.numb == NULL) { printf("������ ��������� ADD_ZZ_Z\n"); Z.sign = -1; return Z; }//check
		if (numbcpy(Z.numb, B.numb, Z.length) == -1) { printf("numbcpy error ADD_ZZ_Z\n"); Z.sign = -1; return Z; }
	}
	return Z;
}
//res.sign==-1 ��� ������
integer_number SUB_ZZ_Z(integer_number A, integer_number B)
{
	integer_number Z;
	Z.numb = NULL;
	Z.length = -1;
	if (B.sign == -1) { printf("������ �������� ������ SUB_ZM_N\n"); Z.sign = -1; return Z; }//check
	if (A.sign == -1) { printf("������ �������� ������ SUB_ZZ_Z\n"); Z.sign = -1;  return Z; } //check
	if (A.numb == NULL) { printf("������ ��������� SUB_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (B.numb == NULL) { printf("������ ��������� SUB_ZM_N\n"); Z.sign = -1; return Z; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ SUB_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	MAXSIZE = _msize(B.numb);
	if (B.length <= 0 || B.length > MAXSIZE) { printf("������ �������� ������ SUB_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	B = MUL_ZM_Z(B);
	if (B.sign == -1) { printf("������ MUL_ZM_Z SUB_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	return ADD_ZZ_Z(A, B);
}
//res.sign==-1 ��� ������
integer_number MUL_ZZ_Z(integer_number A, integer_number B)
{
	integer_number Z;
	Z.numb = NULL;
	Z.length = -1;
	if (B.sign == -1) { printf("������ �������� ������ MUL_ZM_N\n"); Z.sign = -1; return Z; }//check
	if (A.sign == -1) { printf("������ �������� ������ MUL_ZZ_Z\n"); Z.sign = -1;  return Z; } //check
	if (A.numb == NULL) { printf("������ ��������� MUL_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (B.numb == NULL) { printf("������ ��������� MUL_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ MUL_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	MAXSIZE = _msize(B.numb);
	if (B.length <= 0 || B.length > MAXSIZE) { printf("������ �������� ������ MUL_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	Z.sign = (A.sign ^ B.sign);//XOR
	Z.numb = MUL_NN_N(A.numb, B.numb, A.length, B.length, &Z.length);
	if (Z.numb == NULL) { printf("������ �������� ������ MUL_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	return Z;
}
//res.sign==-1 ��� ������
integer_number DIV_ZZ_Z(integer_number A, uint8_t* B, int m)
{
	integer_number Z; Z.sign = A.sign;
	if (A.sign == -1) { printf("error in DIV_ZZ_Z\n"); return Z; }//check
	if (A.numb == NULL || B == NULL) { printf("error in DIV_ZZ_Z\n"); Z.sign = -1; return Z; }//chrck
	int MAXSIZE = _msize(A.numb);
	if (A.length <= 0 || A.length > MAXSIZE) { printf("������ �������� ������ DIV_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	Z.numb = DIV_NN_N(A.numb, B, A.length, m, &Z.length);
	if (Z.numb == NULL) { printf("������ DIV_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	if (Z.sign) Z.numb = ADD_1N_N(Z.numb, &Z.length);
	if (Z.numb == NULL) { printf("������ DIV_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	return Z;
}
//res.sign==-1 ��� ������
integer_number MOD_ZZ_Z(integer_number A, uint8_t* B, int m)
{
	integer_number Z, Z1, BZ; Z.sign = 0;
	if (A.sign == -1) { printf("error in DIV_ZZ_Z\n"); return Z; }//check
	if (A.numb == NULL || B == NULL) { printf("error in DIV_ZZ_Z\n"); Z.sign = -1; return Z; }//check
	uint8_t* AA = A.numb, * BB = new uint8_t[m + 1];;
	if (numbcpy(BB, B, m) == -1) { printf("error in MOD_ZZ_Z");  Z.sign = -1; return Z; }//check
	BZ = TRANS_N_Z(BB, m);
	if (BZ.sign == -1) { printf("error in MOD_ZZ_Z");  Z.sign = -1; return Z; }//check
	Z.numb = MOD_NN_N(&AA, &B, A.length, m, &Z.length); delete[] B;
	if (Z.numb == NULL) { printf("error in MOD_ZZ_Z");  Z.sign = -1; return Z; }//check
	Z1 = SUB_ZZ_Z(Z, BZ);
	if (Z1.sign == -1) { printf("error in MOD_ZZ_Z");  Z.sign = -1; return Z; }//check
	delete[]Z.numb;
	delete[]BZ.numb;
	Z1.sign = 0;
	return Z1;//��� �� ���������, ��� ��� � �
}
//-1 ��� ������
int integer()
{
	while (1) {
		printf("������� ����� �������� �������� ���������� � ������������\n1) ���������� �������� �����, ��������� - �����������\n2) ����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 1 - �������������)\n3) ��������� ������ �� (-1)\n4) �������������� ������������ � �����\n5) �������������� ������ ���������������� � �����������\n6) �������� ����� �����\n7) ��������� ����� �����\n8) ��������� ����� �����\n9) ������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n10) ������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n");
		int x, n, m; char c; uint8_t* AA;
		integer_number A, B, res;
		if (scanf("%d", &x) == EOF) return -1;
		if ((x != 4) && (x != 0)) {
			printf("������� n\n");
			if (scanf("%d%c", &n, &c) == EOF) return -1;;
			A = read_Z(n);
			n = 0;
		}
		switch (x) {
		case 1:
			A = ABS_Z_N(A);
			if (A.sign == -1) return -1;
			print_Z(A);
			delete[] A.numb;
			break;
		case 2:
			printf("%d\n", POZ_Z_D(A));
			delete[] A.numb;
			break;
		case 3:
			A = MUL_ZM_Z(A);
			if (A.sign == -1) return -1;
			print_Z(A);
			delete[] A.numb;
			break;
		case 4:
			printf("������� n\n");
			if (scanf("%d%c", &n, &c) == EOF) return -1;
			AA = read_NN(n);
			A = TRANS_N_Z(AA, n);
			if (A.sign == -1) return -1;
			print_Z(A);
			delete[] AA;
			break;
		case 5:
			AA = TRANZ_Z_N(A, &n);
			if (AA == NULL) return -1;
			print_NN(AA, n);
			delete[] AA;
			break;
		case 6:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_Z(m);
			res = ADD_ZZ_Z(A, B);
			if (res.sign == -1) return -1;
			delete[] A.numb; delete[] B.numb;
			print_Z(res);
			delete[] res.numb;
			break;
		case 7:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_Z(m);
			res = SUB_ZZ_Z(A, B);
			if (res.sign == -1) return -1;
			delete[] A.numb; delete[] B.numb;
			print_Z(res);
			delete[] res.numb;
			break;
		case 8:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_Z(m);
			res = MUL_ZZ_Z(A, B);
			if (res.sign == -1) return -1;
			delete[] A.numb; delete[] B.numb;
			print_Z(res);
			delete[] res.numb;
			break;
		case 9:
			printf("������� n\n");
			if (scanf("%d%c", &n, &c) == EOF) return -1;
			AA = read_NN(n);
			res = DIV_ZZ_Z(A, AA, n);
			if (res.sign == -1) return -1;
			delete[] A.numb; delete[] AA;
			print_Z(res);
			delete[] res.numb;
			break;
		case 10:
			printf("������� n\n");
			if (scanf("%d%c", &n, &c) == EOF) return -1;
			AA = read_NN(n);
			res = MOD_ZZ_Z(A, AA, n);
			if (res.sign == -1) return -1;
			print_Z(res);
			delete[] res.numb;
			break;
		default: return 0;
			break;
		}
	}
	return 0;
}