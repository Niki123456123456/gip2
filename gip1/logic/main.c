#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_TEXT_LENGTH 10

// to use:
// main.exe < input.txt

int getNumber(char c)
{
    uint16_t i = c - '0';
    return i;
}

int main()
{
    // read rights
    int count = 0;
    uint16_t rights[MAX_LENGTH][3];
    char fileNames[MAX_LENGTH][MAX_TEXT_LENGTH];
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        char test[3];
        scanf("%s %s", &test, &fileNames[i]);
        for (unsigned int x = 0; x < 3; x++)
        {
            rights[i][x] = getNumber(test[x]);
        }
    }

    int countChanges = 0;
    scanf("%d", &countChanges);
    for (int i = 0; i < countChanges; i++)
    {
        char test[3];
        char fileName[MAX_TEXT_LENGTH];
        scanf("%s", &fileName);
        scanf("%s", &test);
        scanf("%s", &fileName);
        for (int x = 0; x < count; x++)
        {
            if (strcmp(fileName, fileNames[x]) == 0)
            {
                // ugo
                int t = 0;
                char test0 = test[0];
                if (test0 == 'g'){
                    t = 1;
                } else if (test0 == 'o'){
                    t = 2;
                }
                // rwx
                unsigned int n = 0;
                if (test[2] == 'w'){
                    n = 1;
                } else if (test[2] == 'r'){
                    n = 2;
                }

                if (test[1] == '+'){
                    rights[x][t] = rights[x][t] | (1 << n);
                } else {
                    rights[x][t] = rights[x][t] & ~(1 << n);
                }
            }
        }
    }

    // print rights
    char rightNames[] = {'r', 'w', 'x'};
    for (int i = 0; i < count; i++)
    {
        for (unsigned int x = 0; x < 3; x++)
        {
            for (unsigned int n = 0; n < 3; n++)
            {
                char c = '-';
                if (rights[i][x] & (1 << (2 - n)))
                {
                    c = rightNames[n];
                }
                printf("%c", c);
            }
        }
        printf(" %s\n", fileNames[i]);
    }
    return 0;
}