#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
}

int main() 
{
    Cjt_estudiants a;
    a.llegir();
     
    int ins, dni;
    double nota;

    while(ins != -6 and cin >> ins) 
    {
        if (ins == -1) 
        {
            
            cin >> dni >> nota;
            if(!a.existeix_estudiant(dni)) 
            {
                Estudiant a1(dni);
                if (nota <= 10 and nota >= 0) a1.afegir_nota(nota);
                
                a.afegir_estudiant(a1);
            }
            else 
            {
                cout << "el estudiante " << dni << " ya estaba" << endl;
                cout << endl;
            }
        }
        else if (ins == -2) 
        {
            cin >> dni;
            if(a.existeix_estudiant(dni)) 
            {
            Estudiant a2 = a.consultar_estudiant(dni);
            if(a2.te_nota()) cout << "el estudiante " << dni << " tiene nota " << a2.consultar_nota() << endl;
            else cout << "el estudiante " << dni << " no tiene nota" << endl;
            
            }
            else cout << "el estudiante " << dni << " no esta" << endl;
            cout << endl;
            
        }
        else if (ins == -3) 
        {
            cin >> dni >> nota;
            if(a.existeix_estudiant(dni)) 
            {
                for(int i = 1; i <= a.mida(); i++) 
                {
                    Estudiant prova = a.consultar_iessim(i);   
                    if (prova.consultar_DNI() == dni) 
                    {
                        if (prova.te_nota()) 
                        {
                            prova.modificar_nota(nota);
                            a.modificar_iessim(i, prova);
                           
                        } 
                        else 
                        {
                            prova.afegir_nota(nota);
                            a.modificar_iessim(i, prova);
                        }
                    }
                }
            }
            else 
            {
                cout << "el estudiante " << dni << " no esta" << endl;
                cout << endl;
            }
            
        }
        else if (ins == -4) 
        {
            for(int i = 0; i < a.mida(); i++) 
            {
                Estudiant prova = a.consultar_iessim(i + 1);
                if(prova.te_nota()) 
                {
                    prova.modificar_nota(redondear(prova.consultar_nota()));
                    a.modificar_iessim(i + 1, prova);
                }
            }
        }
        else if(ins == -5)
        {
            a.escriure();
            cout << endl;
        }
        
    }
}