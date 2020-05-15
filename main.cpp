#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
using namespace std;




int main()
{
    curl_global_init(CURL_GLOBAL_ALL);

    Input input = read_input(cin, true);

    double min;
    double max;
    find_minmax(input.numbers,min,max);

    auto bins = make_histogram(input.numbers, input.bin_count, min, max);

    show_histogram_svg(bins);

    return 0;
}
