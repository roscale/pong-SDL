//
// Created by roscale on 1/18/17.
//

#include "Score.hpp"

int Score::get() const {
    return m_value;
}

void Score::set(int newValue) {
    m_value = newValue;
}

void Score::increment() {
    set(get()+1);
}

void Score::reset() {
    set(0);
}
