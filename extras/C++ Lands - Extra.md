# The C++ Lands: its Amazing Creatures and Weird Beasts
### Região: Boost::Variant

 - O que é Boost?

Boost é um conjunto de bibliotecas de alta qualidade que ajuda na criação de programas com menos erros (bugs), reduz a re-criação de código já existente e reduz custos de manutenção a longo prazo.
Estas bibliotecas vêm sendo adicionadas às bibliotecas standard do C++.
Mais informações sobre bibliotecas Boost: <http://www.boost.org/users/>

 - Classe "variant"

A classe "variant" é um tipo de recipiente, tal como, por exemplo, o "std::vector".
Porém no recipiente "variant" é possível armazenar tipos diferentes de dados unidos, e manipulá-los uniformemente com maior simplicidade, menor probabilidade de erros, e resultando em um programa mais eficiente.
Mais informações sobre a classe "variant": <http://www.boost.org/doc/libs/1_64_0/doc/html/variant.html>

#### Exemplo:

 - #include "boost/variant.hpp"
  #include <iostream>

 - class my_visitor : public boost::static_visitor<int>
{
public:
    int operator()(int i) const
    {
        return i;
    }
    
    int operator()(const std::string & str) const
    {
        return str.length();
    }
};

 - int main()
{
    boost::variant< int, std::string > u("hello world");
    std::cout << u; // output: hello world

    int result = boost::apply_visitor( my_visitor(), u );
    std::cout << result; // output: 11 (i.e., length of "hello world")
}