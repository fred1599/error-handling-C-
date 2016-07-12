#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void displayMean(vector<double> notes);

int main()
{
    string line;
    vector<double> v;

    double note;
    int counter = 0;

    while (true){

        cout << "Entrer la note n°" << counter+1 << ": ";
        getline(cin, line);

        if (line.empty()){
            displayMean(v);
            break;
        }

        try{
            note = stod(line);
            if (note < 0 || note > 20){
                displayMean(v);
                break;
            }
        }

        catch (const invalid_argument & ia){
                displayMean(v);
                break;
        }

        v.push_back(note);
        counter++;
    }

    return 0;
}

void displayMean(vector<double> notes){

    double sum = 0.0;
    size_t size_array = notes.size();

    if (size_array == 0) cout << "Pas de notes enregistrées" << endl;

    else{
        for (size_t i=0; i<size_array; i++) sum += notes.at(i);
        cout << "La moyenne est de " << sum/size_array << endl;
    }

}
