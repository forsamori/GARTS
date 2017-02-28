#ifndef _HELPER_FUNCTIONS_H
#define _HELPER_FUNCTIONS_H

#include <windows.h>
#include <sstream>

enum UI_TYPE
{
	UI_SPAWN,
	UI_ORDER,
};

struct vec2
{
	int x;
	int y;
};

struct vec2f
{
	float x;
	float y;
};

inline void Debug_String(char* string)
{
	std::wostringstream out_stream;
	out_stream << string;
	out_stream << "\n\n";
	OutputDebugStringW(out_stream.str().c_str());
}

inline int Lerp(float t, int a, int b)
{
	//return (1 - t)*a + t*b;
	return (a + t*(b - a));
}


#endif