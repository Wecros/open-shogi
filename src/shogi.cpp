#include "shogi.h"

using namespace godot;

void Shogi::_register_methods() {
    register_method("_process", &Shogi::_process);
}

Shogi::Shogi() {
}

Shogi::~Shogi() {
    // add your cleanup here
}

void Shogi::_init() {
    // initialize any variables here
    time_passed = 0.0;
}

void Shogi::_process(float delta) {
    time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

    set_position(new_position);
}
