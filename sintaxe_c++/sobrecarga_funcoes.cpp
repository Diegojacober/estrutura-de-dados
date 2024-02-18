#include <iostream>

using namespace std;

void soma();
void soma(int n1, int n2);

int main(int argc, char *argv[])
{
    soma();
    soma(10, 30);
    return 0;
}

void soma(int n1, int n2) {
    int rs = n1 + n2;
    cout << "Soma de " << n1 << " com " << n2 << " = " << rs << endl;
}

void soma() {
    int n1, n2, rs;
    n1=10;
    n2=20;
    rs = n1 + n2;
    cout << "Soma de " << n1 << " com " << n2 << " = " << rs << endl;
}