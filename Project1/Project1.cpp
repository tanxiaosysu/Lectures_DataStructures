#include <iostream>
#include <set>
#include <stack>

using namespace std;

class stackt {
  public:
    stack<int> a;
    int number;
    bool operator<(const stackt &other) const {
        return (a.top() < other.a.top());
    }
};

int n;
set<stackt> s;
int numofstack = 0;
int wanttoout,noout,noin;
int inlist[2000];

void popp(set<stackt>::iterator &it) {
    stackt b;
    b = *it;
    b.a.pop();
    if (!b.a.empty()) s.insert(b);
    s.erase(it);
}
void check() {
    bool suc;
    set<stackt>::iterator iter;
    do {
        suc = false;
        for (iter = s.begin(); iter != s.end(); iter++) {
            if (iter->a.top() == wanttoout) {
                //stacktoout();
                cout << wanttoout << " from stack "<< iter->number << " to out." << endl;
                set<stackt>::iterator it;
                it = iter;
                iter++;
                popp(it);
                it = s.end();
                wanttoout++;
                noout--;
                suc = true;
                if (iter == s.end()) break;
            } else if (iter->a.top() > wanttoout) break;
        }
    } while (suc == true);
}
void pushp(set<stackt>::iterator it, int x) {
    stackt b;
    b = *it;
    b.a.push(x);
    s.insert(b);
    s.erase(it);
}
void intostack(int x) {
    set<stackt>::iterator iter;
    bool suc = false;
    for (iter = s.begin(); iter != s.end(); iter++) {
        if (x < iter->a.top()) {
            set<stackt>::iterator it;
            cout << x << " from in to stack " << iter->number << "." << endl;
            it = iter;
            iter++;
            pushp(it, x);
            suc = true;
            // print x from in to stack, no new stack;
            if (iter == s.end()) break;
        }
    }
    if (suc == false) {
        numofstack++;
        stackt b;
        b.number = numofstack;
        b.a.push(x);
        s.insert(b);
        cout << x << " from in to stack.Create a new stack(No." << b.number << ")." << endl;
        // print x from in to stack, create new stack;
    }
    noin--;
}

int main() {
    cout << "Please input:\n"
         << "Every input has 2 lines\n"
         << "The first line is the length of the train.(length >= 2)\n"
         << "The second line is the number of train carriage.(seperated by space)\n";
    cin >> n;
    int i;
    for (i = 1; i <= n; i++) cin >> inlist[i];
    wanttoout = 1;
    noout = n;
    noin = n;
    while (noout > 0) {
        check();
        if (noout == 0) {
            cout << "Program over." << endl;
            cout << "Use " << numofstack << " stack(s)." << endl;
            break;
        }
        if (noin > 0 && inlist[noin] == wanttoout) {
            cout << wanttoout << " from in to out.No new stack." << endl;
            wanttoout++;
            noout--;
            noin--;
        } else {
            intostack(inlist[noin]);
        }
    }
    return 0;
}
