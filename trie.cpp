
#include<iostream>
using namespace std;
#define ALPHABET_SIZE 26

class TrieNode{

        public:
        bool isEndOfWord;
        TrieNode * children[ALPHABET_SIZE];

        TrieNode(){
            isEndOfWord = false;

            for (int i = 0 ; i < ALPHABET_SIZE ; i++){
                    this->children[i] = nullptr;
            }
        }

        void markAsLeaf() {
            this->isEndOfWord = true;
        }

        void unMarkAsLeaf(){
            this->isEndOfWord = false;
        }

};
class Trie {
        private :
        TrieNode * root;

        public:

        Trie(){
            this->root = new TrieNode();
        }

        int getIndexOfChar(char t){
                return t - 'a';
        }

        void insertNode(string key, int value){

        }

        void insertNode(string key){

            if (key.empty()){
                return;
            }
            cout << "Key To Insert : " +  key << endl;

            transform(key.begin(),key.end(),key.begin(),::tolower);
            TrieNode * current = root;

            int index = 0;

            for (int level = 0 ; level < key.length();level++){
                index = getIndexOfChar(key[level]);

                if (current->children[index] == nullptr){
                    current->children[index] = new TrieNode();
                    cout << ": insert at : " << index;
                    
                }
                cout<<endl;
               current = current->children[index];
            }
             current->markAsLeaf();
        }

        bool searchKey(string key){

            if (key.empty()){
                return false;
            }

            transform(key.begin(), key.end(), key.begin(), ::tolower); 

            int index = 0;

            TrieNode * current = root;

            for (int i = 0 ; i < key.length();i++){
                index = getIndexOfChar(key[i]);

                if (current->children[index] == nullptr){
                        return false;
                }
                    current = current->children[index];
            }

            if (current != nullptr && current->isEndOfWord == true){
                return true;
            }
            return false;
        }

        bool hasNoChildren(TrieNode * node) {
            bool hasChild = true;

            for (int i = 0 ; i < ALPHABET_SIZE; i++){

                if (node->children[i] != nullptr){
                    return false;
                }
            }

            return hasChild;
        }

        bool deletionHelper(string key,TrieNode * current,int length, int level ){

                bool isDeletedSelf = false;

                if(length == 0 || key.empty()){
                    cout << "Empty key";    
                    return false;
                }

                if (length == level){

                    if (hasNoChildren(current)){

                        delete current;
                        current = nullptr;
                        isDeletedSelf = true;
                    }
                    else {
                        current->unMarkAsLeaf();
                        isDeletedSelf = false;
                    }

                }
                else {
                        int indexOfChild =  getIndexOfChar(key[level]);
                        TrieNode * childNode = current->children[indexOfChild];
                        bool childDeleted = deletionHelper(key,childNode,key.length(),level + 1);

                        if (childDeleted){
                                current->children[indexOfChild] = nullptr;

                                if (current->isEndOfWord) {
                                    isDeletedSelf = false;
                                }
                                else if (!hasNoChildren(current)){
                                    isDeletedSelf = false;
                                }
                                else {
                                    current = nullptr;
                                    isDeletedSelf = true;
                                }
                        }
                        else {
                            isDeletedSelf = false;
                        }


                }
            return isDeletedSelf;
        }

        void deleteNode(string key){
                 if ((root == NULL) || (key.empty())){
                     cout << "Null key";
                     return;
                 }
                 deletionHelper(key,root,key.length(),0);
        }

         
        int calculateRootChild(TrieNode * current){
        int totalChildWords = 0;

        if (current == nullptr){
            return totalChildWords;
         }

         if (current->isEndWord){
            totalChildWords += 1;
        }

        if (hasNoChildren(current)){
            return totalChildWords;
        }

        for (int i  = 0 ; i < ALPHABET_SIZE ; i++){
                 if (current->children[i] != nullptr) {
                int totalChild = calculateRootChild(current->children[i]);
                totalChildWords += totalChild;
         }
        }
        return totalChildWords;
    }

    int totalWords(TrieNode * root){
        int result = calculateRootChild(root);
        return result;
    }

};



int main(){

  Trie * t = new Trie();
  string keys[9] = {"the", "a", "there", "answer", "any", "by", "bye", "their","abc"};
  cout << "Keys to insert:\n";
  for(int i = 0; i < 9; i++){
    cout << keys[i] << ", ";
  }
  cout << endl;

  // Construct trie       
  for (int i = 0; i < 9 ; i++)
  {
    t->insertNode(keys[i]);
    cout << "\"" << keys[i] << "\"" << "Inserted." << endl;
  }

  cout<< "Searching:====================." << endl;
 // cout << "Searching : " << t->searchKey("theree") << endl;

  cout << "Searching : abc" << t->searchKey("abc")<<endl;  
  t->deleteNode("abc");
    cout << "Deleted key \"abc\"" << endl;
  if(t->searchKey("abc") == true)
    cout << "not deleted";
  else
    cout << "deleted";
  return 0;
}