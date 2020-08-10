#include<stdio.h>
#include<math.h>
#include<string.h>

char* decimal_to_binary(float);
char* decimal_to_octal(float);
char* decimal_to_hexadecimal(float);

double binary_to_decimal(char []);
double hexadecimal_to_decimal(char []);
double octal_to_decimal(char []);

int main()
{
	int ch,opt;   //switch case and do while variables
  float no;
	char num[32];   //input
  char *res;   //computed output
  double result;   //computed output
  do{
	  printf("\nNumber conversion\n");
	  printf("\nEnter input type from options below: ");
	  printf("\n1.Decimal to binary,octal and hexadecimal");
	  printf("\n2.Binary to decimal,octal and hexadecimal");
	  printf("\n3.Octal to decimal,binary and hexadecimal");
	  printf("\n4.Hexadecimal to decimal,binary and octal\n");
	  scanf("%d",&ch);
	  switch(ch){
		  case 1:
         	printf("\n Enter a number: ");
	        scanf("%f",&no);
	        res=decimal_to_binary(no);
          printf("\nBinary equivalent : %s",res);
          strcpy(res,"");
	        res=decimal_to_octal(no);
          printf("\nOctal equivalent : %s",res);
          strcpy(res,"");
	        res=decimal_to_hexadecimal(no);
          printf("\nHexadecimal equivalent : %s",res);
          strcpy(res,"");
	        break;
	    
      case 2:
	        printf("\nEnter number in binary format(0s and 1s only): ");
			    fflush(stdin);
	        gets(num);
          result=binary_to_decimal(num);
          printf("\nDecimal Equivalent : %f",result);
          res=decimal_to_octal(result);
          printf("\nOctal Equivalent : %s",res);
          strcpy(res,"");
          res=decimal_to_hexadecimal(result);
          printf("\nHexadecimal Equivalent : %s",res);
          strcpy(res,"");
          break;
	    
      case 3: 
		        printf("\nEnter no in octal format(digits from 0 to 7 only) : ");
            fflush(stdin);
            gets(num);
            result=octal_to_decimal(num);
            printf("\nDecimal Equivalent: %f",result);
            res=decimal_to_binary(result);
            printf("\nBinary Equivalent : %s",res);
            strcpy(res,"");
            res=decimal_to_hexadecimal(result);
            printf("\nHexadecimal Equivalent : %s",res);
            strcpy(res,"");
			      break;
        
        case 4:
             printf("\nEnter no in hexadecimal format(digits from 0 to 9 and letters A to F only) : ");
             fflush(stdin);
             gets(num);
             result=hexadecimal_to_decimal(num);
             printf("\nDecimal Equivalent : %f",result);
             res=decimal_to_binary(result);
             printf("\nBinary Equivalent : %s",res);
             strcpy(res,"");
             res=decimal_to_octal(result);
             printf("\nOctal Eqivalent : %s",res);
             strcpy(res,"");
             break;
        default: 
		       printf("\n Invalid choice!");
	 }
  printf("\n\nEnter 1 to continue:");
  scanf("%d",&opt);
 }while(opt==1);
   return 0;
}

char* decimal_to_binary(float num)
{
    int rem[32],c=0,i,integer=(int)num;
    float fraction;
    char b[64];
    fraction=num-integer;     ///stores decimal part of the entered no
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
	    fraction=fraction-(int)fraction;       
    	fraction=fraction*2;
    	b[i]=(int)fraction+48;
    	i++;
    	c++;
    } 
    b[i]='\0';
   /*for(i=0;b[i]!='\0';i++)
     {
     	printf("%c",b[i]);
     } */
    return b;
}

char* decimal_to_hexadecimal(float num)
{
	struct hex{
		int dec;
		char hex;
	}h[16];
	int rem[64],c=0,i,integer=(int)num;
    float fraction;
    char b[64];
    fraction=num-integer;
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
	    fraction=fraction-(int)fraction;       //extracting only the fractional part of the result on multiplication by 16
    	fraction=fraction*16;                  
    	b[i]=h[(int)fraction].hex;            //accesing the structure's hexadecimal value from the integer part to store the value in final result
    	i++;                                 //i is the iterator for final result's index
    	c++;                                 //iterator for current loop
    }
    b[i]='\0';
   /* printf("\nHexadecimal Equivalent: ");
   for(i=0;b[i]!='\0';i++)
     {
     	printf("%c",b[i]);
     } */
    return b;
}

char* decimal_to_octal(float num)
{
	int rem[64],c=0,i,integer=(int)num;
    float fraction;
    char b[64];
    fraction=num-integer;
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
	    fraction=fraction-(int)fraction;       
    	fraction=fraction*8;
    	b[i]=(int)fraction+48;
    	i++;
    	c++;
    }
    b[i]='\0';
  /*  printf("\nOctal Equivalent: ");
   for(i=0;b[i]!='\0';i++)
     {
     	printf("%c",b[i]);
     } */
    return b;
}

double octal_to_decimal(char num[])
{
    int i,j,dot_count=0,c,sum=0;
    double res=0.0,temp;  //to store the fractional part of the result and then adding integer part to it to produce final result

    /*validating input withj ascii value check from 0 to 7 and checking number of decimal points*/
    for(i=0;num[i]!='\0';i++)
      {
          if((int)num[i]<48 || (int)num[i]>55)
		     if(num[i]!='.')   
             {
                 printf("\nInvalid Input");
                 return 0;      
             }
          if(num[i]=='.')            
               dot_count++;     //to store no of decimal points(in case user has entered more than one)
      }
    if(dot_count>1)
    {
       printf("\nInvalid Input");
       return 0;
    }
    for(i=0;num[i]!='\0';i++)
      if(num[i]=='.')
         break;
 //i now has the position of decimal point in the user entered value
    j=i;                          //copying the value of i to j for later use
    i--;
    c=0;                 //keeps the count of power of 8
    /*storing the decimal equivalent of part before decimal point in variable sum*/
    while(i>=0)
     {
     	 temp=num[i]-'0';    //temp extracting integer value from string
     	 temp= temp*pow(8,c);       //temp multiplied with required power of 8
         sum = sum + temp;
         c++;
         i--;
     }
      res=sum;    //store floating type value of sum in res
     /*if the value of j is equal to the length of the string entered by the user then there is no decimal point
       else the value of j is the position of the decimal point in the string.*/
     if(j!=strlen(num))
      {
          j++;      //inccrementing j so that it now holds the index of the number right after decimal point
          c=-1;      //negative powers after decimal point

          /*the decimal equivalent of the fractional part of the entered no is stored in a variable res of double type*/
          while(num[j]!='\0')
            {
                temp=num[j]-'0';
                temp=temp*pow(8.0,c);
                res=res+temp;
                c--;    //negative power value decreasing
                j++;    //loop counter increasing upto the end of the string
            }
      }
      //printf("\nDecimal Equivalent: %f",res);
      return res;
}

double hexadecimal_to_decimal(char num[])
{
    char ch;
    int i,j,dot_count=0,c,sum=0,z;
    double res=0.0,temp;  //to store the fractional part of the result and then adding integer part to it to produce final result
    for(i=0;num[i]!='\0';i++)
      {
         if((int)num[i]<48 || (int)num[i]>57)
             if(num[i]<'A' || num[i]>'F')
		        if(num[i]!='.')   
                  {
                 printf("\nInvalid Input");
                 return 0;      
                  }
          if(num[i]=='.')            
               dot_count++;     //to store no of decimal points(in case user has entered more than one)
      }
    if(dot_count>1)
     {
       printf("\nInvalid Input");
       return 0;
     }
    for(i=0;num[i]!='\0';i++)
      if(num[i]=='.')
         break;
    //i now has the position of decimal point in the user entered value
    j=i;                          //copying the value of i to j for later use
    i--;
    c=0;                 //keeps the count of power of 16
    while(i>=0)
    {
       if(num[i]>=48 && num[i]<=57)            //for numbers 0 to 9
             z=num[i]-'0';
       else if(num[i]>='A' && num[i]<='F')       //for numbers 10 to 15
           switch(num[i])
            {
                  case 'A':
                          z=10;
                          break;
                  case 'B':
                           z=11;
                           break;
                  case 'C': 
                           z=12;
                           break;
                  case 'D':
                           z=13;
                           break;
                  case 'E':
                           z=14;
                           break;
                  case 'F':
                            z=15;
                            break;
            }
         z=z*pow(16,c);
         sum=sum+z;
         c++;
         i--;
      }
     res=sum;
     if(j!=strlen(num))
      {
          j++;      //incrementing j so that it now holds the index of the number right after decimal point
          c=-1;      //negative powers after decimal point

          /*the decimal equivalent of the fractional part of the entered no is stored in a variable res of double type*/
          while(num[j]!='\0')
            {
                if(num[j]>=48 && num[j]<=57)             //for numbers from 0 to 9
                   temp=num[i]-'0';
               else if(num[j]>='A' && num[j]<='F')          //for numbers from 10 to 15
           switch(num[j])
            {
                  case 'A':
                          temp=10;
                          break;
                  case 'B':
                           temp=11;
                           break;
                  case 'C': 
                           temp=12;
                           break;
                  case 'D':
                           temp=13;
                           break;
                  case 'E':
                           temp=14;
                           break;
                  case 'F':
                            temp=15;
                            break;
            }
                temp=temp*pow(16.0,c);
                res=res+temp;
                c--;    //negative power value decreasing
                j++;    //loop counter increasing upto the end of the string
            }
      }
      //printf("\nDecimal Equivalent: %f",res);
      return res;
}

double binary_to_decimal(char num[])
{
	int i,j,c=0,sum=0;
	double res=0.0;
	//Validating input
	for(i=0;num[i]!='\0';i++){
		if(num[i]!='0' && num[i]!='1' && num[i]!='.'){
		    printf("\nInvalid input");
		    return 0;
	     }
	    if(num[i]=='.')
	       c++;
	}
   if(c>1)
     {
     	printf("\nInvalid Input");
     	return 0;
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
   res=sum;
   if(j!=strlen(num)){
      j++;
      i=-1;
      while(num[j]!='\0')
       {
       	if(num[j]=='1'){
       		res=res+pow(2,i);
       	}
       	i--;
       	j++;
       }
    }
   //printf("\nDecimal Equivalent: %f",res);
   return res;
}


