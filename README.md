# Timer
This is thread safe Timer implementation for C++ developer using threads internally. **timer** class under **Timer** namespace.

Timer implementation as of javaScript setTimeout and setInterval.

setInterval is single shot timer which will call cb_function once after given miliseconds are passed.

## `void Timer::timer::setInterval(function cb_function, int miliSec)`
```
t1.setInterval([]() {
		cout << "after 5 sec of delay in loop" << endl;

		}, 5000);
```

setTimeOut is loop based timer which will keep calling cb_function after given miliseconds till stop() method is not called.

## `void Timer::timer::setTimeOut(function cb_function, int milisec)`
```
t2.setTimeOut([]() {
		cout << "after 15 sec of delay" << endl;
		},15000);
```

## `Sample program` 

```
#include<iostream>
#include"Timer.h"

using namespace std;

int main()
{
	cout << "started" << endl;

	Timer::timer t1 = Timer::timer();

	t1.setInterval([]() {
		cout << "after 5 sec of delay in loop" << endl;

		}, 5000);

	Timer::timer t2 = Timer::timer();

	t2.setTimeOut([&]() {
		cout << "after 15 sec of delay" << endl;
		t1.stop();
		},15000);

	cout << "done" << endl;

	while (true);
}
```
