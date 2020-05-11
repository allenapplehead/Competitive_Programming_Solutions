#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define ln '\n';

int e_gcd (int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
class ST {
    private:
        vi st, A, freq;
        int n;
        int left (int p) {
            return p << 1;
        }
        int right (int p) {
            return (p << 1) + 1;
        }
        void build(int p, int L, int R, bool gcd) {
            if (L == R) {
                st[p] = A[L];
                freq[p] = 1;
            } else {
                build(left(p), L, (L + R) / 2, gcd); // left right closed
                build(right(p), (L + R) / 2 + 1, R, gcd); // left right closed
                int p1 = st[left(p)], p2 = st[right(p)];
                if (gcd) {
                    st[p] = e_gcd(p1, p2);
                    if (st[p] == p1) {
                        freq[p] += freq[left(p)];
                    } else {
                        for (int i = L; i <= (L + R) / 2; i++) {
                            if (A[i] == st[p]) freq[p]++;
                        }
                    }
                    if (st[p] == p2) {
                        freq[p] += freq[right(p)];
                    } else {
                        for (int i = (L + R) / 2 + 1; i <= R; i++) {
                            if (A[i] == st[p]) freq[p]++;
                        }
                    }
                } else {
                    st[p] = (p1 <= p2) ? p1 : p2;
                }
            }
        }
        int rmq(int p, int L, int R, int i, int j, bool gcd) {
            if (i > R || j < L) {
                return -1; // completely outside query range
            }
            if (L >= i && R <= j) {
                return st[p]; // completely inside query range (or partially)
            }

            // compute the min position in the left and right part of the interval
            int p1 = rmq(left(p), L, (L + R) / 2, i, j, gcd);
            int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j, gcd);

            if (p1 == -1) return p2;
            if (p2 == -1) return p1;
            if (gcd) {
                return e_gcd(p1, p2);
            } else {
                return (p1 <= p2) ? p1 : p2;
            }
        }
        void update (int p, int L, int R, int idx, int val, bool gcd) {
            if (L == R) {
                // leaf node
                A[idx] = val;
                st[p] = val;
                freq[p] = 1;
            } else {
                if (L <= idx && idx <= (L + R) / 2) {
                    update(left(p), L, (L + R) / 2, idx, val, gcd);
                } else {
                    update(right(p), (L + R) / 2 + 1, R, idx, val, gcd);
                }
                int p1 = st[left(p)];
                int p2 = st[right(p)];
                if (gcd) {
                    st[p] = e_gcd(st[left(p)], st[right(p)]);
                    freq[p] = 0;
                    if (st[p] == p1) {
                        freq[p] += freq[left(p)];
                    } else {
                        for (int i = L; i <= (L + R) / 2; i++) {
                            if (A[i] == st[p]) freq[p]++;
                        }
                    }
                    if (st[p] == p2) {
                        freq[p] += freq[right(p)];
                    } else {
                        for (int i = (L + R) / 2 + 1; i <= R; i++) {
                            if (A[i] == st[p]) freq[p]++;
                        }
                    }
                } else {
                    st[p] = (st[left(p)] <= st[right(p)]) ? st[left(p)] : st[right(p)];
                }
            }
        }
        int findFreq (int p, int L, int R, int i, int j, int val) {
            // only for gcd
            if (i > R || j < L) {
                return -1;
            } 
            if (L >= i && R <= j) {
                if (st[p] > val) {
                    return 0;
                }
                if (L == R) {
                    // we hit a leaf
                    return A[L] == val ? 1 : 0;
                }
                if (st[p] == val) return freq[p];
            }
            int p1 = findFreq(left(p), L, (L + R) / 2, i, j, val);
            int p2 = findFreq(right(p), (L + R) / 2 + 1, R, i, j, val);
            if (p1 == -1) return p2;
            if (p2 == -1) return p1;
            return p1 + p2;
        }

    public:
        bool gcdGlobal;
        ST(const vi &_A, bool gcd) {
            gcdGlobal = gcd;
            A = _A; n = (int)A.size();
            freq.assign(4 * n, 0);
            st.assign(4 * n, 0);
            build(1, 0, n - 1, gcd);
        }
        int rmq(int i, int j) {
            return rmq(1, 0, n - 1, i, j, gcdGlobal);
        }
        void update(int idx, int val) {
            update(1, 0, n - 1, idx, val, gcdGlobal);
        }
        int findFreq(int i, int j, int val) {
            return findFreq(1, 0, n - 1, i, j, val);
        }
        void printOrig() {
            cout << "PRINTING ORIGINAL ARRAY: " << ln;
            for (int i : A) {
                cout << i << ln;
            }
            cout << ln;
        }
        void printSt() {
            cout << "PRINTING SEGMENT TREE: " << ln;
            for (int i : st) {
                cout << i << ln;
            }
            cout << ln;
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, temp, fir, sec, tgt;
    char command;
    vi A;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        A.push_back(temp);
    }
    
    ST st1(A, false);
    ST st2(A, true);

    while(m--) {
        cin >> command;
        cin >> fir >> sec;
        if (command == 'C') {
            /* prev = A[fir - 1];
            A[fir - 1] = sec; */
            st1.update(fir - 1, sec);
            st2.update(fir - 1, sec);
        } else if (command == 'M') {
            cout << st1.rmq(fir - 1, sec - 1) << ln;
        } else if (command == 'G') {
            cout << st2.rmq(fir - 1, sec - 1) << ln;
        } else if (command == 'Q') {
            tgt = st2.rmq(fir - 1, sec - 1);
            cout << st2.findFreq(fir - 1, sec - 1, tgt) << ln;

        } else {
            // debug
            st1.printSt();
            st1.printOrig();
            cout << "FENCE" << ln;
            st2.printSt();
            st2.printOrig();
        }
    }

    return 0;
}