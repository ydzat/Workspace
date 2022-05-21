#include<iostream>
#include<cstdlib>
#include<cctype>
#include<typeinfo>
using namespace std;
class RechnenInt
{
	private:
		char par1,par2;
		int ergebnis;
		char op;
	public:
		RechnenInt():
		par1(0),par2(0),ergebnis(0),op(NULL){}
		void rechenen()
		{
			cout<<"<int  opreand int >:"<<endl;
			cin>>par1>>op>>par2;

			if (isdigit(par1)==false || isdigit(par2)==false)
			{
					cout<<"error"<<endl;
					exit(0);
			}

			switch(op)
			{
						case '+':ergebnis=(int)par1+(int)par2-48*2;break;
						case '-':ergebnis=par1-par2;break;
						case '*':ergebnis=par1*par2;break;
						case '/':ergebnis=par1/par2;break;
						default:
						exit(0);
			}
			cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;
		}
};
class RechnenDouble
{
		private:
		double par1,par2,ergebnis;
		char op;
	public:
		RechnenDouble():par1(0),par2(0),ergebnis(0),op(NULL)
		{}
		void rechenen()
		{
			cout<<"<double  opreand double >:"<<endl;
			cin>>par1>>op>>par2;
				if (isdigit(par1)==false)
					{
						exit(0);
					}

				if (isdigit(par2)==false)
					{
						exit(0);
					}
			cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;
			switch(op)
			{
						case '+':ergebnis=par1+par2;
						cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;break;
						case '-':ergebnis=par1-par2;
						cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;break;
						case '*':ergebnis=par1*par2;
						cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;break;
						case '/':ergebnis=par1/par2;
						cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;break;
						default:
						exit(0);
			}
			cout<<"Ausgabe<"<<par1<<" "<<op<<" "<<par2<<" >: ="<<ergebnis<<endl;
		}

};
int main ()
{
	int auswahl=0;
	RechnenInt a;
	RechnenDouble b;
	cout<<"Typ Auswahl"<<endl;
	cout<<"---------------"<<endl;
	cout<<"Int--------<1>"<<endl;
	cout<<"Double-----<2>"<<endl;
	cout<<"---------------"<<endl;
	cin>>auswahl;
	cout<<"Auswahl:"<<auswahl<<endl;
	if (auswahl==1)
	{
		while(1)
		{
			a.rechenen();
		}	
	}
	else if (auswahl==2)
	{
		while(1)
		{
			b.rechenen();
		}
	}
	else 
	{
		exit(0);
	}	
	return 0;
}
