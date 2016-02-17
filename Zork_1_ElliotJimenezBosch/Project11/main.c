#include <stdio.h>
#include <stdlib.h>
//Elliot Jimenez Bosch

int main(){
	int number = 3;
	char way;
	char quit = 'a';

	printf("Hello my friend\n\n");
	printf("You are in Dinning Room.\n\n");

	while (quit != 'q'){
		printf("Which direction you want to go (n/s/e/w/q)\n");
		fflush(stdin);
		scanf_s("%c", &way);
		switch (way){
		case 'n':
			if (number == 3){
				printf("\nYou are in kitchen\n\n");
				number = 1;
				break;
			}
			if (number == 1){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 2){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 4){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 5){
				printf("\nYou are in Dinning Room.\n\n");
				number = 3;
				break;
			}
		case 's':
			if (number == 3){
				printf("\nYou are in Bethroom.\n\n");
				number = 5;
				break;
			}
			if (number == 1){
				printf("\nYou are in Dinning Room.\n\n");
				number = 3;
				break;
			}
			if (number == 5){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 4){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 2){
				printf("\nThere is a wall there.\n\n");
				break;
			}
		case 'w':
			if (number == 1){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 3){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 5){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 2){
				printf("\nYou are in Kitchen.\n\n");
				number = 1;
				break;
			}
			if (number == 4){
				printf("\nYou are in Dinning Room.\n\n");
				number = 3;
				break;
			}
		case 'e':
			if (number == 5){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 2){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 4){
				printf("\nThere is a wall there.\n\n");
				break;
			}
			if (number == 1){
				printf("\nYou are in Pantry.\n\n");
				number = 2;
				break;
			}
			if (number == 3){
				printf("\nYou are in Bathroom.\n\n");
				number = 4;
				break;
			}
		case 'q':
			printf("Thanks for playing!!\n\n");
			quit = 'q';
			break;

		default:
			printf("\nThis is not a direction...\n\n");
			break;
		}
	}
	system("pause");
	return 0;
}