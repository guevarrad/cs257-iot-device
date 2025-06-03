#include <iostream>
#include <string>

class SmartThermostat {
private:
    float currentTemp;
    float targetTemp;
    bool isHeating;
    bool isCooling;
    std::string mode; // "heat", "cool", "auto", "off"

public:
    SmartThermostat() : currentTemp(72.0), targetTemp(72.0), 
                       isHeating(false), isCooling(false), mode("off") {}
    
    void setTargetTemp(float temp) {
        targetTemp = temp;
        std::cout << "Target temperature set to " << targetTemp << "°F" << std::endl;
        updateSystem();
    }
    
    void setMode(const std::string& newMode) {
        mode = newMode;
        std::cout << "Mode changed to " << mode << std::endl;
        updateSystem();
    }
    
    void updateSystem() {
        if (mode == "heat" && currentTemp < targetTemp) {
            isHeating = true;
            isCooling = false;
        } else if (mode == "cool" && currentTemp > targetTemp) {
            isHeating = false;
            isCooling = true;
        } else if (mode == "auto") {
            // Auto mode: heat when too cold, cool when too hot
            if (currentTemp < targetTemp - 2) {
                isHeating = true;
                isCooling = false;
            } else if (currentTemp > targetTemp + 2) {
                isHeating = false;
                isCooling = true;
            }
        } else {
            isHeating = false;
            isCooling = false;
        }
    }
    
    void simulateTemperatureChange() {
        if (isHeating) currentTemp += 0.5;
        if (isCooling) currentTemp -= 0.5;
    }
    
    void displayStatus() {
        std::cout << "Thermostat Status:" << std::endl;
        std::cout << "  Current Temp: " << currentTemp << "°F" << std::endl;
        std::cout << "  Target Temp: " << targetTemp << "°F" << std::endl;
        std::cout << "  Mode: " << mode << std::endl;
        std::cout << "  Heating: " << (isHeating ? "ON" : "OFF") << std::endl;
        std::cout << "  Cooling: " << (isCooling ? "ON" : "OFF") << std::endl;
    }
};

int main() {
    SmartThermostat myThermostat;
    
    myThermostat.displayStatus();
    myThermostat.setMode("auto");
    myThermostat.setTargetTemp(75.0);
    
    // Simulate some time passing
    for (int i = 0; i < 10; i++) {
        myThermostat.simulateTemperatureChange();
    }
    
    myThermostat.displayStatus();
    
    return 0;
}