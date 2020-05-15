#include "histogram.h"
#include "svg.h"
using namespace std;




int main()
{
    Input input = read_input(cin, true);

    double min;
    double max;
    find_minmax(input.numbers,min,max);

    auto bins = make_histogram(input.numbers, input.bin_count, min, max);

    show_histogram_svg(bins);

    return 0;
}
