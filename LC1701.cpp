//1701. Average Waiting Time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        double ans=0;
        double start=customers[0][0];
        double wait=0;
        for(int i=0;i<customers.size();i++)
        {
            if(customers[i][0]<=start)
            {
                start+=customers[i][1];
                wait=wait+start-customers[i][0];
            }
            else{
                start=customers[i][0]+customers[i][1];
                wait=wait+customers[i][1];
            }
        }
        return (double)wait/customers.size();

    }
};