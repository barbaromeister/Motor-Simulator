#include <iostream>
#include <thread>
#include <chrono>
#include "Servo.h"

int main() {
    Servo servo;
    double target;

    std::cout << "Servo Motor Kontrol Simülatörü\n";
    std::cout << "Çıkmak için -1 girin.\n";
    while (true) {
        std::cout << "Hedef açı girin (0-180): ";
        std::cin >> target;
        if (target == -1) break;
        servo.moveTo(target);
        while (!servo.atTarget()) {
            servo.step();
            std::cout << "Mevcut açı: " << servo.getAngle() << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        std::cout << "Hedefe ulaşıldı!\n";
    }
    return 0;
}