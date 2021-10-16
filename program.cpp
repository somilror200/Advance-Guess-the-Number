#include "splashkit.h"

string read_string(string prompt) // for letting user input a stringh
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_int(string prompt) // for reading integer from the user
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

int main()
{
    write_line("Guess any number from 1-100\nPress Y for the right answer, S if your number is shorter, L if your number is larger");
    int half = 50, max_value = 100, min_value = 0;
    while(max_value - min_value != 1)
    {
        write("Is it ");
        write(half);
        string ans = read_string("? Input Y/S/L: ");
        if(ans == "S" or ans == "s")
        {
            max_value = half;
            half = min_value + max_value;
            half = half / 2;
        }
        else if (ans == "L" or ans == "l")
        {
            min_value = half;
            half = min_value + max_value;
            half = half / 2;
        }
        else if (ans == "Y" or ans == "y")
        {
            write_line("I guessed it right :-)");
            break;
        }
    }
    return 0;
}