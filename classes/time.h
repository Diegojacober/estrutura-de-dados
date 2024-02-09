/*
    As primeiras linhas de código deste arquivo servem para evitar que múltiplas definições da Classe Time ocorram.
    Isso poderia ocorrer se você der include de dois pacotes que dão include em "time.h"
*/

#ifndef TIME_H // Inclua esse bloco apenas se o TIME_H não está definido 
#define TIME_H // Na primeira inclusão, define TIME_H para que este bloco não seja incluído mais de uma vez.

class Time {
    private: // seção privada 
        // Membros privados
        int hour;
        int minute;
        int second;
    public: //Seção públic
        Time(int hour = 0, int minute = 0, int second = 0);  
        int getHour() const;
        void setHour(int hour);
        int getMinute() const;
        void setMinute(int minute);
        int getSecond() const;
        void setSecond(int second);
        void print() const;
        void nextSecond();
};

#endif //Final do bloco #ifndef