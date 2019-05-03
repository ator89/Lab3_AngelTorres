#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;

//Menú principal
void menu();
//Ejercicio #1
void ejercicio1();
//método recursivo Euclides
int euclides(int, int);

//Ejercicio #2
void ejercicio2();

//Ejercicio#3
void ejercicio3();
//Submenú para admistrar guerras
void menuGuerra();

/*
class Guerra{
  private:
    string codigo, nombre, anio_inicio, anio_fin, continente;
    vector<string> paises;
  public:
    //Constructor
    Guerra();
    //Constructor sobrecargado
    Guerra(string,string,string,string,string);
    //Destructor
    ~Guerra();

    //Agregar un país a la vez
    void addPais(string p){ paises.push_back(p);}

    //Setters
    void setCodigo(string _codigo){ codigo = _codigo;}
    void setNombre(string _nombre){ nombre = _nombre;}
    void setAnioInicio(string _inicio){ anio_inicio = _inicio;}
    void setAnioFin(string _fin){ anio_fin = _fin;}
    void setContinente(string _continente){continente = _continente; }
    void setPaises( vector<string> _paises){paises = _paises;}

    //Getters
    string getCodigo() {return codigo;}
    string getNombre() { return nombre;}
    string getAnioInicio(){ return anio_inicio;}
    string getAnioFin(){return anio_fin;}
    string getContinente(){return continente;}
    vector<string> getPaises(){return paises;}

};

//Constructor
Guerra::Guerra(){
  codigo = "";
  nombre = "";
  anio_inicio = "";
  anio_fin = "";
  continente = "";
}

//Constructor sobrecargado
Guerra::Guerra(string _codigo, string _nombre,string _ini,string _fin,string _continente){
  codigo = _codigo;
  nombre = _nombre;
  anio_inicio = _ini;
  anio_fin = _fin;
  continente = _continente;
}

//Destructor
Guerra::~Guerra(){}
*/


int main(){

  bool menuActivo = true;
  int opcionMenu = -1;

  vector<string> listaPais;
  vector<string> lista;

  while(menuActivo){
    do{
      menu();
      cin >> opcionMenu;
      switch(opcionMenu){
        case 1://Ejercicio #1
          ejercicio1();
        break;
        case 2://Ejercicio #2
          ejercicio2();
        break;
        case 3://Ejercicio #3
          //ejercicio3();
          {
            bool menuActivoG = true;
            int opcionMenu = -1;

            string codigo, nombre, anio_inicio, anio_fin, continente;
            string pais;
            int cantidadPaises;

            stringstream infoGuerra;
            stringstream infoPais;
            stringstream infoCompleta;
            //Guerra* guerra; //Objeto guerra



            while(menuActivoG){
              do{
                menuGuerra();
                cin >> opcionMenu;
                switch(opcionMenu){
                  case 1:{//Insertar Guerra
                    cout << "Código de Guerra: ";
                    cin >> codigo;
                    cout << "Nombre de Guerra: ";
                    cin >> nombre;
                    cout << "Año de Inicio: ";
                    cin >> anio_inicio;
                    cout << "Año Fin: ";
                    cin >> anio_fin;
                    cout << "Continente: ";
                    cin >> continente;


                    //Objeto guerra
                    //guerra=new Guerra(codigo,nombre,anio_inicio,anio_fin,continente);

                    infoGuerra << codigo << ";" << nombre << ";"<<anio_inicio<<";"<<anio_fin<<";";
                    string cadenaGuerra = infoGuerra.str();
                    //cout << s << endl << endl;

                    cout << "Cantidad de paises: ";
                    cin >> cantidadPaises;
                    for( int i= 0; i < cantidadPaises; i++){
                      cout << "Pais participante: ";
                      cin >> pais;
                      infoPais << pais << ",";
                      //guerra->addPais(pais);
                    }
                    string cadenaPais = infoPais.str();

                    infoCompleta << cadenaGuerra << cadenaPais << continente;
                    string cadenaCompleta = infoCompleta.str();
                    cout << cadenaCompleta;

                    lista.push_back(cadenaCompleta);
                    cout << "\nGuerra agregada con éxito." << endl;


                  }//End case 1
                  break;
                  case 2://Buscar Guerra
                  break;
                  case 3://Eliminar Guerra
                  break;
                  case 4:{//Listar Guerras
                    int opcionLista = -1;
                    bool menuLista = true;

                    while(menuLista){
                      do{
                        cout << "\n1 - Listar todo\n"
                          << "2 - Listar Por Continente\n"
                          << "0 - Regresar\n";
                        cin >> opcionLista;
                        switch(opcionLista){
                          case 1:{//Mostar todo
                            for(int i = 0; i < lista.size(); i++){
                              cout << "("<<lista.at(i)<<")";
                            }
                          }
                          break;
                          case 2:{//Mostrar por continente
                            string continent;
                            string substring;
                            int pos = -1;
                            bool esta = false;
                            cout << "Ingrese un continente: ";
                            cin >> continent;

                            

                            for(int i = 0; i < lista.size(); i++){
                               if(size_t indez =lista.at(i).find(continent)){
                                  esta = true;
                               }
                            }
                            if(esta){
                              cout << "está";
                            }
                          }
                          break;
                          case 0://Salir de mostrar listas
                          break;
                          default:
                            cout << endl << "Opción no existe\n\n";
                          break;
                        }//End switch "menú lista"
                      }while(opcionLista != 0);
                      menuLista = false;
                    }//End while listar guerras
                  }//End case 4
                  break;
                  case 0://Salir Menú principal
                  break;
                  default://Opción no disponible
                    cout << "Opción no válida.\n\n"<< endl;
                  break;
               }//End switch
             }while(opcionMenu != 0);//End do-while
             menuActivoG = false;
           }//end while MenuActivo
          }
        break;
        case 0://Salir Menú principal
        break;
        default://Opción no disponible
          cout << "Opción no válida.\n\n"<< endl;
        break;
      }//End switch
    }while(opcionMenu != 0);//End do-while
    menuActivo = false;
  }//end while MenuActivo

  return 0;
}


//Ejercicio #1 - Euclides (MCD)
void ejercicio1(){
  int num1, num2;
  cout << endl;
  cout << "Ingrese un entero positivo: ";
  cin >> num1;
  cout << "Ingrese otro entero positivo: ";
  cin >> num2;

  cout << endl;
  cout << "El MCD de " << num1 << " y " << num2
        << " es: " << euclides(num1,num2) << endl;
}

//Método Euclides MCD
int euclides(int a, int b){
  if(b == 0){
    return a;
  }else{
    return euclides(b, a%b);
  }
}


void ejercicio2(){
  int divisor = 1, divisores = 0, num = 0;
  cout<<"Ingrese numero: ";
  cin>>num;

  do{
    if(num % divisor == 0){
      divisores++;
    }
    divisor++;
  }while(divisor <= num);//End do-while

  if(divisores == 2){
    cout<<"n-> El numero "<<num<<" es primo.";
  }else{
    cout<<"n-> El numero "<<num<<" no es primo.";
  }

}//Final Ejercicio2


//Ejercicio #3 - Listado de Guerras
void ejercicio3(){


}//Final ejercicio 3

//Submenú para administrar guerras
void menuGuerra(){
  cout << "\n\tMENU DE GUERRAS\n\n"
        << "1 - Insertar Guerra\n"
        << "2 - Buscar Guerra\n"
        << "3 - Eliminar Guerra\n"
        << "4 - Listar Guerras\n"
        << "0 - Regresar\n"
        << "Seleccione una opción: ";
}

//Menú principal
void menu(){
  cout << "\n\tMENU\n\n"
        << "1 - Ejercicio 1\n"
        << "2 - Ejercicio 2\n"
        << "3 - Ejercicio 3\n"
        << "Seleccione una opción: ";
}
