/**
 * @file
 * CSVReader library
 *
 * @copyright
 * @verbatim
   Copyright @ 2017 Audi Electronics Venture GmbH. All rights reserved.

       This Source Code Form is subject to the terms of the Mozilla
       Public License, v. 2.0. If a copy of the MPL was not distributed
       with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

   If it is not possible or desirable to put the notice in a particular file, then
   You may include the notice in a location (such as a LICENSE file in a
   relevant directory) where a recipient would be likely to look for such a notice.

   You may add additional accurate notices of copyright ownership.
   @endverbatim
*/

#ifndef A_UTILS_UTIL_CSV_READER_HEADER_INCLUDED_
#define A_UTILS_UTIL_CSV_READER_HEADER_INCLUDED_

#include <string>
#include <vector>

namespace a_util
{
namespace parser
{

/**
 * Class that reads data from .csv file and storage it in a vector of string vectors
 */
class CSVReader
{
private:
    std::vector<std::vector<std::string> > _data_matrix;

public:
    /**
     * Function that reads data from .csv file and storage it in a vector of string vectors
     * internally
     * @param[in] filename String with the name of the file
     * @param[in] delimiter Char with the separator of data, (';' or ',') and line separator '\n'
     */
    void readFile(const std::string& filename, char delimiter);

    /**
     * Function that displays data from .csv file as a vector of string vectors internally
     *
     * @return The data is organized in a 2 dimensional vector, where the first index is the
     * line and the second one the number of element in the line.
     *
     */
    std::vector<std::vector<std::string> > getData();

    /**
     * Function that displays the contents of the column specified as a parameter, as a vector of
     * strings
     * @param[in] column_number Number of the column
     * @return The data is organized in a vector of strings.
     */
    std::vector<std::string> getColumn(size_t column_number);

    /**
     * Function that displays the contents of the row specified as a parameter, as a vector of
     * strings
     * @param[in] row_number Number of the row
     * @return The data is organized in a vector of strings.
     */
    std::vector<std::string> getRow(size_t row_number);

    /**
     * Function that displays the contents of the element specified from the row and column
     * parameters respectively, as a vector of strings
     * @param[in] row_number Number of the row
     * @param[in] column_number Number of the column
     * @return The data is returned as a string.
     */
    std::string getElement(size_t column_number, size_t row_number);

private:
    /**
     * Auxiliary function that splits data from one line into vector elements according to the
     * separator
     * @param[in] data_string Reference to the string to be separated
     * @param[in] vector_split_point Reference to a vector of strings with the separators of data,
     *                               (';' or ',') and line separator '\n'
     * @param[in] vector_with_substrings Reference to a vector of strings with the data separated
     *                                   as vector elements
     */
    void splitIntoSubstring(const std::string& data_string,
                            const std::vector<char>& vector_split_point,
                            std::vector<std::string>& vector_with_substrings);
};

} // namespace parser
} // namespace a_util

#endif // A_UTILS_UTIL_CSV_READER_HEADER_INCLUDED_
