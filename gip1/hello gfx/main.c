#include <gip_gfx/gip_gfx.h>
#include <stdio.h>
#include <stdbool.h>

// to build:
// gcc -o main main.c -l:libgip_gfx.a -lSDL2

// gcc -o main main.c -l:libgip_gfx.a -L/C:/sdl2/Install/sdl2install2/lib -I/C:/sdl2/install/sdl2install2/include/SDL2

// -I = path to include folder with header files	-I/path/to/include
// -L = path to lib folder library filess		-L/path/to/lib
// -l = add librarys with .a or .so file

// to use:
// main.exe 1980 2000 < global-annual.txt

/*
first_number: 1850
last_number: 2023
avg: -0.072956
max: 0.968013
min: -0.597561
count: 174
*/
int get_color_index(float number)
{
    float borders[] = {
        -7.0 / 8.0 * 0.75,
        -6.0 / 8.0 * 0.75,
        -5.0 / 8.0 * 0.75,
        -4.0 / 8.0 * 0.75,

        -3.0 / 8.0 * 0.75,
        -2.0 / 8.0 * 0.75,
        -1.0 / 8.0 * 0.75,
        0,

        1.0 / 8.0 * 0.75,
        2.0 / 8.0 * 0.75,
        3.0 / 8.0 * 0.75,
        4.0 / 8.0 * 0.75,

        5.0 / 8.0 * 0.75,
        6.0 / 8.0 * 0.75,
        7.0 / 8.0 * 0.75,

    };
    int length = sizeof(borders) / sizeof(borders[0]);
    for (int i = 0; i < length; i++)
    {
        if (number <= borders[i])
        {
            return i;
        }
    }
    return length;
}

// 1971–2000
float get_avg(float numbers[], int start, int end)
{
    int count = end - start;
    float sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += numbers[i];
    }
    return sum / (float)count;
}

int main(int argc, char *argv[])
{
    int first_year = 1971;
    int last_year = 2001;
    int number = 0;
    if (argc > 1 && sscanf(argv[1], "%d", &number))
    {
        first_year = number;
    }
    if (argc > 2 && sscanf(argv[2], "%d", &number))
    {
        last_year = number;
    }

    int count = 0;
    float max = 0.968013;
    float min = -0.597561;
    float range = max - min;
    float numbers[174];
    int index2000 = 0;
    int index1971 = 0;

    while (true)
    {
        int number = 0;
        float floatNumber = 0.0;
        int scan_result = scanf("%d, %f", &number, &floatNumber);
        if (scan_result == EOF)
        {
            break;
        }
        if (scan_result == 2)
        {
            numbers[count] = floatNumber;
            if (number == last_year)
            {
                index2000 = count;
            }
            if (number == first_year)
            {
                index1971 = count;
            }
            count++;
        }
    }

    float avg = get_avg(numbers, index1971, index2000);
    printf("avg: %f\n", avg);

    int colors[] = {
        8, 48, 107,
        8, 81, 156,
        33, 113, 181,
        66, 146, 198,

        107, 174, 214,
        158, 202, 225,
        198, 219, 239,
        222, 235, 247,

        254, 224, 210,
        252, 187, 161,
        252, 146, 114,
        251, 106, 74,

        239, 59, 44,
        203, 24, 29,
        165, 15, 21,
        103, 0, 13};
    int rectangle_width = 500 / (index2000 - index1971);
    int rectangle_height = 215;
    int window_width = rectangle_width * (index2000 - index1971);
    char *window_title = (char*)malloc(30 * sizeof(char));
    sprintf(window_title, "%d - %d", first_year, last_year);
    gip_gfx_create_window(window_title, window_width, rectangle_height);
    gip_gfx_begin_draw();
    for (int i = index1971; i < index2000; i++)
    {
        float floatNumber = numbers[i];
        float normalizedNumber = (floatNumber - min) / range;
        int color = (int)(normalizedNumber * 255.0);
        int color_index = get_color_index(floatNumber - avg) * 3;
        int r = colors[color_index + 0];
        int g = colors[color_index + 1];
        int b = colors[color_index + 2];
        gip_gfx_fill_rect((i - index1971) * rectangle_width, 0, rectangle_width, rectangle_height, r, g, b);
    }
    gip_gfx_end_draw();
    gip_gfx_render_loop();
    return 0;
}