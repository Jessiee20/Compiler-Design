#include <stdio.h>

main() {
   int a = 10;
   int b = 30;
   int c = 15;
   int d = 5;
   int e;
   e = (a + b) * c / d;      
   printf("Value of (a + b) * c / d is : %d\n",  e );

   e = ((a + b) * c) / d;    
   printf("Value of ((a + b) * c) / d is  : %d\n" ,  e );

   e = (a + b) * (c / d);  
   printf("Value of (a + b) * (c / d) is  : %d\n",  e );

   e = a + (b * c) / d;    
   printf("Value of a + (b * c) / d is  : %d\n" ,  e );
  
   return 0;
}
