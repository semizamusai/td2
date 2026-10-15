#include <Novice.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <cmath>
const char kWindowTitle[] = "LC1D_03_イダ_ノコ_タルト";

const int kTileSize = 32;
const int kMapWidth = 200;
const int kMapHeight = 23;

// 0 = 空間、1 = 地面、2 = 壁
int map[kMapHeight][kMapWidth] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void DrawMap(float cameraX)
{
    for (int y = 0; y < kMapHeight; y++)
    {
        for (int x = 0; x < kMapWidth; x++)
        {
            if (map[y][x] == 0)
            {
                continue;
            }

            int worldX = x * kTileSize;
            int worldY = y * kTileSize;

            int screenX = (int)(worldX - cameraX);

            // 画面外は描画しない
            if (screenX + kTileSize < 0 ||
                screenX > 1280)
            {
                continue;
            }

            Novice::DrawBox(
                screenX,
                worldY,
                kTileSize,
                kTileSize,
                0.0f,
                GREEN,
                kFillModeSolid
            );
        }
    }
}

bool CheckMapCollision(
    float playerX,
    float playerY,
    float playerWidth,
    float playerHeight)
{
    float left = playerX - playerWidth / 2.0f;
    float right = playerX + playerWidth / 2.0f;
    float top = playerY - playerHeight / 2.0f;
    float bottom = playerY + playerHeight / 2.0f;

    // プレイヤーが重なる可能性のあるマスだけ調べる
    int startX = (int)floorf(left / kTileSize);
    int endX = (int)floorf((right - 0.001f) / kTileSize);
    int startY = (int)floorf(top / kTileSize);
    int endY = (int)floorf((bottom - 0.001f) / kTileSize);

    for (int y = startY; y <= endY; y++)
    {
        for (int x = startX; x <= endX; x++)
        {
            if (x < 0 || x >= kMapWidth ||
                y < 0 || y >= kMapHeight)
            {
                continue;
            }

            if (map[y][x] == 0)
            {
                continue;
            }

            float tileLeft = (float)(x * kTileSize);
            float tileTop = (float)(y * kTileSize);
            float tileRight = tileLeft + kTileSize;
            float tileBottom = tileTop + kTileSize;

            if (left < tileRight &&
                right > tileLeft &&
                top < tileBottom &&
                bottom > tileTop)
            {
                return true;
            }
        }
    }

    return false;
}

enum Scene {
    SCENE_TITLE,
    SCENE_GAME
};

enum FadeState {
    FADE_NONE,
    FADE_OUT,
    FADE_IN
};

struct Vector2 {
    float x;
    float y;
};

struct Bomb {
    float x;
    float y;
    int timer;
    bool isActive;
    bool isExplosion;
    int explosionTimer;
};

struct Enemy {
    float x;
    float y;
    float velocityX;
    float velocityY;
    float speed;
    bool isAlive;
};

Vector2 Player = { 640.0f, 300.0f };

bool isShaking = false;

int shakeDuration = 60; // 画面揺れの継続時間

int amplitude = 10; // 揺れの振幅

int randX = rand() % amplitude / 2;
int randY = rand() % amplitude / 2;

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

    Novice::Initialize(kWindowTitle, 1280, 720);

    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // フェード関連
    FadeState fadeState = FADE_IN;

    // 黒い四角形の透明度（0～255）0x000000FFのFFの部分
    int fadeAlpha = 255;

    // 1フレームごとに変化する透明度
    const int fadeSpeed = 3;

    //シーン管理
    Scene scene = SCENE_TITLE;

    //プレイヤー
    Vector2 player = { 640.0f, 300.0f };

    // カメラ
    float cameraX = 0.0f;

    //プレイやーの当たり判定のサイズ
    float playerWidth = 40.0f;
    float playerHeight = 40.0f;

    // 重力関連
    //sokudo
    float velocityY = 0.0f;
    float velocityX = 0.0f;

    float accelerationX = 10.0f;
    // X方向の摩擦
    float frictionX = 0.5f;
    // 重力
    float gravity = 1.0f;

    // 最大落下速度
    float maxFallSpeed = 15.0f;

    // 爆弾
    const int kBombCount = 10;
    Bomb bombs[kBombCount] = {};

    // 爆弾の設定
    const int bombFuseTime = 60;
    const int explosionDuration = 15;
    const float explosionRadius = 180.0f;
    const float bombKnockBack = 20.0f;

    // 床
    float groundY = 650.0f;

    bool isGround = false;


    // 追跡型の敵
    Enemy enemy = {};
    enemy.x = 1500.0f;
    enemy.y = 630.0f;
    enemy.speed = 2.0f;
    enemy.isAlive = true;

    // 爆発音
    int Explosion01 = Novice::LoadAudio("./Resources/Explosion01-2(Long).mp3");

    int bgm = Novice::LoadAudio("./Resources/hajimeED.wav");

    while (Novice::ProcessMessage() == 0) {

        Novice::BeginFrame();

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理
        ///
        if (scene == SCENE_TITLE && keys[DIK_SPACE] && !preKeys[DIK_SPACE] && fadeState == FADE_NONE)
        {
            fadeState = FADE_OUT;
        }

        // フェード処理
        if (fadeState == FADE_OUT)
        {

            // 黒を徐々に濃くする
            fadeAlpha += fadeSpeed;

            if (fadeAlpha >= 255)
            {
                fadeAlpha = 255;
                // 暗転したらゲーム画面に切り替える 
                scene = SCENE_GAME;
                Novice::PlayAudio(bgm, true, 1.0f);
                fadeState = FADE_IN;
            }
        }
        else if (fadeState == FADE_IN)
        {

            // 黒を徐々に透明にする
            fadeAlpha -= fadeSpeed;

            if (fadeAlpha <= 0)
            {
                fadeAlpha = 0;
                fadeState = FADE_NONE;
            }
        }
        if (scene == SCENE_GAME) {
            //====================
            // プレイヤー左右移動
            //====================

            // Dキーで右移動
            if (keys[DIK_D]) {
                velocityX += accelerationX;
            }

            // Aキーで左移動
            if (keys[DIK_A]) {
                velocityX -= accelerationX;
            }

            //====================
            // 重力処理
            //====================

            // 毎フレーム下方向に加速
            velocityY += gravity;

            // 最大落下速度を制限
            if (velocityY > maxFallSpeed) {
                velocityY = maxFallSpeed;
            }

            //====================
            // 摩擦
            //====================
            velocityX *= frictionX;

            //====================
            // 座標更新
            //====================
          // 横方向の移動
            float nextX = player.x + velocityX;

            if (!CheckMapCollision(
                nextX, player.y, playerWidth, playerHeight))
            {
                player.x = nextX;
            }
            else
            {
                velocityX = 0.0f;
            }

            // 縦方向の移動
            float nextY = player.y + velocityY;

            if (!CheckMapCollision(
                player.x, nextY, playerWidth, playerHeight))
            {
                player.y = nextY;
                isGround = false;
            }
            else
            {
                if (velocityY > 0.0f)
                {
                    isGround = true;
                }

                velocityY = 0.0f;
            }
            //====================
           // 爆弾の設置
           //====================
            if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
            {
                for (int i = 0; i < kBombCount; i++)
                {
                    if (!bombs[i].isActive)
                    {
                        bombs[i].x = player.x;
                        bombs[i].y = player.y + 10;

                        bombs[i].timer = bombFuseTime;
                        bombs[i].isActive = true;
                        bombs[i].isExplosion = false;
                        bombs[i].explosionTimer = 0;

                        break;
                    }
                }
            }
        }
        //====================
        // 爆弾の更新
        //====================
        for (int i = 0; i < kBombCount; i++)
        {
            if (bombs[i].isActive)
            {
                if (!bombs[i].isExplosion)
                {
                    bombs[i].timer--;

                    // 爆発15フレーム前に1回だけ再生
                    if (bombs[i].timer == 15)
                    {
                        Novice::PlayAudio(Explosion01, false, 1.0f);
                        isShaking = true;
                    }

                    if (bombs[i].timer <= 0)
                    {
                        bombs[i].isExplosion = true;
                        bombs[i].explosionTimer = explosionDuration;

                        // プレイヤーとの距離
                        float dx = player.x - bombs[i].x;
                        float dy = player.y - bombs[i].y;

                        float distance = sqrtf(dx * dx + dy * dy);

                        // 爆発範囲内ならノックバック
                        if (distance < explosionRadius)
                        {
                            if (distance > 0.0f)
                            {
                                velocityX += dx / distance * bombKnockBack;
                            }
                            // 上方向に吹き飛ばす
                            velocityY = -25.0f;
                        }

                        // 爆発範囲に入った敵を倒す
                        if (enemy.isAlive)
                        {
                            float enemyDx = enemy.x - bombs[i].x;
                            float enemyDy = enemy.y - bombs[i].y;
                            float enemyDistance = sqrtf(enemyDx * enemyDx + enemyDy * enemyDy);
                            if (enemyDistance < explosionRadius)
                            {
                                enemy.isAlive = false;
                            }
                        }
                    }
                }
                else
                {
                    bombs[i].explosionTimer--;

                    if (bombs[i].explosionTimer <= 0)
                    {
                        bombs[i].isActive = false;
                        bombs[i].isExplosion = false;
                    }
                }
            }
        }



        //====================
        // 追跡型の敵の更新（マップとの当たり判定あり）
        //====================
        if (scene == SCENE_GAME && enemy.isAlive)
        {
            float dx = player.x - enemy.x;
            if (dx > 30.0f) {
                enemy.velocityX += enemy.speed * 0.1f;
            }
            else if (dx < -30.0f) {
                enemy.velocityX -= enemy.speed * 0.1f;
            }
            enemy.velocityX *= 0.9f;
            enemy.velocityY += gravity;
            if (enemy.velocityY > maxFallSpeed) {
                enemy.velocityY = maxFallSpeed;
            }

            float nextEnemyX = enemy.x + enemy.velocityX;
            if (!CheckMapCollision(nextEnemyX, enemy.y, 40.0f, 40.0f)) {
                enemy.x = nextEnemyX;
            }
            else {
                enemy.velocityX = 0.0f;
            }

            float nextEnemyY = enemy.y + enemy.velocityY;
            if (!CheckMapCollision(enemy.x, nextEnemyY, 40.0f, 40.0f)) {
                enemy.y = nextEnemyY;
            }
            else {
                enemy.velocityY = 0.0f;
            }
        }

        //カメラのスクロール
        float cameraTargetX = player.x - 740.0f;

        if (player.x > 740.0f)
        {

            cameraTargetX = player.x - 740.0f;
        }

        cameraX += (cameraTargetX - cameraX) * 0.1f;


        if (cameraX < 0.0f)
        {
            cameraX = 0.0f;
        }

        // //====================
        //// プレイヤーの当たり判定
        ////====================
        // float playerLeft = player.x - playerWidth / 2.0f;
        // float playerRight = player.x + playerWidth / 2.0f;
        // float playerTop = player.y - playerHeight / 2.0f;
        // float playerBottom = player.y + playerHeight / 2.0f;

         //====================
         // 床,壁との当たり判定
         //====================

        if (player.x - playerWidth / 2.0f < 0.0f)
        {
            player.x = playerWidth / 2.0f;
            velocityX = 0.0f;
        }


        if (player.y - playerHeight / 2.0f < 0.0f)
        {
            player.y = playerHeight / 2.0f;
            velocityY = 0.0f;
        }


        ///
        /// ↑更新処理
        ///

        ///
        /// ↓描画処理
        ///

        if (scene == SCENE_TITLE)
        {
            //タイトル
            Novice::DrawBox(
                0,
                0,
                1280,
                720,
                0.0f,
                BLUE,
                kFillModeSolid
            );
            Novice::ScreenPrintf(
                450,
                350,
                "PRESS SPACE"
            );
        }
        else if (scene == SCENE_GAME)
        {
            //背景
            Novice::DrawBox(
                0,
                0,
                1280,
                720,
                0.0f,
                0x000000FF,
                kFillModeSolid
            );

            DrawMap(cameraX);



            // スクロール確認用のめもり
            for (int x = 0; x <= 5000; x += 100)
            {
                int screenX = x - (int)cameraX;

                // 画面内だけ描画
                if (screenX >= 0 && screenX <= 1280)
                {
                    Novice::DrawLine(
                        screenX,
                        (int)groundY - 20,
                        screenX,
                        (int)groundY,
                        0xFFFFFFFF
                    );

                    Novice::ScreenPrintf(
                        screenX + 5,
                        (int)groundY - 40,
                        "%d",
                        x
                    );
                }
            }

            // プレイヤー
            Novice::DrawBox(
                (int)(player.x - cameraX) - 20,
                (int)player.y - 20,
                40,
                40,
                0.0f,
                0x00AAFFFF,
                kFillModeSolid
            );
            //====================
            // 爆弾の描画
            //====================
            for (int i = 0; i < kBombCount; i++)
            {
                if (bombs[i].isActive)
                {
                    int screenX = (int)(bombs[i].x - cameraX);
                    int screenY = (int)bombs[i].y;

                    if (!bombs[i].isExplosion)
                    {
                        // 爆弾本体
                        Novice::DrawBox(
                            screenX - 10,
                            screenY - 10,
                            20,
                            20,
                            0.0f,
                            0xFF0000FF,
                            kFillModeSolid
                        );
                    }
                    else
                    {
                        // 爆発エフェクト
                        float progress =
                            1.0f - (float)bombs[i].explosionTimer
                            / explosionDuration;

                        int size = (int)(explosionRadius * 2.0f * progress);

                        Novice::DrawBox(
                            screenX - size / 2,
                            screenY - size / 2,
                            size,
                            size,
                            0.0f,
                            0xFFAA00FF,
                            kFillModeSolid
                        );
                    }
                }
            }


            // 追跡型の敵（赤い四角）
            if (enemy.isAlive)
            {
                Novice::DrawBox(
                    (int)(enemy.x - cameraX - 20.0f),
                    (int)(enemy.y - 20.0f),
                    40, 40, 0.0f, 0xFF4444FF, kFillModeSolid
                );
            }

            // プレイヤーの当たり判定の描画
            Novice::DrawBox(
                (int)(player.x - cameraX - playerWidth / 2.0f),
                (int)(player.y - playerHeight / 2.0f),
                (int)playerWidth,
                (int)playerHeight,
                0.0f,
                RED,
                kFillModeWireFrame
            );


            ///
            /// ↑描画処理
            ///
        }

        // ブレンディングを通常のアルファ合成にする
        Novice::SetBlendMode(BlendMode::kBlendModeNormal);

        // 黒い四角形の色を作る
        unsigned int fadeColor =
            0x00000000 | ((unsigned int)fadeAlpha & 0xFF);

        // 画面全体に黒い四角形を重ねる
        Novice::DrawBox(
            0, 0,          // 描画する位置
            1280, 720,     // 画面全体のサイズ
            0.0f,          // 回転角度
            fadeColor,     // 黒色＋透明度
            kFillModeSolid // 塗りつぶし
        );

        // ブレンド設定を元に戻す
        Novice::SetBlendMode(BlendMode::kBlendModeNormal);
        Novice::EndFrame();

        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }

    }
    Novice::Finalize();
    return 0;

}