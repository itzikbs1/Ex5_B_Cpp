#include <iostream>
#include <OrgChart.hpp>
#include "doctest.h"
#include <string>
using namespace std;
using namespace ariel;


TEST_CASE("Good Test"){
    OrgChart organization;

    organization.add_root("root");
    organization.add_root("CEO")
    .add_sub("CEO", "CTO")    
    .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
    .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
    .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
    .add_sub("COO", "VP_BI")
    .add_sub("CFO", "VP_S");

    // SUBCASE("add a root and change him"){
    //     organization.add_root("root");
    //     organization.add_root("CEO");
    // }
    // for(auto iter = organization.begin(); iter != organization.end(); iter++){
    //     cout<<"iter "<<(*iter)<<endl;
    // }
    // SUBCASE("add_sub"){
    //     organization.add_sub("CEO", "CTO")  ;       // Now the CTO is subordinate to the CEO
    //     .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
    //     .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
    //     .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
    //     .add_sub("COO", "VP_BI")
    //     .add_sub("CFO", "VP_S");
    // }
    SUBCASE("start with begin_level_order and end with end_level_order"){
        vector<string> vec;
        vec.clear();
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
            vec.push_back((*it));
        }
        CHECK(vec.at(0) == "CEO");
        CHECK(vec.at(1) == "CTO");
        CHECK(vec.at(2) == "CFO");
        CHECK(vec.at(3) == "COO");
        CHECK(vec.at(4) == "VP_SW");
        CHECK(vec.at(5) == "VP_S");
        CHECK(vec.at(6) == "VP_BI");
    }

    SUBCASE("start with begin_reverse_order and end with reverse_order"){
        vector<string> vec;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){
            vec.push_back((*it));
        }
        CHECK(vec.at(0) == "VP_SW");
        CHECK(vec.at(1) == "VP_S");
        CHECK(vec.at(2) == "VP_BI");
        CHECK(vec.at(3) == "CTO");
        CHECK(vec.at(4) == "CFO");
        CHECK(vec.at(5) == "COO");
        CHECK(vec.at(6) == "CEO");
    }
    SUBCASE("start with begin_preorder and end with end_preorder"){
        vector<string> vec;
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
            vec.push_back((*it));
        }
        CHECK(vec.at(0) == "CEO");
        CHECK(vec.at(1) == "CTO");
        CHECK(vec.at(2) == "VP_SW");
        CHECK(vec.at(3) == "CFO");
        CHECK(vec.at(4) == "VP_S");
        CHECK(vec.at(5) == "COO");
        CHECK(vec.at(6) == "VP_BI");
    }
    SUBCASE("change the root"){
        organization.add_root("root");
        vector<string> vec;
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
            vec.push_back((*it));
        }
        CHECK(vec.at(0) == "root");
        CHECK(vec.at(1) == "CTO");
        CHECK(vec.at(2) == "VP_SW");
        CHECK(vec.at(3) == "CFO");
        CHECK(vec.at(4) == "VP_S");
        CHECK(vec.at(5) == "COO");
        CHECK(vec.at(6) == "VP_BI");
    }
    SUBCASE("add sub"){
        organization.add_root("root");
        organization.add_sub("CTO", "itzik");
        organization.add_sub("VP_SW", "CIO");
        vector<string> vec;
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
            vec.push_back((*it));
        }
        CHECK(vec.at(0) == "root");
        CHECK(vec.at(1) == "CTO");
        CHECK(vec.at(2) == "VP_SW");
        CHECK(vec.at(3) == "CIO");
        CHECK(vec.at(4) == "itzik");
        CHECK(vec.at(5) == "CFO");
        CHECK(vec.at(6) == "VP_S");
        CHECK(vec.at(7) == "COO");
        CHECK(vec.at(8) == "VP_BI");
    }
    SUBCASE("add to the first sub that he see"){
        OrgChart organization;
        organization.add_root("root");
        organization.add_sub("root", "itzik");
        organization.add_sub("itzik", "root"); // root -> CEO , itzik -> root
        organization.add_sub("root", "CEO");
        vector<string> vec;
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
            vec.push_back((*it));
        }
        CHECK_EQ(vec.at(0) , "root");
        CHECK_EQ(vec.at(1) , "itzik");
        CHECK_EQ(vec.at(2) , "root");
        CHECK_EQ(vec.at(3) , "CEO");
    }
}
TEST_CASE("Bad Test"){
    OrgChart organization;
    OrgChart org;
    SUBCASE("add sub when the root iis null"){
        CHECK_THROWS(organization.add_sub("root","add"));
        CHECK_THROWS(organization.add_sub("CEo","C"));
        CHECK_THROWS(organization.add_sub("cto","add"));
        CHECK_THROWS(organization.add_sub("CEO","add"));
        CHECK_THROWS(organization.add_sub(" ","root"));   
    }
    SUBCASE("add invalid sub"){
        organization.add_root("root");
        CHECK_THROWS(organization.add_sub("CEO","add"));
        organization.add_root("CEO");
        CHECK_THROWS(organization.add_sub("CEo","C"));
        CHECK_THROWS(organization.add_sub("cto","add"));
        organization.add_root("root");
        CHECK_THROWS(organization.add_sub("CEO","add"));   
        CHECK_THROWS(organization.add_sub("CEO", "CTO"));      ////root -> ..
        organization.add_root("CEO"); ///CEO -> ..
    }
    SUBCASE("add invaild input"){
        CHECK_THROWS(organization.add_root("\n"));
        CHECK_THROWS(organization.add_sub("root", "\n"));
        CHECK_THROWS(organization.add_root("\r"));
        CHECK_THROWS(organization.add_sub("root", "\r"));
        CHECK_THROWS(organization.add_root("\t"));
        CHECK_THROWS(organization.add_sub("root", "\t"));
        CHECK_THROWS(organization.add_root(""));
        CHECK_THROWS(organization.add_sub("root", ""));
        CHECK_THROWS(organization.add_root(" "));
        CHECK_THROWS(organization.add_sub("root", " "));
        // CHECK_THROWS(organization.add_root("\t"));
        // CHECK_THROWS(organization.add_sub("root", "\t"));
        // CHECK_THROWS(org.add_root())
    }
}