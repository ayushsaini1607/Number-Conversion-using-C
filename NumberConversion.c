#include<stdio.h>
#include<math.h>
#include<strig.h>

void decimal_to_binary(float);
void decimal_to_octal(float);
void decimal_to_hexadecimal(float);

void binary_to_decimal(char []);
void binary_to_octal(char []);
void binary_to_hexadecimal(char []);

int main()
{
	int ch;
	printf("\nNumber conversion\n");
	printf("\nEnter input type from options below: ");
	printf("\n1.Decimal");
	printf("\n2.Binary");
	printf("\n3.Octal");
	printf("\n4.Hexadecimal");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			float no;
         	printf("\n Enter a number: ");
	        scanf("%f",&no);
	        decimal_to_binary(no);
	        decimal_to_octal(no);
	        decimal_to_hexadecimal(no);
	        break;
	    case 2:
	    	char no[64];
	        printf("\nEnter number in binary format(0s and 1s only): ");
	        gets(no);
            binary_to_decimal(no);
            binary_to_octal(no);
            binary_to_hexadecimal(no);
            break;
	}
   return 0;
}


