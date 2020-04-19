struct integer_number {
	int length;//длинна целого числа
	int sign;//знак числа
	uint8_t* numb;//массив цифр числа
};
int integer();//main in file
integer_number read_Z(int n);//serv
int print_Z(integer_number A);//serv
integer_number ABS_Z_N(integer_number A);//1
int POZ_Z_D(integer_number A);//2
integer_number MUL_ZM_Z(integer_number A);//3
integer_number TRANS_N_Z(uint8_t* AA, int n);//4
uint8_t* TRANZ_Z_N(integer_number A, int* n);//5
integer_number ADD_ZZ_Z(integer_number A, integer_number B);//6
integer_number SUB_ZZ_Z(integer_number A, integer_number B);//7
integer_number MUL_ZZ_Z(integer_number A, integer_number B);//8
integer_number DIV_ZZ_Z(integer_number A, uint8_t* B, int m);//9
integer_number MOD_ZZ_Z(integer_number A, uint8_t* B, int m);//10
