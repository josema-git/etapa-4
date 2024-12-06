#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Jobs{
private:
    struct job {
        int id;
        vector<int> sameConstraints;
        vector<int> diffConstraints;
    };

    vector<job*> jobs;

    void fixConstraints(job* job, vector<int> color){
        for(int i = 0; i < job->sameConstraints.size(); i++){
            color[job->sameConstraints[i]] = color[job->id];
        }
        for(int i = 0; i < job->diffConstraints.size(); i++){
            color[job->diffConstraints[i]] = color[job->id] == 1 ? 0 : 1;
        }
    }

public:

    Jobs(vector<vector<vector<int>>> initial){
        for(int i = 0; i < initial.size(); i++){
            job* newJob = new job();
            newJob->id = i;
            newJob->sameConstraints = initial[i][0];
            newJob->diffConstraints = initial[i][1];
            jobs.push_back(newJob);
        }
    }

    

    bool isPossible(job* job, vector<int> color){
    }

    vector<int> assignJobs(job* job){

    }

};

int main() {
    Jobs jobs = Jobs({
                    {{1},{2}}, //job 0
                    {{4},{3}}, //job 1
                    {{0},{1}}, //job 2
                    {{2},{0}}, //job 3
                    {{3},{4}}, //job 4
                    {{},{}}, //job 5
                    {{},{}}, //job 6
                    {{},{}}, //job 7
                    {{},{}}, //job 8
                    {{},{}} //job 9
                    });

    return 0;
}