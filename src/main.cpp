#include <raylib.h>
#include <cstring>

#include <cxxopts.hpp>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#include "Game.hpp"

const char* gameName = "Test Game";
const char* gameDescription = "A test game";
int screenWidth = 1280;
int screenHeight = 720;
bool fullscreen = false;
bool borderless = false;

bool msaa = true;
bool vSync = true;

Game* game;
double currentTime = 0.0;
double previousTime = 0.0;

void GameLoop();

int main(int argc, char* argv[])
{
    cxxopts::Options options(gameName, gameDescription);
    options.add_options()
        ("f,fullscreen", "Fullscreen", cxxopts::value<bool>(fullscreen)->default_value("false"))
        ("b,borderless", "Borderless", cxxopts::value<bool>(borderless)->default_value("false"))
        ("width", "Width", cxxopts::value<int>(screenWidth))//->default_value("1280"))
        ("height", "Height", cxxopts::value<int>(screenHeight))//->default_value("720"))
        ("m,msaa", "MSAA", cxxopts::value<bool>(msaa)->default_value("true"))
        ("v,vsync", "VSync", cxxopts::value<bool>(vSync)->default_value("true"))
        ("h,help", "Print usage")
        ;

    auto result = options.parse(argc, argv);


    if (msaa)
        SetConfigFlags(FLAG_MSAA_4X_HINT);

#if defined(PLATFORM_WEB)
    InitWindow(screenWidth, screenHeight, gameName);
    emscripten_set_main_loop(GameLoop, 0, 1);
#else
    InitWindow(screenWidth, screenHeight, gameName);
    if (vSync)
        SetWindowState(FLAG_VSYNC_HINT);

    if (borderless)
    {
        SetWindowState(FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_MAXIMIZED);
        SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
        SetWindowPosition(0, 0);
    } else if (fullscreen)
    {
        SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
        SetWindowState(FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE);
    }

    SetExitKey(KEY_ESCAPE);

    game = new Game();
    game->Init();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        GameLoop();
    }
#endif

    delete game;

    CloseWindow();

    return 0;
}

void GameLoop()
{
    game->Update(GetFrameTime());
    game->Render();
}
