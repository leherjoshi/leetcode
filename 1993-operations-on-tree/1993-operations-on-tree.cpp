class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockedBy; // -1 if unlocked, else user id who locked it

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();
        children.resize(n);
        lockedBy.assign(n, -1);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (lockedBy[num] != -1) return false;
        lockedBy[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockedBy[num] != user) return false;
        lockedBy[num] = -1;
        return true;
    }

    bool upgrade(int num, int user) {
        // 1. num must currently be unlocked
        if (lockedBy[num] != -1) return false;

        // 2. at least one locked descendant must exist
        if (!hasLockedDescendant(num)) return false;

        // 3. no locked ancestor
        int p = parent[num];
        while (p != -1) {
            if (lockedBy[p] != -1) return false;
            p = parent[p];
        }

        // unlock all locked descendants, then lock num
        unlockDescendants(num);
        lockedBy[num] = user;
        return true;
    }

private:
    bool hasLockedDescendant(int num) {
        for (int c : children[num]) {
            if (lockedBy[c] != -1) return true;
            if (hasLockedDescendant(c)) return true;
        }
        return false;
    }

    void unlockDescendants(int num) {
        for (int c : children[num]) {
            lockedBy[c] = -1;
            unlockDescendants(c);
        }
    }
};