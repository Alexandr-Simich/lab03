#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <string>
using namespace std;



Input read_input(istream& in,bool prompt) {
    Input data;
    size_t number_count;
    if(prompt)
    {
    cerr << "Enter number count: ";
    in >> number_count;
    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    cerr << "Enter column count: ";
    in >> data.bin_count;
    }
    else
    {
        in >> number_count;
        data.numbers = input_numbers(in, number_count);
        in >> data.bin_count;
    }

    return data;
}

Input download(const string& address) {
    stringstream buffer;

    curl_global_init(CURL_GLOBAL_ALL);

    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        res = curl_easy_perform(curl);
        if (res)
        {
            cout << curl_easy_strerror(res) << endl;
            exit(1);
        }
    }
   curl_easy_cleanup(curl);
   return read_input(buffer, false);
}

int main(int argc, char* argv[]) {
    Input input;
   if (argc > 1)
    {
        input = download(argv[1]);
    }
    else
    {
        input = read_input(cin, true);
    }
    double min = 0, max = 0;
    find_minmax(input, min, max);
    const auto bins = make_histogram(input, min, max);
    show_histogram_svg(bins);

    return 0;
}














//const vector<double>& numbers,
//  size_t& bin_count, double min, double max
