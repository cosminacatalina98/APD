#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;

struct date
{
    int in;
    int out;
    char litere;
    char stergere;
    int nr_adaugate;
    char adaugare;
    int nr_crt;
} v[100];
char stiva[100];

int main()
{
    ifstream f("date.in");
    int n, m, alf, si, sf[100], nr_sf, x[100], y[100], z[100], nr = 0, c, d,nr_adg,i,a;
    char sir[100], l,s,adg;
    f >> n;//nr de stari
    f >> m;//nr de relatii
    f >> alf;//nr de litere date
    f >> si;//starea initiala
    f >> nr_sf;
    for (int j = 0; j < nr_sf; j++)
        f >> sf[j];//starea finala
    f >> sir;//sirul de verificat
    int poz = 0;
    for (int j = 0; j < m; j++)
    {
        f >> c >> d >>l>> s>>nr_adg;
        v[j].nr_adaugate=nr_adg;
        v[j].nr_crt=poz;
        for(i=0; i<nr_adg; i++)
        {
            f>>adg;
            v[poz++].adaugare=adg;
        }


        v[j].in = c;
        v[j].out = d;
        v[j].litere = l;
        v[j].stergere=s;


    }
    for(int i=0; i<m; i++)
    {
        cout<<v[i].in<<" "<<v[i].out<<" "<<v[i].litere<<" "<<v[i].stergere<<" ";
        for(int j=v[i].nr_crt; j<v[i].nr_crt+v[i].nr_adaugate; j++)
            cout<<v[j].adaugare<<" ";
        cout<<endl;
    }
    a = si;
    int ok = 0;
    int p=0;
    for(int i=0; i<100; i++)
        stiva[i]=-1;
    int poz_s=0;
    stiva[0]='z';
    i =0;
    while (i < m)
    {
        for(int k=0; k<=poz_s; k++)
            cout<<stiva[k]<<" ";
        cout<<endl;
        if (v[i].in ==a && sir[p] == v[i].litere && v[i].stergere==stiva[poz_s])
        {
            stiva[poz_s]=-1;
            int x=v[i].nr_crt;
            if(v[x].adaugare!='e')
                for(int j =v[i].nr_crt+v[i].nr_adaugate-1; j>=v[i].nr_crt; j--)
                    stiva[poz_s++]=v[j].adaugare;
            poz_s--;
            p++;
            a = v[i].out;
            i = -1;

        }
        else
            if (v[i].in ==a && v[i].stergere==stiva[poz_s] && v[i].litere=='e')
             {stiva[poz_s]=-1;
         for(int j =v[i].nr_crt+v[i].nr_adaugate-1; j>=v[i].nr_crt; j--)
                    stiva[poz_s++]=v[j].adaugare;
            poz_s--;
            a = v[i].out;
            i = -1;}



        i++;
    }
    ok = 0;
    i = 0;

    while (i < nr_sf && ok == 0)
    {
        if (a == sf[i] && strlen(sir) == p)
            ok = 1;
        i++;
    }

    cout<<endl;
    if (ok==1 && stiva[poz_s]=='z')
        cout<<"da";
    else
        cout<<"nu";


    return 0;
}
