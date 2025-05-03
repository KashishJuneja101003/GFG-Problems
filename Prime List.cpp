
// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool checkPrime(int n){
        if(n < 2) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    
    int getClosestPrime(int num){
        // Get Prime Smaller
        int small = -1;
        for(int i=num; i>=2; i--){
            if(checkPrime(i)) {small = i; break;}
        }
        
        // Get Prime Larger
        int large = -1;
        for(int i=num; i<=10^4; i++){
            if(checkPrime(i)) {large = i; break;}
        }
        
        // Calculate smallPrimeDistance = num-small & largePrimeDistance = large-num
        int smallPrimeDistance = num-small;
        int largePrimeDistance = large-num;
        
        // If the distance between small-num & num-large is equal, return small
        if(smallPrimeDistance == largePrimeDistance) return small;

        // If smallPrimeDistance = -1, return largePrimeDistance;
        else if(smallPrimeDistance == -1) return large;
        
        // Else, return nearest prime
        else return (smallPrimeDistance < largePrimeDistance) ? small : large;
    }
    Node *primeList(Node *head) {
        // code here
        Node* temp = head;
        while(temp != nullptr){
            temp->val = getClosestPrime(temp->val);
            temp = temp->next;
        }
        
        return head;
    }
};
