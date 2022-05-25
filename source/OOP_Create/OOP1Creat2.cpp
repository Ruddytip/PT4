#include <vector>
#include <memory>
#include "pt4.h"

class ConcreteProduct1{
protected:
    std::string info;
public:
    std::string GetInfo(){ return info; }
    ConcreteProduct1(std::string info);
    virtual void Transform();
    virtual ~ConcreteProduct1(){ Show("ConcreteProduct1"); }
};

ConcreteProduct1::ConcreteProduct1(std::string _info) : info(_info){
    // Implement the constructor
    for(int i = 0; i < info.length(); ++i)
            if(info[i] >= 'A' && info[i] <= 'Z')
                info[i] = info[i] - 'A' + 'a';
}
void ConcreteProduct1::Transform(){
    // Implement the method
    std::string str("");
    for(int i = 0; i < info.length(); ++i){
        str+= info[i];
        if(info[i] != '*' && i < info.length() - 1) str+= '*';
    }
    info = str;
}

// Implement the ConcreteProduct2 descendant class
class ConcreteProduct2 : public ConcreteProduct1{
public:
    ConcreteProduct2(std::string _info) : ConcreteProduct1(_info){
        if(info[0] >= 'a' && info[0] <= 'z') info[0] = info[0] + 'A' - 'a';
    }
    void Transform(){
        ConcreteProduct1::Transform();
        std::string str("==");
        str+= info;
        str+= "==";
        info = str;
    }
    virtual ~ConcreteProduct2(){ Show("ConcreteProduct2"); }
};

class ConcreteCreator1{
protected:
    virtual std::shared_ptr<ConcreteProduct1> FactoryMethod(std::string info){
        return std::make_shared<ConcreteProduct1>(info);
    }
public:
    std::string AnOperation(std::string info);
    virtual ~ConcreteCreator1(){
        Show("ConcreteCreator1");
    }
};

std::string ConcreteCreator1::AnOperation(std::string info){
    auto p = FactoryMethod(info);
    p->Transform();
    p->Transform();
    std::string s = p->GetInfo();
    p.reset();
    return s;
}

// Implement the ConcreteCreator2 descendant class
class ConcreteCreator2 : public ConcreteCreator1{
private:
    std::shared_ptr<ConcreteProduct1> FactoryMethod(std::string info){
        return std::make_shared<ConcreteProduct2>(info);
    }
public:
    virtual ~ConcreteCreator2(){
        Show("ConcreteCreator2");
    }
};

void Solve()
{
    Task("OOP1Creat2");
    for(int i = 0; i < 5; ++i){
        std::string str; pt >> str;
        pt << ConcreteCreator1().AnOperation(str);
        pt << ConcreteCreator2().AnOperation(str);
    }
}
