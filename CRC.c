#include <stdio.h>							
#include <conio.h>								
#include <string.h>								

//LANIBA, ROTCHE MAE C.
//BSCPE4B

void main() {
	int i, j, keylen, msglen;
	char input[100], key[30], temp[30], quot[100], rem[30], key1[30];
	
	printf("Enter the Number:	");				/* Number of bits in data to be sent from sender side */
	gets(input);
	printf("Enter the Divisor:	");				/* Number of bits in the key obtained from generator polynomial */
	gets(key);
	keylen = strlen(key);						/* getting the length of the key which is the divisor */
	msglen = strlen(input);						/* getting the lenth of the input which is the number */
	strcpy(key1, key);

	/* Append 0's */	
	for (i = 0; i < keylen - 1; i++) {			
		input[msglen + i] = '0';
	}
	
	for (i = 0; i < keylen; i++)
		temp[i] = input[i];						/* the data in input is transferred to temp - which will be used in the next processes */
		
		/* Variable �temp� is used instead of �input� to avoid confusion as the value of input has to be changed in the second for loop */

	/* Use modulo-2 binary division to divide binary data by the key and store remainder of division - a bit at a time */	
	for (i = 0; i < msglen; i++) {
		quot[i] = temp[0];							/* a loop is run until the number of digits of the first number (temp[]) */
		if (quot[i] == '0')							/* and then the first digit of the array temp[] is checked if it is equal to 0 */
			for (j = 0; j < keylen; j++)			
				key[j] = '0'; 						
	
		else										/* but if it is equal to 1 then it enters another loop */
			for (j = 0; j < keylen; j++)			
		 		key[j] = key1[j];					/* which checks or better xor the digits of the two numbers one by one */
		 		
		for (j = keylen - 1; j > 0; j--) {			
			if (temp[j] == key[j])				/* if the digits are equal */
				rem[j-1] = '0'; 				/* then at the place of that digit a 0 gets stored */
				
			else								/* if the digits of the two numbers are not equal */
				rem[j-1] = '1';					/* then at the place of that digit 1 gets stored */
		}
		rem[keylen-1] = input[i+keylen];
		strcpy(temp, rem);
	}
	strcpy(rem, temp);
	
	/* Printing the Quotient of the data divided by the key - number and divisor */
	printf("\nQuotient:	");
	for (i = 0; i < msglen; i++) {
		printf("%c", quot[i]);
	}
	
	/* 
	 * Append remainder in the original data
	 * Printing the remainder of the data divided by the key - number and divisor 
	 */
	 
	printf("\nRemainder:	");
	
	for (i = 0; i < keylen-1; i++) {
		printf("%c", rem[i]);
	}
	
	/* The final remainder is the CRC of the given message. */
	printf("\nFinal data:	");
	for (i = 0; i < msglen; i++) {
		printf("%c", input[i]);
	}
	
	for (i = 0; i < keylen-1; i++) {
		printf("%c", rem[i]);
	}
	getch();
}
