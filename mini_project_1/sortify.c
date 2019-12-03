#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MSG_WELCOME "WELCOME TO SORTIFY!"
#define MSG_SORT "Sort the following numbers:"
#define MSG_SORT2 "Please sort the numbers"
#define MSG_WELL "Well done!"
#define MSG_WIN "Congratulations, you win!"
#define MSG_OVER "Game Over."
#define MSG_WRONG "Wrong answer."
#define MSG_MAX "You have reached the maximum number of moves."
#define MSG_BYE "Bye."
#define MSG_UNKNOWN "Unknown option."
#define MAX_ROUNDS 30
/* Use puts() to print constant strings */

void play(unsigned int * level, unsigned int * current_round, unsigned int * current_points);
int rand_number(const int, const int);
void print_status(const int, const int, const int);
void print_menu(void);


int main(int argc, char **argv)
{
	char user_input;
	unsigned int level = 0, current_round = 0, current_points = 0;

	puts(MSG_WELCOME);

	if(argc == 1)
	{
		srand(time(NULL));
	}
	else
	{
		srand(*argv[1] - '0');
	}

	print_menu();
	while (user_input != 'q')
	{
		scanf(" %c", &user_input);
		
		if (user_input == 'q')
		{
			puts(MSG_BYE);
		}
		else if (user_input == 'm')
		{
			print_menu();
		}
		else if (user_input == 's')
		{
			print_status(level, current_points, current_round);
		}
		else if (user_input == 'p')
		{
			play(&level, &current_round, &current_points);
		}
		else
		{
			puts(MSG_UNKNOWN);
		}
	}
	
	return 0;
}

bool is_number_in_array(int * numbers, int n)
{
	unsigned int n = 4, i = 0;

	for(i; i < 4; i++)
	{
		if(*(numbers + i) == n)
		{
			return true;
		}
	}

	return false;
}

void order_numbers(int * numbers)
{
	const unsigned int n = 4;
	unsigned int i, j;
	int t;
	
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(numbers + j) < *(numbers + i))
			{
				t = *(numbers + i);
				*(numbers + i) = *(numbers + j);
				*(numbers + j) = t;
			}
			
		}
	}
}

void play(unsigned int * level, unsigned int * current_round, unsigned int * current_points)
{
	unsigned int level_treshold[5] = {10, 20, 30, 40, 50};
	int min_value[5] = {0, 0, -50, -100, -200}, max_value[5] = {10, 30, 30, 0, -100}, current_generated_numbers[4], current_player_numbers[4];
	bool input_error = false, player_success = true, player_wins = false;
	time_t start_time, time_lapsed;

	*current_round = *current_round + 1;

	puts(MSG_SORT);
	for (unsigned int i = 0; i < 4; i++)
	{
		current_generated_numbers[i] = rand_number(min_value[*level], max_value[*level]);
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		printf("%d", current_generated_numbers[i]);
		if (i < 3)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}
	}

	order_numbers(current_generated_numbers);
	start_time = time(NULL);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &current_player_numbers[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		if(!is_number_in_array(current_generated_numbers, current_player_numbers[i]))
		{
			input_error = true;
			break;
		}

		if (current_player_numbers[i] != current_generated_numbers[i])
		{
			player_success = false;
		}
	}
	
	time_elapsed = time(NULL) - start_time;

	if (player_success)
	{
		puts(MSG_WELL);

		*current_points = *current_points + 5;
		if (*current_points == level_treshold[*level])
		{
			if (*level == 4)
			{
				player_wins = true;
			}
			else
			{
				*level = *level + 1;
			}
		}
	}
	else
	{
		puts(MSG_WRONG);
	}

	if (*current_round == MAX_ROUNDS && !player_wins)
	{
		puts(MSG_MAX);
		print_status(*level, *current_points, *current_round);
		puts(MSG_OVER);
	}
}

/* generate a random integer between min and max */
int rand_number(const int min, const int max)
{
	if (max < min)
	{
		puts("Max must be larger than Min");
		exit(0);
	}
	int n = abs(max - min) + 1;
	return (rand() % n) + min;
}

/* print the game status */
void print_status(const int level, const int score, const int plays)
{
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level + 1);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}

/* print the option menu */
void print_menu(void)
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next chalenge           |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}