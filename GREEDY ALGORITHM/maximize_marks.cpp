#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Question
{
    string name;
    int m_i; //->profit
    int t_i; //->weight
    double ratio;
};

bool compareRatio(Question a, Question b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int M; // total marks- total price
    cin >> M;
    int T; // total time- capacity
    cin >> T;
    int N = 5;
    cin >> N;

    vector<Question> questions(N);

    for (int i = 0; i < N; i++)
    {
        Question q;
        q.name = "Q" + to_string(i + 1);
        cin >> q.m_i;
        cin >> q.t_i;
        q.ratio = (double) q.m_i / q.t_i;
        questions.push_back(q);
    }

    sort(questions.begin(), questions.end(), compareRatio);

    double answered_marks = 0;
    for (int i = 0; i < N; i++)
    {

        if (questions[i].t_i <= T)
        {
            cout << "Question " << questions[i].name << " " << "100% done: " << questions[i].m_i << " marks" << endl;
            answered_marks += questions[i].m_i;
            T -= questions[i].t_i;
        }
        else
        {
            cout << "Question " << questions[i].name << " " << questions[i].ratio * T << " marks" << endl;
            answered_marks += questions[i].ratio * T;
            T = 0;
            break;
        }
    }

    cout << "Maximum " << answered_marks << " marks answering alone" << endl;
}