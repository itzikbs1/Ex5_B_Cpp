#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <stack>

using namespace std;
namespace ariel{

    /*
        the class of th organization, private variable: Node* root 
    */
class OrgChart{
    
    
    /*
        create Node class with name(string) and vector of is "child".
    */
    struct Node{

    public:
        string _name;
        vector<Node*> sub_node;
        Node(string name) : _name(move(name)), sub_node(0){}
        Node(string name, vector<Node*> sub) : _name(move(name)), sub_node(move(sub)){}       
    };

    class Iterator{
        private:
            vector<Node*> order_nodes;
            uint curr_indx;
        public:
        void level_order(Node *root);
        void reverse_level_order(Node *root);
        void preorder(Node *root);
        Iterator(Node *node, const string &order);
        Iterator();
        Iterator& operator++();
        Iterator& operator++(int n);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        string& operator*();
        string* operator->();
        void set_curr_indx(uint current);
        void set_order_nodes(Node* &node, size_t temp);
    };
    private:
        Node* _root;
    public:
    //default constructor
    OrgChart();
    OrgChart(const OrgChart &org);
    OrgChart(OrgChart &&other) noexcept;
    OrgChart& operator=(OrgChart&& other) noexcept;
    ~OrgChart();
    OrgChart& add_root(const string &root_name);
    static Node* create_new_node(const string &n);
    OrgChart& add_sub(const string &n1, const string &n2);
    Iterator begin();
    Iterator end();
    Iterator begin_level_order();
    Iterator end_level_order();
    Iterator begin_reverse_order();
    Iterator reverse_order();
    Iterator begin_preorder();
    Iterator end_preorder();
    friend std::ostream& operator<<(ostream& os,const OrgChart &org);
    OrgChart& operator=(const OrgChart &other);
    void delete_organization(Node *root);       
};
}
