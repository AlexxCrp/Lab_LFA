#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define STATE_MAX 1000

using namespace std;

typedef pair<int, string> transition;

struct traced_transition 
{
    int this_state, parent_state;
    string input_str;
};

vector <transition> nfa[STATE_MAX];
vector <traced_transition> q;
vector <int> stariFinale,arr1,arr2,drum;
vector <string> inputuri;


int main()
{
   
    int nrNoduri, nrTranzitii, stare1, stare2, stareInitiala, nrStariFinale, stareFinala, nrInputuri, index, indexfinal;
    string litera, input;
    bool acceptat;

    //CITIRE DATE

    cin >> nrNoduri >> nrTranzitii;

    for (int i = 0; i < nrTranzitii; i++)
    {
        cin >> stare1 >> stare2 >> litera;
        nfa[stare1].push_back({ stare2, litera });
    }

    cin >> stareInitiala;

    cin >> nrStariFinale;

    for (int i = 0; i < nrStariFinale; i++)
    {
        cin >> stareFinala;
        stariFinale.push_back(stareFinala);
    }

    cin >> nrInputuri;

    for (int i = 0; i < nrInputuri; i++)
    {
        cin >> input;
        inputuri.push_back(input);
    }

    //END CITIRE

    //PARCURGERE NFA SI DECIDERE DACA CUV ESTE ACCEPTAT SAU NU

    for (int i = 0; i < nrInputuri; i++)
    {
        arr1.clear();
        arr2.clear();
        drum.clear();
        q.clear();
        acceptat = false;
        input = inputuri[i];
        arr1.push_back(stareInitiala);
        traced_transition prTr;
        prTr.this_state = stareInitiala;
        prTr.parent_state = -1;
        prTr.input_str = input;
        q.push_back(prTr);

        while (input != "")
        {
            if (!arr2.empty())
            {
                arr2.clear();
            }
            for (int j = 0; j < arr1.size(); j++)
            {
                for (int k = 0; k < nfa[arr1[j]].size(); k++)
                {
                    if (nfa[arr1[j]][k].second[0] == input[0])
                    {
                        arr2.push_back(nfa[arr1[j]][k].first);
                        traced_transition trCurenta;
                        trCurenta.this_state = nfa[arr1[j]][k].first;
                        trCurenta.parent_state = arr1[j];
                        trCurenta.input_str = input.substr(1);
                        q.push_back(trCurenta);
                    }
                }
            }
            input.erase(input.begin());
            if (arr2.empty())
            {
                cout << "NU\n";
                break;
            }
            if (!arr1.empty())
            {
                arr1.clear();
            }
            for (int j = 0; j < arr2.size(); j++)
            {
                arr1.push_back(arr2[j]);
            }
        }

        for (int j = 0; j < arr1.size(); j++)
        {
            for (int k = 0; k < nrStariFinale; k++)
            {
                if (arr1[j] == stariFinale[k])
                {
                    cout << "DA\n";
                    acceptat = true;
                    indexfinal = stariFinale[k];
                    break;
                }
            }
            if (acceptat == true)
            {
                break;
            }
        }

       
    //END 

//AFISARE DRUM 
 
    if(acceptat == true)
    {
        for (int j = 0; j < q.size(); j++)
        {
            
            if (q[j].this_state == indexfinal)
            {
                    index = j;
            }
          
        }

        while (q[index].parent_state != -1)
        {
            drum.push_back(q[index].this_state);
            for (int j = 0; j < q.size(); j++)
            {
                if (q[j].this_state == q[index].parent_state && q[j].input_str.size() == (q[index].input_str.size() + 1))
                {
                    index = j;
                }
            }
        }

        cout << stareInitiala << ' ';

        for (int j = drum.size()-1; j >= 0; j--)
        {
            cout << drum[j]<<' ';
        }
        cout << "\n";
    }
        
    }


    return 0;
}