#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED

class Compra {
private:
    int numeroProducto;
    int cuit;
    Fecha fechaCompra;
    int cantidad;
    int importe;
public:
    void setNumeroProducto(int nuevoNumeroProducto) {
        numeroProducto = nuevoNumeroProducto;
    }
    void setCuit(int nuevoCuit) {
        cuit = nuevoCuit;
    }
    void setFechaCompra(Fecha nuevaFechaCompra) {
        fechaCompra = nuevaFechaCompra;
    }
    void setCantidad(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }
    void setImporte(int nuevoImporte) {
        importe = nuevoImporte;
    }

    int getNumeroProducto() {
        return numeroProducto;
    }
    int getCuit() {
        return cuit;
    }
    Fecha getFecha() {
        return fechaCompra;
    }
    int getCantidad() {
        return cantidad;
    }
    int getImporte(){
        return importe;
    }
};

#endif // COMPRA_H_INCLUDED
