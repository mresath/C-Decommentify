#include <stdio.h>

enum State {
    N, // Normal state
    SL,  // Single-line comment
    ML,  // Multi-line comment
    MLNL  // Multi-line comment with newline in it
};

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