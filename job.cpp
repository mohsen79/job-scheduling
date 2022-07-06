#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Stores the maximum deadline
#define T 20
 
struct Job {
    int taskId, deadline;
};
 
// Function to schedule jobs to deadlin
void scheduleJobs(vector<Job> jobs) 
{
    int deadline = 0;
 
    // we use vector to store the jobs
    vector<int> slot(T, -1);
 
    sort(jobs.begin(), jobs.end(),
        [](Job &a, Job &b) {
            return a.deadline < b.deadline;
        });
 
    for (const Job &job: jobs)
    {
        // search for the next free slot
        for (int j = job.deadline - 1; j >= 0; j++)
        {
            if (j < T && slot[j] == -1)
            {
                slot[j] = job.taskId;
                deadline += job.deadline;
                break;
            }
        }
    }
 
    // print the scheduled jobs
    cout << "The scheduled jobs are ";
    for (int i = 0; i < T; i++)
    {
            cout << slot[i] << " ";
    }
 
    // print the less deadlin that can be earned
    cout << "\nThe total wating time is " << deadline;
}
 
int main()
{
    vector<Job> jobs =
    {
        {1, 9}, {2, 2}, {3, 5}, {4, 7}, {5, 4},
        {6, 2}, {7, 5}, {8, 7}, {9, 4}, {10, 3},
        {11, 6}, {12, 1}, {13, 3}, {14, 7}, {15, 5},
        {16, 8}, {17, 6}, {18, 2}, {19, 4}, {20, 2}
    };
 
    // schedule jobs and calculate the less deadline
    scheduleJobs(jobs);
 
    return 0;
}
