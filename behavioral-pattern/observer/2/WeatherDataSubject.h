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
    using Observer = ObserverPattern::Observer<float, float, float>;

    class WeatherData : public Subject
    {
    public:
        WeatherData() : temperature(0.0f), humidity(0.0f), pressure(0.0f) {}

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
                    observer->Update(temperature, humidity, pressure);
                }
            }
        }

    private:
        float temperature; // 温度
        float humidity;    // 湿度
        float pressure;    // 气压
        std::set<Observer *> observerSet;
    };

    // 第一种观察者 显示屏
    class Display : public Observer
    {
    public:
        Display(std::string no) : no(no) {}

        void Update(float temperature, float humidity, float pressure) override
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

    // 第二种观察者 环境氛围解析器
    // 告白神器
    // 骗你的, 哈哈哈
    class Parser : public Observer
    {
    public:
        void Update(float temperature, float humidity, float pressure) override
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