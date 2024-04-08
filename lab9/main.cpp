#include "getCurrencyData.h"
#include "string"

using namespace std;
using namespace nlohmann;

// CPR lib is used for api response https://docs.libcpr.org/
// nlohmann lib is used for auto-parsing jsons https://github.com/nlohmann/json
// ui design will be added in future

int main() {
    // place here your api key or u can use mine
    // api source: https://app.currencyapi.com/api-keys
    string KEY = "cur_live_6j0cU8OBtgpmnPVbKDTEcc7j4ZDJeiHXuWTB1Bna";
    getCurrencyData lab9opINF(KEY);
    lab9opINF.input();
    return 0;
}

// example of input
/*
CNY
2024-04-01
2024-04-06
 */
