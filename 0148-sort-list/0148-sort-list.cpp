class Solution {
    void merge(vector<ListNode*> &arr, int low, int high){
        vector<ListNode*> temp;
        int mid = low+(high-low)/2;
        int i = low, j = mid+1;
        while(i<=mid && j<=high){
            if(arr[i]->val<=arr[j]->val)
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i<=mid)
            temp.push_back(arr[i++]);
        while(j<=high)
            temp.push_back(arr[j++]);
        for(int i=low, j =0; i<=high; i++, j++){
            arr[i] = temp[j];
        }
    }
    
    void mergeSort(vector<ListNode*> &arr, int low, int high){
        if(low>=high)
            return;
        int mid = low+(high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, high);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) 
            return head; // FIXED: Changed return; to return head;
        
        vector<ListNode*> arr;
        while(head){
            arr.push_back(head);
            head = head->next;
        } 
        
        mergeSort(arr, 0, arr.size()-1);
        
        for(int i=0; i<arr.size()-1; i++)
            arr[i]->next = arr[i+1];
            
        arr[arr.size()-1]->next = nullptr; // FIXED: Moved inside the function
        return arr[0];                     // FIXED: Moved inside the function
    }
};
