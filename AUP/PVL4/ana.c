#include<stdio.h>
#include<stdlib.h>

int ana(char * arr, char **dict, int dictLen,int nummer);

struct Argument{
    char *wort;
    char **dict;
    int len;
    void * (*fuc1)(struct Argument * obj);
};

void *setWort(struct Argument *obj);
int getLen(char *arr);

int main(){
    
    struct Argument demo;
    demo.fuc1 = &setWort;
    int dictLen;
    demo.fuc1(&demo);
    dictLen = demo.len-1;
    
    
    //int nummer = 0;
    for(int i = 0 ; i < dictLen ; i ++){
        ana(demo.wort,demo.dict,dictLen,i);
        //nummer++;
    }
    return 0;
}

int ana(char *arr, char **dict, int dictLen,int nummer){

    int wort[26]={0},maxLenInDict=0,resNu = nummer;
    char *p;
    char **res = (char **)malloc((sizeof(char *)));


    for(int i = 0; i < dictLen-1 ; i++){
        if( getLen(dict[i]) > getLen(dict[i+1])) {
            maxLenInDict = getLen(dict[i]);
        }
    }

    char d[dictLen][maxLenInDict+1] ;

    for(int i = 0; i< dictLen ; i++){
        for(int j = 0; j<getLen(dict[i]);j++){
            
            d[i][j] = dict[i][j];
            if(dict[i][j] <= 'Z'){
                d[i][j] = d[i][j] + 32;
            }
            if(j == getLen(dict[i])-1){
                d[i][j+1] = '\0';
                
            }
            
        }
    }
    

    p = arr;
    int satzLen=0,satzLenOhneLeer=0;
    int markLen[dictLen],markRes[dictLen],markOut[dictLen];

    satzLen = getLen(p);
    
    for(int i = 0; i < satzLen; i++){
        
        if(p[i]!='\040'){
            satzLenOhneLeer++;
            if(p[i]<='Z'){
                wort[(p[i]- 65)%26]++;
            }
            if(p[i]>='a'){
                wort[(p[i]- 97)%26]++;
            }
            
        }
    }

        int *index=NULL;
        int count = 0;
        int start = 0, subLen = 0;
        int flag = 0;

        int *elem = (int*)malloc(sizeof(int)), elemAnzahl = 0;
    for(int i = 0; i < dictLen ; i ++){
        
        elem = (int *)realloc(elem,sizeof(int)*(i+1));

        int tCount[26]={0};
        for(int j = 0; j < getLen(dict[i]); j++){
            int aph = -1;
            if((d[i][j]-96)%26 == 0){
                aph = 26;
            }
            else{
                aph = (d[i][j]-96)%26;
            }
            if(wort[aph - 1] == 0){
                tCount[aph - 1] = 0;
                elem[i] = 0;
                break;
            }
            else{
                tCount[aph - 1]++;
                
                if(tCount[aph - 1] > wort[aph - 1]){
                    
                    elem[i] = 0;
                    break;
                }
                else{
                    
                    elem[i] = 1;
                }
            }
            
            
        }
    }
    int elem1 = 0,st,end;
    for(int i = 0; i < dictLen ; i ++){
        if(elem[i]==1){
            elem1++;
        }
    }
    for(int i = 0; i < dictLen ; i++){
        if(elem[i] == 1){
            st = i;
            break;
        }
    }
    for(int i = dictLen - 1 ; i > 0; i--){
        if(elem[1] == 1){
            end = i;
            break;
        }
    }


    for(int i = 0; i < dictLen; i++){
        markLen[i] = getLen(dict[i]);
    }
    //==============================11111111111111111111111111111111111111111111
    //找到一行结果
    int count2 = 0, mL = -1;
    ///////while start
    while(1){

        
        for(int i = st; i < dictLen ; i++){
            if(elem[i] != 1){
                continue;
            }
            if(i == mL){
                mL=-1;
                continue;
            }
            
            
            
            markRes[i] = 0;
            
            
            for(int j = 0; j < markLen[i]; j++){
                int aph = -1;
                if((d[i][j]-96)%26 == 0){
                    aph = 26;
                }
                else{
                    aph = (d[i][j]-96)%26;
                }
                if(wort[aph - 1]>0){
                    flag = 1;
                    markRes[i]++;
                    wort[aph - 1]--;

                }
                else{
                    flag = 0;
                    for(int k = 0; k < j; k++){
                        wort[(d[i][k]-96)%26 - 1]++;
                    }
                    break;
                }

            }
                
        
            if(markRes[i] == markLen[i] && flag == 1){
                markOut[i] = 1;
                count++;
                index = (int *)realloc(index, sizeof(int)*(count+1));
                index[count-1] = i;
            }
            else{
                markOut[i] = 0;

                
            }

            
            
        }
        
        for(int i = 0; i < count ; i ++){
            subLen = subLen + getLen(dict[index[i]]);
        }
        
        if(subLen != satzLenOhneLeer) 
        {
            
            flag = 0;
            for(int j = 0 ; j < markLen[index[count-1]]; j++){
                int aph = -1;
                if((d[index[count-1]][j]-96)%26 - 1 == 0){
                    aph = 26;
                }
                else{
                    aph = (d[index[count-1]][j]-96)%26;
                }
                wort[aph - 1]++;
                
            }
                
            
            if(markOut[index[count-1]]){
                markOut[index[count-1]] = 0;
            }

            mL = index[count -1];
            
            index[count-1]=-1;
            index = (int *)realloc(index, sizeof(int)*(count));
            count=count - 1;

            if(count2 == count){
                break;
            }
            count2 = count;
            
            start = index[count - 1] + 1;
            
            subLen = 0;

        }
        else{
            break;
        }
        if(count2>0 && count == 1){
            break;
        }
        
    }
    //////while end
    
    
    //将当前记录的组合录入新建的res[h-st]----------------
    int subLen1=0;

    for(int h1 = 0; h1 < count ; h1++){
        subLen1 = getLen(d[index[h1]])+subLen1;
    }
    if(subLen1 == satzLenOhneLeer){
        res[nummer] = (char *)malloc(satzLenOhneLeer+count);
        res[nummer][satzLenOhneLeer+count-1] = '\0';
        
        for(int i = 0; i < count; i++){
            int tempLen = 0, t = 0;
            for (int j = 0; j < i+1; j++){
                tempLen = tempLen + getLen(d[index[j]]);

            }
            tempLen = tempLen + i;
            //printf("tempLen = %d, tempLen-getLen(d[index[i]]) = %d\n",tempLen,tempLen-getLen(d[index[i]]));
            for(int j = tempLen-getLen(d[index[i]]); j < tempLen; j ++){
                //printf("res[%d][%d] = %c | d[index[%d]][%d] = %c\n",h,j,res[h][j],i,t,d[index[i]][t]);
                res[nummer][j] = d[index[i]][t++];
                if(j == tempLen-1 && i < count - 1){
                    res[nummer][j+1] = '\040';
                }
            }
            
        }
        //printf("res[h-st] ==== %s\n",res[nummer]);
    }
    //=================================================
    //===============================2222222222222222222222222222222222222222222222


    //==========00000000============
    //printf("------>res[nummer] = %s\n",res[nummer]);
    int ls= -1;
    int wLen = 0;
    
    for(int h = st; h < dictLen ; h++){
        for(int i = 0 ; i < count -1 ; i++){
            wLen = wLen + getLen(d[index[i]]);
        }
        wLen = satzLenOhneLeer - wLen; //所需长度
        if(elem[h]!=1){
            continue;
        }
        int rSubLen = 0,rSubLenIndex = 0;
        for(int h1 = dictLen-1; h1 > st; h1--){
            if(elem[h1] == 1){
                rSubLenIndex = h1;
            }
        }
        
        //------------先返还，再计算
        for(int i1 = 0 ; i1 < getLen(d[index[count-1]]) ; i1++){
            
            int aph = -1;
            if((d[index[count-1]][i1]-96)%26 - 1 == 0){
                //printf("??????\n");
                aph = 26;
            }
            else{
                aph = (d[index[count-1]][i1]-96)%26;
                
            }
            //printf("aph = %d\n",aph);
            wort[aph - 1]++;
        }
        if(index[0]!=index[count -1]){
            h = index[count - 1];
        }
        else{
            break;
        }
        //printf("index[count -1] = %d\n",index[count -1]);
        index[count-1]=NULL;
        count=count - 1;
        
        nummer++;
        //printf("h = %d\n",h);
        
        //返还后，计算
        printf("start cacu\n");
        ///////while start
        int count3 = 0, mL1 = -1;
        while(1){
            //判断1个单词是否符合条件，若符合，则加入index
            //printf("dictLen = %d\n",dictLen);
            for(int i = h+1; i < dictLen ; i++){
                if(elem[i] != 1){
                    continue;
                }
                if(i == mL1){
                    mL1=-1;
                    continue;
                }
                
                //markLen[i] = getLen(dict[i]);
                markRes[i] = 0;
                //判断单词是否符合单词个数的条件，若是，则让wort的值减少
                printf("---markLen[%d] = %d\n",i, markLen[i]);
                for(int j = 0; j < markLen[i]; j++){
                    
                    int aph = -1;
                    if((d[i][j]-96)%26 == 0){
                        aph = 26;
                    }
                    else{
                        aph = (d[i][j]-96)%26;
                    }
                    if(wort[aph - 1]>0){
                        flag = 1;
                        markRes[i]++;
                        wort[aph - 1]--;
                    }
                    else{

                        flag = 0;
                        for(int k = 0; k < j; k++){
                            wort[(d[i][k]-96)%26 - 1]++;
                        }
                        break;
                    }

                }
                
                //确定搜索的单词是否和其长度相等，若相等，则加入index，总数count+1
                if(markRes[i] == markLen[i] && flag == 1){
                    markOut[i] = 1;
                    count++;
                    
                    index = (int *)realloc(index, sizeof(int)*(count+1));
                    //printf("bababababa\n");
                    index[count-1] = i;
                    //printf("index[count] = %d\n",index[count]);
                    printf("index[count-1] = %d\n",index[count-1]);
                    printf("index[count-2] = %d\n",index[count-2]);
                }
                else{
                    markOut[i] = 0;
                }
 
            }
            //printf("count||||||||| = %d\n",count);
            //printf("index[count-1] = %d\n",index[count-1]);
            int wLen2 = 0;
            for(int i = 0 ; i <count ; i ++){
                wLen2 = wLen2 + getLen(dict[index[i]]);
            }
            //printf("wLen2 = %d\n",wLen2);
            //根据新的index序列，判断长度是否和satzLenOhneLeer相等，若不，则返还，进行下一轮循环。
            if(wLen2 != satzLenOhneLeer) 
            {
                
                flag = 0;
                for(int j = 0 ; j < markLen[index[count-1]]; j++){
                    int aph = -1;
                    if((d[index[count-1]][j]-96)%26 - 1 == 0){
                        aph = 26;
                    }
                    else{
                        aph = (d[index[count-1]][j]-96)%26;
                    }
                    wort[aph - 1]++;
                    
                }
                    
                
                if(markOut[index[count-1]]){
                    markOut[index[count-1]] = 0;
                }

                mL1 = index[count -1];
                
                index[count-1]=-1;
                index = (int *)realloc(index, sizeof(int)*(count));
                count=count - 1;

                if(count3 == count){
                    break;
                }
                count3 = count;
                
                start = index[count - 1] + 1;
                
                subLen = 0;

            }
            else{
                break;
            }
            if(count3>0 && count == 1){
                break;
            }
            
        }
        //////while end
        //将当前记录的组合录入新建的res[h-st]----------------
        int subLen2=0;
        printf("d[index[count -2]] = %s\n",d[index[count -2]]);
        for(int h1 = 0; h1 < count ; h1++){
            printf("getLen ======= %d\n",getLen(d[index[h1]]));
            subLen2 = getLen(d[index[h1]])+subLen2;
        }
        printf("subLen2 = %d\n",subLen2);
        if(subLen2 == satzLenOhneLeer){
            resNu++;
            res[resNu] = (char *)malloc(satzLenOhneLeer+count);
            res[resNu][satzLenOhneLeer+count-1] = '\0';
            
            for(int i = 0; i < count; i++){
                int tempLen = 0, t = 0;
                for (int j = 0; j < i+1; j++){
                    tempLen = tempLen + getLen(d[index[j]]);

                }
                tempLen = tempLen + i;
                //printf("tempLen = %d, tempLen-getLen(d[index[i]]) = %d\n",tempLen,tempLen-getLen(d[index[i]]));
                for(int j = tempLen-getLen(d[index[i]]); j < tempLen; j ++){
                    //printf("res[%d][%d] = %c | d[index[%d]][%d] = %c\n",h,j,res[h][j],i,t,d[index[i]][t]);
                    res[resNu][j] = d[index[i]][t++];
                    if(j == tempLen-1 && i < count - 1){
                        res[resNu][j+1] = '\040';
                    }
                }
                
            }
            printf("res[h-st] ==== %s\n",res[resNu]);
        }
        //=================================================
        //=====::::::::::
    }
            
            

    //==========111111111============

    int pr=0;

    while(getLen(res[pr])>=satzLenOhneLeer){
        printf("res[%d] = %s\n", pr, res[pr]);
        pr++;
        if(getLen(res[pr])<satzLenOhneLeer){
            printf("===111===\n");
            
        }
    }
    printf("%s\n",res[1]);
    

    free(p);
    return resNu;
}

char *getStr(){
    int strLen = 5;
    char ch;
    char *str = (char *)malloc(sizeof(char *) * strLen);

    int count = 0;
    do{
        ch = getchar();
        count++;
        if(count >= strLen){
            str = (char *)realloc(str, sizeof(char *) * (++strLen));

        }
        str[count - 1] = ch;

    }while(ch != '\n');

    return str;
}

void * setWort(struct Argument *obj){
    char *Arg[] = {
        "Sxzytwqp Klj Yrtd",
        "Abc",
        "And",
        "Def",
        "Dxz",
        "k",
        "kx",
        "Ljsrt",
        "lt",
        "pt",
        "Ptyywq",
        "y",
        "Ywjsrq",
        "Zd",
        "zzx",
        '\0'
    };
    int dictLen = 0;
    obj -> wort = Arg[0];

    while(1){

        if(Arg[dictLen] == '\0'){
            break;
        }
        else{
            dictLen++;
        }
    }
    obj -> len = dictLen;

    for(int i = 0; i < dictLen; i++){
        if(i == dictLen-1){
            obj -> dict[i] = '\0';
            break;
        }
        if(i==0)
        {
            obj -> dict = (char**)malloc(sizeof(char*));
        }
        if(obj->dict != NULL){
            obj -> dict = (char **)realloc(obj->dict, sizeof(char*)*(i+1));
        }

        obj -> dict[i] = (char*)malloc(sizeof(char)*(getLen(Arg[i+1])));
        obj -> dict[i] = Arg[i+1];

    }
}

int getLen(char *arr){
    if(arr[0] != '\0'){
        return getLen(arr+1)+1;
    }
    else{
        return 0;
    }
}

