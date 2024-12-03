class Solution {
  public:
    int dataTypeSize(string str) {
        // your code here
        if (str == "Character") return sizeof('x');
        else if (str == "Integer") return sizeof(1);
        else if (str == "Double") return sizeof(1.1);
        else if (str == "Float") return sizeof(1.1F);
        else if (str == "Long") return sizeof(1L);
        
        return -1;
    }
};
