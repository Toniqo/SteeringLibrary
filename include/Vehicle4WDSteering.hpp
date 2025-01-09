#pragma once

#include "Vehicle4WD.hpp"

namespace ab {
    class Vehicle4WDSteering : public Vehicle4WD {
    private:
        int m_turnAngle;    // -40° - 40°
        int m_duty;

    public:
        Vehicle4WDSteering();
        Vehicle4WDSteering(int direction, int speed, int turn);
        //~Vehicle4WDSteering() {}

        int getTurnAngle() const;

        void turnLeft(int turn) override;
        void turnRight(int turn) override;
    };
}