#include<iostream>
using namespace std;

class cricket
{
    char name[20];
    int no_innings;
    int total_runs;
    double avg;

public:
    void getdetails()
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter no_innings:";
        cin >> no_innings;
        cout << "Enter total_runs:";
        cin >> total_runs;
        cout << "Enter avg:";
        cin >> avg;
        cout << endl;
    }

    void print()
    {
        cout << "name:" << name << endl;
        cout << "no_innings" << no_innings << endl;
        cout << "total_runs" << total_runs << endl;
        cout << "avg" << avg << endl;
    }

    void updateavg()
    {
        cout << "Enter new avg:";
        cin >> avg;
    }

    friend double highestAvg(cricket[], int);
};

double highestAvg(cricket players[], int size)
{
    double max = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < players[i].avg)
            max = players[i].avg;
    }
    return max;
}

int main()
{
    cricket p[50];
    int ch, k, u, i = 0;

    while (1)
    {
        cout << "1--Add player  2--display player  3--updateavg  4--highavg  5--exit" << endl;
        cout << "enter choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Add player " << i + 1 << " Details:" << endl;
            p[i].getdetails();
            i++;
            cout << endl;
            break;
        case 2:
            cout << "Enter player no. to display details:" << endl;
            cin >> k;
            p[k - 1].print();
            cout << endl;
            break;
        case 3:
            cout << "Enter player no. to update avg:" << endl;
            cin >> u;
            p[u - 1].updateavg();
            cout << endl;
            break;
        case 4:
            cout << "Highest avg=" << highestAvg(p, i) << endl;
            cout << endl;
            break;
        case 5:
            exit(0);
            break;
        }
    }
    return 0;
}


