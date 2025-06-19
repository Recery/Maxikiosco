#ifndef ARCHIVOPRODUCTOS_H_INCLUDED
#define ARCHIVOPRODUCTOS_H_INCLUDED

class ArchivoProductos{
    private:
    char nombre[40];
    public:
    ArchivoProductos(const char* initNombre) {
        strcpy(nombre, initNombre);
    }

    bool agregarRegistro(Producto reg){
        FILE *archivo;

        archivo = fopen(nombre, "ab");

        bool escribio = false;

        escribio = fwrite(&reg, sizeof(Producto), 1, archivo);

        fclose(archivo);

        return escribio;
    }

    void eliminarRegistro(int pos) {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        int cantRegs = contarRegistros();

        if (pos < 0 || pos >= cantRegs) return;

        Producto* regs = new Producto[cantRegs - 1];

        int j = 0;
        for (int i = 0; i < cantRegs; i++) {
            Producto reg;
            fread(&reg, sizeof(Producto), 1, archivo);

            if (i != pos) {
                regs[j] = reg;
                j++;
            }
        }

        fclose(archivo);
        archivo = fopen(nombre, "wb");

        for (int i = 0; i < cantRegs - 1; i++) {
            fwrite(&regs[i], sizeof(Producto), 1, archivo);
        }

        delete[] regs;

        fclose(archivo);
    }

    int posicionRegistro(int numero) {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        Producto reg;

        for (int pos = 0; pos < contarRegistros(); pos++) {
            fread(&reg, sizeof(Producto), 1, archivo);
            if (reg.getNumero() == numero) return pos;
        }

        return -1;
    }

    Producto leerRegistro (int pos) {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        Producto reg;

        for (int i = 0; i < contarRegistros(); i++) {
            fread(&reg, sizeof(Producto), 1, archivo);

            if (posicionRegistro(reg.getNumero()) == pos) return reg;
        }

        return reg;
    }

    int contarRegistros() {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        fseek(archivo, 0, SEEK_END);
        long tamArchivo = ftell(archivo);

        return tamArchivo / sizeof(Producto);
    }

    Productos* obtenerRegistros() {
        int cantRegs = contarRegistros();

        Productos* regs = new Productos[cantRegs];

        for (int i = 0; i < cantRegs; i++) {
            regs[i] = leerRegistro(i);
        }

        return regs;
    }
};

#endif // ARCHIVOPRODUCTOS_H_INCLUDED
