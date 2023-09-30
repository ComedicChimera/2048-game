#include "game.hpp"

#include "time.h"

Game::Game(Renderer& renderer)
: renderer_(renderer)
{
    calcBoardSites();

    tryFindTileSpawn();
    state_ = GameState::ANIM_SPAWN_TILE;
}

void Game::Run() {
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                return;
        }

        renderer_.Clear();

        handleInput();

        switch (state_) {
        case GameState::PLAYING:
            updateLogic();
            break;
        case GameState::ANIM_SHIFT:
            animateShift();
            break;
        case GameState::ANIM_MERGE:
            animateMerge();
            break;
        case GameState::ANIM_SPAWN_TILE:
            animateSpawnTile();
            break;
        case GameState::WON:
        case GameState::LOST:
            if (hitSpace()) {
                resetGame();
            }
            break;
        }

        draw();

        renderer_.Present();
    }
}

/* -------------------------------------------------------------------------- */

int main() {
    srand(time(nullptr));

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        reportSDLError("initializing SDL");
        return -1;
    }

    if (TTF_Init() < 0) {
        reportSDLError("initializing TTF library");
        SDL_Quit();
        return -1;
    }

    Renderer renderer;
    if (!renderer.Init()) {
        return -1;
    }

    Game game(renderer);
    game.Run();

    return 0;
}