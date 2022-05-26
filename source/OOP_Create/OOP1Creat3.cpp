#include <vector>
#include <memory>
#include "pt4.h"

class Animal{
public:
    virtual std::string GetInfo() = 0;
    virtual ~Animal(){
        Show("Animal");
    }
};

class Lion : public Animal{
    std::string name;
public:
    Lion(std::string _name) : name(_name) {}
    ~Lion(){ Show("Lion"); }
    std::string GetInfo(){ return "Lion " + name; }
};

// Implement the Tiger, Leopard, Gorilla,
//   Orangutan and Chimpanzee descendant classes

class Tiger : public Animal{
    std::string name;
public:
    Tiger(std::string _name) : name(_name) {}
    ~Tiger(){ Show("Tiger"); }
    std::string GetInfo(){ return "Tiger " + name; }
};
class Leopard : public Animal{
    std::string name;
public:
    Leopard(std::string _name) : name(_name) {}
    ~Leopard(){ Show("Leopard"); }
    std::string GetInfo(){ return "Leopard " + name; }
};
class Gorilla : public Animal{
    std::string name;
public:
    Gorilla(std::string _name) : name(_name) {}
    ~Gorilla(){ Show("Gorilla"); }
    std::string GetInfo(){ return "Gorilla " + name; }
};
class Orangutan : public Animal{
    std::string name;
public:
    Orangutan(std::string _name) : name(_name) {}
    ~Orangutan(){ Show("Orangutan"); }
    std::string GetInfo(){ return "Orangutan " + name; }
};
class Chimpanzee : public Animal{
    std::string name;
public:
    Chimpanzee(std::string _name) : name(_name) {}
    ~Chimpanzee(){ Show("Chimpanzee"); }
    std::string GetInfo(){ return "Chimpanzee " + name; }
};

class AnimalCreator{
protected:
    virtual std::shared_ptr<Animal> CreateAnimal(int ind,
        std::string name) = 0;
public:
    std::vector<std::shared_ptr<Animal>> GetZoo(std::vector<int> inds,
        std::vector<std::string> names);
    virtual ~AnimalCreator(){
        Show("AnimalCreator");
    }
};

std::vector<std::shared_ptr<Animal>> AnimalCreator::GetZoo(std::vector<int> inds,
    std::vector<std::string> names){
    std::vector<std::shared_ptr<Animal>> zoo;
    for (int i = 0; i < inds.size(); i++)
        zoo.push_back(CreateAnimal(inds[i], names[i]));
    return zoo;
}

// Implement the CatCreator and ApeCreator descendant classes
class CatCreator : public AnimalCreator{
public:
    std::shared_ptr<Animal> CreateAnimal(int ind, std::string name){
        if(ind == 0){
            auto s = std::make_shared<Lion>(Lion(name));
            return std::dynamic_pointer_cast<Animal>(s);
        } else if(ind == 1){
            auto s = std::make_shared<Tiger>(Tiger(name));
            return std::dynamic_pointer_cast<Animal>(s);
        } else if(ind == 2){
            auto s = std::make_shared<Leopard>(Leopard(name));
            return std::dynamic_pointer_cast<Animal>(s);
        }
        return nullptr;
    }
    ~CatCreator(){ Show("CatCreator"); }
};
class ApeCreator : public AnimalCreator{
public:
    std::shared_ptr<Animal> CreateAnimal(int ind, std::string name){
        if(ind == 0){
            auto s = std::make_shared<Gorilla>(Gorilla(name));
            return std::dynamic_pointer_cast<Animal>(s);
        } else if(ind == 1){
            auto s = std::make_shared<Orangutan>(Orangutan(name));
            return std::dynamic_pointer_cast<Animal>(s);
        } else if(ind == 2){
            auto s = std::make_shared<Chimpanzee>(Chimpanzee(name));
            return std::dynamic_pointer_cast<Animal>(s);
        }
        return nullptr;
    }
    ~ApeCreator(){ Show("ApeCreator"); }
};

void Solve(){
    Task("OOP1Creat3");
    std::vector<int> id;
    std::vector<std::string> names;
    for(int i = 0; i < 4; ++i){
        int _id;
        std::string _name;
        pt >> _id >> _name;
        id.push_back(_id);
        names.push_back(_name);
    }
    
    auto cats = CatCreator().GetZoo(id, names);
    for(int i = 0; i < 4; ++i)
        pt << cats[i]->GetInfo();

    auto apes = ApeCreator().GetZoo(id, names);
    for(int i = 0; i < 4; ++i)
        pt << apes[i]->GetInfo();

}
