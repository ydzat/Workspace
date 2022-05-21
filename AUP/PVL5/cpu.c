#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include<math.h>

struct reg {
    unsigned char pc;
    unsigned char sp;
    unsigned char fa;
};

enum cpuparam{maxcmdadr=255, maxdataadr=127};

bool cpu(struct reg *registers, unsigned char data[128], uint16_t cmd[256]);

bool load(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);    //0
bool store(struct reg *registers, uint16_t adressmode, uint16_t cmd[256]);   //1
bool neg(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);     //2
bool cmp(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);     //3
bool add(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);     //4
bool jump(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand, uint16_t *cmd);    //5
bool push(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);    //6
bool pop(struct reg *registers,uint16_t adressmode, uint16_t cmd[256]);     //7
bool and(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);     //8
bool or(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand);      //9

unsigned char getAddr(uint16_t adressmode, unsigned char data[128], uint16_t operand);
double pow(double x, double y);
//======================================
//-------pow------
double pow(double x, double y){
    double temp = 1;
    for(int i = 0; i < y; i++){
        temp = temp * x;
    }
    return temp;
}
//-------------getAddr------------------
// uint16_t adressmode 的uint16_t可能有问题
unsigned char getAddr(uint16_t adressmode, unsigned char data[128], uint16_t operand){
    int temp;
    switch(adressmode){
        case 0:
            //int temp;
            temp = operand / 2;
            if(temp % 2 == 0){
                return data[temp & 15];
            }
            else{
                return data[(temp & 240)]>>4;
            }
            break;
        case 1:
            temp = data[getAddr(0, data, operand)] + ((data[getAddr(0, data, operand + 1)])<<4);
            return getAddr(0,data,temp);
        case 2:
            return operand&15;
        case 3:
            return false;
        default:
            return false;
    }
}
//----------Befehle--------------------------
//---------0-----check
bool load(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand);
    uint16_t temp1 = 240; //1111 0000

    registers->fa = (registers->fa & temp1) + temp;

    return true;
}

//---------1--------check
bool store(struct reg *registers, uint16_t adressmode, uint16_t cmd[256]){
   

    if((adressmode == 3) || (adressmode == 2)){
        return false;
    }
    //int temp = getAddr(adressmode, data[128], operand);
    uint16_t temp1 = 65280;//1111 1111 0000 0000;
    uint16_t temp2 = 15; //0000 1111

    cmd[registers->pc] = (cmd[registers->pc] & temp1) + (registers->fa & temp2);
    return true;
}

//-----------2-----------check
bool neg(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand), t;

    if(((temp >> 3)&1) == 0){
        t = temp;
    }
    else{
        

        t = (((temp>>3)&1)<<3) + ((~(temp>>2)&1)<<2) + ((~(temp>>1)&1)<<1) + (~(temp>>0)&1);
    }
    if(t == 0){
        registers->fa^= (registers->fa&(1<<6))^(1<<6);
    }
    else{
        registers->fa^= (registers->fa&(1<<6))^(0<<6);
    }
    uint16_t temp1 = 240;

    
    registers->fa = (registers->fa & temp1) + t;

    return true;
}

//-----------3----------check
bool cmp(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand), t;
    if(((temp >> 3)&1) == 0){
        t = temp;
    }
    else{
        t = (((temp>>3)&1)<<3) + ((~(temp>>2)&1)<<2) + ((~(temp>>1)&1)<<1) + (~(temp>>0)&1) + 1;
    }

    if(t == 0){
        registers->fa^= (registers->fa&(1<<6))^(1<<6);
    }
    else{
        registers->fa^= (registers->fa&(1<<6))^(0<<6);
    }

    uint16_t temp1 = 240;
    registers->fa = (registers->fa & temp1) + t;

    return true;
}

//--------4-------check
bool add(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand);

    unsigned char sum = temp + (registers->fa & 15);
    if( ((sum>>5)&1) == 1 ){
        registers->fa^=(registers->fa&(1<<7)) ^ (1<<7);
    }
    else{
        registers->fa^=(registers->fa&(1<<7)) ^ (0<<7);
    }
    sum = sum & 15;
    uint16_t temp1 = 240;//1111 0000;
    registers->fa = (registers->fa & temp1) + sum;

    if((registers->fa & 15) == 0){
        registers->fa^= (registers->fa&(1<<6))^(1<<6);
    }
    else{
        registers->fa^= (registers->fa&(1<<6))^(0<<6);
    }

    return true;

}

//--------------5---?
bool jump(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand, uint16_t *cmd){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand);

    if((registers->pc + temp) > 255 || (registers->pc + temp) < 0){
        return false;
    }
    // uint16_t *cmdr;
    // cmdr = cmd[registers->pc+temp];
    cmd = cmd + temp;
    cpu(registers, data, cmd);

    return true;

}

//----------------6
bool push(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand);
    uint16_t temp1 = 240;
    registers->sp = (registers->sp & temp1) + temp;
    registers->sp-=1;
    return true;
}

//---------------7
bool pop(struct reg *registers,uint16_t adressmode, uint16_t cmd[256]){

    if(adressmode == 3 || adressmode == 2){
        return false;
    }
    //unsigned char temp = getAddr(adressmode, data, operand);
    registers->sp+=1;
    // if((registers->sp) > 255){
    //     return false;
    // }
    uint16_t temp1 = 65280;//1111 1111 0000 0000;
    cmd[registers->pc] = (cmd[registers->pc] & temp1) + (registers->sp & 15);
    return true;
}

//------------8
bool and(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand);

    uint16_t temp1 = 240; //1111 0000;
    uint16_t temp2 = 15; //0000 1111;
    registers->fa = (registers->fa & temp1) + ((registers->fa & temp2) & temp);

    return true;
}

//--------------9
bool or(struct reg *registers, unsigned char data[128],uint16_t adressmode, uint16_t operand){

    if(adressmode == 3){
        return false;
    }
    unsigned char temp = getAddr(adressmode, data, operand);

    uint16_t temp1 = 240; //1111 0000;
    uint16_t temp2 = 15; //0000 1111;
    registers->fa = (registers->fa & temp1) + ((registers->fa & temp2) | temp);

    return true;
}

//----------CPU-----------------------


bool cpu(struct reg *registers, unsigned char data[128], uint16_t cmd[256]){
    uint16_t opr = cmd[registers->pc];
    
    uint16_t *opr1 = &cmd[registers->pc];
    uint16_t temp1 = 61440;     //1111 0000 0000 0000
    uint16_t temp2 = 3840;      //0000 1111 0000 0000
    uint16_t temp3 = 240;       //0000 0000 1111 0000
    uint16_t temp4 = 15;        //0000 0000 0000 1111
    uint16_t opCode = (opr&temp1)>>12;
    //同样方法获取bedingung和adressmode和operand

    //判断bedingung
    //获取x第n位 的值   (x>>n)&1
    //设置x第n位的值为a  x^=(x&(1<<n)) ^ (a<<n)
    uint16_t bedingung = (opr&temp2)>>10;
    uint16_t adressmode = (opr&temp3)>>8;
    uint16_t operand = (opr&temp4);
    uint16_t C = (registers->fa>>7)&1;
    uint16_t Z = (registers->fa>>6)&1;
    
    
    if((bedingung == 0) || (bedingung == 1 && Z==1) || (bedingung == 2 && C == 1) || (Z == 0)){
        bool temp;
        switch(opCode){
            case 0:
                temp = load(registers, data, adressmode, operand);
                return temp;

            case 1:
                temp = store(registers, adressmode, cmd);
                return temp;

            case 2:
                //registers->fa^= registers->fa&(1<<6)^(0<<6);    //zero-flag = 0;
                temp = neg(registers, data, adressmode, operand);
                return temp;

            case 3:
                //registers->fa^= registers->fa&(1<<6)^(0<<6);    //zero-flag = 0;
                temp = cmp(registers, data, adressmode, operand);
                return temp;

            case 4:
                temp = add(registers, data, adressmode, operand);
                return temp;
            case 5:
                temp = jump(registers, data, adressmode, operand, opr1 );
                return temp;
            case 6:
                temp = push(registers, data, adressmode, operand);
                return temp;
            case 7:
                temp = pop(registers, adressmode, cmd);
                return temp;

            case 8:
                temp = and(registers, data, adressmode, operand);
                return temp;

            case 9:
                temp = or(registers, data, adressmode, operand);
                return temp;
            default: 
                return false;
        }
    }
    else{
        return false;
    }


}
