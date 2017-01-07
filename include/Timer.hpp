#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
private:
	int startTicks;
	int pausedTicks;

	bool paused;
	bool started;

public:
	Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	int get_ticks();

	bool is_started();
	bool is_paused();
};


#endif /* end of include guard: TIMER_HPP */
