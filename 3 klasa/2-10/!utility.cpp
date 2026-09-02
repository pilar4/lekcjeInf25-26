int main()
{
    int licz, mian, i, j;
    cout<<"Licznik: " cin>>licz;
    cout<<"Mianownik: " cin>>mian;
    string s="0,";
    bool jest_okres=false;
    wymierna w;
    vector<wymierna> Tab;
    while (!jest_okres)
    {
        licz=licz*2;
        w.calk=licz/mian;
        licz=licz%mian;
        w.licz=licz;
        i=0;
        while(i<Tab.size() && !jest_okres)
            if(Tab[i]calk==w.calk && Tab[i].licz==w.licz)
        else i++;
    if (!jest_okres) Tab.push_back(w);
    }
    for (j=0;j<Tab.size();j++)
    {
        if (j==i) s=s+'(';
        if (Tab[j].calk==1) s=s+'1';
        else s=s+'0';
    }
    s=s+')';
    cout<<"Rozwiniecie binarne: "<<s;
    return 0;
}


#include <iostream>
#include <iomanip>

using namespace std;
double silnia(int x){
	double xx=1;
	for(int i=1; i<x+1; i++){
		xx*=i;
	}
	return xx;
}

int main(){
	
	float sin=1;
	bool flaga = 1;
	int x=3;
	while(sin/10000==0){
		if(flaga){
			sin -= 1/silnia(x);
		}
		else{
			sin += 1/silnia(x);
		}
		flaga = !flaga;
		x = x+2;
	}
	cout<<setprecision(4)<<fixed<<sin<<endl;

    return 0;
}

