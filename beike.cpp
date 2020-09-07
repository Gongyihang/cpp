#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    int k = T;
    int l = 0,r = 0;
    while(T--){
        int cl = 0,cr = 0;
        char nml,nnl,nmr,nnr;
        cin >> nml >> nmr >> nnl >> nnr;
        if(nml == 'J' && nnl == 'S') ;
        if(nml == 'J' && nnl == 'B') cl++;
        if(nml == 'S' && nnl == 'J') cl++;
        if(nml == 'S' && nnl == 'B') ;
        if(nml == 'B' && nnl == 'J') ;
        if(nml == 'B' && nnl == 'S') cl++;
        
        if(nmr == 'J' && nnr == 'S') ;
        if(nmr == 'J' && nnr == 'B') cr++;
        if(nmr == 'S' && nnr == 'J') cr++;
        if(nmr == 'S' && nnr == 'B') ;
        if(nmr == 'B' && nnr == 'J') ;
        if(nmr == 'B' && nnr == 'S') cr++;
        
        if(nml == 'J' && nnr == 'S') ;
        if(nml == 'J' && nnr == 'B') cl++;
        if(nml == 'S' && nnr == 'J') cl++;
        if(nml == 'S' && nnr == 'B') ;
        if(nml == 'B' && nnr == 'J') ;
        if(nml == 'B' && nnr == 'S') cl++;
        
        if(nmr == 'J' && nnl == 'S') ;
        if(nmr == 'J' && nnl == 'B') cr++;
        if(nmr == 'S' && nnl == 'J') cr++;
        if(nmr == 'S' && nnl == 'B') ;
        if(nmr == 'B' && nnl == 'J') ;
        if(nmr == 'B' && nnl == 'S') cr++;
        
        if(cr == cl) cout << "same" << endl;
        else if(cr > cl) cout << "right" << endl;
        else if(cr < cl) cout << "left" << endl;
    }
    return 0;
}