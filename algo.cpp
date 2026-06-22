#include "DataStores.h"
#include<iostream>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;


//Algorithm #4: Top K Teams based on points
void topKTeams(vector<Team>& team, int k) {
    priority_queue<pair<int, string>> pq;

    for (const auto& t : team) {
        pq.push({t.points, t.name});
    }

    cout << "\n Top " << k << " Teams Leaderboard \n";
    cout << "-----------------------------------\n";

    int count = 0;
    while (!pq.empty() && count < k) {
        cout << count + 1 << ". " << pq.top().second 
             << " - " << pq.top().first << " pts\n";
        pq.pop();
        count++;
    }
}


//Algorithm #5: Dutch National Flag
void dutchNF(vector<Match>& matches) {
    int l=0, h=matches.size()-1;                        //Win, Draw, Loss - l,m,h
    int m=0;

    while(m<=h){
        if(matches[m].result == 'W'){
            swap(matches[l], matches[m]);
            l++;
            m++;
        }
        else if(matches[m].result == 'D'){
            m++;
        }
        else{
            swap(matches[m], matches[h]);
            h--;
        }
    }
}

//Algorithm #7: Prefix Sum - Cumulative Goals
vector<int> buildPrefixGoals(vector<Match>& matches){
    vector<int> prefix;
    int sum = 0;

    for(auto m : matches){
        int totalGoals = m.home_team_goals + m.away_team_goals;
        sum += totalGoals;
        prefix.push_back(sum);
    }

    return prefix;
}

//Algorithm #8: Maximum Goals Window (Kadane)
int maxGoalWindow(vector<Match>& matches){
    int maxSum = 0;
    int currSum = 0;

    for(auto m : matches){
        int totalGoals = m.home_team_goals + m.away_team_goals;

        currSum += totalGoals;

        if(currSum > maxSum)
            maxSum = currSum;

        if(currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

//Algorithm #9: Sliding Window - Rolling Form
int rollingForm(vector<int>& formPoints, int k){
    if(formPoints.size() < k)
        return -1;

    int sum = 0;

    for(int i=0; i<k; i++){
        sum += formPoints[i];
    }

    int maxForm = sum;

    for(int i=k; i<formPoints.size(); i++){
        sum = sum - formPoints[i-k] + formPoints[i];

        if(sum > maxForm)
            maxForm = sum;
    }

    return maxForm;
}

//Algorithm #15: Two Pointer - Match Goal Pairs
void findGoalPairs(vector<int>& goals, int target){
    sort(goals.begin(), goals.end());

    int left = 0;
    int right = goals.size() - 1;

    cout << "\nPairs with sum " << target << ":\n";

    while(left < right){
        int sum = goals[left] + goals[right];

        if(sum == target){
            cout << goals[left] << " + "
                 << goals[right] << endl;

            left++;
            right--;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
}