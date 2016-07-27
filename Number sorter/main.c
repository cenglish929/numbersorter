/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: chris
 *
 * Created on July 27, 2016, 3:13 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *numbers, how_many;
	int i, aux;
	int swapped;

	printf("How many numbers are you going to sort?");
	scanf("%d", &how_many);
	if( how_many <= 0 || how_many > 1000000) {
		printf("Are you kidding?\n");
		return 1;
	}
	numbers = (int *) malloc(how_many * sizeof(int));
	if(numbers == NULL) {
		printf("Allocation failed, try again.\n");
		return 1;
	}
	for(i = 0; i < how_many; i++) {
		printf("\nEnter the number #%i:\n",i + 1);
		scanf("%d",numbers + i);
	}
	do {
		swapped = 0;
		for(i = 0; i < how_many - 1; i++)
			if(numbers[i] > numbers[i + 1]) {
				swapped = 1;
				aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
			}
	} while(swapped);
	printf("\nThe sorted array:\n");
	for(i = 0; i < how_many; i++)
		printf("%d ",numbers[i]);
	printf("\n");
	free(numbers);
	return 0;
}

