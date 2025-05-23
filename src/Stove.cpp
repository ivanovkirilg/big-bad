#include "Stove.hpp"

#include <string>
#include <iostream>

#include <thread>

namespace
{

int measureInitialTemperature()
{
    // Get current month
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&t);

    // Simulate average room temperature by month (Celsius)
    // Jan: 18, Feb: 18, Mar: 19, Apr: 20, May: 22, Jun: 24, Jul: 25, Aug: 25, Sep: 23, Oct: 21, Nov: 19, Dec: 18
    static const int avgTemps[12] = {18, 18, 19, 20, 22, 24, 25, 25, 23, 21, 19, 18};
    int baseTemp = avgTemps[localTime->tm_mon];

    // Add a small random fluctuation
    int fluctuation = rand() % 3 - 1; // -1, 0, or +1

    return baseTemp + fluctuation;
}

}

Stove::Stove(int temperatureRangeC)
    : m_temperatureC(measureInitialTemperature()),
      m_temperatureRangeC(temperatureRangeC)
{
}

void Stove::turnOn(int targetTemperatureC, int timerSeconds)
{
    m_targetTemperatureC = targetTemperatureC;
    m_timer = timerSeconds;
}

void Stove::simulateHeating()
{
    if (m_temperatureC < m_targetTemperatureC - m_temperatureRangeC)    
    {
        m_isOn = true;
    }
    else if (m_temperatureC > m_targetTemperatureC + m_temperatureRangeC)
    {
        m_isOn = false;
    }
    
    if (m_isOn)
    {
        m_temperatureC += 1;
    }
    else
    {
        m_temperatureC -= 1;
    }
}

bool Stove::waitReady()
{
    simulateHeating();

    std::string onLight = m_isOn ? "(*)" : "( )";
    std::cout << onLight << " " << m_temperatureC << "C";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    m_timer--;
    return m_timer <= 0;
}
