#ifndef RUBBLE_PRICE_API_GETCURRENCYDATA_H
#define RUBBLE_PRICE_API_GETCURRENCYDATA_H

#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <ctime>
#include <nlohmann/json.hpp>

using namespace nlohmann;
using namespace std;

class getCurrencyData {
private:
    string key;

    class currencyToRub {
    public:
        float amount;
    };

    void getCurrencyInfo(string &date, string currencyTag);

    void TimeFromDateToDateWithCurrencyInfo(string &startDate, string &endDate, string currencyTag);

public:
    getCurrencyData(string _key);

    void input();
};


#endif //RUBBLE_PRICE_API_GETCURRENCYDATA_H
