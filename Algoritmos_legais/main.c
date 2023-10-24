#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// =-=-=-=-=-=-=-=-=-=-=-=-= Ordenacao =-=-=-=-=-=-=-=-=-=-=-=-=

void bubbleSort(int num[], int n) {
	int temp, c, i;
	
	for(c = 0; c < n - 1; c++) {
		for(i = 0; i < n - 1 - c; i++) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}	
	}
}

void bubbleSort2(int num[], int n) {
	int temp, c, i;
	
	for(c = 0; c < n - 1; c++) {
		for(i = (c + 1); i < n; i++) {
			if (num[c] > num[i]) {
				temp = num[c];
				num[c] = num[i];
				num[i] = temp;
			}
		}	
	}
	
}

void selectionSort(int num[], int newnum[], int n) {
	// Analisar todos os itens da lista e pegar o menor. Depois colocar o menor em uma nova lista e retirar o menor da lista original.
	int i, j, indice_menor;
	int n2 = n;
	for(j = 0; j < n; j++) {
		int menor = num[0];
		for(i = 0; i < n2; i++) {
			if (num[i] <= menor) {
				menor = num[i];
				indice_menor = i;
			}
		}
		newnum[j] = menor;

		// Remover elemento da lista
		for (i = indice_menor; i < n2 - 1; i++) {
            num[i] = num[i + 1];
        }
        n2--;
	}
}

void quickSort(int array[], int n) {
	if (n <= 1) {
		return;
	}
	
	int c, a = 0, b = 0, pivo = array[0];
	int menor[n];
	int maior[n];
	
	
	for(c = 1; c < n; c++) {
		if (array[c] <= pivo ) {
			menor[a] = array[c];
			a++;
		} else if (array[c] > pivo) {
			maior[b] = array[c];
			b++;
		}
	}
	
	quickSort(menor, a);
	quickSort(maior, b);
	
    for (c = 0; c < a; c++) {
        array[c] = menor[c];
    }
    array[a] = pivo;

    for (c = 0; c < b; c++) {
        array[a + 1 + c] = maior[c];
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-= Pesquisa =-=-=-=-=-=-=-=-=-=-=-=-=
int binarySearch(int num[], int len, int bs) {
	//Variaveis
	int left, right, mid;
	left = 0;
	right = len - 1;
	
	// 28 38 39 383
	//  0  1  2  3 
	// right = 3; left = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		if (bs == num[mid]) {
			return 1;
		} else if (bs < num[mid]) {
			// bs esta na metade esquerda	
			right = mid - 1;
		} else if (bs > num[mid]) {
			// bs esta na metade direita
			left = mid + 1;
		}
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int c = 0;
	int num[4] = {-1};
	int bs = 0;
	int num2[4] = {-1};
	
	printf("Digite quatro valores inteiros:\n");
	scanf("%i", &num[0]);
	scanf("%i", &num[1]);
	scanf("%i", &num[2]);
	scanf("%i", &num[3]);
	
	printf("\n");
	
//	// Bubble sort
//	printf("**BUBBLE SORT**\n");
//	bubbleSort(num, 4);
//	
//	for (c = 0; c < (sizeof(num) / sizeof(num[0])); c++) {
//		printf("%i ", num[c]);
//	}
//	
//	printf("\n");
	
//	// Selection sort
//	printf("\n**SELECTION SORT**\n");
//	selectionSort(num, num2, 4);
//	
//	for (c = 0; c < (sizeof(num2) / sizeof(num2[0])); c++) {
//		printf("%i ", num2[c]);
//	}
//	// Se for usar o selection sort, substituir o "num" por "num2" nos codigos subsequentes.
//
//	printf("\n");

	printf("**QUICK SORT**\n");
	quickSort(num, 4);
	
	for (c = 0; c < (sizeof(num) / sizeof(num[0])); c++) {
		printf("%i ", num[c]);
	}
	
	printf("\n\n");
	
	// Binary Search
	printf("**BINARY SEARCH**\n");
	printf("Digite o valor a ser pesquisado na lista de numeros anterior:\n");
	scanf("%i", &bs);
	
	if (binarySearch(num, 4, bs)) {
		printf("O numero %i existe na lista !", bs);
	} else {
		printf("O numero %i nao existe na lista !", bs);
	}
	
	
	return 0;
}
