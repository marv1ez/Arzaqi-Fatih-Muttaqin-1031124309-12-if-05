#include <iostream>

  

using namespace std;

int main(){

    float celcius, fahrenheit;

    cout << "dingin kamu berapa derajat:";

    cin >> celcius;

    fahrenheit = (9.0/5.0) * celcius + 32;

    cout << "setara dinginnya : " << fahrenheit << " derajat fahrenheit" << endl;

    cout << "terlalu dingin";

    return 0;

}