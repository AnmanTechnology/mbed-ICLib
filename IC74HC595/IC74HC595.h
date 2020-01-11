#include "mbed.h"


class IC74HC595
{
private:
    DigitalOut _DAT;
    DigitalOut _CLK;
    DigitalOut _LAT;
public:
    IC74HC595(PinName DAT, PinName CLK,PinName LAT);
    void store_data(void);
    void send_data(uint8_t data);
    void send_data(uint16_t data);
    void send(uint8_t data);
    void send(uint16_t data);
};

IC74HC595::IC74HC595(PinName DAT, PinName CLK,PinName LAT):_DAT(DAT),_CLK(CLK),_LAT(LAT){}

void IC74HC595::store_data(void)
{
    _LAT = 1;
    _LAT = 0;
}

void IC74HC595::send_data(uint8_t data)
{
    for(uint8_t i=0;i<8;i++)
    {
        _CLK = 0;
        _DAT = data & 0x01;
        data >>= 1;
        _CLK = 1;
    }
}

void IC74HC595::send_data(uint16_t data)
{
    for(uint8_t i=0;i<16;i++)
    {
        _CLK = 0;
        _DAT = data & 0x01;
        data >>= 1;
        _CLK = 1;
    }
}

void IC74HC595::send(uint8_t data)
{
    send_data(data);
    store_data();
}

void IC74HC595::send(uint16_t data)
{
    send_data(data);
    store_data();
}