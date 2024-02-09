#include <iostream> // Para usar a função std::cout
#include "time.h"

using namespace std;

/*
    Getters
*/

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

/*
    Setters
*/
void Time::setHour(int hour) {
    this->hour = hour;
}

void Time::setMinute(int minute) {
    this->minute = minute;
}

void Time::setSecond(int second) {
    this->second = second;
}

void Time::print() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond() {
    second++;

    if (second >= 60) {
        second = 0;
        minute++;
    }
    if (minute >= 60) {
        minute = 0;
        hour++;
    }
    if (hour >= 24) {
        hour = 0;
    }
}

/*
  Deixei o construtor para o fim para você conhecer uma sintaxe
  alternativa para inicialização de atributos. Colocamos uma lista de
  inicialização após a declaração dos parâmetros. Para separar os
  parâmetros da lista de inicialização, usamos ":". A lista possui a
  sintaxe:

  atributo1(parâmetroA), atributo2(parâmetroB), ..., atributoN(parâmetroM).
 */

// Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {
  /*
    O corpo do método executa após as inicializações. Neste caso, ele
    está vazio porque as inicialiações eram tudo o que queríamos
    fazer.
   */
// }

Time::Time(int h, int m, int s) {
    this->hour = h;
    this->minute = m;
    this->second = s;
}
