char *add(char *x, char *y, int len){
    char *res = (char*)calloc(len+2, sizeof(char)); // 用于保存结果，长度为原始长度+2，因为可能存在进位
    int lenR = len+1;
    for(int i = 0; i < lenR; i++){
        res[i] = '0';
    }
    res[len+1] = '\0';
    
    //加法有3种情况：1.都为正；2.都为负；（这两种情况可以用同样的算法） 3.一正一负（等与减法）
    //判断符号
    if(x[0] == y[0]){
        //情况1,2
        res[0] = x[0];
        int flag = 0;
        int i0 = 0;
        for(int i = len - 1  ; i > 0 ; i --){
            int t;
            if(x[i] == ','){
                res[lenR-1-i0] = ',';
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
                res[lenR-i0-1] = '0' + t1;
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
                res[lenR-i0-1] = '0' + t1;
                i0++;
                
            }

            if((flag == 1) && (i == 1)){
                
                res[1] = '0' + (t /10 %10);
            }
            if((flag == 0) && (i == 1)){
                //整数位不进位，则将数字向前移动1位
                for(int i = 1; i <lenR; i++){
                    res[i] = res[i+1];
                }
                res[lenR-1] = '\0';
            }
            
        }

        return res;
    }
    else{
        //变成减法
        return mini(x,y,len);
    }
    return 0;
}