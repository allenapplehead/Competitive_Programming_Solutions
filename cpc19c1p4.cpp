#include <bits/stdc++.h>
using namespace std;
int instructions = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, resp;
    double k;
    cin >> N;
    cout << flush;
    bool repeat = true;
    

    k = log10(N) / log10(2);
    k = floor(k);

    for (int cur, i = k; i >= 1; i--)
    {
        cur = pow(2, i) - 1; // current gap

        for (int j = cur + 1; j <= N; j++)
        {
            repeat = true;
            for (int kk = j; kk > cur && repeat; kk -= cur)
            {
                repeat = false;
                // send query
                cout << "C " << kk - cur << " " << kk << endl;
                instructions++;
                
                cin >> resp;
                
                if (resp == 0)
                {
                    repeat = true;
                    cout << "S " << kk - cur << " " << kk << endl;
                    instructions++;
                    
                    cin >> resp;
                    
                    cout << "C " << kk - cur << " " << kk << endl;
                    instructions++;
                    cin >> resp;

                    if (resp == 0) {
                        // they are the same
                        repeat = false;
                    }
                    
                }
                
            }
        }
    }
    cout << "A" << endl;
    return 0;
}