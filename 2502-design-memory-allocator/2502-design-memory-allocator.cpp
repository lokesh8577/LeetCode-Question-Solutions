class Allocator {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int* arr;
    int FreeSpace;
    int length;
    Allocator(int n) {
        this->FreeSpace = n;
        this->length = n;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = -1;
        }
    }

    int allocate(int size, int mID) {
        if (FreeSpace < size) {
            return -1;
        }

        int first_index = -1;
        int last_index = -1;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < length; i++) {
            if (arr[i] == -1) {
                cnt++;
                if (first_index == -1) {
                    first_index = i;
                    last_index = i;
                } else {
                    last_index = i;
                }

                if (cnt == size) {
                    flag = true;
                    mp[mID].push_back({first_index, last_index});
                    FreeSpace -= last_index - first_index + 1;
                    for (int i = first_index; i <= last_index; i++) {
                        arr[i] = mID;
                    }
                }
            } else {
                cnt = 0;
                first_index = -1;
                last_index = -1;
            }

            if (flag) {
                return first_index;
            }
        }

        return -1;
    }

    int freeMemory(int mID) {
        auto it = mp.find(mID);

        if (it != mp.end()) {
            int FreeMemory = 0;

            for (auto i : mp[mID]) {
                FreeMemory += i.second - i.first + 1;
                FreeSpace += i.second - i.first + 1;

                for (int j = i.first; j <= i.second; j++) {
                    arr[j] = -1;
                }
            }

            mp.erase(mID);

            return FreeMemory;
        }

        return 0;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */