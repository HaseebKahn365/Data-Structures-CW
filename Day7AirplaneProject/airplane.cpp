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
    }

private:
    Airplane *getRoot()
    {
        return root;
    }

    void inOrder(Airplane *n)
    {
        if (n == NULL)
        {
            return;
        }
        inOrder(n->left);
        cout << "[ " << n->arr_time << " ]"
             << "\t";
        inOrder(n->right);
    }
};

int main()
{
    AirplaneTree *airTree = new AirplaneTree();
    airTree->insert(new Airplane(49), 3);
    airTree->insert(new Airplane(46), 1);
    airTree->insert(new Airplane(79), 1);
    airTree->insert(new Airplane(43), 1);
    airTree->insert(new Airplane(64), 1);
    airTree->insert(new Airplane(83), 1);
    airTree->insert(new Airplane(84), 4);

    airTree->displayAllPlanes();

    return 0;
}