#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high) {

        int i = low;
        int j = mid + 1;

        vector<int> temp(high-low+1,0);

        int k = 0;

        while(i<=mid and j<=high) {

                if(v[i] <= v[j])
                        temp[k++] = v[i++];
                else
                        temp[k++] = v[j++];
        }

        while(i<=mid) {
                temp[k++] = v[i++];
        }

        while(j<=high) {
                temp[k++] = v[j++];
        }

        k = 0;

        for(int i=low;i<=high;++i) {
                v[i] = temp[k++];
        }
}

void mergeSort(vector<int> &v, int low, int high) {

        if(low >= high)
                return;

        int mid = (low + high)/2;

        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);

        merge(v,low,mid,high);
}

int main() {

        int n;
        cin >> n;

        vector<int> v(n,0);

        for(int i=0;i<n;++i) {

                int num;
                cin >> num;

                v[i] = num;
        }

        cout << "\nBefore Sorting : " << endl;

        for(int i=0;i<n;++i) {
                cout << v[i] << " ";
        }
        cout << endl;

        mergeSort(v,0,n-1);

        cout << "\nAfter Sorting : " << endl;

        for(int i=0;i<n;++i) {
                cout << v[i] << " ";
        }
        cout << endl;

        return 0;
}
