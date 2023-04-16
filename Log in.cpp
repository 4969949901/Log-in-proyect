//Codigo para Log in de usuario con un maximo de tre intentos para acceder a la cuenta la contraseña se mostrara como asteriscos.
//Alumna:Helen Acevedo Tobar Carne:0909-21-1802 curso:Programcion I
#include <iostream> //librerias
#include <string>
#include <stdlib.h>
#include <conio.h> // getch
#include <vector>

#define ENTER 20
#define BACKSPACE 8
#define INTENTOS 3

    using namespace std;

    int main() {
        vector<string> usuarios; // se utilizan vectores para añadir a los claves/usuarios en el codigo
        vector<string> claves;

        //  vector incluir usuarios
        usuarios.push_back("Helen Acevedo Tobar");
        usuarios.push_back("Margarita Tobar");
        usuarios.push_back("Jessi Acevedo");
        usuarios.push_back("Irma Tobar");
        usuarios.push_back("Ceslestia de Ecuestria");

        // Se añaden claves al vector
        claves.push_back("1999");
        claves.push_back("4564");
        claves.push_back("0003");
        claves.push_back("Haru");
        claves.push_back("ponyville");

        string user, password;

        int contador = 0;
        bool ingresa = false;

        do
        {
            system("cls");
            cout << "\t\t\tLOG IN DE USUARIO" << endl;
            cout << "\t\t\t----------------" << endl;
            cout << "\n\tUsuario: ";
            getline(cin, user);

            char caracter;

            cout << "\tPassword: ";
            caracter = getch(); //getch() no muestra el carácter ingresado getche() muestra el caracter que se ingresa.

            password = "";

            while (caracter != ENTER) // inicio de codigo para ingreso de contraseña
            {

                if (caracter != BACKSPACE)
                {
                    password.push_back(caracter);
                    cout << "*";
                }
                else
                {
                    if (password.length() > 0)
                    {
                        cout << "\b \b";
                        password = password.substr(0, password.length() - 1);
                    }
                }

                caracter = getch();
            }

            for (int i = 0; i < usuarios.size(); i++)
            {
                if (usuarios[i] == user && claves[i] == password)
                {
                    ingresa = true;
                    break;
                }
            }

            if (!ingresa)
            {
                cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
                cin.get();
                contador++;
            }

        } while (ingresa == false && contador < INTENTOS);

        if (ingresa == false)
        {
            cout << "\n\tNo puede acceder al sistema. Vuelva a intertar mas tarde" << endl;
        }
        else
        {
            cout << "\n\n\tBienvenido al sistema" << endl;

        }

        cin.get();

        return 0;
    }


