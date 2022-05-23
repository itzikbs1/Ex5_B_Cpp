#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
#include "OrgChart.hpp"

using namespace std;
namespace ariel{

        //scan the organization with level order method print from up to down step by step.
        void OrgChart::Iterator::level_order(Node *root){
            if(root != nullptr){
                queue<Node*> queue_c;
                queue_c.push(root);
                int size=0;
                while(!queue_c.empty()){
                    size=queue_c.size();
                    while(size>0){
                        Node *node_p = queue_c.front();
                        this->order_nodes.push_back(node_p);
                        queue_c.pop();
                        for (size_t i = 0; i < node_p->sub_node.size(); i++)
                        {
                            queue_c.push(node_p->sub_node.at(i));
                        }
                    size--;
                    }
                }
            }
            }
            //scan the organization with reverse level order method print From the bottom up and from right to left.
            void OrgChart::Iterator::reverse_level_order(Node *root){
                if(root != nullptr){
                    this->order_nodes.clear();
                    stack<Node*> s;
                    queue<Node*> queue;
                    s.push(root);
                    queue.push(root);
                    int size=0;
                    while(!queue.empty()){
                        size=queue.size();
                        while(size>0){
                            Node *node_p = queue.front();
                            queue.pop();
                            for (int i = int(node_p->sub_node.size()-1); i >= 0; i--)
                            {
                                s.push(node_p->sub_node.at(size_t(i)));
                                queue.push(node_p->sub_node.at(size_t(i)));
                            }
                        size--;
                        }
                    }
                    int size_s = s.size();
                    for (size_t i = 0; i < size_s; i++)
                    {
                        this->order_nodes.push_back(s.top());
                        s.pop();
                    }
                }
            }
            //scan the organization with level order method print from left to right and from up to down.
            void OrgChart::Iterator::preorder(Node *root){
                if(root != nullptr){
                    this->order_nodes.clear();
                    stack<Node*> stack;
                    stack.push(root);
                    while(!stack.empty()){
                        Node *temp = stack.top();
                        this->order_nodes.push_back(temp);
                        stack.pop();
                        for (int i = int(temp->sub_node.size()-1); i >= 0; i--)
                        {
                            stack.push(temp->sub_node.at(size_t(i)));
                        }
                    }
                }
            }
            //enpty Constructor
            OrgChart::Iterator::Iterator() : curr_indx(0){}

            //Constructor of Iterator
            OrgChart::Iterator::Iterator(Node *node, const string &order) : curr_indx(0) {
                if(order == "level_order" && node != nullptr){
                    level_order(node);
                }else if(order == "reverse_level_order" && node != nullptr){
                    reverse_level_order(node);
                }else{
                    if(node != nullptr){
                        preorder(node);
                    }
                }
                this->order_nodes.push_back(nullptr);
            }

            //operator++ after the promotion
            OrgChart::Iterator& OrgChart::Iterator::operator++(){
                this->curr_indx++;
                return *this;
            }
            
            //operator++ before the promotion
            OrgChart::Iterator& OrgChart::Iterator::operator++(int n){
                Iterator& iter = *this;
                this->curr_indx++;
                return iter;
            }
            //operator== check the address of specific node* in the vector
            bool OrgChart::Iterator::operator==(const OrgChart::Iterator& other) const{
                return this->order_nodes[this->curr_indx] == other.order_nodes[other.curr_indx];
            }
            //operator !=
            bool OrgChart::Iterator::operator!=(const OrgChart::Iterator& other) const{
                return !((*this) == other);
            }
            //operator* go one step inside
            string& OrgChart::Iterator::operator*(){
                return this->order_nodes[this->curr_indx]->_name;
            }
            //operator-> take the address of the variable
            string* OrgChart::Iterator::operator->(){
                return &(this->order_nodes[this->curr_indx]->_name);
            }
            void OrgChart::Iterator::set_curr_indx(uint current){
                this->curr_indx = current;
            }
            void OrgChart::Iterator::set_order_nodes(OrgChart::Node* &node, size_t temp){
                this->order_nodes.at(temp)->sub_node.push_back(node);
            }
    //default constructor
        OrgChart::OrgChart(){
            this->_root = nullptr;
        }
        //copy constructor
        OrgChart::OrgChart(const OrgChart &org) : _root(new Node(org._root->_name, org._root->sub_node)){}
        
        OrgChart::OrgChart(OrgChart &&other) noexcept{
            this->_root = other._root;
            other._root = nullptr;
        }
        OrgChart& OrgChart::operator=(OrgChart&& other) noexcept{
            this->_root = other._root;
            other._root = nullptr;
            return *this;
        }
        // //distructor    
        OrgChart::~OrgChart(){
            this->delete_organization(this->_root);
        }
        void OrgChart::delete_organization(Node *root){
            if(root == nullptr){
                return;
            }
            for (size_t i = 0; i < root->sub_node.size(); i++)
            {
                delete_organization(root->sub_node.at(i));
            }
            delete root;
        }
        OrgChart& OrgChart::operator=(const OrgChart &other){
            if(this == &other){
                return *this;
            }
            this->delete_organization((this->_root));
            this->_root = new OrgChart::Node(other._root->_name, other._root->sub_node);
            return *this;
        }
        // //check if root is null add to him else rape the old one and create new one
        OrgChart& OrgChart::add_root(const string &root_name){
            if(root_name == "\n"){
                throw runtime_error("this is invalid input");
            }
            if(this->_root == nullptr){
                this->_root = OrgChart::create_new_node(root_name);
            }else{
                this->_root->_name = root_name;
            }
            return *this;
        }
        //create new Node
        OrgChart::Node* OrgChart::create_new_node(const string &n){
            Node *temp = new Node{n};
            return temp;
        }
        //add new for the organization if n1 in the org
        OrgChart& OrgChart::add_sub(const string &n1, const string &n2){
            //if the root null than throw exception
            if(this->_root == nullptr){
                throw runtime_error(n1 + " dosen`t find in this Org!!!");
            }
            if(n2 == "\n"){
                throw runtime_error("this is invalid input");
            }
            // //if we want to crete new one for the root than do it
            if(this->_root->_name == n1){
                Node *new_node = create_new_node(n2);
                this->_root->sub_node.push_back(new_node);
            }
            //if is find in the org search him and put n2 in the right place    
            // }
            else{
                size_t temp=0;
                bool ans =false;
                
                for(auto iter = this->begin_level_order(); iter != OrgChart::end_level_order(); ++iter)
                {
                    if((*iter) == n1){
                        Node *new_node = this->create_new_node(n2);
                        iter.set_order_nodes(new_node, temp);
                        // iter.get_order_nodes().clear();
                        ans=true;
                        break;
                    }
                    temp++;
                }
                if(!ans){
                    throw runtime_error(n1 + " dosen`t find in this Org!");
                }
            }
            return *this;
        }
        //Iterator using the scan
        // OrgChart::Node* OrgChart::get_root() const{
        //     return this->_root;
        // }
        OrgChart::Iterator OrgChart::begin(){
            // cout<<"284"<<endl;
            return this->begin_level_order();
        }
        OrgChart::Iterator OrgChart::end(){
            return this->end_level_order();
        }
        OrgChart::Iterator OrgChart::begin_level_order(){
            // cout<<"291"<<endl;
            if(this->_root == nullptr){
                throw runtime_error("chart is empty!");
            }
            return OrgChart::Iterator(this->_root, "level_order");
        }
        OrgChart::Iterator OrgChart::end_level_order(){
            // cout<<"295"<<endl;
            if(this->_root == nullptr){
                throw runtime_error("chart is empty!");
            }
            return OrgChart::Iterator(nullptr, "level_order");
        }
        OrgChart::Iterator OrgChart::begin_reverse_order(){
            Iterator iter = OrgChart::Iterator(this->_root, "reverse_level_order");
            if(this->_root == nullptr){
                throw runtime_error("chart is empty!");
            }
            return iter;
        }
        OrgChart::Iterator OrgChart::reverse_order(){
            if(this->_root == nullptr){
                throw runtime_error("chart is empty!");
            }
            return OrgChart::Iterator(nullptr, "reverse_level_order");

        }
        OrgChart::Iterator OrgChart::begin_preorder(){
            Iterator iter = OrgChart::Iterator(this->_root, "");
            if(this->_root == nullptr){
                throw runtime_error("chart is empty!");
            }
            return iter;
        }
        OrgChart::Iterator OrgChart::end_preorder(){
            if(this->_root == nullptr){
                throw runtime_error("chart is empty!");
            }
            return OrgChart::Iterator(nullptr, "");
        }
        // //print the org with some scan
        // std::ostream& operator<<(ostream& os,const OrgChart &org){
        //     os << "                "<<org._root->_name<<endl;
        //     os<<endl;
        //     os<<"        |--------|--------|"<<endl;
        //     string space = "       ";
        //     for (size_t i = 0; i < org._root->sub_node.size(); i++)
        //     {
        //         if(org._root->sub_node.size() - i> 0){
        //             os<<space<<org._root->sub_node[i]->_name<<"             "<<endl;
        //             if(!org._root->sub_node[i]->sub_node.empty()){
        //                 for (size_t j = 0; j < org._root->sub_node[i]->sub_node.size(); j++)
        //                 {
        //                     os <<"        |"<<endl;
        //                     os<<"      "<<org._root->sub_node[i]->sub_node[j]->_name<<endl;
        //                 }
        //                 os<<endl;
        //             }
        //         }
        //     }
        //     return os;
        // }

        //print the org with some scan
        std::ostream& operator<<(ostream& os,const OrgChart &org){
            if(org._root != nullptr){
                os<<"             ";
                bool first_time=true;
                bool last_rotation=false;
                // this->order_nodes.clear();
                queue<OrgChart::Node*> queue_c;
                queue_c.push(org._root);
                int size=0;
                // string len = "    ";
                while(!queue_c.empty()){
                    size=queue_c.size();
                    while(size>0){
                        OrgChart::Node *node_p = queue_c.front();
                        // this->order_nodes.push_back(node_p);

                        // if(node_p->sub_node.size() < 2){
                        //     // cout<<"node p: "<<node_p->_name<<endl;
                        //     last_rotation=true;
                        // }
                        if(!first_time && !last_rotation){
                        os<<"     ";
                        }
                        // if(last_rotation){
                        //     os<<"   ";
                        // }
                        
                        first_time=false;
                        os<<node_p->_name;
                        queue_c.pop();
                        for (size_t i = 0; i < node_p->sub_node.size(); i++)
                        {
                            queue_c.push(node_p->sub_node.at(i));
                        }
                    size--;
                    }
                    os<<"\n\n";
                }
            }
            return os;
        }
};