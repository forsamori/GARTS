#ifndef _HELPER_FUNCTIONS_H
#define _HELPER_FUNCTIONS_H

#include <windows.h>
#include <sstream>

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

inline float randf()
{ 
	float result = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 100.0f);
	return result;
}
inline float randf_ext(float min = 0.0f, float max = 100.0f)
{
	float result = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	return result;
}


#endif