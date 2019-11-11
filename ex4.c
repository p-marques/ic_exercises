#include <stdio.h>

int toupper(int);
void menu();
void calculate_mean();
void filter_even_numbers();
void max_string();
void replace_char_and_print(char[], int, char, char);

int main()
{
	char option;
	menu();

	do
	{
		scanf(" %c", &option);

		if (option == 'q')
		{
			puts("Bye");
		}
		else if (option == 's')
		{
			menu();
		}
		else if (option == 'a')
		{
			calculate_mean();
		}
		else if (option == 'b')
		{
			filter_even_numbers();
		}
		else if (option == 'c')
		{
			max_string();
		}
		else if (option == 'd')
		{
			int max_length = 100;
			char string_value[max_length];
			char char1, char2;
			scanf("%s %c %c", string_value, &char1, &char2);

			replace_char_and_print(string_value, max_length, char1, char2);
		}
		else if (option == 'e')
		{
			int max_length = 100;
			char string_value[max_length];
			char char1;
			scanf("%s %c", string_value, &char1);

			replace_char_and_print(string_value, max_length, char1, 0);
		}
		else
		{
			puts("Unknown option");
		}
		
	} while (option != 'q');
	

	return 0;
}

// If char_to_replace_with is 0 -> deletes all occurrences of char_to_replace
void replace_char_and_print(char string_value[], int max_length, char char_to_replace, char char_to_replace_with)
{
	char value[max_length];

	// Will only copy chars that are not char_to_replace
	if (char_to_replace_with == 0)
	{
		int last_value_index = -1;

		for (int i = 0; i < max_length; i++)
		{
			if (string_value[i] != char_to_replace)
			{
				last_value_index++;
				value[last_value_index] = string_value[i];
			}
		}
	}
	else
	{
		for (int i = 0; i < max_length; i++)
		{
			if (string_value[i] == char_to_replace)
			{
				value[i] = char_to_replace_with;
			}
			else
			{
				value[i] = string_value[i];
			}
			
		}
	}

	printf("%s\n", value);
}

void max_string()
{
	int max_length = 100;
	char string_value[max_length];

	scanf("%s", string_value);

	for (int i = 0; i < max_length; i++)
	{
		string_value[i] = toupper(string_value[i]);
	}
	
	printf("%s\n", string_value);
}

void filter_even_numbers()
{
	int n = 10;
	int numbers[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (numbers[i] % 2 == 0)
		{
			printf("%d\n", numbers[i]);
		}
	}
	
}

void calculate_mean()
{
	int mean;
	int sum = 0;
	int n = 10;
	int numbers[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
		sum += numbers[i];
	}

	mean = sum / n;
	
	printf("Mean = %d\n", mean);
}

void menu()
{
	puts("a - reads 10 integers and outputs the mean value of those numbers.");
	puts("b - reads 10 integers and then outputs the even numbers in reverse order");
	puts("c - reads a string and converts all characters to uppercase");
	puts("d - reads a string and two characters (c1 and c2), and replaces all occurences of c1 by c2");
	puts("e - reads a string and a character and deletes all occurences of that character in the string");
	puts("s - print this menu");
	puts("q - end program");
}