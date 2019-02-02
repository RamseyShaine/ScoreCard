#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
int gradeExam(ifstream&,string,string);
int getHigh(int[],int);
int getLow(int[],int);
double getAvg(int[],int);

const int NUM_QUESTIONS = 10;

int main()
{
    int scores[NUM_QUESTIONS];
    string key;
    string exam;
    int count = 1;
    int index = 0;
    
    ifstream fin;
    fin. open ("grade_data.txt");
    
    if (!fin)
    {
        cout << "File failed to open.\n";
    }
    else
        cout << "Check output file.\n";
    
    ofstream fout;
    fout.open("grade_report.txt");
    
    fin >> key;
    
    while (fin >> exam)
    {
        fout << "Student - " << count++ << " got " ;
        int correct = gradeExam(fin,exam,key);
        fout << correct << " answers correct." <<endl;
        
        scores[index]= correct;
        index++;
    }
    
    for (int i = NUM_QUESTIONS; i>=0; i--)
    {
        int studentGrade=0;
        
        for(int other = 0; other < 11; other++)
        {
            if(scores[other] == i)
            {
                studentGrade++;
                break;
            }
        }
        fout << i << " - " << studentGrade << endl;
        
    }
    
    int highScore = getHigh(scores, index);
    fout << "The highest score is: " << scores[highScore] << endl;
    
    int lowScore = getLow(scores, index);
    fout << "The lowest score is: " << scores[lowScore] << endl;
    
    double average = getAvg(scores,index);
    fout << "The mean score is: " << average << endl;
    
    fin.close();
    fout.close();
    
    return 0;
    
}
int gradeExam(ifstream &fin, string exam,string key)
{
    int correct = 0;
    
    
    for (int i= 0; i < NUM_QUESTIONS; i++)
    {
        if (key[i] == exam [i])
        {
            correct++;
        }
    }
    return correct;
    
}

int getHigh( int scores[], int index)
{
    int highest=0;
    
    for (int i=0; i < index; i++)
    {
        if (scores[i] > scores[highest])
        {
            highest=i;
        }
    }
    return highest;
}
int getLow(int scores[], int index)
{
    int lowest=0;
    
    for (int i = 1; i < index; i++)
    {
        if (scores[i] < scores[lowest])
        {
            lowest=i;
        }
    }
    return lowest;
}
double getAvg (int scores[], int index)
{
    double average;
    double total = 0.0;
    
    for(int i = 0; i < index; i++)
    {
        total+=scores[i];
    }
    average = static_cast<double>(total/index);
    
    return average;
}
