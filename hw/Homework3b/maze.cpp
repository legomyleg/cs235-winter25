#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string, std::to_string, std::getline;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream, std::ofstream, std::getline;
#include <sstream>
using std::istringstream;


#include "Grid.h"

bool find_maze_path(Grid& grid, int row, int col, int level, vector<string>& solution)
{
    solution.push_back(to_string(row) + " " + to_string(col) + " " + to_string(level));
    try 
    {
        grid.at(row, col, level);
    } catch(...)
    {
        solution.pop_back();
        return false;
    }
    if (grid.at(row, col, level) == 0 || grid.at(row, col, level) == 2)
    {
        solution.pop_back();
        return false;
    }
    if (row == grid.height()-1 && col == grid.width() - 1 && level == grid.depth() - 1)
    {
        return true;
    }

    grid.at(row, col, level) = 2;
    if (find_maze_path(grid, row - 1, col, level, solution) || find_maze_path(grid, row + 1, col, level, solution) || 
    find_maze_path(grid, row, col - 1, level, solution) || find_maze_path(grid, row, col + 1, level, solution) || 
    find_maze_path(grid, row , col, level - 1, solution) || find_maze_path(grid, row, col, level + 1, solution))
    {
        return true;
    } 
    else
    {
        solution.pop_back();
        return false;
    }

}

int main(int argc, char* argv[]) 
{
    // Write your code here
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    if (!in.is_open() || !out.is_open())
    {
        return 1;
    }

    Grid maze;
    in >> maze;
    vector<string> solution;
    if (find_maze_path(maze, 0, 0, 0, solution))
    {
        out << "SOLUTION" << endl;
        for (auto line : solution)
        {
            out << line << endl;
        }
    }
    else
    {
        out << "NO SOLUTION" << endl;
    }
    
    out.close();
    in.close();

    return 0;
}
