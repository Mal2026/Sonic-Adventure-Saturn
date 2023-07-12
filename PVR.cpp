#include "pch.h"
#include "mod.h"

#define ReplacePNG_Common(a) \
             _snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\PVR\\index.txt", path); \
             helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \

void PVR_GUI(const char* path, const HelperFunctions& helperFunctions)
{
    char pathbuf[MAX_PATH];

    ReplacePNG_Common("ST_064S_SCORE");
    ReplacePNG_Common("HYOJI_BALLS_E");
}

void PVR_EMBLEM(const char* path, const HelperFunctions& helperFunctions)
{
    char pathbuf[MAX_PATH];

    ReplacePNG_Common("HYOJI_EMBLEM0");
    ReplacePNG_Common("HYOJI_EMBLEM1");
}

void PVR_TitleCards(const char* path, const HelperFunctions& helperFunctions)
{
    char pathbuf[MAX_PATH];

    ReplacePNG_Common("S_STAGE01_E");
    ReplacePNG_Common("S_STAGE02_E");
    ReplacePNG_Common("S_STAGE03_E");
    ReplacePNG_Common("S_STAGE04_E");
    ReplacePNG_Common("S_STAGE05_E");
    ReplacePNG_Common("S_STAGE06_E");
    ReplacePNG_Common("S_STAGE07_E");
    ReplacePNG_Common("S_STAGE08_E");
    ReplacePNG_Common("S_STAGE09_E");
    ReplacePNG_Common("S_STAGE10_E");

}
