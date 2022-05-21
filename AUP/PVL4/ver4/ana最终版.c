#include <stdlib.h>
#include<stdio.h>

void combine(int n,int m,int a[],int b[],const int M, int deep,int lenOhneLeer,char **dict);
int getLen(const char *arr);
void Permutation(char* str, int lenOhneLeer);
void Swap(char *a ,char *b);
int IsSwap(char* str,int start,int end);
void FullRange(char* str,int start,int length, int lenOhneLeer);
void* ana(int dSuN, char *arr, int lenOhneLeer);
int numOfChar(char *arr, int *wort);
void forFree(char **p, int len);
int* IsIn(char **arr, int arrLen, char *b, int start);
int IsSame(char * a, char *b);

int comCount = 0;
int permuCount = 0;

static char **wortS;
static char **dictS;
static char **dictSu;
int numOfDictSu = 0;


int main(int argc, char * args[])
{
    void* num = 0;
    printf("%d\n",sizeof(&num));
    int wortLen = getLen(args[1]),wortLenOhneLeer = 0;
    char *wort = (char*)malloc(sizeof(char)*wortLen);
    // "Sxzytwqp Klj Yrtd"
    // char *dict[] = {
    //     "Abc",
    //     "And",
    //     "Def",
    //     "Dxz",
    //     "k",
    //     "kx",
    //     "Ljsrt",
    //     "lt",
    //     "pt",
    //     "Ptyywq",
    //     "y",
    //     "Ywjsrq",
    //     "Zd",
    //     "zzx",
    //     "NULL"};
    char **d = (char **)malloc(sizeof(char*)*(argc-1));




    //printf("getLen(args[1]) = %d\n",getLen(args[1]));
    
    // while(wort[im]!='\0'){

    //     if(wort[im]!='\040'){
    //         wortLenOhneLeer++;
    //     }
    //     im++;
    // }
    
    //im = 0;
    for(int i = 0 ; i < wortLen; i++){
        if(args[1][i] == '\040'){
            wort[i] = '\040';
            
        }
        else{
            wort[i] = args[1][i];
            wortLenOhneLeer++;
        }
        if(i == wortLen - 1){
            wort[wortLen] = '\0';
        }
    }
    //printf("wotLenOhneLeer = %d",wortLenOhneLeer);
    //wort[]
    //printf("args[1] = %s\n",args[1]);
    //printf("argc = %d\n",argc);
    //printf("wort = %s\n",wort);
    

    int leer = 0;

    //密码大写转小写
    for(int j = 0; j< wortLen;j++){
        if(wort[j] == '\0'){
            break;
        }
        if(wort[j] == '\040'){
            leer++;

            continue;
        }
        
        if(wort[j]<='Z'){
            wort[j] = wort[j] + 32;
        }

    }
    leer = 0;
    
    for(int j = 0 ; j < wortLen; j++){
        if(wort[j+leer] == '\040'){
            
            for(int k = j + leer; k < wortLen - leer; k++){
                wort[k] = wort[k+1];
            }
            leer ++;
            
        }
    }

    int dictLen = argc - 2;
    

    //判断字典长度
    // while(1){

    //     int len = 0;
    //     len = getLen(dict[im]);
    //     if(len == 4){

    //         if((dict[im][0] == 78) && (dict[im][1] == 85) && (dict[im][2] == 76) && (dict[im][3] == 76)){
    //             break;
    //         }
    //     }
    //     dictLen++;
    //     im++;
    // }
    // im = 0;

    int diLen[dictLen];
    // if( d == NULL){
    //     d = (char **)malloc(sizeof(char*)*dictLen);
    // }
    
    for(int i = 0; i < dictLen; i++){
        
        int len = getLen(args[i+2]);
        diLen[i] = getLen(args[i+2]);
        d[i] = (char*)malloc(sizeof(char)*(len+1));
        d[i][len] = '\0';

        for(int j = 0 ; j < len; j++){
            d[i][j] = args[i+2][j];
            
        }
        d[i][len] = '\0';
        //printf("d[%d] = %s\n",i,d[i]);
        //printf("getLen(d[%d]) = %d\n",i,getLen(d[i]));
    }
    
    //判断字典中是否存在相同字符串
    
    for(int i = 0; i < dictLen-1; i++){
        int *index = IsIn(d,dictLen,d[i],i+1);

        //若存在，返回值为*index，若不存在，返回值为NULL
        if( index== NULL){
            continue;
        }
        else{       //存在，则将重复的单词清空，然后让后面的单词向前移动一位，字典长度-index[0]。
            for(int j = 0; j < index[0]; j++){
                for(int k = index[j+1]; k < dictLen - j - 1; k++){
                    int len = getLen(d[k+1]);
                    free(d[k]);
                    d[k] = (char *)realloc(d[k],sizeof(char)*len);
                    d[k] = d[k+1];
                }
                free(d[dictLen - 1]);
                d[dictLen - 1] = NULL;
            }
            dictLen = dictLen - index[0] + 1;
            //字典长度缩小
            d = (char **)realloc(d,sizeof(char*)*(dictLen+1));
            free(index);
            index = (int* )realloc(index,sizeof(int));
            index = NULL;
        }
    }
    printf("dictLen = %d\n",dictLen);
    for(int i = 0; i < dictLen ; i++){
        printf("d[%d] = %s\n",i,d[i]);
    }
    

    for(int i = 0; i < dictLen ; i++){
        int b[i];
        //printf("======================================================i == %d\n",i);
        combine(dictLen,i,diLen,b,i, 0,wortLenOhneLeer,d);
        //printf("123123\n");
        for(int j = 0 ; j < comCount ; j++){
            if(dictSu == NULL){
                dictSu = (char**)malloc(sizeof(char*));
            }
            if(dictSu != NULL){
                dictSu = (char**)realloc(dictSu,sizeof(char*)*(numOfDictSu+comCount));
            }
            dictSu[j + numOfDictSu] = (char*)malloc(sizeof(char)*(wortLenOhneLeer+comCount-1));
            
            for(int k = 0 ; k < wortLenOhneLeer+comCount-1 ; k++){
                dictSu[j + numOfDictSu][k] = dictS[j][k];
                
            }
            dictSu[j + numOfDictSu][wortLenOhneLeer+comCount-1] = '\0';
            
        }
        dictS = (char**)realloc(dictS,sizeof(char*));
        dictS = NULL;
        numOfDictSu = numOfDictSu + comCount;
        
        if(i != dictLen - 1){
            comCount = 0;
        }
        
        

    }

    ana(numOfDictSu, wort, wortLenOhneLeer);
    printf("===");

    free(wort);
    forFree(wortS,wortLen);
    forFree(dictS,comCount);
    forFree(dictSu,numOfDictSu);
    forFree(d,dictLen);
    forFree(args,argc);
    return 0;

}

void forFree(char **p, int len){
    
    for(int i = 0 ; i < len ; i++){
        if(p[i]!=NULL){
            free(p[i]);
            p[i] = NULL;
        }
        
    }
    if(p!=NULL){
        free(p);
        p = NULL;
    }
}

void Swap(char *a ,char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

int IsSwap(char* str,int start,int end){
	for(;start<end;start++)
	{
		if(str[start] == str[end])
			return 0;
	}
	return 1;
}

void FullRange(char* str,int start,int length, int lenOhneLeer){
	if(start == length-1)
	{
        if(permuCount == 0){
            wortS = (char**)malloc(sizeof(char*));
        }
        if(wortS!=NULL){
            wortS = (char**)realloc(wortS,sizeof(char*)*(permuCount+1));
        }
        
        wortS[permuCount] = (char *)malloc(sizeof(char)*lenOhneLeer);
        
		for (int i = 0; i < getLen(str); i++)
		{
            wortS[permuCount][i] = str[i];
		}
        wortS[permuCount][lenOhneLeer] = '\0';
	}
	else
	{
		for(int i=start;i<=length-1;i++)
		{
			if(IsSwap(str,start,i))
			{
				Swap(&str[start],&str[i]); 
				FullRange(str,start+1,length,lenOhneLeer);
				Swap(&str[start],&str[i]); 
			}
		}
	}
}

void Permutation(char* str, int lenOhneLeer){
	if(str == NULL){
        return;
    }
		

	FullRange(str,0,getLen(str),lenOhneLeer);
}

// int getLen(char *arr){
//     if((arr[0] != '\0') || (arr[0] == NULL)){
//         return getLen(arr+1)+1;
//     }
//     else{
//         return 0;
//     }
//     return 0;
// }

int getLen(const char *arr){
    if((*arr == '\0') || (arr == NULL)){
        return 0;
    }
    else{
        return getLen(arr + 1) + 1;
    }
    return 0;
}



// int getLen2D(char **arr){
//     if(arr[0] != "NULL"){
//         return getLen(*arr+1)+1;
//     }
//     else{
//         return 0;
//     }
//     return 0;
// }

void combine(int n,int m,int a[],int b[],const int M,int deep,int lenOhneLeer,char **dict){
    for(int h = n ; h >= m ; h--){
        b[ m-1 ] = h - 1;
        if(m > 1){
            deep++;
            // int c = 0;
            // if(comCount != 0){
            //     c = comCount - 1;
            // }
            combine(h-1, m-1, a ,b , M, deep, lenOhneLeer, dict);
        }
        else{
            int len = 0;
            for(int i = M - 1; i >= 0; i--){
                len = len + a[b[i]];   
            }
            
            if(len == lenOhneLeer){

                if(comCount==0){
           
                    dictS = (char **)malloc(sizeof(char*));
                }
                if(dictS!=NULL){
                    
                    dictS = (char **)realloc(dictS,sizeof(char*)*(comCount+1));

                }
                
                dictS[comCount] = (char*)malloc(sizeof(char)*(lenOhneLeer+M-1));
                
                int len,len1 = 0;
                
                for(int i = 0; i < M; i++){
                    
                    len = getLen(dict[b[i]]);
                    //printf("len = %d, dict[b[%d]] = %s\n",len,i,dict[b[i]]);
                    for(int j = 0; j < len; j ++){
                        
                        dictS[comCount][j+len1] = dict[b[i]][j];
                    }
                    dictS[comCount][len + len1] = '\040';
                    
                    len1 = len1 + len + 1;

                }
                //printf("comCount = %d, lenOhneLeer+M-1 = %d, lenOhneLeer = %d, M = %d",comCount,lenOhneLeer+M-1,lenOhneLeer,M);
                dictS[comCount][lenOhneLeer+M-1] = '\0';
                //printf("dictS[%d] = %s\n",comCount,dictS[comCount]);
                comCount++;
            }
        }
    }
}

void* ana(int dSuN, char *arr, int lenOhneLeer){
    int wort[26] = {0};

    for(int i =0; i < lenOhneLeer; i++){
        if(arr[i] != '\0'){
            int aph;
            //printf("arr = %s\n",arr);

            if((arr[i]-96) == 26){
                aph = 26;
            }
            else{
        
                aph = (arr[i]-96)%26;
            }
  
            wort[aph-1]++;
            
        }
        
    }

    int *index, numOfIndex = 0;
    index = NULL;
    for(int i = 0; i < dSuN; i++){
        if(numOfChar(dictSu[i],wort)){
            
            if(index == NULL){
                index = (int *)malloc(sizeof(int)*(numOfIndex+1));
                
            }
            if(index != NULL){

                index = (int *)realloc(index, sizeof(int)*(numOfIndex+1));
            }
            
            
            index[numOfIndex] = i;
            
            numOfIndex++;
            
        }
    }
    for( int i = 0 ; i < numOfIndex; i++){
        printf("%s\n", dictSu[index[i]]);
    }
    if(index !=NULL){
        free(index);
    }
    return NULL;
}

int numOfChar(char *arr, int wort[26]){
    int wortArr[26] = {0};

    for(int i =0; i < getLen(arr); i++){
        if(arr[i] != '\040'){
            int aph;
            //printf("== hier!==\n");
            if(arr[i]<='Z'){
                if(arr[i]-64 == 26){
                    aph = 26;
                }
                else{
                    aph = (arr[i]-64)%26;
                }
            }
            else{
                if((arr[i]-96) == 26){
                    aph = 26;
                }
                else{
                    aph = (arr[i]-96)%26;
                }
            }
            
            wortArr[aph-1]++;
            
        }
        
    }

    for(int i = 0 ; i<26; i++){
        if(wortArr[i]!=wort[i]){
            return 0;
        }
        if(wortArr[i]==wort[i] && i == 25){
            return 1;
        }
    }


    return 0;
}

//判断字符串b是否在**arr中，index[0]存储了有多少个重复，index[1]为第一个重复的下标
int* IsIn(char **arr, int arrLen, char *b, int start){
    int *index,flag = 0;
    //printf("===============================start=============\n");
    for(int i = start; i < arrLen ; i ++){
        
        //printf("i == %d\n",i);
        //printf("arr[%d] = %s, b = %s\n",i,arr[i],b);
        if(IsSame(arr[i], b) == 1){
            //printf("find!\n");
            flag ++;
            if(flag == 1){
                index = (int *)malloc(sizeof(int)*(flag + 1));
                index[0] = 1;
            }
            //printf("???????????\n");
            if(index != NULL){
                index = (int *)realloc(index,sizeof(int)*(flag + 1));
            }
            index[flag] = i;
            index[0]++;
            //printf("arr[%d] = %s\n",i,arr[i]);
        }
    }
    if(flag != 0){
        return index;
    }
    return NULL;
}

//判断两个字符串是否相等，若相等，则返回1，若不等，则返回0
int IsSame(char * a, char *b){
    int lenA = getLen(a);
    int lenB = getLen(b);
    if(lenA != lenB){
        return 0;
    }
    else{
        
        for(int i = 0 ; i < lenA ; i ++){
            if(a[i] != b[i]){
                return 0;
            }
            if((a[i] == b[i] ) && (i == lenA-1)){
                
                return 1;
            }
        }
    }
    return -1;
}