unsigned deldigits(unsigned num, unsigned short div){
    
    if(num/10%10==0 && num<10){

        if (num %div==0){
            return 0;
        }
        else{
            return num;
        }
    }
    
    if(num%10 %div != 0){
        num = num%10 + deldigits(num/10,div)*10;
    }
    else{
        num = 0 + deldigits(num/10,div);
    }

    return num;
}