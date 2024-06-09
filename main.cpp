#include <SDL2/SDL.h>
#include <iostream>

// Screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Player dimensions and speed
const int PLAYER_WIDTH = 50;
const int PLAYER_HEIGHT = 50;
const int PLAYER_SPEED = 5;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("2D Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Player position
    int playerX = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2;
    int playerY = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2;

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // Main game loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            // Handle input for player
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        playerY -= PLAYER_SPEED;
                        break;
                    case SDLK_DOWN:
                        playerY += PLAYER_SPEED;
                        break;
                    case SDLK_LEFT:
                        playerX -= PLAYER_SPEED;
                        break;
                    case SDLK_RIGHT:
                        playerX += PLAYER_SPEED;
                        break;
                }
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Render player
        SDL_Rect fillRect = { playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT };
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF); // Blue color
        SDL_RenderFillRect(renderer, &fillRect);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
