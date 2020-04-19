
struct polinom {
	int k;//старшая степень полинома, иначе говоря, длина массива коэффициэнтов 
	struct rational_number* mas; //массив рациональнах коэффициентов
};
int polinomial();//main in file
polinom read_PP();//serv
int free_P(polinom P);//serv
int print_PP(polinom P);//serv
polinom Pcpy(polinom P);//serv
polinom ADD_PP_P(polinom P1, polinom P2);//1
polinom SUB_PP_P(polinom P1, polinom P2);//2
polinom MUL_PQ_P(polinom P1, rational_number Q);//3
polinom MUL_Pxk_P(polinom P1, int k);//4
rational_number LED_P_Q(polinom P);//5
int DEG_P_N(struct polinom P);//6
polinom FAC_P_Q(polinom P);//7
polinom MUL_PP_P(polinom P1, polinom P2);//8
polinom DIV_PP_P(polinom P1, polinom P2);//9
polinom MOD_PP_P(polinom P1, polinom P2);//10
polinom GCF_PP_P(polinom P1, polinom P2);//11
polinom DER_P_P(polinom P1);//12
polinom NMR_P_P(polinom P1, polinom P2);//13