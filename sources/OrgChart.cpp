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
            if(root == nullptr){
                return;
            }else{
                // this->order_nodes.clear();
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
                if(root == nullptr){
                    return;
                }else{
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
                if(root == nullptr){
                    return;
                }else{
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
            OrgChart::Iterator::Iterator(Node *node, const string &order) {
                this->set_curr_indx(0);
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
            // bool operator!=(const Iterator& other) const{//?????????????????????????????????????????????????????????????
            //     return !((*this) == other.end_level_order());
            // }
            //operator* go one step inside
            string& OrgChart::Iterator::operator*(){
                return this->order_nodes[this->curr_indx]->_name;
            }
            //operator-> take the address of the variable
            string* OrgChart::Iterator::operator->(){
                return &(this->order_nodes[this->curr_indx]->_name);
            }
            //getters and setters
            vector<OrgChart::Node*> OrgChart::Iterator::get_order_nodes(){
                return this->order_nodes;
            }
            uint OrgChart::Iterator::get_curr_indx() const{
                return this->curr_indx;
            }
            void OrgChart::Iterator::set_curr_indx(uint current){
                this->curr_indx = current;
            }
            void OrgChart::Iterator::set_order_nodes(OrgChart::Node* &node, size_t temp){
                this->order_nodes.at(temp)->sub_node.push_back(node);
            }
            // void set_curr_indx(){
                // this->get_curr_indx() = 0;
            // }
    //default constructor
        OrgChart::OrgChart(){
            this->_root = nullptr;
        }
        //copy constructor
        // OrgChart(const OrgChart &org) : _root(new Node(org._root->_name, org._root->sub_node)){}
            
        // //distructor    
        // ~OrgChart(){
        //     delete _root;
        // }
        // //check if root is null add to him else rape the old one and create new one
        OrgChart& OrgChart::add_root(const string &root_name){
            if(root_name == "\n"){
                throw runtime_error("this is invalid input");
            }
            else if(this->_root == nullptr){
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
            else if(n1 == "\n" || n2 == "\n"){
                throw runtime_error("this is invalid input");
            }
            // //if we want to crete new one for the root than do it
            else if(this->_root->_name == n1){
                Node *new_node = create_new_node(n2);
                this->_root->sub_node.push_back(new_node);
            }
            //if is find in the org search him and put n2 in the right place    
            // }
            else{
                size_t temp=0;
                bool ans =false;
                Node *new_node = this->create_new_node(n2);
                for(auto iter = this->begin_level_order(); iter != OrgChart::end_level_order(); ++iter)
                {
                    if((*iter) == n1){
                        iter.set_order_nodes(new_node, temp);
                        iter.get_order_nodes().clear();
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
        OrgChart::Node* OrgChart::get_root() const{
            return this->_root;
        }
        OrgChart::Iterator OrgChart::begin(){
            // cout<<"284"<<endl;
            return begin_level_order();
        }
        OrgChart::Iterator OrgChart::end(){
            return end_level_order();
        }
        OrgChart::Iterator OrgChart::begin_level_order(){
            // cout<<"291"<<endl;
            return OrgChart::Iterator(this->_root, "level_order");
        }
        OrgChart::Iterator OrgChart::end_level_order(){
            // cout<<"295"<<endl;
            return OrgChart::Iterator(nullptr, "level_order");
        }
        OrgChart::Iterator OrgChart::begin_reverse_order(){
            return OrgChart::Iterator(this->_root, "reverse_level_order");
        }
        OrgChart::Iterator OrgChart::reverse_order(){
            return OrgChart::Iterator(nullptr, "reverse_level_order");

        }
        OrgChart::Iterator OrgChart::begin_preorder(){
            return OrgChart::Iterator(this->_root, "");
        }
        OrgChart::Iterator OrgChart::end_preorder(){
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