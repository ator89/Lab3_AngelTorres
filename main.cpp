#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
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


class Guerra{
  private:
    string codigo, nombre, anio_inicio, anio_fin, continente;
    vector<string> paises;
  public:
    //Constructor
    Guerra();
    //Destructor
    ~Guerra();
    
    //Setters
    void setCodigo(string _codigo){ codigo = _codigo;}
    void setNombre(string _nombre){ nombre = _nombre;}
    void setAnioInicio(string _inicio){ anio_inicio = _inicio;}
    void setAnioFin(string _fin){ anio_fin = _fin;}
    void setContinente(string _continente){continente = _continente; }
    
    //Getters
    string getCodigo() {return codigo;}
    string getNombre() { return nombre;}
    string getAnioInicio(){ return anio_inicio;}
    string getAnioFin(){return anio_fin;}
    string getContinente(){return continente;}

};

//Constructor
Guerra::Guerra(){
  codigo = "";
  nombre = "";
  anio_inicio = "";
  anio_fin = "";
  continente = "";
}

//Destructor
Guerra::~Guerra(){}



int main(){

  bool menuActivo = true;
  int opcionMenu = -1;

  while(menuActivo){
    do{
      menu();
      cin >> opcionMenu;
      switch(opcionMenu){
        case 1://Ejercicio #1
          ejercicio1();
        break;
        case 2://Ejercicio #2
        break;
        case 3://Ejercicio #3
          ejercicio3();
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


//Ejercicio #3 - Listado de Guerras
void ejercicio3(){
 
  bool menuActivoG = true;
  int opcionMenu = -1;
  
  string codigo, nombre, anio_inicio, anio_fin, continente;
  string pais;  
  vector<Guerra*> lista;

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
          

        }//End case 1
        break;
        case 2://Buscar Guerra
        break;
        case 3://Eliminar Guerra
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
