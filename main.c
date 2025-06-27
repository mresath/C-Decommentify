#include <stdio.h>

#define N 0 // Normal state
#define SL 1 // In a single-line comment
#define ML 2 // In a multi-line comment without a newline yet
#define MLNL 3 //  In a multi-line comment with a newline

int main()
{
    int c;
    int state = N;
    while ((c = getchar()) != EOF)
    {
        switch (state)
        {
        case N:
            if (c == '/')
            {
                c = getchar();
                if (c == '/')
                {
                    state = SL;
                }
                else if (c == '*')
                {
                    state = ML;
                }
                else
                {
                    putchar('/');
                    putchar(c);
                }
            }
            else
            {
                putchar(c);
            }
            break;
        case SL:
            if (c == '\n')
            {
                state = N;
                putchar(c);
            }
            break;
        case ML:
            if (c == '\n')
            {
                state = MLNL;
                putchar(c);
            }
        case MLNL:
            if (c == '*' && (c = getchar()) == '/')
            {
                state = N;
                if ((c = getchar() == ' ')) {
                    putchar('\t');
                }
            }
            break;
        }
    }

    return 0;
}