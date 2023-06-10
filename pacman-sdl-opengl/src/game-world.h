#ifndef __PACMAN_SDL_OPENGL_GAMEWORLD_HEADER_H__
#define __PACMAN_SDL_OPENGL_GAMEWORLD_HEADER_H__

#ifdef __MINGW32__
	#define SDL_MAIN_HANDLED
#endif

#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <stdint.h>

#include "lib.h"
#include "opengl.h"
#include "game-object.h"

// ---------------------------------------------------

class game_world_t;

// ---------------------------------------------------

class game_main_t
{
protected:
	OO_ENCAPSULATE(SDL_Window*, sdl_window)
	OO_ENCAPSULATE(SDL_GLContext, sdl_gl_context)
	OO_ENCAPSULATE(uint32_t, screen_width_px)
	OO_ENCAPSULATE(uint32_t, screen_height_px)
	OO_ENCAPSULATE(game_world_t*, game_world)
	OO_ENCAPSULATE_READONLY(opengl_circle_factory_t*, opengl_circle_factory_low_def)
	OO_ENCAPSULATE_READONLY(opengl_circle_factory_t*, opengl_circle_factory_high_def)

public:
	game_main_t ();
	~game_main_t ();
	void run ();
};

// ---------------------------------------------------

class game_world_t
{
protected:
	// the screen coordinates here are in game world coords (not opengl, neither pixels)
	// every unit corresponds to a tile
	OO_ENCAPSULATE_READONLY(float, screen_width)
	OO_ENCAPSULATE_READONLY(float, screen_height)
	//OO_ENCAPSULATE(float, world_to_opengl_conversion)

	OO_ENCAPSULATE_READONLY(opengl_program_triangle_t*, opengl_program_triangle)
	OO_ENCAPSULATE_READONLY(GLuint, vao) // vertex array descriptor id
	OO_ENCAPSULATE_READONLY(GLuint, vbo) // vertex buffer id

	OO_ENCAPSULATE_REFERENCE_READONLY(game_player_t*, player)

public:
	game_world_t ();
	~game_world_t ();

	void bind_vertex_array ();
	void bind_vertex_buffer ();
};

// ---------------------------------------------------

extern game_main_t *game_main;

#endif