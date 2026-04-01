// same for painter's partition and split array- largest sum ;
#include<bits/stdc++.h>
using namespace std ;
 
int no_of_student(vector<int> &arr , int mid){
    int std=0 , pages=0;
    for(int i=0 ; i<arr.size() ; i++){
        pages+=arr[i] ;
        if(pages==mid) {
            std++ ;
            pages=0 ;
        }
        else if(pages>mid){
            std++ ;
            pages=arr[i] ;
        }
    }
    if(pages) std++ ;
    return std ;
}

int min_book_allocate(vector<int> &arr , int student){
    if(student>arr.size()) return -1 ;
    int low=*max_element(arr.begin() , arr.end()) ;
    int high=0 ;
    for(int i=0 ; i<arr.size() ; i++) high=high+arr[i] ;
    while(low<=high){
        int mid=(low+high)/2 ;
        int std=no_of_student(arr , mid) ;
        if(std<=student){
            high=mid-1 ;
        }
        else low=mid+1 ;
    }
    return low ;
}

int main(){
vector<int> arr={25 , 46 , 28 , 49 , 24} ;
int student=4 ;
cout<<min_book_allocate(arr , student) ;
return 0 ;
}