//
// Created by roscale on 1/18/17.
//

#ifndef PONG_SDL_SCORE_HPP
#define PONG_SDL_SCORE_HPP


class Score {
public:
	int get() const;
	void set(int newValue);
	void increment();
	void reset();

private:
    int m_value = 0;
};


#endif //PONG_SDL_SCORE_HPP
