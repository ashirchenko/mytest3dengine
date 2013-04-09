#pragma once

namespace core_private
{
	class Timer
	{
	public:

		Timer( void );

		void getFrequency( void );
		double getCurrentTime( void );

	private:

		double secPerUnit;
	};
}
