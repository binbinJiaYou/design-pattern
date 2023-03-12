/**
 * @file WeatherData.h
 * @author liubin (15085776458@163.com)
 * @brief
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright Copyright (c) 2023
 *
 * 气象数据是一个具体的主题
 */
#pragma once
#include <iostream>
#include <cmath>
#include <set>
#include "Common.h"

namespace WeatherDataSubject
{
    using Subject = ObserverPattern::Subject<float, float, float>;

    class Display
    {
    public:
        Display(std::string no) : no(no) {}
        ~Display() = default;

        void operator()(float temperature, float humidity, float pressure)
        {
            std::cout << no << " 显示屏: "
                      << "温度：" << temperature << " "
                      << "湿度：" << humidity << " "
                      << "气压：" << pressure << std::endl;
            std::cout << "================================" << std::endl;
        }

    private:
        std::string no;
    };

    class Parser
    {
    public:
        Parser() = default;
        ~Parser() = default;

        void operator()(float temperature, float humidity, float pressure)
        {
            std::cout << "现在的氛围" << (IsNiceAir(temperature, humidity, pressure) ? "适合表白" : "不适合表白") << std::endl;
            std::cout << "================================" << std::endl;
        }

    private:
        bool IsNiceAir(float temperature, float humidity, float pressure)
        {
            auto equal = [](float a, float b, float interal)
            {
                using namespace std;
                return abs(a - b) <= interal;
            };
            return equal(temperature, 5.0f, 0.01f) && equal(humidity, 2.0f, 0.01f) && equal(pressure, 0.0f, 0.01f);
        }

    private:
        // 对象内部的数据
    };

    class WeatherData : public Subject
    {
    public:
        WeatherData() : temperature(0.0f), humidity(0.0f), pressure(0.0f) {}
        ~WeatherData() = default;

        void SetWeatherData(float temperature, float humidity, float pressure)
        {
            this->temperature = temperature;
            this->humidity = humidity;
            this->pressure = pressure;
        }

        void Register(Observer &observer) override
        {
            observerSet.insert(&observer);
        }

        void Unregister(Observer &observer) override
        {
            observerSet.erase(&observer);
        }

        void Notify() override
        {
            for (auto &observer : observerSet)
            {
                if (observer)
                {
                    (*observer)(temperature, humidity, pressure);
                }
            }
        }

    private:
        float temperature; // 温度
        float humidity;    // 湿度
        float pressure;    // 气压
        std::set<Observer *> observerSet;
    };

    class Client
    {
    public:
        void SetWeatherData(WeatherData &weatherData, float temperature, float humidity, float pressure)
        {
            weatherData.SetWeatherData(temperature, humidity, pressure);
            weatherData.Notify();
        }
    };
};