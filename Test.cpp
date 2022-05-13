#include <iostream>
#include <OrgChart.hpp>
#include "doctest.h"
#include <string>

using namespace std;
using namespace ariel;


TEST_CASE("Good Test"){
    OrgChart organization;
    organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI")
      .add_sub("CFO", "VP_S");
    // cout<<"12"<<endl;
    vector<string> vec = {"a", "b", "c", "d", "e", "f", "g"};
    vec.clear();
    // cout<<"19"<<endl;
    SUBCASE("start with begin_level_order and end with end_level_order"){
        // cout<<"21"<<endl;
        // vec.clear();
        // vec.push_back("CEO");
        // vec.push_back("CTO");
        // vec.push_back("CFO");
        // vec.push_back("COO");
        // vec.push_back("VP_SW");
        // vec.push_back("VP_S");
        // vec.push_back("VP_BI");
        // size_t i=0;
        // cout<<"org "<<organization<<endl;
        vector<string> vec = {"a", "b", "c", "d", "e", "f", "g"};
        vec.clear();
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
            // cout<<"32"<<endl;
            // CHECK((*it) == vec.at(i));
            // i++;

            vec.push_back((*it));
        }
        cout<<"vec size "<<vec.size()<<endl;
        // cout<<"vec"<< vec.at(0)<<endl;
        CHECK(vec.at(0) == "CEO");
        CHECK(vec.at(1) == "CTO");
        CHECK(vec.at(2) == "CFO");
        CHECK(vec.at(3) == "COO");
        CHECK(vec.at(4) == "VP_SW");
        CHECK(vec.at(5) == "VP_S");
        CHECK(vec.at(6) == "VP_BI");
    }

    SUBCASE("start with begin_reverse_order and end with reverse_order"){
        // vector<string> vec;   
        vector<string> vec = {"a", "b", "c", "d", "e", "f", "g"};
    // vec.clear();  
        vec.clear();   
        // vec.push_back("VP_SW");
        // vec.push_back("VP_S");
        // vec.push_back("VP_BI");
        // vec.push_back("CTO");
        // vec.push_back("CFO");
        // vec.push_back("COO");
        // vec.push_back("CEO");
        // size_t i=0;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){
            // CHECK((*it) == vec.at(i));
            // i++;
            vec.push_back((*it));
        }
        // cout<<"vec[0] "<<vec[0]<<endl;
        // cout<<"vec.at(I) "<<vec.at(0)<<endl;
        CHECK(vec[0] == "VP_SW");
        CHECK(vec[1] == "VP_S");
        CHECK(vec[2] == "VP_BI");
        CHECK(vec[3] == "CTO");
        CHECK(vec[4] == "CFO");
        CHECK(vec[5] == "COO");
        CHECK(vec[6] == "CEO");
    }
    SUBCASE("start with begin_preorder and end with end_preorder"){
        // vector<string> vec;
        vector<string> vec = {"a", "b", "c", "d", "e", "f", "g"};
    // vec.clear();
        vec.clear();
        // vec.push_back("CEO");   
        // vec.push_back("CTO");     
        // vec.push_back("VP_SW");
        // vec.push_back("CFO");
        // vec.push_back("VP_S");
        // vec.push_back("COO");
        // vec.push_back("VP_BI");
        // size_t i=0;
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
            // CHECK((*it) == vec.at(i));
            // i++;
            vec.push_back((*it));
        }
        CHECK(vec[0] == "CEO");
        CHECK(vec[1] == "CTO");
        CHECK(vec[2] == "VP_SW");
        CHECK(vec[3] == "CFO");
        CHECK(vec[4] == "VP_S");
        CHECK(vec[5] == "COO");
        CHECK(vec[6] == "VP_BI");
    }
    SUBCASE("change the root"){
        organization.add_root("root");
        // vector<string> vec;
        vector<string> vec = {"a", "b", "c", "d", "e", "f", "g"};
    // vec.clear();
        vec.clear();
        // vec.push_back("root");   
        // vec.push_back("CTO");     
        // vec.push_back("VP_SW");
        // vec.push_back("CFO");
        // vec.push_back("VP_S");
        // vec.push_back("COO");
        // vec.push_back("VP_BI");
        // size_t i=0;
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
            // CHECK((*it) == vec.at(i));
            // i++;
            vec.push_back((*it));
        }
        CHECK(vec[0] == "root");
        CHECK(vec[1] == "CTO");
        CHECK(vec[2] == "VP_SW");
        CHECK(vec[3] == "CFO");
        CHECK(vec[4] == "VP_S");
        CHECK(vec[5] == "COO");
        CHECK(vec[6] == "VP_BI");
    }
}
TEST_CASE("Bad Test"){
    OrgChart organization;
    CHECK_THROWS(organization.add_sub("CEO","add"));
    organization.add_root("CEO");
    CHECK_THROWS(organization.add_sub("CEo","C"));
    organization.add_sub("CEO", "CTO");
    CHECK_THROWS(organization.add_sub("cto","add"));
    organization.add_root("root");
    CHECK_THROWS(organization.add_sub("CEO","add"));   
}