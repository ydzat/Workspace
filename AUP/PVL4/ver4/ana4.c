//#include <windows.h>

#include <stdlib.h>
#include<stdio.h>

/*
原词重组，然后再字典中查找
方法：原单词全排列，然后字典全排列，然后匹配
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////去重全排列
void combine(int n,int m,int a[],int b[],const int M,char **dS,int deep,int lenOhneLeer,char **dict);
int getLen(char *arr);
void Permutation(char* str,char **wortS, int lenOhneLeer);
void Swap(char *a ,char *b);
int IsSwap(char* str,int start,int end);
void AllRange2(char* str,int start,int length,char **wS, int lenOhneLeer);
void* ana(char **dSu,int dSuN, char *arr, int lenOhneLeer, char **dict, int dictLen);
int numOfChar(char *arr, int *wort);
void strRec(char **d, int *index, int numOfIndex, int dictLen, int lenOhneLeer);


int comCount = 0;
int permuCount = 0;

//建立两个可用词条，**wortS中存储字谜的所有种排列，**dictSu中存储所有符合条件（长度和==字谜无符号长度）的字典排列
//**dictS 作为一个中间字符串组指针
// char **wortS = (char**)malloc(sizeof(char*));
// char **dictS = (char**)malloc(sizeof(char*));
// char **dictSu = (char**)malloc(sizeof(char*));
static char **wortS;
static char **dictS;
static char **dictSu;
int numOfDictSu = 0;

/*
 "Das Anagramm ist das erste Argument an ihr Programm(d.h. an main())"
字谜是主函数的第一个参数

*/
int main(char *args[])
{

    char wort[] = "Sxzytwqp Klj Yrtd";
    char *dict[] = {
        "Abc\0",
        "And\0",
        "Def\0",
        "Dxz\0",
        "k\0",
        "kx\0",
        "Ljsrt\0",
        "lt\0",
        "pt\0",
        "Ptyywq\0",
        "y\0",
        "Ywjsrq\0",
        "Zd\0",
        "zzx\0",
        NULL},**d;
    //d = dict;




    int wortLen = 0,wortLenOhneLeer = 0, im = 0;
    while(wort[im]!='\0'){
        wortLen++;
        if(wort[im]!='\040'){
            //printf("wort[%d] = %c\n",im,wort[im]);
            wortLenOhneLeer++;
        }
        im++;
    }
    im = 0;

    //*wortS = '\0';
    //*dictS = '\0';
    //*wortS+=1;
    //*dictS+=1;
    //printf("123%s\n",wortS[0]);
    //printf("get = %d\n",getLen(wortS));

    //printf("wortLen = %d\n",wortLen);
    //printf("wortLenOhneLeer = %d\n",wortLenOhneLeer);
    //删除空格，并且大写转小写;
    int leer = 0;
    // source[wortLenOhneLeer];
    for(int j = 0; j< wortLen;j++){
        if(wort[j] == '\0'){
            break;
        }
        if(wort[j] == '\040'){
            leer++;
            //printf("j = %d\n",j);
            continue;
        }
        int aph;
        if(wort[j]<='Z'){
            wort[j] = wort[j] + 32;
        }
        // if((wort[j]-96) == 26){
        //     aph = 26;
        // }
        // else{
        //     aph = (wort[j] -96)%26;
        // }
        //source[j-leer] = aph;
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
    //printf("wort = %s\n",wort);
    //printf("getLen(dict[%d] ) = %d\n",im,getLen(dict[im]));
    
    //对字典进行初始化，将单词存入d，并将大写变小写
    int dictLen = 0,maxWortLen = 0;
    while(dict[im]!=NULL){
        
        if(im>0 && getLen(dict[im]) < getLen(dict[im-1]) ){
            maxWortLen = getLen(dict[im]);
            
        }
        //printf("123123\n");
        dictLen++;
        im++;
    }
    im = 0;
    //printf("dictLen = %d, maxWortLen = %d\n",dictLen,maxWortLen);
    int diLen[dictLen];
    char di[dictLen][maxWortLen+1];
    d = (char **)malloc(sizeof(char*)*dictLen);
    for(int i = 0; i < dictLen; i++){
        int len = getLen(dict[i]);
        diLen[i] = getLen(dict[i]);
        d[i] = (char*)malloc(sizeof(char)*len);
        d[i][len] = '\0';
        di[i][len] = '\0';
        for(int j = 0 ; j < len; j++){
            d[i][j] = dict[i][j];
            di[i][j] = dict[i][j];
            if(d[i][j]<='Z'){         
                d[i][j] = d[i][j] + 32;
                di[i][j] = di[i][j] + 32;
            }
        }
        //printf("di[%d] = %s\n",i,di[i]);
    }
    /////////////////////////////字典转换↑

	
	int i, count = wortLenOhneLeer;
 
	//scanf("%d", &count);
 
	// 初始化数组
	// for (i = 0; i < count; i++)
	// {
	// 	source[i] = i + 1;
	// }
    

    //////////////////////////////////////////////////////////////////////////////////////////////////
	//FullPermutation(wort, 0, count, &wortS,wortLenOhneLeer);
    // int res[dictLen];
    // for(int i = 0 ; i < dictLen ; i ++){
    //     res[i] = 0;
    //     //printf("===diLen[%d] = %d\n",i,diLen[i]);
    // }
    //======================
    for(int i = 0; i < dictLen ; i++){
        int b[i];
        //printf("======================================================i == %d\n",i);
        combine(dictLen,i,diLen,b,i,&dictS,0,wortLenOhneLeer,d);
        for(int j = 0 ; j < comCount ; j++){
            if(dictSu == NULL){
                dictSu = (char**)malloc(sizeof(char*));
            }
            if(dictSu != NULL){
                dictSu = (char**)realloc(dictSu,sizeof(char*)*(numOfDictSu+comCount));
            }
            dictSu[j + numOfDictSu] = (char*)malloc(sizeof(char)*(wortLenOhneLeer+comCount-1));
            dictSu[j + numOfDictSu][wortLenOhneLeer+comCount-1] = '\0';
            for(int k = 0 ; k < wortLenOhneLeer+comCount-1 ; k++){
                dictSu[j + numOfDictSu][k] = dictS[j][k];
                
            }
            
        }
        dictS = (char**)realloc(dictS,sizeof(char*));
        dictS = NULL;
        numOfDictSu = numOfDictSu + comCount;
        comCount = 0;
        
        //printf("\n");
    }
    // for(int i = 0 ; i < numOfDictSu; i++){
    //     printf("dictSu[%d] = %s\n",i,dictSu[i]);
    // }
    printf("======================================================================================================================= Permutation\n");
    //Sleep(1000);
    //Permutation(wort,&wortS,wortLenOhneLeer);
    ana(dictSu,numOfDictSu, wort, wortLenOhneLeer,d, dictLen);
    printf("=======================================================================================================================\n");
    // int i1 = 0;
    // while(1){
    //     if(i1 == 5){
    //         break;
    //     }
    //     printf("%s\n",wortS[i1]);
    //     i1++;
    // }
    //FullPermutationDict(d, 0, dictLen, &dictS,wortLenOhneLeer);
	
    //Combination(wort);

    // for(int i = 0; i < comCount; i++){
    //     printf("wortS[%d] = %s\n",i,wortS[i]);
    // }


    
    return 0;

}

void Swap(char *a ,char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

//在 str 数组中，[start,end) 中是否有与 str[end] 元素相同的
int IsSwap(char* str,int start,int end){
	for(;start<end;start++)
	{
		if(str[start] == str[end])
			return 0;
	}
	return 1;
}

//递归去重全排列，start 为全排列开始的下标， length 为str数组的长度
void AllRange2(char* str,int start,int length,char **wS, int lenOhneLeer){
	if(start == length-1)
	{
        if(permuCount == 0){
            wortS = (char**)malloc(sizeof(char*));
        }
        if(wortS!=NULL){
            wortS = (char**)realloc(wortS,sizeof(char*)*(permuCount+1));
        }
        
        //printf("asdasdasdasd\n");
        wortS[permuCount] = (char *)malloc(sizeof(char)*lenOhneLeer);
        
        // int len = 0, index[lenOhneLeer];//,wortLen = 0,flag = 0;
		for (int i = 0; i < getLen(str); i++)
		{
            wortS[permuCount][i] = str[i];
            // len++;
            // index[i] = i;
		}
        wortS[permuCount][lenOhneLeer] = '\0';
		//printf("%s\n",wortS[permuCount]);
        //printf("wortS[0] = %s\n",wortS[0]);
	}
	else
	{
		for(int i=start;i<=length-1;i++)
		{
			if(IsSwap(str,start,i))
			{
				Swap(&str[start],&str[i]); 
				AllRange2(str,start+1,length,&wortS,lenOhneLeer);
				Swap(&str[start],&str[i]); 
			}
		}
	}
}

void Permutation(char* str,char **wS, int lenOhneLeer){
	if(str == NULL){
        //printf("NULL\n");
        return;
    }
		

	AllRange2(str,0,getLen(str),&wortS,lenOhneLeer);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////去重全排列↑

int getLen(char *arr){
    if(arr[0] != '\0'){
        return getLen(arr+1)+1;
    }
    else{
        return 0;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//字典全组合,b[i]是在a[]中的下标，即在dict中的下标

void combine(int n,int m,int a[],int b[],const int M,char **dS,int deep,int lenOhneLeer,char **dict){
    for(int h = n ; h >= m ; h--){
        b[ m-1 ] = h - 1;
        if(m > 1){
            deep++;
            int c = 0;
            if(comCount != 0){
                c = comCount - 1;
            }
            combine(h-1, m-1, a ,b , M, &dictS, deep, lenOhneLeer, dict);
        }//用到了递归思想
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
                    
                    //printf("where\n");
                }
                
                dictS[comCount] = (char*)malloc(sizeof(char)*(lenOhneLeer+M-1));
                
                int len,len1 = 0;
                for(int i = 0; i < M; i++){
                    // printf("--- i = %d---\n",i);
                    // printf("b[i] = %d\n",b[i]);
                    // printf("dict[b[i]] = %s\n",dict[b[i]]);
                    //printf("getLen(dict[b[i]]) = %d\n",getLen(dict[b[i]]));
                    len = getLen(dict[b[i]]);
                    
                    for(int j = 0; j < len; j ++){
                        
                        dictS[comCount][j+len1] = dict[b[i]][j];
                    }
                    dictS[comCount][len + len1] = '\040';
                    
                    len1 = len1 + len + 1;
                    //printf("where\n");
                }
                
                dictS[comCount][lenOhneLeer+M-1] = '\0';
                
                //printf("dictS[%d] = %s\n",comCount,dictS[comCount]);
                comCount++;
            }
            //printf("\n");
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////统计密码的单词个数，通过个数进行匹配
void* ana(char **dSu,int dSuN, char *arr, int lenOhneLeer, char **dict, int dictLen){
    int wort[26] = {0};
    //printf("arr = %s\n",arr);
    for(int i =0; i < lenOhneLeer; i++){
        if(arr[i] != '\0'){
            int aph;
            if((arr[i]-96) == 26){
                aph = 26;
            }
            else{
                //printf("arr[i]-96 = %d\n",arr[i]-96);
                aph = (arr[i]-96)%26;
            }
            //printf("arr[%d] = %c\n",i,arr[i]);
            wort[aph-1]++;
            
        }
        
    }

    // for(int i = 0 ; i < 26; i++){
    //     printf("wort[%d] = %d\n",i,wort[i]);
    // }
    //在dictSu中找到符合条件的字符串的下标
    int *index, numOfIndex = 0;
    index = NULL;
    for(int i = 0; i < dSuN; i++){
        if(numOfChar(dictSu[i],wort)){
            
            if(index == NULL){
                index = (int *)malloc(sizeof(int)*(numOfIndex+1));
                
            }
            if(index != NULL){
                //printf("----\n");
                index = (int *)realloc(index, sizeof(int)*(numOfIndex+1));
            }
            
            
            index[numOfIndex] = i;
            
            numOfIndex++;
            
        }
    }
    for( int i = 0 ; i < numOfIndex; i++){
        //printf("index[%d] = %d\n",i,index[i]);

        printf("%s\n", dictSu[index[i]]);

        //strRec(dict, index, numOfIndex, dictLen,lenOhneLeer);

        
    }
    
}

///统计某字符串中的字母个数是否与wort[26]中的字母个数相同，若相同返回1，否则返回0
int numOfChar(char *arr, int wort[26]){
    int wortArr[26] = {0};
    //printf("arr = %s\n",arr);
    for(int i =0; i < getLen(arr); i++){
        if(arr[i] != '\040'){
            int aph;
            if((arr[i]-96) == 26){
                aph = 26;
            }
            else{
                //printf("arr[i]-96 = %d\n",arr[i]-96);
                aph = (arr[i]-96)%26;
            }
            //printf("arr[%d] = %c\n",i,arr[i]);
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

void strRec(char **d, int *index, int numOfIndex, int dictLen, int lenOhneLeer){
    for(int i = 0 ; i < numOfIndex; i++){
        for(int j = 0 ; j < dictLen; j++){
            int len = getLen(d[j]);
            for(int k = 0; k < len ; k++){

            }
        }
    }
}