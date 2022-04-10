// Neptun: HZS05V
// 8. het 2. feladat
// tradicionalis unix utemezes
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

class process
{
public:
    size_t p_uspri, p_cpu, p_nice;
    bool p_next = false;
    string p_name;
};

void clear(deque<process> &q)
{
    deque<process> empty;
    swap(q, empty);
}

void priter(deque<process> ready_queue, size_t puser, size_t max_time)
{
    deque<process> spaces = ready_queue;
    deque<process> pohar;
    process p;
    cout << "|" << setw(4) << "Quan";
    while (!spaces.empty())
    {

        cout << "||  " << spaces.front().p_name << setw(12) << "processz  ";

        spaces.pop_front();
    }
    cout << "|" << endl;
    spaces = ready_queue;

    cout << "|" << setw(4) << "tum ";
    while (!spaces.empty())
    {

        cout << "||" << setw(7) << "p_uspri"
             << "|" << setw(7) << "p_cpu";

        spaces.pop_front();
    }
    cout << "|" << endl;
    spaces = ready_queue;

    cout << "|   1|";
    while (!spaces.empty())
    {

        cout << "|" << setw(6) << spaces.front().p_uspri << " |" << setw(6) << spaces.front().p_cpu << " |";
        spaces.pop_front();
    }
    cout << endl;
    spaces = ready_queue;
    size_t min_value;
    size_t x;
    bool elso = false;
    string csillag;
    size_t quantums = max_time / puser;
    for (size_t y = 0; y < quantums; y++)
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
        // cout << min_value << endl;
        clear(pohar);

        for (size_t i = 0; i <= puser; i++)
        {
            while (!spaces.empty())
            {
                p = spaces.front();
                // cout << "|" << setw(4) << p.p_uspri << " |" << setw(4) << p.p_cpu << " |";

                if (p.p_uspri == min_value && elso == false)
                {
                    p.p_next = true;

                    elso = true;
                }
                else
                {
                    p.p_next = false;
                }
                if (p.p_next)
                {

                    p.p_cpu++;
                }

                pohar.push_back(p);
                spaces.pop_front();
            }
            spaces = pohar;
            clear(pohar);
            elso = false;

            // cout << endl;
        }



        while (!spaces.empty())
        {
            p = spaces.front();
            if (p.p_cpu != 0)
            {
                p.p_cpu = p.p_cpu / 2;
                p.p_uspri = puser + (p.p_cpu / 2) + p.p_nice;
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
        cout << "|" << setw(4) << y + 2 << "|";
        csillag = "  ";

        while (!spaces.empty())
        {
            if (spaces.front().p_next)
            {
                csillag = " *";
            }

            cout << "|" << csillag << setw(4) << spaces.front().p_uspri << " |" << setw(6) << spaces.front().p_cpu << " |";
            spaces.pop_front();
            csillag = "  ";
        }
        cout << endl;
        spaces = pohar;
        clear(pohar);
    }
}

int main()
{
    // ebbol itt lehetne egy bekero programot is csinalni

    deque<process> ready_queue;
    process processz, processz2, processz3, processz4;
    size_t PUSER = 60;
    size_t clock = 300;

    processz.p_name = "A";
    processz.p_uspri = 60;
    processz.p_cpu = 0;
    processz.p_nice = 0;

    processz2.p_name = "B";
    processz2.p_uspri = 60;
    processz2.p_cpu = 0;
    processz2.p_nice = 0;

    processz3.p_name = "C";
    processz3.p_uspri = 60;
    processz3.p_cpu = 0;
    processz3.p_nice = 0;

    processz4.p_name = "D";
    processz4.p_uspri = 60;
    processz4.p_cpu = 0;
    processz4.p_nice = 5;

    ready_queue.push_back(processz);
    ready_queue.push_back(processz2);
    ready_queue.push_back(processz3);
    ready_queue.push_back(processz4);

    priter(ready_queue, PUSER, clock);
    return 0;
}

// FIXIT: nem mindig kerekit helyesen
