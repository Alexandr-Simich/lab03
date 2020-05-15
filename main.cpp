#include "histogram.h"
#include "svg.h"
using namespace std;




int main()
{
    Input data = read_input(cin, true);

    double min;
    double max;
    find_minmax(data.numbers,min,max);

    auto bins = make_histogram(data.numbers, data.bin_count, min, max);

    show_histogram_svg(bins);

    return 0;
}
