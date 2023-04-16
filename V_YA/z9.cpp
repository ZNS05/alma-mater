#include <iostream>
#include <cstring>

using namespace std;

class Stack // класс стека
{
private:
    char *sim; // массив элементов
    int id; // кол-во
public:
    Stack(); // конструктор
    void set(char sim); // метод присваивания 
    char pop(); // метод удаления
    char ret(); // метод возвращения значений
    ~Stack(); // деструктор
};

char Stack::ret()
{
    return sim[id-1];
}

char Stack::pop() 
{
    return sim[id--];
}

void Stack::set(char sim) 
{
    this->sim[id++] = sim; 
}

Stack::Stack()
{
    this->sim = new char;
    this->id = 0;
}

Stack::~Stack()
{
    delete[] sim;
}

int main()
{
    Stack st;
    char line[1000];
    cin >> line;

    int count = 0;

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '(' || line[i] == '{' || line[i] == '[' || line[i] == '<' || line[i] == '"') 
        {
            st.set(line[i]);
            count++;
        }

        if (line[i] == ')' || line[i] == '}' || line[i] == ']' || line[i] == '>' || line[i] == '"') 
        {
            char sim = st.ret();

            if ((sim == '(' && line[i] == ')') || (sim == '{' && line[i] == '}') || (sim == '[' && line[i] == ']') ||
            (sim == '<' && line[i] == '>') || (sim == '"' && line[i] == '"')) 
            {
                
                count--;
                st.pop();
            }
            else
            {
                cout << "false" << endl;
                return 1;
            }
        }
    }

    if (count == 0) 
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    return 0;
}