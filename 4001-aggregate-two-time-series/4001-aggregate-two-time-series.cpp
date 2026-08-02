class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        int n1 = series1.size();
        int n2 = series2.size();

        vector<vector<int>> ans;

        int i = 0, j = 0;

        while (i < n1 || j < n2) {

            if (i == n1) {
                ans.push_back({series2[j][0], series2[j][1]});
                j++;
            }
            else if (j == n2) {
                ans.push_back({series1[i][0], series1[i][1]});
                i++;
            }
            else {

                int t1 = series1[i][0];
                int t2 = series2[j][0];

                if (t1 == t2) {
                    ans.push_back({t1, series1[i][1] + series2[j][1]});
                    i++;
                    j++;
                }
                else if (t1 < t2) {

                    // CHANGED: search in series2
                    int k = j;
                    while (k < n2 && series2[k][0] < t1)
                        k++;

                    int val2 = (k < n2) ? series2[k][1] : 0;

                    ans.push_back({t1, series1[i][1] + val2});
                    i++;
                }
                else { // t2 < t1

                    // CHANGED: search in series1
                    int k = i;
                    while (k < n1 && series1[k][0] < t2)
                        k++;

                    int val1 = (k < n1) ? series1[k][1] : 0;

                    ans.push_back({t2, val1 + series2[j][1]});
                    j++;
                }
            }
        }

        return ans;
    }
};