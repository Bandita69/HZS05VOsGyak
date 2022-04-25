// HZS05V  C++ First - fit es Next fit algoritmus
#include <algorithm>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m,
              int processSize[], int n)
{
    // Tarolja a blokkok szamait
    // amelyiket sikerult lefoglalni
    int allocation[n];
    int blockSize_Origin[m];
    copy(blockSize, blockSize + m, blockSize_Origin);

    // alapbol nincs lefoglalas
    memset(allocation, -1, sizeof(allocation));

    // keresunk egy megfelelo blokkot
    // a meretetol fuggoen
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                // allokalja  a p[i] proceszt a j memoria blokkhoz
                allocation[i] = j;

                // Levonja az elfolglalt memoriat a blokkban
                blockSize[j] -= processSize[i];

                break;
            }
        }
    }

    cout << "\nProcesz szam\tes Meret\tLefoglalt Blokk\tes meret\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\t\t" << blockSize_Origin[allocation[i]];
        else
            cout << "Nem sikerult allocalni";
        cout << endl;
    }
}

void NextFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n], j = 0;
    int blockSize_Origin[m];
    copy(blockSize, blockSize + m, blockSize_Origin);

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {

        while (j < m)
        {

            if (blockSize[j] >= processSize[i])
            {

                allocation[i] = j;

                blockSize[j] -= processSize[i];

                break;
            }

            // mod m segit ha elerne a veget a blokkoknak
            // es hogy melyikkel probalkozzon ujra
            j = (j + 1) % m;
        }
    }

    cout << "\nProcesz szam\tes Meret\tLefoglalt Blokk\tes meret\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\t\t" << blockSize_Origin[allocation[i]];
        else
            cout << "Nem sikerult allocalni";
        cout << endl;
    }
}

void BestFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n];

    int blockSize_Origin[m];
    copy(blockSize, blockSize + m, blockSize_Origin);



    memset(allocation, -1, sizeof(allocation));


    for (int i = 0; i < n; i++)
    {
        // Keressunk legjobban passzolo blokkot
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        // Csak akkor ha talal megfelelo blokkot
        if (bestIdx != -1)
        {

            allocation[i] = bestIdx;


            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcesz szam\tes Meret\tLefoglalt Blokk\tes meret\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\t\t" << blockSize_Origin[allocation[i]];
        else
            cout << "Nem sikerult allocalni";
        cout << endl;
    }
}

int main()
{
    //Lehetne csinalni egy input funkciot, de lusta vagyok
    int blockSize[] = {30, 35, 15, 25, 75, 45};
    int processSize[] = {39, 40, 33, 20, 21};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    int blockSize_Next[m];
    copy(blockSize, blockSize + m, blockSize_Next);

    int blockSize_Best[m];
    copy(blockSize, blockSize + m, blockSize_Best);

    cout << "Szabad Blokkok: ";
    for (int el : blockSize)
        cout << el << " ";
    cout << "\nLefoglalas igenyek: ";
    for (int el : processSize)
        cout << el << " ";
    cout << "\n---------First Fit megoldas--------";
    firstFit(blockSize, m, processSize, n);
    cout << "\n---------Next Fit megoldas--------";
    NextFit(blockSize_Next, m, processSize, n);
    cout << "\n---------Best Fit megoldas--------";
    BestFit(blockSize_Best, m, processSize, n);

    return 0;
}