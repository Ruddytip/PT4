#include "pt4.h"
#include <memory>
#include <fstream>

class StackNode
{
public:
    int data;
    std::shared_ptr<StackNode> next;
    StackNode(int _data, std::shared_ptr<StackNode> _next) :
        data(_data), next(_next) {}
};

class Stack
{
    std::shared_ptr<StackNode> top = nullptr;
public:
    virtual void Push(int data){
        auto newTop = std::make_shared<StackNode>(data, top);
        top = newTop;
    }
    bool Empty(){ return (top == nullptr ? true : false); }
    virtual int Pop(){
        if(Empty()) return 0;
        int data = top->data;
        auto oldTop = top;
        top = top->next;
        oldTop.reset();
        return data;
    }
    int Peek(){
        if(Empty()) return 0;
        return top->data;
    }
    void Clear(){ while(!Empty()) Pop(); }
    virtual std::string toStr(){
        std::string str("");
        auto it = top;
        while(it != nullptr){
            str+= std::to_string(it->data) + '-';
            it = it->next;
        }
        str+="end";
        return str;
    }
};

class StackC : public Stack {
private:
    int cnt = 0;
public:
    void Push(int data) override { Stack::Push(data); ++cnt; }
    int Pop() override {
        if(Stack::Empty()) return 0;
        --cnt;
        return Stack::Pop();
    }
    std::string toStr() override {
        std::string str = Stack::toStr();
        str+= '[' + std::to_string(cnt) + ']';
        return str;
    }
    int Count(){ return cnt; }
};

void StackTest(std::shared_ptr<Stack> s)
{
    std::string fileName, msg, str;
    int count, data;
    pt>> fileName >> count;

    std::ofstream out(fileName);
    if(!out.is_open()) return;

    for(int i = 0; i < count; ++i){
        pt >> msg;
        str+= msg + ": ";
        if(msg == "Push") {
            pt >> data;
            s->Push(data);
        } else
        if(msg == "Pop") {
            data = s->Pop();
            str+= std::to_string(data) + ' ';
        } else
        if(msg == "Peek") {
            data = s->Peek();
            str+= std::to_string(data) + ' ';
        } else
        if(msg == "Clear") {
            s->Clear();
        } else
        if(msg == "Empty") {
            str+= (s->Empty() ? "True " : "False ");
        }
        str+= s->toStr() + '\n';
        out << str;
        str = "";
    }
}

void Solve()
{
    Task("OOP0Begin3");
    std::string typeVar;
    pt >> typeVar;
    if(typeVar == "Stack"){
        Stack s;
        StackTest(std::make_shared<Stack>(s));
    }else{
        StackC s;
        StackTest(std::make_shared<StackC>(s));
    }
}
