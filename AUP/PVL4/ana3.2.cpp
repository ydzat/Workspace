#include<stdio.h>
#include<stdlib.h>
#include<exception>
#include<iostream>
using namespace std;
//------临时

//-----临时

char* ana(char * arr, char **dict, int dictLen,int nummer,char **res,int maxDiLen);
void moveChar(char *a, char *b);
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
    char **res = (char **)malloc((sizeof(char *)));
    //**res = NULL;


    // int minDiLen = 0,satzLen = 0;
    // for(int i = 0; i < getLen(demo.wort); i++){
    //     if(demo.wort[i]!='\040'){
    //         satzLen++;
    //     }
    // }
    // for(int i = dictLen -1 ; i>=0; i-- ){
    //     minDiLen = getLen(demo.dict[i])+ minDiLen;
    //     if(minDiLen > satzLen - getLen(demo.dict[0])){
    //         minDiLen = minDiLen - getLen(demo.dict[i]);
    //         break;
    //     }
    // }
    //printf("satzLen = %d,minDiLen = %d\n",satzLen,minDiLen);
    //printf("getLen(demo.dict[dictLen-1]) = %d\n",getLen(demo.dict[dictLen-1]));
    ana(demo.wort,demo.dict,dictLen,0,&res,-1);
    free(res);
    free(demo.wort);
    free(demo.dict);
    free(demo.fuc1);
    //free(ana);
    system("pause");
    //printf("====res[0] = %s\n",res[0]);
    return 0;
}

char* ana(char *arr, char **dict, int dictLen,int nummer,char **res,int maxDiLen){
    
    printf("start link!\n");
    
    // if(maxDiLen != -1){
    //     printf("res[1111] = %s\n",res[1]);
    // }


    int wort[26]={0},maxLenInDict=0,resNu = nummer;
    char *p;

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
    // printf("p[0] = %c, res[0][0] = %c\n",p[0],res[0][0]);
    satzLen = getLen(p);
    // int m[satzLen],mNum=0;
    // for(int i = 0; i < satzLen; i++){
    //     if(p[i] == res[0][i] && p[satzLen] == '\0'){
            
    //         m[i] = 1;
    //     }
    // }
    // for(int i = 0 ; i < satzLen ; i++){
    //     if(m[i]==1){
    //         mNum++;
    //     }
    // }
    // if(mNum == satzLen){
    //     printf("ssssssssssss = %n",p);
    //     return NULL;
    // }
    // if(res != NULL){
    //     for(int i = 0 ; i < nummer; i ++){
    //         printf("res[%d] = %s\n",i,res[i]);
    //     }
    // }

    //统计wort中的字母数
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


    //printf("nummer = %d\n",nummer);
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

    
    printf("nummer = %d\n",nummer);
    //无差别计算每个字典单词长度
    for(int i = 0; i < dictLen; i++){
        markLen[i] = getLen(dict[i]);
        //printf("markLen[%d] = %d\n",i,markLen[i]);
    }
    if(maxDiLen == -1){
        maxDiLen = 0;
        int zeit = 0;
        
        for(int i = 0; i < dictLen; i++ ){
            if(elem[i]==1 && zeit == 0){
                zeit++;
                continue;
                
            }
            if(elem[i]==1){
                maxDiLen = maxDiLen + markLen[i];
            }
        }
        //printf("maxDiLen = %d\n",maxDiLen);
    }
    //==============================11111111111111111111111111111111111111111111
    //找到一行结果
    int count2 = 0, mL = -1;
    ///////while start
    try{
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
    }
    catch(exception e){
        printf("hier ist prob!\n");
    }
    //////while end
    
    
    //将当前记录的组合录入新建的res[h-st]----------------
    int subLen1=0;
    //printf("bahdkashd   nummer = %d\n",nummer);
    for(int h1 = 0; h1 < count ; h1++){
        subLen1 = getLen(d[index[h1]])+subLen1;
    }
    int flag1 = 0;
    if(subLen1 == satzLenOhneLeer){
        
        res[nummer] = (char *)malloc(satzLenOhneLeer+count);
        //res[nummer] = NULL;
        flag1 = 1;

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
        if(getLen(res[nummer])<getLen(res[0])){

            int diff = 0,lenA,lenB;
            lenA = getLen(res[0]);
            lenB = getLen(res[nummer]);
            diff = lenA - lenB;
            char temp;
            for(int i = 0;i<lenB;i++){
                res[nummer][lenB - i - 1 +diff] = res[nummer][lenB - i - 1];
            }
            for(int i = 0; i < diff; i++){
                res[nummer][i] = res[0][i];
            }




            //moveChar(&res[0],&res[nummer]);
        }
        printf("res[%d] ==== %s\n",nummer,res[nummer]);
    }
    else{
        
        return NULL;
    }
    //=================================================
    //===============================2222222222222222222222222222222222222222222222

    
    //==========00000000============
    //printf("------>res[%d] = %s\n",nummer,res[nummer]);
    int ls= -1;
    int wLen = 0;
    
    if(flag1 == 1){
        nummer++;
        //printf("nummer = %d\n",nummer);
        res[nummer] = (char *)malloc(sizeof(char)*(nummer+1));
        //res[nummer] = NULL;
    }

    for(int h = st; h < dictLen ; h++){
        for(int i = 0 ; i < count -1 ; i++){
            wLen = wLen + getLen(d[index[i]]);
        }
        wLen = satzLenOhneLeer - wLen; //所需长度
        // if(elem[h]!=1){
        //     continue;
        // }
        int rSubLen = 0,rSubLenIndex = 0;
        for(int h1 = dictLen-1; h1 > st; h1--){
            if(elem[h1] == 1){
                rSubLenIndex = h1;
            }
        }
    
        //------------先返还，再计算
        int tIndex = index[count-1];
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
            //printf("h = %d\n",h);
        }
        else{
            //printf("ccccccc\n");
            break;
        }
        
        //printf("index[0] = %d\n",index[0]);
        index[count-1]=NULL;
        count=count - 1;
        if(index[0]==0){
            break;
        }
        
    
        //printf("h = %d\n",h);
        
        //返还后，计算
        // printf("res[nummer-1] = %s\n",res[nummer-1]);
        // char *a2 = (char)malloc(sizeof(char)*(satzLen - wLen-1));
        // a2 = res[nummer-1] + satzLen - wLen+1;
        
        
        int qLen=0;
        for(int i = 0 ; i < 26 ; i++){
            if(wort[i]!=0){
                for(int j = 0; j<wort[i];j++){
                    qLen++;

                }
            }
        }
        //printf("qLen = %d\n",qLen);
        char qT[qLen];
        int qI=0;
        for(int i = 0 ; i < 26 ; i++){
            if(wort[i]!=0){
                for(int j = 0; j < wort[i]; j++){
                    qT[qI++] = ( i + 1 + '0') + 48;
                    
                }
            }
            
        }
        // for(int i =0;i<6;i++){
        //     printf("qT[%d] = %c\n",i,qT[i]);
        // }
        // char *q = (char)malloc((sizeof(char))*(qLen+1));
        char *q =qT;
        // for(int i = 0 ; i < qLen ; i ++){
            
        //     q[i] = qT[i];
        //     printf("q[%d] = %c\n",i,q[i]);
        // }
        //printf("q = %s\n",q);
        
        
        char **di = (char *)malloc(sizeof(char*));
        //**di == NULL;
        int diLen = 0;
        for(int i = 0; i < dictLen - tIndex - 1; i++){
            di[i] = (char)malloc(sizeof(char)*markLen[tIndex + i]);
            di[i] = dict[tIndex+i+1];
            diLen = diLen + getLen(di[i]);
        }
        //printf("di[0] = %s\n",di[0]);
        //printf("start cacu\n");
        char *anag;
        // if(nummer == count){
        //     break;
        // }
        printf("h = %d\n",h);
        //printf("res[%d] = %s\n",nummer - 1,res[nummer-1]);
        //printf("res[1] = %s\n",res[1]);
        //printf("nummer ====== %d\n",nummer);

        //==================================================-----------------------------------------
        //printf("diLen = %d, maxDiLen = %d\n",diLen,maxDiLen);
        if(diLen < maxDiLen ){
            anag = ana(q,di,dictLen - tIndex - 1,nummer,&res[0],maxDiLen);
            
        }
        

        
        //res[nummer-1] = NULL;
        //printf("nummer = %d\n",nummer);
        
        // if(anag != NULL){
        //     printf("anag = %s\n",anag);
        // }
        
        free(di);
        
        //=================================================
        //=====::::::::::
    }
            
    

    //==========111111111============

    // int pr=0;

    // while(getLen(res[pr])>=satzLenOhneLeer){
    //     printf("res[%d] = %s\n", pr, res[pr]);
    //     pr++;
    //     if(getLen(res[pr])<satzLenOhneLeer){
    //         printf("===111===\n");
            
    //     }
    // }
    
    
    for(int i = 0 ; i < nummer; i++ ){
        printf("i = %d\n",i);
        printf("=== res[%d] = %s\n",i,res[i]);
    }


    free(p);
    free(elem);
    
    return res;
}

// char *getStr(){
//     int strLen = 5;
//     char ch;
//     char *str = (char *)malloc(sizeof(char *) * strLen);
//     //*str = NULL;
//     int count = 0;
//     do{
//         ch = getchar();
//         count++;
//         if(count >= strLen){
//             str = (char *)realloc(str, sizeof(char *) * (++strLen));

//         }
//         str[count - 1] = ch;

//     }while(ch != '\n');

//     return str;
// }

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

void moveChar(char *a, char *b){
    int diff = 0,lenA,lenB;
    lenA = getLen(a);
    lenB = getLen(b);
    diff = lenA - lenB;
    char temp;
    for(int i = 0;i<lenB;i++){
        b[lenA - i] = b[lenA-diff-i];
    }
    for(int i = 0; i < diff; i++){
        b[i] = a[i];
    }
}