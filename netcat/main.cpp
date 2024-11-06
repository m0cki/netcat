//g++ -std=c++17 -O3 main.cpp -lb15fdrv

#include<iostream>
#include<b15f/b15f.h>
#include<array>

const size_t ESCAPE_CODE_LEN = 1;
const size_t CHECKSUM_LEN = 2;
const size_t FRAME_DATA_LEN = 64;
const size_t FRAME_LEN = ESCAPE_CODE_LEN + FRAME_DATA_LEN + CHECKSUM_LEN + ESCAPE_CODE_LEN;

using Frame = std::array<uint8_t,FRAME_LEN>;

enum EscapeCode : uint8_t{
    StartOfFrame = 0x12,
    EndOfFrame = 0x23
};

uint16_t calculate_checksum(const std::vector<uint8_t>& data) {
    uint16_t checksum = 0;
    for (const auto& byte : data) {
        checksum ^= byte; //XOR
    }
    return checksum;
}

int main(){

    B15F& drv = B15F::getInstance();
    drv.setRegister(&DDRA,0x0f);

    while(1){
        std::cout << "Schreibe 0" << std::endl;
        drv.setRegister(&PORTA, 0);    
        std::cout << "Schreibe 1" << std::endl;
        drv.setRegister(&PORTA, 1);
    }
}

//TODO - Clock
//Clock Sender gibt abwechslend 0 und 1 an Leitung vor - Arduino liest an einer Clockleitung mit doppeler Geschw. 
