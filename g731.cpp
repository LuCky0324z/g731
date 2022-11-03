#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define int long long int

using namespace std;

int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}

const vector<string> split(const string &str, const char &delimiter) {
    vector<string> result;
    stringstream ss(str);
    string tok;

    while (getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}

string red(int a,int b){
    int g=gcd(a,b);
    a=a/g;
    b=b/g;
    return to_string(a)+"/"+to_string(b);
}

signed main() {
    string str;
    getline(cin,str);
    vector<string> ret = split(str, '+');
    int a1, a2,    b1, b2,   ab1, ab2;
    string gcd_ab;
    int now=1;
    vector<string> rr = split(ret[0], '/');
    a1 = atoi(rr[0].c_str());
    a2 = atoi(rr[1].c_str());
    for (int i=1; i<ret.size(); i++) {
        rr = split(ret[i], '/');   
        b1 = atoi(rr[0].c_str());     
        b2 = atoi(rr[1].c_str());     
        ab1 = a1*b2+a2*b1;
        ab2 = a2*b2;
        gcd_ab = red(ab1, ab2);
        cout<<'='<<gcd_ab;
        now++;
        for(int j=now;j<ret.size();j++) cout<<'+'<<ret[j];
        cout<<endl;
        a1 = ab1;
        a2 = ab2;
    }
    return 0;
}
