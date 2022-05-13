/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
  OrgChart organization;
  cout<<"19"<<endl;
  organization.add_root("CEO");
  // cout<<"org "<<organization.begin()<<endl;
  cout<<"21"<<endl;
      organization.add_sub("CEO", "CTO");         // Now the CTO is subordinate to the CEO
      cout<<"22"<<endl;
      organization.add_sub("CEO", "CFO")  ;       // Now the CFO is subordinate to the CEO
      // cout << organization << endl;
      cout<<"26"<<endl;
      organization.add_sub("CEO", "COO")   ;      // Now the COO is subordinate to the CEO
      cout<<"28"<<endl;
      organization.add_sub("CTO", "VP_SW");// Now the VP Software is subordinate to the CTO
      cout<<"31"<<endl;
      organization.add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO
      // organization.add_sub("VP_BI", "VP_XY");      // Now the VP_BI is subordinate to the COO
      // organization.add_sub("CFO", "XXX");      // Now the VP_BI is subordinate to the COO
      // organization.add_sub("XXX", "QQQ");      // Now the VP_BI is subordinate to the COO

  cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */
  cout<<"************************************************************************************"<<endl;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI
  cout<<endl;
  cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: VP_SW VP_BI CTO CFO COO CEO
  cout<<endl;
  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: CEO CTO VP_SW CFO COO VP_BI
  cout<<endl;
  for (auto element : organization)
  { // this should work like level order
    cout <<element << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI
  cout<<endl;
  // demonstrate the arrow operator:
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 3 3 3 3 5 5
}