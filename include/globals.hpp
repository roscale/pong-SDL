#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <SDL2pp/SDL2pp.hh>
#include "Vector2D.hpp"
#include "Timer.hpp"

using namespace SDL2pp;

extern SDL sdl;
extern Window gWindow;
extern Vector2D windowCenter;
extern Renderer gRenderer;
extern Timer gTimer;
extern Font scoreFont;



#endif /* end of include guard: GLOBALS_HPP */
