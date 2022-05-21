#include<stdio.h>
#include<stdlib.h>

//------临时

//-----临时

char* ana(char * arr, char **dict, int dictLen,int nummer,char **res,int maxDiLen,int *originalLen,int f);
void moveChar(char *a, char *b);
struct Argument{
    char *wort;
    char **dict;
    int len;
    void * (*fuc1)(struct Argument * obj);
};


struct Res{
    char **res;
    int len;
};

void *setWort(struct Argument *obj);
int getLen(char *arr);

int dictReMake(struct Argument *obj,int dictLen);

int main(){
    
    struct Argument demo;
    demo.fuc1 = &setWort;
    int dictLen;
    demo.fuc1(&demo);
    dictLen = demo.len-1;
    printf("maxIndex\n");
    char **res = (char **)malloc((sizeof(char *)));
    //printf("getLen(res) = %d\n",getLen(res));
    
    for(int i = 0; i < getLen(res);i++)
    {
        res[i] = '\0';
    }
    
    
    int minLen = 0,satzOhneLeer=0;
    for(int i = 0; i < getLen(demo.wort); i++){
        if(demo.wort[i]!='\040'){
            satzOhneLeer++;
        }
    }
    int maxIndex ;
    for(int i = dictLen -1; i >=0; i--){
        minLen = minLen + getLen(demo.dict[i]);
        if(minLen > satzOhneLeer){
            maxIndex = i;
            break;
        }
    }
    minLen = dictLen - maxIndex-1;
    
    int resLen = 0;
    char * anag ;
    //printf("dictLen = %d, minLen = %d\n",dictLen, minLen);
    while(dictLen > minLen){
        //printf("dictLen = %d\n",dictLen);
        //printf("demo.dictLen[0] = %s\n",demo.dict[0]);
        // printf("demo.dict[%d] = %s\n",dictLen-1 ,demo.dict[dictLen-1]);
        printf("============================================================== in main ==========\n");
        //printf("demo.dict[0] = %s,dictLen = %d,demo.dict[dictLen-1] = %s\n",demo.dict[0],dictLen,demo.dict[dictLen-1]);
        sturct Res 
        anag = ana(demo.wort,demo.dict,dictLen,resLen,res,-1,satzOhneLeer,0);
        dictLen = dictReMake(&demo,dictLen);
        printf("==========back to main================================================================\n");
        //printf("getLen(res) = %d\n",getLen(res));
        if(dictLen < minLen){
            break;
        }
        while(1){
            int flag = 0;
            
            for(int j = 0 ; j < getLen(res); j ++){
                if(res[j]!='\0'){
                    int resjLen = 0;
                    for(int k = 0; k < getLen(res[j]); k++){
                        if(res[j][k]!='\040'){
                            resjLen++;
                        }
                        if(res[j][k]=='\0'){
                            break;
                        }
                    }
                    if(resjLen == satzOhneLeer){
                        resLen++;
                        //printf("nach cacu resLen = %d\n",resLen);
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                else{
                    flag = 1;
                    break;
                }

            }
            if(flag == 1){
                break;
            }
        }
        
        //printf("resLen = %d\n",resLen);
        int resLen3 = 0;
        for(int i = 0; i < getLen(res[0]); i++){
            if(res[0][i]=='\0'){
                break;
            }
            if(res[0][i]!='\040'){
                resLen3++;
            }
            
        }
 
        int fstWortLen = 0;
        char *fstWort = (char*)malloc(sizeof(char));
        
        for(int i = 0; i < demo.len ; i++){
            if(res[0][i]=='\040'){
                break;
            }
            fstWort[i] = (char*)realloc(fstWort[i],sizeof(char)*(i+1));
            fstWort[i] = res[0][i];
            fstWortLen++;

        }
        
        fstWort[fstWortLen] = '\0';
        int fstWortIndex;
        //printf("hhhhhhhh1111111111\n");
        for(int i = 0 ; i <dictLen; i++){
            
            int len = getLen(demo.dict[i]);
            char *wInD = (char*)malloc(sizeof(char)*len);
            *wInD = NULL;
            //*wInD = demo.dict[i];
            for(int j = 0; j < len; j++){
                wInD[j] = (char*)realloc(wInD[j],sizeof(char)*(j+1));
                wInD[j] = demo.dict[i][j];
                if(wInD[j]<'Z'){
                    wInD[j] = wInD[j] + 32;
                }
            }
            wInD[len] = (char*)realloc(wInD[len],sizeof(char)*(len+1));
            wInD[len] = '\0';
            // if(*wInD == *fstWort){
            //printf("wInD = %s, fstWort = %s\n",wInD,fstWort);
            //printf("len = %d\n",len);
            //     fstWortIndex = i;
            //     break;
            // }
            int flagg = 0;
            for(int j = 0; j < len; j++){
                if(wInD[j]!=fstWort[j]){
                    //printf("----%s\n",wInD);
                    //printf("----%d\n",flagg);
                    fstWortIndex = 0;
                    break;
                }
                if(j == len -1 && wInD[j] == fstWort[j]){
                    fstWortIndex = i;
                    flagg = 1;
                    //printf("====%s\n",wInD);
                }
            }
            if(flagg == 1){
                break;
            }
            if(flagg == 0 && i == dictLen - 1){
                fstWortIndex = 0;
            }
        }
        //printf("fsWortIndex = %d\n",fstWortIndex);
        //printf("demo.dict[0] = %s\n",demo.dict[0]);
        for(int i = 0 ; i < fstWortIndex ; i ++){
            dictLen = dictReMake(&demo,dictLen);

            //printf("demo.dict[0] = %s\n",demo.dict[0]);
        }
        if(resLen3 != satzOhneLeer || resLen == 0){
            
            // for(int i = 0; i < resLen ; i++){
            //     res[i] = '\0';
            // }
            for(int i = 0; i < getLen(res);i++)
            {
                res[i] = '\0';
            }
            res = (char**)realloc(res,sizeof(char*));
           
            resLen = 0;
        }
        //printf("resLen = %d\n",resLen);
    }
    
    
    int i = 0;
    //printf("getlen(*res) = %d\n",getLen(*res));
    printf("=================OUTPUT in main==================\n");
    
    while(1){
        // for(int a=0;a<getLen(res[i]);a++){
        //     if(res[i] == '\0'){
                
        //         res[i] = (char*)realloc(res[i],i*sizeof(char));
        //         break;
        //     }
        // }
        if(res[i]!= '\0'){
            //printf("getLen(res[%d]) = %d\n",i,getLen(res[i]));
            for(int j = 0 ; j < getLen(res[i]); j++){
                printf("%c",res[i][j]);
            }
            printf("\n");
            i++;
        }
        else{
            printf("===");
            break;
        }
    }
    free(res);
    //printf("%s\n",res[i+1]);
    return 0;
}

char* ana(char *arr, char **dict, int dictLen,int nummer,char **res,int maxDiLen,int *originalLen,int f){
    printf("===========ana start============!\n");
    printf("========nummer = %d ===========\n",nummer);
    // if(maxDiLen != -1){
    //     printf("arr = %s\ndict = %s\ndictLen = %d\nnummer = %d\nres[0] = %s\nmaxDiLen = %d\n",arr,dict[0],dictLen,nummer,res[0],maxDiLen);
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
        //该循环内都对
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
    //以上都对
    //统计wort中的字母数，都对
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

    // for(int i = 0; i < 26 ; i ++){
    //     printf("wort[%d] = %d\n",i,wort[i]);
    // }

    int *index=NULL;
    int count = 0;
    int start = 0, subLen = 0;
    int flag = 0;

    int *elem = (int*)malloc(sizeof(int)), elemAnzahl = 0;
    for(int i = 0; i < dictLen ; i ++){
        //此语句块都对
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
    int elem1 = 0,st,end,canFind = 0;
    for(int i = 0; i < dictLen ; i ++){
        if(elem[i]==1){
            canFind = 1;
            elem1++;
        }
        
    }
    if(canFind == 0){
        return NULL;
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
    // for(int i = 0; i<dictLen;i++){
    //     printf("elem[%d] = %d\n",i,elem[i]);
    // }
    
    //printf("nummer = %d\n",nummer);
    //无差别计算每个字典单词长度，都对
    for(int i = 0; i < dictLen; i++){
        markLen[i] = getLen(dict[i]);
        //printf("markLen[%d] = %d\n",i,markLen[i]);
    }
    if(maxDiLen == -1){
        maxDiLen = 0;
        int zeit = 0;
        
        for(int i = 0; i < dictLen; i++ ){
            //需要找到第一个符合条件的，并删去
            if(elem[i]==1 && (zeit == 0)){
                zeit++;
                continue;
                
            }
            if(elem[i]==1){
                //printf("i = %d\n",i);
                //printf("dict[%d] = %s\n",i,dict[i]);
                maxDiLen = maxDiLen + markLen[i];
            }
        }

    }
    //==============================11111111111111111111111111111111111111111111
    //找到一行结果
    
    int count2 = 0, mL = -1;
    ///////while start
    while(1){

        //int flagIndex = 0;
        for(int i = start; i < dictLen ; i++){
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
                // if(d[i][1] == 'd'){
                //     printf("d[%d][0] = %c, d[%d][j]-96 = %d\n",i,d[i][0],i,d[i][0]-96);
                // }
                if(d[i][j]-96 == 26){
                    
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
                    // if(aph == 26){
                    //     wort[25]++;
                    //     break;
                    // }
                    for(int k = 0; k < j; k++){
                        if(d[i][k]-96 == 26){
                            wort[25]++;
                        }
                        else{
                            wort[(d[i][k]-96)%26 - 1]++;
                        }
                        
                    }
                    break;
                }

            }
            //printf("d[%d] = %s\n",i,d[i]);
            //printf("markRes[%d] = %d, markLen[%d] = %d, flag = %d\n",i,markRes[i],i,markLen[i],flag);
            //printf("mmmmmmmmmmmmmmmmm\n");
            if(markRes[i] == markLen[i] && flag == 1){
                markOut[i] = 1;
                count++;
                index = (int *)realloc(index, sizeof(int)*(count+1));
                
                index[count-1] = i;
                //printf("--dict[index[count-1]] = %s\n",dict[index[count-1]]);
                //printf("index[count - 1] = %d, index[count] = %d\n",index[count-1],index[count]);
            }
            else{
                markOut[i] = 0;

                
            }
            if(count == 0){
                //printf("return\n");
                return NULL;
            }
 
        }
        
        // for(int i = 0; i < count; i++){
        //     printf("index[%d] = %d\n",i,index[i]);
        //     printf("dict")
        // }
        //求获得的index中的单词总长度，无空格，正确
        for(int i = 0; i < count ; i ++){
            //printf("getLen(dict[index[%d]]) = %d, getLen(d[index[%d]]) = %d, markLen[index[%d]] = %d\n",i,getLen(dict[index[i]]),i,getLen(d[index[i]]),i,markLen[index[i]]);

            //printf("%s\n",dict[index[i]]);
            subLen = subLen + getLen(dict[index[i]]);
        }
        //printf("---------------\n");
        
        if(subLen != satzLenOhneLeer) 
        {
            
            flag = 0;
            
            for(int j = 0 ; j < markLen[index[count-1]]; j++){
                int aph = -1;
                if(d[index[count-1]][j]-96 == 26){
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
            //printf("return dict[%d] = %s\n",index[count-1],dict[index[count-1]]);
            mL = index[count -1];
            
            index[count-1]=-1;
            index = (int *)realloc(index, sizeof(int)*(count));
            count=count - 1;

            if(count2 == count){
                break;
            }
            count2 = count;
            
            start = index[count - 1] + 1;
            //printf("new start = dict[%d] = %s\n",start, dict[start]);
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
    int subLen1=0,subLen2 = 0; //subLen1: 当前无空格长度，subLen2有空格长度
    char *tempArr = (char*)malloc((sizeof(char)));
    
    //printf("======\n");
    
    for(int h1 = 0; h1 < count ; h1++){
        
        int len = getLen(d[index[h1]]);
       
        for(int h2 = 0; h2 < len; h2++){
            if(nummer > 0){
                tempArr[subLen2 + h2 ] = (char*)malloc(sizeof(char));
                tempArr[subLen2 + h2 ] = d[index[h1]][h2];
            }
            
  
            
        }
        if(nummer>0 && res[nummer]!='\0')
        {
            tempArr[subLen2 + len ] = (char*)malloc(sizeof(char));
            if(h1 != count-1){
            
            tempArr[subLen2 + len ] = '\040';
            }
            else{
                tempArr[subLen2 + len ] = '\0';
            }
        }
        
        
        
        subLen1 = len+subLen1;
        subLen2 = len+subLen2 + 1;

    }
    
    // printf("getLen(tempArr) = %d\n",getLen(tempArr));
    // printf("tempArr = %s\n",tempArr);
    if(subLen2 != 0){
        subLen2 = subLen2 - 1;
    }
    
    
    int flag1 = 0,lastW=1,charComp = 0;
    for(int i = 0; i< 26; i++){
        if(wort[i] >0 ){
            //printf("wort[%d] = %d\n",i,wort[i]);
            lastW = 0;
            break;
        }
    }
    //printf("tempArr = %s\n",tempArr);
    
    //printf("-----------------------%d------------\n",1);
    // if(nummer>0){
    //     printf("getLen(res[%d]) = %d\n",nummer-1,getLen(res[nummer-1]));
    // }
    //printf("-----------------------%d------------\n",1);
    //printf("subLen2 = %d\n",subLen2);
    int resLen0 = 0;
    if(nummer > 0 && res[nummer]!='\0' ){
        
        for(int i = 0 ; i < nummer; i++){
            
            resLen0 = getLen(res[i]);
            //printf("getLen(res[%d]) = %d\n",getLen(res[nummer]));
            int j1 = 0;
            for(int j = subLen2-1 ; j >=0 ;j--){
                //printf("res[%d] = %s\n",nummer, res[nummer]);
                //printf("tempArr[%d] = %c, res[%d][%d] = %c\n",j,tempArr[j],nummer,resLen0-j1,res[nummer][resLen0-j1]);
                if(tempArr[j] != res[nummer][resLen0 - j1]){
                    charComp = 1;
                    
                    break;
                }
                j1++;
            }
        }
    }
    
    if(nummer == 0){
        charComp = 1;
    }
    
    if(nummer >0)
    {
        tempArr = '\0';
        //tempArr = (char*)realloc(tempArr,1);
        free(tempArr);
        tempArr = '\0';
    }
    //printf("hier oben\n");
    int resLen2 = 0,resLen2a=0; //resLen2: res[nummer-1]无空格长度，resLen2ayou空格长度。
    if(res[nummer-1]!=NULL&& nummer>0){
        for(int i = 0 ; i < getLen(res[nummer-1]); i++){
            if(res[nummer-1]=='\0'){
                break;
            }
            resLen2a++;
            if(res[nummer-1][i]!='\040'){
                resLen2++;
            }

        }
    }
    // if(nummer>0 && res[nummer-1]!=NULL){

    // }
    
    int flag2 = 0;
    // for(int h1 = 0; h1 < count ; h1 ++){
    //         printf("d[%d] = %s\n",index[h1],d[index[h1]]);
    // }
    //printf("subLen1 =%d, satzLenOhneLeer =%d, lastW = %d, charComp =%d\n",subLen1,satzLenOhneLeer,lastW ,charComp);
    
    if(subLen1 == satzLenOhneLeer && lastW == 1 && charComp == 1){
        
        
        //+++++++++++++++++++++++
        //printf("try!\n");
        //printf("resLen2 = %d",resLen2);
        //原始写入
        if( resLen2 + subLen1 != originalLen && nummer>0) {
            //printf("ooooooo\n");
            // if(flag2 == 1){
                //printf("res[nummer] = %s\n",res[nummer]);
                
            //     break;
            // }
            
            //printf("=1=1=1=1=1=1=1=1=1=1=\n");
            res = (char**)realloc(res,sizeof(char*)*(nummer+1));
            for(int h = nummer; h < getLen(res); h++){
                res[h] = '\0';
            }
            
            res[nummer] = (char *)malloc((sizeof(char))*(satzLenOhneLeer + count));
            for(int i0 = 0; i0 < getLen(res[nummer]); i0++){
                res[nummer][i0] = '\0';
            }
            
            flag1 = 1;
            
            for(int i = 0; i < count; i++){
                int tempLen = 0, t = 0;
                for (int j = 0; j < i+1; j++){
                    tempLen = tempLen + getLen(d[index[j]]);

                }
                tempLen = tempLen + i;
                
                for(int j = tempLen-getLen(d[index[i]]); j < tempLen; j ++){
                
                    res[nummer][j] = d[index[i]][t++];
                    if(j == tempLen-1 && i < count - 1){
                        res[nummer][j+1] = '\040';
                    }
                    if(i == count-1){
                        res[nummer][j+1] = '\0';
                    }
                }
                
            }
            //printf("===res[%d] = %s\n",nummer,res[nummer]);
            //break;
            
        }
        
        //printf("nummer = %d\n",nummer);
        
        if((nummer==0  && resLen2 != originalLen && f == 1 )||(nummer > 0 && resLen2!=0 && resLen2!= originalLen && resLen2 + subLen1 == originalLen)){
            //printf("alllllthere?\n");
            //printf("res[0] = %s\n",res[0]);
            int fI = 0;
            if(nummer>0){
                fI = nummer-1;
            }
            
            flag2 = 1;
            res[fI] = (char*)realloc(res[fI],sizeof(char)*(resLen2a+subLen1));
            //res[0][resLen2a+subLen1] = '\0';
            
            int stLen = resLen2a;
            //printf("stLen = %d\n",stLen);
            //printf("res[0] = %s\n",res[0]);
            res[fI][stLen] = (char*)malloc(sizeof(char));
            res[fI][stLen] = '\040';
            stLen = stLen + 1;
            for(int i = 0 ; i < count; i++){
                //printf("d[index[%d]] = %s")
                
                for(int j = 0; j < markLen[index[i]]; j++){
                    //printf("d[index[%d]][%d] = %c\n",i,j,d[index[i]][j]);
                    res[fI][stLen + j] = (char*)malloc(sizeof(char));
                    res[fI][stLen + j] = d[index[i]][j];
                    
                    //printf("res[0][%d] = %c\n",stLen+j,res[0][stLen+j]);
                }
                if(i != count-1){
                    res[fI][stLen + markLen[index[i]]] = '\040';
                }
                else{
                    res[fI][stLen + markLen[index[i]]] = '\0';
                }
                stLen = stLen + markLen[index[i]] + 1;
                
            }
            
            //res[nummer] = NULL;
            //nummer = 0;
            //printf("123123123\n");
            //printf("res[0] = %s\n",res[0]);
            //+++++++++++++++++++++++
        }
        //int te = 0;
        
        ///-----
        
        // if(nummer>0){
        //     printf("________res[%d] = %s\n",nummer-1,res[nummer-1]);
        // }
        //新nummer的res后移，前方补写res[nummer-1]的数据
        if(nummer>0 && resLen2 == originalLen){
            //printf("______\n");
            int diff = 0,lenA=0,lenB=0,lenAA,lenBB;
            lenAA = originalLen;
            lenBB = getLen(res[nummer]);
            //printf("lenAA = %d\n",lenAA);

            for(int a = 0 ; a < getLen(res[nummer]);a++){
                if(res[nummer][a]!='\040'){
                    
                    lenB++;
                 
                }
            }
            //printf("++res[nummer-1] = %s\n",res[nummer-1]);
            for(int a = 0 ; a < getLen(res[nummer-1]);a++){
                if(res[nummer-1][a]=='\0'){
                    break;
                }
                if(res[nummer-1][a]!='\040'){
                    lenA++;
                }
            }
            //printf("lenA = %d, lenAA = %d, lenB = %d, lenBB = %d\n",lenA,lenAA,lenB,lenBB);
            diff = lenA - lenB;
            lenA = 0;
            //printf("diff = %d\n",diff);
            int leer = 0;
            for(int a = 0 ; a < getLen(res[nummer-1]) ; a++){
                if(res[nummer-1][a]!= '\040'){
                    lenA++;

                   
                }
                if(lenA == diff){
                    break;
                }
                if(res[nummer-1][a]== '\040'){
                    leer++;
                }
                
                
            }
            
            diff = diff + leer + 1;
            //printf("diff = %d,lenA = %d\n",diff,lenA);
            //diff = lenA - lenB;
            //printf("res[%d] = %d\n",nummer,getLen(res[nummer]));
            res[nummer] = (char *)realloc(res[nummer],sizeof(char)*(getLen(res[nummer])+diff));
            for(int i = 0;i<lenBB;i++){
                res[nummer][lenBB - 1 - i  + diff] = res[nummer][lenBB -1 -i];
                //printf("res[%d][%d] = %c\n",nummer,lenBB-i+diff,res[nummer][lenBB-i+diff]);
            }
            //printf("res[0][5] = %c\n",res[0][5]);
            for(int i = 0; i < diff; i++){
                res[nummer][i] = res[nummer-1][i];
            }
            //printf("getLen(res[%d]) = %d\n",nummer,getLen(res[nummer]));

            
           
        }
        //printf("res[%d] = %s\n",nummer,res[nummer]);
        
    }
    else{
        
        //printf("hier untern!\n");
        //printf("res[%d] = %s\n",nummer,res[nummer]);

        if(res[nummer] != '\0'){
            
            //printf("???\n");
            return NULL;
        }
        
        
    }
    
    //===============================2222222222222222222222222222222222222222222222
    //printf("===return to dict[%d] = %s\n",index[count-1],dict[index[count-1]]);
    
    //==========00000000============
  
    int ls= -1;
    int wLen = 0;
    int oLen = 0;
    if(nummer > 0){
        for(int i = 0; i < getLen(res[nummer-1]);i++){
            if(res[nummer-1][i]!='\040'){
                oLen++;
            }
        }
    }
    printf("?");
    if((nummer == 0 && flag1 == 1 )|| (nummer>0 && oLen == originalLen && flag == 1)){
        nummer++;
        //printf("asdasdasdasdasd\n");
    }
    //printf("index[count-1] = %d, end = %d\n",index[count-1],end);
    for(int h = st; h < dictLen ; h++){
        if(index[count-1] == end-1){
            //printf("bbbbbbbbbbbreak\n");
            break;
        }
        for(int i = 0 ; i < count -1 ; i++){
            wLen = wLen + getLen(d[index[i]]);
        }
        wLen = satzLenOhneLeer - wLen; //所需长度
       
        int rSubLen = 0,rSubLenIndex = 0;
        for(int h1 = dictLen-1; h1 > st; h1--){
            if(elem[h1] == 1){
                rSubLenIndex = h1;
            }
        }
        
        //------------先返还，再计算
        int tIndex = index[count-1];
   

        //printf("h = %d, start = %d\n",h,start);
        //若h不等于起始第一个可用wort，则返还字母个数
        if(h != start ){
            
            for(int i1 = 0 ; i1 < getLen(d[index[count-1]]) ; i1++){
                
                int aph = -1;
                if(d[index[count-1]][i1]-96 == 26){
                
                    aph = 26;
                }
                else{
                    aph = (d[index[count-1]][i1]-96)%26;
                    
                }
            
                wort[aph - 1]++;
            }
            if(index[0]!=index[count -1]){
                h = index[count - 1];
                
            }
            else{
                //printf("break hier! --1");
                break;
            }
            
            
            // if(index[count -1] == end){
            //     break;
            // }
        
            index[count-1]=NULL;
            count=count - 1;
            if(count == 0 && index[0] == NULL){
                //printf("count = %d, index[0] = %d\n",count,index[0]);
                //printf("break hier! --2");
                break;
            }
        
        }
        
        //若res[0]无符号长度不等于原始字符串无符号长度，则让res[0]等于d[index[所有]]。此时res[0]后可以直接连接。然后，在res[nummer]赋值模块，判断res[0]的长度是否等于原始长度，若不等，则让res[nummer]覆盖。
        if(f == 0){
            int resLen1 = 0,resLen1a = 0;
            if(res[0]!=NULL){
                for(int i = 0; i < getLen(res[0]); i++){
                    if(res[0][i]=='\0'){
                        break;
                    }
                    resLen1a++;
                    if(res[0][i]!='\040'){
                        resLen1++;
                    }

                }
            }
            
            if(res[0]==NULL || resLen1 != originalLen){
                
                //printf("resLen1 = %d, res[0] = %s\n",resLen1,res[0]);
                res[0] = NULL;
                
                res[0] = (char*)realloc(res[0],sizeof(char)*(subLen2+1));
                //res[0][subLen2] = '\0';
                
                int stPo = 0;
                
                for(int i =0; i < count+1 ; i++){
                    //printf("d[%d] = %s\n",index[i],d[index[i]]);
                    for(int j = 0; j < markLen[index[i]]; j++){
                        //printf("index[%d]= %d, d[index[i]] = %s,d[index[i]][%d] = %c\n",i,index[i],d[index[i]],j,d[index[i]][j]);
                        //printf("markLen[index[%d]] = %d\n",i,markLen[index[i]]);
                        
                        res[0][stPo+j] = (char*)malloc(sizeof(char));   
                        res[0][stPo+j] = d[index[i]][j];
                        
                        //printf("res[0][%d] = %c\n",stPo+j,res[0][stPo+j]);
                        
                    }
                    //printf("\n");
                    if(i !=count-1){
                        res[0][stPo+markLen[index[i]]] = '\040';
                    }
                    else{
                        res[0][stPo+markLen[index[i]]] = '\0';
                    }
                    
                    stPo = stPo + markLen[index[i]] + 1;
                    
                    
                }
                nummer ++;
            }
        //printf("res[0] = %s\n",res[0]);
        }
        
        
        
        //=================================================
        //printf("===========================================\n");
        //返还后，计算
        int qLen=0;
        for(int i = 0 ; i < 26 ; i++){
            if(wort[i]!=0){
                for(int j = 0; j<wort[i];j++){
                    qLen++;

                }
            }
        }
        
        char qT[qLen];
        int qI=0;
        for(int i = 0 ; i < 26 ; i++){
            if(wort[i]!=0){
                for(int j = 0; j < wort[i]; j++){
                    qT[qI++] = ( i + 1 + '0') + 48;
                    
                }
            }
            
        }
      
        // char *q =qT;
        char *q = (char*)malloc(sizeof(char)*(qLen));
        q[qLen] = '\0';
        for(int i = 0; i < qLen; i++){
            q[i] = qT[i];
        }
        //printf("q = %s\n",q);

        char **di = (char **)malloc(sizeof(char*));
        di[0] = NULL;
        int diLen = 0;
        for(int i = 0; i < dictLen - tIndex - 1; i++){
            
            di = (char **)realloc(di,sizeof(char*)*(i+1));
            
            di[i] = (char*)malloc(sizeof(char)*markLen[tIndex + i+1]);
          
            //for(int j = 0; j < markLen[tIndex+i+1];j++){
            di[i] = dict[tIndex+i+1];
            
            diLen = diLen + getLen(di[i]);
            printf("di[%d] = %s\n",i,di[i]);
            
        }
       
        char *anag;
        printf("hier untern111111!\n");
        //printf("h = %d\ndiLen = %d\n",h,diLen);
        printf("diLen = %d, maxDiLen = %d\n",diLen, maxDiLen);
        //==================================================-----------------------------------------
        //printf("getLen(res[0]) = %d\n",getLen(res[0]));
        //printf("diLen = %d, maxDiLen = %d, qLen = %d\n",diLen,maxDiLen,qLen);
        if(diLen < maxDiLen && qLen != 0 && count != 0){
            //printf("000000000000000000000000000000finde start!\n");
            //printf("originalLen = %d",originalLen);
            printf("receve\n");
            printf("--->res[%d] = %s\n",nummer-1,res[nummer-1]);
            
            anag = ana(q,di,dictLen - tIndex - 1,nummer,&res[nummer-1],maxDiLen,originalLen,1);
            
        }
        else{
            break;
        }
        //=================================================
        //=====::::::::::
    }
            
    

    //==========111111111============

    
    // for(int i = 0 ; i < nummer; i++ ){
    //     //printf("i = %d\n",i);
    //     printf("=== res[%d] = %s\n",i,res[i]);
    // }
    //free(p);
    //printf("last\n");
    free(elem);
    //free(dict);
    return res;
}

void * setWort(struct Argument *obj){
    char *Arg[] = {
        "Sxzytwqp Klj Yrtd",
        //"Abc",
        //"And",
        //"Def",
        //"Dxz",
        //"k",
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


int dictReMake(struct Argument *obj, int dictLen){
    obj->dict = (obj -> dict + 1);
    return dictLen -1;
}