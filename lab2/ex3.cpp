// vivliothikes
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// ---- Adjacency Matrix ----
void add_edge(int pinakas[][9], int i, int j, int h) { // eisagwgi apostasewn ston pinaka (kai stis 2 kateuthinseis)
    pinakas[i][j] = h;
    pinakas[j][i] = h;
}

void print_array(int pinakas[][9], int v, const vector<string>& countries) { // ektipwsei tou pinaka
    cout << setw(12) << " ";
    for (int i = 0; i < v; i++) cout << setw(10) << countries[i];
    cout << "\n";
    for (int i = 0; i < v; i++) {
        cout << setw(12) << countries[i];
        for (int j = 0; j < v; j++) cout << setw(10) << pinakas[i][j];
        cout << "\n";
    }
}

// ---- Adjacency List ----
void addedge(vector<pair<int,int>> graph[], int i, int j, int w) {
    graph[i].push_back({j, w});
    graph[j].push_back({i, w});
}

void printgraph(vector<pair<int,int>> graph[], int v, const vector<string>& countries) {
    for (int i = 0; i < v; i++) {
        cout << "The country " << countries[i] << " has direct flights to:\n";
        cout<<"----------------------------------------\n";
        for (auto &p : graph[i]) {
            cout << "  " << countries[p.first] << " with a distance of: "
                 << p.second << " rectangles\n";
        }
        cout << "\n";
    }
}

// ---- kiria sinartisi ----
int main() {
    const int v = 9;
    // Seira komvwn (indices):
    // 0: UK, 1: Germany, 2: Poland, 3: Austria, 4: France, 5: Spain, 6: Italy, 7: Greece, 8: Cyprus
    vector<string> countries = {"UK", "Germany", "Poland", "Austria", "France", "Spain", "Italy", "Greece", "Cyprus"};

    int pinakas[v][v] = {0};
    vector<pair<int,int>> graph[v];

    // ---- Edges me ta NEO dedomena ----
    // UK
    add_edge(pinakas, 0, 1, 3); // UK - Germany
    add_edge(pinakas, 0, 4, 3); // UK - France

    // Germany
    add_edge(pinakas, 1, 4, 5); // Germany - France
    add_edge(pinakas, 1, 2, 3); // Germany - Poland
    add_edge(pinakas, 1, 3, 4); // Germany - Austria

    // Poland
    add_edge(pinakas, 2, 3, 4); // Poland - Austria

    // France
    add_edge(pinakas, 4, 5, 4); // France - Spain
    add_edge(pinakas, 4, 6, 6); // France - Italy

    // Spain
    add_edge(pinakas, 5, 6, 5);  // Spain - Italy
    add_edge(pinakas, 5, 8, 11); // Spain - Cyprus

    // Austria
    add_edge(pinakas, 3, 6, 3); // Austria - Italy
    add_edge(pinakas, 3, 7, 6); // Austria - Greece

    // Italy / Greece / Cyprus
    add_edge(pinakas, 6, 7, 4); // Italy - Greece
    add_edge(pinakas, 7, 8, 4); // Greece - Cyprus

    // ---- Ektypwseis ----
    cout << "Adjacency Matrix\n";
    cout << string(90, '-') << "\n\n";
    print_array(pinakas, v, countries);

    // Ftiaxnoume kai tis listes me tis idies akmes
    addedge(graph, 0, 1, 3);
    addedge(graph, 0, 4, 3);
    addedge(graph, 1, 4, 5);
    addedge(graph, 1, 2, 3);
    addedge(graph, 1, 3, 4);
    addedge(graph, 2, 3, 4);
    addedge(graph, 4, 5, 4);
    addedge(graph, 4, 6, 6);
    addedge(graph, 5, 6, 5);
    addedge(graph, 5, 8, 11);
    addedge(graph, 3, 6, 3);
    addedge(graph, 3, 7, 6);
    addedge(graph, 6, 7, 4);
    addedge(graph, 7, 8, 4);

    cout << "\n\nAdjacency Lists\n";
    cout << string(90, '-') << "\n\n";
    printgraph(graph, v, countries);

    return 0;
}
