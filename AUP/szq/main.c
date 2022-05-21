#include <stdio.h>
#include "ascset.h"
#include <stdlib.h>

ascset_t as_create(enum as_t type, const char * items);
void as_destroy(ascset_t *set);
enum asop_t;
ascset_t as_combine(enum asop_t operation, ascset_t set1, ascset_t set2);

enum asop_t {
    aso_join, // Vereinigungsmenge 
    aso_cut // Schnittmenge 
};


int strlen(const char *str);
int strlen1(const uint8_t *str);

int main(){
    ascset_t s1, s2, s3, s4, s5;
    // andere Werte nach Bedarf... 
    s1 = as_create(as_caps,"ABC123");       // {A,B,C}
    s2 = as_create(as_all,"ABC123");        // {A,B,C,1,2,3}
    s3 = as_create(as_numbers,"ABC123");    // {1,2,3} 
    printf("%d ",s1.bitarray[0]); 
    printf("%d ",s1.bitarray[1]); 
    printf("%d ",s1.bitarray[2]); 
    printf("\n");
    printf("%d ",s2.bitarray[0]); 
    printf("%d ",s2.bitarray[1]); 
    printf("%d ",s2.bitarray[2]); 
    printf("%d ",s2.bitarray[3]); 
    printf("%d ",s2.bitarray[4]); 
    printf("%d ",s2.bitarray[5]);
    printf("\n");
    printf("%d ",s3.bitarray[0]);
    printf("%d ",s3.bitarray[1]); 
    printf("%d ",s3.bitarray[2]); 
    printf("\n");
    s4 = as_combine(aso_cut,s1,s2);         // {A,B,C}

    printf("%d ",s4.bitarray[0]); 
    printf("%d ",s4.bitarray[1]); 
    printf("%d ",s4.bitarray[2]); 
    printf("%d ",s4.bitarray[3]);
    printf("\n");
    s5 = as_combine(aso_join,s1,s3);        //{A,B,C,1,2,3}

    printf("%d ",s5.bitarray[0]); 
    printf("%d ",s5.bitarray[1]); 
    printf("%d ",s5.bitarray[2]); 
    printf("%d ",s5.bitarray[3]);
    printf("%d ",s5.bitarray[4]);
    printf("%d ",s5.bitarray[5]);
    printf("%d ",s5.bitarray[6]);

    as_destroy(&s1); 
    as_destroy(&s2); 
    as_destroy(&s3); 
    as_destroy(&s4);
    as_destroy(&s5);

    return 0;
}

// ... bis hier alles fuer die Abgabe loeschen/auskommentieren 
// Die Definitionen (und ggf. Deklarationen) Ihres Codes startet hier

ascset_t as_create(enum as_t type, const char * items){
    ascset_t as;
    
    if(type == as_empty){
        as.bitarray = NULL;
    }
    else{
        int length = strlen(items);
        int lengthChar = 0;
        int lengthNum = 0;
        char *t = (char *)malloc(length+1);

        for (int i = 0; i < length; i++)
        {
            t[i] = items[i];
        }
        t[length] = '\0';

        char chars[length];
        char Nums[length];
        while (*t != '\0')
        {
            if(65<= *t && *t <=90){
                //printf("t = %d\n", *t);
                chars[lengthChar] = *t;
                lengthChar++;
            }
            if(48<= *t && *t <=57){
                //printf("t = %d\n", *t);
                Nums[lengthNum] = *t;
                lengthNum++;
            }
            t++;
        }

        if (type == as_caps)
        {
            as.bitarray = malloc(4 * lengthChar);
            for (int i = 0; i < lengthChar;i++)
            {
                as.bitarray[i] = chars[i];
            }
        }
        if(type == as_numbers){
            as.bitarray = malloc(2 * lengthNum);
            for (int i = 0; i < lengthNum;i++)
            {
                as.bitarray[i] = Nums[i];
            }
        }
        if(type == as_all){
            as.bitarray = malloc(12*(length+1));
            for (int i = 0; i < length;i++)
            {
                as.bitarray[i] = items[i];
            }
            as.bitarray[length] = '\0';
        }
    }

    return as;
}

void as_destroy(ascset_t *set){
    free(set);
}

ascset_t as_combine(enum asop_t operation, ascset_t set1, ascset_t set2){
    ascset_t as;

    int lengthSet1 = strlen1(set1.bitarray);
    int lengthSet2 = strlen1(set2.bitarray);
    //printf("l1 = %d, l2 = %d\n", lengthSet1, lengthSet2);
    char *t = malloc(lengthSet1+lengthSet2+1);
    int n = 0;
    if(operation == aso_cut){

        
        for (int i = 0; i < lengthSet1; i++)
        {
            for (int j = 0; j < lengthSet2;j++){
                if(set2.bitarray[j] == set1.bitarray[i]){
                    t[n] = set2.bitarray[j];
                    n++;
                    break;
                }
            }
        }
        as.bitarray = malloc(n + 1);
        for (int i = 0; i < n; i++){
            as.bitarray[i] = t[i];
        }
        as.bitarray[n] = '\0';

    }
    if(operation == aso_join){
        for (int i = 0; i < lengthSet1; i++){
            t[i] = set1.bitarray[i];
            n++;
        }
        for (int i = 0; i < lengthSet2; i++)
        {
            for (int j = 0; j < lengthSet1; j++)
            {
                if(set2.bitarray[i] == set1.bitarray[j]){
                    break;
                }
                if(j == lengthSet1-1){
                    t[n] = set2.bitarray[i];
                    n++;
                }
            }
        }
    }
    else{
        as.bitarray = NULL;
    }

    as.bitarray = malloc(n + 1);
    for (int i = 0; i < n;i++){
        as.bitarray[i] = t[i];
    }
    as.bitarray[n] = '\0';

    return as;
}

int strlen(const char *str)   
{     
	if ('\0' == *str)  
		return 0;           
	else        
		return strlen(str+1) + 1;         
}

int strlen1(const uint8_t *str)   
{     
	if ('\0' == *str)  
		return 0;           
	else        
		return strlen1(str+1) + 1;         
}