#include "mbed.h"

AnalogIn ai(A0);
PwmOut pwm(D6);
float ADC;
Thread thread;
void sample(){
    int cnt = 0;
    while(cnt<1000){
        ADC = ai;
        printf("%f\n", ADC);
        cnt++;
    }
    ThisThread::sleep_for(1ms);
}
// main() runs in its own thread in the OS
int main()
{
    thread.start(sample);
    pwm.period_us(20);
    double data[9];
    for(int i = 0; i<9; ++i){
        data[i] = 0.1*i;
    }
    while (true) {
        for(int i = 0; i<9; ++i){
            pwm.pulsewidth_us(20*data[i]);
            ThisThread::sleep_for(50ms);
        }
    }
}

