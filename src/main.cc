#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

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
    SDL_WaitEvent(&event);
    switch (event.type) {
      case SDL_EVENT_QUIT:
      {
        is_running = false;
        break;
      }
      case SDL_EVENT_WINDOW_EXPOSED:
      {
        SDL_SetRenderDrawColor(renderer, 16, 0, 16, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        break;
      }
    }
  }


  return 0;
}
