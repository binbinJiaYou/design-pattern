#include "WeatherDataSubject.h"
#include "LifeSubject.h"

void TestWeatherDataSubject()
{
    WeatherDataSubject::WeatherData weatherData;
    WeatherDataSubject::Display lcd("液晶");
    WeatherDataSubject::Display holod("全息");
    WeatherDataSubject::Parser parser;
    weatherData.Register(lcd);
    weatherData.Register(holod);
    weatherData.Register(parser);

    WeatherDataSubject::Client client;
    client.SetWeatherData(weatherData, 1, 2, 3);
    client.SetWeatherData(weatherData, 5, 2, 0);
}

void TestLifeSubject()
{
    LifeSubject::Life life;
    LifeSubject::AppearanceObserver appearanceObserver;
    LifeSubject::HeightObserver heightObserver;
    life.Register(appearanceObserver);
    life.Register(heightObserver);

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
    return 0;
}
