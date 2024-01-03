 void searchTestString(string str) {
        int index;
        index = hashFunction(str);
        int originalIndex = index;

        do {
            if (hashArr[index] == str) {
                cout << "Found string: " << str << endl;
                return;
            }
            index = (index + 1) % 11;
        } while (index != originalIndex && hashArr[index] != "-1");

        cout << "String not found: " << str << endl;
    }