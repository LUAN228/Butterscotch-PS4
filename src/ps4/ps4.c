#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// PS4 platform entry point for Butterscotch runner
int main(int argc, char *argv[]) {
    printf("Starting Butterscotch on PlayStation 4...\n");

    // Initialize SDL2 with video, audio, and controller support
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) < 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window and OpenGL ES context for PS4 hardware acceleration
    SDL_Window *window = SDL_CreateWindow(
        "Butterscotch PS4",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1920, 1080,
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN
    );

    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if (!gl_context) {
        fprintf(stderr, "SDL_GL_CreateContext Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    printf("PS4 graphics and window context initialized successfully!\n");

    // Main loop stub for asset loading and execution
    // (Here is where data.win parsing and game loop hooks will be attached)

    // Cleanup and exit
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
