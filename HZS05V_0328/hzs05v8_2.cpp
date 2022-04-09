// Neptun: HZS05V
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class process
{
public:
    size_t p_uspri, p_cpu;
    bool p_next = false;
};

void clear(queue<process> &q)
{
    queue<process> empty;
    swap(q, empty);
}

void priter(queue<process> ready_queue, size_t puser)
{
    queue<process> spaces = ready_queue;
    queue<process> pohar;
    process p;
    for (size_t y = 0; y < 4; y++)
    {

        for (size_t i = 0; i <= puser; i++)
        {
            while (!spaces.empty())
            {
                p = spaces.front();
                cout << "|" << setw(4) << p.p_uspri << " |" << setw(4) << p.p_cpu << " |";
                if (p.p_next)
                {
                    p.p_cpu++;
                }

                pohar.push(p);
                spaces.pop();
            }
            spaces = pohar;
            clear(pohar);

            cout << endl;
        }
        if (spaces.front().p_next)
        {
           spaces.front().p_next = false;
           spaces.back().p_next = true; 
        }else
        {
            spaces.front().p_next = true;
            spaces.back().p_next = false; 
        }
        
        
        
        

        while (!spaces.empty())
        {
            p = spaces.front();
            if (p.p_cpu != 0)
            {
                p.p_cpu = p.p_cpu  / 2;
                p.p_uspri = puser + p.p_cpu / 2;
                pohar.push(p);
                spaces.pop();
            }
            else
            {
                p.p_uspri = puser;
                pohar.push(p);
                spaces.pop();
            }
        }

        spaces = pohar;

        while (!spaces.empty())
        {

            cout << "|" << setw(4) << spaces.front().p_uspri << " |" << setw(4) << spaces.front().p_cpu << " |";
            spaces.pop();
        }
        cout << endl;
        spaces = pohar;
        clear(pohar);
    }
}

int main()
{
    queue<process> ready_queue;
    process teszt, teszt2;
    teszt.p_cpu = 0;
    teszt.p_uspri = 60;
    teszt.p_next = true;
    teszt2.p_cpu = 0;
    teszt2.p_uspri = 60;

    ready_queue.push(teszt);
    ready_queue.push(teszt2);
    priter(ready_queue, 60);
    return 0;
}
