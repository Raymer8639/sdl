#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <array>
#include <cstdint>
#include <vector>

int main(int argc, char** argv)
{

  std::array<SDL_Vertex, 3> sjx;
  sjx = {
    SDL_Vertex { { 150, 100 }, { 1.0f, 0.0f, 0.0f, 1.0f } },
    SDL_Vertex { { 000, 300 }, { 0.0f, 1.0f, 0.0f, 1.0f } },
    SDL_Vertex { { 300, 300 }, { 0.0f, 0.0f, 1.0f, 1.0f } }
  };
  uint64_t last_tickets = SDL_GetTicks();
  float pos = 0.0f;
  float dire = 1.0f;


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
    uint64_t current_ticks = SDL_GetTicks();
    float delta_time = (current_ticks - last_tickets) / 1000.0f;
    last_tickets = current_ticks;
    pos += 200.0f * delta_time * dire;

    int width = 0;

    SDL_GetRenderOutputSize(renderer, &width, 0);

    float max_pos = static_cast<float>(width) - (sjx[2].position.x - sjx[1].position.x);

    if (pos > max_pos)
      dire = -1.0f;
    else if (pos < 0.0f)
    {
      pos = 0.0f;
      dire = 1.0f;
    }

    std::vector<SDL_Vertex> vertices;
    for (const auto& vertex : sjx)
    {
      vertices.push_back(vertex);
      vertices.back().position.x += pos;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderGeometry(renderer, 0, sjx.data(), sjx.size(), 0, 0);
    SDL_RenderPresent(renderer);
  }


  return 0;
}
