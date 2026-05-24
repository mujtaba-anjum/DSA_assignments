//#include <iostream>
//using namespace std;
//
//const int MAXN = 102;
//char grid[MAXN][MAXN];
//int areaCount;
//
//void processArea(int row, int col) 
//{
//    if (grid[row][col] != 'w') 
//        return;  
//
//    grid[row][col] = '*';  
//    areaCount++;
//
//    processArea(row - 1, col);
//    processArea(row + 1, col);
//    processArea(row, col - 1);
//    processArea(row, col + 1);
//}
//
//int main() 
//{
//    int n;
//    cout << "Enter n (size of square): ";
//    cin >> n;
//
//    int total = n + 2;  
//
//    for (int i = 0; i < total; i++)
//        for (int j = 0; j < total; j++)
//            grid[i][j] = 'b';
//
//    cout << "Enter " << n << " rows of " << n << " characters (w=white, b=black):" << endl;
//    
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            cin >> grid[i][j];
//
//            if (grid[i][j] != 'w' && grid[i][j] != 'b')
//            {
//                cout << "Invalid character entered." << endl;
//                return 0;
//            }
//        }
//    }
//
//    int numAreas = 0;
//    int sizes[MAXN * MAXN];
//    int sizeIndex = 0;
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++) 
//        {
//            if (grid[i][j] == 'w')
//            {
//                areaCount = 0;
//                processArea(i, j);
//                sizes[sizeIndex++] = areaCount;
//                numAreas++;
//            }
//        }
//    }
//
//    cout << "\nNumber of white areas: " << numAreas << endl;
//    cout << "Sizes of white areas: ";
//    for (int i = 0; i < sizeIndex; i++) 
//    {
//        cout << sizes[i];
//        if (i < sizeIndex - 1) cout << ", ";
//    }
//    cout << endl;
//
//    return 0;
//}