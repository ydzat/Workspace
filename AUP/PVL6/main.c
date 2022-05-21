#include<stdio.h>
#include<stdlib.h>

int getLen(char *p);
int max(int a, int b);
int min(int a, int b);

char *rechner(char *x, char *y, char *opr, int commaX, int commaY, int lenX, int lenY);
char *add(char *x, char *y, int commaX, int commaY, int lenX, int lenY);
//int addR();
char mini(char *x, char *y, int commaX, int commaY, int lenX, int lenY);
char multi(char *x, char *y, int commaX, int commaY, int lenX, int lenY);

char multiTable[8][8]={{1,2,3,4,5,6,7,8},
                      {2,4,6,8,11,13,15,17},
                      {3,6,10,13,16,20,23,26},
                      {4,8,13,17,22,26,31,35},
                      {5,11,16,22,27,33,38,44},
                      {6,13,20,26,33,40,46,53},
                      {7,15,23,31,38,46,54,62},
                      {8,17,26,35,44,53,62,71}
};
char addTable[9][9]={{0,1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8,10},
                    {2,3,4,5,6,7,8,10,11},
                    {3,4,5,6,7,8,10,11,12},
                    {4,5,6,7,8,10,11,12,13},
                    {5,6,7,8,10,11,12,13,14},
                    {6,7,8,10,11,12,13,14,15},
                    {7,8,10,11,12,13,14,15,16},
                    {8,10,11,12,13,14,15,16,17}
    
};

int main(int argc, char *argv[]){

    //----------x, y 处理前后的0
    char *x = argv[1], *y = argv[3];
    
    int lenX = getLen(x), lenY = getLen(y);

    if(x[0] == '0' || (x[0] == '-' && x[1] == '0')){
        if(x[0] == '-'){
            for(int i = 1; i < lenX; i ++){
                if(x[i] != '0'){
                    x = x + i - 1;
                    x[0] = '-';
                    break;
                }
            }
        }
        if(x[0] == '0'){
            for(int i = 0; i < lenX ; i++){
                if(x[i] != '0'){
                    x = x + i;
                    break;
                }
            
            }
        }
        
    }
    if(y[0] == '0' || (y[0] == '-' && y[1] == '0')){
        if(y[0] == '-'){
            for(int i = 1; i < lenY; i ++){
                if(y[i] != '0'){
                    y = y + i - 1;
                    y[0] = '-';
                    break;
                }
            }
        }
        if(y[0] == '0'){
            for(int i = 0; i < lenY ; i++){
                if(y[i] != '0'){
                    y = y + i;
                    break;
                }
            
            }
        }
    }

    //处理','之后的0
    lenX = getLen(x), lenY = getLen(y);
    int commaX = 0, commaY = 0;
    for(commaX; commaX < lenX; commaX ++){
        if(x[commaX] == ','){
            break;
        }
    }
    for(commaY; commaY < lenY; commaY ++){
        if(y[commaY] == ','){
            break;
        }
    }

    if(commaX != lenX && x[lenX-1] == '0'){
        for(int i = lenX-1; i >=commaX; i --){
            if(x[i] != '0'){
                x[i+1] = '\0';
                lenX = getLen(x);
                break;
            }
        }
    }
    if(commaY != lenY && y[lenY-1] == '0'){
        for(int i = lenY-1; i >=commaY; i --){
            if(y[i] != '0'){
                y[i+1] = '\0';
                lenY = getLen(y);
                break;
            }
        }
    }

    
    
    
    //char *x1 = (char*)malloc(sizeof(char)*(lenX+1));
    if(commaX == lenX){
        lenX++;
       // x1[lenX] = 
    }
    if(commaY == lenY){
        lenY++;
    }

    printf("lenX = %d, lenY = %d\n",lenX,lenY);
    printf("commaX = %d, commaY = %d\n",commaX,commaY);
    printf("x = %s y = %s\n",x,y);
    //---------------
    char *pp = rechner(x,y,argv[2],commaX,commaY,lenX,lenY);
   
    /*关于输出：当小数位全为0时，应省略包括','及以后的0*/
    puts(pp);
    



    return 0;

}
//-----------------------
int getLen(char *p){
    char *end = p;
    while (*end != '\0'){
        end++;
    }
    return end - p;
}

int max(int a, int b){
    if(a >=b){
        return a;
    }
    else{
        return b;
    }
}

int min(int a, int b){
    if(a<=b){
        return a;
    }
    else{
        return b;
    }
}

//----------------------
char *rechner(char *x, char *y, char *opr, int commaX, int commaY, int lenX, int lenY){
    int index = max(lenX,lenY);
    char *res = (char*)malloc(sizeof(char)*index);
    //int lenX = getLen(x), lenY = getLen(y);
    
    
    switch(opr[0]){
        case '+':
            res = add(x,y,commaX,commaY,lenX,lenY);
            
            break;
        case '-':
            res = mini(x,y,commaX,commaY,lenX,lenY);
            break;
        case '*':
            res = multi(x,y,commaX,commaY,lenX,lenY);
            break;
    }
    return res;
}
//---------------------------
char *add(char *x, char *y, int commaX, int commaY, int lenX, int lenY){
    
    int index = max(lenX-commaX, lenY-commaY) + max(commaX, commaY);
    printf("index = %d,lenX = %d, lenY = %d\n",index,lenX, lenY);
    char *res = (char*)malloc(sizeof(char)*(index));
    for(int i = 0; i < index; i++){
        res[i] = '0';
    }

    //都为负数
    if((x[0] == '-') && (y[0] == '-')){
        
        res[0] = '-';
        x = x + 1;
        y = y + 1;
        lenX--;
        lenY--;
        index = index - 1;
        res[index] = '\0';
        int ziffX = 0, ziffY = 0;
        int cX=0,cY=0;

        

        //先算小数
        if(commaX != lenX){
            ziffX = lenX - commaX; //表示有多少位小数
            //
            // for(int i = 1 ; i <= ziffX ; i ++ ){
                
            // }
        }

        if(commaY != lenY){
            ziffY = lenY - commaY;
            // for(int i = 1 ; i <= ziffY ; i ++ ){
            //     cY = cY + pow(y[commaY+i],ziffY-i);
            // }
        }
        
        int shortZi = min(ziffX,ziffY), longZi = max(ziffX,ziffY);
        //把多余的小数位存进res后面
        
        if((ziffX == longZi) && (ziffX != ziffY)){
            
            res[index-ziffX-1] = ',';
            int j = 1;
            for(int i = index - 1; i >= index - ziffX ; i --){
                res[i] = x[lenX-j];

                j++;
                
            }
            
        }
        if((ziffY == longZi) && (ziffX != ziffY)){
            
            res[index-ziffY-1] = ',';
            int j = 1;

            for(int i = index - 1; i >= index - ziffY ; i --){
                res[i] = y[lenY-j];
                j++;
            }
        }
        else{
            res[index-ziffX-1] = ',';
        }
        
        int flag = 0,commaR=0;
        //计算位数相同的小数位
        for(commaR = 0 ; commaR < index; commaR ++){
            if(res[commaR]==','){
                break;
            }
        }

        if(commaR != index ){
            printf("shortZi = %d\n",shortZi);
            if(shortZi == 0){
                shortZi = 1;
            }
            for(int i = shortZi ; i >= 1; i--){
                printf("hhhhhhhhh\n");
                printf("commaX = %d, commaY = %d\n",commaX,commaY);
                printf("x = %s y = %s\naaa\n",x,y);
                printf("x[commaX+i-1] = %c, y[commaY+i-1] = %c\n",x[commaX+i-1],y[commaY+i-1] );
                int t = addTable[x[commaX+i-1] -48 ][y[commaY+i-1] -48 ];
                printf("t = %d\n",t);
                if(flag == 1){
                    //int tempLen = getLen(t);
                    if(t >= 9){
                        res[commaR + i] = '0' + addTable[t-10][1] / 1 %10;
                        flag = 1;

                    }
                    if(t < 9){
                        int t1;
                        t1 = addTable[t][1];
                        if(t1 >= 9){
                            res[commaR + i ] = '0' + (t1 / 1 % 10);
                            flag = 1;
                            
                        }
                        else{
                            res[commaR + i] = '0'+ t1;
                            flag = 0;
                        }
                    }
                }
                else{
                    if(t>=9){
                        res[commaR + i] = '0'+ (t /1 %10);
                        flag = 1;
                    }
                    else{
                        res[commaR + i] = '0' + t;
                        flag = 0;
                    }
                }
            }
        }
        printf("res=====%s\n",res);
        //再算整数
        int shortZ = min(lenX-ziffX-1, lenY-ziffY-1), longZ = max(lenX-ziffX, lenY-ziffY);
        printf("shortZ = %d, longZ = %d\n",shortZ,longZ);
        for(int i = 1; i <=shortZ ; i++){
            int t;
            t = addTable[x[commaX-i-1] -48 ][y[commaY-i-1] -48 ];
            printf("t=%d\n",t);
            if(flag == 1){
                
                if(t >= 9){
                    res[commaR - i] = '0' +(addTable[t-10][1] / 1 %10);
                    flag = 1;

                }
                if(t < 9){
                    int t1;
                    t1 = addTable[t][1];
                    
                    if(t1 > 9 ){
                        res[commaR - i ] = '0' + (t1/1%10);
                        flag = 1;
                    }
                    else{
                        res[commaR - i] = '0' + t1;
                        flag = 0;
                    }
                }
            }
            else{
                if(t>=9){
                    res[commaR - i] = '0'+ (t /1 %10);
                    
                    flag = 1;
                }
                else{
                    res[commaR - i] = '0' + t;
                    flag = 0;
                }
            } 
        }
        
        int leftZ = longZ - shortZ;
        if(flag == 1){
            if(leftZ == 0){
                res[commaR-shortZ-1] = '1';
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '-';
                res[index+1] = '\0';
                return res;
            }
            else{
                char *l,commaL;
                if (lenX-ziffX > lenY-ziffY){
                    l = x;
                    commaL = commaX;
                }
                else{
                    l = y;
                    commaL = commaY;
                }
                int flag1=0;
                for(int i = 1 ; i <= leftZ; i++ ){
                    int t;

                    t = addTable[l[leftZ-i] - 48][flag];
                    printf("t+++ = %d\n",t);
                    printf("commaR = %d, shortZ = %d, i = %d\n",commaR,shortZ,i);
                    if(t>=9){
                        res[commaR-shortZ-i+1] = '0' + (t/1%10);
                        flag = 1;
                    }
                    else{
                        res[commaR-shortZ-i+1] = '0' + t;
                        
                        flag = 0;
                    }

                }
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '-';
                res[index+1] = '\0';
                return res;
            }
        }
        else{
            if(leftZ == 0){
                res[commaR-shortZ-1] = '1';
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '-';
                
                res[index+1] = '\0';
                return res;
            }
            else{
                char *l,commaL;
                if (lenX-ziffX > lenY-ziffY){
                    l = x;
                    commaL = commaX;
                }
                else{
                    l = y;
                    commaL = commaY;
                }
                for(int i = 1 ; i <= leftZ; i ++){
                    res[commaR-shortZ-i+1] = l[leftZ-i];
                }
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '-';
                res[index+1] = '\0';
                return res;
            }
        }
        
        
    }
    //一个为负数
    if(((x[0] == '-') && (y[0] != '0')) || ((y[0] == '-') && (x[0] != '0'))){
        if(x[0]=='-'){
            mini(y,x,commaY,commaX,lenY,lenX);

        }
        if(y[0]=='-'){
            mini(x,y,commaX,commaY,lenX,lenY);
        }
    }
    else{//都为正数
        //============================================
        res[0] = '0';
        // x = x + 1;
        // y = y + 1;
        // lenX--;
        // lenY--;
        // index = index - 1;

        res[index] = '\0';
        int ziffX = 0, ziffY = 0;
        int cX=0,cY=0;
        commaX++;
        commaY++;
        
        //先算小数
        if(commaX != lenX){
            ziffX = lenX - commaX; //表示有多少位小数


        }
        //printf("ziffX = %d\n",zifX);
        if(commaY != lenY){
            ziffY = lenY - commaY;
            // for(int i = 1 ; i <= ziffY ; i ++ ){
            //     cY = cY + pow(y[commaY+i],ziffY-i);
            // }
        }
        
        int shortZi = min(ziffX,ziffY), longZi = max(ziffX,ziffY);
        //把多余的小数位存进res后面
        if((ziffX == longZi) && (ziffX != ziffY)){
            
            res[index-ziffX-1] = ',';
            int j = 1;
            for(int i = index - 1; i > index - ziffX ; i --){
                res[i] = x[lenX-j];
                j++;
            }
            
        }
        if((ziffY == longZi) && (ziffX != ziffY)){
            
            res[index-ziffY-1] = ',';
            int j = 1;

            for(int i = index - 1; i > index - ziffY ; i --){
                res[i] = y[lenY-j];
                j++;
            }
        }
        else{
            res[index-ziffX-1] = ',';
        }
        
        int flag = 0,commaR=0;
        //计算位数相同的小数位
        for(commaR = 0 ; commaR < index; commaR ++){
            if(res[commaR]==','){
                break;
            }
        }

        if(commaR != index ){

            for(int i = shortZi ; i >= 1; i--){
 
                int t = addTable[x[commaX+i-1] -48 ][y[commaY+i-1] -48 ];
                printf("t = %d\n",t);
                printf("commaY = %d, i = %d, y[commaY+i-1] = %d,",commaY,i,y[commaY+i-1]);
                if(flag == 1){
                    //int tempLen = getLen(t);
                    if(t >= 9){
                        res[commaR + i] = '0' + addTable[t-10][1] / 1 %10;
                        flag = 1;

                    }
                    if(t < 9){
                        int t1;
                        t1 = addTable[t][1];
                        if(t1 >= 9){
                            res[commaR + i ] = '0' + (t1 / 1 % 10);
                            flag = 1;
                            
                        }
                        else{
                            res[commaR + i] = '0'+ t1;
                            flag = 0;
                        }
                    }
                }
                else{
                    if(t>=9){
                        res[commaR + i] = '0'+ (t /1 %10);
                        flag = 1;
                    }
                    else{
                        res[commaR + i] = '0' + t;
                        flag = 0;
                    }
                }
            }
        }
        printf("res = %s\n",res);
        printf("x = %s y = %s\n",x,y);
        //再算整数
        int shortZ = min(lenX-ziffX, lenY-ziffY), longZ = max(lenX-ziffX, lenY-ziffY);
        for(int i = 1; i <shortZ ; i++){
            int t;
            t = addTable[x[commaX-i-1] -48 ][y[commaY-i-1] -48 ];
            printf("t = %d, flag = %d\n",t,flag);
            if(flag == 1){
                
                if(t >= 9){
                    res[commaR - i] = '0' +(addTable[t-10][1] / 1 %10);
                    flag = 1;

                }
                if(t < 9){
                    int t1;
                    t1 = addTable[t][1];
                    if(t1 > 9 ){
                        res[commaR - i ] = '0' + (t1/1%10);
                        flag = 1;
                    }
                    else{
                        res[commaR - i] = '0' + t1;
                        flag = 0;
                    }
                }
            }
            else{
                if(t>=9){
                    res[commaR - i] = '0'+ (t /1 %10);
                    flag = 1;
                }
                else{
                    res[commaR - i] = '0' + t;
                    flag = 0;
                }
            } 
        }
        
        int leftZ = longZ - shortZ;
        if(flag == 1){
            if(leftZ == 0){
                res[commaR-shortZ-1] = '1';
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '0';
                res[index+1] = '\0';
                return res;
            }
            else{
                char *l,commaL;
                if (lenX-ziffX > lenY-ziffY){
                    l = x;
                    commaL = commaX;
                }
                else{
                    l = y;
                    commaL = commaY;
                }
                int flag1=0;
                for(int i = 1 ; i <= leftZ; i++ ){
                    int t;

                    t = addTable[l[leftZ-i] - 48][flag];
                    
                    if(t>=9){
                        res[commaR-shortZ-i+1] = '0' + (t/1%10);
                        flag = 1;
                    }
                    else{
                        res[commaR-shortZ-i+1] = '0' + t;
                        flag = 0;
                    }

                }
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '0';
                res[index+1] = '\0';
                return res;
            }
        }
        else{
            if(leftZ == 0){
                res[commaR-shortZ-1] = '1';
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '0';
                
                res[index+1] = '\0';
                return res;
            }
            else{
                char *l,commaL;
                if (lenX-ziffX > lenY-ziffY){
                    l = x;
                    commaL = commaX;
                }
                else{
                    l = y;
                    commaL = commaY;
                }
                for(int i = 1 ; i <= leftZ; i ++){
                    res[commaR-shortZ-i+1] = l[leftZ-i];
                    printf("commaR = %d, shortZ = %d, i = %d, l[leftZ-i]=%c\n",commaR,shortZ,i,l[leftZ-i]);
                }
                for(int i = index ; i > 0; i--){
                    res[i] = res[i-1];
                }
                res[0] = '0';
                res[index+1] = '\0';
                return res;
            }
        }
        //--------------------
    }
    
    return res;
}

// int addR(int a, int flag){

// }



char mini(char *x, char *y, int commaX, int commaY, int lenX, int lenY){
    char res;  
    
    
    return res;
}

char multi(char *x, char *y, int commaX, int commaY, int lenX, int lenY){
    char res;
    
    
    
    return res;
}


