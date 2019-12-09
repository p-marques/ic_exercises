#include <stdio.h>

int is_upper(char);
int get_string_length(char *);
void reverse_string(char *);

int main(int argc, char **argv)
{
    char command, etx[100];

    if (argc < 3)
    {
        puts("Not enough arguments.");
        return 0;
    }

    command = argv[1][0];

    if (command != 'i' && command != 'd')
    {
        puts("Unknown option");
        return 0;
    }
    else if (command == 'd')
    {
        for (short i = 0, k = 0; i < get_string_length(argv[2]); i++)
        {
			if (!is_upper(argv[2][i]))
            {
                etx[k] = argv[2][i];
                k++;
            }
        }
        
        printf("%s\n", etx);
    }
    else if (command == 'i')
    {
        if (argc == 4)
        {
            for (short i = 0; i < get_string_length(argv[3]); i++)
            {
                etx[i] = argv[3][i];
            }
        }
        else
        {
            for (short i = 0; i < get_string_length(argv[2]); i++)
            {
                etx[i] = argv[2][i];
            }
        }
        
        reverse_string(etx);
        printf("%s\n", etx);
    }
}

int is_upper(char in_char)
{
    if (in_char >= 'A' && in_char <= 'Z')
      return 1;
   else
      return 0;
}

int get_string_length(char * etx)
{
    short count = 0;

    while (*(etx + count) != '\0')
        count++;
    
    return ++count;
}

void reverse_string(char * txt)
{
    int size = get_string_length(txt) - 1, end = size - 1, begin = 0;
    char temp[size];

    for (begin = 0; begin < size; begin++)
    {
        temp[begin] = *(txt + end);
        end--;
    }

    temp[begin] = '\0';
	
    for (begin = 0; begin < size; begin++)
    {
        *(txt + begin) = temp[begin];
    }
        
}