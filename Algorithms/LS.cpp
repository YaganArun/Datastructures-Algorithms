// Linear Search 
#include <iostream>
using namespace std;

// Returns location of the element if present else return -1
int LinearSearch(int arr[], int n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            return (i + 1);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int search_ele;
    cin >> search_ele;
    int res = LinearSearch(arr, sizeof(arr) / sizeof(arr[0]), search_ele);
    if (res != -1)
        cout << res << endl;
    else
        cout << "NA" << endl;
    return 0;
}
