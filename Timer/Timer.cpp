#include "Timer.h"
#include<thread>
#include<chrono>

Timer::timer::timer() : active(false)
{
}

Timer::timer::timer(int t) : active(false)
{
}

Timer::timer::~timer()
{
	active = false;
}

void Timer::timer::setInterval(function cb_function, int miliSec)
{
	if (active.load())
		return;

	active = true;

	std::thread timerThread([=]() {
		while (active.load())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(miliSec));

			if (!active.load())
				return;

			cb_function();
		}
		});

	timerThread.detach();
}

void Timer::timer::setTimeOut(function cb_function, int milisec)
{
	if (active.load())
		return;

	active = true;

	std::thread timerThread([=]() {
		if (!active.load())
			return;

		std::this_thread::sleep_for(std::chrono::milliseconds(milisec));

		if (!active.load())
			return;

		cb_function();
		active = false;
		});

	timerThread.detach();
}

void Timer::timer::stop()
{
	active = false;
}
