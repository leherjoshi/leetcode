class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < a.size(); i++) {

            if (!st.empty() &&
                ((st.top() > 0 && a[i] > 0) ||
                 (st.top() < 0 && a[i] < 0))) {

                st.push(a[i]);
            }
            else {

                bool destroyed = false;

                while (!st.empty() && st.top() > 0 && a[i] < 0) {

                    if (st.top() < -a[i]) {
                        st.pop();
                    }
                    else if (st.top() == -a[i]) {
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed)
                    st.push(a[i]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};