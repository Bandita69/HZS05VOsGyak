// Laphivatkozások sorrendje: <szamok vesszovel elvalasztva>
// Memóriakeret (igényelt lapok/capacity): <egy szam>
// Fifo laphibak szamanak megkeresese
#include <bits/stdc++.h>
using namespace std;
int pageFaultsLRU(int pages[], int n, int capacity)
{

    unordered_set<int> s;
    // egy beepitett hashmap szeru tarolo, egyedi kulcsokkal
    unordered_map<int, int> indexes;

    // Ugyan az mint a fifo algoritmusnal az eleje
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {

        if (s.size() < capacity)
        {

            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);

                page_faults++;
            }

            // itt taroljuk az utoljara hasznalt oldalak indexet
            indexes[pages[i]] = i;
        }

        // ha tele a keret akkor a legkorabban haszanlt elemet kivesszuk es helyere kerul az uj
        else
        {

            if (s.find(pages[i]) == s.end())
            {
                // melyik lru lap van benne a keretben
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }

                s.erase(val);

                s.insert(pages[i]);

                page_faults++;
            }

            // index frissitese
            indexes[pages[i]] = i;
        }
    }

    return page_faults;
}

bool search(int key, vector<int>& fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
 
// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int>& fr, int pn, int index)
{
    // Store the index of pages which are going
    // to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
 
        // If a page is never referenced in future,
        // return it.
        if (j == pn)
            return i;
    }
 
    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise
    // we return res.
    return (res == -1) ? 0 : res;
}
 
int pageFaultsOPT(int pg[], int pn, int fn)
{
    // Create an array for given number of
    // frames and initialize it as empty.
    vector<int> fr;
 
    // Traverse through page reference array
    // and check for miss and hit.
    int hit = 0;
    for (int i = 0; i < pn; i++) {
 
        // Page found in a frame : HIT
        if (search(pg[i], fr)) {
            hit++;
            continue;
        }
 
        // Page not found in a frame : MISS
 
        // If there is space available in frames.
        if (fr.size() < fn)
            fr.push_back(pg[i]);
 
        // Find the page to be replaced.
        else {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    return(pn-hit);
}

int pageFaultsFifo(int pages[], int n, int capacity)
{

    unordered_set<int> s;
    //egy beepitett fifo alapu tarolo
    queue<int> indexes;

    // elso lappal kezdve, vegig nezi hogy tud e lapokat tarolni meg
    // ha igen es meg nem tartalmazza ezt akkor beilleszti
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {

        if (s.size() < capacity)
        {

            if (s.find(pages[i]) == s.end())
            {

                s.insert(pages[i]);

                // page fault(aka) laphiba szamanak novelese
                page_faults++;

                // queue frissitese (egy fifo szerkezetu taroloegyseg)
                indexes.push(pages[i]);
            }
        }

        // ha televan akkor kitorli az elso elemet (pop)
        // es a vegere beilleszti a ujat
        else
        {

            if (s.find(pages[i]) == s.end())
            {

                int val = indexes.front();

                indexes.pop();

                s.erase(val);

                s.insert(pages[i]);

                indexes.push(pages[i]);

                page_faults++;
            }
        }
    }

    return page_faults;
}

int main()
{
    int pages[] = {7, 6, 5, 4, 6, 7, 3, 2, 6, 7, 6, 5, 1, 2, 5, 6, 7, 6, 5, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4; // memoria keret
    cout << pageFaultsFifo(pages, n, capacity) << endl;
    cout << pageFaultsLRU(pages, n, capacity) << endl;
    cout << pageFaultsOPT(pages, n, capacity) << endl;

    return 0;
}