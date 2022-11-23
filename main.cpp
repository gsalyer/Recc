#include <bits/stdc++.h>
#include "FileIO.h"
#include "Movies.h"
#include "util.h"
#include "jsoncons/json.hpp"
#include "jsoncons_ext/csv/csv.hpp"

//temp testing
int main()
{
    //call CSVtoStr()
    // const std::string data = FILEIO::CSVtoStr("tmdb_5000_movies.csv");

    // jsoncons::csv::csv_options options;
    // options.assume_header(true);

    // Parse the CSV data into an ojson value
    // jsoncons::ojson j = jsoncons::csv::decode_csv<jsoncons::ojson>(data, options);

    // Pretty print
    // jsoncons::json_options print_options;
    // print_options.float_format(jsoncons::float_chars_format::fixed);
    // std::cout << "(1)\n" << pretty_print(j, print_options) << "\n\n";

    // Iterate over the rows
    // std::cout << "Testing the first 10 rows\n";
    // int i = 0;
    // for (const auto& row : j.array_range())
    // {
    //     if (i < 10)
    //     {
    //         // print column
    //         std::cout << row["genres"].as<std::string>() << std::endl;
    //         i++;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // std::vector<NamesIDs> namesIDs = FILEIO::parseNamesIDs("[{\"id\": 28, \"name\": \"Action\"}, {\"id\": 12, \"name\": \"Adventure\"}]");
    // for (const auto& nameID : namesIDs)
    // {
    //     std::cout << nameID.id << " " << nameID.name << std::endl;
    // }

    return 0;
}

// #include "FileIO.h"
// #include "Movies.h"
// #include "util.h"

// int main()
// {
//     Genre g1{1, "Action"};
//     Genre g2{2, "Adventure"};
//     Genre g3{3, "Fantasy"};

//     Movie movie;
//     movie.addGenre(g1);
//     movie.addGenre(g2);
//     movie.addGenre(g3);
//     movie.printGenres();

//     return 0;
// }