#ifndef SRC_EXERCISE
#define SRC_EXERCISE

/**
 * @brief Class representing a temperature-controlled stove/heating element
 * 
 * The Stove class simulates a heating element that can be controlled to reach
 * and maintain a target temperature within a specified range. It includes timing
 * functionality for controlled heating duration.
 * 
 * Requirements:
 * - Stove simulates gradual heating to target temperature
 * - Stove maintains temperature within the specified range once target is reached until timer expires
 * - Stove reports the current temperature and status (heating or not)
 * - Stove must be turned on before use
 * 
 * @note This is a simulation class and does not control actual hardware
 */
class Stove
{
public:
    Stove(int temperatureRangeC);

    void turnOn(int targetTemperatureC, int timerSeconds);
    bool waitReady();

private:
    void simulateHeating();

    int m_temperatureRangeC;
    double m_temperatureC;
    double m_targetTemperatureC;
    int m_timer;
    bool m_isOn;
};

#endif // SRC_EXERCISE
