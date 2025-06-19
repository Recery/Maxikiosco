#ifndef ARCHIVOPROVEEDORES_H_INCLUDED
#define ARCHIVOPROVEEDORES_H_INCLUDED
class ArchivoProveedores{
    private:
    char nombre[40];
    public:
    ArchivoProveedores(const char* initNombre) {
        strcpy(nombre, initNombre);
    }

    bool agregarRegistro(Proveedor reg){
        FILE *archivo;

        archivo = fopen(nombre, "ab");

        bool escribio = false;

        escribio = fwrite(&reg, sizeof(Proveedor), 1, archivo);

        fclose(archivo);

        return escribio;
    }

    void eliminarRegistro(int pos) {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        int cantRegs = contarRegistros();

        if (pos < 0 || pos >= cantRegs) return;

        Proveedor* regs = new Proveedor[cantRegs - 1];

        int j = 0;
        for (int i = 0; i < cantRegs; i++) {
            Proveedor reg;
            fread(&reg, sizeof(Proveedor), 1, archivo);

            if (i != pos) {
                regs[j] = reg;
                j++;
            }
        }

        fclose(archivo);
        archivo = fopen(nombre, "wb");

        for (int i = 0; i < cantRegs - 1; i++) {
            fwrite(&regs[i], sizeof(Proveedor), 1, archivo);
        }

        delete[] regs;

        fclose(archivo);
    }

    int posicionRegistro(int cuit) {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        Proveedor reg;

        for (int pos = 0; pos < contarRegistros(); pos++) {
            fread(&reg, sizeof(Proveedor), 1, archivo);
            if (reg.get_cuit() == cuit) return pos;
        }

        return -1;
    }

    Proveedor leerRegistro (int pos) {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        Proveedor reg;

        for (int i = 0; i < contarRegistros(); i++) {
            fread(&reg, sizeof(Proveedor), 1, archivo);

            if (posicionRegistro(reg.get_cuit()) == pos) return reg;
        }

        return reg;
    }

    int contarRegistros() {
        FILE *archivo;
        archivo = fopen(nombre, "rb");

        fseek(archivo, 0, SEEK_END);
        long tamArchivo = ftell(archivo);

        return tamArchivo / sizeof(Proveedor);
    }
};


#endif // ARCHIVOPROVEEDORES_H_INCLUDED
