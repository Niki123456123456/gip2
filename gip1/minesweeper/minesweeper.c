#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <gip_gfx/gip_gfx.h>

// to build:
// gcc -o main minesweeper.c -l:libgip_gfx.a -lSDL2

#define NUM_ROWS 20
#define NUM_COLS 20
#define NUM_MINES 10

#define TILE_HEIGHT 48
#define TILE_WIDTH 48
#define NUM_TILE_ROWS 3
#define NUM_TILE_COLS 4

gip_gfx_image_t *tiles = NULL;

typedef struct
{
  bool has_mine;
  bool has_flag;
  bool is_open;
  int number;
} Cell;

Cell state[NUM_ROWS][NUM_COLS];

int GetSum(int xCenter, int yCenter, int range)
{
  int sum = 0;
  for (int x = xCenter - range; x <= xCenter + range; x++)
  {
    for (int y = yCenter - range; y <= yCenter + range; y++)
    {
      if (x >= 0 && x < NUM_COLS && y >= 0 && y < NUM_ROWS && state[x][y].has_mine)
      {
        sum++;
      }
    }
  }
  return sum;
}

int GetTextNumber(int x, int y)
{
  if (state[x][y].is_open)
  {
    if (state[x][y].has_mine)
    {
      return 9;
    }
    return state[x][y].number;
  }
  if (state[x][y].has_flag)
  {
    return 11;
  }
  return 10;
}

void update_window_image()
{
  gip_gfx_image_t *board_image = gip_gfx_access_window_image();

  for (int x = 0; x < NUM_COLS; x++)
  {
    for (int y = 0; y < NUM_ROWS; y++)
    {
      int texNumber = GetTextNumber(x, y);
      gip_gfx_rect_t tile_rect = {.x = (texNumber % NUM_TILE_COLS) * TILE_WIDTH,
                                  .y = (texNumber / NUM_TILE_COLS) * TILE_HEIGHT,
                                  .width = TILE_WIDTH,
                                  .height = TILE_HEIGHT};
      gip_gfx_pos2d_t board_pos = {.x = x * TILE_WIDTH, .y = y * TILE_HEIGHT};
      gip_gfx_copy_rect(tiles, tile_rect, board_image, board_pos);
    }
  }

  gip_gfx_update_window_image();
}

void open_numbers(int xCenter, int yCenter)
{
  int range = 1;
  if (xCenter >= 0 && xCenter < NUM_COLS && yCenter >= 0 && yCenter < NUM_ROWS && state[xCenter][yCenter].has_mine == false && state[xCenter][yCenter].is_open == false)
  {
    for (int x = xCenter - range; x <= xCenter + range; x++)
    {
      for (int y = yCenter - range; y <= yCenter + range; y++)
      {
        if (x >= 0 && x < NUM_COLS && y >= 0 && y < NUM_ROWS && state[x][y].is_open == true && state[x][y].number == 0)
        {
          state[xCenter][yCenter].is_open = true;
          break;
        }
      }
    }
  }
}

void clear_view(int x, int y)
{
  if (x >= 0 && x < NUM_COLS && y >= 0 && y < NUM_ROWS && state[x][y].is_open == false && state[x][y].number == 0)
  {
    state[x][y].is_open = true;
    clear_view(x - 1, y);
    clear_view(x + 1, y);
    clear_view(x, y - 1);
    clear_view(x, y + 1);
  }
}

void on_click(int x, int y, gip_gfx_mouse_button_t button)
{
  x = x / TILE_WIDTH;
  y = y / TILE_HEIGHT;
  if (button == GIP_GFX_MOUSE_BUTTON_LEFT)
  {
    printf("Left click ");
    if (state[x][y].has_flag == false)
    {
      state[x][y].is_open = true;
      state[x][y].has_flag = false;
      if (state[x][y].number == 0)
      {
        clear_view(x - 1, y);
        clear_view(x + 1, y);
        clear_view(x, y - 1);
        clear_view(x, y + 1);
        for (int x = 0; x < NUM_COLS; x++)
        {
          for (int y = 0; y < NUM_ROWS; y++)
          {
            open_numbers(x, y);
          }
        }
      }
    }
    update_window_image();
  }
  else if (button == GIP_GFX_MOUSE_BUTTON_RIGHT)
  {
    printf("Right click ");
    state[x][y].has_flag = state[x][y].has_flag == false;
    update_window_image();
  }
  printf("at (%d,%d).\n ", x, y);
}

int *getRandoms(int number_of_elements, int limit)
{
  int *randoms = (int *)malloc(number_of_elements * sizeof(int));
  for (int i = 0; i < number_of_elements; i++)
  {
    int ran = rand() % limit;
    printf("%d ", ran);
    limit--;
    randoms[i] = ran;
    for (int j = 0; j < i; j++)
    {
      if (ran >= randoms[j])
      {
        ran++;
        randoms[i] = ran;
      }
      else
      {
        for (int x = i; x >= j; x--)
        {
          randoms[x] = randoms[x - 1];
        }
        randoms[j] = ran;
        break;
      }
    }
    printf("-> %d\n", ran);
  }
  return randoms;
}

int main(int argc, char *argv[])
{
  for (int x = 0; x < NUM_COLS; x++)
  {
    for (int y = 0; y < NUM_ROWS; y++)
    {
      state[x][y].has_flag = false;
      state[x][y].has_mine = false;
      state[x][y].is_open = false;
      // state[x][y].is_open = true;
      state[x][y].number = 0;
    }
  }

  srand(time(NULL));
  int *randoms = getRandoms(NUM_MINES, NUM_ROWS * NUM_COLS);
  for (int i = 0; i < NUM_MINES; i++)
  {
    int x = randoms[i] % NUM_COLS;
    int y = randoms[i] / NUM_COLS;
    state[x][y].has_mine = true;
    printf("(%d,%d)", x, y);
  }

  for (int x = 0; x < NUM_COLS; x++)
  {
    for (int y = 0; y < NUM_ROWS; y++)
    {
      state[x][y].number = GetSum(x, y, 1);
    }
  }

  gip_gfx_create_window("Minesweeper", NUM_COLS * TILE_WIDTH,
                        NUM_ROWS * TILE_HEIGHT);

  gip_gfx_set_on_click_fn(on_click);

  tiles = gip_gfx_load_bmp("./media/tiles.bmp");
  update_window_image();

  while (gip_gfx_running())
  {
    gip_gfx_handle_events();
    gip_gfx_render();
  }

  gip_gfx_free_image(tiles);

  return 0;
}
