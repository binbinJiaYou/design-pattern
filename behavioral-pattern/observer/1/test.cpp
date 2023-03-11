/**
 * @file Weather.cpp
 * @author liubin (15085776458@163.com)
 * @brief 观察者模式的简单示例
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright Copyright (c) 2023
 *
 * 以气象数据为例，当气象数据（具体主题）发生变化时，所有显示屏（具体观察者）都要刷新显示数据（观察者的更新操作）。
 */
#include <set>
#include <iostream>
#include <functional>
using namespace std;

class Observer
{
public:
    Observer() = default;
    virtual ~Observer() = default;

    // 显然，这种声明不能适应多个主题
    virtual void Update(float temperature, float humidity, float pressure) = 0;
};

class Subject
{
public:
    Subject() = default;
    virtual ~Subject() = default;

    virtual void Register(Observer &observer) = 0;
    virtual void Unregister(Observer &observer) = 0;
    virtual void Notify() = 0;
};

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

    // 通知观察者
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
    set<Observer *> observerSet;
};

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

int main()
{
    WeatherData weatherData;
    Display lcd("液晶");
    Display holod("全息");
    Parser parser;
    weatherData.Register(lcd);
    weatherData.Register(holod);
    weatherData.Register(parser);

    Client client;
    client.SetWeatherData(weatherData, 1, 2, 3);
    client.SetWeatherData(weatherData, 5, 2, 0);

    return 0;
}