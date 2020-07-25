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

void decimal_to_hexadecimal(float num)
{
	struct hex{
		int dec;
		char hex;
	}h[16];
	int rem[64],c=0,i,integer=(int)num;
    float decimal;
    char b[64];
    decimal=num-integer;
    for(i=0;i<16;i++)
    {
    	h[i].dec=i;
    	if(i<10){
    		 h[i].hex=i+48;
    	}
    	else{
    		switch(i){
    	   	  case 10:
    	   	  	   h[i].hex='A';
    	   	  	   break;
    	   	  case 11:
    	   	  	   h[i].hex='B';
    	   	       break;
    	   	  case 12:
    	   	  	   h[i].hex='C';
    	   	       break;
    	   	  case 13:
    	   	  	   h[i].hex='D';
    	   	  	   break;
    	   	  case 14:
    	   	  	   h[i].hex='E';
    	   	       break;
    	   	  case 15:
    	   	  	   h[i].hex='F';
    	   	  	   break;
    	   }
    	}
    }
	while(integer!=0){
		rem[c]=integer%16;
		integer/=16;
	    c++;
	}     //calculating heaxdecimal value for integer part
	c--;  //reduction of count to keep the count of index
   for(i=0;c>=0;c--,i++)
    {  
      b[i]=h[rem[c]].hex;
    }           //storing the hexadecimal value for integer part in a character array
    b[i]='.';  //decimal part starts here,allocation of decimal point with this step
    i++;
    //code for binary value of decimal part
    c=0;
    while(c<10){      
	    decimal=decimal-(int)decimal;       
    	decimal=decimal*16;
    	b[i]=h[(int)decimal].hex;
    	i++;
    	c++;
    }
    b[i]='\0';
    printf("\nHexadecimal Equivalent: ");
   for(i=0;b[i]!='\0';i++)
     {
     	printf("%c",b[i]);
     }
}

void decimal_to_octal(float num)
{
	int rem[64],c=0,i,integer=(int)num;
    float decimal;
    char b[64];
    decimal=num-integer;
	while(integer!=0){
		rem[c]=integer%8;
		integer/=8;
	    c++;
	}     //calculating octal value for integer part
	c--;  //reduction of count to keep the count of index
   for(i=0;c>=0;c--,i++)
    {
    	b[i]=rem[c]+48;
    }           //storing the binary value for integer part in a character array
    b[i]='.';  //decimal part starts here,allocation of decimal point with this step
    i++;
    //code for binary value of decimal part
    c=0;
    while(c<10){      
	    decimal=decimal-(int)decimal;       
    	decimal=decimal*8;
    	b[i]=(int)decimal+48;
    	i++;
    	c++;
    }
    b[i]='\0';
    printf("\nOctal Equivalent: ");
   for(i=0;b[i]!='\0';i++)
     {
     	printf("%c",b[i]);
     }
}


