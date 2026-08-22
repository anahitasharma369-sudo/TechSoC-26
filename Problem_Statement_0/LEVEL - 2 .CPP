#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    char processAnother = 'y';

    while (processAnother == 'y' || processAnother == 'Y') {
        int choice;
        cout << "\n--- SHIPMENT MENU ---\n";
        cout << "1. Enter container weights manually\n";
        cout << "2. Read container weights from file\n";
        cout << "Choose input option (1 or 2): ";
        cin >> choice;

        vector<int> weights;

        if (choice == 1) {
            int count;
            cout << "How many containers? ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                int w;
                cout << "Enter weight " << i + 1 << ": ";
                cin >> w;
                weights.push_back(w);
            }
        } 
        else if (choice == 2) {
            ifstream file("shipment_data.txt");
            if (!file) {
                cout << "Error opening file!\n";
            } else {
                int w;
                while (file >> w) {
                    weights.push_back(w);
                }
                file.close();
                cout << "Loaded " << weights.size() << " weights from file.\n";
            }
        }

        if (!weights.empty()) {
            
            vector<int> sorted = weights;
            for (size_t i = 0; i < sorted.size(); i++) {
                for (size_t j = 0; j < sorted.size() - 1; j++) {
                    if (sorted[j] > sorted[j + 1]) {
                        int temp = sorted[j];
                        sorted[j] = sorted[j + 1];
                        sorted[j + 1] = temp;
                    }
                }
            }
            cout << "\n1. Sorted Weights: ";
            for (int w : sorted) cout << w << " ";
            cout << "\n";

            cout << "\n3. Bar Chart (* = 10 units):\n";
            for (size_t i = 0; i < weights.size(); i++) {
                cout << "Container " << i + 1 << ": ";
                for (int j = 0; j < weights[i] / 10; j++) {
                    cout << "*";
                }
                cout << "\n";
            }

            ofstream outFile("shipment_report.txt");
            if (outFile) {
                outFile << "Total Containers: " << weights.size() << "\nWeights: ";
                for (int w : weights) outFile << w << " ";
                outFile.close();
                cout << "\n4. Report saved to shipment_report.txt\n";
            }

            int searchTarget;
            cout << "\n6. Enter weight to search: ";
            cin >> searchTarget;
            cout << "Found at position(s): ";
            for (size_t i = 0; i < weights.size(); i++) {
                if (weights[i] == searchTarget) cout << (i + 1) << " ";
            }
            cout << "\n";

            int k;
            cout << "\n7. Enter K (e.g. 1 for heaviest): ";
            cin >> k;
            if (k >= 1 && k <= static_cast<int>(sorted.size())) {
                cout << k << "th heaviest weight: " << sorted[sorted.size() - k] << "\n";
            }

            int sum = 0;
            for (int w : weights) sum += w;
            cout << "\n8. Summary Dashboard:\n";
            cout << "   Total Weight: " << sum << "\n";
            cout << "   Average Weight: " << (double)sum / weights.size() << "\n";
        }

        cout << "\nProcess another ship? (y/n): ";
        cin >> processAnother;
    }

    cout << "Program finished.\n";
    return 0;
}
