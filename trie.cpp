
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

        bool deleteNode(string key){
            return true;
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
  cout << "Searching : " << t->searchKey("theree") << endl;

  return 0;
}