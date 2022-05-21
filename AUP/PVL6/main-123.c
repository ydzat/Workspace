#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_comma(char *p){
    int flag,i = 0;
    while(p[i] != '\0'){
        if(p[i] == ','){
            flag = i;
            break;
        }
        else flag = 0;
        i++;
    }
    return flag;
}
int get_lastNr(char *p,int length){
    int temp,temp_data;
    temp = get_comma(p);
    if(temp == 0) temp_data = length - 1;
    else{
        int flag = 0;
        for(int i = length - 1;i > temp;i--){
            if(p[i] != '0'){
                temp_data = i;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            temp_data = temp - 1;
    }

    return temp_data;
}
int get_firstNr(char *p,int length){
    int temp,temp_data;
    temp = get_comma(p);
    if(temp == 0){
        for(int i = 0;i < length;i++){
            if(p[i] != '0' && p[i] != '-'){
                temp_data = i;
                break;
            }
        }
    }
    else{
        int flag = 0;
        for(int i = 0;i < temp;i++){
            if(p[i] != '0' && p[i] != '-'){
                temp_data = i;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            temp_data = temp - 1;
    }

    return temp_data;
}
int zeichenTozahlen(char *p,int first,int last){
    if(last == first) return p[first] - '0';
    else if(p[last] == ',')return zeichenTozahlen(p,first,last - 1);
    else return zeichenTozahlen(p,first,last - 1) * 10 + (p[last] - '0');
}
int nineToten(int number){
    if(number / 10 == 0) return number;
    else return nineToten(number / 10) * 9 + number % 10;
}
int ten_index(int number){
    int temp = 1;
    for(int i = 0;i < number;i++){
        temp = temp * 10;
    }
    return temp;
}
int compare(int comma1,int comma2,int diff1,int diff2){
    int flag;
    if(comma1 == 0 && comma2 == 0) flag = 0;
    else if(comma1 == 0 && comma2 != 0){
        if(diff2 < 0) flag = 0;
        else flag = 1;
    }
    else if(comma1 != 0 && comma2 == 0){
        if(diff1 < 0) flag = 0;
        else flag = 2;
    }
    else{
        if(diff1 == diff2) flag = 0;
        else if(diff1 < diff2) flag = 1;
        else flag = 2;

    }
    return flag;
}
long int calc(int number_1,int number_2,char *p,char *p1,char *p2){
    int result;
    if(p[0] == '+'){
        if(p1[0] == '-' && p2[0] == '-') result = 0 - (number_1 + number_2);
        else if(p1[0] != '-' && p2[0] == '-') result = number_1 - number_2;
        else if(p1[0] == '-' && p2[0] != '-') result = number_2 - number_1;
        else result = number_1 + number_2;
    }
    else if(p[0] == '-'){
        if(p1[0] == '-' && p2[0] == '-') result = number_2 - number_1;
        else if(p1[0] != '-' && p2[0] == '-') result = number_1 + number_2;
        else if(p1[0] == '-' && p2[0] != '-') result = 0 - (number_1 + number_2);
        else result = number_1 - number_2;
    }
    else{
        if(p1[0] == '-' && p2[0] == '-') result = number_1 * number_2;
        else if(p1[0] != '-' && p2[0] != '-') result = number_1 * number_2;
        else result = 0 - (number_1 * number_2);
    }
    return result;
}
long int tenTonine(long int number){
    if(number / 9 == 0) return number;
    else return tenTonine(number / 9 ) * 10 + (number % 9);
}
int check_divisor1(int comma1,int comma2,int diff1,int diff2){
    int temp;
    if(comma1 == 0 && comma2 == 0) temp = 0;
    else if(comma1 != 0 && comma2 == 0){
        if(diff1 < 0) temp = 0;
        else temp = diff1;
    }
    else if(comma1 == 0 && comma2 != 0){
        if(diff2 < 0) temp = 0;
        else temp = diff2;
    }
    else{
        if(diff1 == diff2){
            if(diff1 < 0 && diff2 < 0) temp = 0;
            else temp = diff1;
        }
        else if(diff1 > diff2) temp = diff1;
        else temp = diff2;
    }
    return temp;
}
int check_divisor2(int comma1,int comma2,int diff1,int diff2){
    int temp;
    if(comma1 == 0 && comma2 == 0) temp = 0;
    else if(comma1 != 0 && comma2 == 0){
        if(diff1 < 0) temp = 0;
        else temp = diff1;
    }
    else if(comma1 == 0 && comma2 != 0){
        if(diff2 < 0) temp = 0;
        else temp = diff2;
    }
    else{
        if(diff1 == diff2){
            if(diff1 < 0 && diff2 < 0) temp = 0;
            else temp = diff1 + diff2;
        }
        else if(diff1 > diff2){
            if(diff2 < 0) temp = diff1;
            else temp = diff1 + diff2;
        }
        else{
            if(diff1 < 0) temp = diff2;
            else temp = diff2 + diff1;
        }

    }
    return temp;
}
int length_out(long int number){
    if(number / 10 == 0)return 1;
    else return length_out(number / 10) + 1;
}
int check_length(long int number,int length,int divisor){
   int temp = length;
   if(divisor == 0) temp = length;
   else{
        for(int i = 1; i <= divisor;i++){
            if(number % 10 == 0) {
                temp--;
                number = number / 10;
                continue;
            }
            else break;
        }
   }
    return temp;
}
int have_comma(int length1,int length2,int divisor){
    int flag;
    if(divisor == 0) flag = 0;
    else{
        if(divisor == length1 - length2) flag = 0;
        else flag = 1;
    }
    return flag;
}
int have_comma2(int length1,int length2,int divisor,long int number){
    int flag;
    if(divisor == 0) flag = 0;
    else{
        if(divisor == length1 - length2) {
                if(number / ten_index(divisor) > 0) flag = 1;
                else flag = 0;
        }
        else flag = 1;
    }
    return flag;
}
void output1(char *p,long int number,int length1,int length2,int length3,int divisor,int commaflag){
   if(commaflag == 0 && number > 0)
   for(int i = length1 - 1;i >= 0;i--){
        p[i] = '0' + (number % 10);
        number = number / 10;
   }
   else if(commaflag == 0 && number < 0){
            number = 0 - number;
            p[0] = '-';
            for(int i = length1 - 1;i > 0;i--){
                p[i] = '0' + (number % 10);
                number = number / 10;
            }
   }
   else if(commaflag != 0 && number > 0){
        if(divisor < length3)
            for(int i = length1 - 1;i >= 0;i--){
                if(i == length2 - divisor){
                    p[i] = ',';
                    continue;
                }
                p[i] = '0' + (number % 10);
                number = number / 10;
            }
        else{
            for(int i = length1 - 1;i >= length1 - length3;i--){
                p[i] = '0' + number % 10;
                number = number / 10;
            }
            for(int k = 2;k < length1 - length3;k++){
                p[k] = '0';
            }
            p[0] = '0';
            p[1] = ',';
        }

   }
   else{
        number = 0 - number;
        if(divisor < length3){
            p[0] = '-';
            for(int i = length1 - 1; i > 0;i--){
                if(i == length2 - divisor + 1){
                    p[i] = ',';
                    continue;
                }
                p[i] = '0' + (number % 10);
                number = number / 10;
            }
        }
        else{
            for(int i = length1 - 1;i >= length1 - length3;i--){
                    p[i] = '0' + (number % 10);
                    number = number / 10;
            }
            for(int k = 3; k < length1 - length3;k++){
                 p[k] = '0';
            }
            p[0] = '-';
            p[1] = '0';
            p[2] = ',';
        }
   }
}
int main(int argc,char *argv[])
{
    int length_1,length_2,i = 0,j = 0;
    while(*(argv[1] + i) != '\0'){
        i++;
    }
    length_1 = i;
    while(*(argv[3] + j) != '\0'){
        j++;
    }
    length_2 = j;
    char *p_first =(char *)malloc(length_1 + 1);
    p_first[length_1] = '\0';
    for(int k = 0;k < length_1;k++){
        p_first[k] = *(argv[1] + k);
    }
    puts(p_first);
    char *p_symbol =(char *)malloc(2);
    p_symbol[1] = '\0';
    p_symbol[0] = argv[2][0];
    char *p_last =(char *)malloc(length_2 + 1);
    p_last[length_2] = '\0';
    puts(p_symbol);
    for(int k = 0;k < length_2;k++){
        p_last[k] = *(argv[3] + k);
    }
    puts(p_last);
    int comma_1 = get_comma(p_first);
    int comma_2 = get_comma(p_last);
    //int out_comma;
    printf("%d   %d\n",comma_1,comma_2);
    int first_1 = get_firstNr(p_first,length_1);
    int first_2 = get_firstNr(p_last,length_2);
    printf("%d   %d\n",first_1,first_2);
    int last_1 = get_lastNr(p_first,length_1);
    int last_2 = get_lastNr(p_last,length_2);
    printf("%d   %d\n",last_1,last_2);
    int diff_1 = last_1 - comma_1;
    int diff_2 = last_2 - comma_2;
    printf("%d   %d\n",diff_1,diff_2);
    int number9_1 = zeichenTozahlen(p_first,first_1,last_1);
    int number9_2 = zeichenTozahlen(p_last,first_2,last_2);
    printf("%d     %d\n",number9_1,number9_2);
    int flag = compare(comma_1,comma_2,diff_1,diff_2);
    int divisor_1 = check_divisor1(comma_1,comma_2,diff_1,diff_2);
    int divisor_2 = check_divisor2(comma_1,comma_2,diff_1,diff_2);
    if(flag == 1){
        if(comma_1 != 0 && comma_2 != 0){
            if(diff_1 < 0) number9_1 = number9_1 * ten_index(diff_2);
            else number9_1 = number9_1 * ten_index(diff_2 - diff_1);
        }
        else number9_1 = number9_1 * ten_index(diff_2);
    }
    if(flag == 2){
        if(comma_1 != 0 && comma_2 != 0){
            if(diff_2 < 0) number9_2 = number9_2 * ten_index(diff_1);
            else number9_2 = number9_2 * ten_index(diff_1 - diff_2);
        }
        else number9_2 = number9_2 * ten_index(diff_1);
    }
    long int number10_1 = nineToten(number9_1);
    long int number10_2 = nineToten(number9_2);
    printf("%ld     %ld\n",number10_1,number10_2);
    printf("%d\n",flag);
    long int result10 = calc(number10_1,number10_2,p_symbol,p_first,p_last);
    printf("%ld\n",result10);
    long int result9 = tenTonine(result10);
    int length_result = length_out(result9);
    int length_result1 = check_length(result9,length_result,divisor_1);
    int length_result2 = check_length(result9,length_result,divisor_2);//#
    if(length_result - length_result1 > 0) result9 = result9 / ten_index(length_result - length_result1);
    printf("%ld\n",result9);
    int flag_comma1 = have_comma(length_result,length_result1,divisor_1);
    int flag_comma2 = have_comma2(length_result,length_result2,divisor_2,result9);//#
    printf("%d    %d   %d\n",length_result,length_result1,length_result2);
    printf("%d    %d\n",divisor_1,divisor_2);
    printf("%d    %d\n",flag_comma1,flag_comma2);
    int length_final;
    if(p_symbol[0] != '%'){
        if(result9 > 0) {
                if(divisor_1 >= length_result1) length_final = length_result1 + flag_comma1 + (divisor_1 - length_result1 + 1);
                else length_final = length_result1 + flag_comma1;
        }
        else {
                if(divisor_1 >= length_result1) length_final = length_result1 + flag_comma1 + 1 + (divisor_1 - length_result1 + 1);
                else length_final = length_result1 + flag_comma1 + 1;
        }
    }
    else{
        if(result9 > 0) {
                if(divisor_2 >= length_result2) length_final = length_result2 + flag_comma2 + (divisor_2 - length_result2 + 1);
                else length_final = length_result2 + flag_comma2;
        }
        else {
                if(divisor_2 >= length_result2) length_final = length_result2 + flag_comma2 + (divisor_2 - length_result2 + 1) + 1;
                else length_final = length_result2 + flag_comma2 + 1;

        }
    }
    char *out =(char *)malloc(length_final + 1);
    out[length_final] = '\0';
    if(p_symbol[0] == '+' || p_symbol[0] == '-')
    output1(out,result9,length_final,length_result,length_result1,divisor_1,flag_comma1);
    //else output2(out,result9,length_final,length_result,length_result2,divisor_2,flag_comma2);
    puts(out);
    free(p_first);
    free(p_symbol);
    free(p_last);
    free(out);
    return 0;
}
