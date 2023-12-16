#include <iostream>
using namespace std;

class Airplane
{
public:
    int arr_time;
    Airplane *left;
    Airplane *right;
    int nAirplanes;

    Airplane(int arr_time)
    {
        this->arr_time = arr_time;
        left = NULL;
        right = NULL;
        int nAirplanes = 1; // number of airplanes in the subtree;
    }
};

class AirplaneTree
{
    Airplane *root;

public:
    int totalPlanes;
    Airplane *rankArray[100]; // containing all the planes upto the rank
    AirplaneTree()
    {
        totalPlanes = 0;
        root = NULL;
    }

    // TODO: INSERTING THE PLANE WITH THE KEY

    void insert(Airplane *n, int k)
    {
        if (root == NULL)
        {
            root = n;
            cout << "new made the root" << endl;
            return;
        }
        Airplane *curr = root;
        while (curr != NULL)
        {
            if (curr->arr_time == n->arr_time)
            {
                cout << "AirPlanes can't have same arr_time" << endl;
                totalPlanes++;
                return;
            }
            if (n->arr_time > curr->arr_time)
            {
                if (curr->right == NULL && abs(curr->arr_time - n->arr_time) >= k)
                {
                    curr->right = n;
                    totalPlanes++;
                    cout << "inserted to the right, Total = " << totalPlanes << endl;
                    return;
                }
                else
                    curr = curr->right;
            }
            else
            {
                if (curr->left == NULL && abs(curr->arr_time - n->arr_time) >= k)
                {
                    curr->left = n;
                    totalPlanes++;
                    cout << "inserted to the left, Total = " << totalPlanes << endl;
                    return;
                }
                else
                    curr = curr->left;
            }

            if (curr == NULL)
                cout << "Dangerously close not allowed to land" << endl;
        }
    }

    // TODO: displaying the airplanes:
    void displayAllPlanes()
    {
        inOrder(getRoot());
        cout << endl;
    }

    Airplane *getRoot()
    {
        return root;
    }

    // TODO: Deleting the node with key.
    void deleteAirplane(int arrTime)
    {

        // searching for plane with arr_time
        Airplane *parent, *curr;
        parent = curr = root;
        bool isLeft;

        while (curr != NULL && curr->arr_time != arrTime)
        {
            parent = curr;
            if (curr->arr_time > arrTime)
            {
                curr = curr->left;
                isLeft = true;
            }
            else if (curr->arr_time < arrTime)
            {
                curr = curr->right;
                isLeft = false;
            }
        }
        if (curr == NULL)
        {
            cout << "No key found as: " << arrTime;
            return;
        }

        // check if leaf node:
        if (curr->right == NULL && curr->left == NULL)
        {
            if (isLeft)
            {
                parent->left = NULL;
                cout << "deleting the left node of parent known to be leaf" << endl;
                delete curr;
            }
            else
            {
                parent->right = NULL;
                cout << "deleting the right node of parent known to be leaf" << endl;
                delete curr;
            }
            return;
        }

        // Airplane* delNode = curr; //not needed

        // check if node with one child on the left;
        if (curr->left != NULL && curr->right == NULL)
        {
            parent->left = curr->left;
            curr->left = NULL;
            delete curr;
            cout << "Deleted node with one right child null" << endl;
            return;
        }
        // check if node with one child on the right
        if (curr->right != NULL && curr->left == NULL)
        {
            parent->right = curr->right;
            curr->right = NULL;
            delete curr;
            cout << "Deleted node with one left child null" << endl;
            return;
        }

        // deleting node with both child ! null; on right side
        if (!isLeft)
        {
            parent->right = findSuccessor(curr);
            cout << parent->right->arr_time << endl;
            parent->right->left = curr->left;
            cout << parent->left->arr_time << endl;
            delete curr;
            return;
        }
        else
        {
            parent->left = findSuccessor(curr);
            cout<<parent->left->arr_time<<endl;
            parent->left->left = curr->left;
            cout<<parent->left->left->arr_time<<endl;
            delete curr;
            return;

        }
        //
    }

private:
    void inOrder(Airplane *n)
    {
        if (n == NULL)
        {
            return;
        }
        inOrder(n->left);
        cout << "[ " << n->arr_time << " ]"
             << "\t\t";
        inOrder(n->right);
    }

    Airplane *findSuccessor(Airplane *A)
    {
        A = A->right;
        while (A->left != NULL)
        {
            A = A->left;
        }
        return A;
    }
};

int main()
{
    AirplaneTree *airTree = new AirplaneTree();
    airTree->insert(new Airplane(49), 3);
    airTree->insert(new Airplane(46), 1);
    airTree->insert(new Airplane(47), 0);
    airTree->insert(new Airplane(79), 1);
    airTree->insert(new Airplane(43), 1);
    airTree->insert(new Airplane(64), 1);
    airTree->insert(new Airplane(83), 1);
    airTree->insert(new Airplane(84), 4);

    airTree->displayAllPlanes();
    // airTree->deleteAirplane(43);
    // airTree->displayAllPlanes(); //test passed;
    // airTree->deleteAirplane(46);
    // airTree->displayAllPlanes(); //test passed;
    // airTree->deleteAirplane(83);
    // airTree->displayAllPlanes(); //test passed
    // airTree->deleteAirplane(79);
    // airTree->displayAllPlanes(); // test passed

    airTree->deleteAirplane(49);
    airTree->displayAllPlanes(); 
    

    return 0;
}