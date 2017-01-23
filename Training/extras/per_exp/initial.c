#include <stdio.h>

#if 0

int global_u_var;
int global_i_var = 100;

const con_un_var;
const con_in_var = 150;

static sta_un_var;
static sta_in_var = 120;

const static con_sta_un_var;
const static con_sta_in_var = 200;

volatile const vo_con_un;
volatile const vo_con_in = 1555;

const volatile con_vo_un;
const volatile con_vo_in = 2000;

int main()
{
	

int fun_u_var;
int fun_i_var = 100;

const fun_con_un_var;
const fun_con_in_var = 150;

static fun_sta_un_var;
static fun_sta_in_var = 120;

const static fun_con_sta_un_var;
const static fun_con_sta_in_var = 200;

return 0;
}

#endif

#if 
size_t temp1;
int main()
{
	size_t temp = 40;
	printf("hello world\n");
	return 0;
}
#endif
