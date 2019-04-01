#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
void merge(vector<int> out, vector<int> left, vector<int> mid, vector<int> right)
{
    vector<int> temp(out.size());
    int total = 0;
    int lft = 0;
    int md = 0;
    int rght = 0;
    while ((lft < left.size()) && (md < mid.size()) && (rght < right.size()))
    {
        if ((left[lft] < mid[md]) && (left[lft] < right[rght]))
        {
            temp[total++] = left[lft++];
        }
        else if ((mid[md] < left[lft]) && (mid[md] < right[rght]))
        {
            temp[total++] = mid[md++];
        }
        else
        {
            temp[total++] = right[rght++];
        }
    }
    while ((lft < left.size()) && (md < mid.size()))
    {
        if (left[lft] < mid[md])
        {
            temp[total++] = left[lft++];
        }
        else
        {
            temp[total++] = mid[md++];
        }
    }
    while ((lft < left.size()) && (rght < right.size()))
    {
        if (left[lft] < right[rght])
        {
            temp[total++] = left[lft++];
        }
        else
        {
            temp[total++] = right[rght++];
        }
    }
    while ((md < mid.size()) && (rght < right.size()))
    {
        if (mid[md] < right[rght])
        {
            temp[total++] = mid[md++];
        }
        else
        {
            temp[total++] = right[rght++];
        }
    }
    while (lft < left.size())
    {
        temp[total++] = left[lft++];
    }
    while (md < mid.size())
    {
        temp[total++] = mid[md++];
    }
    while (rght < right.size())
    {
        temp[total++] = right[rght++];
    }
    out.clear();
    out = temp;
}
vector<int> merge_sort(vector<int> &vec)
{
    //some initial conditions
    if (vec.size() == 1)
    {
        return vec;
    }
    else if (vec.size() == 2)
    {
        //we want to make two arrays
        vector<int> v1;
        v1[0] = vec[0];
        vector<int> v2;
        v2[0] = vec[1];
        vector<int> mid(0);
        merge(vec, v1, mid, v2);
        return vec;
    }
    //now we split the vector up into three parts
    int vecsize = vec.size();
    int leftsize;
    int midsize;
    int rightsize;

    if (vecsize > 2)
    {
        if (vecsize % 3 == 0)
        {
            leftsize = vecsize / 3;
            midsize = vecsize / 3;
            rightsize = vecsize / 3;
        }
        else if (vecsize % 3 == 1)
        {
            leftsize = (vecsize / 3) + 1;
            midsize = vecsize / 3;
            rightsize = vecsize / 3;
        }
        else
        { //if vecsize % 3 == 2
            leftsize = (vecsize / 3) + 1;
            midsize = vecsize / 3;
            rightsize = (vecsize / 3) + 1;
        }
    }
    vector<int> left;
    vector<int> mid;
    vector<int> right;
    for (int i = 0; i < leftsize; i++)
    {
        cout << i << endl;
        cout << vec[i] << endl;
        left.push_back(vec[i]);
    }
    for (int i = 0; i < (midsize); i++)
    {
        mid.push_back(vec[i + leftsize]);
    }
    for (int i = 0; i < rightsize; i++)
    {
        cout << i << endl;
        right.push_back(vec[i + (midsize + leftsize)]);
    }
    merge_sort(left);
    merge_sort(mid);
    merge_sort(right);

    merge(vec, left, mid, right);

    return vec;
}
int main(void)
{
    vector<int> test = {13, -2, 110, 34, 17, 99, 100};
    cout << "Hi" << endl;
    vector<int> out;
    out = merge_sort(test);
    cout << "output vector contents: " << endl;
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
}