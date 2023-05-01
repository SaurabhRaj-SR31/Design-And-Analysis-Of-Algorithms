#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class algo
{

public:
    int idx;
    int atm;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int pr;
    void srtf();
    void rr();
    void priority();
};

void algo::srtf()
{

    int n;

    cout << "enter no. of process:" << endl;
    cin >> n;

    algo a[n];

    for (int i = 0; i < n; i++)
    {

        cout << "enter AT of P" << (i + 1) << ":" << endl;
        a[i].idx = (i + 1);
        cin >> a[i].atm;
        cout << "enter BT of P" << (i + 1) << ":" << endl;
        cin >> a[i].bt;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].atm > a[j + 1].atm)

            {
                algo temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int temp[10];
    int count = 0, t = 0, short_P;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;

    for (int i = 0; i < n; i++)
    {

        temp[i] = a[i].bt;
    }

    a[9].bt = 10000;

    for (t = 0; count != n; t++)
    {

        short_P = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[i].bt < a[short_P].bt && (a[i].atm <= t && a[i].bt > 0))
            {
                short_P = i;
            }
        }
        cout << "  " << t << "  "
             << "P" << short_P + 1 << "  ";
        a[short_P].bt = a[short_P].bt - 1;

        if (a[short_P].bt == 0)
        {

            count++;
            a[short_P].wt = t + 1 - a[short_P].atm - temp[short_P];
            a[short_P].tat = t + 1 - a[short_P].atm;

            total_WT = total_WT + a[short_P].wt;
            total_TAT = total_TAT + a[short_P].tat;
        }
    }
    cout << "  " << t << "  " << endl;
    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;
    cout << "Process\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << "P" << a[i].idx << "\t" << a[i].atm << "\t" << a[i].bt << "\t" << (a[i].tat + a[i].atm) << "\t" << a[i].tat << "\t" << a[i].wt << endl;
    }

    cout << "Avg turn around time of the process =" << Avg_TAT << endl;
    cout << "Avg waiting time of the process is =" << Avg_WT << endl;
}

void algo::rr()
{

    int n;

    cout << "enter no. of process:" << endl;
    cin >> n;
    algo a[n];

    for (int i = 0; i < n; i++)
    {

        cout << "enter AT of P" << (i + 1) << ":" << endl;
        a[i].idx = (i + 1);
        cin >> a[i].atm;
        cout << "enter BT of P" << (i + 1) << ":" << endl;
        cin >> a[i].bt;
    }

    int time_quantum;

    cout << "Enter Time Quantum :" << endl;

    cin >> time_quantum;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].atm > a[j + 1].atm)

            {
                algo temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    queue<int> q;

    int clock_time = 0;

    bool visited[n + 1];

    int first_arrived_process = -1;

    for (int i = 0; i < n; i++)
    {
        a[i].wt = a[i].tat = 0;
        a[i].rt = a[i].bt;
        visited[i] = false;

        if (first_arrived_process == -1 || a[i].atm < a[first_arrived_process].atm)
            first_arrived_process = i;
    }

    q.push(first_arrived_process);
    visited[first_arrived_process] = true;

    while (!q.empty())
    {

        int running_process = q.front();
        q.pop();

        bool to_add_current_process = false;

        cout << "  " << clock_time << "  "
             << "P" << running_process + 1 << "  ";

        if (a[running_process].rt > time_quantum)
        {
            a[running_process].rt -= time_quantum;

            clock_time += time_quantum;

            to_add_current_process = true;
        }

        else
        {
            clock_time += a[running_process].rt;

            a[running_process].rt = 0;

            a[running_process].wt = clock_time - a[running_process].atm - a[running_process].bt;
            a[running_process].tat = a[running_process].wt + a[running_process].bt;
        }

        for (int i = 0; i <= n; i++)
        {

            if ((a[i].atm <= clock_time) && (visited[i] == false))
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if (to_add_current_process == true)
            q.push(running_process);
    }
    cout << clock_time << "  " << endl;
    float avg_tat = 0, avg_wt = 0;
    cout << endl;
    cout << "Process\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << a[i].idx << "\t" << a[i].atm << "\t" << a[i].bt << "\t" << (a[i].tat + a[i].atm) << "\t" << a[i].tat << "\t" << a[i].wt << endl;
        avg_tat += a[i].tat;
        avg_wt += a[i].wt;
    }
    cout << "Avg turn around time of the process =" << (float)(avg_tat / n) << endl;
    cout << "Avg waiting time of the process is =" << (float)(avg_wt / n) << endl;
}

void algo::priority()
{
    int n;

    cout << "enter no. of process:" << endl;
    cin >> n;
    algo a[n];

    for (int i = 0; i < n; i++)
    {

        cout << "enter AT of P" << (i + 1) << ":" << endl;
        a[i].idx = (i + 1);
        cin >> a[i].atm;
        cout << "enter BT of P" << (i + 1) << ":" << endl;
        cin >> a[i].bt;
        cout << "enter priority of P" << (i + 1) << ":" << endl;
        cin >> a[i].pr;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].pr > a[j + 1].pr)

            {
                algo temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int current_time = 0;

    vector<algo> completed_processes;

    for (int i = 0; i < n; i++)
    {
        algo p = a[i];

        if (current_time < p.atm)
        {
            current_time = p.atm;
        }
        cout << "  " << current_time << "  "
             << "P" << p.idx << "  ";

        p.ct = current_time + p.bt;

        completed_processes.push_back(p);
        current_time = p.ct;
    }
    cout << current_time << "  " << endl;
    float avg_tat = 0, avg_wt = 0;
    cout << "Process\tAT\tBT\tPT\tCT\tTAT\tWT" << endl;
    for (const algo &p : completed_processes)
    {
        cout << "P" << p.idx << "\t" << p.atm << "\t" << p.bt << "\t" << p.pr << "\t" << (p.ct) << "\t" << p.ct - p.atm << "\t" << p.ct - p.atm - p.bt << endl;
        avg_tat += p.tat;
        avg_wt += p.wt;
    }

    cout << "Avg turn around time of the process =" << (float)(avg_tat / n) << endl;
    cout << "Avg waiting time of the process is =" << (float)(avg_wt / n) << endl;
}
int main()
{

    algo obj;
    int ch;
    while (1)
    {

        cout << "Welcome to the process scheduling\n";
        cout << "1. SJF-Preemptive\n";
        cout << "2. Round Robin\n";
        cout << "3. Priority-Nonpreemptive\n";
        cout << "4. exit\n";

        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.srtf();

            break;

        case 2:
            obj.rr();

            break;

        case 3:
            obj.priority();
            break;

        case 4:
            exit(0);
        default:
            cout << "\n Wrong Input\n";
        }
        return 0;

        return 0;
    }
}