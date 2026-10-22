#include <Novice.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <cmath>
const char kWindowTitle[] = "LC1D_03_イシダ_ノリヒコ_タイトル";

const int kTileSize = 32;
const int kMapWidth = 200;
const int kMapHeight = 23;

// 0 = 空間、1 = 地面、2 = 壁、3 = 壊れる壁
int map[kMapHeight][kMapWidth] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// Boss arena: 40 columns x 23 rows, 32 pixels per tile.
const int kBossMapWidth = 40;
const int kBossMapHeight = 23;
int bossMap[kBossMapHeight][kBossMapWidth] = {};

void InitBossMap() {
    for (int y = 0; y < kBossMapHeight; ++y) {
        for (int x = 0; x < kBossMapWidth; ++x) {
            bossMap[y][x] = (y >= 20) ? 1 : 0;
            if (x == 0) bossMap[y][x] = 2; // left wall only
        }
    }
}

void DrawBossMap(int yukaTexture, int breakableYukaTexture) {
    for (int y = 0; y < kBossMapHeight; ++y) {
        for (int x = 0; x < kBossMapWidth; ++x) {
            if (bossMap[y][x] == 0) continue;
            int texture = bossMap[y][x] == 3 ? breakableYukaTexture : yukaTexture;
            Novice::DrawSprite(x * kTileSize, y * kTileSize, texture,
                1.0f, 1.0f, 0.0f, WHITE);
        }
    }
}

bool CheckBossMapCollision(float x, float y, float width, float height) {
    float left = x - width / 2.0f;
    float right = x + width / 2.0f;
    float top = y - height / 2.0f;
    float bottom = y + height / 2.0f;
    int sx = (int)floorf(left / kTileSize);
    int ex = (int)floorf((right - 0.001f) / kTileSize);
    int sy = (int)floorf(top / kTileSize);
    int ey = (int)floorf((bottom - 0.001f) / kTileSize);
    for (int ty = sy; ty <= ey; ++ty) {
        for (int tx = sx; tx <= ex; ++tx) {
            if (tx < 0 || tx >= kBossMapWidth || ty < 0 || ty >= kBossMapHeight)
                return true;
            if (bossMap[ty][tx] != 0) return true;
        }
    }
    return false;
}

int backGroundRandomX{};;//ランダム
int backGroundRandomY{};;//ランダム

void DrawMap(float cameraX,
    int yukaTexture,
    int breakableYukaTexture)
{
    for (int y = 0; y < kMapHeight; y++)
    {
        for (int x = 0; x < kMapWidth; x++)
        {
            if (map[y][x] == 0)
            {
                continue;
            }

            int worldX = x * kTileSize + backGroundRandomX;
            int worldY = y * kTileSize + backGroundRandomY;

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

            int tileTexture = yukaTexture;


            if (map[y][x] == 3)
            {
                tileTexture = breakableYukaTexture;
            }

            Novice::DrawSprite(
                screenX,
                worldY,
                tileTexture,
                1.0f,
                1.0f,
                0.0f,
                WHITE
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
    SCENE_GAME,
    SCENE_GAME2
};

enum FadeState {
    FADE_NONE,
    FADE_OUT,
    FADE_IN
};

struct Vector2 {
    float x{};
    float y{};
};

struct BreakParticle {
    float x{};
    float y{};
    float velocityX{};
    float velocityY{};
    int sourceX{};
    int sourceY{};
    int life{};
    bool isActive{};
};

// パーティクルの最大数
const int kMaxBreakParticles = 100;

// パーティクル配列
BreakParticle breakParticles[kMaxBreakParticles]{};

struct Bomb {
    float x{};
    float y{};

    float velocityX{};
    float velocityY{};

    int timer{};
    bool isActive{};
    bool isExplosion{};
    int explosionTimer{};
};

struct Enemy {
    float x{};
    float y{};
    float velocityX{};
    float velocityY{};
    float speed = 0.0f;
    bool isAlive{};
    bool isKnockedBack{};
    int knockbackTimer = 0;
    bool isDead{};          // 倒されたか
    int deathTimer = 0;       // 消えるまでの時間
    float rotation = 0.0f;       // 回転角度
    float rotationSpeed = 0.0f;  // 回転速度
    bool isExploding = false;  // 爆発中
    bool explosionReserved = false; // 誘爆予約中
    int explosionTimer = 0;    // 爆発エフェクト
    int chainTimer = 0;        // 誘爆までの待ち時間
};
struct Boss {
    float x;
    float y;
    float velocityX;

    float width;
    float height;

    int hp;
    int maxHp;

    bool isAlive;
    int damageCooldown;
};

// 壁が壊れたときにパーティクルを発生させる

void SpawnBreakParticles(float x, float y)
{
    const int kParticleCount = 16;
    const int kPieceSize = 1;
    int count = 0;

    for (int i = 0; i < kMaxBreakParticles; i++)
    {
        if (!breakParticles[i].isActive)
        {
            int column = count % 4;
            int row = count / 4;

            // 破片の初期位置
            breakParticles[i].x = x + column * kPieceSize;
            breakParticles[i].y = y + row * kPieceSize;

            // 横方向をランダムにする（左・右）
            breakParticles[i].velocityX =
                (float)(rand() % 801 - 400) / 100.0f;

            // 縦方向をランダムにする（上方向に飛ぶ）
            breakParticles[i].velocityY =
                -(float)(rand() % 601 + 200) / 100.0f;

            // 画像の切り出し位置
            breakParticles[i].sourceX = column * kPieceSize;
            breakParticles[i].sourceY = row * kPieceSize;

            // 寿命もランダムにする
            breakParticles[i].life = 20 + rand() % 21;

            breakParticles[i].isActive = true;

            count++;

            if (count >= kParticleCount)
            {
                break;
            }
        }
    }
}

struct Shake {
    int duration;//揺れの時間
    int amplitude;//揺れの振幅
    bool backGroundFlag;//背景の揺れフラグ

};

Vector2 Player = { 640.0f, 300.0f };
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

    srand((unsigned int)time(nullptr));

    Novice::Initialize(kWindowTitle, 1280, 720);
    InitBossMap();

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
    const float explosionRadius = 100.0f;
    const float bombKnockBack = 20.0f;

    bool isGround = false;

    Shake shake;
    shake.duration = 2;//揺れの時間
    shake.amplitude = 30;//揺れの振幅
    shake.backGroundFlag = false;//背景の揺れフラグ

    // 50体の敵をマップの空きスペースに配置
    const int kEnemyCount = 100;
    Enemy enemies[kEnemyCount] = {};
    int spawnedEnemies = 0;
    const float enemySize = 40.0f;
    ////////////////
    //ボス///////////////////////
    //////////////              //////////
    ///////                              //////////
    Boss boss = {};

    boss.x = 900.0f;
    boss.y = 500.0f;
    boss.velocityX = 0.0f;

    boss.width = 120.0f;
    boss.height = 120.0f;

    boss.hp = 10;
    boss.maxHp = 10;

    boss.isAlive = true;
    boss.damageCooldown = 0;

    // ボスの壊せる壁生成攻撃（60FPSで約3秒ごと）
    // 壁攻撃：予告60F → 3段せり上がり(各10F) → 次の攻撃まで待機
    int bossWallTimer = 0;
    const int bossWallInterval = 180;
    const int bossWallWarning = 60;
    const int bossWallRiseStep = 10;
    int bossWallX = -1;
    int bossWallRiseCount = 0;
    int playerWallHitCooldown = 0;

    // 左右から挟み込む岩攻撃（ボス戦専用）
    int rockAttackTimer = 0;
    int rockPhase = 0; // 0:待機 1:予告 2:挟み込み（到達時に破壊）
    int rockPhaseTimer = 0;
    float rockLeftX = -96.0f;
    float rockRightX = 1280.0f;
    float rockTargetX = 640.0f; // 攻撃開始時のプレイヤー位置を固定
    const float rockWidth = 96.0f;
    const float rockHeight = 160.0f;
    const float rockY = 480.0f; // 地面の上端640から160px
    bool rockLeftAlive = false;
    bool rockRightAlive = false;
    int rockHitCooldown = 0;

    // 落石攻撃：予告後に重力で落ちる岩
    struct FallingRock {
        float x, y, velocityY;
        int warningTimer;
        int lifeTimer;
        bool active;
        bool falling;
        bool landed;
    };
    const int kFallingRockCount = 16;
    FallingRock fallingRocks[kFallingRockCount] = {};
    int fallingRockAttackTimer = 0;
    int fallingRockHitCooldown = 0;


    //タイトルもんげ
    int monge1 =
        Novice::LoadTexture("./tntn/monge1.png");
    int monge2 =
        Novice::LoadTexture("./tntn/monge2.png");
    int monge3 =
        Novice::LoadTexture("./tntn/monge3.png");


    // マップ・爆弾のテクスチャ
    int yukaTexture =
        Novice::LoadTexture("./Resources/yuka.png");

    int bombTexture =
        Novice::LoadTexture("./Resources/bomb.png");

    int breakableYukaTexture =
        Novice::LoadTexture("./Resources/kowareruyuka.png");

    int enterSE = Novice::LoadAudio("./Resources/ENTER.mp3");

    int hakaiSE = Novice::LoadAudio("./Resources/hakai.mp3");
    // 現在選択している項目// 選択番号（0:左、1:中央、2:右）
    int titleSelect = 0;

    // 爆発音
    int Explosion01 = Novice::LoadAudio("./Resources/Explosion01-1(Short).mp3");
    int bgm = Novice::LoadAudio("./Resources/icarusnotsuiraku.mp3");

    int rensaSE = Novice::LoadAudio("./Resources/HIKAKIN.mp3");
    Novice::PlayAudio(bgm, true, 0.5f);

    while (Novice::ProcessMessage() == 0) {

        Novice::BeginFrame();

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理
        ///
        if (scene == SCENE_TITLE && fadeState == FADE_NONE)
        {
            // Aキーで左へ
            if (keys[DIK_A] && !preKeys[DIK_A])
            {
                titleSelect--;

                if (titleSelect < 0)
                {
                    titleSelect = 2;
                }
            }

            // Dキーで右へ
            if (keys[DIK_D] && !preKeys[DIK_D])
            {
                titleSelect++;

                if (titleSelect > 2)
                {
                    titleSelect = 0;
                }
            }

            // Enterキーで決定
            if (keys[DIK_RETURN] && !preKeys[DIK_RETURN])
            {
                // Enterキーの効果音を再生
                Novice::PlayAudio(enterSE, false, 1.0f);

                if (titleSelect == 0)
                {
                    // 左：ゲーム開始
                    fadeState = FADE_OUT;
                }
                else if (titleSelect == 1)
                {
                    // 中央：操作説明（後から実装）
                }
                else if (titleSelect == 2)
                {
                    // 右：終了
                    break;
                }
            }
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
        if (scene == SCENE_GAME || scene == SCENE_GAME2) {
            //====================
            // プレイヤー左右移動
            //====================

             // X方向に候補を並べ、各地点の地面の上に配置する
            for (int x = 160; scene == SCENE_GAME && x < kMapWidth * kTileSize - 40 && spawnedEnemies < kEnemyCount; x += 80)
            {
                for (int y = (kMapHeight - 1) * kTileSize - 20; y >= 20; y -= 4)
                {
                    float spawnX = (float)x;
                    float spawnY = (float)y;
                    // 敵の全身が空間内、足元に床がある位置だけ採用
                    if (CheckMapCollision(spawnX, spawnY, enemySize, enemySize) ||
                        !CheckMapCollision(spawnX, spawnY + 2.0f, enemySize, enemySize))
                    {
                        continue;
                    }
                    // プレイヤーの初期位置付近には置かない
                    if (fabsf(spawnX - player.x) < 640.0f && fabsf(spawnY - player.y) < 400.0f)
                    {
                        continue;
                    }
                    // 敵同士が初期状態で重ならないようにする
                    bool overlaps = false;
                    for (int j = 0; j < spawnedEnemies; ++j)
                    {
                        if (fabsf(enemies[j].x - spawnX) < enemySize + 4.0f &&
                            fabsf(enemies[j].y - spawnY) < enemySize + 4.0f)
                        {
                            overlaps = true;
                            break;
                        }
                    }
                    if (overlaps) continue;

                    Enemy& e = enemies[spawnedEnemies++];
                    e.x = spawnX;
                    e.y = spawnY;
                    e.speed = 2.0f;
                    e.isAlive = true;
                    e.isKnockedBack = false;
                    e.knockbackTimer = 0;
                    break;
                }
            }

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

            if (!(scene == SCENE_GAME2
                ? CheckBossMapCollision(nextX, player.y, playerWidth, playerHeight)
                : CheckMapCollision(nextX, player.y, playerWidth, playerHeight)))
            {
                player.x = nextX;
            }
            else
            {
                velocityX = 0.0f;
            }

            // 縦方向の移動
            float nextY = player.y + velocityY;

            if (!(scene == SCENE_GAME2
                ? CheckBossMapCollision(player.x, nextY, playerWidth, playerHeight)
                : CheckMapCollision(player.x, nextY, playerWidth, playerHeight)))
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
            // 着地済みの岩は障害物：重なった場合は横へ押し出す
            if (scene == SCENE_GAME2) {
                for (int i = 0; i < kFallingRockCount; ++i) {
                    const FallingRock& r = fallingRocks[i];
                    if (!r.active || !r.landed) continue;
                    float dx = player.x - r.x;
                    float dy = player.y - r.y;
                    float overlapX = playerWidth * 0.5f + 32.0f - fabsf(dx);
                    float overlapY = playerHeight * 0.5f + 32.0f - fabsf(dy);
                    if (overlapX > 0.0f && overlapY > 0.0f) {
                        if (overlapX < overlapY) {
                            player.x += dx < 0.0f ? -overlapX : overlapX;
                            velocityX = 0.0f;
                        }
                        else {
                            player.y += dy < 0.0f ? -overlapY : overlapY;
                            velocityY = 0.0f;
                            if (dy < 0.0f) isGround = true;
                        }
                    }
                }
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

                        bombs[i].velocityX = 0.0f;
                        bombs[i].velocityY = 0.0f;

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

                    //====================
                    // 爆弾の物理処理
                    //====================

                    // 重力
                    bombs[i].velocityY += 0.6f;

                    // 最大落下速度
                    if (bombs[i].velocityY > 15.0f)
                    {
                        bombs[i].velocityY = 15.0f;
                    }

                    // 横方向の摩擦
                    bombs[i].velocityX *= 0.98f;

                    // 横方向の移動と壁判定
                    float remainingX = bombs[i].velocityX;

                    while (fabsf(remainingX) > 0.001f)
                    {
                        float stepX = remainingX;

                        if (stepX > 4.0f) stepX = 4.0f;
                        if (stepX < -4.0f) stepX = -4.0f;

                        float nextX = bombs[i].x + stepX;

                        if (nextX >= 10.0f &&
                            nextX <= kMapWidth * kTileSize - 10.0f &&
                            !(scene == SCENE_GAME2
                                ? CheckBossMapCollision(nextX, bombs[i].y, 20.0f, 20.0f)
                                : CheckMapCollision(nextX, bombs[i].y, 20.0f, 20.0f)))
                        {
                            bombs[i].x = nextX;
                            remainingX -= stepX;
                        }
                        else
                        {
                            bombs[i].velocityX = 0.0f;
                            break;
                        }
                    }

                    // 縦方向の移動と床・天井判定
                    float remainingY = bombs[i].velocityY;

                    while (fabsf(remainingY) > 0.001f)
                    {
                        float stepY = remainingY;

                        if (stepY > 4.0f) stepY = 4.0f;
                        if (stepY < -4.0f) stepY = -4.0f;

                        float nextY = bombs[i].y + stepY;

                        if (nextY >= 10.0f &&
                            !(scene == SCENE_GAME2
                                ? CheckBossMapCollision(bombs[i].x, nextY, 20.0f, 20.0f)
                                : CheckMapCollision(bombs[i].x, nextY, 20.0f, 20.0f)))
                        {
                            bombs[i].y = nextY;
                            remainingY -= stepY;
                        }
                        else
                        {
                            bombs[i].velocityY = 0.0f;
                            break;
                        }
                    }

                    bombs[i].timer--;

                    // 爆発15フレーム前に1回だけ再生
                    if (bombs[i].timer == 15)
                    {
                        Novice::PlayAudio(Explosion01, false, 1.0f);
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

                        //====================
                       // 爆風で別の爆弾を吹き飛ばす
                       //====================
                        for (int j = 0; j < kBombCount; j++)
                        {
                            // 自分自身や爆発中の爆弾は除外
                            if (i == j || !bombs[j].isActive ||
                                bombs[j].isExplosion)
                            {
                                continue;
                            }

                            float dx1 = bombs[j].x - bombs[i].x;
                            float dy1 = bombs[j].y - bombs[i].y;

                            float distance1 = sqrtf(dx1 * dx1 + dy1 * dy1);

                            if (distance1 < explosionRadius)
                            {
                                float directionX = 1.0f;

                                if (distance1 > 0.001f)
                                {
                                    directionX = dx1 / distance1;
                                }

                                // 横方向に吹き飛ばす
                                bombs[j].velocityX = directionX * 20.0f;

                                // 上方向にも吹き飛ばす
                                bombs[j].velocityY = -15.0f;
                            }
                        }

                        // 爆発範囲内の敵をそれぞれ吹き飛ばす
                        for (int e = 0; scene == SCENE_GAME && e < spawnedEnemies; ++e)
                        {
                            if (enemies[e].isAlive)
                            {
                                float enemyDx = enemies[e].x - bombs[i].x;
                                float enemyDy = enemies[e].y - bombs[i].y;
                                float enemyDistance = sqrtf(enemyDx * enemyDx + enemyDy * enemyDy);
                                if (enemyDistance < explosionRadius)
                                {
                                    // 重なっていても方向が決まるようにする
                                    float directionX = enemyDx >= 0.0f ? 1.0f : -1.0f;
                                    if (enemyDistance > 0.001f)
                                    {
                                        directionX = enemyDx / enemyDistance;
                                    }
                                    // 壁にぶつけやすいように横方向の最低速度を確保
                                    if (directionX > -0.5f && directionX < 0.5f)
                                    {
                                        directionX = directionX >= 0.0f ? 0.5f : -0.5f;
                                    }
                                    enemies[e].velocityX = directionX * 24.0f;
                                    enemies[e].velocityY = -12.0f;
                                    enemies[e].isKnockedBack = true;
                                    enemies[e].knockbackTimer = 45;
                                    enemies[e].isDead = true;
                                    enemies[e].deathTimer = 180;
                                    enemies[e].rotationSpeed = directionX * 0.16f;
                                }
                            }
                        }

                        //shake起動条件
                        if (bombs[i].timer == 0) {
                            shake.backGroundFlag = true;
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

                        //--- 壊せる壁の破壊処理 ---
                        //爆発中心のタイル座標
                        int explosionTileX = (int)bombs[i].x / kTileSize;
                        int explosionTileY = (int)bombs[i].y / kTileSize;

                        //爆風が届くタイルの半径（切り上げ）
                        int explosionTileRadius = (int)ceilf(explosionRadius / kTileSize);


                        //探索するタイルの範囲（最小・最大座標）
                        int minExTileX = explosionTileX - explosionTileRadius;
                        int maxExTileX = explosionTileX + explosionTileRadius;
                        int minExTileY = explosionTileY - explosionTileRadius;
                        int maxExTileY = explosionTileY + explosionTileRadius;

                        for (int checkY = minExTileY; checkY <= maxExTileY; checkY++)
                        {
                            for (int checkX = minExTileX; checkX <= maxExTileX; checkX++)
                            {
                                // マップ配列の範囲内か確認
                                int activeMapWidth = (scene == SCENE_GAME2) ? kBossMapWidth : kMapWidth;
                                if (checkX < 0 || checkX >= activeMapWidth ||
                                    checkY < 0 || checkY >= kMapHeight)
                                {
                                    continue;
                                }

                                // 壊せる壁の場合
                                if ((scene == SCENE_GAME2 ? bossMap[checkY][checkX] : map[checkY][checkX]) == 3)
                                {
                                    float tileCenterX = (checkX + 0.5f) * kTileSize;
                                    float tileCenterY = (checkY + 0.5f) * kTileSize;

                                    float diffX = tileCenterX - bombs[i].x;
                                    float diffY = tileCenterY - bombs[i].y;
                                    float distanceToBomb = sqrtf(diffX * diffX + diffY * diffY);

                                    // 爆発範囲内なら破壊
                                    if (distanceToBomb <= explosionRadius)
                                    {
                                        float particleX = (float)(checkX * kTileSize);
                                        float particleY = (float)(checkY * kTileSize);

                                        SpawnBreakParticles(particleX, particleY);

                                        // ブロック破壊SE
                                        Novice::PlayAudio(hakaiSE, false, 0.1f);

                                        // 壁を消す
                                        if (scene == SCENE_GAME2) {
                                            bossMap[checkY][checkX] = 0;
                                        }
                                        else {
                                            map[checkY][checkX] = 0;
                                        }
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }



        //====================
        // 追跡型の敵：爆風で飛び、壁に強く衝突すると倒れる
        //====================
        for (int e = 0; e < spawnedEnemies; ++e)
            if (scene == SCENE_GAME && enemies[e].isAlive)
            {
                if (enemies[e].isKnockedBack)
                {
                    enemies[e].knockbackTimer--;
                    // 吹き飛び中は横方向の速度を緩やかに減衰
                    enemies[e].velocityX *= 0.99f;
                }
                else
                {
                    float dx = player.x - enemies[e].x;
                    if (dx > 30.0f) {
                        enemies[e].velocityX += enemies[e].speed * 0.1f;
                    }
                    else if (dx < -30.0f) {
                        enemies[e].velocityX -= enemies[e].speed * 0.1f;
                    }
                    enemies[e].velocityX *= 0.9f;
                }

                enemies[e].velocityY += gravity;
                if (enemies[e].velocityY > maxFallSpeed) {
                    enemies[e].velocityY = maxFallSpeed;
                }

                // 高速でも壁をすり抜けないように小刻みに移動
                float remainingX = enemies[e].velocityX;
                while (enemies[e].isAlive && fabsf(remainingX) > 0.001f)
                {
                    float stepX = remainingX;
                    if (stepX > 4.0f) stepX = 4.0f;
                    if (stepX < -4.0f) stepX = -4.0f;
                    if (enemies[e].x + stepX >= 20.0f &&
                        enemies[e].x + stepX <= kMapWidth * kTileSize - 20.0f &&
                        !CheckMapCollision(enemies[e].x + stepX, enemies[e].y, 40.0f, 40.0f))
                    {
                        enemies[e].x += stepX;
                        remainingX -= stepX;
                    }
                    else
                    {
                        // 衝突直前の速度でダメージを判定
                        if (enemies[e].isKnockedBack && fabsf(enemies[e].velocityX) >= 8.0f)
                        {
                            enemies[e].isAlive = false;
                        }
                        enemies[e].velocityX = 0.0f;
                        break;
                    }
                }

                if (enemies[e].isAlive)
                {
                    float remainingY = enemies[e].velocityY;
                    bool hitVertical = false;
                    while (fabsf(remainingY) > 0.001f)
                    {
                        float stepY = remainingY;
                        if (stepY > 4.0f) stepY = 4.0f;
                        if (stepY < -4.0f) stepY = -4.0f;
                        if (!CheckMapCollision(enemies[e].x, enemies[e].y + stepY, 40.0f, 40.0f))
                        {
                            enemies[e].y += stepY;
                            remainingY -= stepY;
                        }
                        else
                        {
                            hitVertical = true;
                            enemies[e].velocityY = 0.0f;
                            break;
                        }
                    }

                    // 地面に着地したら追跡に戻る（空中で45F経過しても戻る）
                    if (enemies[e].isKnockedBack &&
                        ((hitVertical && remainingY > 0.0f) || enemies[e].knockbackTimer <= 0))
                    {
                        enemies[e].isKnockedBack = false;
                    }
                }
            }

        //====================
        // 時間差の敵誘爆
        //====================
        const float chainRadius = 120.0f;
        const int chainDelay = 5;
        const int chainExplosionDuration = 15;

        // ① 吹き飛ばされた敵が別の敵に衝突
        for (int i = 0; i < spawnedEnemies; i++) {

            if (!enemies[i].isAlive ||
                !enemies[i].isDead ||
                enemies[i].isExploding ||
                enemies[i].explosionReserved) {
                continue;
            }

            for (int j = 0; j < spawnedEnemies; j++) {

                if (i == j ||
                    !enemies[j].isAlive ||
                    enemies[j].isExploding) {
                    continue;
                }

                float dx = enemies[j].x - enemies[i].x;
                float dy = enemies[j].y - enemies[i].y;

                float distance = sqrtf(dx * dx + dy * dy);

                if (distance < enemySize) {

                    enemies[i].explosionReserved = true;
                    enemies[i].chainTimer = chainDelay;
                    break;
                }
            }
        }

        // ② 誘爆予約のカウントダウン
        for (int i = 0; i < spawnedEnemies; i++) {

            if (!enemies[i].isAlive ||
                !enemies[i].explosionReserved) {
                continue;
            }

            enemies[i].chainTimer--;

            if (enemies[i].chainTimer <= 0) {

                enemies[i].explosionReserved = false;
                enemies[i].isExploding = true;
                enemies[i].explosionTimer = chainExplosionDuration;
                Novice::PlayAudio(rensaSE, false, 1.0f);
                // 周囲の敵に次の誘爆を予約
                for (int j = 0; j < spawnedEnemies; j++) {

                    if (i == j ||
                        !enemies[j].isAlive ||
                        enemies[j].isExploding ||
                        enemies[j].explosionReserved) {
                        continue;
                    }

                    float dx = enemies[j].x - enemies[i].x;
                    float dy = enemies[j].y - enemies[i].y;

                    float distance = sqrtf(dx * dx + dy * dy);

                    if (distance < chainRadius) {

                        enemies[j].explosionReserved = true;
                        enemies[j].chainTimer = chainDelay;
                        enemies[j].isDead = true;

                        float directionX =
                            dx >= 0.0f ? 1.0f : -1.0f;

                        enemies[j].velocityX = directionX * 20.0f;
                        enemies[j].velocityY = -12.0f;
                    }
                }
            }
        }

        // ③ 爆発エフェクトの時間管理
        for (int i = 0; i < spawnedEnemies; i++) {

            if (!enemies[i].isExploding) {
                continue;
            }

            enemies[i].explosionTimer--;

            if (enemies[i].explosionTimer <= 0) {
                enemies[i].isAlive = false;
                enemies[i].isExploding = false;
            }
        }

        //====================
        // 落石攻撃（ボス戦）
        //====================
        if (scene == SCENE_GAME2) {
            if (fallingRockHitCooldown > 0) --fallingRockHitCooldown;
            if (!boss.isAlive) {
                for (int i = 0; i < kFallingRockCount; ++i) {
                    fallingRocks[i].active = false;
                }
            }
            else {
                ++fallingRockAttackTimer;
                // 約6秒ごとに最大4個追加。着地済みの岩は再利用しない
                if (fallingRockAttackTimer >= 360) {
                    fallingRockAttackTimer = 0;
                    for (int spawn = 0; spawn < 4; ++spawn) {
                        int slot = -1;
                        for (int i = 0; i < kFallingRockCount; ++i) {
                            if (!fallingRocks[i].active) { slot = i; break; }
                        }
                        if (slot < 0) break;
                        FallingRock& r = fallingRocks[slot];
                        r = FallingRock{};
                        r.active = true;
                        r.falling = false;
                        r.landed = false;
                        r.y = -64.0f;
                        r.warningTimer = 55 + spawn * 12;
                        float offset = spawn == 0 ? 0.0f : (float)(rand() % 401 - 200);
                        r.x = player.x + offset;
                        if (r.x < 80.0f) r.x = 80.0f;
                        if (r.x > 1200.0f) r.x = 1200.0f;
                    }
                }

                for (int i = 0; i < kFallingRockCount; ++i) {
                    FallingRock& r = fallingRocks[i];
                    if (!r.active) continue;

                    // 落下中・着地済みのどちらも爆弾で破壊できる。
                    // 岩の矩形と爆風の円の最短距離で判定する。
                    bool broken = false;
                    for (int j = 0; j < kBombCount; ++j) {
                        if (!bombs[j].isActive || !bombs[j].isExplosion) continue;
                        float dx = fabsf(bombs[j].x - r.x) - 32.0f;
                        float dy = fabsf(bombs[j].y - r.y) - 32.0f;
                        if (dx < 0.0f) dx = 0.0f;
                        if (dy < 0.0f) dy = 0.0f;
                        if (dx * dx + dy * dy <= explosionRadius * explosionRadius) {
                            broken = true;
                            break;
                        }
                    }
                    if (broken) {
                        SpawnBreakParticles(r.x - 16.0f, r.y - 16.0f);
                        r.active = false;
                        r.landed = false;
                        continue;
                    }
                    if (r.landed) continue;

                    if (!r.falling) {
                        --r.warningTimer;
                        if (r.warningTimer <= 0) r.falling = true;
                        continue;
                    }

                    // 半径32pxの岩。重力と落下速度上限
                    r.velocityY += 0.65f;
                    if (r.velocityY > 18.0f) r.velocityY = 18.0f;
                    float nextY = r.y + r.velocityY;

                    // 地形と着地済みの岩の両方を床として扱う。
                    // 1pxずつ進めて、下の岩にめり込まず上に積み重なるようにする。
                    bool landedNow = false;
                    float travel = nextY - r.y;
                    while (travel > 0.0f) {
                        float step = travel > 1.0f ? 1.0f : travel;
                        float candidateY = r.y + step;
                        bool blocked = false;

                        // 画面外の上側は衝突とみなさない
                        if (candidateY >= 32.0f &&
                            CheckBossMapCollision(r.x, candidateY, 64.0f, 64.0f)) {
                            blocked = true;
                        }

                        // 先に着地した岩の上に乗る
                        for (int j = 0; j < kFallingRockCount && !blocked; ++j) {
                            if (j == i || !fallingRocks[j].active || !fallingRocks[j].landed) continue;
                            const FallingRock& other = fallingRocks[j];
                            if (fabsf(r.x - other.x) < 64.0f &&
                                fabsf(candidateY - other.y) < 64.0f) {
                                blocked = true;
                            }
                        }

                        if (blocked) {
                            r.velocityY = 0.0f;
                            r.landed = true;
                            landedNow = true;
                            break;
                        }
                        r.y = candidateY;
                        travel -= step;
                    }
                    if (landedNow) continue;

                    // プレイヤーと接触：落石は砕け、プレイヤーは吹き飛ぶ
                    if (fabsf(player.x - r.x) < playerWidth / 2.0f + 32.0f &&
                        fabsf(player.y - r.y) < playerHeight / 2.0f + 32.0f) {
                        if (fallingRockHitCooldown == 0) {
                            velocityY = -16.0f;
                            velocityX = player.x < r.x ? -12.0f : 12.0f;
                            fallingRockHitCooldown = 35;
                            shake.backGroundFlag = true;
                        }
                        // 接触しても落石は残る（ノックバックのみ）
                    }
                }
            }
        }

        //====================
        // 左右からの岩挟み込み攻撃
        //====================
        if (scene == SCENE_GAME2) {
            if (rockHitCooldown > 0) --rockHitCooldown;

            if (!boss.isAlive) {
                rockPhase = 0;
                rockLeftAlive = false;
                rockRightAlive = false;
            }
            else {
                if (rockPhase == 0) {
                    // 既存の壁攻撃と重ならないよう、壁攻撃が終わった時だけ開始
                    ++rockAttackTimer;
                    if (rockAttackTimer >= 420 && bossWallX < 0 &&
                        bossWallTimer < bossWallInterval - 60) {
                        rockAttackTimer = 0;
                        rockPhase = 1;
                        rockPhaseTimer = 0;
                        rockLeftX = -rockWidth;
                        rockRightX = 1280.0f;
                        rockTargetX = player.x;
                        // ステージ内の位置に制限
                        if (rockTargetX < 150.0f) rockTargetX = 150.0f;
                        if (rockTargetX > 1130.0f) rockTargetX = 1130.0f;
                        rockLeftAlive = true;
                        rockRightAlive = true;
                    }
                }
                else {
                    ++rockPhaseTimer;
                    if (rockPhase == 1 && rockPhaseTimer >= 60) {
                        rockPhase = 2; rockPhaseTimer = 0;
                    }
                    else if (rockPhase == 2) {
                        // 予告時のプレイヤー位置を左右から挟む。
                        // 目標は移動中に更新しない（移動で回避可能）。
                        const float rockSpeed = 12.0f;
                        const float leftGoal = rockTargetX - rockWidth;
                        const float rightGoal = rockTargetX;
                        if (rockLeftX < leftGoal) rockLeftX += rockSpeed;
                        if (rockRightX > rightGoal) rockRightX -= rockSpeed;
                        if (rockLeftX > leftGoal) rockLeftX = leftGoal;
                        if (rockRightX < rightGoal) rockRightX = rightGoal;

                        // 両方が目標地点に到達したら、停止せずその場で破壊
                        if (rockLeftX >= leftGoal && rockRightX <= rightGoal) {
                            if (rockLeftAlive) {
                                for (int j = 0; j < 3; ++j) {
                                    SpawnBreakParticles(rockLeftX + j * kTileSize,
                                        rockY + (j % 2) * 2 * kTileSize);
                                }
                                rockLeftAlive = false;
                            }
                            if (rockRightAlive) {
                                for (int j = 0; j < 3; ++j) {
                                    SpawnBreakParticles(rockRightX + j * kTileSize,
                                        rockY + (j % 2) * 2 * kTileSize);
                                }
                                rockRightAlive = false;
                            }
                            rockPhase = 0;
                            rockPhaseTimer = 0;
                        }
                    }

                    // 爆発した爆弾が岩に当たれば、その側の岩を破壊
                    if (rockPhase == 2) {
                        for (int i = 0; i < kBombCount; ++i) {
                            if (!bombs[i].isActive || !bombs[i].isExplosion) continue;
                            float bx = bombs[i].x, by = bombs[i].y;
                            float nearestY = (by < rockY) ? rockY :
                                ((by > rockY + rockHeight) ? rockY + rockHeight : by);
                            if (rockLeftAlive) {
                                float nearestX = (bx < rockLeftX) ? rockLeftX :
                                    ((bx > rockLeftX + rockWidth) ? rockLeftX + rockWidth : bx);
                                float dx = bx - nearestX, dy = by - nearestY;
                                if (dx * dx + dy * dy < explosionRadius * explosionRadius) {
                                    rockLeftAlive = false;
                                    SpawnBreakParticles(rockLeftX + rockWidth / 2, rockY + rockHeight / 2);
                                }
                            }
                            if (rockRightAlive) {
                                float nearestX = (bx < rockRightX) ? rockRightX :
                                    ((bx > rockRightX + rockWidth) ? rockRightX + rockWidth : bx);
                                float dx = bx - nearestX, dy = by - nearestY;
                                if (dx * dx + dy * dy < explosionRadius * explosionRadius) {
                                    rockRightAlive = false;
                                    SpawnBreakParticles(rockRightX + rockWidth / 2, rockY + rockHeight / 2);
                                }
                            }
                        }
                    }

                    // 岩が触れたら中央方向へ吹き飛ばす（連続ヒット防止）
                    if (rockPhase == 2 && rockHitCooldown == 0) {
                        float pl = player.x - playerWidth / 2;
                        float pr = player.x + playerWidth / 2;
                        float pt = player.y - playerHeight / 2;
                        float pb = player.y + playerHeight / 2;
                        if (pb > rockY && pt < rockY + rockHeight) {
                            if (rockLeftAlive && pr > rockLeftX && pl < rockLeftX + rockWidth) {
                                player.x = rockLeftX + rockWidth + playerWidth / 2 + 1.0f;
                                velocityX = 15.0f; velocityY = -12.0f;
                                rockHitCooldown = 35;
                                shake.backGroundFlag = true;
                            }
                            else if (rockRightAlive && pr > rockRightX && pl < rockRightX + rockWidth) {
                                player.x = rockRightX - playerWidth / 2 - 1.0f;
                                velocityX = -15.0f; velocityY = -12.0f;
                                rockHitCooldown = 35;
                                shake.backGroundFlag = true;
                            }
                        }
                    }
                }
            }
        }

        //====================
        // ボス戦の更新
        //====================
        if (scene == SCENE_GAME2) {

            // 壁攻撃の予告・せり上がり・接触ノックバック
            if (playerWallHitCooldown > 0) --playerWallHitCooldown;
            if (boss.isAlive) {
                ++bossWallTimer;
                // 予告開始時に攻撃位置を確定（途中でプレイヤーが動いても追わない）
                if (bossWallTimer == bossWallInterval) {
                    bossWallX = (int)(player.x / kTileSize);
                    if (bossWallX < 2) bossWallX = 2;
                    if (bossWallX > kBossMapWidth - 3) bossWallX = kBossMapWidth - 3;
                    bossWallRiseCount = 0;
                }
                if (bossWallX >= 0 && bossWallTimer >= bossWallInterval + bossWallWarning) {
                    int elapsed = bossWallTimer - (bossWallInterval + bossWallWarning);
                    int wanted = 1 + elapsed / bossWallRiseStep;
                    if (wanted > 3) wanted = 3;
                    while (bossWallRiseCount < wanted) {
                        int tileY = 19 - bossWallRiseCount; // 下から上へ
                        if (bossMap[tileY][bossWallX] == 0) {
                            bossMap[tileY][bossWallX] = 3;
                        }
                        ++bossWallRiseCount;
                    }
                    // 壁がせり上がっている間だけプレイヤーを吹き飛ばす
                    if (elapsed < 3 * bossWallRiseStep && playerWallHitCooldown == 0) {
                        float wallLeft = bossWallX * (float)kTileSize;
                        float wallRight = wallLeft + kTileSize;
                        float wallTop = (20 - bossWallRiseCount) * (float)kTileSize;
                        float playerLeft = player.x - playerWidth * 0.5f;
                        float playerRight = player.x + playerWidth * 0.5f;
                        float playerTop = player.y - playerHeight * 0.5f;
                        float playerBottom = player.y + playerHeight * 0.5f;
                        if (playerRight > wallLeft && playerLeft < wallRight &&
                            playerBottom > wallTop && playerTop < 640.0f) {
                            // マップに埋まらないよう壁の上に押し出す
                            player.y = wallTop - playerHeight * 0.5f - 0.1f;
                            velocityY = -18.0f;
                            velocityX = (player.x < wallLeft + 16.0f) ? -10.0f : 10.0f;
                            playerWallHitCooldown = 45;
                            shake.backGroundFlag = true;
                        }
                    }
                    if (elapsed >= 3 * bossWallRiseStep) {
                        bossWallTimer = 0;
                        bossWallX = -1;
                        bossWallRiseCount = 0;
                    }
                }
            }

            if (boss.isAlive) {

                // プレイヤーを追跡
                float dx = player.x - boss.x;

                if (dx > 10.0f) {
                    boss.velocityX = 2.0f;
                }
                else if (dx < -10.0f) {
                    boss.velocityX = -2.0f;
                }
                else {
                    boss.velocityX = 0.0f;
                }

                boss.x += boss.velocityX;

                // 画面外に出さない
                if (boss.x < boss.width / 2.0f) {
                    boss.x = boss.width / 2.0f;
                }

                if (boss.x > 1280.0f - boss.width / 2.0f) {
                    boss.x = 1280.0f - boss.width / 2.0f;
                }

                // 無敵時間
                if (boss.damageCooldown > 0) {
                    boss.damageCooldown--;
                }

                // 爆弾の爆発との当たり判定
                if (boss.damageCooldown == 0) {

                    for (int i = 0; i < kBombCount; i++) {

                        if (!bombs[i].isActive ||
                            !bombs[i].isExplosion) {
                            continue;
                        }

                        float bombDx = boss.x - bombs[i].x;
                        float bombDy = boss.y - bombs[i].y;

                        float distance =
                            sqrtf(bombDx * bombDx + bombDy * bombDy);

                        if (distance <
                            explosionRadius + boss.width / 2.0f) {

                            boss.hp--;
                            boss.damageCooldown = 30;

                            if (boss.hp <= 0) {
                                boss.hp = 0;
                                boss.isAlive = false;
                            }

                            break;
                        }
                    }
                }
            }
        }


        //背景の揺れ処理
        if (shake.backGroundFlag) {

            backGroundRandomX = rand() % (shake.amplitude * 2 + 1) - shake.amplitude;
            backGroundRandomY = rand() % (shake.amplitude * 2 + 1) - shake.amplitude;

            shake.duration--;

            if (shake.duration <= 0) {
                shake.backGroundFlag = false;

                //シェイク終了時に元の位置へ戻す
                backGroundRandomX = 0;
                backGroundRandomY = 0;
                //初期化
                shake.duration = 2;
            }
        }

        // Scroll only in the normal stage. Boss arena uses fixed camera.
        if (scene == SCENE_GAME) {
            float cameraTargetX = player.x - 740.0f;
            if (cameraTargetX < 0.0f) cameraTargetX = 0.0f;
            cameraX += (cameraTargetX - cameraX) * 0.1f;
            if (cameraX < 0.0f) cameraX = 0.0f;
            const float maxCameraX = kMapWidth * kTileSize - 1280.0f;
            if (cameraX > maxCameraX) cameraX = maxCameraX;
        }
        else if (scene == SCENE_GAME2) {
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

        // 壊せる壁のパーティクル更新
        for (int i = 0; i < kMaxBreakParticles; i++)
        {
            if (!breakParticles[i].isActive)
            {
                continue;
            }

            breakParticles[i].x += breakParticles[i].velocityX;
            breakParticles[i].y += breakParticles[i].velocityY;

            // 重力
            breakParticles[i].velocityY += 0.25f;

            // 空気抵抗
            breakParticles[i].velocityX *= 0.99f;

            // 寿命
            breakParticles[i].life--;

            if (breakParticles[i].life <= 0)
            {
                breakParticles[i].isActive = false;
            }
        }
        //テスト用
        if (scene == SCENE_GAME && keys[DIK_2] && !preKeys[DIK_2]) {
            scene = SCENE_GAME2;

            player.x = 200.0f;
            player.y = 500.0f;

            velocityX = 0.0f;
            velocityY = 0.0f;
            cameraX = 0.0f;
            for (int i = 0; i < kBombCount; ++i) bombs[i] = Bomb{};
            boss.x = 900.0f;
            boss.y = 580.0f;
            bossWallTimer = 0;
            bossWallX = -1;
            bossWallRiseCount = 0;
            playerWallHitCooldown = 0;
            InitBossMap();
            rockAttackTimer = 0;
            rockPhase = 0;
            rockPhaseTimer = 0;
            rockLeftX = -rockWidth;
            rockRightX = 1280.0f;
            rockTargetX = player.x;
            rockLeftAlive = false;
            rockRightAlive = false;
            rockHitCooldown = 0;
            fallingRockAttackTimer = 0;
            fallingRockHitCooldown = 0;
            for (int i = 0; i < kFallingRockCount; ++i) {
                fallingRocks[i] = FallingRock{};
            }
        }


        ///
        /// ↑更新処理
        ///

        ///
        /// ↓描画処理
        ///
        if (scene == SCENE_TITLE)
        {
            int titleTexture = monge1;

            if (titleSelect == 0)
            {
                titleTexture = monge1;
            }
            else if (titleSelect == 1)
            {
                titleTexture = monge2;
            }
            else if (titleSelect == 2)
            {
                titleTexture = monge3;
            }

            // 選択状態に応じて画像を切り替える
            Novice::DrawSprite(
                0,
                0,
                titleTexture,
                1.0f,
                1.0f,
                0.0f,
                WHITE
            );
        }
        else if (scene == SCENE_GAME)
        {
            //背景
            Novice::DrawBox(
                -50 + backGroundRandomX,
                -50 + backGroundRandomY,
                1500,
                790,
                0.0f,
                0x000000FF,
                kFillModeSolid
            );

            DrawMap(cameraX,
                yukaTexture,
                breakableYukaTexture);

            // 壊せる壁の破片を描画
            for (int i = 0; i < kMaxBreakParticles; i++)
            {
                if (!breakParticles[i].isActive)
                {
                    continue;
                }

                Novice::DrawSpriteRect(
                    (int)(breakParticles[i].x - cameraX) + backGroundRandomX,
                    (int)breakParticles[i].y + backGroundRandomY,
                    breakParticles[i].sourceX,
                    breakParticles[i].sourceY,
                    8,
                    8,
                    breakableYukaTexture,
                    1.0f,
                    1.0f,
                    0.0f,
                    WHITE
                );
            }

            // プレイヤー
            Novice::DrawBox(
                (int)(player.x - cameraX) - 20 + backGroundRandomX,
                (int)player.y - 20 + backGroundRandomY,
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
                        Novice::DrawSprite(
                            screenX - 10 + backGroundRandomX,
                            screenY - 10 + backGroundRandomY,
                            bombTexture,
                            1.0f,
                            1.0f,
                            0.0f,
                            WHITE
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

            for (int j = 0; j < spawnedEnemies; j++) {

                if (enemies[j].isExploding) {

                    float progress =
                        1.0f - enemies[j].explosionTimer / 15.0f;

                    int radius = (int)(20.0f + progress * 100.0f);

                    Novice::DrawEllipse(
                        (int)(enemies[j].x - cameraX),
                        (int)enemies[j].y,
                        radius,
                        radius,
                        0.0f,
                        0xFF880088,
                        kFillModeSolid
                    );
                }
            }

            // 追跡型の敵（赤い四角）
            for (int e = 0; e < spawnedEnemies; ++e)
                if (enemies[e].isAlive)
                {
                    Novice::DrawBox(
                        (int)(enemies[e].x - cameraX - 20.0f) + backGroundRandomX,
                        (int)(enemies[e].y - 20.0f) + backGroundRandomY,
                        40, 40, 0.0f, 0xFF4444FF, kFillModeSolid
                    );
                }

            // プレイヤーの当たり判定の描画
            Novice::DrawBox(
                (int)(player.x - cameraX - playerWidth / 2.0f) + backGroundRandomX,
                (int)(player.y - playerHeight / 2.0f) + backGroundRandomY,
                (int)playerWidth,
                (int)playerHeight,
                0.0f,
                RED,
                kFillModeWireFrame
            );

        }
        else if (scene == SCENE_GAME2)
        {
            Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x202030FF, kFillModeSolid);
            DrawBossMap(yukaTexture, breakableYukaTexture);

            // 落石予告と落下する岩の描画
            for (int i = 0; i < kFallingRockCount; ++i) {
                const FallingRock& r = fallingRocks[i];
                if (!r.active) continue;
                if (!r.falling) {
                    unsigned int warningColor = (r.warningTimer / 6) % 2 == 0
                        ? 0xFF3333AA : 0xFF333344;
                    Novice::DrawBox((int)(r.x - 32.0f), 620, 64, 20,
                        0.0f, warningColor, kFillModeSolid);
                    Novice::DrawLine((int)r.x, 0, (int)r.x, 620, 0xFF555566);
                }
                else {
                    // 64x64の岩（壊せる壁画像を4枚使用）
                    for (int ty = 0; ty < 2; ++ty) {
                        for (int tx = 0; tx < 2; ++tx) {
                            Novice::DrawSprite(
                                (int)(r.x - 32.0f) + tx * kTileSize,
                                (int)(r.y - 32.0f) + ty * kTileSize,
                                breakableYukaTexture, 1.0f, 1.0f, 0.0f, WHITE);
                        }
                    }
                }
            }

            // 岩攻撃の予告：左右の侵入方向と狙われた位置を点滅表示
            if (boss.isAlive && rockPhase == 1) {
                unsigned int c = (rockPhaseTimer / 7) % 2 == 0
                    ? 0xFF3333AA : 0xFF333344;
                Novice::DrawBox(32, (int)rockY, 90, (int)rockHeight,
                    0.0f, c, kFillModeSolid);
                Novice::DrawBox(1158, (int)rockY, 90, (int)rockHeight,
                    0.0f, c, kFillModeSolid);
                Novice::DrawBox((int)(rockTargetX - 3.0f), (int)rockY,
                    6, (int)rockHeight, 0.0f, c, kFillModeSolid);
                Novice::ScreenPrintf(30, 455, "ROCK ATTACK!");
                Novice::ScreenPrintf(1110, 455, "ROCK ATTACK!");
            }
            // 岩の本体：壊せる壁と同じテクスチャを3列×5段で描画
            if (rockPhase == 2) {
                for (int side = 0; side < 2; ++side) {
                    bool alive = side == 0 ? rockLeftAlive : rockRightAlive;
                    float x = side == 0 ? rockLeftX : rockRightX;
                    if (!alive) continue;
                    for (int ry = 0; ry < 5; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            Novice::DrawSprite((int)x + rx * kTileSize,
                                (int)rockY + ry * kTileSize,
                                breakableYukaTexture, 1.0f, 1.0f, 0.0f, WHITE);
                        }
                    }
                }
            }
            // 壁生成の予告：攻撃列を赤く点滅させる
            if (boss.isAlive && bossWallX >= 0 &&
                bossWallTimer < bossWallInterval + bossWallWarning) {
                int warningX = bossWallX * kTileSize;
                unsigned int warningColor = ((bossWallTimer / 8) % 2 == 0)
                    ? 0xFF3333AA : 0xFF333355;
                Novice::DrawBox(warningX, 544, kTileSize, 96,
                    0.0f, warningColor, kFillModeSolid);
                Novice::ScreenPrintf(warningX - 8, 520, "DANGER!");
            }


            // Player (world coordinates, fixed camera).
            Novice::DrawBox(
                (int)(player.x - playerWidth / 2.0f),
                (int)(player.y - playerHeight / 2.0f),
                (int)playerWidth, (int)playerHeight,
                0.0f, 0x00AAFFFF, kFillModeSolid);

            // Bombs and explosions.
            for (int i = 0; i < kBombCount; ++i) {
                if (!bombs[i].isActive) continue;
                int bx = (int)bombs[i].x;
                int by = (int)bombs[i].y;
                if (!bombs[i].isExplosion) {
                    Novice::DrawSprite(bx - 10, by - 10, bombTexture,
                        1.0f, 1.0f, 0.0f, WHITE);
                }
                else {
                    float progress = 1.0f -
                        (float)bombs[i].explosionTimer / explosionDuration;
                    int size = (int)(explosionRadius * 2.0f * progress);
                    Novice::DrawBox(bx - size / 2, by - size / 2,
                        size, size, 0.0f, 0xFFAA00FF, kFillModeSolid);
                }
            }

            // ボス描画
            if (boss.isAlive) {

                Novice::DrawBox(
                    (int)(boss.x - boss.width / 2.0f),
                    (int)(boss.y - boss.height / 2.0f),
                    (int)boss.width,
                    (int)boss.height,
                    0.0f,
                    0xAA3333FF,
                    kFillModeSolid
                );

                // ボスのコア
                Novice::DrawEllipse(
                    (int)boss.x,
                    (int)boss.y,
                    25, 25,
                    0.0f,
                    0xFFFF00FF,
                    kFillModeSolid
                );
            }

            // HPバーの背景
            Novice::DrawBox(
                390, 40, 500, 30,
                0.0f,
                0x444444FF,
                kFillModeSolid
            );

            // HPバー
            Novice::DrawBox(
                390, 40,
                500 * boss.hp / boss.maxHp,
                30,
                0.0f,
                0xFF3333FF,
                kFillModeSolid
            );

            Novice::ScreenPrintf(
                390, 15,
                "BOSS HP : %d / %d",
                boss.hp, boss.maxHp
            );
        }
        ///
        /// ↑描画処理
        ///


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