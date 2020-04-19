//����� ��� �������� ������ ����� ���������� ����� ������
#include "natural.h"
//NULL ��� ������
uint8_t* read_NN(int n)
{
	char c; int MAXSIZE = n + 1;
	if (n == 0) { printf("������ �����\n"); return NULL; }//check
	uint8_t* x = new uint8_t[MAXSIZE];
	if (x == NULL) { printf("Error new readNN\n"); return NULL; }//check
	for (int i = n - 1; i >= 0; i--) {
		if (i > MAXSIZE) { printf("Error size readNN\n"); return NULL; }//check
		if (scanf("%c", &c) == EOF)
		{
			printf("Error scanf readNN\n"); return NULL;
		}//check
		x[i] = c - '0';
		if (x[i] > 9) { printf("Error x readNN\n"); return NULL; }//check
	}
	return x;
}
//�-1 ��� ������
int print_NN(uint8_t* A, int n)
{
	if (A == NULL) { printf("������ ��������� � printNN\n"); return -1; }//check
	int MAXSIZE = _msize(A);//check
	if (n > MAXSIZE || n <= 0) { printf("Error MAXSIZE int print_NN\n"); return -1; }//check
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", A[i]);
		if (A[i] > 9) { printf("Error MAXSIZE int print_NN\n"); return -1; }//check
	}
	printf("\n");
	return 0;
}
//-1 ��� ������
int numbcpy(uint8_t* A, uint8_t* B, int n)
{
	if ((A == NULL) || (B == NULL)) { printf("������ ��������� � numbcpy\n"); return -1; }//check
	int i, MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B);//check
	if (!n) { printf("zero length numbcpy"); return -1; }//check
	if (n > MAXSIZE_A || n > MAXSIZE_B || n <= 0) { printf("too loong n in numbcpy\n"); return -1; }//check
	for (i = 0; i < n; i++)
	{
		A[i] = B[i];
		if (B[i] > 9) { printf("incorrect B[i] numbcpy\n"); return -1; }//check
	}
	return 0;
}
//-1 ��� ������
int COM_NN_D(uint8_t* A, uint8_t* D, int n, int m)
{
	if (A == NULL || D == NULL) { printf("������ ��������� � COM_NN_D\n"); return -1; }//check
	int i, MAXSIZE_A = _msize(A), MAXSIZE_D = _msize(D);//check
	if (n > MAXSIZE_A || m > MAXSIZE_D || n <= 0 || m <= 0) { printf("MAXSIZE error in COM_NN_D\n"); return -1; }//check
	if (n > m) return 2;
	if (n < m) return 1;
	for (i = n - 1; i >= 0; i--)
		if (A[i] > D[i]) return 2;
		else if (A[i] != D[i]) return 1;
	return 0;
}
//-1 ��� ������
int NZER_N_B(uint8_t* A, int n)
{
	if (A == NULL) { printf("������ ��������� � NZER_N_B\n"); return -1; }//check
	if (n > (int)(_msize(A)) || n <= 0) { printf("MAXSIZE error in NZER_N_B\n"); return -1; }//check
	return !((n == 1) && (A[0] == 0));
}
//Null ��� ������
uint8_t* ADD_1N_N(uint8_t* A, int* n)
{
	if ((A == NULL) || (n == NULL)) { printf("������ ��������� � ADD_1N_N\n"); return NULL; }//check
	int i, nn = *n, MAXSIZE_A = _msize(A);//check
	if (nn > MAXSIZE_A || nn <= 0) { printf("MAXSIZE error in ADD_1N_N\n"); return NULL; }//check
	for (i = 0; i < nn; i++)
	{
		A[i]++;
		if (A[i] > 10) { printf("incorrect A[i] � ADD_1N_N\n"); return NULL; }//check
		if (A[i] == 10) A[i] = 0;
		else return A;
	}
	uint8_t* temp = new uint8_t[MAXSIZE_A + 1];
	if (temp == NULL) { printf("������ ��������� � ADD_1N_N\n"); return NULL; }//check
	if (numbcpy(temp, A, nn) < 0)
	{
		printf("error numbcpy � ADD_1N_N\n"); return NULL;
	}//check
	delete[] A;
	A = temp;
	A[nn] = uint8_t(1);
	*n = nn + 1;
	return A;
}
//NULL ��� ������
uint8_t* ADD_NN_N(uint8_t* A, uint8_t* B, int n, int m, int* p)// � p ����� ������ ��������� �������
{
	if ((A == NULL) || (B == NULL)) { printf("������ ��������� � ADD_NN_N\n"); return NULL; }//check
	uint8_t* temp; int tempint, i, x, MAX_temp, MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B), COM = COM_NN_D(A, B, n, m);
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � ADD_NN_N\n"); return NULL; }//check
	if (COM == -1) { printf("error in ADD_NN_N\n"); return NULL; }//check
	if (COM == 1) { temp = A; A = B; B = temp; x = n; n = m; m = x; }
	x = 0;
	MAX_temp = n + 2;
	temp = new uint8_t[MAX_temp];
	if (temp == NULL) { printf("������ ��������� � ADD_NN_N\n"); return NULL; }//check
	for (i = 0; i < n; i++)
	{
		if (i > MAX_temp || i > MAXSIZE_A || (i > MAXSIZE_B&& i < m)) { printf("������������ in ADD_NN_N\n"); return NULL; }//check
		tempint = x + A[i];
		if (tempint < 0) { printf("error tempint\n"); return NULL; }//check
		temp[i] = tempint;
		if (i < m) temp[i] += B[i];
		if (temp[i] >= 10) { x = 1; temp[i] -= 10; }
		else x = 0;
		if (temp[i] > 10) { printf("������������ temp[i] in ADD_NN_N\n"); return NULL; }//check
		if (i < m && B[i] > 9) { printf("������������ B[i] in ADD_NN_N\n"); return NULL; }//check
	}
	if (n > MAX_temp) { printf("������������ n in ADD_NN_N\n"); return NULL; }//check
	*p = n;
	if (x) { (*p)++; temp[n] = 1; }
	return temp;
}
//NULL ��� ������
uint8_t* SUB_NN_N(uint8_t* A, uint8_t* B, int n, int m, int* p)
{
	if ((A == NULL) || (B == NULL)) { printf("������ ��������� � SUB_NN_N\n"); return NULL; }//check
	int i, flag = 1, x = 0, MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B);
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � SUB_NN_N\n"); return NULL; }//check
	for (i = 0; i < n; i++)
	{
		x += A[i];
		if (i < m) x -= B[i];
		if (x < 0)
		{
			A[i] = x + 10;
			x = -1;
		}
		else {
			A[i] = x;
			x = 0;
			if (i > m) break;
		}
		if (A[i] > 10) { printf("error A[i] in SUB_NN_N\n"); return NULL; }//check
		if (i < m && B[i] > 10) { printf("error B[i] in SUB_NN_N\n"); return NULL; }//check
	}
	for (i = n - 1; i >= 0; i--)
		if (A[i]) {
			*p = i + 1;
			flag = 0;
			break;
		}
	if (flag) *p = 1;
	return A;
}
//NULL ��� ������
uint8_t* MUL_ND_N(uint8_t* A, int n, int a, int* p)
{
	if (A == NULL) { printf("������ ��������� � MUL_ND_N\n"); return NULL; }//check
	int i, x, MAXSIZE_A = _msize(A), r = 0, MAXSIZE_temp = n + 2; uint8_t* temp;
	if (n > MAXSIZE_A || n <= 0) { printf("Maxsize error � MUL_ND_N\n"); return NULL; }//check
	if (a > 9 || a < 0) { printf("invalid input a MUL_ND_N\n");	return NULL; }//check
	if (a == 0) {
		temp = new uint8_t[2];
		if (temp == NULL) { printf("������ ��������� � MUL_ND_N\n"); return NULL; }//check
		temp[0] = 0;
		*p = 1;
		return temp;
	}
	temp = new uint8_t[MAXSIZE_temp];
	if (temp == NULL) { printf("������ ��������� � MUL_ND_N\n"); return NULL; }//check
	for (i = 0; i < MAXSIZE_temp - 2; i++)
	{
		x = ((A[i] * a + r) % 10);
		if (x < 0 || x > 9 || A[i] > 10) { printf("������ ������������ ����� � MUL_ND_N\n"); return NULL; }//check
		temp[i] = uint8_t(x);
		r = (A[i] * a + r) / 10;
	}
	if (r) {
		temp[MAXSIZE_temp - 2] = uint8_t(r % 10);
		n++;
	}
	*p = n;
	return temp;
}
//NULL ��� ������
uint8_t* MUL_Nk_N(uint8_t* A, int n, int k, int* p)//7
{
	if (A == NULL) { printf("������ ��������� � MUL_Nk_N\n"); return NULL; }//check
	int i, MAXSIZE_A = _msize(A), MAXSIZE_temp = n + k + 2; uint8_t* temp;
	if (n > MAXSIZE_A || n <= 0) { printf("Maxsize error � MUL_Nk_N\n"); return NULL; }//check
	if (k < 0) { printf("invalid k MUL_Nk_N\n"); return NULL; }//check
	if (k == 0) return MUL_ND_N(A, n, 1, p);
	temp = new uint8_t[MAXSIZE_temp];
	if (temp == NULL) { printf("������ ��������� � MUL_Nk_N\n"); return NULL; }//check
	for (i = 0; i < MAXSIZE_temp - 2 - n; i++) temp[i] = uint8_t(0);
	for (int i = k; i < MAXSIZE_temp - 2; i++)
	{
		if (A[i - k] > 9) { printf("����� �� ������� ��������� � MUL_Nk_N\n"); return NULL; }//check
		temp[i] = uint8_t(A[i - k]);
	}
	*p = n + k;
	return temp;
}
//NULL ��� ������
uint8_t* MUL_NN_N(uint8_t* A, uint8_t* B, int n, int m, int* p)
{
	if (A == NULL || B == NULL) { printf("������ ��������� � MUL_NN_N\n"); return NULL; }//check
	int i, temp_n = 1, T_B = 1, MAXSIZE_temp = m + n + 2, MAXSIZE_x, MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B); uint8_t* x, * y, * temp;
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � MUL_NN_N\n"); return NULL; }//check
	temp = new uint8_t[MAXSIZE_temp];
	if (temp == NULL) { printf("������ ��������� � MUL_NN_N\n"); return NULL; }//check
	temp[0] = 0;
	for (i = 0; i < n; i++)
	{
		x = MUL_ND_N(B, m, A[i], &T_B);//�������� ������ ��� ������, �������� �� �����
		if (x == NULL) { printf("������ ��������� � MUL_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(x);//check
		if (T_B > MAXSIZE_x) { printf("too big T_B � MUL_NN_N\n"); return NULL; }//check
		y = MUL_Nk_N(x, T_B, i, &T_B);//���������� ���������
		if (y == NULL) { printf("������ ��������� � MUL_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(y);//check
		if (T_B > MAXSIZE_x) { printf("too big T_B � MUL_NN_N\n"); return NULL; }//check
		delete[] x; x = NULL;
		x = ADD_NN_N(y, temp, T_B, temp_n, &temp_n);//���������� ���������
		if (x == NULL) { printf("������ ��������� � MUL_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(x);//check
		if (temp_n > MAXSIZE_x || temp_n > MAXSIZE_temp) { printf("too big temp_n � MUL_NN_N\n"); return NULL; }//check
		delete[] y;	y = NULL;
		if (numbcpy(temp, x, temp_n) == -1) { printf("error � MUL_NN_N\n"); return NULL; }//������ ����������� strcp�, �.�. �� �������� �������  <32 
		delete[] x;	x = NULL;
	}
	*p = temp_n;
	return temp;
}
//NULL ��� ������
uint8_t* SUB_NDN_N(uint8_t* A, uint8_t* B, int n, int m, int k, int* p)//9//������ ���������, ����������� � �
{
	if (A == NULL || B == NULL) { printf("������ ��������� � SUB_NDN_N\n"); return NULL; }//check
	int MAXSIZE_x, MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B), COM; uint8_t* x, * y;
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � SUB_NDN_N\n"); return NULL; }//check
	if (k < 0) { printf("invalid k � SUB_NDN_N\n"); return NULL; }//check
	x = MUL_ND_N(B, m, k, &m);
	if (x == NULL) { printf("������ ��������� � SUB_NDN_N\n"); return NULL; }//check
	MAXSIZE_x = _msize(x);//check
	if (MAXSIZE_x < m) { printf("error maxsize_x SUB_NDN_N\n"); return NULL; }//check
	COM = COM_NN_D(A, x, n, m);//check
	if (COM == 1) return NULL;//check
	if (COM == -1) { printf("error � SUB_NDN_N\n"); return NULL; }//check
	y = SUB_NN_N(A, x, n, m, p);
	if (y == NULL) { printf("������ ��������� � SUB_NDN_N\n"); return NULL; }//check
	MAXSIZE_x = _msize(y);//check
	if (MAXSIZE_x < *p) { printf("error maxsize_x SUB_NDN_N\n"); return NULL; }//check
	delete[] x;	x = NULL;
	return y;
}
//-1 ��� ������
int DIV_NN_Dk(uint8_t* A, uint8_t* B, int n, int m, int* k)//10
{
	if (A == NULL || B == NULL) { printf("������ ��������� � DIV_NN_Dk\n"); return -1; }//check
	int x, COM, MAXSIZE_temp1, MAXSIZE_temp, res = 1, q = 1, MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B); uint8_t* temp, * temp1;//check
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � DIV_NN_Dk\n"); return -1; }//check
	*k = 0;
	COM = COM_NN_D(A, B, n, m);
	if (COM == -1) { printf("error � DIV_NN_Dk\n"); return -1; }//check
	if (COM == 1) { temp = A; A = B; B = temp; x = n; n = m; m = x; }
	else if (COM == 0) return 1;
	x = n - m - 1;
	if (n == m) x = 0;
	*k = x;
	temp1 = MUL_Nk_N(B, m, x, &q);
	temp = MUL_Nk_N(B, m, x, &m);
	MAXSIZE_temp = _msize(temp);//check
	MAXSIZE_temp1 = _msize(temp1);//check
	if (temp == NULL || temp1 == NULL) { printf("������ ��������� � DIV_NN_Dk\n"); return -1; }//check
	if (q > MAXSIZE_temp1 || m > MAXSIZE_temp) { printf("error MAXSIZE � DIV_NN_Dk\n"); return -1; }//check
	while (COM_NN_D(A, temp1, n, q) != 1)
	{
		res++;
		delete[] temp1;
		temp1 = NULL;
		if (res == 10) {
			temp1 = MUL_Nk_N(temp, m, 1, &m);
			if (temp1 == NULL) { printf("������ ��������� � DIV_NN_Dk\n"); return -1; }//check
			MAXSIZE_temp1 = _msize(temp1);//check
			if (m > MAXSIZE_temp1) { printf("error MAXSIZE � DIV_NN_Dk\n"); return -1; }//check
			delete[]temp;
			temp = temp1;
			res = 1;
			(*k)++;
		}
		temp1 = MUL_ND_N(temp, m, res, &q);
		if (temp1 == NULL) { printf("������ ��������� � DIV_NN_Dk\n"); return -1; }//check
		MAXSIZE_temp1 = _msize(temp1);//check
		if (q > MAXSIZE_temp1) { printf("error MAXSIZE � DIV_NN_Dk\n"); return -1; }//check
		if (COM_NN_D(A, temp1, n, q) == -1) { printf("error � DIV_NN_Dk\n"); return -1; }//check
	}
	res--;
	delete[] temp; temp = NULL;
	delete[] temp1; temp1 = NULL;
	if (res == 0) { (*k)--; return 9; }
	return res;
}
//NULL ��� ������
uint8_t* DIV_NN_N(uint8_t* A, uint8_t* B, int n, int m, int* p)
{
	uint8_t i, * temp, * temp1, * temp2; int MAXSIZE_temp, MAXSIZE_temp1, t1, t2, q, x, k, COM = COM_NN_D(A, B, n, m);
	if (A == NULL || B == NULL) { printf("������ ��������� � DIV_NN_N\n"); return NULL; }//check
	int MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B);//check
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � DIV_NN_N\n"); return NULL; }//check
	if (COM == -1) { printf("error � DIV_NN_N\n"); return NULL; }//check
	if (COM == 1) { temp = A; A = B; B = temp; x = n; n = m; m = x; }
	MAXSIZE_temp = n - m + 2;
	temp = new uint8_t[MAXSIZE_temp];
	if (temp == NULL) { printf("������ ��������� � DIV_NN_N\n"); return NULL; }//check
	if ((m == 1) && (B[0] <= 1)) {
		*p = n;
		if (numbcpy(temp, A, n) == -1) { printf(" DIV_NN_N\n"); return NULL; }//check
		return temp;
	}
	for (i = 0; i < MAXSIZE_temp - 1; i++) temp[i] = uint8_t(0);
	q = 0;
	while (COM_NN_D(A, B, n, m) != 1)
	{
		x = DIV_NN_Dk(A, B, n, m, &k);
		if (x < 0 || x > 9) { printf("invalid x � DIV_NN_N\n"); return NULL; }//check
		temp1 = MUL_Nk_N(B, m, k, &t1);
		if (temp1 == NULL) { printf("������ ��������� � DIV_NN_N\n"); return NULL; }//check
		MAXSIZE_temp1 = _msize(temp1);//check
		if (t1 > MAXSIZE_temp1) { printf("MAXSIZE error � DIV_NN_N\n"); return NULL; }//check
		temp2 = MUL_ND_N(temp1, t1, x, &t2);
		if (temp2 == NULL) { printf("������ ��������� � DIV_NN_N\n"); return NULL; }//check
		MAXSIZE_temp1 = _msize(temp2);//check
		if (t2 > MAXSIZE_temp1) { printf("MAXSIZE error � DIV_NN_N\n"); return NULL; }//check
		delete[] temp1; temp1 = NULL;
		A = SUB_NN_N(A, temp2, n, t2, &n);
		if (A == NULL) { printf("������ ��������� � DIV_NN_N\n"); return NULL; }//check
		MAXSIZE_temp1 = _msize(A);//check
		if (n > MAXSIZE_temp1) { printf("MAXSIZE error � DIV_NN_N\n"); return NULL; }//check
		delete[] temp2;	temp2 = NULL;
		if (k + 1 > q) q = k + 1;
		if (k >= MAXSIZE_temp) { printf("MAXSIZE_temp error � DIV_NN_N\n"); return NULL; }//check
		temp[k] = uint8_t(x);
		if (COM_NN_D(A, B, n, m) == -1) { printf("error � DIV_NN_N\n"); return NULL; }//check
	}
	*p = q;
	return temp;
}
//NULL ��� ������
uint8_t* MOD_NN_N(uint8_t** AA, uint8_t** BB, int n, int m, int* p)
{
	if (AA == NULL || BB == NULL) { printf("������ ��������� � MOD_NN_N\n"); return NULL; }//check
	uint8_t* temp1, * temp2, * B = *BB, * A = *AA; int MAXSIZE_x, t1, t2, x, k, MAXSIZE_A, MAXSIZE_B, COM;
	if (A == NULL || B == NULL) { printf("������ ��������� � MOD_NN_N\n"); return NULL; }//check
	MAXSIZE_A = _msize(A), MAXSIZE_B = _msize(B);//check
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � MOD_NN_N\n"); return NULL; }//check
	COM = COM_NN_D(A, B, n, m);//check
	if (COM == -1) { printf("COM error � MOD_NN_N\n"); return NULL; }//check
	if (COM == 1) { temp1 = A; A = B; B = temp1; x = n; n = m; m = x; }
	while (COM_NN_D(A, B, n, m) != 1)
	{
		x = DIV_NN_Dk(A, B, n, m, &k);
		if (x > 9 || x < 0) { printf("������ ��������� � MOD_NN_N\n"); return NULL; }//check
		temp1 = MUL_Nk_N(B, m, k, &t1);
		if (temp1 == NULL) { printf("������ ��������� � MOD_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(temp1);//check
		if (MAXSIZE_x == -1) { printf("� x ��� ����� MOD_NN_N\n"); return NULL; }//check
		if (t1 > MAXSIZE_x) { printf("������������ � MOD_NN_N\n"); return NULL; }//check
		temp2 = MUL_ND_N(temp1, t1, x, &t2);
		if (temp2 == NULL) { printf("������ ��������� � MOD_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(temp2);//check
		if (MAXSIZE_x == -1) { printf("� x ��� ����� MOD_NN_N\n"); return NULL; }//check
		if (t2 > MAXSIZE_x) { printf("������������ � MOD_NN_N\n"); return NULL; }//check
		delete[]temp1;
		temp1 = NULL;
		A = SUB_NN_N(A, temp2, n, t2, &n);
		if (A == NULL) { printf("������ ��������� � MOD_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(A);//check
		if (MAXSIZE_x == -1) { printf("� x ��� ����� MOD_NN_N\n"); return NULL; }//check
		if (n > MAXSIZE_x) { printf("������������ � MOD_NN_N\n"); return NULL; }//check
		delete[] temp2;
		temp2 = NULL;
		if (COM_NN_D(A, B, n, m) == -1) { printf("COM error � MOD_NN_N\n"); return NULL; }//check
	}
	*p = n;
	return A;
}
//NULL ��� ������
uint8_t* GCF_NN_N(uint8_t** AA, uint8_t** BB, int* n, int* m, int* p)
{
	if (AA == NULL || BB == NULL || *AA == NULL || *BB == NULL || n == NULL || m == NULL) { printf("������ ��������� � GCF_NN_N\n"); return NULL; }//check
	int x, COM, MAXSIZE_x, MAXSIZE_A = _msize(*AA), MAXSIZE_B = _msize(*BB); uint8_t* temp;//check
	if (*n > MAXSIZE_A || *m > MAXSIZE_B || *n <= 0 || *m <= 0) { printf("Maxsize error � GCF_NN_N\n"); return NULL; }//check
	if (NZER_N_B(*AA, *n) + NZER_N_B(*BB, *m) < 2) { *p = 1; *AA[0] = 0;  return *AA; }
	COM = COM_NN_D(*AA, *BB, *n, *m);
	if (COM == -1) { printf("COM error � GCF_NN_N\n"); return NULL; }//check
	if (COM == 1) { temp = *AA; *AA = *BB; *BB = temp; x = *n; *n = *m; *m = x; }
	while (NZER_N_B(*BB, *m)) {
		*AA = MOD_NN_N(AA, BB, *n, *m, n);
		if (*AA == NULL) { printf("������ ��������� � GCF_NN_N\n"); return NULL; }//check
		MAXSIZE_x = _msize(*AA);//check
		if (*n > MAXSIZE_x) { printf("MAXSIZE error � GCF_NN_N\n"); return NULL; }//check
		temp = *AA; *AA = *BB; *BB = temp; x = *n; *n = *m; *m = x;
		if (NZER_N_B(*BB, *m) == -1) { printf("error NZER_N_B � GCF_NN_N\n"); return NULL; }//check
	}
	*p = *n;
	return *AA;
}
//NULL ��� ������
uint8_t* LCM_NN_N(uint8_t** AA, uint8_t** BB, int n, int m, int* p)
{
	if (AA == NULL || BB == NULL || *BB == NULL || *AA == NULL) { printf("Pointer error � LCM_NN_N"); return NULL; }//check
	int x, t1, t2, m_temp, MAXSIZE_B_temp, MAXSIZE_temp, MAXSIZE_A = _msize(*AA), MAXSIZE_B = _msize(*BB), COM = COM_NN_D(*AA, *BB, n, m); uint8_t* temp, * B_temp, * temp1;
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � LCM_NN_N"); return NULL; }//check
	if (COM == -1) { printf("COM error � LCM_NN_N"); return NULL; }//check
	if (COM == 1) { temp = *AA; *AA = *BB; *BB = temp; x = n; n = m; m = x; }
	MAXSIZE_temp = n + 1; t1 = n;
	temp = new uint8_t[MAXSIZE_temp];
	if (temp == NULL) { printf("Pointer error � LCM_NN_N"); return NULL; }//check
	temp[0] = 0;
	*p = 1;
	if (!NZER_N_B(*BB, m)) return temp;
	if (numbcpy(temp, *AA, n) < 0) { printf("numbcpy error � LCM_NN_N"); return NULL; }
	MAXSIZE_B_temp = m + 1;
	B_temp = new uint8_t[MAXSIZE_B_temp];
	if (B_temp == NULL) { printf("Pointer error � LCM_NN_N"); return NULL; }//check
	if (numbcpy(B_temp, *BB, m) < 0) { printf("numbcpy error � LCM_NN_N"); return NULL; }
	m_temp = m;
	temp = GCF_NN_N(&temp, &B_temp, &t1, &m_temp, &t1); delete[] B_temp; B_temp = NULL;
	if (temp == NULL) { printf("Pointer error � LCM_NN_N"); return NULL; }//check
	MAXSIZE_temp = _msize(temp);//check
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � LCM_NN_N"); return NULL; }//check
	temp1 = DIV_NN_N(*AA, temp, n, t1, &t2); delete[] temp; temp = NULL;
	if (temp1 == NULL) { printf("Pointer error � LCM_NN_N"); return NULL; }//check
	MAXSIZE_temp = _msize(temp1);//check
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � LCM_NN_N"); return NULL; }//check
	temp = MUL_NN_N(temp1, *BB, t2, m, p); delete[]temp1; temp1 = NULL;
	if (temp == NULL) { printf("Pointer error � LCM_NN_N"); return NULL; }//check
	MAXSIZE_temp = _msize(temp);//check
	if (n > MAXSIZE_A || m > MAXSIZE_B || n <= 0 || m <= 0) { printf("Maxsize error � LCM_NN_N"); return NULL; }//check
	return temp;
}
int natural()
{
	int x = 0, n = 0, m = 0, p = 0, k, a;
	uint8_t* A, * B, * res, c;
	while (1) {
		printf("������� ����� �������� �������� ���������� � ������������\n1) ��������� ����������� �����: \n2) �������� �� ���� : ���� ����� �� ����� ����, �� ��� ����� ����\n3) ���������� 1 � ������������ �����\n4) �������� ����������� �����\n5) ��������� �� ������� �������� ������������ ����� ������� �������� ��� �������\n6) ��������� ������������ ����� �� �����\n7) ��������� ������������ ����� �� 10^k\n8) ��������� ����������� �����\n9) ��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������\n10) ���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k,��� k - ������������ ���� ����� (����� ��������� � ����)\n11) ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n12) ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n13) ��� ����������� �����\n14) ��� ����������� �����\n");
		if (scanf("%d", &x) == EOF) return -1;
		if (x == 0) return 0;
		printf("������� n\n");
		if (scanf("%d%c", &n, &c) == EOF) return -1;
		A = read_NN(n);
		switch (x) {
		case 1:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			printf("%d\n", COM_NN_D(A, B, n, m));
			if (B == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[]B; B = NULL;
			break;
		case 2:
			printf("%d\n", NZER_N_B(A, n));
			if (A == NULL) { printf("error in natural");  return -1; }
			break;
		case 3:
			A = ADD_1N_N(A, &n);
			print_NN(A, n);
			if (A == NULL) { printf("error in natural");  return -1; }
			break;
		case 4:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			res = ADD_NN_N(A, B, n, m, &p);
			print_NN(res, p);
			if (B == NULL || res == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B; delete[] res;
			B = NULL; res = NULL;
			break;
		case 5:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			A = SUB_NN_N(A, B, n, m, &p);
			print_NN(A, p);
			if (B == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B; B = NULL;
			break;
		case 6:
			printf("������� �����\n");
			if (scanf("%d%c", &a, &c) == EOF) return -1;
			res = MUL_ND_N(A, n, a, &n);
			print_NN(res, n);
			if (res == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] res;
			res = NULL;
			break;
		case 7:
			printf("������� k\n");
			if (scanf("%d%c", &k, &c) == EOF) return -1;
			res = MUL_Nk_N(A, n, k, &n);
			if (res == NULL || A == NULL) return -1;
			print_NN(res, n);
			delete[] res;
			res = NULL;
			break;
		case 8:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			res = MUL_NN_N(A, B, n, m, &p);
			print_NN(res, p);
			if (B == NULL || res == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B; delete[] res;
			B = NULL; res = NULL;
			break;
		case 9:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			printf("������� �����\n");
			if (scanf("%d%c", &k, &c) == EOF) return -1;
			A = SUB_NDN_N(A, B, n, m, k, &p);
			print_NN(A, p);
			if (B == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B;
			B = NULL;
			break;
		case 10:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			printf("%d\n", DIV_NN_Dk(A, B, n, m, &k));
			printf("k = % d\n", k);
			delete[] B;
			B = NULL;
			break;
		case 11:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			res = DIV_NN_N(A, B, n, m, &p);
			print_NN(res, p);
			if (B == NULL || res == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B; delete[] res;
			B = NULL; res = NULL;
			break;
		case 12:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			A = MOD_NN_N(&A, &B, n, m, &p);
			if (B == NULL || A == NULL) { printf("error in natural");  return -1; }
			print_NN(A, p);
			delete[] B;
			B = NULL;
			break;
		case 13:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			A = GCF_NN_N(&A, &B, &n, &m, &p);
			print_NN(A, p);
			if (B == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B;
			B = NULL;
			break;
		case 14:
			printf("������� m\n");
			if (scanf("%d%c", &m, &c) == EOF) return -1;
			B = read_NN(m);
			res = LCM_NN_N(&A, &B, n, m, &p);
			print_NN(res, p);
			if (B == NULL || res == NULL || A == NULL) { printf("error in natural");  return -1; }
			delete[] B; delete[] res;
			B = NULL; res = NULL;
			break;
		default: printf("incorrect number");
			break;
		}
		delete[] A; A = NULL;
	}
	return 0;
}