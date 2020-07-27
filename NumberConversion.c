#include<stdio.h>
#include<math.h>
#include<string.h>

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

void decimal_to_binary(float num)
{
    int rem[32],c=0,i,integer=(int)num;
    float decimal;
    char b[64];
    decimal=num-integer;     ///stores decimal part of the entered no
	while(integer!=0){
		rem[c]=integer%2;
		integer/=2;
	    c++;
	}    //calculating binary value for integer part;contains in reverse order as of now
	c--; //reduction of count to keep the count of index
   for(i=0;c>=0;c--,i++)
    {
    	b[i]=rem[c]+48;
    }      //storing the binary value for integer part in a character array
    b[i]='.';  //decimal part starts here,allocation of decimal point with this step
    i++;
    //code for binary value of decimal part
    c=0;
    while(c<10){      
	    decimal=decimal-(int)decimal;       
    	decimal=decimal*2;
    	b[i]=(int)decimal+48;
    	i++;
    	c++;
    }
    b[i]='\0';
    printf("\nBinary Equivalent: ");
   for(i=0;b[i]!='\0';i++)
     {
     	printf("%c",b[i]);
     }
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
	    c++;   //stores the  no of digits
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
	    decimal=decimal-(int)decimal;       //extracting only the fractional part of the result on multiplication by 16
    	decimal=decimal*16;                  
    	b[i]=h[(int)decimal].hex;            //accesing the structure's hexadecimal value from the integer part to store the value in final result
    	i++;                                 //i is the iterator for final result's index
    	c++;                                 //iterator for current loop
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

void binary_to_decimal(char num[])
{
	int i,j,c=0,temp,sum=0;
	double dec=0.0;
	//Validating input
	for(i=0;num[i]!='\0';i++){
		if(num[i]!='0' && num[i]!='1' && num[i]!='.'){
		    printf("\nInvalid input");
		    return;
	     }
	    if(num[i]=='.')
	       c++;
	}
   if(c>1)
     {
     	printf("\nInvalid Input");
     	return;
     }
    
    //storing the position of point
   for(i=0;num[i]!='\0';i++)
     {
     	if(num[i]=='.')
	       break;
     }
    j=i;
    i--;
    c=0;
    while(i>=0){
        if(num[i]=='1'){
          	sum=sum+pow(2.0,c);
         }
        c++;
        i--;
   }
   dec=sum;
   if(j!=strlen(num)){
      j++;
      i=-1;
      while(num[j]!='\0')
       {
       	if(num[j]=='1'){
       		dec=dec+pow(2,i);
       	}
       	i--;
       	j++;
       }
    }
   printf("\nDecimal Equivalent: %f",dec);
}


