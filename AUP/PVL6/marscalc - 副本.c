#include<stdio.h>
#include<stdlib.h>

long int getLen(char *p);
long int max(long int a, long int b);
long int min(long int a, long int b);
long int String2Int(char *str);

char *verarbeitZ(char *p);
char **plusNull(char *x, char *y);
long int getCommaSum(char *x, char *y);
char *allZ(char *p); //变为整数，形如1,234  ->  1234,0
char *endVerab(char *p);
// void freeD1(char *p);
// void freeD2(char **p,long int len);
long int mypow(long int x, long int y);

char *rechner(char *x, char *y, char *xt, char *yt, char opr, long int len, long int commaSum);
char *add(char *x, char *y, long int len);

char *mini(char *x, char *y, long int len);
char *miniR(char *x, char *y, long int len);
char *multi(char *xt, char *yt, long int len, long int commaSum);



char addTable[9][9]={
    {0,1,2,3,4,5,6,7,8},
    {1,2,3,4,5,6,7,8,10},
    {2,3,4,5,6,7,8,10,11},
    {3,4,5,6,7,8,10,11,12},
    {4,5,6,7,8,10,11,12,13},
    {5,6,7,8,10,11,12,13,14},
    {6,7,8,10,11,12,13,14,15},
    {7,8,10,11,12,13,14,15,16},
    {8,10,11,12,13,14,15,16,17}
    
};

char miniTable[18][18]={
    {0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16,-17,-18},
    {1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16,-17},
    {2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16},
    {3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15},
    {4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14},
    {5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13},
    {6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12},
    {7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11},
    {8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10},
    {10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8},
    {11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7},
    {12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6},
    {13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5},
    {14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4},
    {15,14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3},
    {16,15,14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2},
    {17,16,15,14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1},
    {18,17,16,15,14,13,12,11,10,8,7,6,5,4,3,2,1,0}
};


int main(int argc, char *argv[]){
    
    //'*'的处理
    if((argv[2][0] < 42) || (argv[2][0] > 45) || (argv[2][0] == 44)){
        argv[2][0] = 42;
    }
    //printf("argv[2][0] = %c\n",argv[2][0]);
    char *x = verarbeitZ(argv[1]), *y = verarbeitZ(argv[3]);
    
    
    char **xy = plusNull(x, y);
    char *xf = xy[0], *yf = xy[1];
    
    long int len = getLen(xf);
    long int commaSum = getCommaSum(x,y);
    


    
    

    //开始计算
    char *p = rechner(xf, yf, x, y, argv[2][0], len, commaSum);
    //printf("p = %s\n",p);
    char *p1 = endVerab(p);
    printf("%s",p1);
    
    
    



    // free(x);
    // free(y);
    // free(xf);
    // free(yf);
    // free(p);
    // free(xy[0]);
    // free(xy[1]);
    // free(xy);

    // freeD1(x);
    // freeD1(y);
    // freeD1(xf);
    // freeD1(yf);
    // freeD1(p);
    // freeD2(xy,2);

    return 0;
}


//-----------------------
long int getLen(char *p){
    char *end = p;
    while (*end != '\0'){
        end++;
    }
    return end - p;
}

long int max(long int a, long int b){
    if(a >=b){
        return a;
    }
    else{
        return b;
    }
}

long int min(long int a, long int b){
    if(a<=b){
        return a;
    }
    else{
        return b;
    }
}


//----------------------
char *verarbeitZ(char *p){
    long int lenP = getLen(p), commaP = 0;
    char *veraP;
    /*A
    判断是否有','，若commaP == lenP-1,则说明没有。
    若没有小数点，则在其后加上',0'。
    commaP的值为','的下标*/
    
    for(commaP; commaP < lenP; commaP++){
        
        if(p[commaP] == ','){
            
            break;
        }
    }
    
    if(commaP == lenP){ //为正
        //veraP = (char*)malloc(sizeof(char)*(lenP+4));
        veraP = (char*)calloc(lenP+4,sizeof(char));
        for(long int i = 0; i< lenP; i++){
            veraP[i] = p[i];

        }
        veraP[lenP] = ',';
        veraP[lenP+1] = '0';
        veraP[lenP+2] = '\0';
        
    }
    else{
        veraP = (char*)calloc(lenP+4,sizeof(char));
        for(long int i = 0; i< lenP; i++){
            veraP[i] = p[i];

        }
        veraP[lenP] = '\0';
    }
    /*A -- 正确*/

    /*B
    判断符号位是否存在，优先去除前导0，然后若为+，则加上前导符号'+'
    */
    if(veraP[0] == '0'){
        for(long int i = 0 ; i < commaP; i++){
            if(veraP[i] != '0'){
                veraP[i-1] = '+';
                veraP = veraP + i - 1;
                break;
            }
        }
    }
    
    if((veraP[0] == '-') && (veraP[1] == '0')){
        for(long int i = 1 ; i < commaP; i++){
            if(veraP[i] != '0'){
                veraP[i - 1] = '-';
                veraP = veraP + i - 1;
                break;
            }
        }
    }

    if((veraP[0] != '-')&& (veraP[0] != '+') && (veraP[0] != '0')){
        for(long int i = lenP+2; i > 0 ; i--){
            veraP[i] = veraP[i-1];
            
        }
        veraP[0] = '+';
        veraP[lenP+3] = '\0';
        
    }

    if((veraP[0] =='+') && (veraP[1] == '0')){
        for(long int i = 1 ; i < commaP; i++){
            if(veraP[i] != '0'){
                veraP[i - 1] = '-';
                veraP = veraP + i - 1;
                break;
            }
        }
    }

    
    
    /*B -- 正确*/
    
    return veraP;

}

char **plusNull(char *x, char *y){
    char **finalxy;
    
    //finalxy = (char**)malloc(sizeof(char*)*2);
    finalxy = (char**)calloc(2,sizeof(char*));
    /*C
    统一小数点和整数的长度，先去掉多余的0，然后补齐小数点长度短的后续的0
    */
    
    long int lenX = getLen(x), lenY = getLen(y);
    //printf("lenX = %d, lenY = %d\n",lenX,lenY);
    long int ziffX = lenX - 1, ziffY = lenY - 1, needNull;
    long int commaX = 0, commaY = 0 ; //','的下标
    //printf("xxxxxxx= %s   yyyyyyyyyyy= %s\n",x,y);
    while(x[ziffX] != ','){
        
        ziffX--;
        
    }
    
    ziffX = lenX - ziffX - 1;
    commaX = lenX - ziffX-1;
    while(y[ziffY] != ','){

        ziffY--;
        
    }
    ziffY = lenY - ziffY - 1;
    commaY = lenY - ziffY-1;
    
    long int lastNumX,lastNumY; //最后一位有效数字的下标
    for(long int i = lenX - 1  ; i > lenX - ziffX - 1; i--){
        if(x[i] != '0'){
            lastNumX = i;
            lenX = i + 1;

            x[i+1] = '\0';
            break;
        }
    }

    for(long int i = lenY - 1  ; i > lenY - ziffY - 1; i--){
        if(y[i] != '0'){
            lastNumY = i;
            lenY = i + 1;
            y[i+1] = '\0';
            break;
        }
    }

    long int ziffNeed;

    ziffX = lenX - commaX - 1;
    ziffY = lenY - commaY - 1;
    
    
    char *xt, *yt;  //用于对齐小数，是小数位对齐后的数字
    //对齐小数位
    if(ziffX != ziffY){
        if(ziffX > ziffY){
            //x长，对齐y
            //xt = (char*)malloc(sizeof(char)*(lenX+1));
            xt = (char*)calloc(lenX+1,sizeof(char));
            for(long int i = 0 ; i < lenX; i++){
                xt[i] = x[i];
            }
            xt[lenX] = '\0';
            ziffNeed = ziffX - ziffY;
            //yt = (char*)malloc(sizeof(char)*(lenY+1+ziffNeed));
            yt = (char*)calloc(lenY+1+ziffNeed,sizeof(char));
            for(long int i = 0 ; i < lenY; i++){
                yt[i] = y[i];
            }
            for(long int i = lenY; i < lenY+1+ziffNeed;i++){
                yt[i] = '0';
            }
            lenY = lenY + ziffNeed;
            yt[lenY] = '\0';
        }
        else{
            
            //yt = (char*)malloc(sizeof(char)*(lenY+1));
            yt = (char*)calloc(lenY+1,sizeof(char));
            for(long int i = 0 ; i < lenY; i++){
                yt[i] = y[i];
            }
            yt[lenY] = '\0';
            ziffNeed = ziffY - ziffX;
            //xt = (char*)malloc(sizeof(char)*(lenX+1+ziffNeed));
            xt = (char*)calloc(lenX+1+ziffNeed,sizeof(char));
            for(long int i = 0 ; i < lenX; i++){
                xt[i] = x[i];
            }
            for(long int i = lenX; i < lenX+1+ziffNeed;i++){
                xt[i] = '0';
            }
            lenX = lenX + ziffNeed;
            xt[lenX] = '\0';
        }
    }
    else{
        // xt = (char*)malloc(sizeof(char)*(lenX+1));
        // yt = (char*)malloc(sizeof(char)*(lenY+1));
        xt = (char*)calloc(lenY+1,sizeof(char));
        yt = (char*)calloc(lenY+1,sizeof(char));
        for(long int i = 0 ; i < lenX; i++){
            xt[i] = x[i];
        }
        xt[lenX] = '\0';
        for(long int i = 0 ; i < lenY; i++){
            yt[i] = y[i];
        }
        yt[lenY] = '\0';
    }
    
    //对齐整数位
    char *xf, *yf; //在小数位对齐的基础上，对齐整数位
    
    if(commaX != commaY){ //不等于说明整数位不等
        long int zNeed;
        if(commaX < commaY){
            //yf = (char*)malloc(sizeof(char)*(lenY+1));
            yf = (char*)calloc(lenY+1,sizeof(char));
            for(long int i = 0 ; i < lenY; i++){
                yf[i] = yt[i];
                
            }
            yf[lenY] = '\0';

            //x少，给x向前补齐zNeed位的0
            zNeed = commaY - commaX;
            // xf = (char*)malloc(sizeof(char)*(lenX+zNeed+1));
            xf = (char*)calloc(lenX+zNeed+1,sizeof(char));
            for(long int i = 0; i <lenX ; i++){
                xf[lenX + zNeed -1 -i] = xt[lenX-i-1];
                
            }
            for(long int i = 1; i <= zNeed ; i++){
                xf[i] = '0';
            }
            xf[0] = xt[0];
            lenX = lenX + zNeed;
            xf[lenX] = '\0';
        }
        else{
            //xf = (char*)malloc(sizeof(char)*(lenX+1));
            xf = (char*)calloc(lenX+1,sizeof(char));
            for(long int i = 0 ; i < lenX; i++){
                xf[i] = xt[i];
            }
            xf[lenX] = '\0';

            zNeed = commaX - commaY;
            // yf = (char*)malloc(sizeof(char)*(lenY+zNeed+1));
            yf = (char*)calloc(lenY+zNeed+1,sizeof(char));
            for(long int i = 0; i <lenY ; i++){
                yf[lenY + zNeed -1 -i] = yt[lenY-i-1];
            }
            for(long int i = 1; i <= zNeed ; i++){
                yf[i] = '0';
            }
            yf[0] = yt[0];
            lenY = lenY + zNeed;
            yf[lenY] = '\0';

        }
    }
    else{
        // xf = (char*)malloc(sizeof(char)*(lenX+1));
        // yf = (char*)malloc(sizeof(char)*(lenY+1));
        xf = (char*)calloc(lenX+1,sizeof(char));
        yf = (char*)calloc(lenY+1,sizeof(char));
        for(long int i = 0 ; i < lenX; i++){
            xf[i] = xt[i];
        }
        xf[lenX] = '\0';
        for(long int i = 0 ; i < lenY; i++){
            yf[i] = yt[i];
            
        }
        yf[lenY] = '\0';
    }

    // finalxy[0] = (char*)malloc(sizeof(char)*lenX);
    // finalxy[1] = (char*)malloc(sizeof(char)*lenY);
    finalxy[0] = (char*)calloc(lenX+1,sizeof(char));
    finalxy[1] = (char*)calloc(lenY+1,sizeof(char));
    for(long int i = 0; i < lenX ; i++){
        finalxy[0][i] = xf[i];
        finalxy[1][i] = yf[i];
    }
    finalxy[0][lenX] = '\0';
    finalxy[1][lenY] = '\0';
    return finalxy;
    /*C*/

}

long int getCommaSum(char *x, char *y){
    long int sum=0;
    long int ziffX = 0, ziffY = 0;
    long int lenX = getLen(x), lenY = getLen(y);
    while(x[ziffX] != ','){
        ziffX++;
    }
    ziffX = lenX - ziffX - 1;
    while(y[ziffY] != ','){
        ziffY++;
    }
    ziffY = lenY - ziffY - 1;
    if((ziffX == 1) && (x[getLen(x)-1] == '0')){
        ziffX = 0;
    }
    if((ziffY == 1) && (y[getLen(y)-1] == '0')){
        ziffY = 0;
    }

    sum = ziffX + ziffY;
    //printf("sum = %d\n",sum);
    return sum;



    return sum;
}

char *allZ(char *p){
    long int lenP = getLen(p);
    long int lenNew = lenP + 1;
    char *newP = (char*)calloc(lenP+2,sizeof(char));
    newP[0] = '0';
    newP[lenNew] = '\0';
    newP[lenNew-1] = '0';
    newP[lenNew-2] = ',';
    long int i0 = lenNew-3;
    for(long int i = lenP -1; i >=0 ; i--){
        
        if((p[i] == ',') || ((i == lenP-1) && (p[i] == '0'))){
            continue;
        }
        newP[i0] = p[i];
        //printf("newP[%d] = %c\n",i0,newP[i0]);
        i0--;
    }
    if(newP[0] == '0'){
        newP = newP + 1;
    }
    //printf("newP = %s\n",newP); //此时已经变为：符号正数逗号0
    return newP;
}

long int String2Int(char *str)//字符串转数字 
{
    char flag = '+';//指示结果是否带符号 
    long res = 0;
    
    if(*str=='-')//字符串带负号 
    {
        ++str;//指向下一个字符 
        flag = '-';//将标志设为负号 
    } 
    //逐个字符转换，并累加到结果res 
    while(*str>=48 && *str<57)//如果是数字才进行转换，数字0~9的ASCII码：48~57 
    {
        res = 10*res+  *str++-48;//字符'0'的ASCII码为48,48-48=0刚好转化为数字0 
    } 
 
    if(flag == '-')//处理是负数的情况
    {
        res = -res;
    }
 
    return (long int)res;
}

// void freeD1(char *p){
//     if(p!=NULL){
//         free(p);
//     }
// }
// void freeD2(char **p, long int len){
//     while(len != 0){
//         if(p[len-1]!=NULL){
//             free(p[len-1]);
//         }
//         len--;
//     }
//     if(p != NULL){
//         free(p);
//     }
// }


char *endVerab(char *p){
    long int lenP = getLen(p);
    int cutNull = 0;
    while(p[cutNull+1] == '0'){
        cutNull++;
    }

    if(p[0] == '+'){
        p = p + cutNull+1;
        lenP = lenP - cutNull - 1;
    }
    if(p[0] == '-'){
        p = p + cutNull ;
        p[0] = '-';
        lenP = lenP - cutNull;
    }
    
    //printf("lenP=%d\n",lenP);
    //printf("p = %s\n",p);
    if(p[lenP-1] == '0'){
        // p[lenP-2] = '\0';
        // p[lenP-1] = '\0';
        long int t = lenP-1;
        while(p[t] =='0'){
            p[t] = '\0';
            t--;
        }
        if(p[t] == ','){
            p[t] = '\0';
            t--;
        }
    }
    
    return p;
}


long int mypow(long int x,long int y)  
{  
    long int result = 1;
    while(y--){
        result *=x;
    }
  
    return result;  
} 

//----------------------

char *add(char *x, char *y, long int len){
    char *res = (char*)calloc(len+3, sizeof(char)); // 用于保存结果，长度为原始长度+2，因为可能存在进位
    long int lenR = len+1;
    for(long int i = 0; i < lenR; i++){
        res[i] = '0';
    }
    res[len+1] = '\0';

    long int fstShortZ=1; //短的数字的第一个有效数字的下标
    if(x[1] == '0'){
        while(x[fstShortZ] == '0'){
            fstShortZ++;
        }
    }
    if(y[1] == '0'){
        while(y[fstShortZ] == '0'){
            fstShortZ++;
            //printf("fstShortZ = %d====\n",fstShortZ);
        }
    }
    //printf("x = %s  y = %s\n",x,y);
    //printf("y[1] = %c\n",y[1]);
    //printf("fstShortZ = %d\n",fstShortZ);
    //在加法循环中，从小数一直循环到最低的数字下标
    //加法有3种情况：1.都为正；2.都为负；（这两种情况可以用同样的算法） 3.一正一负（等与减法）
    //判断符号
    if(x[0] == y[0]){
        //情况1,2
        res[0] = x[0];
        int flag = 0;
        long int i0 = 0;

        for(long int i = len-1   ; i >= fstShortZ ; i --){

            int t;
            if(x[i] == ','){
                res[i+1] = ',';
                i0++; 
                continue;
            }
            if(flag == 1){
                
                t = addTable[x[i]-48][y[i]-48];

                int t1;
                if(t>=9){
                    t1 = t/1%10;
                    t1 = addTable[t1][1];
                    flag = 1;
                }
                else{
                    t1 = t;
                    t1 = addTable[t1][1];
                    flag = 0;
                }
                res[i+1] = '0' + t1;
                i0++;
            }
            else{
                
                t = addTable[x[i] - 48][y[i] - 48];
                int t1;
                
                
                if(t>=9){
                    t1 = t/1%10;
                    flag = 1;
                }
                else{
                    t1 = t;
                    flag = 0;
                }

                res[i+1] = '0' + t1;

                i0++;
                

            }
            //printf("1 = %d, t = %d\n",i,t);
            // if((flag == 1) && (i == 1)){
            //     printf("res = %s\n",res);
            //     res[1] = 49;
                
            // }
            // if((flag == 0) && (i == 1)){
            //     //整数位不进位，则将数字向前移动1位
            //     // for(long int j = 1; j <lenR; j++){
            //     //     res[j] = res[j+1];
            //     // }
            //     res[1] = res[0];
            //     res = res + 1;
            //     //res[lenR-1] = '\0';
            // }
            
        }
        //printf("flag = %d\n",flag);
        //若长度相等，即fstShortZ == 1
        if((fstShortZ == 1) && (flag == 1)){
            res[1] = '1';
            //printf("res = %s\n",res);
        }

        //整数多余的部分进位并赋值给res
        int flag2= 0;
        
        for(int i = 1; i < len; i++){
            if(x[i]<y[i]){
                flag2 = 1;
                break;
            }
            
        }
        if(x[1] == '0'){
            flag2 = 1;
        }
        if(y[1] == '0'){
            flag2 = 0;
        }
        //printf("flag = %d, flag2 = %d\n",flag,flag2);
        if((flag == 1) && (fstShortZ != 1)){
            if(flag2 == 0){
                
                for(int i = fstShortZ ; i >1; i --){
                    if(x[i-1] == '8'){
                        for(int j = i-1; j > 0 ; j--){
                            if(x[j] == '8'){
                                x[j] = '0';
                            }
                            else{
                                x[j] = x[j] + 1;

                                break;
                            }
                            
                        }
                        if(x[1] == '0'){
                            res[1] = '1';
                        }
                        res[i] = x[i-1];
                        
                    }
                    else{
                        x[i-1] = x[i-1]+1;
                        
                        for(int j = i; j>0;j--){
                            //printf("")
                            //printf("x[i-1] = %c\n",x[i-1]);
                            res[j] = x[j-1];
                            //printf("res[%d] = %c\n",j,res[j]);
                        }
                        
                        res[1] = res[0];
                        res++;
                        
                        break;
                    }
                }
            }
            else{
                for(int i = fstShortZ ; i >1; i --){
                    if(x[i-1] == '8'){
                        for(int j = i-1; j > 0 ; j--){
                            if(x[j] == '8'){
                                x[j] = '0';
                                
                                
                            }
                            else{
                                x[j] = x[j] + 1;

                                break;
                            }
                            
                        }
                        if(x[1] == '0'){
                            res[1] = '1';
                        }
                        res[i] = x[i-1];
                        
                    }
                    else{
                        x[i-1] = x[i-1]+1;
                        for(int j = i; j>0;i--){
                            res[i] = x[i-1];
                        }
                        res[1] = res[0];
                        
                        res++;
                        break;
                    }
                }
            }

            
        }
        if((flag == 0) && (fstShortZ != 1)){//整数多余的部分直接赋值给res
            if(flag2 == 0){ //x>y
                for(int i = fstShortZ; i>0;i--){
                    res[i] = x[i-1];
                }
                res[1] = res[0];
                res++;
                
            }
            else{
                for(int i = fstShortZ; i>0;i--){
                    res[i] = y[i-1];
                }
                res[1] = res[0];
                res++;
                
            }
        }

        return res;
    }
    else{
        //变成减法
        //printf("1111111111111111111111111111\n");
        if(x[0] == '-'){
            x[0] = '+';
            return mini(y,x,len);
        }
        if(x[0] == '+'){
            y[0] = '-';
            return mini(x,y,len);
        }
        
    }
    return 0;
}



//----------------------------------


char *mini(char *x, char *y, long int len){
    
    char *res;
    /*
    1. -x - -y  = +y - x 结果可能为'+'或'-'
    2. -x - y = - (x + y) 结果为'-'，等于加法
    3. x - -y = x+y 结果为'+'，等于加法
    4. x - y 结果可能为'+'或'-'
    即 1/4一类，2/3一类
    */
    //printf("x = %s    y = %s\n",x,y);
    //1,4
    int flag = 0;
    if( x[0] == y[0] ){
        if(x[0] == '+'){ // x - y
            
            char *t = miniR(x,y,len);
            long int lenT = getLen(t);
            res = (char*)calloc(lenT+1,sizeof(char));
            res[lenT] = '\0';
            for(long int i = 0 ; i < lenT; i++){
                res[i] = t[i];
            }
        }
        else{ // y - x
            x[0] = '+';
            y[0] = '+';
            char *t = miniR(y,x,len);
            long int lenT = getLen(t);
            res = (char*)calloc(lenT+1,sizeof(char));
            res[lenT] = '\0';
            for(long int i = 0 ; i < lenT; i++){
                res[i] = t[i];
            }
        }  
    }
    else{//2,3
        
        if(x[0] == '+'){// x + y
            y[0] = '+';
            return add(x,y,len);
        }
        else{ // - ( x + y )
            //printf("==========\n");
            x[0] = '+';
            y[0] = '+';
            char *t = add(x,y,len);
            
            long int lenT = getLen(t);
            
            res = (char*)calloc(lenT+1,sizeof(char));
            res[0] = '-';
            res[lenT] = '\0';
            
            for(long int i = 1 ; i < lenT; i++){
                res[i] = t[i];
            }
            
        }
        
    }
    
    
    return res;
}

char *miniR(char *x, char *y, long int len){ //正数相减 x-y

    //判断最高位的值，最高位的值的下标为1。最长的整数长度为longZ,长度差为deffZ。
    long int commaX = 0, commaY = 0;
    while(x[commaX] != ','){
        commaX++;
    }
    while(y[commaY] != ','){
        commaY++;
    }
    long int fstNumX = 1, fstNumY = 1;
    while(x[fstNumX] == '0'){
        fstNumX++;
    }
    while(y[fstNumY] == '0'){
        fstNumY++;
    }
    long int longX = commaX - fstNumX, longY = commaY - fstNumY;
    long int longZ = max(longX,longY),shortZ = min(longX,longY), deffZ = longZ - shortZ;
    

    
    char *res = (char*)calloc(len+1, sizeof(char));
    res[len] = '\0';

    long int flag = 0, flag2 = 0, i0 = 0; //flag2 用于判断x 和y谁大。flag2 = 0表示x大，flag2=1表示y大

    if(x[1]>y[1]){
        flag2 = 0;
    }
    if(x[1] == y[1]){
        for(long int i = 2; i < len ; i ++){
            if(i == commaX){
                continue;
            }
            if(x[i]<y[i]){
                flag2 = 1;
                break;
            }
            if((i == len - 1) && (x[i] >= y[i])){
                flag2 = 0;
            }
        }
        
    }
    if(x[1]<y[1]){
        flag2 = 1;
    }


    if(flag2 == 1){
        for(long int j = 0; j < len ; j ++){
            char temp = y[j];
            y[j] = x[j];
            x[j] = temp;
        }
    }

    for(long int i = len-1; i >0; i--){
        if(x[i] == ','){
            res[len - i0 - 1] = ',';
            i0++;
            continue;
        }
        //if(flag2 == 0){//x的数值大于y的数值
            //int xNum = x[i] - 48;
            int t;
            if(x[i] < y[i]){ //需要借位,x可能为0,1,2,3,4,5,6,7
                int xNum = x[i] - 48;
                xNum = xNum + 9;
                t = miniTable[xNum][y[i]-48];
                
                flag = 1;
                if((x[i-1] == '0') || ((x[i-1] == ',') && (x[i-2] == '0'))){
                    long int start = 1;
                    while(x[start] == '0'){
                        start ++;
                    }
                    for(long int j = start; i <= i-1; j ++){
                        if(x[j] > '0'){
                            x[j] = x[j] - 1;
                        }
                        if(x[j] == '0'){
                            x[j] = 57;
                        }
                    }
                }
                if((x[i-1] != '0') && (x[i-1] !=',')){
                    x[i-1] = x[i-1] -1;
                }
                if((x[i-1] == ',') && (x[i-2] != '0')){
                    x[i-2] = x[i-2] -1;
                }


            }
            else{ //不需要借位，x可能为0,1,2,3,4,5,6,7,8。
                t = miniTable[x[i]-48][y[i]-48];
                flag = 0;

            }
            res[len - i0 -1] = '0' + t;
            i0++;
        // }
        // else{
        //     //交换x,y的值
            
        //     for(int j = 0; j < len ; j ++){
        //         char temp = y[j];
        //         y[j] = x[j];
        //         x[j] = temp;
        //     }
        //     printf("x = %s  y = %s======\n",x,y);
        //     int t;
        //     if(x[i] < y[i]){ //需要借位,x可能为0,1,2,3,4,5,6,7
        //         int xNum = x[i] - 48;
        //         xNum = xNum + 9;
        //         t = miniTable[xNum][y[i]-48];
        //         printf("xNum = %d, t = %d\n",xNum,t);
        //         flag = 1;
        //         if((x[i-1] == '0') || ((x[i-1] == ',') && (x[i-2] == '0'))){
        //             int start = 1;
        //             while(x[start] == '0'){
        //                 start ++;
        //             }
        //             for(int j = start; i <= i-1; j ++){
        //                 if(x[j] > '0'){
        //                     x[j] = x[j] - 1;
        //                 }
        //                 if(x[j] == '0'){
        //                     x[j] = 57;
        //                 }
        //             }
        //         }
        //         if((x[i-1] != '0') && (x[i-1] !=',')){
        //             x[i-1] = x[i-1] -1;
        //         }
        //         if((x[i-1] == ',') && (x[i-2] != '0')){
        //             x[i-2] = x[i-2] -1;
        //         }


        //     }
        //     else{ //不需要借位，x可能为0,1,2,3,4,5,6,7,8。
        //         t = miniTable[x[i]-48][y[i]-48];
        //         flag = 0;

        //     }
        //     res[len - i0 -1] = '0' + t;
        //     i0++;

        // }
    }

    
    

    if((res[0] != '+') && (res[0] !='-') ){
        i0 = 1;
        while((res[i0] == '-') || (res[i0] == '+')){
            i0++;
        }
        res = res + i0 - 1;
    }
    if(flag2 == 1){
        res[0] = '-';
    }
    else{
        res[0] = '+';
    }


    return res;
}


char *multi(char *xt, char *yt, long int len, long int commaSum){
    
    char **res;
    

    //这里处理yt，并给lenR赋值
    char *y = allZ(yt);
    long int lenR = getLen(y)-3, lenX = getLen(xt);
    char *y0 = (char*)calloc(lenR+1,sizeof(char));
    y0[lenR] = '\0';
    for(long int i = 1; i < lenR+1; i ++){
        y0[i-1] = y[i];
    }
    
    lenR = (long int)String2Int(y0)-1;

    if(lenR < 0){
        lenR = lenR * (-1);
    }
    long int t = lenR,n = 0,lenR9=0;
    while(t){ 
        t = t/10;
        n++;
    }
    //printf("n = %d\n",n);
    //printf("lenR+1 = %d\n",lenR+1);
    
    for(long int i = 1 ; i <=n ; i++){
        
       lenR9 = lenR9 + ((lenR+1)/mypow(10,i-1)%10)*mypow(9,i-1);
       //printf("lenR9 = %d\n",lenR9);
    }
    lenR = lenR9-1;
    //printf("lenR = %d\n",lenR);
    //printf("y0 = %s\n",y0);
    //初始化res，lenR即 无符号乘数 y0 - 1。表示 加lenR次，有lenR个结果
    //printf("lenR = %d, y0 = %s\n",lenR,y0);
    //res = (char**)malloc(sizeof(char*)*(lenR+1));
    // res = (char**)calloc(lenR+1,sizeof(char*));
    res = (char**)calloc(2,sizeof(char*));
    res[0] = (char*)calloc(2*len, sizeof(char));
    res[1] = (char*)calloc(2*len, sizeof(char));
    int count = 1;
    //printf("hhhhhhhhh\n");
    //相当于循环调用加法
    //1.都为正；2.都为负；3.一正一负
    //1.符号为'+'；
    //2.符号为'+'；
    //3.符号为'-'
    /*
    思路：先统计两个原始数据x,y的小数位个数之和sumComma，然后去掉原始的小数点，变成两个整数的乘法-> 连续y次的x相加。
    最终得到的和，再从后向前数sumComma位，其中的值依次向后移动1位，并在res[sumComma](存疑)存入','，然后从后向前数'0'，去掉多余的尾部'0'。
    最后添加'\0'
    */
    /*对x,y的处理：
    需要xt,
    y需要变成yt
    */
    //step 1: 统计两个数值的小数位之和，即commaSum
    //step 2: 移动','，让两个数据变成xxxx,0
    /*思路：让原始长度+2，然后定位到','，
    然后其后的数据依次向前移动1位，
    然后在x[lenX-1]存入','，
    在x[lenX]处存入0，在x[lenX+1]处存入'\0'*/
    //printf("xt = %s, yt = %s\n",xt,yt);
    int flag0 = 0;//0表示1,2。1表示3
    if(xt[0] == yt[0]){ //1,2
        xt[0] = '+';
        yt[0] = '+';
        flag0 = 0;
        //printf("lenR = %d\n",lenR);
        
    }
    else{ //3
        xt[0] = '+';
        yt[0] = '+';
        flag0 = 1;
        // for(long int i = 0; i < lenR; i++){
        //     long int lenRt;
            
        //     if(i != 0){
                
        //         char **xy = plusNull(res[i-1],xt);
        //         lenRt = getLen(xy[0]);
        //         char *t = add(xy[0],xy[1],lenRt);
        //         long int lenT = getLen(t);
        //         res[i] = (char*)calloc(lenT+1,sizeof(char));
        //         //res[i][0] = '+';
        //         res[i][lenT] = '\0';
        //         for(long int j = 0; j < lenT; j ++){
        //             res[i][j] = t[j];
        //         }
                
        //     }
        //     else{
                
        //         char *t = add(xt,xt,lenX);
        //         long int lenT = getLen(t);
        //         res[i] = (char*)calloc(lenT+1,sizeof(char));
        //         //res[i][0] = '+';
        //         res[i][lenT] = '\0';
        //         for(long int j = 0; j < lenT; j ++){
        //             res[i][j] = t[j];
        //         }
                
        //     }
            
            
        // }
        // res[lenR-1][0] = '-';
        
        
    }

    for(long int i = 0; i < lenR; i++){
        long int lenRt;
        
        if(i != 0){
            //printf("start ====================,i = %d\n",i);
            //printf("res[i-1] = %s, xt = %s\n",verarbeitZ(res[i-1]),verarbeitZ(xt));
            char **xy = plusNull(verarbeitZ(res[count]),verarbeitZ(xt));
            //printf("xy[0] = %s, xy[1] = %s\n",xy[0],xy[1]);
            lenRt = getLen(xy[0]);
            //printf("222222\n");
            
            xy[0][0] = '+';
            xy[1][0] = '+';
            char *t = add(xy[0],xy[1],lenRt);
            //printf("33333\n");
            //printf("t = %s\n",t);
            long int lenT = getLen(t);
            //res[!count] = (char*)calloc(lenT+1,sizeof(char));
            //res[i][0] = '+';
            
            
            //free(res[!count]);
            //printf("res[!count] ==== %s\n",res[!count]);
            //printf("res[count] ==== %s\n",res[count]);
            
            if(res[!count][0] != '\0'){
                //res[!count] = '\0';
                res[!count][lenT] = '\0';
            }
            //printf("==================\n");
            for(long int j = 0; j < lenT; j ++){
                //printf("1111111111\n");
                res[!count][j] = t[j];
                //printf("res[!count][%d] = %c\n",j,res[!count][j]);
            }
            //printf("res[!count] = %s\n",res[!count]);
            count = !count;
            // free(xy[0]);
            // free(xy[1]);
            // free(xy);
        }
        else{
            
            char *t = add(xt,xt,lenX);
            long int lenT = getLen(t);
            //res[i] = (char*)calloc(lenT+1,sizeof(char));
            //res[i][0] = '+';
            //res[!count][lenT] = '\0';
            for(long int j = 0; j < lenT; j ++){
                res[0][j] = t[j];
            }
            //printf("res[0] = %s\n",res[0]);
            count = 0;

        }
        //printf("res[count] = %s\n",res[count]);
        
    }
    //printf("res[0] = %s\n",res[0]);
    //printf("res[1] = %s\n",res[1]);
    if(flag0 == 0){
        res[count][0] = '+';
    }
    else{
        res[count][0] = '-';
    }
    //printf("--->res[count] = %s\n",res[count]);
    /*
    截止到现在，数值对了，现在需要移动小数位commaSum
    */
    //printf("commaSum = %d\n",commaSum);
    long int lenRes = getLen(res[count]);
    if(res[count][lenRes-1] == '0'){
        //若尾数为0，则移动commaSum位
        commaSum = commaSum;
    }
    else{//否则移动commaSum - 1位
        commaSum--;
        
    }




    for(long int i = lenRes-2; i > lenRes-2 -commaSum; i--){
        res[count][i] = res[count][i-1];
    }
    res[count][lenRes-2-commaSum] = ',';
    //printf("res[count] = %s\n",res[count]);
    
    //return verarbeitZ(res[count]);
    
    return res[count];
}


//-----------------------
char *rechner(char *x, char *y, char *xt, char * yt, char opr, long int len, long int commaSum){
    char *res = (char*)calloc(len+2,sizeof(char));
    switch(opr){
        
        case '+':
            //printf("jia fa x = %s, y = %s, len = %d\n",x,y,len);
            res = add(x,y,len);
            return res;
        case '-':

            res = mini(x,y,len);
            return res;
        case '*':
            
            return multi(xt,yt,len, commaSum);
            
    }
    //return '\0';
}