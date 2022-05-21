#include<iostream>
using namespace std;


int max2(int a, int b);
int max3(int a, int b, int c);
int CF(int a);
string teilbar(int a, int b);
int ReF(int a);
int ggT(int a, int b);
int TrinkgR(float prozent, float max,float betrag);
int DzuB(int a);

int main(){
    int a=3, b=4, c=5, d = 6 ;
    int T= 30;
    float betrag = 345,prozent = 0.05, max = 1000;
    
    cout<<max2(a,b)<<endl;
    cout<<max3(a,b,c)<<endl;
    cout<<CF(T)<<endl;
    cout<<teilbar(d,a)<<endl;
    cout<<ReF(c)<<endl;
    cout<<ggT(81,72)<<endl;
    cout<<TrinkgR(max,prozent,betrag)<<endl;
    cout<<DzuB(8)<<endl;

    if((a%b)==0){
        printf("Ja");
    }




    return 0;
}
//--------------------------------------------------
int max2(int a, int b){
    if (a>b) return a;
    if (a<b) return b;
    return false;
}

int max3(int a, int b, int c){
    a = max2(a,b);
    a = max2(a,c);
    return a;
}

int CF(int a){
    /*9/5T = F - 32*/
    if (a>=5) return a/5*9+32;
    else return a*9/5+32;
}

string teilbar(int a, int b){
    if ((a % b) == 0) return "Ja";
    return "Nein";

}

int ReF(int a){
    if (a==1) return 1;
    else return a * ReF(a-1);
}

int ggT(int a, int b){
    int max,min,mo;
    max = max2(a,b);
    min = (a+b) -max;
    mo = max % min;
    if(mo!=0){
        return ggT(min,mo);
    }
    else{
        return min;
    }
}

int TrinkgR(float prozent, float max,float betrag){
    cout<<"Maximalbetrag ist "<<max<<endl;
    cout<<"Prozent ist "<<prozent<<endl;
    if (betrag <=max){
        return betrag*prozent;
    }
    else if(betrag <0) return false;
    else return 50;
}

int DzuB(int a){
    if(a == 1) return 1;
    else{
        return a%2 + 10*DzuB((a-(a%2))/2);
    }
}