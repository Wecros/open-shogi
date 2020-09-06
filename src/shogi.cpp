#include "shogi.h"

using namespace godot;

void Shogi::_register_methods() {
    register_method("_process", &Shogi::_process);

    register_property<Shogi, float>("amplitude", &Shogi::amplitude, 10.0);
    register_property<Shogi, float>("speed", &Shogi::set_speed, &Shogi::get_speed, 1.0);

    register_signal<Shogi>((char *)"position_changed", "node", GODOT_VARIANT_TYPE_OBJECT, "new_pos", GODOT_VARIANT_TYPE_VECTOR2);
}

Shogi::Shogi() {
}

Shogi::~Shogi() {
    // add your cleanup here
}

void Shogi::_init() {
    // initialize any variables here
    time_passed = 0.0;
    time_emit = 0.0;
    amplitude = 50.0;
    speed = 1.0;
}

void Shogi::_process(float delta) {
    time_passed += speed * delta;

    Vector2 new_position = Vector2(
        amplitude + (amplitude * sin(time_passed * 2.0)),
        amplitude + (amplitude * cos(time_passed * 1.5))
    );

    set_position(new_position);

    time_emit += delta;
    if (time_emit > 1.0) {
        emit_signal("position_changed", this, new_position);

        time_emit = 0.0;
    }
}

void Shogi::set_speed(float p_speed) {
    speed = p_speed;
}

float Shogi::get_speed() {
    return speed;
}
