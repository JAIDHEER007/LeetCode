// Memory Usage: 48ms
// Faster Than: 99.83%
// Memory Usage: 48.3 MB
// Less Than: 68.81%
// With NeedForSpeed Snippet; 

#include<iostream>
#include<vector>

using namespace std; 

typedef struct node{
    node* children[26]; 
    bool isEnd; 

    node(){
        for(int i = 0; i < 26; i++)
            children[i] = NULL; 
        isEnd = false; 
    }
} node; 

class WordDictionary{
    private:
        node* root; 
        int calls; 
        void searchRecursive(bool &result, string &word, node* n, int index){
            ++calls; 

            // Base Case
            if(result) return; // Found a match no need to search the trie again 

            if(index == (word.length())){ 
                result = n->isEnd; 
                return; 
            }

            // Check if the word[index] is '.'
            // Then check all the possibilities
            if(word[index] == '.'){
                for(int i = 0; i < 26; i++)
                    if(n->children[i]) searchRecursive(result, word, n->children[i], (index + 1)); 
            }else{
                // Check if word[index] is present in the node n
                // if yes proceed
                // else fuck off
                if(n->children[word[index] - 'a']) 
                    searchRecursive(result, word, (n->children[word[index] - 'a']), (index + 1)); 
            }
        }

    public:
        // Contructor
        WordDictionary(){
            root = new node; 
        }

        void addWord(string word){
            node* curr = root; 
            for(int i = 0; i < word.length(); i++){
                int index = word[i] - 'a'; 
                if(curr->children[index] == NULL) 
                    curr->children[index] = new node; 
                curr = curr->children[index]; 
            }
            curr->isEnd = true; 
        }

        bool search(string word){
            bool result = false; 
            calls = 0; 
            searchRecursive(result, word, root, 0); 
            // cout<<"Calls made: "<<calls<<endl; 
            return result; 
        }

}; 

int main(){
    WordDictionary* obj = new WordDictionary(); 

    obj->addWord("bad"); 
    obj->addWord("dad"); 
    obj->addWord("mad"); 

    cout<<boolalpha<<obj->search("pad")<<endl; 
    cout<<boolalpha<<obj->search("bad")<<endl; 
    cout<<boolalpha<<obj->search(".ad")<<endl; 
    cout<<boolalpha<<obj->search("b..")<<endl; 
    
    return 0; 
}