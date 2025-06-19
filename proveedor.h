#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
class Proveedor{
private:
    int cuit;
    char nombre[30];
    int numero;
    char email[40];
    char direccion[100];
public:
    void ingresarDatos() {
        cout << "Ingrese cuit: " << endl;
        cin >> cuit;
        cout << "Ingrese nombre: " << endl;
        cin >> nombre;
        cout << "Ingrese numero: " << endl;
        cin >> numero;
        cout << "Ingrese email: " << endl;
        cin >> email;
        cout << "Ingrese direccion: " << endl;
        cin >> direccion;
    }

    void mostrar() {
        cout << "Cuit: " << cuit << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Numero: " << numero << endl;
        cout << "Email: " << email << endl;
        cout << "Direccion: " << direccion << endl;
    }

    void set_cuit(int nuevo_cuit){
    cuit= nuevo_cuit;

    }
    void set_nombre(const char* nuevo_nombre){
    strcpy(nombre, nuevo_nombre);

    }
    void set_numero ( int nuevo_numero){
    numero = nuevo_numero;
    }

    void set_email(const char* nuevo_email){
    strcpy( email, nuevo_email);
    }
    void set_direccion (const char* nueva_direccion){
    strcpy(direccion, nueva_direccion);

    }

    int get_cuit (){
    return cuit;
    }
    const char* get_nombre(){
    return nombre;
    }
    int get_numero(){
    return numero;
    }
    const char* get_email(){
    return email;
    }
    const char* get_direccion(){
    return direccion;
    }
};


#endif // PROVEEDOR_H_INCLUDED
