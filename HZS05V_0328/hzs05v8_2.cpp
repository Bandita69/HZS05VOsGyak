// Neptun: HZS05V
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

class process
{
public:
    size_t p_uspri, p_cpu;
    bool p_next = false;
};

void clear(deque<process> &q)
{
    deque<process> empty;
    swap(q, empty);
}

void priter(deque<process> ready_queue, size_t puser)
{
    deque<process> spaces = ready_queue;
    deque<process> pohar;
    process p;
    cout << "|   1";
    while (!spaces.empty())
    {

        cout << "|" << setw(4) << spaces.front().p_uspri << " |" << setw(4) << spaces.front().p_cpu << " |";
        spaces.pop_front();
    }
    cout << endl;
    spaces = ready_queue;
    size_t min_value = 10000;
    size_t x;
    for (size_t y = 0; y < 4; y++)
    {
        pohar = spaces;
        min_value = 10000;
        while (!pohar.empty())
        {

            x = pohar.front().p_uspri;
            pohar.pop_front();

            if (x < min_value)
                min_value = x;
                }
        cout << min_value << endl;
        clear(pohar);

        for (size_t i = 0; i <= puser; i++)
        {
            while (!spaces.empty())
            {
                p = spaces.front();
                // cout << "|" << setw(4) << p.p_uspri << " |" << setw(4) << p.p_cpu << " |";
                if (p.p_next)
                {
                    p.p_cpu++;
                }

                pohar.push_back(p);
                spaces.pop_front();
            }
            spaces = pohar;
            clear(pohar);

            // cout << endl;
        }

        if (spaces.front().p_next)
        {
            spaces.front().p_next = false;
            spaces.back().p_next = true;
        }
        else
        {
            spaces.front().p_next = true;
            spaces.back().p_next = false;
        }

        while (!spaces.empty())
        {
            p = spaces.front();
            if (p.p_cpu != 0)
            {
                p.p_cpu = p.p_cpu / 2;
                p.p_uspri = puser + p.p_cpu / 2;
                pohar.push_back(p);
                spaces.pop_front();
            }
            else
            {
                p.p_uspri = puser;
                pohar.push_back(p);
                spaces.pop_front();
            }
        }

        spaces = pohar;
        cout << "|" << setw(4) << y + 2;
        while (!spaces.empty())
        {

            cout << "|" << setw(4) << spaces.front().p_uspri << " |" << setw(4) << spaces.front().p_cpu << " |";
            spaces.pop_front();
        }
        cout << endl;
        spaces = pohar;
        clear(pohar);
    }
}

int main()
{
    deque<process> ready_queue;
    process teszt, teszt2, teszt3;
    teszt.p_cpu = 0;
    teszt.p_uspri = 60;
    teszt.p_next = true;
    teszt2.p_cpu = 1;
    teszt2.p_uspri = 60;
 /*    teszt3.p_cpu = 1;
    teszt3.p_uspri = 60; */

    ready_queue.push_back(teszt);
    ready_queue.push_back(teszt2);
   /*  ready_queue.push_back(teszt3); */

    priter(ready_queue, 60);
    return 0;
}
