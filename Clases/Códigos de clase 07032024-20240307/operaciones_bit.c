#include <stdlib.h>
#include <stdio.h>

int esImpar(unsigned int num){
	int mask = 1; //00000000 00000000 00000000 00000001
	return num & mask; //0 si es par o 1 si es impar
}

/* Muestra por pantalla la representación de unsigned char en binario */
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
	//unsigned char - 1byte
	unsigned char a = 20;	/* 20 = 00010100 */
	unsigned char b = 21;	/* 21 = 00010101 */
	unsigned char c = 0;

	if(esImpar(10)){
		printf("El 10 es impar\n");
	}else if(esImpar(11)){
		printf("El 11 es impar\n");
	}else{
		printf("Ni el 10 ni el 11 son impares\n");
	}

	c = a & b;       /* 20 = 00010100 */
	printf("\nAND - a & b: %u", c );
	
	c = a | b;       /* 21 = 00010101 */
	printf("\nOR - a | b: %u\n", c );

	/*XOR devuelve 0 en los bits que son iguales y 1 en los que son diferentes*/
	c = a ^ b;       /* 1 = 000001 */
	printf("XOR - a ^ b: %u\n", c );

	/* Desplazar un bit a la izquierda equivale a multiplicar por 2*/
	c = a << 2;	/* 80 = 00101000 */
	printf("Left shift - a << 2: %u\n", c );

	/* Desplazar un bit a la derecha equivale a dividir entre 2*/
	c = a >> 2;	/*05 = 00000101 */
	printf("Right shift - a >> 2: %u\n", c );

	c = ~(a); /* 235 = 11101011*/
	printf("Complemento - ~(a): %u\n", c );


	/* Operaciones con mascaras de bits.
	 * Suponemos que el bit menos significativo está en la posición 0
	 * y el más significativo en la 7 */
	/* El OR permite poner a 1 los bits que en la máscara están a 1 */
	/* El AND permite poner a 0 los bits que en la máscara están a 0*/

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
	 * Necesito la máscara 11101111
	 * opcion 1: a & 239
	 * opcion 2: usar la máscara 1 (00000001), desplazo el 1 al bit 4 (00010000) y
	 * hago el complemento (11101111)
	 */
	c = a & (~(1<<4)); /* 4 = 00000100 */
	printf("Poner a 0 el bit 4 de 20 (00010100): %u\n", c );

	/*Obtener el valor del bit 6 de a ==> AND
	 *opcion 1: aplico un AND con la máscara 01000000 ==> 0X000000
	 *          desplazo a la derecha 6 bits ==> 0000000X
	 *opcion 2: desplazo a la derecha 6 bits de a ==> 0000000X
	            aplico la máscara 1 para quedarme solo con el bit 0
	 */
	 c = (a & (1<<6)) >>6;
	 printf("Opcion 1: El bit 6 de a esta a %u\n", c);
	 c = (a >>6) & 1;
	 printf("Opcion 2: El bit 6 de a esta a %u\n", c);
	
	
	printf("\nprintBits(a): ");
	printBits(a);
	
	return 0;

}
