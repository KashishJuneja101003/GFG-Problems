// TC: O(n) SC: O(1)
string printSequence(string S) {
    vector<string> vec = {
        "2", "22", "222", "3", "33", 
        "333", "4", "44", "444", "5",
        "55", "555", "6", "66", "666",
        "7", "77", "777", "7777", "8",
        "88", "888", "9", "99", "999", "9999"
    };
    
    string output = "";
    for(char& c:S){
        if(c == ' ') output += '0';
        else{
            int idx = c - 'A';
            output += vec[idx];
        }
    }
    
    return output;
}
