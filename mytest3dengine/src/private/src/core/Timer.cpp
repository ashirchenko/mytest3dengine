#include "../../include/Core/Timer.h"

#include <Windows.h>

namespace core_private
{
	Timer::Timer( void )
		: secPerUnit( 0 )
	{

	}

	void Timer::getFrequency( void )
	{
		long long int frequency = 0;
		QueryPerformanceFrequency( (LARGE_INTEGER*)&frequency );
		secPerUnit = 1.0 / (double)frequency;
	}

	double Timer::getCurrentTime()
	{
		long long int tics;
		QueryPerformanceCounter( (LARGE_INTEGER*)&tics );
		return secPerUnit * tics;
	}
}
