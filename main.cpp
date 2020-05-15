#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
using namespace std;




int main(int argc, char* argv[])
{
    if (argc > 1)
                            {
                                CURL *curl = curl_easy_init();
                        if(curl) {
                          CURLcode res;
                          curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
                          res = curl_easy_perform(curl);
                          curl_easy_cleanup(curl);
                        }


      //  cout << "argñ = " << argc;
      //  cout << "argv[0] = "<< argv[0];
        return 0;
    }

        curl_global_init(CURL_GLOBAL_ALL);
        Input input = read_input(cin, true);
        double min;
        double max;
        find_minmax(input.numbers,min,max);

        auto bins = make_histogram(input.numbers, input.bin_count, min, max);

        show_histogram_svg(bins);




        return 0;
}

