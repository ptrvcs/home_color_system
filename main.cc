// #include <iostream>
// #include <cmath>   // for std::sin and M_PI

// int main() {
//     const double amplitude = 10.0;   // starting maximum wave height
//     const double decay = 0.95;       // how much the wave shrinks each cycle
//     const double frequency = 0.2;    // speed of oscillation (controls wave length)

//     double value = amplitude;        // current amplitude

//     for (int t = 0; t < 100; ++t) {
//         // compute echo wave = sine * current amplitude
//         double echo = value * std::sin(frequency * t);

//         std::cout << "t=" << t << " value=" << echo << std::endl;

//         // reduce amplitude slightly after each step (like fading sound)
//         value *= decay;
//     }

//     return 0;
// }


#include "SDL.h"
#include <cmath>
#include <iostream>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Sine Wave",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (int x = 0; x < 800; ++x) {
            int y = 300 + static_cast<int>(100 * std::sin(x * 0.02));
            SDL_RenderDrawPoint(renderer, x, y);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
