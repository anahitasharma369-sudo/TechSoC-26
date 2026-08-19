#include <iostream>
using namespace std ; 
int main() { 
int N; // number of containers 
double C ; // storage capacity 
double W1 ; // weight 1 
double W2 ; // weight 2 
double w3 ; // weight 3 
cout << " enter storage capacity here " << endl ; 
cin >> C ; 
cout<< " number of containers " << endl ; 
cin >> N ; 
cout << " enter weight 1 , weight 2 , weight 3 " << endl ; 
cin >> W1 >> W2 >> W3 ; 
double total = W1 + W2 + W3 ;
double avg = total/N ;
double heaviest = max({ W1 , W2 , W3 } ) ; 
double lightest = min( { W1 , W2 , W3 } ) ; 
cout<< " total weight " << total << endl ; 
cout << " average " << avg << endl ; 
cout << " heaviest container " <<  heaviest << endl ; 
cout << " lightest container " << lightest << endl ; 
if ( total > 300 ) { 
cout << " classification - heavy " << endl ;
} else { 
cout << " classification - light " << endl ; 
} 
cout << " port capacity " << C << endl ; 
if ( total <= C ) {
cout << " Status : shipment can be unloaded " << endl ; 
} else { 
cout << " Status : shipment exceeds port capacity " << endl ; 
} 
return 0 ; 
} 
