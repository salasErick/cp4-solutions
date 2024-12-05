#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

/* My first solution gave me TLE. It's complexity was
 * O(2*n^2) = O(n^2) since it was traversing the entire list for every element.
 *
 * To fix it, I thought about doing the same but without the nested loop
 * We do so by determining that in constant time.
 *
 * To be a pivot, the selected pivot needs to divide the array into three parts:
 * the left sub-array needs its elements to be less than the pivot and the 
 * right sub-array needs its elements to be greater than the pivot.
 *
 * If you notice, you can create a list of the minimum number in each position 
 * of the array as well as a list of the maximum number on each position so 
 * that you can compare the element in its respective position with the one 
 * that is in the original list. That's the approach we take here and its 
 * complexity is O(n).
 */
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> numbers(n);
    vector<int> smaller(n), greater(n);

    int num = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // minimum
    smaller[0] = numbers[0];
    for(int i = 1; i < n; i++)
        smaller[i] = max(smaller[i-1], numbers[i]);
   
    // maximum
    greater[n-1] = numbers[n-1];
    for(int i = n-2; i >= 0; i--)
        greater[i] = min(greater[i+1], numbers[i]);
    
    if(numbers[0] <= greater[1])
        num++;
    if(numbers[n-1] >= smaller[n-2])
        num++;
    
    for(int i = 1; i < n-1; i++)
        if(numbers[i] <= greater[i+1] && numbers[i] >= smaller[i-1])
                num++;

    cout << num;
    return 0;
    
}
