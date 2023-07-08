#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

std::vector<std::vector<std::string>> parselist(int argc, char *argv[], std::vector<std::vector<std::string>> lists) {
   // Define a multi-token option.
   po::options_description desc("Allowed options");
   desc.add_options()
      ("list", po::value<std::vector<std::string>>()->multitoken(), "multiple values");

   // Just parse the options without storing them in a map.
   po::parsed_options parsed_options = po::command_line_parser(argc, argv)
      .options(desc)
      .run();

   // Build list of multi-valued option instances. We iterate through
   // each command-line option, whether it is repeated or not. We
   // accumulate the values for our multi-valued option in a
   // container.
   for (const po::option& o : parsed_options.options) {
      if (o.string_key == "list")
         lists.push_back(o.value);
   }

   // If we had other normal options, we would store them in a map
   // here. In this demo program it isn't really necessary because
   // we are only interested in our special multi-valued option.
   po::variables_map vm;
   po::store(parsed_options, vm);

   // Print out the multi-valued option, each separate instance on its
   // own line.
   for (size_t i = 0; i < lists.size(); ++i) {
      for (size_t j = 0; j < lists[i].size(); ++j)
         std::cout << lists[i][j] << ' ';
      std::cout << '\n';
   }

   return lists;
}