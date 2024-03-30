#include <stdlib.h>
#include <stdio.h>

int esImpar(unsigned int num){ /* Comprobar que un número es par o impar */
	int mask = 1; //00000000 00000000 00000000 00000001
	return num & mask; //0 si es par o 1 si es impar
}

/*Muestra por pantalla la representación de unsigned char en binario*/
void printBits(unsigned char num){
   int numBits = 8* sizeof(unsigned char);
   int i, mascara;
   for(i = numBits-1; i>=0; i--){
	   mascara = 1<<i;
	   printf("%d",(num & mascara) >> i);
   }
   printf("\n");
}


int main(int argc, char **argv){
	setvbuf(stdout, NULL, _IONBF, 0);
	//No existe un tipo byte - debemos usar un tipo base de la longitud en byte que necesitemos	
	//Por ejemplo unsigned char para trabajar con  1 byte
	unsigned char a = 20;	/* 20 = 00010100 */
	unsigned char b = 21;	/* 21 = 00010101 */
	unsigned char c = 0;
	//unsigned int - 4 bytes
	unsigned int n =0;

	c = a & b;       /* 20 = 00010100 */
	printf("AND - a & b: %u\n", c );
	
	c = a | b;       /* 21 = 00010101 */
	printf("\nOR - a | b: %u\n", c );

	c = a ^ b;       /* 1 = 000001 */
	printf("XOR - a ^ b: %u\n", c );

	c = a << 2;	/* 80 = 00101000 */
	printf("Left shift - a << 2: %u\n", c );

	c = a >> 2;	/*05 = 00000101 */
	printf("Right shift - a >> 2: %u\n", c );

	c = ~(a); /* 235 = 11101011*/
	printf("Complemento - ~(a): %u\n", c );

	n = ~(a); /* 4294967275 = 11111111 11111111 11111111 11101011*/
	printf("Complemento - n = ~(a): %u\n", n );

	/*Operaciones con mascaras de bits*/
#define N 6
    /* a = 20 = 00010100 */
	/* poner a 1 el bit 6 y el resto permanece igual => OR
	 * necesito la mascara: 01000000
	 * opcion 1 calcular el valor de la máscara:  a | 64
	 * opcion 2 usar la mascara 1 (00000001) y desplazar el bit 0 a la posicion 6
	 */
	c = a |(1<<6); /* 84 = 01010100 */
	printf("Poner a 1 el bit 6 de 20 (00010100): %u\n", c );


    /* a = 20 = 00010100 */
	/* poner a 0 el bit 4 y el resto permanece igual => AND
	 * Necesito la mascara 11110111
	 * opcion 1: a & 247
	 * opcion 2: usar la mascara 1 (00000001), desplazo el 1 al bit 4 (00001000) y 
	 * hago el complemento (11110111)
	 */
	c = a & (~(1<<4)); /* 4 = 00000100 */
	printf("Poner a 0 el bit 4 de 20 (00010100): %u\n", c );

	/*Obtener el valor del bit 6 de a ==> AND
	 *opcion 1: aplico un AND con la mascara 01000000 ==> 0X000000  
	 *          desplazo a la derecha 6 bits ==> 0000000X
	 *opcion 2: desplazo a la derecha 6 bits de a ==> 000000YX 
	            aplico la mascara 1 para quedarme solo con el bit 0
	 */
	 c = (a & (1<<6)) >>6;
	 printf("Opcion 1: El bit 6 de a esta a %u\n", c);
	 c = (a >>6) & 1;
	 printf("Opcion 2: El bit 6 de a esta a %u\n", c);
	
	
	printf("\nprintBits(a): ");
	printBits(a);
	
	return 0;

}
