#include "pt4.h"
#include <memory>
#include <fstream>
#include <sstream>

class StackException : public std::exception {
private:
    std::string msg;
public:
    StackException(std::string msg):msg(msg) {}

    const char* what() const throw() override
    {
        return msg.c_str();
    }
};

template <typename T>
class StackNode{
public:
    T data;
    std::shared_ptr<StackNode<T>> next;
    StackNode(T _data, std::shared_ptr<StackNode<T>> _next) :
        data(_data), next(_next) {}
};

template <typename T>
class Stack{
    std::shared_ptr<StackNode<T>> top = nullptr;
public:
    virtual void Push(T data){
        auto newTop = std::make_shared<StackNode<T>>(data, top);
        top = newTop;
    }
    bool Empty(){ return (top == nullptr ? true : false); }
    virtual T Pop(){
        if(Empty()) throw StackException("Empty stack in Pop");
        T data = top->data;
        auto oldTop = top;
        top = top->next;
        oldTop.reset();
        return data;
    }
    virtual T Peek(){
        if(Empty()) throw StackException("Empty stack in Peek");
        return top->data;
    }
    void Clear(){ while(!Empty()) Pop(); }
    virtual std::string toStr(){
        std::ostringstream iss (std::ostringstream::ate);
        auto it = top;
        while(it != nullptr){
            iss << it->data << '-';
            it = it->next;
        }
        iss << "end";
        return iss.str();
    }
};

template <typename T>
class StackC : public Stack<T> {
private:
    int cnt = 0;
public:
    void Push(T data) override { Stack<T>::Push(data); ++cnt; }
    T Pop() override {
        --cnt;
        return Stack<T>::Pop();
    }
    T Peek() override { return Stack<T>::Peek(); }
    std::string toStr() override {
        std::string str = Stack<T>::toStr();
        str+= '[' + std::to_string(cnt) + ']';
        return str;
    }
    int Count(){ return cnt; }
};

template <typename T>
void StackTest(std::shared_ptr<Stack<T>> s){
    std::string fileName, msg;
    std::ostringstream str (std::ostringstream::ate);
    int count;
    T data;
    pt >> fileName >> count;

    std::ofstream out(fileName);
    if(!out.is_open()) return;

    for(int i = 0; i < count; ++i){
        pt >> msg;
        str << msg << ": ";
        if(msg == "Count"){
            auto c = std::dynamic_pointer_cast<StackC<T>>(s);
            if(c == nullptr){
                str << "Method not available\n";
            } else {
                str << std::to_string(c->Count()) << '\n';
            }
            out << str.str();
            str.str("");
            continue;
        } else
        if(msg == "Push") {
            pt >> data;
            s->Push(data);
        } else
        if(msg == "Pop") {
            try{
                data = s->Pop();
            }
            catch(std::exception& ex){
                out << "Pop: " << ex.what() << '\n';
                break;
            }
            str << data << ' ';
        } else
        if(msg == "Peek") {
            try{
                data = s->Peek();
            }
            catch(std::exception& ex){
                out << "Peek: " << ex.what() << '\n';
                break;
            }
            str << data << ' ';
        } else
        if(msg == "Clear") {
            s->Clear();
        } else
        if(msg == "Empty") {
            str << (s->Empty() ? "True " : "False ");
        }
        str << s->toStr() << '\n';
        out << str.str();
        str.str("");
    }
}

void Solve()
{
    Task("OOP0Begin6");
    std::string _class, _fileName;
    char _type;
    pt >> _class >> _type;
    
    if(_class == "Stack"){
        if(_type == 'I'){
            StackTest(std::make_shared<Stack<int>>(Stack<int>()));
        } else if (_type == 'C'){
            StackTest(std::make_shared<Stack<char>>(Stack<char>()));
        } else if (_type == 'S'){
            StackTest(std::make_shared<Stack<std::string>>(Stack<std::string>()));
        }
    } else if(_class == "StackC"){
        if(_type == 'I'){
            auto s = std::make_shared<StackC<int>>(StackC<int>());
            StackTest(std::dynamic_pointer_cast<Stack<int>>(s));
        } else if (_type == 'C'){
            auto s = std::make_shared<StackC<char>>(StackC<char>());
            StackTest(std::dynamic_pointer_cast<Stack<char>>(s));
        } else if (_type == 'S'){
            auto s = std::make_shared<StackC<std::string>>(StackC<std::string>());
            StackTest(std::dynamic_pointer_cast<Stack<std::string>>(s));
        }
    }
}
