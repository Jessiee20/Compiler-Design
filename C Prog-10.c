#include<stdio.h>
#include<stdlib.h>>
int main(){
	char op,var1,var2,result;
	printf("Enter an Expression in the form'result=var1 op var2':");
	scanf("%c=%c%c%c,&result,&var1,&op,&var2");
	printf("Quadruple intermediatr code:\n");
	printf("(%c,%c,%c,%c)\n",op,var1,var2,result);
	return 0;	
}
