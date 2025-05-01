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
