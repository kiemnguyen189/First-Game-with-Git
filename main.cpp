// First Game with Git.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;
using std::cout;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

SDL_Surface* loadSurface(string path) {
	SDL_Surface* loaded = SDL_LoadBMP(path.c_str());
	if (loaded == NULL) {
		printf("FAILED TO LOAD: ", path.c_str(), SDL_GetError());
	}
	return loaded;
}

int main(int argc, char *argv[])
{
	bool quit = false;

	SDL_Surface* gKeyPress[KEY_PRESS_SURFACE_TOTAL];

	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Surface *surface = nullptr;
	SDL_Texture *texture = nullptr;
	SDL_Event event;

	SDL_Rect srcRect;
	SDL_Rect dimensionRect; //can stretch

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 640;
	srcRect.h = 480;

	dimensionRect.x = 0;
	dimensionRect.y = 0;
	dimensionRect.w = 640;
	dimensionRect.h = 480;


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 1;
	}

	if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 1;
	}

	surface = SDL_LoadBMP("640 x 480 grid32.bmp");
	if (!surface) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
		return 1;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
		return 1;
	}

	SDL_FreeSurface(surface);
	surface = nullptr;

	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_SPACE) {
					cout << "SPACE" << endl;
				}
				else {
					cout << "DOWN" << endl;
				}
				
			}
			//gKeyPress[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "Base character.bmp" );

			//SDL_SetRenderDrawColor(renderer, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, texture, NULL, &dimensionRect);
			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Delay(2000);

	SDL_Quit();

	return 0;

	// VSCODE TEST
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
