#include "Timings.h"

Timings::Timings()
{
	lastFrameTime = SDL_GetTicks();
	lastFootstepTime = SDL_GetTicks();
}

float Timings::FrameUpdate()
{
	auto currentTime = SDL_GetTicks();
	auto delta = (currentTime - lastFrameTime) / 1000.0f;
	lastFrameTime = currentTime;
	return delta;
}

bool Timings::CanPlayFootstep()
{
	auto currentTime = SDL_GetTicks();
	if ((currentTime - lastFootstepTime) > 350){
		lastFootstepTime = SDL_GetTicks();
		return true;
	} 
	return false;

}

Timings::~Timings()
{


}
