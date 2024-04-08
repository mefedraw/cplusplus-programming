#include "getCurrencyData.h"
#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <ctime>
#include <nlohmann/json.hpp>


getCurrencyData::getCurrencyData(string _key) {
    key = _key;
}

void getCurrencyData::getCurrencyInfo(std::string &date, std::string currencyTag) {
    cpr::Response convertRate = cpr::Get(
            cpr::Url{
                    "https://api.currencyapi.com/v3/historical?apikey=cur_live_6j0cU8OBtgpmnPVbKDTEcc7j4ZDJeiHXuWTB1Bna&currencies=RUB&base_currency=" +
                    currencyTag + "&date=" + date},
            cpr::Header{{"X-Api-Key", key}});
    //cpr::Timeout{10000});

    json curInf = json::parse(convertRate.text);

    currencyToRub currencyInfo{
            curInf["data"]["RUB"]["value"].template get<float>()
    };
    cout << currencyTag << "/RUB" << " for date: " << date << " is " << currencyInfo.amount << "\n";
}

void getCurrencyData::TimeFromDateToDateWithCurrencyInfo(std::string &startDate, std::string &endDate,
                                                         std::string currencyTag) {
    int year, month, day;
    year = stoi(startDate.substr(0, 4));
    month = stoi(startDate.substr(5, 2));
    day = stoi(startDate.substr(8, 2));
    tm timeinfo;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;
    timeinfo.tm_isdst = -1;

    time_t unix_time = mktime(&timeinfo);
    //cout << unix_time << "\n";
    string tempDate;
    while (tempDate != endDate) {
        char sDateAndTime3[80];
        tm *timeinfo3 = localtime(&unix_time);
        strftime(sDateAndTime3, 80, "%Y-%m-%d", timeinfo3);
        //std::cout << sDateAndTime3 << "\n";
        tempDate = sDateAndTime3;
        getCurrencyInfo(tempDate, currencyTag);
        unix_time += 86400;
    }
}

void getCurrencyData::input() {
    string currencyTag; // USD
    cin >> currencyTag;
    string startDate;
    string endDate;
    cin >> startDate; // 2024-03-01
    cin >> endDate; // if u want to get price only for just 1 day (starDate) fill endDate with '-'
    if (endDate != "-") {
        TimeFromDateToDateWithCurrencyInfo(startDate, endDate, currencyTag);
    } else {
        getCurrencyInfo(startDate, currencyTag);
    }
    /// https://api.currencyapi.com/v3/historical?apikey=cur_live_6j0cU8OBtgpmnPVbKDTEcc7j4ZDJeiHXuWTB1Bna&currencies=RUB&base_currency=EUR&date=2024-04-07
    /// "{\"meta\":{\"last_updated_at\":\"2024-03-27T23:59:59Z\"},\"data\":{\"RUB\":{\"code\":\"RUB\",\"value\":92.6002413647}}}"
}