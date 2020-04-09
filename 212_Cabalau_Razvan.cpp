///Grupa 212->Cabalau Razvan

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>

using namespace std;

class Proces
{
protected:
    static int nrProcese;
    int nrProces;
    string reclamant;
    string reclamat;

public:
    Proces(int,string,string);
    Proces(const Proces &);     /// constructor de copiere
    virtual ~Proces();       /// destructor

    /// setter si getter
    void set_nrProces(int x)
    {
        nrProces=x;
    }
    int get_nrProces()
    {
        return nrProces;
    }
    void set_reclamant(string y)
    {
        reclamant=y;
    }
    string get_reclamant()
    {
        return reclamant;
    }
    void set_reclamat(string z)
    {
        reclamat=z;
    }
    string get_reclamat()
    {
        return reclamat;
    }
    ///supraincarcare operator egal
    Proces & operator=(const Proces &);

    virtual   void citire(istream &in);
    virtual  void afisare(ostream &out);

    friend istream & operator >> (istream &in,Proces &p);
    friend ostream & operator << (ostream &out,Proces &p);

    static void NumarProcese()
    {
        cout<< nrProcese;
    }

};

int Proces :: nrProcese;

Proces::Proces(int nr=0,string rn="",string rt="")
{
    nrProcese++;
    this->nrProces=nr;
    this->reclamant=rn;
    this->reclamat=rt;
}

Proces::~Proces()
{

}

void Proces::citire(istream &in)
{
    nrProces=nrProcese;
    cout<<"Reclamant: ";
    string x;
    in.get();
    getline(in,x);
    reclamant=x;
    cout<<"Reclamat: ";
    string y;
    getline(in,y);
    reclamat=y;

}

void Proces::afisare(ostream &out)
{
    out<<"Procesul: "<<nrProces<<"\n";
    out<<"Reclamant: "<<reclamant<<"\n";
    out<<"Reclamat: "<<reclamat<<"\n";

}



istream &operator >>(istream &in,Proces &p)
{
    p.citire(in);
    return in;

}

ostream &operator <<(ostream &out,Proces &p)
{
    p.afisare(out);
    return out;
}

class Proces_civil:public Proces
{
protected:
    double dauneMorale;
    double dauneMateriale;
    int nrMartori;
    bool stadiu;


public:
    Proces_civil(int,string,string,double,double,int);      ///constructor
    Proces_civil(const Proces_civil&);      ///construcor de copiere
    ~Proces_civil();        ///destructor
    ///setter si getter
    void set_dauneMorale(double a)
    {
        dauneMorale=a;
    }

    double get_dauneMorale()
    {
        return dauneMorale;
    }

    void set_dauneMateriale(double b)
    {
        dauneMateriale=b;
    }

    double get_dauneMateriale()
    {
        return dauneMateriale;
    }
    void set_nrMartori(int y)
    {

        nrMartori=y;
    }

    int get_nrMartori()
    {
        return nrMartori;
    }

    void set_stadiu(int x)
    {
        stadiu=x;
    }

    int get_stadiu()
    {
        return stadiu;
    }

    float taxa,maxtaxa;

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream & operator >> (istream &in,Proces_civil &p);
    friend ostream & operator << (ostream &out,Proces_civil &p);


};

Proces_civil::Proces_civil(int nr=0,string rn=" ",string rt=" ",double moral=0,double material=0,int martori=0):Proces(nr,rn,rt)
{
    this->dauneMorale=moral;
    this->dauneMateriale=material;
    this->nrMartori=martori;

}
Proces_civil::~Proces_civil()
{

}

int poz=-1;

void Proces_civil::citire(istream &in)
{
    maxtaxa=taxa;
    Proces::citire(in);
    cout<<"Dati cate dauna morale are persoana: ";
    in>>dauneMorale;
    cout<<"Dati cate daune materiale are persoana: ";
    in>>dauneMateriale;
    taxa=dauneMorale/10+dauneMateriale/10;
    cout<<"Dati numarul de  martori: ";
    in>>nrMartori;
    if (nrMartori>5)
        Proces_civil::set_stadiu(1);
    else
        Proces_civil::set_stadiu(0);

    if (taxa<maxtaxa)
    {
        maxtaxa=taxa;
        poz=nrProcese;
    }


}

void Proces_civil::afisare(ostream &out)
{

    Proces::afisare(out);
    cout<<"Daune morale: ";
    out<<dauneMorale<<"\n";
    cout<<"Daune materiale: ";
    out<<dauneMateriale<<"\n";
    cout<<"Numar martori: ";
    out<<nrMartori<<"\n";
    cout<<"Stadiul este: ";
    out<<stadiu;
    cout<<"\n";
    cout<<"Taxa este: ";
    out<<taxa<<"\n";

}

istream& operator>>(istream& in,Proces_civil & p)
{
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Proces_civil & p)
{
    p.afisare(out);
    return out;
}


class Proces_penal:public Proces
{
protected:
    int dovezi;
    bool stadiu;
public:
    Proces_penal(int,string,string,int);    ///constructor
    Proces_penal(const Proces_penal &);     ///constructor de copiere
    ~Proces_penal();        ///destructor
    ///setter si getter
    void set_dovezi(int x)
    {
        dovezi=x;
    }

    int get_dovezi()
    {
        return dovezi;
    }

    void set_stadiu(int y)
    {
        stadiu=y;
    }

    int get_stadiu()
    {
        return stadiu;
    }

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream & operator >> (istream &in,Proces_penal &p);
    friend ostream & operator << (ostream &out,Proces_penal &p);

};

Proces_penal::Proces_penal(int nr=0,string rn=" ",string rt=" ",int dov=0):Proces(nr,rn,rt)
{

    dovezi=dov;

}
Proces_penal::~Proces_penal()
{


}

void Proces_penal::citire(istream &in)
{

    Proces::citire(in);
    cout<<"Dati numarul de dovezi: ";
    in>>dovezi;
    if (dovezi>25)
        Proces_penal::set_stadiu(1);

}

void Proces_penal::afisare(ostream &out)
{
    Proces::afisare(out);
    cout<<"Sunt ";
    out<<dovezi;
    cout<<" dovezi.\n";
    cout<<"Stadiul este: ";
    out<<stadiu;
    cout<<"\n";
}

istream& operator>>(istream& in,Proces_penal & p)
{
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Proces_penal & p)
{
    p.afisare(out);
    return out;
}

void tip(Proces *&p, int &i)
{
    string s;
    cout<<"\n";
    cout<<"Introduceti tipul procesului "<<i+1<<": ";
    cin>>s;
    try
    {
        if(s=="civil")
        {
            p=new Proces_civil;
            cin>>*p;
            i++;
        }
        else if(s=="penal")
        {

            p=new Proces_penal;
            cin>>*p;
            i++;
        }
        else
            throw 15;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus un proces corespunzator. Incercati civil sau penal.\n ";
    }
}

void menu_output()
{
    cout<<"->Cabalau Razvan 212 - Proiect - Tema 14: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Introduceti numarul de procese.";
    cout<<"\n";
    cout<<"2. Introduceti tipul procesului.";
    cout<<"\n";
    cout<<"3. Afisati procese.";
    cout<<"\n";
    cout<<"4. Afisati procesul cu taxa de timbru cea mai mare.";
    cout<<"\n";
    cout<<"5. Schimbare studiu.";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";


}
void menu()
{
    int option=0,n,a=0,b=0;
    Proces **v;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            a=1;
            cout<<"Dati numarul de procese: ";
            cin>>n;
            if (n<=0)
                cout<<"Numarul trebuie sa fie pozitiv sau mai mare ca 0.\n";
            v=new Proces*[n];
        }

        if (option==2)
        {
            if (a==0)
                cout<<"Introduceti numarul de procese, actiunea 1.\n";
            else
            {
                b=1;
                for(int i=0; i<n;)
                    tip(v[i],i);
            }
        }

        if (option==3)
        {
            if (a==0 || b==0)
                cout<<"Introduceti numarul de procese, actiunea 1 si dati procesele, actiunea 2.\n";
            else
            {

                cout<<"\nAfisam Procesele: \n";
                for(int i=0; i<n; i++)
                {
                    cout<<"\n"<<*v[i];
                    cout<<"--------------------------\n";
                }
            }

        }

        if (option==4)
        {
            if (a==0 || b==0)
                cout<<"Introduceti numarul de procese, actiunea 1.";
            ///merge doar pentru o initializare, deoarece poz=-1 e var globala
            else
            {
                if (poz==-1)
                    cout<<"Avem doar procese penale, deci nu avem taxa de timbru!\n";
                else
                {
                    cout<<"Afisam procesul cu taxa maxima: \n";
                    cout<<"\n"<<*v[poz];
                    cout<<"--------------------------\n";
                }
            }
        }

        if (option==5)
        {
            if (a==0 || b==0 )
                cout<<"Introduceti numarul de procese, actiunea 1.";
            /// aici ar trebuie sa setez stadiu pentru fiecare proces,doar ca nu stiu cum
            /*
            else
            {

                int s;
                cout<<"Dati stadiul: ";
                cin>>s;

                for(int i=0; i<n; i++)
                    ///acesta comanta nu functioneaza
                 //   *v[i]->set_stadiu(s);

                cout<<"\nAfisam Procesele cu stadiul modificat: \n";
                for(int i=0; i<n; i++)
                {
                    cout<<"\n"<<*v[i];
                    cout<<"--------------------------\n";
                }
            }
            */
        }

        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }

        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }

        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

int main()
{
    Proces::NumarProcese();
    cout<<"\n";
    menu();
    /// dupa ce iesiti din menu  se va afisa numarul total de procese
    Proces::NumarProcese();
    return 0;
}
