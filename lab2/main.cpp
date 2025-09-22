
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono> // For timing

// --- Linked List Implementation ---

// Node for the linked list
struct Node {
    std::string word;
    Node* next;

    Node(std::string w) : word(w), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const std::string& word) {
        // Insert at the beginning for O(1) insertion time
        Node* newNode = new Node(word);
        newNode->next = head;
        head = newNode;
    }

    bool search(const std::string& word) {
        Node* current = head;
        while (current != nullptr) {
            if (current->word == word) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

// --- Hash Table Implementation ---

class HashTable {
private:
    std::vector<LinkedList> table;
    int table_size;

    // Hash function: sum of ASCII values % table_size
    int hash_function(const std::string& key) {
        long long sum = 0; // Use long long to prevent overflow for long strings
        for (char ch : key) {
            sum += ch;
        }
        return sum % table_size;
    }

public:
    HashTable(int size) : table_size(size) {
        table.resize(table_size);
    }

    void insert(const std::string& word) {
        int index = hash_function(word);
        table[index].insert(word);
    }

    bool search(const std::string& word) {
        int index = hash_function(word);
        return table[index].search(word);
    }
};

// --- Helper Functions ---

// Function to clean a word by removing trailing punctuation and converting to lowercase
std::string clean_word(std::string word) {
    // Remove trailing punctuation
    while (!word.empty() && (ispunct(word.back()))) {
        word.pop_back();
    }
    // Convert to lowercase
    for (char &c : word) {
        c = tolower(c);
    }
    return word;
}

// --- Main Program Logic ---

int main() {
    int choice;
    std::cout << "Choose a data structure to use:" << std::endl;
    std::cout << "[1] Hash Table (mod 20)" << std::endl;
    std::cout << "[2] Hash Table (mod 450)" << std::endl;
    std::cout << "[3] Linked List" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 3) {
        std::cout << "Invalid choice. Exiting." << std::endl;
        return 1;
    }

    // --- Load Dictionary ---
    std::ifstream dict_file("dictionary.txt");
    if (!dict_file) {
        std::cerr << "Error: Could not open dictionary.txt" << std::endl;
        return 1;
    }

    HashTable ht_mod20(20);
    HashTable ht_mod450(450);
    LinkedList ll;
    std::string word;

    auto start = std::chrono::high_resolution_clock::now();

    while (dict_file >> word) {
        std::string cleaned = clean_word(word);
        if (!cleaned.empty()) {
            switch (choice) {
                case 1: ht_mod20.insert(cleaned); break;
                case 2: ht_mod450.insert(cleaned); break;
                case 3: ll.insert(cleaned); break;
            }
        }
    }
    dict_file.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> load_time = end - start;
    std::cout << "\nDictionary loaded in " << load_time.count() << " ms." << std::endl;

    // --- Sentence Validation ---
    std::cout << "\nEnter a sentence to check: ";
    std::cin.ignore(); // Consume the newline character left by std::cin >> choice
    std::string sentence;
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::vector<std::string> not_found_words;
    bool all_found = true;

    start = std::chrono::high_resolution_clock::now();

    while (ss >> word) {
        std::string cleaned = clean_word(word);
        if (cleaned.empty()) continue;

        bool found = false;
        switch (choice) {
            case 1: found = ht_mod20.search(cleaned); break;
            case 2: found = ht_mod450.search(cleaned); break;
            case 3: found = ll.search(cleaned); break;
        }

        if (!found) {
            all_found = false;
            not_found_words.push_back(cleaned);
        }
    }

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> search_time = end - start;

    // --- Print Results ---
    if (all_found) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
        std::cout << "Words not found: ";
        for (size_t i = 0; i < not_found_words.size(); ++i) {
            std::cout << not_found_words[i] << (i == not_found_words.size() - 1 ? "" : ", ");
        }
        std::cout << std::endl;
    }
    
    std::cout << "Sentence checked in " << search_time.count() << " ms." << std::endl;

    return 0;
}
