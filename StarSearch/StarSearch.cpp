// Ranjana Rajagopalan
// 11/27/20
// StarSearch.cpp
// This program calculates and displays the final score of a contestant by dropping the lowest and highest scores out of five, and averaging the rest of the three.

#include <iostream>
#include <iomanip> // needed for setprecision() function
using namespace std;

// function prototypes
void getJudgeData(double& score, int);
double calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main()
{
    double score1, score2, score3, score4, score5, finalScore;
    getJudgeData(score1, 1);
    getJudgeData(score2, 2);
    getJudgeData(score3, 3);
    getJudgeData(score4, 4);
    getJudgeData(score5, 5);
    
    finalScore = calcScore(score1, score2, score3, score4, score5);
    
    cout << "The final score is " << fixed << setprecision(2) << finalScore << ".\n";
}

void getJudgeData(double& score, int judgeNum)
{
    do
    {
        cout << "Enter the score of judge " << judgeNum << " as a value between 0 and 10: \n";
        cin >> score;
    } while ((score < 0) || (score > 10));
}

double calcScore(double score1, double score2, double score3, double score4, double score5)
{
    const int NUM_OF_SCORES = 3;
    double sum, average;
    double lowest, highest;
    
    lowest = findLowest(score1, score2, score3, score4, score5);
    highest = findHighest(score1, score2, score3, score4, score5);
    
    sum = score1 + score2 + score3 + score4 + score5; // add up all the scores
    sum -= lowest; // remove the lowest score
    sum -= highest; // remove the highest score
    
    average = sum / NUM_OF_SCORES; // take the average
    
    return average;
}

double findHighest(double score1, double score2, double score3, double score4, double score5)
{
    double highest = score1;
    
    // if the next score is larger than the previous score, make it the largest number
    if (score2 >= highest)
        highest = score2;
    
    if (score3 >= highest)
        highest = score3;
    
    if (score4 >= highest)
        highest = score4;
    
    if (score5 >= highest)
        highest = score5;
    
    return highest;
}

double findLowest(double score1, double score2, double score3, double score4, double score5)
{
    double lowest = score1;
    
    // if the next score is smaller than the previous score, make it the smallest number
    if (score2 <= lowest)
        lowest = score2;
    
    if (score3 <= lowest)
        lowest = score3;
    
    if (score4 <= lowest)
        lowest = score4;
    
    if (score5 <= lowest)
        lowest = score5;
    
    return lowest;
}
