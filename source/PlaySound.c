#include "PlaySound.h"
#include <stdio.h>


void LoadAudio(Window* sdlWindow)
{
    // Load the wav file
    if (!SDL_LoadWAV("media/chess_move_sound.wav",
                    &sdlWindow->spec,
                    &sdlWindow->audioBuffer,
                    &sdlWindow->audioLength))
    { 
        printf("Could not load audio file: %s\n", SDL_GetError());
        return;
    }

    sdlWindow->audioDevice = SDL_OpenAudioDevice(NULL, 0, &sdlWindow->spec, NULL, 0);
}

void PlaySound(Window* sdlWindow)
{
    SDL_QueueAudio(sdlWindow->audioDevice, sdlWindow->audioBuffer, sdlWindow->audioLength);
    SDL_PauseAudioDevice(sdlWindow->audioDevice, 0);
}

