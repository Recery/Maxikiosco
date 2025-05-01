#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    void setDia(int nuevoDia) {
        dia = nuevoDia;
    }
    void setMes(int nuevoMes) {
        mes = nuevoMes;
    }
    void setAnio(int nuevoAnio) {
        anio = nuevoAnio;
    }

    int getDia() {
        return dia;
    }
    int getMes() {
        return mes;
    }
    int getAnio() {
        return anio;
    }
};

#endif // FECHA_H_INCLUDED
