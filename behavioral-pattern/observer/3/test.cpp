#include <functional>
#include "WeatherDataSubject.h"
#include "LifeSubject.h"

void TestWeatherDataSubject()
{
    WeatherDataSubject::WeatherData weatherData;
    WeatherDataSubject::Display lcd("液晶");
    WeatherDataSubject::Display holod("全息");
    WeatherDataSubject::Parser parser;

    auto lcdFunc = std::function(lcd);
    auto holodFunc = std::function(holod);
    auto parserFunc = std::function(parser);

    weatherData.Register(lcdFunc);
    weatherData.Register(holodFunc);
    weatherData.Register(parserFunc);

    WeatherDataSubject::Client client;
    client.SetWeatherData(weatherData, 1, 2, 3);
    client.SetWeatherData(weatherData, 5, 2, 0);
}

/**
 * @brief 使用 std::function 替代抽象观察者后，还可以使代码更灵活，功能更强大
 *
 */
void TestLamda()
{
    WeatherDataSubject::WeatherData weatherData;

    auto surprise = std::function([](float, float, float)
                                  { std::cout << "给你心仪的女孩子制造一点小惊喜" << std::endl; });
    auto awesome = std::function([&surprise](float, float, float){
        std::cout << "我还可以捕获上下文, 就问你6不6!" << std::endl;
    });

    weatherData.Register(surprise);
    weatherData.Register(awesome);

    WeatherDataSubject::Client client;
    client.SetWeatherData(weatherData, 1, 2, 3);
    client.SetWeatherData(weatherData, 5, 2, 0);
}

void TestLifeSubject()
{
    LifeSubject::Life life;
    LifeSubject::AppearanceObserver appearanceObserver;
    LifeSubject::HeightObserver heightObserver;

    auto appearanceObserverFunctor = std::function(appearanceObserver);
    auto heightObserverFunctor = std::function(heightObserver);

    life.Register(appearanceObserverFunctor);
    life.Register(heightObserverFunctor);

    LifeSubject::Client client;
    client.SetStage(life, LifeSubject::Stage::YOUNG);
    client.SetStage(life, LifeSubject::Stage::ADULT);
    client.SetStage(life, LifeSubject::Stage::OLD);
    client.SetStage(life, LifeSubject::Stage::STAGE_LENGTH);
}

int main()
{
    TestWeatherDataSubject();
    TestLifeSubject();
    TestLamda();
    return 0;
}
