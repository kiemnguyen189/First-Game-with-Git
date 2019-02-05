// First Game with Git.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SDL.h"
#include "pch.h"
#include <iostream>


using namespace std;
using std::cout;


int main(int argc, char *argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *sdlWindow;// = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_SHOWN);
	SDL_Renderer *sdlRenderer;// = SDL_CreateRenderer(sdlWindow, -1, 0);
	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &sdlWindow, &sdlRenderer);

	SDL_SetRenderDrawColor(sdlRenderer, 0, 255, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(sdlRenderer, 640, 480);

	SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 640, 480);

	SDL_Surface *image = SDL_LoadBMP("640 x 480 grid32.bmp");
	//extern Uint32 &image;

	SDL_UpdateTexture(sdlTexture, NULL, image, 640 * sizeof(Uint32));

	SDL_RenderClear(sdlRenderer);
	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
	SDL_RenderPresent(sdlRenderer);

	SDL_Delay(2000);

	// PC TEST
    //cout << "Hello World!\n"; 

	// LAPTOP TEST
	return 0;
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
