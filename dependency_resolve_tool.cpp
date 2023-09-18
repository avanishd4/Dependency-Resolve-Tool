

#include<bits/stdc++.h>
using namespace std;

    // void init_code(){
    //     #ifndef ONLINE JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("outut.txt","w",stdout);
    //     #endif
    // }

struct Package;
{
    string packageName;
    string packageCode;
    vector<Package*> dependencies;
};


void dfs(Package* P, vector<string>& correctOrder, unordered_set<Package*>& alreadyBuilt, bool& buildPossible, unordered_set<Package*> & beingBuilt){

    if(alreadyBuilt.find(P) != alreadyBuilt.end()){                              //  check if the dependency is in the alreadyBuilt
         return;
    }
    
    beingBuilt.insert(P);
    for(Package* dependency: P->dependencies){
        if(beingBuilt.find(dependency)!= beingBuilt.end()){
            buildPossible = false;
            return;
        }
        dfs(dependency, correctOrder, alreadyBuilt, buildPossible, beingBuilt );                            //   checking each directed sub dependecies
    }

    alreadyBuilt.insert(P); 
    beingBuilt.erase(P);                                                    // if built insert into alreadyBuilt
    correctOrder.push_back(P->packageName);

}

vector<string> resolveDependencies(Package* P){
    unordered_set<Package*> alreadyBuilt;                      // an unordered set for checking if the packages are already built when calling dfs algo
    vector<string> correctOrder; 
    bool buildPossible=true;                              // to store the correct order of dependencies
    dfs(Package* P, correctOrder, alreadyBuilt, true);               // topological order using dfs algo
    if(buildPossible){
        return correctOrder;
    }
    return vector<Package*>();
    

}

int main(){
   // init_code();
    int t=1;
    while(t--){

    }
    return 0;
}