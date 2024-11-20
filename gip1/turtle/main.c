#include <gip_gfx/gip_gfx.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 500
#define BUFFER_SIZE 100

/*
GAGA
HHAG

G/H = sin
A/H = cos
G/A = tan
A/G = cot

U = PI * D
U = count * length
D = length * csc(PI/count)

circle:
T -90.0
F 0.28647889756
D
T 90.0
R 3600
F 0.0005
T 0.1

sechseck:
F 0.34641016151
T -90.0
F 0.2
D
T 90.0
T 30.0
R 6
T 60.0
F 0.4

*/

float p_x = 0;
float p_y = 0;
float rotation = 0;
bool is_down = false;

float s_p_x = 0;
float s_p_y = 0;
float s_rotation = 0;
bool s_is_down = false;

void up(void)
{
    is_down = false;
}
void down(void)
{
    is_down = true;
}

void draw_line(float start_x, float start_y, float end_x, float end_y)
{
    gip_gfx_draw_line((int)((start_x + 0.5) * ((float)SIZE)), (int)((start_y + 0.5) * ((float)SIZE)), (int)((end_x + 0.5) * ((float)SIZE)), (int)((end_y + 0.5) * ((float)SIZE)));
}
void forward(float distance)
{
    float radians = rotation * (M_PI / 180.0);
    float x_new = p_x + distance * cos(radians);
    float y_new = p_y + distance * sin(radians);

    if (is_down)
    {
        draw_line(p_x, p_y, x_new, y_new);
    }

    p_x = x_new;
    p_y = y_new;
}
void turn(float angle)
{
    rotation = rotation - angle;
}

int main(char argc, char *argv[])
{
    gip_gfx_create_window("turtle", SIZE, SIZE);
    gip_gfx_begin_draw();

    FILE *file = fopen(argv[1], "r");
    char buffer[BUFFER_SIZE];
    int n = 1;
    long repeat_position = 0;
    while (n > 0)
    {
        n--;
        fseek(file, repeat_position, SEEK_SET);
        while (fgets(buffer, BUFFER_SIZE, file) != NULL)
        {
            char c;
            float f;
            sscanf(buffer, "%c %f", &c, &f);
            switch (c)
            {
            case 'D':
                down();
                break;
            case 'U':
                up();
                break;
            case 'F':
                forward(f);
                break;
            case 'T':
                turn(f);
                break;
            case '{': // save
                s_p_x = p_x;
                s_p_y = p_y;
                s_is_down = is_down;
                s_rotation = rotation;
                break;
            case '}': // restore
                p_x = s_p_x;
                p_y = s_p_y;
                is_down = s_is_down;
                rotation = s_rotation;
                break;
            case 'R':
                if (n == 0)
                {
                    n = ((int)f) - 1;
                }
                repeat_position = ftell(file);
                break;
            default:
            }
        }
    }
    fclose(file);
    gip_gfx_end_draw();
    gip_gfx_render_loop();
    return 0;
}
