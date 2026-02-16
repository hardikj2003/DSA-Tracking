#include <iostream>
using namespace std;

const int MAX = 100;
void printArray(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* ---------- Q1: Insert at End ---------- */
void insertAtEnd(int arr[], int &n, int x)
{
    if (n >= MAX)
    {
        cout << "Array overflow\n";
        return;
    }
    arr[n++] = x;
}

/* ---------- Q5: Insert at Index ---------- */
void insertAtIndex(int arr[], int &n, int pos, int x)
{
    if (n >= MAX || pos < 0 || pos > n)
    {
        cout << "Invalid operation";
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = x;
    n++;
}

/* ---------- Q6: Delete by Index ---------- */
void deleteByIndex(int arr[], int &n, int pos)
{
    if (n == 0 || pos < 0 || pos >= n)
    {
        cout << "Invalid operation\n";
        return;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

/* ---------- Q9: Delete All Occurrences ---------- */
void deleteAllOccurrences(int arr[], int &n, int x)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != x)
            arr[k++] = arr[i];
    }
    n = k;
}

/* ---------- Q10: Insert in Sorted Array ---------- */
void insertInSortedArray(int arr[], int &n, int x)
{
    if (n >= MAX)
    {
        cout << "Array overflow\n";
        return;
    }
    int i = n - 1;
    while (i >= 0 && arr[i] > x)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = x;
    n++;
}

/* ---------- Q12: Remove Duplicates (Unsorted) ---------- */
void removeDuplicates(int arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
                j--;
            }
        }
    }
}

/* ---------- Helper for Q14 ---------- */
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* ---------- Q14: Left Rotate by K ---------- */
void leftRotateByK(int arr[], int n, int k)
{
    if (n == 0)
        return;
    k = k % n;
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
}

/* ---------- MAIN ---------- */
int main()
{
    int arr[MAX];
    int n = 0;
    int choice;

    do
    {
        cout << "\n---- ARRAY CRUD MENU ----\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at index\n";
        cout << "3. Delete by index\n";
        cout << "4. Delete all occurrences\n";
        cout << "5. Insert in sorted array\n";
        cout << "6. Remove duplicates\n";
        cout << "7. Left rotate by K\n";
        cout << "8. Print array\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int x, pos, k;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            insertAtEnd(arr, n, x);
            break;

        case 2:
            cout << "Enter index and value: ";
            cin >> pos >> x;
            insertAtIndex(arr, n, pos, x);
            break;

        case 3:
            cout << "Enter index: ";
            cin >> pos;
            deleteByIndex(arr, n, pos);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> x;
            deleteAllOccurrences(arr, n, x);
            break;

        case 5:
            cout << "Enter value to insert (array must be sorted): ";
            cin >> x;
            insertInSortedArray(arr, n, x);
            break;

        case 6:
            removeDuplicates(arr, n);
            break;

        case 7:
            cout << "Enter K: ";
            cin >> k;
            leftRotateByK(arr, n, k);
            break;

        case 8:
            printArray(arr, n);
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}
