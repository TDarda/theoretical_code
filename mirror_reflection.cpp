#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

bool mirror(vector<std::string> arg_vec)
{
    static int width = 0;
    const size_t SIZE = arg_vec.size();

    std::vector<std::string> new_row;
    if (SIZE < 2)
    {

        cout << setw(width) << arg_vec[0] << endl;
        width = 0;
        return true;
    }
    else
    {
        int column = SIZE / 2;
        cout << setw(width);
        while (column < SIZE)
        {
            cout << arg_vec[column] << ", ";
            column++;
        }
        width += column / 2;
        cout << endl;
        int decrement = SIZE - 1;
        int increment = SIZE / 2;
        while (decrement >= increment)
        {
            if (arg_vec[decrement--] != arg_vec[increment++])
            {
                width = 0;
                return false;
            }
        }

        int j = 0;

        while (j < SIZE / 2)
        {

            new_row.push_back(arg_vec[j++]);
        }
    }
    return mirror(new_row);
}

int main()
{
    std::vector<std::string> vec{"a", "b", "b", "c", "c", "c", "c", "g", "d", "d", "s", "s", "d", "d", "g"};

    cout << boolalpha << mirror(vec) << endl;
    cout << boolalpha << mirror(vec) << endl;
}