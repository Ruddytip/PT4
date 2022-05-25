#include <vector>
#include <memory>
#include "pt4.h"

class Product{
public:
    virtual std::string GetInfo() = 0;
    virtual void Transform() = 0;
    virtual ~Product(){
        Show("Product");
    }
};

// Implement the ConcreteProduct1
//   and ConcreteProduct2 descendant classes
class ConcreteProduct1 : public Product{
private:
    std::string info;    
public:
    ConcreteProduct1(const std::string _info) : info(_info){
        for(int i = 0; i < info.length(); ++i)
            if(info[i] >= 'A' && info[i] <= 'Z')
                info[i] = info[i] - 'A' + 'a';        
    }
    std::string GetInfo(){ return info; }
    void Transform(){
        std::string str("");
        for(int i = 0; i < info.length(); ++i){
            str+= info[i];
            if(info[i] != ' ' && i < info.length() - 1) str+= ' ';
        }
        info = str;
    }
};

class ConcreteProduct2 : public Product{
private:
    std::string info;    
public:
    ConcreteProduct2(const std::string _info) : info(_info){
        for(int i = 0; i < info.length(); ++i)
            if(info[i] >= 'a' && info[i] <= 'z')
                info[i] = info[i] + 'A' - 'a';   
    }
    std::string GetInfo(){ return info; }
    void Transform(){
        std::string str("");
        for(int i = 0; i < info.length(); ++i){
            str+= info[i];
            if(info[i] != '*' && i < info.length() - 1) str+= "**";
        }
        info = str;
    }
};

class Creator{
protected:
    virtual std::shared_ptr<Product> FactoryMethod(std::string info) = 0;
public:
    std::string AnOperation(std::string info);
    virtual ~Creator(){
        Show("Creator");
    }
};

std::string Creator::AnOperation(std::string info){
    auto p = FactoryMethod(info);
    p->Transform();
    p->Transform();
    return p->GetInfo();
}

// Implement the ConcreteCreator1
//   and ConcreteCreator2 descendant classes;
//   the AnOperation method should not be
//   overridden in these classes

class ConcreteCreator1 : public Creator{
public:
    std::shared_ptr<Product> FactoryMethod(std::string info){
        auto s = std::make_shared<ConcreteProduct1>(ConcreteProduct1(info));
        return std::dynamic_pointer_cast<Product>(s);
    }
};

class ConcreteCreator2 : public Creator{
public:
    std::shared_ptr<Product> FactoryMethod(std::string info){
        auto s = std::make_shared<ConcreteProduct2>(ConcreteProduct2(info));
        return std::dynamic_pointer_cast<Product>(s);
    }
};

void Solve(){
    Task("OOP1Creat1");
    ConcreteCreator1 s1;
    ConcreteCreator2 s2;
    for(int i = 0; i < 5; ++i){
        std::string str; pt >> str;
        pt << s1.AnOperation(str);
        pt << s2.AnOperation(str);
    }
}
