#include <iostream>

using namespace std;

  

int main(){

    float x, y;

    cin >> x >> y;

    cout << x + y << endl;

    cout << x - y << endl;

    cout << x * y << endl;

    if(y != 0)

        cout << x / y << endl;

    else

        cout << "Error" << endl;

    return 0;

}