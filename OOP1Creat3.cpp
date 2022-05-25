#include <vector>
#include <memory>
#include "pt4.h"
using namespace std;

class Animal
{
public:
    virtual string GetInfo() = 0;
    virtual ~Animal()
    {
        Show("Animal");
    }
};

class Lion : public Animal
{
    string name;
public:
    Lion(string name) : name(name) {}
    string GetInfo()
    {
        return "Lion " + name;
    }
};

// Implement the Tiger, Leopard, Gorilla,
//   Orangutan and Chimpanzee descendant classes

class AnimalCreator
{
protected:
    virtual shared_ptr<Animal> CreateAnimal(int ind,
        string name) = 0;
public:
    vector<shared_ptr<Animal>> GetZoo(vector<int> inds,
        vector<string> names);
    virtual ~AnimalCreator()
    {
        Show("AnimalCreator");
    }
};

vector<shared_ptr<Animal>> AnimalCreator::GetZoo(vector<int> inds,
    vector<string> names)
{
    vector<shared_ptr<Animal>> zoo;
    for (int i = 0; i < inds.size(); i++)
        zoo.push_back(CreateAnimal(inds[i], names[i]));
    return zoo;
}

// Implement the CatCreator and ApeCreator descendant classes

void Solve()
{
    Task("OOP1Creat3");

}
