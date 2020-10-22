//============================================================================
// Name        : 3333.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>

#include <SDL2/SDL.h>

constexpr double Pi = acos(-1.);

#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr int WIDTH = 800, HEIGHT = 600;



int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	auto win = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
						"Yo!",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT,
						SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (win == nullptr) {
		std::cerr << "Error creating windows: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (ren == nullptr) {
		std::cerr << "Error creating renderer: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Event event;

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(),48, 48, 48, 48);
		SDL_RenderClear(ren.get());

		SDL_SetRenderDrawColor(ren.get(), 0xFF, 0x00, 0xFF, 0xFF);

	    SDL_Rect r;
	    r.x = 350;
	    r.y = 300;
	    r.w = 200;
	    r.h = 200;
	    SDL_RenderDrawRect(ren.get(), &r);

	    SDL_Rect r2;
	    r2.x = 410;
	    r2.y = 350;
	    r2.w = 70;
	    r2.h = 70;
	    SDL_RenderDrawRect(ren.get(), &r2);


	    SDL_RenderDrawLine(ren.get(), 350, 300, 450, 200);
	    SDL_RenderDrawLine(ren.get(), 550, 300, 450, 200);

	    SDL_RenderDrawLine(ren.get(), 350, 300, 150, 250);
	    SDL_RenderDrawLine(ren.get(), 150, 250, 250, 150);
	    SDL_RenderDrawLine(ren.get(), 250, 150, 450, 200);
	    SDL_RenderDrawLine(ren.get(), 350, 500, 150, 450);
	    SDL_RenderDrawLine(ren.get(), 150, 450, 150, 250);

	    SDL_RenderDrawLine(ren.get(), 310, 320, 240, 302);
	    SDL_RenderDrawLine(ren.get(), 310, 470, 310, 320);
	    SDL_RenderDrawLine(ren.get(), 310, 470, 240, 452);
	    SDL_RenderDrawLine(ren.get(), 240, 452, 240, 302);

	    SDL_RenderDrawLine(ren.get(), 500, 250, 500, 210);
	    SDL_RenderDrawLine(ren.get(), 500, 210, 520, 210);
	    SDL_RenderDrawLine(ren.get(), 520, 210, 520, 269);



		int x0 = 450;
		int y0 = 260;
		int radius =20;
		int x = 0;
		int y = radius;
		int delta = 1 - 2 * radius;
		int error = 0;
		while(y >= 0) {
			SDL_RenderDrawPoint(ren.get(),x0 + x, y0 + y);
			SDL_RenderDrawPoint(ren.get(),x0 + x, y0 - y);
			SDL_RenderDrawPoint(ren.get(),x0 - x, y0 + y);
			SDL_RenderDrawPoint(ren.get(),x0 - x, y0 - y);
			error = 2 * (delta + y) - 1;
			if(delta < 0 && error <= 0) {
				++x;
				delta += 2 * x + 1;
				continue;
			}
			error = 2 * (delta - x) - 1;
			if(delta > 0 && error > 0) {
				--y;
				delta += 1 - 2 * y;
				continue;
			}
			++x;
			delta += 2 * (x - y);
			--y;
		}





		SDL_RenderPresent(ren.get());
	}



	return 0;
}










