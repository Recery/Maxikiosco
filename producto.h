#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto {
private:
    int numero;
    char nombre[30];
    char tipo[30];
    int precio;
    int stock;
public:
    void cargar() {
        cout << "Ingrese numero: " << endl;
        cin >> numero;
        cout << "Ingrese nombre: " << endl;
        cin >> nombre;
        cout << "Ingrese tipo: " << endl;
        cin >> tipo;
        cout << "Ingrese precio: " << endl;
        cin >> precio;
        cout << "Ingrese stock: " << endl;
        cin >> stock;
    }

    void mostrar() {
        cout << "Numero: " << numero << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }

    void setNumero(int nuevoNumero) {
        numero = nuevoNumero;
    }
    void setNombre(const char* nuevoNombre) {
        strcpy(nombre, nuevoNombre);
    }
    void setTipo(const char* nuevoTipo) {
        strcpy(tipo, nuevoTipo);
    }
    void setPrecio(int nuevoPrecio) {
        precio = nuevoPrecio;
    }
    void setStock(int nuevoStock) {
        stock = nuevoStock;
    }

    int getNumero() {
        return numero;
    }
    const char* getNombre() {
        return nombre;
    }
    const char* getTipo() {
        return tipo;
    }
    int getPrecio() {
        return precio;
    }
    int getStock() {
        return stock;
    }
};

#endif // PRODUCTO_H_INCLUDED
