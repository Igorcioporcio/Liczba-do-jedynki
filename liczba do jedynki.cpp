#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int l, r, m, n, il, o;
    string odp;
    r=0;
    n=0;
    il=1;
    vector<int> wyn;
    vector<int> res2;

    cout << "Od jakiej do jakiej liczby chcesz aby program sprawdzil nadluzsza liczbe krokow potrzebnych aby liczba wynosila 1?" << "\n" << "Od: ";
    cin >> o;
    cout << "Do: ";
    cin >> l;

    if (l-o>10000)
    {
        cout << "\n" << "Zbyt duza roznica liczb. Sprobuj jescze raz." << "\n";
        exit(0);
    }

    if (l>250000)
    {
        cout << "\n" << "Zbyt duza liczba. Sprobuj jeszcze raz." << "\n";
        exit(0);
    }
    
    if(o>l)
    {
        cout << "\n" << "Liczba pierwsza nie moze byc wieksza od drugiej. Sprobuj jeszcze raz.";
        exit(0);
    }

    cout << "\n" << "Chcesz, aby program na koncu wypisal ilosc krokow kazdej z liczb od " << o << " do " << l << " potrzebnych do otrzymania 1?" << "\n" << "Tak (tak) Nie (nie)" << "\n";
    cin >> odp;
    int tab[l];
    int res[l];

    m=o-1;

    for(int i=0; i<l-o+1; i++)
    {
        m+=1;
        tab[i]=m;

        while(tab[i]>1)
        {
            if (tab[i]%2==0)
                tab[i]=tab[i]/2;
            else
                tab[i]=tab[i]*3+1;

            r+=1;
        }
        res[i]=r;
        r=0;
    }

    m=o-1;

    for(int i=0; i<l-o+1; i++)
    {
        m+=1;
        tab[i]=m;
    }

    for (int j=0; j<l-o+1; j++)
    {
        for(int k=0; k<l-o+1; k++)
        {
            if(res[j]>res[k] || res[j]==res[k])
                n+=1;
        }
        if(n==l-o+1)
        {
            wyn.push_back(tab[j]);
            res2.push_back(res[j]);
            il+=1;
        }
        n=0;

    }

        if(il-1==1)
            cout << "\n" << "Liczba " << wyn[0] << " potrzebuje najwiekszej ilosci krokow, aby otrzymac 1. Potrzebuje dokladnie " << res2[0] << " krokow." << "\n" << "\n";
        else
            {
                cout << "\n" << "Liczby " << wyn[0];
                for (int i=1; i<=il-2; i++)
                {
                    if(i==il-2)
                        cout << " oraz ";
                    else
                        cout << ", ";
                    cout << wyn[i];
                }
                cout << " potrzebuja najwiekszej ilosci krokow, aby otrzymac 1. Potrzebuja dokladnie " << res2[1] << " krokow." << "\n" << "\n";
            }

    if (odp=="tak")
    {
        for(int i=0; i<l-o+1; i++)
        cout << "Liczba " << tab[i] << " potrzebuje " << res[i] << " krokow aby otrzymac 1" << "\n";
    }

    return 0;
}
