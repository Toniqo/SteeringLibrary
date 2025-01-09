#pragma once

#include <cmath>
#include <vector>

#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_rom_gpio.h"
#include "soc/gpio_sig_map.h"

constexpr gpio_num_t LED_PIN = GPIO_NUM_2;

constexpr gpio_num_t MOTOR_IN1_PIN = GPIO_NUM_26;
constexpr gpio_num_t MOTOR_IN2_PIN = GPIO_NUM_25;
constexpr gpio_num_t MOTOR_IN3_PIN = GPIO_NUM_33;
constexpr gpio_num_t MOTOR_IN4_PIN = GPIO_NUM_32;
constexpr gpio_num_t MOTOR_ENA_PIN = GPIO_NUM_14;
constexpr gpio_num_t MOTOR_ENB_PIN = GPIO_NUM_27;

constexpr gpio_num_t SERVO_STEERING_PIN = GPIO_NUM_12;

namespace ab {
    class Vehicle4WD {
    private:
        int m_leftWheels;   //0 == stop, 1 == forward, 2 == backward
        int m_rightWheels;

        int m_speed;    //working range 40 - 100

        int m_pwmResolution;

        void leftWheelsDirection(int dir);
        void rightWheelsDirection(int dir);

    public:
        Vehicle4WD();
        Vehicle4WD(int left, int right, int speed);

        virtual ~Vehicle4WD();

        void setSpeed(int speed);

        int getPwmResolution() const;

        int getSpeed() const;

        std::vector<int> getDirection() const;

        //car1.driveForward(duration) 0 == infinite drive
        void driveForward(int duration);

        void driveBackward(int duration);

        void stop();
        //car1.turnLeft(angle/percentage) 0 == infinite turn
        virtual void turnLeft(int turn);

        virtual void turnRight(int turn);
    };
}