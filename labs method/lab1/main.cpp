#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// среднее
double avar(const vector<double>& data)
{
    double sum = 0.0;
    for (double a : data)
    {
        sum += a;
    }
    return sum / data.size();
}

//квадрат отклонения
vector<double> deviationSquar(vector<double>& dev)
{
    vector<double> sq;
    for (int i = 0; i < dev.size(); i++)
    {
        double t = dev[i];
        sq.push_back(t * t);
    }
    return sq;
}

//отклонение
vector<double> deviation(const vector<double>& data, double avar)
{
    vector<double> dev;
    for (int i = 0; i < data.size(); i++)
    {
        dev.push_back(data[i] - avar);
    }

    return dev;
}


int main()
{
        const double gamma = 3.5;

    ifstream file("input1.txt");
    string line;
    vector<double> values;

    if (!file.is_open())
    {
        cerr << "no such file1" << endl;
        return 0;
    }

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;  
        }

        values.push_back(stod(line));
    }

    file.close();

    double mean = avar(values);
    cout << "mean: " << mean << endl;

    cout << "deltaR приб: " << gamma*mean/100;

    vector<double> dev = deviation(values, mean);

    for (int i = 0; i < dev.size(); i++)
    {
        cout << dev[i] << "\n";
    }
    cout << endl;

    vector<double> devSq = deviationSquar(dev);
    for (int i = 0; i < devSq.size(); i++)
    {
        cout << devSq[i] << "\n";
    }

    double tmp = 0;
    for (int i = 0; i < devSq.size(); i++) {
        tmp = tmp + devSq[i];
    }
     tmp = sqrt(tmp/(devSq.size() - 1));
    cout << "sigma: " << tmp << endl;
    cout << "sigmax-: " << tmp/sqrt((devSq.size()));

    return 0;
}
