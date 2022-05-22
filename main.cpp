#include <iostream>
#include <stdlib.h>
#include <string>
#include "sources/OrgChart.cpp"

using namespace std;
using namespace ariel;

int main(){
OrgChart org;
org.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI"); 
string scan_org;
cout<<"Please choose a scan: ";
cin>>scan_org;

    if(scan_org == "level_order"){
        
        for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
        {
            cout << (*it) << " " ;
        } // prints: CEO CTO CFO COO VP_SW VP_BI
    }
    else if(scan_org == "reverse_level_order"){
        for (auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it)
        {
            cout << (*it) << " " ;
        } // prints: VP_SW VP_BI CTO CFO COO CEO
    }
    else if(scan_org == "preorder"){
        for (auto it=org.begin_preorder(); it!=org.end_preorder(); ++it) {
            cout << (*it) << " " ;
        }  // prints: CEO CTO VP_SW CFO COO VP_BI
    }
    else{
        cout<<"scann "<<scan_org<<endl;
        cout<<"You have only one choise!"<<endl;
        cin>>scan_org;
    }



return 0;
}