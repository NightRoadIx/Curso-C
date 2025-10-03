#include <iostream>
#include <vector>
using namespace std;

// Clase Libro
class Libro {
private:
    string titulo;
    string autor;
    bool prestado;

public:
    // Constructor
    Libro(string _titulo, string _autor) : titulo(_titulo), autor(_autor), prestado(false) {}

    // Método para prestar libro
    void prestar() {
        if (!prestado) {
            prestado = true;
            cout << "El libro \"" << titulo << "\" ha sido prestado." << endl;
        } else {
            cout << "El libro \"" << titulo << "\" ya está prestado." << endl;
        }
    }

    // Método para devolver libro
    void devolver() {
        if (prestado) {
            prestado = false;
            cout << "El libro \"" << titulo << "\" ha sido devuelto." << endl;
        } else {
            cout << "El libro \"" << titulo << "\" no estaba prestado." << endl;
        }
    }

    // Mostrar datos del libro
    void mostrar() {
        cout << "Título: " << titulo << " | Autor: " << autor
             << " | Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
    }
};

// Clase Biblioteca que contiene un conjunto de libros
class Biblioteca {
private:
    vector<Libro> libros;

public:
    // Método para agregar libro a la biblioteca
    void agregarLibro(const Libro &libro) {
        libros.push_back(libro);
    }

    // Método para mostrar todos los libros
    void mostrarLibros() {
        cout << "--- Catálogo de la Biblioteca ---" << endl;
        for (auto &libro : libros) {
            libro.mostrar();
        }
    }
};

int main() {
    // Crear libros
    Libro l1("Cien años de soledad", "Gabriel García Márquez");
    Libro l2("1984", "George Orwell");

    // Crear biblioteca y agregar libros
    Biblioteca b;
    b.agregarLibro(l1);
    b.agregarLibro(l2);

    // Mostrar catálogo
    b.mostrarLibros();

    // Prestar un libro
    l1.prestar();

    // Mostrar estado después del préstamo
    l1.mostrar();

    return 0;
}
