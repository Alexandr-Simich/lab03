#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
            if (numbers.size()!= 0) {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers)
        {

                if (number < min)
        {
            min = number;
        }

        if (number > max)
        {
            max = number;
        }

         }

    }

}

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

vector <size_t> make_histogram(const vector<double>& numbers, size_t bin_count, double min, double max)
{
    vector<size_t> bins(bin_count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return (bins);
}

void show_histogram_text(vector <size_t> bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << " ";
        }
        if (bin < 10)
        {
            cout << " ";
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

  vector <string> input_colors(size_t bin_count)
{

    vector<string> colors(bin_count);
    bool flag2;
    for (size_t i=0; i<bin_count; i++) {
    do {
        cin >> colors[i];
            bool flag1 = true;
        for (auto s : colors[i]){
            if (s == ' '){
                flag1 = false;
            }
        }
        if(colors[i][0] == '#'){
            if (flag1 == true){
                flag2 = true;
            }
            else {
                flag2 = false;
                cerr << "Error1";
            }
        }

        else if(colors[i][0] != '#'){
            if(flag1 = true){
                flag2 = true;
            }
            else{
                flag2 = false;
                cerr << "Error2";
            }
        }

    }
    while(flag2 == false);
    }

        return colors;
 }










