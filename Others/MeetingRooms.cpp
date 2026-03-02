class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        // int n = A.size();
        int n = start.size();
        int m = end.size();
    // vector<int> start(n) , end(n);
    // for(int i=0;i<n;i++){
    //     start[i] = A[i][0];
    //     end[i] = A[i][1];
    // }
    
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    int rooms = 0;
    int maxRooms = 0;
    int i=0,j=0;
    
    while(i<n && j<n){
        if(start[i] < end[j]){
            rooms++;
            maxRooms = max(maxRooms,rooms);
            i++;
        }
        else{
            rooms--;
            j++;
        }
    }
    return maxRooms;
    }
};
