/*
 * BST.h
 *
 *  Created on: Nov 20, 2017
 *      Author: Maya
 */

/*
 * BST.h
 *
 *  Created on: Nov 2, 2017
 *      Author: Maya
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include "Song.h"
#include<iostream>

using namespace std;
template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* leftchild;
        Node* rightchild;

        Node(bstdata newdata)
        {
            data = newdata;
            leftchild = NULL;
            rightchild = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    void insertNode(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrint(ostream& out, Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrint(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrint(ostream& out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyNode(Node* copy);
    //recursive helper function to the copy constructor

    void freeNode(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchNode(Node* root, bstdata data)const;
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimum(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximum(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* deleteNode(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSize(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeight(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

    void getResults(Node* root, string usersearch, int searchtype, ostream& out, int& found);
    //checks the BST at a index and pulls all the nodes that match into a results BST

public:

    /**constructors and destructor*/

    BST();
    //Instantiates a new BST

    BST(const BST &bst);
    //copy constructor

    ~BST();
    //deallocates the tree memory

    /**access functions*/

    bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const;
    //determines whether the BST is empty

    int getSize() const;
    //returns the size of the tree

    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bool search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST

    void results(string userSearch, int searchtype, ostream& out, int& found);
    //wrapper function for getResults
    //stores all results in a new BST

    void fullResults(string usersearch, ostream& out, Node* root, int& found);

    void getFullResults(string search, ostream& out, int& found);
};



/*
 * BST.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: Maya & Kyle
 */

//BST.cpp


template<typename bstdata>
BST<bstdata>::BST()
	{
	root=NULL;
	}


template<typename bstdata>
BST<bstdata>::BST(const BST &bst) //&bst is the source object
{
	root=NULL;
	if(bst.root==NULL)
		return;
	else
	{
		copyNode(bst.root);
	}
}


template<typename bstdata>
BST<bstdata>::~BST()
	{
	freeNode(root);



	}
template<typename bstdata>
void BST<bstdata>:: insertNode(Node* root, bstdata data)//private version
	{
		Node* N = new Node(data);// IS THIS OK!>!?!?!? to not pass in root
		if(root->data>data)
			{
				if(root->leftchild==NULL)
					{root->leftchild=N;}
				else
					{insertNode(root->leftchild,data);}
			}
		else //root->data>data
			{
				if(root->rightchild==NULL)
					{root->rightchild=N;}
				else
					{insertNode(root->rightchild,data);}
			}

	}


template<typename bstdata>
void BST<bstdata>::insert(bstdata data) //wrapper
	{
	 	 if (root == NULL)
	 	 {
	 		 root = new Node(data); //if the tree is empty insert the value at the root
	 	 }
	    else
	    	{
	    		insertNode(root, data); //otherwise call the helper function, passing it the root
	    	}
	}

template<typename bstdata>
void  BST<bstdata>:: inOrderPrint(ostream& out, Node* root) const //private
	{
		/*if(root->data == NULL)
		{
			out << "Null thing"<<endl;
			return;
		}*/
		if(root == NULL)
		{
			return;
		}
		else
		{
			inOrderPrint(out, root->leftchild);
			out << root->data;
			inOrderPrint(out,root->rightchild);
		}
	}


template<typename bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const //wrapper
{
	inOrderPrint(out,root);
}


template<typename bstdata>
void  BST<bstdata>:: preOrderPrint(ostream& out, Node* root) const //private
	{
		if(root==NULL) //base case(stop passing in the leftchild when a node points to null)
			return;
		if(root!=NULL)
			{
				out << root->data <<" ";
				preOrderPrint(out, root->leftchild);
				preOrderPrint(out, root->rightchild);

			}

	}


template<typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const //wrapper
{
	preOrderPrint(out,root);
}

template<typename bstdata>
void  BST<bstdata>:: postOrderPrint(ostream& out, Node* root) const //private
	{
		if(root==NULL)
			return;
		if(root!=NULL)
			{
				postOrderPrint(out, root->leftchild);
				postOrderPrint(out, root->rightchild);
				out << root->data <<" ";
			}

	}


template<typename bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const //wrapper
{
	postOrderPrint(out,root);
}
template<typename bstdata>
void BST<bstdata>::copyNode(Node* copy)  //private helper of copy constructor
	{
		if(copy==NULL)
		{
		return;
		}

		//copy = new Node;
		insert(copy->data);
		copyNode(copy->leftchild);
		copyNode(copy->rightchild);
	}
template<typename bstdata>
void  BST<bstdata>:: freeNode(Node* root) //private helper of destructor
	{

		if(root==NULL)
			return;
		if(root!=NULL) //is this ok?????
			{
				freeNode(root->leftchild);
				freeNode(root->rightchild);
				delete root;
			}

	}

template<typename bstdata>
bool BST<bstdata>::searchNode(Node* root, bstdata data)const //private helper of search(recursive)
	{
		//cout << root->data << endl;
//		if(root->data == data)
//			return true;
//
//		if(root->data< data)
//			{
//				if(root->leftchild==NULL)
//					{
//					return false;}
//				else
//					{return searchNode(root->leftchild,data);}
//			}
//		else//root->data>data
//			{
//				if(root->rightchild==NULL)
//					{cout << "test";
//					return false;}
//				else
//					{return searchNode(root->rightchild,data);}
//			}
		if(root==NULL)
		{
			cout << "Null end" <<endl;
			return false;
		}
		else if(data == root -> data){
			cout << "this is good"<<endl;
			return true;
		}
		else if(data<root->data)
		{
			return searchNode(root->leftchild,data);
		}
		else if(data>root->data)
		{
			return searchNode(root->rightchild,data); //only changes if delete is actually used
		}
	}

template<typename bstdata>
bool BST<bstdata>::search(bstdata data) const//wrapper
	{
		return searchNode(root, data);
	}
template<typename bstdata>
bstdata BST<bstdata>::minimum(Node* root) const //private helper of minimum
	{
		if(root->leftchild==NULL)
			return root->data;
		else
			{minimum(root->leftchild);}
	}
template<typename bstdata>
bstdata BST<bstdata>::minimum() const //wrapper
	{
		return minimum(root);
	}

template<typename bstdata>
bstdata BST<bstdata>::maximum(Node* root) const //private helper of minimum
	{
		if(root->rightchild==NULL)
			return root->data;
		else
			{maximum(root->rightchild);}
	}
template<typename bstdata>
bstdata BST<bstdata>::maximum() const //wrapper
	{
		maximum(root);
	}

template<typename bstdata>
typename BST<bstdata>::Node* BST<bstdata>::deleteNode(Node* root, bstdata data)

	{

		if(root==NULL)
		{

			return root; //root is now null, we return null

		}
		else if(data<root->data)
			{
			root->leftchild=deleteNode(root->leftchild,data);
			}
		else if(data>root->data)
			{
			root->rightchild=deleteNode(root->rightchild,data); //only changes if delete is actually used
			}
		else if(root->data==data)
			{

				if(root->leftchild==NULL && root->rightchild==NULL)
					{	delete root;
						root=NULL;
						return root;
						//cout <<"hi";
					}
				else if(root->leftchild!=NULL && root->rightchild==NULL)//left, no right
					{
						Node* temp = root;
						root=root->leftchild;
						delete temp;
						return root;
					}
				else if(root->rightchild!=NULL && root->leftchild==NULL)
					{
						Node* temp = root;
						root=root->rightchild;
						delete temp;
						return root;



					}
				else
					{

							if(root->rightchild->leftchild!=NULL)
							{
								Node* leftCurrent;
								Node* leftCurrentPred;
								leftCurrentPred=root->rightchild;
								leftCurrent=(root->rightchild)->leftchild;
								while(leftCurrent->leftchild != nullptr)
									{
										leftCurrentPred=leftCurrent;
										leftCurrent=leftCurrent->leftchild;
									}
								root->data=leftCurrent->data;
								delete leftCurrent;
								leftCurrentPred->leftchild=nullptr;
							}
							else
							{
								Node* temp=root->rightchild;
								root->data=temp->data;
								root->rightchild=temp->rightchild;
								delete temp;
							}

					}
			}

			return root;
	}

template<typename bstdata>
void BST<bstdata>::remove(bstdata data)
	{
		deleteNode(root,data);
	}

template<typename bstdata>
void BST<bstdata>:: getSize(Node* root, int& size) const //private helper of getSize recursive
	{

			if(root==NULL)
				return;
			if(root!=NULL)
				{
					getSize(root->rightchild,size);
					size++;
					getSize(root->leftchild,size);
				}
	}
template<typename bstdata>
int BST<bstdata>:: getSize() const//wrapper
	{
		int size=0;
		getSize(root,size);
		return size;
	}
template<typename bstdata>
int BST<bstdata>::getHeight(Node* root) const//private helper of getHeight recursive
	{

		int height = 0;
		if(root==NULL)
			return -1;
		else
		{
			return max(getHeight(root->leftchild),getHeight(root->rightchild))+1;
		}

			return height;

	}

template<typename bstdata>
int BST<bstdata>::getHeight() const//private helper of getHeight recursive
	{
		return getHeight(root);



	}
template<typename bstdata>
bool BST<bstdata>:: isEmpty() const
	{
		if(root==NULL)
			return true;

		else
			return false;
	}

template<typename bstdata>
bstdata BST<bstdata>::getRoot() const
	{
		Song B1;
		if(root == NULL)
		{
			return B1;
		}
		return root->data;
	}

template<typename bstdata>
void BST<bstdata>::getResults(Node* root, string usersearch, int searchType, ostream& out, int& found)
	{
		if(root == NULL)
		{
			return;
		}
		Song S1 = root->data;
		string field;
		if(searchType == 1)
		{
			field = S1.getName();
		}
		else if(searchType == 2)
		{
			field = S1.getAlbum();
		}
		else if(searchType == 3)
		{
			field = S1.getYear();
		}
		else if(searchType == 4)
		{
			field == S1.getMonth();
		}
		else if(searchType == 5)
		{
			field = S1.getDay();
		}
		else if(searchType == 6)
		{
			field == S1.isOnChart();
		}
		else if(searchType == 7)
		{
			field = S1.getLength();
		}
		else if(searchType == 8)
		{
			field = S1.getViews();
		}
		getResults(root->leftchild, usersearch, searchType, out, found);
		if(usersearch == field)
		{
		out << root->data;
		found = 1;
		}
		getResults(root->rightchild, usersearch, searchType, out, found);
	}

template<typename bstdata>
void BST<bstdata>::results(string userSearch, int searchtype, ostream& out, int& found)
{
	getResults(root, userSearch, searchtype, out, found);
}

template<typename bstdata>
void BST<bstdata>::fullResults(string usersearch, ostream& out, Node* root, int& found)
{
	if(root == NULL)
	{
		return;
	}
	Song B1;
	B1 = root->data;
	fullResults(usersearch, out, root->leftchild, found);
	if(B1.getName() == usersearch)
	{
		out <<"Title: " << B1.getName() <<endl;
		out << "Album: " << B1.getAlbum() <<endl;
		out << "Publish Date: " <<B1.getDate() <<endl;
		out << "Reached Charts: " << B1.isOnChart() <<endl;
		out << "Length: " << B1.getLength() <<endl;
		out << "Youtube Views: " << B1.getViews() <<endl;
		out << "Lyrics: " << B1.getLyrics()<<endl <<endl;
		found = 1;
		return;
	}
	fullResults(usersearch, out, root->rightchild, found);
}

template<typename bstdata>
void BST<bstdata>::getFullResults(string search, ostream& out, int& found)
{
	fullResults(search, out, root, found);
}




#endif /* BST_H_ */
