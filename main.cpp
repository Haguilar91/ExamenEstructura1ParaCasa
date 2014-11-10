#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <SFML/Audio.hpp>

using namespace std;


///**************************************************************
/// Programado por Hector Leonel Aguilar Herdocia 20911190
///Creditos:
///     Cartas obtenidas de:
///     https://code.google.com/p/vector-playing-cards/ --Dominio Publico
///
///     Musica de Fondo:
///     "Crunk Knight" Kevin MacLeod (incompetech.com)
///     Licensed under Creative Commons: By Attribution 3.0
///     http://creativecommons.org/licenses/by/3.0/
///***************************************************************


stack<int> rellenarStack(stack<int> x)
{


  for(int i = 0; i<10;i++)
        {
           int valor = rand() % 64  +1;
           x.push(valor);
           if(valor==x.top())
           {
             valor = rand() % 64  +1;
           }
           x.pop();
           x.push(valor);
           cout<<"Valor "<<i+1<<" Contiene "<<valor<<endl;
        }


        return x;

}
stack <int> agregarMasCartas(int cant,stack<int> x)
{
         cout<<"Agregando "<< cant <<"Valores mas"<<endl;
                        for(int i=0;i<cant;i++)
                        {

                         int valor = rand() % 64  +1;
                          if(valor==x.top()&&x.size()>0)
                          {
                              valor = 0;
                          valor = rand() % 64  +1;
                          }
                          x.push(valor);
                          cout<<"-Valor Agregado- "<<i<<" Contiene "<<valor<<endl;
                        }
                      return x;

}

stack<int>  mostrarImagenSiguiente(stack<int> x)
{

                    cout<<x.size()<<endl;

                    cout<<"Entre"<<x.top()<<endl;
                        if(x.empty())
                        {
                            return rellenarStack(x);
                        }
                        int tope = x.top();

                        std::ostringstream o;
                        o << tope<<".png"<<endl;

                         std::string carta = o.str();
                         carta = carta.erase(carta.find_last_not_of(" \n\r\t")+1);
                         x.pop();
                         return  x;

}



int main()
{
    //Se crea stack
    stack<int> cartas;
    int aumento=0;


    sf::Music music;
if (!music.openFromFile("Crunk_Knight.ogg"))
    cout<<"Error Musica"<<endl;  // error
    music.play();
    //Agrega valores random

   cartas =rellenarStack(cartas);
   sf::RenderWindow window(sf::VideoMode(500, 726), "Juego Pila Estructura");

    sf::Texture texture;

cout<<cartas.top()<<endl;
int tope = cartas.top();
std::ostringstream o;
o << tope<<".png"<<endl;



std::string carta = o.str();
carta = carta.erase(carta.find_last_not_of(" \n\r\t")+1);
cout<<carta<<endl;
texture.loadFromFile(carta);


 window.clear();

       sf::Sprite sprite(texture);
        window.draw(sprite);
        window.display();

    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
                    {


                        aumento =3;
                        cartas = agregarMasCartas(3,cartas);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
                    {
                      aumento = 5;
                      cartas = agregarMasCartas(5,cartas);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
                    {
                      aumento=10;
                      cartas = agregarMasCartas(10,cartas);
                    }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {


                        if(!cartas.empty())
                        {

                            std::ostringstream o;
                         o << cartas.top()<<".png"<<endl;

                        std::string carta = o.str();
                        carta = carta.erase(carta.find_last_not_of(" \n\r\t")+1);
                        texture.loadFromFile(carta);
                        cartas=mostrarImagenSiguiente(cartas);

                        }else

                        {
                           cartas=rellenarStack(cartas);
                            cout<<"Ceroooooo"<<endl;
                            texture.loadFromFile("67.png");
                            cout<<"Fin de Baraja // Rellenando Stack"<<endl;

                        }



                        }



        }

        window.clear();
        window.draw(sprite);
        window.display();


    }

    return 0;
}
