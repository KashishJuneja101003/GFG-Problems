class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_map<int, list<int>::iterator> pageNumber_index;
        list<int> lruCache;
        int countPageFaults = 0;
        
        for(int i=0; i<N; i++){
            int page = pages[i];
            
            // Check if a page already exists
            // If yes, update index
            // If no, increment countPageFaults and remove element with smallest index
            if(pageNumber_index.find(page) != pageNumber_index.end()){
                lruCache.erase(pageNumber_index[page]);
                lruCache.push_front(page);
                pageNumber_index[page] = lruCache.begin();
            } else{
                countPageFaults++;
                
                if(pageNumber_index.size() >= C){
                    // Finding element with smallest index
                    int lruPage = lruCache.back();
                    
                    // Erase the element with smallest index
                    lruCache.pop_back();
                    pageNumber_index.erase(lruPage);
                }
                
                // Insert new page
                lruCache.push_front(page);
                pageNumber_index[page] = lruCache.begin();
            }
        }
        
        return countPageFaults;
    }
};
