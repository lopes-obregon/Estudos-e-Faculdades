#include <iostream>
using namespace std;
extern "C" int question (int a);
int main(int argc, char const *argv[])
{
    if (question(26) == 1){
        cout << "O numero é par" << endl;
    }else{
        cout << "O numero é Impar" << endl;
    }
    return 0;
}
