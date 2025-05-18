#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <array>

int main(int argc, char** argv)
{
  SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("hello!", 800, 600, SDL_WINDOW_RESIZABLE);
  SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

  bool is_running = true;
  SDL_Event event {};
  while(is_running)
  {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_QUIT:
        {
          is_running = false;
          break;
        }
      }
    }
    std::array<SDL_Vertex, 3> sjx;
    sjx = {
      SDL_Vertex { { 150, 100 }, { 1.0f, 0.0f, 0.0f, 1.0f } },
      SDL_Vertex { { 000, 300 }, { 0.0f, 1.0f, 0.0f, 1.0f } },
      SDL_Vertex { { 300, 300 }, { 0.0f, 0.0f, 1.0f, 1.0f } }
    };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderGeometry(renderer, 0, sjx.data(), sjx.size(), 0, 0);
    SDL_RenderPresent(renderer);
  }


  return 0;
}
