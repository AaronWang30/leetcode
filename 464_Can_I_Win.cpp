class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if (sum < desiredTotal) return false;
        string state(maxChoosableInteger+1,'0');
        unordered_map<string, bool> stateTable;
        return memSearch(state, stateTable, desiredTotal);
    }
    
    bool memSearch(string &state, unordered_map<string, bool>& stateTable, int dT) {
        auto it = stateTable.find(state);
        if (it != stateTable.end()) {
            return it->second;
        }
        // DFS
        for (int i = state.size()-1; i >= 1; --i) {
            if (state[i] == '0') {
                if (i >= dT) {
                    stateTable.emplace(state, true); return true;
                }
                string nextState(state); nextState[i] = '1';
                bool isOpponentWin = memSearch(nextState, stateTable, dT-i);
                stateTable.emplace(nextState, isOpponentWin); 
                if (!isOpponentWin) return true;
            }
        }
        return false;
    }
};  