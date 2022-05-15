#pragma once
#include<functional>
#include<atomic>

namespace Timer {
	
	class timer
	{
	private:
		std::atomic<bool> active;
		using function = std::function<void()>;

	public:
		timer();
		timer(int t);
		~timer();
		void setInterval(function Cb_function, int miliSec);
		void setTimeOut(function cb_function, int milisec);
		void stop();
	};
}